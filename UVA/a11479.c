#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, t, edge[3]; //t������ƶq
	
	fflush(stdin);
	scanf("%d", &t);
	
	for(i = 1; i <= t; i++)
	{
		scanf("%d %d %d", &edge[0], &edge[1], &edge[2]);
		
		if( abs(edge[0]-edge[1]) >= edge[2] || abs(edge[1]-edge[2]) >= edge[0] || abs(edge[0]-edge[2]) >= edge[1] )
	        printf( "Case %d: Invalid\n", i ); 		//�o�T��L�k�Φ��@�ӤT���� 
	    else if( edge[0] == edge[1] && edge[1] == edge[2] )
	        printf( "Case %d: Equilateral\n", i ); 	//�T�䧡���� 
	    else if( edge[0] == edge[1] || edge[1] == edge[2] || edge[2] == edge[0] )
	        printf( "Case %d: Isosceles\n", i ); 	//�������䵥�� 
	    else printf( "Case %d: Scalene\n", i ); 	//�T�䧡������ 
	}
		
	return 0;
}
