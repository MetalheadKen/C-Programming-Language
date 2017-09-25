#include <stdio.h>
#include <stdbool.h>

#define LENGTH 101
#define MAX_COORDINATE 51

#define IS_LOST(X, Y, ROW, COLUMN) ((X) < 0 || (X) > (ROW) || (Y) < 0 || (Y) > (COLUMN))

typedef struct _Robot {
    int  x;
    int  y;
    char orientation;
} Robot;

int row, column;

bool MoveRobot(Robot *, char *, bool [][MAX_COORDINATE]);

int main(int argc, char *argv[])
{
    Robot robot;
    bool lostTable[MAX_COORDINATE][MAX_COORDINATE] = {0};
    
    fflush(stdin);
    scanf("%d %d%*c", &row, &column);

    while (~scanf("%d %d %c%*c", &robot.x, &robot.y, &robot.orientation)) {
        char command[LENGTH];

        scanf("%s%*c", command);
        bool lost = MoveRobot(&robot, command, lostTable);
    
        printf("%d %d %c", robot.x, robot.y, robot.orientation);
        if (lost) printf(" LOST");

        printf("\n");
    }

    return 0;
}

bool MoveRobot(Robot *robot, char *command, bool lostTable[][MAX_COORDINATE])
{
    bool lost = false;

    for (int i = 0; command[i]; i++) {
        switch (command[i]) {
            case 'L':
                switch (robot->orientation) {
                    case 'N': robot->orientation = 'W'; break;
                    case 'E': robot->orientation = 'N'; break;
                    case 'W': robot->orientation = 'S'; break;
                    case 'S': robot->orientation = 'E'; break;
                }
                break;
            case 'R':
                switch (robot->orientation) {
                    case 'N': robot->orientation = 'E'; break;
                    case 'E': robot->orientation = 'S'; break;
                    case 'W': robot->orientation = 'N'; break;
                    case 'S': robot->orientation = 'W'; break;
                }
                break;
            case 'F':
                switch (robot->orientation) {
                    case 'N':
                        lost = IS_LOST(robot->x, robot->y + 1, row, column);
                        if (!lost) robot->y++;

                        break;
                    case 'E':
                        lost = IS_LOST(robot->x + 1, robot->y, row, column);
                        if (!lost) robot->x++;
                        
                        break;
                    case 'W':
                        lost = IS_LOST(robot->x - 1, robot->y, row, column);
                        if (!lost) robot->x--;
                        
                        break;
                    case 'S':
                        lost = IS_LOST(robot->x, robot->y - 1, row, column);
                        if (!lost) robot->y--;
                        
                        break;
                }
                break;
        }

        if (lost && !lostTable[robot->x][robot->y]) {
            lostTable[robot->x][robot->y] = true;
            break;
        }
    }

    return lost;
}
