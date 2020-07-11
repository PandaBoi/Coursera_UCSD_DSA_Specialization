#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;
using std::map;
using std::vector;
using std::string;

#define p pair<char,int>
typedef map<char, int> edges;
typedef vector<edges> trie;

// trie build_trie(vector<string> & patterns) {
//   trie t;
//   int x =0;
//   // write your code here

//   for(string pattern : patterns){
//   	int current = 0;
// 	edges edge = t[current];

//   	for(int i =0;i<pattern.size();i++){
  		
//   		char c = pattern[i];
//   		edges edge = t[current];
  		
//   		if(edge.find(c)!= edge.end()){
//   			current = edge[c];
//   		}
//   		else{
//   			x++;
//   			edge[c] = x;
//   			current = x;
//   		}
//   	}
//   	t.push_back(edge);
//   }
//   return t;
  		
// }
trie build_trie(vector<string> & patterns) {
    trie t;
    int counter = 0;
    edges e;
    t.push_back(e);

    for (string pattern : patterns) {
        
        int current_node = 0;
        edges edge = t[current_node];
        for (int i = 0; i < pattern.length(); i++) {
            
            char c = pattern[i];
            edge = t[current_node];
            int lol = edge.find(c) != edge.end();
            // cout<< "checking for "<<c<<" "<<current_node<<endl;
            
            if (lol) {
            	// cout<<"LOLED"<<endl;
                current_node = edge[c];
            } 

            else {
                counter++;
            	// cout<<"LOLED 2"<<endl; 
                t[current_node].insert(p(c,counter));
            	// cout<<"LOLED 2"<<endl; 
                // edge[c] = counter;
                current_node = counter;
                edges ee;
                t.push_back(ee);
            	// cout<<"LOLED 2"<<endl; 

            }
        
        }
        // t.push_back(edge);
    }
	  // for (size_t i = 0; i < t.size(); ++i) {
	  // 	cout<<i<<endl;
	  //   for (const auto & j : t[i]) {
	  //     std::cout << i << "->" << j.second << ":" << j.first << "\n";
	  //   }
	  // }
    return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}