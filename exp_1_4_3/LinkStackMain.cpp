#include "LinkStack.h"

StackNode *path;

//1 as wall, 0 as space, 1,1 start, 8,8 end
const int maze[10][10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
                          1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
                          1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
                          1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
                          1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
                          1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
                          1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
                          1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void findpath() {
    InitStack(path);
    //copy maze
    int mazeProgress[10][10] = {0};
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            mazeProgress[x][y] = maze[x][y];
        }
    }
    int x = 1, y = 1;    //position, 1, 1 as start
    Push(path, x, y);
    mazeProgress[x][y] = 2;
    //search sequence: up, right, down, left
    //set walked path as 2
    while (x != 8 || y != 8) {
        if (mazeProgress[x - 1][y] == 0) {  //up
            x = x - 1;
            mazeProgress[x][y] = 2;
            Push(path, x, y);
        } else if (mazeProgress[x][y + 1] == 0) {  //right
            y = y + 1;
            mazeProgress[x][y] = 2;
            Push(path, x, y);
        } else if (mazeProgress[x + 1][y] == 0) {  //down
            x = x + 1;
            mazeProgress[x][y] = 2;
            Push(path, x, y);
        } else if (mazeProgress[x][y - 1] == 0) {  //left
            y = y - 1;
            mazeProgress[x][y] = 2;
            Push(path, x, y);
        } else {    //when dead end, move back to last available path while block all front paths
            while (mazeProgress[x - 1][y] != 0 && mazeProgress[x][y + 1] != 0 && mazeProgress[x + 1][y] != 0 &&
                   mazeProgress[x][y - 1] != 0) {
                mazeProgress[GetTopX(path)][GetTopY(path)] = 1;
                SlientPop(path);  //when debugging using Pop()
                if(StackEmpty(path)==1){
                    cout << "Path notfound." << endl;
                    abort();
                }
                x = GetTopX(path);
                y = GetTopY(path);
            }
        }
    }
    //path found
    for (; StackEmpty(path) == 0; Pop(path));
    DestroyStackNode(path);
}

int main() {
    findpath();
}