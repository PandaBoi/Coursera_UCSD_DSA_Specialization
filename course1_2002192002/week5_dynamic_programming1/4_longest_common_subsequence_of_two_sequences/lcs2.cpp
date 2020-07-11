#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
using std::string;

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
	int T[a.size() + 1][b.size() + 1];

	for (size_t i =0 ; i<= a.size();i++){
		for(size_t j =0;j<= b.size();j++){

			if (i == 0 || j == 0)
				T[i][j]= 0;
			else
				T[i][j] = 0;
		}
	}

	for (size_t i =1 ; i<= a.size();i++){
		for(size_t j =1;j<= b.size();j++){

			if(a[i-1] == b[j-1])
				T[i][j] = max(T[i][j],T[i-1][j-1]+1);
			else
				T[i][j] = max(max(T[i][j],T[i-1][j]),T[i][j-1]);
		}
	}



  return T[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
