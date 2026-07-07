// Leetcode-2169 : Count Operations to Obtain Zero

#include<iostream>
using namespace std;

int main(){
    int num1, num2;
    cout<<"Enter the value of num1: ";
    cin>>num1;
    cout<<"Enter the value of num2: ";
    cin>>num2;

    int steps = 0;
    while(num1!=0 && num2!=0){
        if(num1>=num2) num1 = num1-num2;
        else num2 = num2 - num1;
        steps++;
    }
    
    cout<<"Operation required to come to zero is: "<<steps;
    cout<<endl;

    return 0;
}