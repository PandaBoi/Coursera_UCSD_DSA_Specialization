#include <cstdio>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
	Node* parent;
	Node* left;
	Node* right;

	char c;
	int key;
  int size;

	Node(char c,int size, int key, Node* parent,Node* left,Node* right):
	c(c),size(size), key(key), parent(parent), left(left), right(right){}
};

void print_tree(Node* root,Node* start){
  if(start == NULL) return;
  print_tree(root,start->left);
  cout<< " node key: "<< start->key<<" node char "<< start->c <<" node size "<<start->size<<endl;
  print_tree(root,start->right);
  // cout<<endl;
}


void update(Node* n){
	// cout<<"2"<<endl;
	if(n == NULL) return;

	n->size = (n->left != NULL ? n->left->size  :0) +  (n->right != NULL ? n->right->size  :0) + 1 ;

	if(n->left !=NULL)
		n->left->parent = n;
	if(n->right != NULL)
		n->right->parent = n;


}

void small_rotation(Node* n) {
	// cout<<"3"<<endl;
  Node* parent = n->parent;
 
  if (parent == NULL) {
    return;
  }
 
  Node* grandparent = n->parent->parent;
 
  if (parent->left == n) {
    Node* m = n->right;
    n->right = parent;
    parent->left = m;
  } 

  else {
    Node* m = n->left;
    n->left = parent;
    parent->right = m;
  }
  update(parent);
  update(n)	;
  n->parent = grandparent;
  
  if (grandparent != NULL) {
    if (grandparent->left == parent) {
      grandparent->left = n;
    } else {
      grandparent->right = n;
    }
  }

}

void big_rotation(Node* n) {
	// cout<<"4"<<endl;
  if (n->parent->left == n && n->parent->parent->left == n->parent) {
    // Zig-zig
    small_rotation(n->parent);
    small_rotation(n);
  } else if (n->parent->right == n && n->parent->parent->right == n->parent) {
    // Zig-zig
    small_rotation(n->parent);
    small_rotation(n);
  } else {
    // Zig-zag
    small_rotation(n);
    small_rotation(n);
  }  
}

void splay(Node*& root, Node* n) {
  if (n == NULL) return;
  // cout<<"5"<<endl;
  while (n->parent != NULL) {
    if (n->parent->parent == NULL) {
      small_rotation(n);
      break;
    }
    big_rotation(n);
  }
  root = n;
}

Node* find(Node*& root, int key) {
  Node* n = root;
  
  if(n == NULL) return NULL;

  // int s = (n->left != NULL ? n->left->size:0);
 
  // if (key == s){
  //   // splay(root,n);
  //   return n;
  // }
  // else if(key<s){
  //   Node* temp = find(n->left,key  );
    
  //   // splay(n,temp);
  //   return temp;
        
  // }
  // else{
  //   Node* temp = find(n->right,key - s );
  //   // if(n->right)
  //   //   n = n->right;
  //   // else
  //   //   break;
  //   // splay(n,temp);
  //   return temp;
  // }

  while(n!= NULL){
    int s; Node* candidate;
   
    if(n->left!=NULL){
      s = n->left->size;
      candidate = n->left;
    }
    else if(n->right!=NULL){

      s = n->right->size;
      candidate = n->right;
    }
    else{
      s = 0;
      candidate =  n->left;
    }
    cout<< " s "<<s<<" key "<<key<<endl;
    
    if(key == s)
      return n;
    if(key<s){
      
      n = candidate;


    }
    else{
      n =  candidate;
      key = key ;
    }
  }
  return n;
  // splay(root,n);
  // return n;
}

void split(Node* root, int key, Node*& left, Node*& right) {
  // cout<<"7"<<endl;
  right = find(root, key);
  if(right!=NULL)
  cout<<" find returns "<<right->c<<" "<<right->key<<endl;
  else
    cout<<" find returned null"<<endl;
  // cout<<" left splay in split"<<endl;
  // print_tree(root,root);
  splay(root, right);
  // cout<<" in split"<<endl;
  // Node* start = root;
  // print_tree(root,root);

  if (right == NULL) {
    left = root;
    return;
  }
  left = right->left;
  right->left = NULL;
  if (left != NULL) {
    left->parent = NULL;
  }
  update(left);
  update(right);
  cout<<" split finished "<<endl;
}

Node* merge(Node* left, Node* right) {
	// cout<<"8"<<endl;
  if (left == NULL) return right;
  if (right == NULL) return left;
  Node* min_right = right;
  while (min_right->left != NULL) {
    min_right = min_right->left;
  }
  splay(right, min_right);
  right->left = left;
  update(right);
  return right;
}

Node* root = NULL;


void insert(char c,int x) {
  Node* left = NULL;
  Node* right = NULL;
  Node* new_vertex = NULL;
  // cout<<"started"<<endl;  
  split(root, x, left, right);
  if (right == NULL || right->key != x) {
    new_vertex = new Node(c,1, x, NULL, NULL, NULL);
  }
  // cout<<"node made"<<endl;
  root = merge(merge(left, new_vertex), right);
  // Node* start = root;
  // print_tree(root,start);
}

Node* make_tree(string s){
	
	int siz = s.size();
	// cout<<s<<endl;
	for( int i =0 ; i < siz ; i++){
		// cout<< s[i]<<" ";
		insert(s[i],i);
	}
}

class Rope {
	std::string s;
	
public:
	Rope(const std::string &s) : s(s) { 

		make_tree(s);
		// Node* start = root;
		print_tree(root,root);
    // Node* temp = find(root,1);
    // splay(root,temp);
    // cout<<endl;
    // print_tree(temp,temp);

	}

	void process( int i, int j, int k ) {
        // Replace this code with a faster implementation
        // std::string t = s.substr(0, i) + s.substr(j + 1);
        // s = t.substr(0, k) + s.substr(i, j - i + 1) + t.substr(k);
		Node* left = NULL;
		Node* mid = NULL;
		Node* right = NULL;
		Node* place_to_insert = NULL;


        split(root,i,left,mid);
        
        cout<<"first split"<<endl;
        print_tree(left,left);
        cout<<"------"<<endl;
        print_tree(mid,mid);
        cout<<"------"<<endl;
       
        split(mid,j,mid,right);
        cout<<"second split"<<endl;
        // cout<<mid->right->c<<endl;
        print_tree(mid,mid);
        cout<<"------"<<endl;
		    print_tree(right,right);
        cout<<"------"<<endl;

       
        Node* after_removal = merge(left,right);
        Node* tmp = after_removal;
        while(tmp->left != NULL)
          tmp = tmp->left;
        splay(after_removal,tmp);
        // full_update(after_removal);

        cout<<"after merge with removal"<<endl;
        print_tree(after_removal,after_removal);
        cout<<"------"<<endl;
  			print_tree(mid,mid);
        cout<<"------"<<endl;
        Node* before_2 = NULL;
        Node* after_2 = NULL;
        split(after_removal,k+1,before_2,after_2);
        // full_update(after);

        cout<<"after split with removal"<<endl;
        print_tree(before_2,before_2);
        cout<<"------"<<endl;
        print_tree(after_2,after_2);
        cout<<"------"<<endl;
  

        // Node* root_1 = merge(left,till); 
        // full_update(root_1);
         // cout<<endl;
         // while(prev(root_1)!= NULL)
         //  root_1 = prev(root_1);
        // full_update(root_1);
        // cout<<root->c<<root->key;
        // print_tree(root_1,root_1);
        // Node* root_2 = merge(root_1,after);
        // cout<<endl;
        // cout<<root->c<<root->key;
        // print_tree(root_2,root_2);
        root = merge(merge(before_2,mid),after_2);
        // full_update(root);
        // cout<<endl;
        // cout<<after->c<<after->key;
        // print_tree(after,after);



	}

	std::string result() {
		// Node* start = root;
		print_tree(root,root);
	}
};

int main() {
	std::ios_base::sync_with_stdio(0);
	std::string s;
	std::cin >> s;
	Rope rope(s);
	int actions;
	std::cin >> actions;
        for (int action_index = 0; action_index < actions; ++action_index) {
                int i, j, k;
		std::cin >> i >> j >> k;
		rope.process(i, j, k);
	}
	std::cout << rope.result() << std::endl;
}
