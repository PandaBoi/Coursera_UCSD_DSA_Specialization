#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void in_order_traverse(const std::vector<Node>& tree,int root,std::vector<int>& order,int* flag){


  if(root == -1) return;
  
  // cout<<root<<" "<<tree[root].left<<" "<<tree[root].right<<" "<<*flag<<endl;
  
  if(*flag == 1) return;
 
  *flag = 0;
  in_order_traverse(tree,tree[root].left,order,flag);

  if(order.size()){
    
      if(tree[root].key>order.back()){
      
      order.push_back(tree[root].key);

    }
    else{
      *flag = 1;
    }

  }
  else
    order.push_back(tree[root].key);

  in_order_traverse(tree,tree[root].right,order,flag);


  return;


}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.size()<=1)
    return true;
  std::vector<int> order;
  int flag = 0;
  in_order_traverse(tree,0,order,&flag);
  // for(auto x:order)
  //   cout<<x<<" ";

  return !flag;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } 
  else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
