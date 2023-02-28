//Daniel Nelson (102578897)
#include "GreedyBestSearch.h"
#include <iostream>
#include <algorithm>

void GreedyBestSearch::GBFS(Cell* cell, vector<int> bestgoal, bool weighted)
{
    //Initialize queue
    vector<Cell*> queue;
    
    queue.push_back(cell);
    
    //Loop until all nodes explored
    while (!queue.empty())
    {
        Cell* next = queue[0];
        //Set visited
        next->Set_Visited();
        //Check for goal state
        if (next->Get_Type() == "g")
        {
           
            SearchAlgorithm::PrintPath(next);

            break;
        }
        //Remove node from queue
        queue.erase(queue.begin());
        //Declare neighbours
        vector<Cell*> neighbours = { next->Get_North(), next->Get_West(), next->Get_South(), next->Get_East() };
       
        //Loop over neighbours
        for (size_t i = 0; i < neighbours.size() ; i++)
        {
            //Check if valid neighbour
            if (neighbours[i] != NULL && neighbours[i]->Get_Visited() == false && neighbours[i]->Get_Type() != "w")
            {
                //Set previous cell in path
                 neighbours[i]->Set_Prev(next);
                 //Determine Heuristic
                 neighbours[i]->Set_Dist(SearchAlgorithm::Distance(neighbours[i]->Get_X(), neighbours[i]->Get_Y(), bestgoal[0], bestgoal[1]));
                 //Add weights to cost if weighted
                 if (weighted) { neighbours[i]->Set_Dist(neighbours[i]->Get_Dist() + SearchAlgorithm::Get_Weight(i)); }
                 //Append queue with neighbour
                 queue.push_back(neighbours[i]);
            }
        }
        //Sort queue by heuristic
        queue = SearchAlgorithm::Sort(queue);
    }
    //Check if no solution found
    if (queue[0]->Get_Type() != "g")
    {
        cout << " No Solution Found" << endl;
    }
}

