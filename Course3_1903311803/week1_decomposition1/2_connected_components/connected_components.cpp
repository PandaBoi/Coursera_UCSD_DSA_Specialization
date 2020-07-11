#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;
void explore(std::vector<std::vector<int>> adj,std::vector<int>& visited,int i,int visit_num){

  visited[i] = visit_num;
  for(int j = 0;j <adj[i].size();j++){
    if(visited[adj[i][j]] == 0){
      // cout<<" exploring "<<adj[i][j]<<endl;
      explore(adj,visited,adj[i][j],visit_num);
    }
  }

}

int number_of_components(vector<vector<int> > &adj,int n) {
  int res = 0;
  int visit_num = 1;
  std::vector<int> visited(n,0);
  //write your code here
  for (int i = 0; i < n;i++){
   
    if(visited[i] == 0){
      // cout<<" visit num is "<<visit_num<<endl;
      explore(adj,visited,i,visit_num);
      visit_num += 1;
    }
   
    
  }
  // for(auto x:visited)
  //   cout<<x<<" ";
  // cout << endl;
  return visit_num-1;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj,n);
}
