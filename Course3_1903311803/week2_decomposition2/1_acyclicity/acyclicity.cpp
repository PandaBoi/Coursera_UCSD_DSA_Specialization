#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;
using std::pair;

int CLOCK = 1;
void pre_post_visit(std::vector<int>& pre_post_visited,int i){
	pre_post_visited[i] = CLOCK;
	CLOCK = CLOCK + 1;
}

void explore(std::vector<std::vector<int>> adj,std::vector<int>& visited,
				vector<int>& pre_visited,vector<int>& post_visited,int i){

  visited[i] =1;
  pre_post_visit(pre_visited,i);
  for(int j = 0;j <adj[i].size();j++){
    if(visited[adj[i][j]] == 0){
      // cout<<" exploring "<<adj[i][j]<<endl;
      explore(adj,visited,pre_visited,post_visited,adj[i][j]);
      pre_post_visit(post_visited,adj[i][j]);
    }
  }

}
void explore_2(std::vector<std::vector<int>> adj,std::vector<int>& visited,int i,int& visit_num){

  visited[i] = 1;
  visit_num +=1;
  // cout<< " visit num in explore_2 "<<visit_num<<endl;
  for(int j = 0;j <adj[i].size();j++){
    if(visited[adj[i][j]] == 0){
      // cout<<" exploring "<<adj[i][j]<<endl;
      explore_2(adj,visited,adj[i][j], visit_num);
    }
  }

}

int acyclic(vector<vector<int> > &adj, vector<vector<int>>& adj_r) {
  //write your code here
	std::vector<int> visited(adj.size(),0);
	std::vector<int> pre_visited(adj.size(),0);
	std::vector<int> post_visited(adj.size(),0);

	for(int i = 0;i < adj.size();i++){
		if(visited[i] == 0){
			// pre_post_visit(pre_visited,i);
			explore(adj_r,visited,pre_visited,post_visited,i);
			pre_post_visit(post_visited,i);
		}
	}
	// for(auto x: post_visited)
	// 	cout<< x<< " ";
	// cout<<" That was post_visited"<<endl;

	// for(auto x: pre_visited)
	// 	cout<< x<< " ";
	// cout<<" That was pre_visited"<<endl;
	std::vector<int> visited_2(adj.size(),0);

	for(int i =0;i<post_visited.size();i++){

		int max_idx = max_element(post_visited.begin(),post_visited.end()) - post_visited.begin();
		int visit_num = 0;

		if(visited_2[max_idx] == 0){
			explore_2(adj,visited_2,max_idx, visit_num);
			post_visited[max_idx] = -5;
		}
		if(visit_num > 1){
			// cout<< visit_num<<endl;
			// for(auto x: visited_2)
			// 	cout<<x<<" ";
			// cout<<endl;
			return 1;

		}
		// cout<< visit_num<<endl;
	}







  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adj_r(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj_r[y-1].push_back(x-1);
  }
  std::cout << acyclic(adj,adj_r);
}
