//Daniel Nelson (102578897)
#include "SearchAlgorithm.h"
#include <vector>
#include <iostream>


int SearchAlgorithm::Distance(int x1, int y1, int x2, int y2)
{
    //Return manhattan distance
    return (abs(x1 - x2) + abs(y1 - y2));
}
        
vector<Cell*> SearchAlgorithm::Sort(vector<Cell*> queue)
{
    //Sort vector of cell pointers by heuristic
    for (size_t i = 1; i < queue.size(); i++)
    {
        for (int j = i; (j > 0) && (queue[j]->Get_Dist() < queue[j - 1]->Get_Dist()); j--)
        {
            //Swap pointers
            Cell* temp = queue[j];

            queue[j] = queue[j - 1];

            queue[j - 1] = temp;
        }
    }
    return queue;
}


void SearchAlgorithm::PrintPath(Cell* goal)
{
    //Initialize number of nodes in path ( 1 to account for beginning node)
    int lNodeNum = 1;
    //Initialize path
    vector<Cell*> path = { goal };

    //Go backwards from end node to start to gather path
    while (path.back()->Get_Prev()->Get_Type() != "a")
    {
        lNodeNum += 1;
        path.push_back(path.back()->Get_Prev());
    }

    cout << lNodeNum << endl;
    //Reverse path vector
    reverse(path.begin(), path.end());

    //For each node in path output the direction that was taken to get there
    for (size_t i = 0; i < path.size(); i++)
    {
        if (path[i]->Get_North() != NULL && path[i]->Get_Prev()->Get_X() == path[i]->Get_North()->Get_X() && path[i]->Get_Prev()->Get_Y() == path[i]->Get_North()->Get_Y())
        {
            cout << "Down; ";
        }
        else if (path[i]->Get_South() != NULL && path[i]->Get_Prev()->Get_X() == path[i]->Get_South()->Get_X() && path[i]->Get_Prev()->Get_Y() == path[i]->Get_South()->Get_Y())
        {
            cout << "Up; ";
        }
        else if (path[i]->Get_East() != NULL && path[i]->Get_Prev()->Get_X() == path[i]->Get_East()->Get_X() && path[i]->Get_Prev()->Get_Y() == path[i]->Get_East()->Get_Y())
        {
            cout << "Left; ";
        }
        else if (path[i]->Get_West() != NULL && path[i]->Get_Prev()->Get_X() == path[i]->Get_West()->Get_X() && path[i]->Get_Prev()->Get_Y() == path[i]->Get_West()->Get_Y())
        {
            cout << "Right; ";
        }
    }
    cout << endl;
}

vector<int> SearchAlgorithm::BestGoal(Cell * cell, vector<vector<int>>& goals)
{
    //Initialize goals
    vector<int> lGoaldists;

    //Find Closest Goal to Prioritize
    for (size_t i = 0; i < goals.size(); i++)
    {
        //Get distance from agent to each goal
        lGoaldists.push_back(Distance(cell->Get_X(), cell->Get_Y(), goals[i][0], goals[i][1]));
    }

    int index = 0;

    for (size_t i = 0; i < lGoaldists.size(); i++)
    {
        //Sort by cheapest goal
        if (lGoaldists[i] < lGoaldists[index]) { index = i; }
    }
    //Determine final goal
    vector<int> lBestGoal = goals[index];

    return lBestGoal;
}

int SearchAlgorithm::Get_Weight(int index)
{
    if (index == 0) { return 4; }
    else if (index == 1 || index == 2) { return 2; }
    else { return 1; }
}
