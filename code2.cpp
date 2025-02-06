#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int tpSort(int n,vector<vector<int>>& edges,vector<int>& deg,vector<int>& ans){
  queue<int> q;
  for(int i=0;i<n;++i){
    if(!deg[i]){
      q.push(i);
    }
  }
  while(!q.empty()){
    int u=q.front();
    q.pop();
    ans.push_back(u);
    for(int i=0;i<edges[u].size();++i){
      int v=edges[u][i];
      deg[v]--;
      if(!deg[v]){
        q.push(v);
      }
    }
  }
  if(ans.size()==n){
    return 1;
  }
  return 0;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> edges(n,vector<int>(n,0));
  vector<int> deg(n,0),ans,dp(n,0);
  while(m--){
    int u,v;
    cin>>u>>v;
    edges[u-1].push_back(v-1);
    deg[v-1]++;
  }
  for(const auto& ele:ans){
    cout<<ele<<endl;
  }
  int result=tpSort(n,edges,deg,ans);
  if(result){
    for(int i=ans.size()-1;i>=0;--i){
      int u=ans[i];
      for(int j=0;j<edges[u].size();++j){
        int v=edges[u][j];
        dp[u]=max(dp[u],dp[v]+1);
      }
    }
    cout<<dp[ans[0]]<<endl;
  }else{
    cout<<-1<<endl;
  }
  return 0;
}
