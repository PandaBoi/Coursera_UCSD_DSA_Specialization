#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using std::vector;
using namespace std;

typedef struct sack{

  int weight;
  int value;
  double frac;


}sack;

bool compareByFrac(const sack &a, const sack &b)
{
    return a.frac > b.frac ;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  
  double value = 0.0;
  std::vector<sack> stack;
  // write your code here
  int n = values.size();
  for (int i =0; i < n; i++ ){

    stack.push_back(
      {weights[i],
        values[i],
        ((double)values[i]/weights[i])}
        );
  }
  
  sort(stack.begin(), stack.end(), compareByFrac);

  for (int i =0; i< n ;i ++){

    if (capacity == 0)
      return value;

    double cap = min(stack[i].weight,capacity);

    value += cap*stack[i].frac;
    stack[i].weight -= cap;
    capacity -= cap;

  }



  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
