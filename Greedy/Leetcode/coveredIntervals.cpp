// Leetcode-1288 : Remove Covered Intervals

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0])
        return a[1] > b[1]; // larger end first
    return a[0]<b[0];
}

void helper(vector<vector<int>> &intervals, vector<vector<int>> &mergedV){
    
    for(int i=1; i<intervals.size(); i++){
        if((intervals[i][0]<=mergedV[mergedV.size()-1][1]) && (intervals[i][1]<=mergedV[mergedV.size()-1][1])){
            continue;
        }
        else{
            mergedV.push_back(intervals[i]);
        }
    }
}

int main(){
    vector<vector<int>> intervals = {{1,2}, {1,4}, {2,8}};
    
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> mergedV;
    mergedV.push_back(intervals[0]);
    helper(intervals, mergedV);

    cout<<mergedV.size()<<"\n";

    return 0;
}