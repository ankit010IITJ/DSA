// ProblemNo - 326 : Power of Three

// Similarly you can solve (Leetcode 342) Power of 4
// And also (Leetcode 231) Power of 2 

#include<iostream>
#include<climits>
using namespace std;

// Method-1
bool powerOfThree1(int n, int temp){
    if(n==temp) return true;
    if(n<temp) return false;

    /*
        Prevent overflow and also temp is last power of 3 before INT_MAX
        and n is greater than it, it means n is not power of 3
    */
    if (temp > INT_MAX / 3) return false;

    temp *= 3;
    bool flag = powerOfThree1(n, temp);
    return flag;
}

// Method-2
bool powerOfThree2(int n){
    if(n==1) return true;
    if(n<=0 || n%3!=0) return false;
    return powerOfThree2(n/3);
}

int main(){
    int n; // -2^31 <= n <= 2^31 - 1
    cout<<"Enter the value of n: ";
    cin>>n;

    // bool flag = powerOfThree1(n, 3);
    bool flag = powerOfThree2(n);

    if(flag) cout<<"Yes "<<n<<" is power of three"<<"\n";
    else cout<<"No "<<n<<" is not a power of three"<<"\n";

    return 0;
}