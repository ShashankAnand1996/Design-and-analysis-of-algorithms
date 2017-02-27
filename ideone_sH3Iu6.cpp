#include<stdio.h>
#include<stdlib.h>
#include<vector>
int lis( vector<int>& arr, int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    /* Free memory to avoid memory leak */
    free(lis);
 
    return max;
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
			vec.push_back(x);
		}
	int result = lis(vec,n);
	cout<<result<<endl;
	}
   return 0;
}