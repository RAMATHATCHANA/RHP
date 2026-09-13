#include <bits/stdc++.h>
using namespace std;
int main(){
  int R,C;cin>>R>>C;
  vector<vector<int>> arr(R,vector<int>(C,0));
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin>>arr[i][j];
    }
  }
  int diff[8][2]={
  {-1,-1},{-1,0},{-1,1},
  {0,-1},        {0,1},
  {1,-1}, {1,0}, {1,1}
  };
  int r,c;cin>>r>>c;
  int sum=0;
  for(const auto& d:diff){
    int ar=r+d[0];
    int ac=c+d[1];
    if(ar>=0 && ac>=0 && ar<R && ac<C){
      sum+=arr[ar][ac];
    }
  }
  cout<<sum<<"\n";
  return 0;
}
