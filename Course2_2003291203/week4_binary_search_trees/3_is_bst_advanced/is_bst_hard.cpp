#include <algorithm>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long key;
  long long left;
  long long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, long long left_, long long right_) : key(key_), left(left_), right(right_) {}
};


bool is_binary(const std::vector<Node>& tree,int root, long long min, long long max){

	if(tree.size()<=1)
		return true;
	if(root == -1)
		return true;
	
	if(tree[root].key<min || tree[root].key>max)
		return false;

	return is_binary(tree,tree[root].left,min,tree[root].key-1) && is_binary(tree,tree[root].right,tree[root].key,max);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
	

	
  return is_binary(tree,0,INT_MIN,INT_MAX);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
	long long key, left, right;
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
