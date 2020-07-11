#include <algorithm>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using std::vector;
using std::pair;
using namespace std;

int CLOCK = 1;
struct prepost{
  int idx;
  int time;
};

void pre_post_visit(std::vector<prepost>& pre_post_visited,int i){
  pre_post_visited[i].idx= i;
  pre_post_visited[i].time = CLOCK;
  // cout<<"CLOCK"<<endl;
  // cout<<pre_post_visited[i].idx<<" "<<pre_post_visited[i].time<<endl;
  CLOCK = CLOCK + 1;
}

void explore(std::vector<std::vector<int>>& adj,std::vector<int>& visited,
        vector<prepost>& pre_visited,vector<prepost>& post_visited,int i){

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
void explore_2(std::vector<std::vector<int>>& adj,
                std::vector<int>& visited,int i){

  visited[i] = 1;
  // cout<< " visit num in explore_2 "<<visit_num<<endl;
  for(int j = 0;j <adj[i].size();j++){
    if(visited[adj[i][j]] == 0){
      // cout<<" exploring "<<adj[i][j]<<endl;
      explore_2(adj,visited,adj[i][j]);
    }
  }

}

bool prepost_sort(  const prepost& a,const prepost& b){
  return a.time > b.time;
}

int number_of_strongly_connected_components(vector<vector<int> >& adj,std::vector<std::vector<int> >& adj_r,int n) {
  int result = 0;
  //write your code here
  std::vector<int> visited(n,0);
  std::vector<prepost> pre_visited(n,{0,0});
  std::vector<prepost> post_visited(n,{0,0});

  for(int i = 0;i < n;i++){
    if(visited[i] == 0){
      // pre_post_visit(pre_visited,i);
      explore(adj,visited,pre_visited,post_visited,i);
      pre_post_visit(post_visited,i);
    }
  }

  // for(int j =0;j<n;j++)
  //  cout<< post_visited[j].time<<" ";
  // cout<<" That was post_visited"<<endl;


  std::vector<int> visited_2(n,0);
  int scc_num = 1;

  sort(post_visited.begin(),post_visited.end(),prepost_sort);

  // for(int j =0;j<n;j++)
  //  cout<< post_visited[j].time<<" ";
  // cout<<" That was post_visited"<<endl;

  for(int i =0;i<n;i++){

    
    // for(auto x: post_visited)
    //  cout<< x<< " ";
    // cout<<" That was post_visited"<<endl;
    int visit_num = 0;

    if(visited_2[post_visited[i].idx] == 0){
      explore_2(adj_r,visited_2,post_visited[i].idx);
      
      scc_num +=1;
    }
    
    // cout<< visit_num<<endl;
  }

  // for(auto x: visited_2)
  //   cout << x << " ";
  // cout <<endl;

  return scc_num - 1;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  std::vector<std::vector<int>> adj_r(n,std::vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj_r[y-1].push_back(x - 1);

  }
  std::cout << number_of_strongly_connected_components(adj,adj_r,n);
}
