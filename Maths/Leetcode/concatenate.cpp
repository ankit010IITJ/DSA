// Leetcode-3754 : Concatenate Non-Zero Digits and Multiply by Sum I

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // Take n of more than one digit and include 0 also
    // eg n = 10075, n = 840, n = 10, etc
    int n;
    cout<<"enter the value of n: ";
    cin>>n;

    long long x = 0;
    int temp = 0;
    vector<int> tempV;
    while(n>0){
        temp = n%10;
        n /= 10;
        tempV.push_back(temp);
    }

    int sum = 0;
    reverse(tempV.begin(), tempV.end());
    for(int i=0; i<tempV.size(); i++){
        if(tempV[i]!=0){
            x *= 10;
            x += tempV[i];
            sum += tempV[i];
        }
    }

    cout<<(sum*x)<<"\n";

    return 0;
}