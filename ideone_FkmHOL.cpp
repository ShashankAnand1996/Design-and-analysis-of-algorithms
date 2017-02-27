#include <iostream>
using namespace std;
int path(int cost[R][C], int m, int n)
{
     int i, j;
     
     int tp[R][C];  
 
     tc[0][0] = cost[0][0];
     
     for (i = 1; i <= m; i++)
        if(hori[i][0]==1)
        	{ tp[i][0] = 1;}
 
     for (j = 1; j <= n; j++)
        {
        	if(vert[0][j]==1)
        	{ tp[0][j] = 1;}
        	
        }
     /* Construct rest of the tp array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tp[i][j] = tp[i-1][j-1]+tp[i-1][j];
 
     return tp[m][n];
}
 

/* Driver program to test above functions */
int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", path(cost, 2, 2));
   return 0;
}