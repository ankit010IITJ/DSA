// Leetcode-1342 : Number of Steps to Reduce a Number to Zero

#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the value of num: ";
    cin>>num;

    int steps = 0;
    while(num>0){
        if(num%2==0) num /= 2;
        else num -= 1;
        steps++;
    }
    
    cout<<"No. of steps required to reduce to zero is: "<<steps;
    cout<<endl;

    return 0;
}