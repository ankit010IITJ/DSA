// Leetcode-841 : Keys and Rooms

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

// Method-I : Applying BFS
bool bfs(vector<vector<int>> &rooms){
    unordered_set<int> visited;
    queue<int> q;
    int curr = 0;
    visited.insert(0);
    q.push(0);
    while(!(q.empty())){
        int curr = q.front();
        q.pop();
        for(auto neighbour : rooms[curr]){
            if(!(visited.count(neighbour))){
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
    return (visited.size()==rooms.size());
}


// Method-II : Applying DFS
void dfs(vector<vector<int>>& rooms, int room, vector<bool> &visited){
    visited[room] = true;
    for(auto next : rooms[room]){
        if(!(visited[next])){
            dfs(rooms, next, visited);
        }
    }
}

int main(){
    vector<vector<int>> rooms1 = {{1,3},{3,0,1},{2},{0}}; // give false
    vector<vector<int>> rooms2 = {{1},{2},{3},{}}; // give true

    bool flag1 = bfs(rooms1);
    bool flag2 = true;

    vector<bool> visited(rooms2.size(), false);
    dfs(rooms2, 0, visited);
    for(int i=0; i<visited.size(); i++){
        if(!visited[i]){
            flag2 = false;
            break;
        };
    }

    if(flag1) cout<<"There exists a way to reach all the rooms of rooms1";
    else cout<<"There is no way to reach all the rooms of rooms1";
    cout<<"\n";


    if(flag2) cout<<"There exists a way to reach all the rooms of rooms2";
    else cout<<"There is no way to reach all the rooms of rooms2";
    cout<<"\n";

    return 0;
}