// Leetcode-2139 : Minimum Moves to Reach Target Score

#include<iostream>
using namespace std;

int main(){
    int target, maxDoubles;
    cout<<"Enter the value of target: ";
    cin>>target;
    cout<<"Enter the value of maxDoubles: ";
    cin>>maxDoubles;

    if(maxDoubles==0) return (target-1);
    int steps = 0;
    while(target>1){
        if(target%2==0 && maxDoubles){
            target /= 2;
            maxDoubles--;
            steps++;
        }
        else if(target%2!=0){
            target -= 1;
            steps++;
        }
        else{ // maxDoubles becomes zero
            steps += (target-1);
            break;
        }
    }

    cout<<"The minimum operations required to reach target from 1 is: "<<steps;
    cout<<endl;

    return 0;
}