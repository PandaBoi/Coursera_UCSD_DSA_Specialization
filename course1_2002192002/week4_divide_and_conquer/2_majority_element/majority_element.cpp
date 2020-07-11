#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int count (std::vector<int>& a, int left, int right,int key){

  int c = 0;
  for (int i = left; i<=right;i++){
    if (a[i] == key)
      c++;

  }
  return c;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left +1 == right) return a[left];

  int mid = left + (right - left)/2;
  //write your code here
  int y = get_majority_element(a,mid + 1,right);
  int z = get_majority_element(a,left,mid );

  int y_count = 0;
  int z_count = 0;
  
  // cout <<"y "<< y<<' '<<"z "<<z<<'\n';
  
  if(y == -1 && z != -1){
    z_count = count(a,left,right,z);
    if (z_count > (right - left )/2)
      return z;
    else
      return -1;
  }

  if(z == -1 && y != -1){
    y_count = count(a,left,right,y);
    if (y_count > (right - left )/2)
      return y;
    else
      return -1;
  }


  if(y != -1 && z != -1){
    y_count = count(a,left,right,y);
    z_count = count(a,left,right,z);

    if (z_count > (right - left )/2)
      return z;
    else if (y_count > (right - left )/2)
      return y;
    else
      return -1;
  }

    

  



  

  return -1;
}

int get_majority_element_another (std::vector<int>& a,int left,int right){ // only if present
  int m;
  int i = 0;

  for (int j =left; j < right;j++){

    if (i == 0){
      m = a[j];
      i =1;
    }
    else (m == a[j]) ? i++ : i--;
  }
  return m;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
