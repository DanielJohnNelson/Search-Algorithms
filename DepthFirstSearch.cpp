//Daniel Nelson (102578897)
#include "DepthFirstSearch.h"
#include <iostream>
#include <vector>

bool DepthFirstSearch::DFS(Cell* cell)
{
    
    //Check for goal state
    if (cell->Get_Type() == "g")
    {
        SearchAlgorithm::PrintPath(cell);

        return true;
    }

    //Set visited
    cell->Set_Visited();
    //Init neighbours
    vector<Cell*> neighbours = { cell->Get_North(), cell->Get_West(), cell->Get_South(), cell->Get_East() };
    //Loop over neighbours
    for (size_t i = 0; i < neighbours.size(); i++)
    {
        //Check if valid neighbour
        if (neighbours[i] != NULL && neighbours[i]->Get_Visited() == false && neighbours[i]->Get_Type() != "w")
        {
            //Set previous cell in path
            neighbours[i]->Set_Prev(cell);
            

            //Recurse up branch
            if (DFS(neighbours[i]))
            {
                return true;
            }

        }

    }
    //Return down branch
    return false;


}
