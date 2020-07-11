#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

using std::vector;

long long merge(vector<int> &x, vector<int> &y, size_t left,size_t middle, size_t right){

	long long number_of_inversions = 0;

	int i = left;
	int k = left;
	int j = middle +1;
	// cout << " i " <<i<< " j "<< j << '\n';
	while ( i <=middle && j <= right){

		if ( x[i] > x[j]){
			// cout << "in this";
			y[k] = x[j];
			k++;
			j++;
			number_of_inversions +=  middle-i +1;
		}
		if (x[i] <= x[j]){

			y[k] = x[i];
			k++;
			i++;
		}

	}

	while(i <=middle){
		y[k] = x[i];
		k++;
		i++;

	}

	while(j <=right){
		y[k] = x[j];
		k++;
		j++;

	}
  	
  	// for (auto l : y){
	  // 	cout << l << ' ';
  	// }
  	// cout << '\n';

	for (int i = left;i<k;i++){
		x[i] = y[i];
	}

	return number_of_inversions;

}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
 
  long long number_of_inversions = 0;
 
  if (left  >= right) return number_of_inversions;



 
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);

  // cout << " before merge " << number_of_inversions<<'\n';

  number_of_inversions += merge (a, b, left, ave, right);

  // cout << " after merge " << number_of_inversions<<'\n';



  // for (auto l : a){
  // 	cout << l << ' ';
  // }
  // cout << '\n';



 
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
