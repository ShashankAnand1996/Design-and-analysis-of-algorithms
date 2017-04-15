#include <bits/stdc++.h>
using namespace std;
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(int x[],int y[],int p, int q, int r)
{
    int val = (y[q] - y[p]) * (x[r] - x[q]) -
              (x[q] - x[p]) * (y[r] - y[q]);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// Prints convex hull of a set of n points.
void convexHull(int x[],int y[], int n)
{
    // At least 3 points are required
    if (n < 3) return;
 
    // Initialize Result
    int hullx[n];
    int hully[n]; 
 
    // Find the leftmost point
    int l = 0, i;
    for (i = 1; i < n; i++)
       {
        if (x[i] < x[l])
            l = i;
       }
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    int k=0;
    do
    {
       
        // Add current point to result
        hullx[k]=x[p];
        hully[k]=y[p];
        k=k+1;
 
        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%n;

        for (i = 0; i < n; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientation(x,y,p,i,q) == 2)
               q = i;
        }
 
        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;
 
    } while (p != l);  // While we don't come to first point
 
    // Print Result
    for (i = 0; i < k; i++)
        cout << "(" << hullx[i] << ", "
              << hully[i] << ")\n";
}
 
// Driver program to test above functions
int main()
{
   int x[7]={0,2,1,2,3,0,3};
   int y[7]={3,2,1,1,0,0,3};
    int n = sizeof(x)/sizeof(x[0]);
    convexHull(x,y,n);
    return 0;
}
