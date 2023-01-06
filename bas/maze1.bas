
#proto hasWall(__X__,__Y__,__Z__)
#proto visitCell(__X__,__Y__)
#proto hasWall(__X__,__Y__,__D__)

#include <hbasic.h>

Begin
    Option Ctrl+C
    Cls, Locate(1,1)
    height = 20
    width  = 30
    top = 1
    bottom = 2
    left = 3
    right = 4
    
    maze=0
    Let( maze := Gosub(resetMaze) )
    
    //# Randomize the PRNG.
    Gosub(randomize)
 
    //# Visit all the cells starting at a random point.
    _visitCell( Gosub( getRandX ), Gosub(getRandY) )
 
    //# Show the result.
    Gosub(printMaze)
        
End
Subrutines

///# Wander through the maze removing walls as we go.
visitCell(x, y)
    _setVisited(x, y)  //;   # This cell has been visited.
 
   // # Visit neighbors in a random order.
    dirList = getRandDirList();
    for (dir = 1; dir <= 4; dir++) {
       // # Get coordinates of a random neighbor (next in random direction list).
        ndir = substr(dirList, dir, 1);
        nx = getNextX(x, ndir);
        ny = getNextY(y, ndir);
 
       // # Visit an unvisited neighbor, removing the separating walls.
        if (wasVisited(nx, ny) == 0) {
            rmWall(x, y, ndir);
            rmWall(nx, ny, getOppositeDir(ndir));
            visitCell(nx, ny)
        } 
    }
}

printMaze:
    For (y = 1, var(y) Is Le?(height), ++y)
        For (pass = 1, var(pass) Is Le?(2), ++pass) //{ # Go over each row twice: top, middle
            For (x = 1, var(x) Is Le?(width), ++x) 
                If ( var(pass) Is Eq?(1) )      //{ # top
                    Print("+");
                    Print If( _hasWall(x, y, top) Is Eq? ( 1 ), "---", "   " )
                    If ( var(x) Is Eq? (width) )
                        Print("+")
                    End If
                End If
                Else If ( var(pass) Is Eq?(2) ) ///{ # left, right
                    Print If (_hasWall(x, y, left) Is Eq? (1), "|", " ")
                    Print("   ")
                    If ( var(x) Is Eq? (width) )
                        Print (_hasWall(x, y, right) Is Eq? (1), "|", " ")
                    End If
                End If
            Next
            Put a Newl
        Next
    Next
    For (x = 1, var(x) Is Le?(width), ++x)
        Print("+---"); //# bottom row
    Next
    Print("+", Newl); //# bottom right corner
Return

# Given a direction, get its opposite.
function getOppositeDir(d) {
    if (d == top) return bottom;
    if (d == bottom) return top;
    if (d == left) return right;
    if (d == right) return left;
}
 
# Build a list (string) of the four directions in random order.
function getRandDirList(    dirList, randDir, nx, ny, idx) {
    dirList = "";
    while (length(dirList) < 4) {
        randDir = getRandDir();
        if (!index(dirList, randDir)) {
            dirList = dirList randDir;
        }
    }
    return dirList;
}
 
# Get x coordinate of the neighbor in a given a direction.
function getNextX(x, dir) {
    if (dir == left) x = x - 1;
    if (dir == right) x = x + 1;
    if (!isGoodXY(x, 1)) return -1; # Off the edge.
    return x;
}
 
# Get y coordinate of the neighbor in a given a direction.
function getNextY(y, dir) {
    if (dir == top) y = y - 1;
    if (dir == bottom) y = y + 1;
    if (!isGoodXY(1, y)) return -1; # Off the edge.
    return y;
}
 
# Mark a cell as visited.
function setVisited(x, y,    cell) {
    cell = getCell(x, y);
    if (cell == -1) return;
    cell = substr(cell, 1, 4) "1"; # walls plus visited
    setCell(x, y, cell);
}
 
///# Get the visited state of a cell.
wasVisited(x, y) {
    cell = 0
    Let( cell := _getCell(x, y) )
    If ( var(cell) Is Eq? (-1) ) 
        Return (1) ///# Off edges already visited.
    End If
Return (Mid$(1, 5, _getCell(x,y)))
 
///# Remove a cell's wall in a given direction.
rmWall(x, y, d)
    oldCell = 0
    Let( oldCell := _getCell(x, y))
    If ( var(oldCell) Is Eq?( -1)) 
        Return
    End If
    newCell = ""
    For (i = 1, var(i) Is Le?( 4), ++i) //// # Ugly as concat of two substrings and a constant?.
        Let ( newCell := Cat$(newCell, Get If( var(i) Is Eq?(d), "0", Mid$(1,i,oldCell)) ) )
    Next
    Let( newCell := Cat$(newCell, _wasVisited(x, y)) )
    _setCell(x, y, newCell)
Return
 
hasWall(x, y, d)
    cell = 0
    Let( cell := _getCell(x, y))
    if ( var(cell) Is Eq? (-1) )
       Return (1)   //; # Cells off edge always have all walls.
    End If
Return (Mid$(1, d, _getCell(x, y)))

///# Plunk a cell into the maze.
setCell(x, y, cell)
    If ( Not( _isGoodXY(x, y) ) ) 
       Back
    End If
    Take(cell), At Interval [x, y], SPut(maze)
Return

///# Get a cell from the maze.
getCell(x, y)
    If ( Not(_isGoodXY(x, y)) )
       Return (-1) ///# Bad cell marker.
    End If
Return ( [x, y] Get(maze) )
 
///# Are the given coordinates in the maze?
isGoodXY(x, y)
    If ( Or( Lt(x,1), Gt( x, width) ) )
        Return(0)
    End If
    If ( Or( Lt(y, 1), Gt(y, height) ) )
        Return (0)
    End If
Return (1)


//# Build the empty maze.
resetMaze:
    Dim(height, width) for Zeros Array (maze)
    maze = "11110"
Return(maze)

///# Random things properly scaled.
 
getRandX:
Return ( Add(1, Int( Mul(Rand(1), width) ) ) )
 
getRandY:
Return ( Add(1, Int( Mul(Rand(1), height) ) ) )
 
getRandDir:
Return ( Add(1, Int( Mul(Rand(1), 4) ) ) )
 
randomize:
  Seed(1234)
Return



