// Leetcode-47 : Permutations II

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void helper(vector<vector<int>> &result, vector<int> &nums, int idx){
    if(idx==nums.size()){
        result.push_back(nums);
        return;
    }

    unordered_set<int> st;
    int i = idx;
    while(i<nums.size()){
        if(st.count(nums[i])==0){
            swap(nums[idx], nums[i]);
            st.insert(nums[i]);
        }
        else{
            i++;
            continue;
        }
        helper(result, nums, idx+1);
        swap(nums[idx], nums[i]);
        i++;
    }
}

int main(){
    vector<int> nums; // duplicate integers are allowed
    cout<<"Enter the elements of nums(Type -1 to stop):\n";
    
    int x;
    while (cin >> x && x != -1) {
        nums.push_back(x);
    }

    vector<vector<int>> result;
    helper(result, nums, 0);

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}