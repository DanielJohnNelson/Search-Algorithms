//Daniel Nelson (102578897)
#include "Grid.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "Cell.h"
#include "GreedyBestSearch.h"
#include "AStarSearch.h"
#include "SearchAlgorithm.h"
#include "UniformCostSearch.h"
#include "BeamSearch.h"
#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{
    
    bool lWeighted;
    //Check if valid command
    if (argc < 4)
    {
        cout << "Not enough commands" << endl;
        return 2;
    }
    //Check if weighted search trees are to be used
    else if (string(argv[3]) == "WEIGHTED") { lWeighted = true; }
    else if (string(argv[3]) == "STANDARD") { lWeighted = false; }
    else 
    { 
        cout << "Invalid Weight Input"; 
        return 2;
    }
    
    //Declare and open file
    ifstream lFile;
    lFile.open(string(argv[1]));

    //Check if file opened correctly
    if (!lFile)
    {
        cout << "File not found" << endl;
        return -1;
    }
    //Declare Grid
    Grid grid(lFile);

    //Close File
    lFile.close();

    vector<int> lAgentCoords = grid.Get_Agent();

    //Initialize agent
    Cell lStartCell = grid.Get_Grid()[lAgentCoords[1]][lAgentCoords[0]];

    //Output filename and method
    cout << argv[1] << " " << argv[2] << " ";

    //Declare and compute each algorithm depending on input 
    if (string(argv[2]) == "BFS")
    {
        BreadthFirstSearch bfs;
        bfs.BFS(&lStartCell, lWeighted);
    }
    else if (string(argv[2]) == "DFS")
    {
        DepthFirstSearch dfs;
        //Output no solution if no goal node
        if (!dfs.DFS(&lStartCell))
        {
            cout << "No Solution Found " << endl;
        }
    }
    else if (string(argv[2]) == "GFS")
    {
        GreedyBestSearch gfs;
        gfs.GBFS(&lStartCell, gfs.SearchAlgorithm::BestGoal(&lStartCell, grid.Get_Goals()), lWeighted);
    }
    else if (string(argv[2]) == "AS")
    {
        AStarSearch as;
        as.AS(&lStartCell, as.SearchAlgorithm::BestGoal(&lStartCell, grid.Get_Goals()), lWeighted);
    }
    else if (string(argv[2]) == "BS")
    {
        BeamSearch bs;
        bs.BS(&lStartCell, bs.SearchAlgorithm::BestGoal(&lStartCell, grid.Get_Goals()), lWeighted);
    }
    else if (string(argv[2]) == "UCS")
    {
        UniformCostSearch ucs;
        ucs.UCS(&lStartCell, lWeighted);
    }
    else 
    {
        //If unknown method
        cout << "Unknown Method" << endl;
    }
    
    return 0;
}

