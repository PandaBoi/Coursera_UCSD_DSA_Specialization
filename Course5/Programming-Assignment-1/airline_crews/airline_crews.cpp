#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using std::vector;
using std::cin;
using std::cout;
using namespace std;

class MaxMatching {
 public:
  void Solve() {
    vector<vector<bool>> adj_matrix = ReadData();
    vector<int> matching = FindMatching(adj_matrix);
    WriteResponse(matching);
  }

 private:
  vector<vector<bool>> ReadData() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> adj_matrix(N, vector<bool>(M));
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) {
        int bit;
        cin >> bit;
        adj_matrix[i][j] = (bit == 1);
      }
    return adj_matrix;
  }

  void WriteResponse( vector<int>& matching) {
    for (int i = 0; i < matching.size(); ++i) {
      if (i > 0)
        cout << " ";
      if (matching[i] == -1)
        cout << "-1";
      else
        cout << (matching[i] + 1);
    }
    cout << "\n";
  }

  bool bipartiteMatch(int u,std::vector<int>& assign,std::vector<bool>& visited,
                    std::vector<int>& matching,std::vector<std::vector<bool>>& adj_matrix){
    // cout<< endl;
    // cout<<"u is "<<u<<endl;
    for(int i =0;i<visited.size();i++){
      
      // cout<<u<<" "<<i<<endl;
      // for(auto x:visited)
      //   cout<<x<<" ";
      // cout<<endl;
      // for(auto x:assign)
      //   cout<<x<<" ";
      // cout<<endl;
      // cout<<endl;
      
      if(adj_matrix[i][u] && !visited[i]){
        visited[i] = true;
            
        if(assign[i]<0 || bipartiteMatch(assign[i],assign,visited,matching,adj_matrix)){
          assign[i] = u;
          matching[u] = i;
          return true;
        }
      } 
    }
    return false;
  }

  vector<int> FindMatching(vector<vector<bool>>& adj_matrix) {
    // Replace this code with an algorithm that finds the maximum
    // matching correctly in all cases.
    int N = adj_matrix.size();
    int M = adj_matrix[0].size();
    vector<int> matching(N, -1);
    // vector<bool> busy_right(M, false);
    vector<int> assign(N, -1);
    std::vector<bool> visited(N,false);
    
    // for (int i = 0; i < N; ++i)
    //   for (int j = 0; j < M; ++j)
    //     if (matching[i] == -1 && !busy_right[j] && adj_matrix[i][j]) {
    //       matching[i] = j;
    //       busy_right[j] = true;
    //     }

    for(int i =0;i<M;i++){
      fill(visited.begin(),visited.end(),false);
      // cout<<"going bipartiteMatch"<<endl;
      bool tp = bipartiteMatch(i,assign,visited,matching,adj_matrix);
      // cout<<"after bipartiteMatch"<<endl;
      // for(auto x:assign)
      //   cout<<x<<" ";
      // cout<<endl;


    }



    return matching;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  MaxMatching max_matching;
  max_matching.Solve();
  return 0;
}
