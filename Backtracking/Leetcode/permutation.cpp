// Leetcode-46: Permutations

#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &result, vector<int> &nums, int idx){
    if(idx==nums.size()){
        result.push_back(nums);
        return;
    }

    int i = idx;
    while(i<nums.size()){
        swap(nums[idx], nums[i]);
        helper(result, nums, idx+1);
        swap(nums[idx], nums[i]);
        i++;
    }
}

int main(){
    vector<int> nums; // only distinct integers
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