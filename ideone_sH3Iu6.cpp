#include<bits/stdc++.h>
using namespace std;
int lis_fun( vector<int>& arr, int n )
{
    int *lis;
    lis = (int*) malloc ( sizeof( int ) * n );
    for (int i = 0; i < n; i++ )
        lis[i] = 1;
    
    for (int i = 0; i < n; i++ ){
	    int *list1;
	    list1 = (int*) malloc ( sizeof( int ) * n );
	    for (int m = 0; m < n; m++ ){
		list1[m] = 1;}
	    vector<int> array;
	    for(int k=0;k<n;k++){
	    	 array.push_back(arr[(i+k)%n]);}
	    for(int j=1;j<n;j++){
			if(array[j]<=array[0])
				list1[j] = 0;
			else{
				for(int k=0;k<j;k++){
					if(array[k] < array[j] && list1[j] <= list1[k] + 1)
						list1[j] = list1[k] + 1;
				}
			}		
		}
	    int max = list1[0];
	    for(int k = 1;k<n;k++){
		if(list1[k]>max)
			max = list1[k];}
	    free(list1);
	lis[i] = max;
    }
    int max = lis[0];
    int max_index = 1;
    for(int i=1;i<n;i++){
		if(max<lis[i]){
			max = lis[i];
			max_index = i+1;
		}	
	}
    free(lis);
 
    return max_index;
}
 
/* Driver program to test above function */
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		vector <int> vec;
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			vec.push_back(x);
		}
	int result = lis_fun(vec,n);
	cout<<result<<endl;
	}
   return 0;
}
