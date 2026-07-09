// Leetcode-1791 : Find Center of Star Graph

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> edges = {{1,2},{5,1},{1,3},{1,4}};

    if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]) cout<<edges[0][0];
    else cout<<edges[0][1];

    cout<<"\n";

    return 0;
}