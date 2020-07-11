#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> opti_sequence(int n){
	int T[n+1];
	vector<int> ans;

	for (size_t i =0; i<=n;i++){
		T[i] = INT_MAX;
	}
	T[0] = -1;
	T[1] = 0;

	for (size_t i = 2;i<=n;i++){
		if(i%3 == 0)
			T[i] = min(min(T[i],1+T[i/3]),1+T[i-1]);
		else if(i%2 == 0)
			T[i] = min(min(T[i],1+T[i/2]),1+T[i-1]);
		else
			T[i] = min(T[i],1+T[i-1]);

	}

	int idx = T[n];

	for (size_t i =n; i>=0;i--){

		if (T[i] == idx){
			ans.push_back(i);
			idx--;
		}
		if (idx == -1)
			break;

	}

	reverse(ans.begin(),ans.end());
	// for(size_t i = 0;i<=n;i++){
	// 	cout << T[i]<< ' ';
	// }
	// cout << T[n] ;
	// cout << endl;

	return ans; 
}

int main() {
  int n;
  std::cin >> n;
  // opti_sequence(n);
  vector<int> sequence = opti_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
