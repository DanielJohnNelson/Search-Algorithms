//Daniel Nelson (102578897)
#include <string>


using namespace std;

class Cell
{
    private:
        //Coordinates
        int x;
        int y;

        //Visited or not
        bool visited;
        
        //Type
        std::string cType;

        //Heuristics
        int fdistance;
        int fPathCost;

        //Direction for path output
        string fDirection;

        //Neighbour pointers
        Cell* north;
        Cell* south;
        Cell* east;
        Cell* west;
        //Previous cell in path
        Cell* previous = nullptr;

        

    public:
        //Constructor
        Cell(int _x, int _y, bool _visited, string _cType);

        //Getters and Setters
        void Set_North(Cell *north);

        void Set_South(Cell* south);

        void Set_East(Cell* east);

        void Set_West(Cell* west);

        Cell* Get_North();

        Cell* Get_South();

        Cell* Get_East();

        Cell* Get_West();

        string Get_Type();

        bool Get_Visited();

        void Set_Visited();

        int Get_X();

        int Get_Y();

        void Set_Dist(int distance);
        int Get_Dist();

        Cell* Get_Prev();
        void Set_Prev(Cell* prev);

        void Set_Dir(string direction);
        string Get_Dir();

        void Set_PathCost(int pathcost);
        int Get_PathCost();

        
};
