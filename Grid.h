//Daniel Nelson (102578897)
#pragma once

#include "Cell.h"
#include <fstream>
#include <vector>

using namespace std;

class Grid
{
    private:
        
        //Grid data from file
        vector<vector<int>> fGridData;
        //Grid of Cells
        vector<vector<Cell>> fGrid;
        //Goal Coordinate Vector
        vector<vector<int>> fGoals;
        //Wall coordinate Vector
        vector<vector<int>> fWalls;

        vector<int> fAgent;

        

    public:
        Grid(ifstream& file);
        //Load data from file
        void loadGridData(ifstream& file);
        //Initialize grid of cells
        void initGrid();
        //Declare pointer neighbours
        void declareNeighbours();
        //Return Grid
        vector<vector<Cell>> &Get_Grid();
        //Return Goals
        vector<vector<int>>& Get_Goals();
        vector<int>& Get_Agent();
};

