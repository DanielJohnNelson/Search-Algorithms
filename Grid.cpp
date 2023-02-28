//Daniel Nelson (102578897)
#include "Grid.h"
#include "Cell.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

using namespace std;


Grid::Grid(ifstream& file)
{
    //Load the file data
    loadGridData(file);
    //Initialize grid of cells
    initGrid();
    //Initialize neighbours if each cell
    declareNeighbours();
}

void Grid::loadGridData(ifstream& file)
{
    //Declare variables
    
    string line;
    int num;

    //Iterate over each line
    while (getline(file, line))
    {
        vector<int> line_digits;
        //Extract digits from each line
        stringstream newline(regex_replace(line, regex(R"([\D])"), " "));
        //Append digits to line vector
        while (newline >> num) { line_digits.push_back(num); }
        //Append line vector to lines vector
        fGridData.push_back(line_digits);
    }
    
}


void Grid::initGrid()
{
    fAgent = { fGridData[1][0], fGridData[1][1] };


    if (fGridData.size() >= 3)
    {
        //Loop over every row of wall coordinates
        for (int k = 3; k < fGridData.size(); k++)
        {
            //Loop from the beginning x,y to their width and height

            for (int n = fGridData[k][0]; n < (fGridData[k][0] + fGridData[k][2]); n++)
            {

                for (int m = fGridData[k][1]; m < fGridData[k][1] + fGridData[k][3]; m++)
                {
                    //Append wall array with wall coordinate
                    fWalls.push_back({ n , m });
                }
            }
        }
    }

    
    //Loop over goal coordinates
    for (size_t m = 0; m < fGridData[2].size(); m++)
    {
        if (m % 2 == 0) 
        { 
            //Append goal array with goals
            fGoals.push_back({ fGridData[2][m], fGridData[2][m + 1] });
        }
    }

    //Loop over grid x
    for (int i = 0; i < fGridData[0][0]; i++)
    {
        //Declare row vector
        vector<Cell> row;
        //Loop over grid y
        for (int j = 0; j < fGridData[0][1]; j++)
        {
            string type = "e";
            bool visited = false;
            //Check if cell type is to be agent
            if (i == fGridData[1][1] && j == fGridData[1][0]) { type = "a"; visited = true; }
            
            //Otherwise...
            else
            {
                //Loop over each goal
                for (size_t n = 0; n < fGoals.size(); n++)
                {
                    //Check if cell type is to be a goal
                    if (j == fGoals[n][0] && i == fGoals[n][1]) { type = "g"; }
                }
                //Loop over each wall
                for (size_t l = 0; l < fWalls.size(); l++)
                {
                    //Check if cell type is to be wall
                    if (j == fWalls[l][0] && i == fWalls[l][1]) { type = "w"; }
                }
            }
            //Append row with new cell
            row.push_back(Cell(j, i, visited, type));

        }
        //append grid with row
        fGrid.push_back(row);
    }
    
    
}

void Grid::declareNeighbours()
{
    //Loop over grid
    for (int i = 0; i < fGridData[0][0]; i++)
    {
        for (int j = 0; j < fGridData[0][1]; j++)
        {
            if (i > 0)
            {
                //Set north neighbour
                fGrid[i][j].Set_North(&fGrid[i - 1][j]);
            }
            if (i < fGridData[0][0] - 1)
            {
                //Set south neighbour
                fGrid[i][j].Set_South(&fGrid[i + 1][j]);
            }
            if (j > 0)
            {
                //Set west neighbour
                fGrid[i][j].Set_West(&fGrid[i][j - 1]);
            }
            if (j < fGridData[0][1] - 1)
            {
                //Set east neighbour
                fGrid[i][j].Set_East(&fGrid[i][j + 1]);
            }
            
        } 
        
      
    }
}

vector<vector<Cell>>& Grid::Get_Grid()
{
    return fGrid;
}

vector<vector<int>>& Grid::Get_Goals()
{
    return fGoals;
}

vector<int>& Grid::Get_Agent()
{
    return fAgent;
}
