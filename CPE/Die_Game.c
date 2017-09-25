#include <stdio.h>
#include <string.h>

#define LENGTH 6

typedef struct _Dice {
    int top, bottom;
    int north, east, west, south;

    void (*Roll)(struct _Dice *, char *);
} Dice;

void RollingDice(Dice *, char *);

int main(int argc, char *argv[])
{
    int times;

    fflush(stdin);
    while (~scanf("%d%*c", &times) && times != 0) {
        if (times > 1024) continue;
        
        Dice dice = {
            .top   = 1, .bottom = 6,
            .north = 2, .east   = 3,
            .west  = 4, .south  = 5,
            .Roll = RollingDice
        };
        char command[LENGTH];

        for (int i = 0; i < times; i++) {
            scanf("%s%*c", command + i);
            dice.Roll(&dice, command + i);
        }
        
        printf("%d\n", dice.top);
    }

    return 0;
}

/* If the dice roll to north or south, then variable east and west don't change the value, vice versa */
void RollingDice(Dice *dice, char *command)
{
    int temp;
    if (!strcmp(command, "north")) {
        temp         = dice->top;
        dice->top    = dice->south;
        dice->south  = dice->bottom;
        dice->bottom = dice->north;
        dice->north  = temp;
    } else if (!strcmp(command, "east")) {
        temp         = dice->top;
        dice->top    = dice->west;
        dice->west   = dice->bottom;
        dice->bottom = dice->east;
        dice->east   = temp;
    } else if (!strcmp(command, "west")) {
        temp         = dice->top;
        dice->top    = dice->east;
        dice->east   = dice->bottom;
        dice->bottom = dice->west;
        dice->west   = temp;
    } else if (!strcmp(command, "south")) {
        temp         = dice->top;
        dice->top    = dice->north;
        dice->north  = dice->bottom;
        dice->bottom = dice->south;
        dice->south  = temp;
    }
}
