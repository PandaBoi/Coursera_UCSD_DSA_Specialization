#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std;

bool giveGreater ( const string &a, const string &b){
  int i =0;

  while(i <min(a.length(),b.length()) ){

    if(a[i]>b[i])
      return true;

    else if (a[i] == b[i])
      i++;

    else if (a[i]<b[i])
      return false;

  }

  if (a.length()>b.length()){

    if(a[a.length()-1] > b[a.length()-2])
      return true;
    else
      return false;
  }

  if (b.length()>a.length()){

    if(b[b.length()-1] > a[b.length()-2])
      return false;
    else
      return true;
  }






}

string largest_number(vector<string> a) {
  //write your code here

  sort(a.begin(),a.end(),giveGreater);

  // for (size_t i = 0; i < a.size(); i++) {
  //   cout << a[i]<< ' ';
  // }
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
