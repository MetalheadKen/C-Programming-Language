#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, t, edge[3]; //t代戈计秖
	
	fflush(stdin);
	scanf("%d", &t);
	
	for(i = 1; i <= t; i++)
	{
		scanf("%d %d %d", &edge[0], &edge[1], &edge[2]);
		
		if( abs(edge[0]-edge[1]) >= edge[2] || abs(edge[1]-edge[2]) >= edge[0] || abs(edge[0]-edge[2]) >= edge[1] )
	        printf( "Case %d: Invalid\n", i ); 		//硂娩礚猭Θà 
	    else if( edge[0] == edge[1] && edge[1] == edge[2] )
	        printf( "Case %d: Equilateral\n", i ); 	//娩А单 
	    else if( edge[0] == edge[1] || edge[1] == edge[2] || edge[2] == edge[0] )
	        printf( "Case %d: Isosceles\n", i ); 	//Τㄢ娩单 
	    else printf( "Case %d: Scalene\n", i ); 	//娩Аぃ单 
	}
		
	return 0;
}
