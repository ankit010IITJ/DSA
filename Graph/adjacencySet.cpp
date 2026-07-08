#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<unordered_set<int>> graph;
// unordered_set in case of unordered_map for unweighted graph

int v; // no of vertices

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].insert(dest);
    if(bi_dir){
        graph[dest].insert(src);
    }
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto el : graph[i]){
            cout<<el<<" , ";
        }
        cout<<"\n";
    }
}

int main(){
    cout<<"Enter the no. of vertices: ";
    cin>>v;
    graph.resize(v, unordered_set<int> ());
    int e;
    cout<<"Enter the no. of edges: ";
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }

    display();

    return 0;
}