#include <iostream>
#include <vector>

using std::vector;
using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int i =1;
  while(n>0){
    
    if (i==1){
      summands.push_back(i);
      n -=1;
    }
    
    while(n>0 && (n >= i+1)){
      summands.push_back(i+1);
      n -= i+1;
      i++;
    }

    if (n>0 &&(n < i+1)){
      // cout << "IN!" << '\n';
      summands[i-1] += n;
      n =0;
    }

  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
