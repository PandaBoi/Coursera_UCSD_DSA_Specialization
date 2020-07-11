#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;

int relax(vector<vector<int>> &adj, vector<long long>& distance ,vector<vector<int>>& cost,int u, int v,vector<int>& prev){
	int w = adj[u][v];
	// cout<<"current distance "<<distance[w]<<" and compared to "<< distance[w] + cost[u][v]<<endl;
	if( distance[w] > distance[u] + cost[u][v] ){
		// cout<<"goin in "<<endl;
		distance[w] = distance[u] + cost[u][v];
		prev[w] = u;
		return 1;

	}
	return -1;

}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
	std::vector<long long> distance(adj.size(),INT_MAX);
	distance[0] = 0;
	std::vector<int> prev(adj.size(),-1);
	int last_node = -1;
	int sum = 0;
	for(int z = 0; z<adj.size();z++){
		if(sum == adj.size())
			break;
		 sum = 0;
		for(int i =0; i<adj.size();i++){
			
			for(int j = 0;j<adj[i].size();j++){
				int v = adj[i][j];
				// cout<<i<<"-->"<<v<<endl;
				int x = relax(adj,distance,cost,i,j,prev);
				// for(auto x:distance)
				// 	cout<< x <<" ";
				// cout<< endl;
				// for(auto x:prev)
				// 	cout<< x <<" ";
				// cout<< endl;
				
				if(z==adj.size()-1 && x == 1)
					return 1;
			}
		}
		
	}

	// for(auto x:prev)
	// 	cout<< x <<" ";
	// cout<< endl;
	// for(auto x:distance)
	// 	cout<< x <<" ";
	// cout<< endl;
	// cout<<"Done with relaxation"<<endl;
	// int x= 0;
	// for(int i =0; i <adj.size();i++){
	// 	x = prev[x];
	// 	if(x==-1)
	// 		break;
	// }
	// 	// cout<<"X is "<<x<<endl;
	// if (x!=-1){
	// 	int y = 0;
	// 	while(x!=y)
	// 		x = prev[x];
	// 	return 1;
	// }




  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
