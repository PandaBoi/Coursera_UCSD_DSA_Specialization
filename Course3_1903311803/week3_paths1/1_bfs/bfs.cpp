#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here

	queue<int> Q;
	Q.push(s);
	std::vector<int> visited(adj.size(),0);
	std::vector<int> distance(adj.size(),-1);
	distance[s] = 0;
	while(Q.size()!=0){
		
		int current = Q.front();
		Q.pop();
		visited[current] = 1;
		// distance[current] = dist;
		
		
		for(int i =0; i < adj[current].size();i++){
			if(visited[adj[current][i]] == 0){
				Q.push(adj[current][i]);
				visited[adj[current][i]] = 1;
				distance[adj[current][i]] = distance[current] + 1;
			}
		}
		

	}
	// for(auto x : distance)
	// 	cout << x<< " ";

  return distance[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
