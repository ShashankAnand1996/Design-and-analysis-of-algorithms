#include <iostream>
using namespace std;
// hort[i][j]= 0 if there is bad path between (i-1,j) to (i,j) else 1
// vert[i][j]= 0 if there is bad path between (i,j-1) to (i,j) else 1

int path(int m, int n)
{
     int i, j;
     
     int tp[m][n];  
     int hort[m][n];
     int vert[m][n];
 
     tp[0][0] = 0;
     
     for (i = 1; i <= m; i++)
     {
          for (j = 1; j <= n; j++)
          { 
                vert[i][j] = 1;
                hort[i][j] = 1;
          }
     }    
     for (i = 1; i <= m; i++)
     {
          for (j = 1; j <= i; j++)
          { 
               if(hori[j][0]==0)
        	     { tp[i][0] = 1;}
          }
     }
      for (j = 1; i <= n; j++)
     {
          for (i = 1; i <= j; i++)
          { 
               if(vert [0][0]==0)
        	     { tp[i][0] = 1;}
          }
     }
     
     for (i = 1; i <= m; i++)
     {
          for (j = 1; j <= n; j++)
          {
                if(hort[i][j]==0 && vert[i][j]==0)
                { tp[i][j]=0; }
               else if(hort[i][j]==0)
                { tp[i][j] = tp[i][j-1]; }
               else if(vert[i][j]==0)
                { tp[i][j] = tp[i-1][j]; }
               else 
                { tp[i][j]=tp[i][j-1] + tp[i-1][j]; }
          }
      }     
     return tp[m][n];
}
 

/* Driver program to test above functions */
int main()
{ int width, height;
 cin>>width;
 cin>>height;
   int bad[][] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", path(width, height));
   return 0;
}
