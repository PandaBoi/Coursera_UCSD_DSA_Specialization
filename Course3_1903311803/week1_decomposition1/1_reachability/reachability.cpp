#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;

void explore(std::vector<std::vector<int>> adj,std::vector<int>& visited,int i){

	visited[i] = 1;
	for(int j = 0;j <adj[i].size();j++){
		if(visited[adj[i][j]] == 0){
			// cout<<" exploring "<<adj[i][j]<<endl;
			explore(adj,visited,adj[i][j]);
		}
	}

}

int reach(vector<vector<int> > &adj, int x, int y,int n) {
  //write your code here
	std::vector<int> visited(n,0);

	
		
	explore(adj,visited,x);
		

	// for( auto x: visited)
	// 	cout<<x<<" ";
	return visited[y];
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1,n);
}
