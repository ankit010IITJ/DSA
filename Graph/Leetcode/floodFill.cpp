// Leetcode-733 : Flood Fill

#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &image, int sr, int sc, int rowS, int colS, int startClr, int color){
    if(sr<0 || sr>rowS-1) return;
    if(sc<0 || sc>colS-1) return;
    if(image[sr][sc]!=startClr) return;
    image[sr][sc] = color;
    helper(image, sr, sc+1, rowS, colS, startClr, color);
    helper(image, sr+1, sc, rowS, colS, startClr, color);
    helper(image, sr, sc-1, rowS, colS, startClr, color);
    helper(image, sr-1, sc, rowS, colS, startClr, color);
}

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;

    cout<<"Before change in image"<<"\n";
    for(int i=0; i<image.size(); i++){
        for(int j=0; j<image[0].size(); j++){
            cout<<image[i][j]<<" ";
        }
        cout<<"\n";
    }

    // if(image[sr][sc]==color) return image; -> uncomment in leetcode
    int rowS = image.size();
    int colS = image[0].size();
    int startClr = image[sr][sc];
    helper(image, sr, sc, rowS, colS, startClr, color);

    
    cout<<"After change in image"<<"\n";
    for(int i=0; i<image.size(); i++){
        for(int j=0; j<image[0].size(); j++){
            cout<<image[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}