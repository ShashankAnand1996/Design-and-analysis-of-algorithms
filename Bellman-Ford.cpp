// A C++ program for Bellman-Ford's Algorithm for the shortest path in a graph.
 
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

using namespace std;
 
// Weighted edge in graph


// A utility function used to print the solution
void print(int dist[], int n)
{
    cout<<"Vertex   Distance from Source\n";
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// main function
void BellmanFord(int V, int E, int start, int E1[],int E2[],int W[])
{
    int dist[V];
 
    // Step 1: Initialize distances from start to all other vertices
    // as INFINITE
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[start] = 0;
 
    // Relaxation on all edges |V| - 1 times
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = E1[j];
            int v = E2[j];
            int weight = W[j];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    // Check for negative-weight cycles
    for (int i = 0; i < E; i++)
    {
        int u = E1[i];
        int v = E2[i];
        int weight = W[i];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            cout<<"Graph contains negative weight cycle";
    }
 
    print(dist, V);
 
    return;
}


int main () 
{
int v=5;
int e=8;
int E1[8]={0,0,1,1,1,3,3,4};
int E2[8]={1,2,2,3,4,2,1,3};
int W[8]={-1,4,3,2,2,5,1,-3};
BellmanFord(v, e, 0,E1,E2,W);
return 0;
}
