#include <iostream>
using namespace std;

int maximum(int x, int y) {  return (x > y) ? x : y; }
 
// Function to return longest Zig-Zag subsequence length
int zigzag(int arr[], int n)
{
	 
    int result = 1;
    
    int Zig[n][2];
 
    /* Minimum value of zigzag sequence will be at least 1  */
    for (int i = 0; i < n; i++)
        Zig[i][0] = Zig[i][1] = 1;
 
    for (int i = 1; i < n; i++)
    {
        // Consider all elements as previous of arr[i]
        for (int j = 0; j < i; j++)
        {
         
            if (arr[j] < arr[i] && Zig[i][0] < Zig[j][1] + 1)
                Zig[i][0] = Zig[j][1] + 1;
                
            if( arr[j] > arr[i] && Zig[i][1] < Zig[j][0] + 1)
                Zig[i][1] = Zig[j][0] + 1;
        }

        if (result < maximum(Zig[i][0], Zig[i][1]))
            result = maximum(Zig[i][0], Zig[i][1]);
    }
 
    return result;
}
 

int main() {
	 int arr[] = { 90, 33, 49, 50, 31, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of Longest Zig-Zag subsequence is %d\n",
            zigzag(arr, n) );
	return 0;
}