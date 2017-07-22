#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <limits>
#include <stack>
using namespace std;
#define ROW 9
#define COL 10
//shortcut for int int pair
typedef pair<int, int> Pair;
//shortcut for pair<double, pair<int,int> > pPair
typedef pair<double, pair<int, int> > pPair;
//structure to hold parameters
typedef struct Cell
{
	//row and column index
	int parent_i,parent_j;
	//f = g + h
	double f, g, h;
}cell;
// function to check whether giveln cell is valid cell or not
bool isValid(int row,int col)
{
	//return if row n.o and col n.o falls in range
	return (row>=0)&&(row<ROW)&&(col>=0)&&(col<COL);
}
//function to check whether cell is blocked or not
bool isUnBlocked(int grid[][COL],int row,int col)
{
	//return true if the cell is not blocked else false
	return (grid[row][col]==1)?true:false;
}
// Function to check whether destination cell has been reached or not
bool isDestination(int row,int col,Pair dest)
{
	return (row==dest.first && col==dest.second)?true:false;
}
//Utility Function to calculate the 'h' heuristics
int calculateHValue(int row,int col,Pair dest)
{
	// Return using the distance formula
    return ((double)sqrt ((row-dest.first)*(row-dest.first)
                          + (col-dest.second)*(col-dest.second)));
}
//Utility function to trace path from source to destination
void tracePath(cell cellDetails[][COL], Pair dest)
{
    cout<<"\nThe Path is "<<endl;
    int row = dest.first;
    int col = dest.second;
 
    stack<Pair> Path;
 
    while (!(cellDetails[row][col].parent_i == row
             && cellDetails[row][col].parent_j == col ))
    {
        Path.push (make_pair (row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }
 
    Path.push (make_pair (row, col));
    while (!Path.empty())
    {
        pair<int,int> p = Path.top();
        Path.pop();
        cout<<"-> "<<p.first<<","<<p.second;
        //printf("-> (%d,%d) ",p.first,p.second);
    }
 
    return;
}
// Utility Function to find shortest path between given source cell to 
// a destination cell using A* algorithm
void aStarSearch(int grid[][COL], Pair src, Pair dest)
{
	//Check Points
	//If the source is out of range
	if(isValid(src.first,src.second) == false)
	{
		cout<<"Source is Invalid"<<endl;
		return;
	}
	//Destination is out of range
	if(isValid(dest.first,dest.second) == false)
	{
		cout<<"Destination in invalid"<<endl;
		return;
	}
	//if the source or destination is blocked
	if(isUnBlocked(grid,src.first,src.second)==false ||
		isUnBlocked(grid,dest.first,dest.second) == false)
	{
		cout<<"Source or the Destination is blocked "<<endl;
		return;
	}
	//Create a closed list and initialis\ze it to false
	//means no cell has been included it
	bool closedList[ROW][COL];
	memset(closedList,false,sizeof(closedList));

	//Declare a 2D array of stucture to hold details from cells
	cell cellDetails[ROW][COL];
	int i,j;
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			cellDetails[i][j].f = numeric_limits<double>::max();
			cellDetails[i][j].g = numeric_limits<double>::max();
			cellDetails[i][j].h = numeric_limits<double>::max();
			cellDetails[i][j].parent_i = -1;
			cellDetails[i][j].parent_j = -1;
		}
	}
	// Initialize parameter of starting node
	i=src.first,j=src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent_i = i;
	cellDetails[i][j].parent_j = j;
	/*
	Create an open list having information as-
     <f, <i, j>>
     where f = g + h,
     and i, j are the row and column index of that cell
     Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
     This open list is implenented as a set of pair of pair.
	*/

	set<pPair > openList;
	// put starting cell on the open list and set its f to zero
	openList.insert(make_pair(0.0,make_pair(i,j)));
	//we set the boolena value to false as initially destination is not reached
	bool foundDest = false;
	while(!openList.empty())
	{
		// sets can be iterated through itterators not indices
		pPair p = *openList.begin();// this return pointer to first postion
		// Remove this vertex from open List
		openList.erase(openList.begin());
		// Add vertes to openlist
		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;
		 /*
        Generating all the 8 successor of this cell
 
            N.W   N   N.E
              \   |   /
               \  |  /
            W----Cell----E
                 / | \
               /   |  \
            S.W    S   S.E
 
        Cell-->Popped Cell (i, j)
        N -->  North       (i-1, j)
        S -->  South       (i+1, j)
        E -->  East        (i, j+1)
        W -->  West           (i, j-1)
        N.E--> North-East  (i-1, j+1)
        N.W--> North-West  (i-1, j-1)
        S.E--> South-East  (i+1, j+1)
        S.W--> South-West  (i+1, j-1)
        */
        // store the 'g' 'f 'h' of 8 successor
        double gNew,hNew,fNew;
        //----------- 1st Successor (North) ------------
        // Proceed if the Cell is valid
        if(isValid(i-1,j)==true)
        {
        	//if destination cell is same as the current successor
        	if(isDestination(i-1,j,dest)==true)
        	{
        		//set parameter of destination cell
        		cellDetails[i-1][j].parent_i = i;
        		cellDetails[i-1][j].parent_j = j;
        		cout<<"The Destination Cell is Found"<<endl;
        		tracePath(cellDetails,dest);
        		foundDest = true;
        		return;
        	}
        	// If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if(closedList[i-1][j]==false && isUnBlocked(grid,i-1,j)==true)
            {
            	gNew=cellDetails[i][j].g+1.0;
            	hNew=calculateHValue(i-1,j,dest);
            	fNew = gNew+hNew;
            	// If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if(cellDetails[i-1][j].f==numeric_limits<double>::max()||cellDetails[i-1][j].f>fNew)
                {
                	openList.insert(make_pair(fNew,make_pair(i-1,j)));
                	//update the details of the cell
                	cellDetails[i-1][j].f = fNew;
                	cellDetails[i-1][j].g = gNew ;
                	cellDetails[i-1][j].h = hNew;
                	cellDetails[i-1][j].parent_i = i;
                	cellDetails[i-1][j].parent_j = j;
                }
            }
        }
        //----------- 2nd Successor (South) ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i+1, j) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i+1, j, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i+1][j].parent_i = i;
                cellDetails[i+1][j].parent_j = j;
                cout<<"The Destination Cell is Found"<<endl;
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i+1][j] == false &&
                     isUnBlocked(grid, i+1, j) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i+1, j, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i+1][j].f == numeric_limits<double>::max() ||
                        cellDetails[i+1][j].f > fNew)
                {
                    openList.insert( make_pair (fNew, make_pair (i+1, j)));
                    // Update the details of this cell
                    cellDetails[i+1][j].f = fNew;
                    cellDetails[i+1][j].g = gNew;
                    cellDetails[i+1][j].h = hNew;
                    cellDetails[i+1][j].parent_i = i;
                    cellDetails[i+1][j].parent_j = j;
                }
            }
        }
 
        //----------- 3rd Successor (East) ------------
 
        // Only process this cell if this is a valid one
        if (isValid (i, j+1) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j+1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i][j+1].parent_i = i;
                cellDetails[i][j+1].parent_j = j;
                cout<<"The Destination Cell is Found"<<endl;
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i][j+1] == false &&
                     isUnBlocked (grid, i, j+1) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue (i, j+1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i][j+1].f == numeric_limits<double>::max() ||
                        cellDetails[i][j+1].f > fNew)
                {
                    openList.insert( make_pair(fNew,
                                        make_pair (i, j+1)));
 
                    // Update the details of this cell
                    cellDetails[i][j+1].f = fNew;
                    cellDetails[i][j+1].g = gNew;
                    cellDetails[i][j+1].h = hNew;
                    cellDetails[i][j+1].parent_i = i;
                    cellDetails[i][j+1].parent_j = j;
                }
            }
        }
 
        //----------- 4th Successor (West) ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i, j-1) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j-1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i][j-1].parent_i = i;
                cellDetails[i][j-1].parent_j = j;
                cout<<"The Destination Cell is Found"<<endl;
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i][j-1] == false &&
                     isUnBlocked(grid, i, j-1) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j-1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i][j-1].f == numeric_limits<double>::max() ||
                        cellDetails[i][j-1].f > fNew)
                {
                    openList.insert( make_pair (fNew,
                                          make_pair (i, j-1)));
 
                    // Update the details of this cell
                    cellDetails[i][j-1].f = fNew;
                    cellDetails[i][j-1].g = gNew;
                    cellDetails[i][j-1].h = hNew;
                    cellDetails[i][j-1].parent_i = i;
                    cellDetails[i][j-1].parent_j = j;
                }
            }
        }
 
        //----------- 5th Successor (North-East) ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i-1, j+1) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i-1, j+1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i-1][j+1].parent_i = i;
                cellDetails[i-1][j+1].parent_j = j;
                cout<<"The Destination Cell is Found"<<endl;
                tracePath (cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i-1][j+1] == false &&
                     isUnBlocked(grid, i-1, j+1) == true)
            {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateHValue(i-1, j+1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i-1][j+1].f == numeric_limits<double>::max() ||
                        cellDetails[i-1][j+1].f > fNew)
                {
                    openList.insert( make_pair (fNew, 
                                    make_pair(i-1, j+1)));
 
                    // Update the details of this cell
                    cellDetails[i-1][j+1].f = fNew;
                    cellDetails[i-1][j+1].g = gNew;
                    cellDetails[i-1][j+1].h = hNew;
                    cellDetails[i-1][j+1].parent_i = i;
                    cellDetails[i-1][j+1].parent_j = j;
                }
            }
        }
 
        //----------- 6th Successor (North-West) ------------
 
        // Only process this cell if this is a valid one
        if (isValid (i-1, j-1) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination (i-1, j-1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i-1][j-1].parent_i = i;
                cellDetails[i-1][j-1].parent_j = j;
                cout<<"The Destination Cell is Found"<<endl;
                tracePath (cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i-1][j-1] == false &&
                     isUnBlocked(grid, i-1, j-1) == true)
            {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateHValue(i-1, j-1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i-1][j-1].f == numeric_limits<double>::max() ||
                        cellDetails[i-1][j-1].f > fNew)
                {
                    openList.insert( make_pair (fNew, make_pair (i-1, j-1)));
                    // Update the details of this cell
                    cellDetails[i-1][j-1].f = fNew;
                    cellDetails[i-1][j-1].g = gNew;
                    cellDetails[i-1][j-1].h = hNew;
                    cellDetails[i-1][j-1].parent_i = i;
                    cellDetails[i-1][j-1].parent_j = j;
                }
            }
        }
 
        //----------- 7th Successor (South-East) ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i+1, j+1) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i+1, j+1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i+1][j+1].parent_i = i;
                cellDetails[i+1][j+1].parent_j = j;
                cout<<"The Destination Cell is Found"<<endl;
                tracePath (cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i+1][j+1] == false &&
                     isUnBlocked(grid, i+1, j+1) == true)
            {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateHValue(i+1, j+1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i+1][j+1].f == numeric_limits<double>::max() ||
                        cellDetails[i+1][j+1].f > fNew)
                {
                    openList.insert(make_pair(fNew, 
                                        make_pair (i+1, j+1)));
 
                    // Update the details of this cell
                    cellDetails[i+1][j+1].f = fNew;
                    cellDetails[i+1][j+1].g = gNew;
                    cellDetails[i+1][j+1].h = hNew;
                    cellDetails[i+1][j+1].parent_i = i;
                    cellDetails[i+1][j+1].parent_j = j;
                }
            }
        }
 
        //----------- 8th Successor (South-West) ------------
 
        // Only process this cell if this is a valid one
        if (isValid (i+1, j-1) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i+1, j-1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i+1][j-1].parent_i = i;
                cellDetails[i+1][j-1].parent_j = j;
                cout<<"The Destination Cell is Found"<<endl;
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
 
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i+1][j-1] == false &&
                     isUnBlocked(grid, i+1, j-1) == true)
            {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateHValue(i+1, j-1, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i+1][j-1].f == numeric_limits<double>::max() ||
                        cellDetails[i+1][j-1].f > fNew)
                {
                    openList.insert(make_pair(fNew, 
                                        make_pair(i+1, j-1)));
 
                    // Update the details of this cell
                    cellDetails[i+1][j-1].f = fNew;
                    cellDetails[i+1][j-1].g = gNew;
                    cellDetails[i+1][j-1].h = hNew;
                    cellDetails[i+1][j-1].parent_i = i;
                    cellDetails[i+1][j-1].parent_j = j;
                }
            }
        }
	}
	return;
}
int main(int argc, char const *argv[])
{
	/* Description of the Grid-
     1--> The cell is not blocked
     0--> The cell is blocked    */
	int grid[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 0, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
    };
    // Source is the left-most bottom-most corner
    Pair src = make_pair(8, 0);
 
    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 0);
 
    aStarSearch(grid, src, dest);
	return 0;
}