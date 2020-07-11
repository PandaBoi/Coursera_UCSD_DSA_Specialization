#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int get_change(int m) {
  //write your code here
	int change[3] = {1,3,4};
	int count = 0;
	int T[m+1];

	for(size_t i = 0;i<=m;i++){
		T[i] = 1000000;
	}

	T[0] = 0;

	for(size_t i =1; i<= m; i++)

		for (size_t j =0 ; j<3;j++){
			if(i>=change[j]){

				T[i] = min(T[i],1 + T[i - change[j]]);
			}
		}

	// for(size_t i = 0;i<=m;i++){
	// 	cout << T[i]<< ' ';
	// }
	// cout << endl;

  return T[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
