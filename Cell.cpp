//Daniel Nelson (102578897)
#include "Cell.h"

using namespace std;

Cell::Cell(int _x, int _y, bool _visited, string _cType) : north(NULL), south(NULL), east(NULL), west(NULL)
{
    //Initialize member variables
    x = _x;
    y = _y;
    visited = _visited;
    cType = _cType;
}

//Getters and Setters
void Cell::Set_North(Cell* north)
{
    Cell::north = north;
}

void Cell::Set_South(Cell* south)
{
    Cell::south = south;
}

void Cell::Set_East(Cell* east)
{
    Cell::east = east;
}

void Cell::Set_West(Cell* west)
{
    Cell::west = west;
}

Cell* Cell::Get_North()
{
    return north;
}

Cell* Cell::Get_South()
{
    return south;
}

Cell* Cell::Get_East()
{
    return east;
}

Cell* Cell::Get_West()
{
    return west;
}


string Cell::Get_Type()
{
    return cType;
}

bool Cell::Get_Visited()
{
    return visited;
}

void Cell::Set_Visited()
{
    visited = true;
}


int Cell::Get_X() 
{
    return x;
}

int Cell::Get_Y()
{
    return y;
}

void Cell::Set_Dist(int distance)
{
    fdistance = distance;
}

int Cell::Get_Dist()
{
    return fdistance;
}

Cell* Cell::Get_Prev()
{
    return previous;
}

void Cell::Set_Prev(Cell* prev)
{
    previous = prev;
}

void Cell::Set_Dir(string direction)
{
    fDirection = direction;
}

string Cell::Get_Dir()
{
    return fDirection;
}

void Cell::Set_PathCost(int pathcost)
{
    fPathCost = pathcost;
}

int Cell::Get_PathCost()
{
    return fPathCost;
}

