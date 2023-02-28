//Daniel Nelson (102578897)
#include "BreadthFirstSearch.h"
#include <vector>
#include <iostream>
#include <algorithm>

void BreadthFirstSearch::BFS(Cell* agent, bool weighted)
{
    //Initialize queue
    vector<Cell*> queue;
    
    queue.push_back(agent);
    
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
        vector<Cell*> neighbours = {next->Get_North(), next->Get_West(), next->Get_South(), next->Get_East()};

        //Loop over neighbours
        for (size_t i = 0; i < neighbours.size(); i++)
        {
            //Check if valid neighbour
            if (neighbours[i] != NULL && neighbours[i]->Get_Visited() == false && neighbours[i]->Get_Type() != "w")
            {
                if (weighted){ neighbours[i]->Set_Dist(SearchAlgorithm::Get_Weight(i)); }
                
                //Set previous cell in path
                neighbours[i]->Set_Prev(next);
                //Append neighbour to path
                queue.push_back(neighbours[i]);
           
            }
        }
        if (weighted) { queue = SearchAlgorithm::Sort(queue); }
    }
    //Check if no solution found
    if (queue[0]->Get_Type() != "g")
    {
        cout << " No Solution Found" << endl;
    }
}



