
// FindClusters.cpp : Defines the entry point for the console application.
//

/*  
 Problem Statement:
 Find the clusters in a 2D matrix of size mxn  containing 1's and 0's and 
return the size of the cluster that  is the biggest

0's can be considered as water and 1's as land
So a  cluster is  all portions of land that are connected
*/

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;


//DFS algo on a 2D matrix to find the strongly connected components in an undirected graph
int Traverse(vector< vector<int> >& v, int i, int j, vector< vector<int> >& visited, int m, int n)
{
    visited[i][j] = 1;
    int neighbours = 0;

    for( int k = (i - 1); k <= (i+1) ; k++)
        for (int l = (j - 1); l <= (j + 1); l++)
        {
            if (k < m && k >= 0 && l < n && l >= 0)
            {
                if (!visited[k][l] && v[k][l])
                    neighbours += Traverse(v, k,l,visited,m,n);
            }
        }

    return v[i][j] ? neighbours + 1 : neighbours;

}

int FindMaximumSizeCluster(vector< vector<int> >& v, int m, int n)
{
    vector< vector<int> > visited(m, vector<int>(n, 0));
    int maxClusterSize = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = Traverse(v, i, j, visited, m, n);
            if (maxClusterSize < temp)
                maxClusterSize = temp;
        }
    }
    return maxClusterSize;
}



int main()
{
    int m, n;
    m = 7; n = 7;

    vector<vector<int> > V = { {1,0,1,1,1,1,1},
                               {1,0,1,1,1,1,0},
                               {1,0,0,0,0,0,0},
                               {1,1,1,1,1,1,0},
                               {1,0,0,0,0,1,0},
                               {1,0,0,0,1,0,0},
                               {1,1,1,1,0,0,0}
                              };

    //for (int i = 0; i < m; i++)
    //{
    //    V[i][0] = 1;
    //    V[i][1] = 0;
    //    V[i][2] = 1;

    //}
    //V[2][1] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << V[i][j];
        }
        cout << endl;
    }

    cout <<"Max SizeCluster :"<<FindMaximumSizeCluster(V, m, n);

    return 0;
}

