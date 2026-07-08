// DFS - Depth First Search

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v; // no of vertices

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void dfs(int curr, int end, vector<int> &path){
    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr); // marked visited
    path.push_back(curr);
    for(auto neighbour : graph[curr]){
        if(!(visited.count(neighbour))){
            dfs(neighbour, end, path);
        }
    }

    path.pop_back();
    visited.erase(curr);
    return;
}

void allPath(int src, int dest){
    vector<int> v;
    dfs(src, dest, v);
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
    graph.resize(v, list<int> ());
    int e;
    cout<<"Enter the no. of vertices: ";
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }

    int x, y;
    cout<<"Enter the value of x and y: ";
    cin>>x>>y;

    allPath(x, y);
    for(int i=0; i<result.size(); i++){
        for(auto ele : result[i]){
            cout<<ele<<" -> ";
        }
        cout<<endl;
    }

    return 0;
}