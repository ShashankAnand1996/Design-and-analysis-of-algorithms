#include<bits/stdc++.h>
using namespace std;
// hort[i][j]= 0 if there is bad path between (i-1,j) to (i,j) else 1
// vert[i][j]= 0 if there is bad path between (i,j-1) to (i,j) else 1

long path(int n, int m, string s[],int t)
{
     int i, j;
     long long tp[m+1][n+1];  
     long long hort[m+1][n+1];
     long long vert[m+1][n+1];
 
     tp[0][0] = 1;
     
     for (i = 0; i <= m; i++)
     {
          for (j = 0; j <= n; j++)
          { 
                vert[i][j] = 1;
                hort[i][j] = 1;
          }
     }    
     for(int i=0;i<t;i++){
        int a,b,c,d;
	string word = s[i];
	string str = " ";
	a  = atoi((word.substr(0,word.find(str))).c_str());
	word.erase(0,(word.substr(0,word.find(str))).length()+1);
	b = atoi((word.substr(0,word.find(str))).c_str());
	word.erase(0,(word.substr(0,word.find(str))).length()+1);
	c = atoi((word.substr(0,word.find(str))).c_str());
	word.erase(0,(word.substr(0,word.find(str))).length()+1);
	d = atoi((word.substr(0,word.find(str))).c_str());
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	if(a==c){
		vert[d][a] = 0;
	}
	else{
		hort[b][c] = 0;
	}
     }
     for (i = 1; i <= m; i++)
     {
          if(vert[i][0]==0)
		tp[i][0] = 0;
	  else
		tp[i][0] = tp[i-1][0];
     }
      for (j = 1; j <= n; j++)
     {
          if(hort[0][j]==0)
		tp[0][j] = 0;
	  else
		tp[0][j] = tp[0][j-1];
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
int main(){
int w = 6;
int h = 6;
string s[] = {"0 0 0 1","5 6 6 6"};
int n = sizeof(s)/sizeof(s[0]);
//cout<<n<<endl;
int result = path(w,h,s,n);
cout<<result<<endl;
return 0;
}
