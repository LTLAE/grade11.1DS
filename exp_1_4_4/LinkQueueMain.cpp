#include "LinkQueue.h"

QueueNode *path;

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

int main() {
    InitQueue(path);
    int mazeProgress[10][10] = {0};
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            mazeProgress[x][y] = maze[x][y];
        }
    }
    //position, 1, 1 as start
    EnQueue(path, 1, 1, -1, -1);
    path->x = path->y = -1;
    mazeProgress[1][1] = 2;

    QueueNode *scanner;
    int pos = 1;  //pos how many EnQueues per time and move *scanner according to pos
    while (true) {
        scanner = path;
        int count = pos;
        for (; pos != 0; pos--) scanner = scanner->next;
        for (; count != 0; count--) {
            if (mazeProgress[scanner->x - 1][scanner->y] == 0) {  //up
                EnQueue(path, scanner->x - 1, scanner->x, scanner->x, scanner->y);
                mazeProgress[scanner->x - 1][scanner->y] = 2;
                pos++;
            }
            if (mazeProgress[scanner->x][scanner->y + 1] == 0) {  //right
                EnQueue(path, scanner->x, scanner->y + 1, scanner->x, scanner->y);
                mazeProgress[scanner->x][scanner->y + 1] = 2;
                pos++;
            }
            if (mazeProgress[scanner->x + 1][scanner->y] == 0) {  //down
                EnQueue(path, scanner->x + 1, scanner->y, scanner->x, scanner->y);
                mazeProgress[scanner->x + 1][scanner->y] = 2;
                pos++;
            }
            if (mazeProgress[scanner->x][scanner->y - 1] == 0) {  //left
                EnQueue(path, scanner->x, scanner->y - 1, scanner->x, scanner->y);
                mazeProgress[scanner->x][scanner->y - 1] = 2;
                pos++;
            }
            if (path->front->x == 8 && path->front->y == 8) {
                // FlipQueue(path);    DeQueue(path);   //debug, GetFront(path)
                goto output; //here I can't find a convenience way to jump two whiles, output: at line 63
            }
            if (scanner->last == path){
                cout << "Path notfound." << endl;
                abort();
            }
            scanner = scanner->last;
        }
    }
    //output result
    output:
    FlipQueue(path);
    while (QueueEmpty(path) == 0) {
        for (scanner = path->rear->last;scanner->x != path->rear->lastX || scanner->y != path->rear->lastY; scanner = scanner->last);
        DeQueue(path);
        for (;path->rear != scanner; SlientDeQueue(path));
    }
    scanner = nullptr;
    delete scanner;
    Destroy(path);
}