#include<iostream>
#include<vector>
using namespace std;


vector<vector<pair<int,int>>> graph;
// instead of pair we can have int in case of unweighted graph

int v; // no of vertices
void add_edge(int src, int dest, int wt, bool bi_dir = true){
    graph[src].push_back({dest, wt});
    if(bi_dir){
        graph[dest].push_back({src, wt});
    }
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto el : graph[i]){
            cout<<"("<<el.first<<" "<<el.second<<")"<<" , ";
        }
        cout<<"\n";
    }
}

int main(){
    cout<<"Enter the no. of vertices: ";
    cin>>v;
    graph.resize(v, vector<pair<int,int>> ());
    int e;
    cout<<"Enter the no. of edges: ";
    cin>>e;
    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;
        add_edge(s, d, wt); // send false to make the graph directed
    }

    display();

    return 0;
}