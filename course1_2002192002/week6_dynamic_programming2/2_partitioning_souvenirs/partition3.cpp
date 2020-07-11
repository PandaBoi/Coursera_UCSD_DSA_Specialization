#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;



int partition3(vector<int> &A) {
  //write your code here
	int sum = 0;
	for ( auto x :A)
		sum += x;

	if (sum%3 != 0)
		return false;
	
	int cols = sum/3+1;
	int rows = A.size() +1;
	int T[rows][cols];





	// for(int i =0;i<rows;i++)
	// 	T[i][0] =1;

	for(int j =0;j<cols;j++){
		for(int i =0;i<rows;i++){

			if (j==0)
				T[i][j] = 1;
			else
				T[i][j] = 0;
		}
	}


	for(int i =1;i<=A.size();i++){
		for(int j =1;j<=sum/3;j++){
			T[i][j] = T[i-1][j];

			if(j >= A[i-1])
				T[i][j] = T[i][j] || T[i-1][j-A[i-1]];
		}

	}

	// for(int i =0;i<rows;i++){
	// 	for(int j =0;j<cols;j++){
	// 		cout<< T[i][j] <<' ';
	// 	}
	// 	cout << '\n';
	// }




  return T[A.size()][sum/3];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
