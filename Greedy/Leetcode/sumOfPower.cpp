// Leetcode-1780 : Check if Number is a Sum of Powers of Three

#include<iostream>
#include<cmath>
using namespace std;

/*
    pow function uses double which store data like floating-point,
    not alway but with bigger value, so when a bigger pow of 3 calculated
    it will be become floating and its int value ignore the value after decimal
*/

bool checkFunc(int n){
    int maxP = 0;
    while(n>pow(3,maxP)) maxP++;

    while(maxP>=0 && n>0){
        int temp = pow(3,maxP);
        if(n>=temp){
            n -= temp;
        }
        maxP--;
    }

    if(n==0) return true;
    else return false;
}

bool checkFunc2(int n){
    int powerValue = 1;
    while(n>(powerValue*3)) powerValue *= 3;

    while(powerValue>0 && n>0){
        if(n>=powerValue){
            n -= powerValue;
        }
        powerValue /= 3;
    }

    if(n==0) return true;
    else return false;
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    bool flag = checkFunc2(n);
    if(flag) cout<<"Yes, "<<n<<" can be represented as sum of powers of three";
    else cout<<"No, "<<n<<" cann't be represented as sum of powers of three";
    cout<<endl;

    return 0;
}