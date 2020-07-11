#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;
using namespace std;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order_traverse(std::vector<int>& result,int root){
  	if(root ==- 1)
  		return;
  	in_order_traverse(result,left[root]);
  	result.push_back(key[root]);
  	in_order_traverse(result,right[root]);
  }


  vector <int>  in_order() {
  	// for(auto x: key)
  	// 	cout <<x<<" ";
  	// cout<<endl;
  	// cout<<endl;
  	// for(auto x: left)
  	// 	cout <<x<<" ";
  	// cout<<endl;
  	// cout<<endl;
  	// for(auto x: right)
  	// 	cout <<x<<" ";
  	// cout<<endl;
  	// cout<<endl;
    vector<int> result;

    in_order_traverse(result,0);
    
    return result;
  }

  void pre_order_traverse(std::vector<int>& result,int root){
  	if(root ==- 1)
  		return;
  	result.push_back(key[root]);
  	pre_order_traverse(result,left[root]);
  	pre_order_traverse(result,right[root]);
  }

  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    pre_order_traverse(result,0);
    return result;
  }

  void post_order_traverse(std::vector<int>& result,int root){
  	if(root ==- 1)
  		return;
  	
  	post_order_traverse(result,left[root]);
  	post_order_traverse(result,right[root]);
  	result.push_back(key[root]);
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    post_order_traverse(result,0);
    
    return result;
  }
    	
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  // t.in_order();
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

