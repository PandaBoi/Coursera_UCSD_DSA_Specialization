#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  queue<int> Q;
  Q.push(0);
  std::vector<int> visited(adj.size(),0);
  std::vector<int> color(adj.size(),-1);
  color[0] = 0;

  while(Q.size()!=0){
    int current = Q.front();
    Q.pop();
    visited[current] = 1;

    for(int i =0;i<adj[current].size();i++){
      
      if(visited[adj[current][i]]!=0 && color[adj[current][i]] == color[current] ){
        return 0;

      }
      if(visited[adj[current][i]] == 0){
        Q.push(adj[current][i]);
        visited[adj[current][i]] = 1;
        color[adj[current][i]] = (color[current] + 1 )% 2;
      }
   
    }

  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
