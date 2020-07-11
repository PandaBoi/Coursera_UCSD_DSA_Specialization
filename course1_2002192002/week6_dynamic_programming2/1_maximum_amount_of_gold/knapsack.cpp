#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;

// int optimal_weight(int W, const vector<int> &w) {
//   //write your code here
//   int current_weight = 0;
//   for (size_t i = 0; i < w.size(); ++i) {
//     if (current_weight + w[i] <= W) {
//       current_weight += w[i];
//     }
//   }
//   return current_weight;
// }

int optimal_weight(int W,const std::vector<int>& w){

	std::vector<std::vector<int>> T(w.size()+1, std::vector<int>(W+1,0)) ;

	for (size_t i =0;i<=w.size();i++){
		for(size_t j = 0; j <= W;j++){

			T[i][j] = 0;
		}
	}

	for (size_t i =1; i<= w.size(); i++){
		for(size_t j = 1; j <= W; j++){
			T[i][j] = T[i-1][j];


			if(w[i-1]<=j){
		
				T[i][j] =  max( T[i][j] , T[i-1][j-w[i-1]] + w[i-1] );
			}
	

		}
	}

	// for (size_t i =0;i<=w.size();i++){
	// 	for(size_t j = 0; j <= W;j++){

	// 		cout << T[i][j] << ' ';

	// 	}
	// 	cout << endl;
	// }

	return T[w.size()][W];


}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
