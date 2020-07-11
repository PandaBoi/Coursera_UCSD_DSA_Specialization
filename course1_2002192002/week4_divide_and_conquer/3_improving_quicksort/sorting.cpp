#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <bits/stdc++.h>
using std::vector;
using std::swap;
using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      // cout << i << ' '<< j<<'\n';
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void  partition3 (std::vector<int>& a, int l, int r,int &i,int &j){

  if(r - l <= 1){
    if (a[r] < a[l])
      swap(a[r],a[l]);
    i = l;
    j = r;
    return;

  }

  int key = a[l];
  int curr = l;

  while(curr <=r){
    cout <<"l "<<l<<" curr "<<curr<<'\n';
    for (auto i : a){
      cout << i <<" ";
    }
    cout << '\n';

    cout << '\n';
    
    if(a[curr]<key)
      swap(a[l++],a[curr++]);
    
    else if (a[curr] == key)
      curr++;
    
    else if(a[curr]>key)
      swap(a[curr],a[r--]);

  }
  i = l-1;
  j = curr;
  return;

}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    // cout << "IN";
    return;
  }

  // int k = l + rand() % (r - l + 1);
  // swap(a[l], a[k]);
  // int m = partition2(a, l, r);

  int i,j;
 
  partition3(a,l,r,i,j);

  randomized_quick_sort(a, l, i);
  randomized_quick_sort(a, j, r);
  // for (auto i : a){
  //   cout << i <<" ";
  // }
  // cout << '\n';

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
