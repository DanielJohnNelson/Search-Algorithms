//Daniel Nelson (102578897)
#include "BeamSearch.h"
#include <iostream>

void BeamSearch::BS(Cell* cell, vector<int> bestgoal, bool weighted)
{
    //Initialize beam width
    size_t beamwidth = 1;

    //Search until returns path
    while (Search(cell, bestgoal, beamwidth, weighted) == false) 
    {
        //Output beamwidth failed and increment beam width
        cout << endl;
        cout << "Beamwidth pruned goal. Trying again..." << endl;
        beamwidth += 1;   
    }
    
}

bool BeamSearch::Search(Cell* cell, vector<int> bestgoal, size_t beamwidth, bool weighted)
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

            return true;
        }
        //Remove node from queue
        queue.erase(queue.begin());
        //Declare neighbours
        vector<Cell*> neighbours = { next->Get_North(), next->Get_West(), next->Get_South(), next->Get_East() };

        //Loop over neighbours
        for (size_t i = 0; i < neighbours.size(); i++)
        {
            //Check if valid neighbour
            if (neighbours[i] != NULL && neighbours[i]->Get_Visited() == false && neighbours[i]->Get_Type() != "w")
            {
                //Set previous cell in path
                neighbours[i]->Set_Prev(next);

                //Determine heuristic
                neighbours[i]->Set_Dist(SearchAlgorithm::Distance(neighbours[i]->Get_X(), neighbours[i]->Get_Y(), bestgoal[0], bestgoal[1]));

                //Check if weighted cost is to be added
                if (weighted) { neighbours[i]->Set_Dist(neighbours[i]->Get_Dist() + SearchAlgorithm::Get_Weight(i)); }

                //Append neighbour to path
                queue.push_back(neighbours[i]);
            }
        }
        //Sort queue by heuristic
        queue = SearchAlgorithm::Sort(queue);
        //Remove queue elements beyond beamwidth
        while (queue.size() >= beamwidth)
        {
            queue.pop_back();
        }
    }
    //Return false if nothing found
    return false;
    //Output if no solution found
    if (queue[0]->Get_Type() != "g")
    {
        cout << " No Solution Found" << endl;
    }
}

