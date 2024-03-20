#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void solve(int col,vector<string>&boards,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&upperdiagonal,vector<int>&lowerdiagonal,int n){
    if(col==n){
        ans.push_back(boards);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && upperdiagonal[n-1+col-row]==0 && lowerdiagonal[row+col]==0){
            boards[row][col]='Q';
            leftrow[row]=1;
            upperdiagonal[n-1+col-row]=1;
            lowerdiagonal[row+col]=1;
            solve(col+1,boards,ans,leftrow,upperdiagonal,lowerdiagonal,n);
            boards[row][col]='.';
            leftrow[row]=0;
            upperdiagonal[n-1+col-row]=0;
            lowerdiagonal[row+col]=0;
        }
    }
}
vector<vector<string>> solvequeens(int n){
    vector<vector<string>>ans;
    vector<string>boards(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        boards[i]=s;
    }
    vector<int>leftrow(n,0);
    vector<int>upperdiagonal(2*n-1,0);
    vector<int>lowerdiagonal(2*n-1,0);
    solve(0,boards,ans,leftrow,upperdiagonal,lowerdiagonal,n);
    return ans;

}
int main() {
  int n = 4;
  vector < vector < string >> ans = solvequeens(n);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
