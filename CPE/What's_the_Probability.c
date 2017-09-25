/* 
 Ref: 1. http://minstrel-uva.blogspot.tw/2011/10/acm10056.html
      2. http://awesq123.pixnet.net/blog/post/103273280-uva10056---what-is-the-probability-%28cpe%E4%B8%80%E9%A1%86%E6%98%9F%E9%81%B8%E9%9B%86%29
      3. http://samchien.blogspot.tw/2013/04/10056-what-is-probability.html
      4. http://www.cnblogs.com/scau20110726/archive/2013/02/04/2892176.html
*/

#include <stdio.h>
#include <math.h>

#define IS_ZERO(X) ((X) > -0.000001 && ((X) < 0.000001))

double GetPlayerProbability(int, double, int);

int main(int argc, char *argv[])
{
    int times, players, winner;
    double probability;
    
    fflush(stdin);
    while (~scanf("%d", &times)) {
        while (times--) {
            scanf("%d %lf %d", &players, &probability, &winner);
            printf("%.4f\n", GetPlayerProbability(players, probability, winner));
        }
    }

    return 0;
}

double GetPlayerProbability(int players, double p, int winner)
{
    if (IS_ZERO(p)) return 0.0000;

    if (winner == 1)
        return p / (1 - pow(1 - p, players));
    else
        return (pow(1 - p, players - 1) * p) / (1 - pow(1 - p, players));  
}
