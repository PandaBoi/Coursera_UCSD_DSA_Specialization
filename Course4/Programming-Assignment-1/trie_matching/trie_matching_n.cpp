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



trie build_trie(const vector<string> & patterns) {
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

bool prefix_matching(const string& text, int start_pt,trie& t){

	int idx = start_pt;
	char c = text[idx];
	int current_node = 0;

	while(1){
		edges curr_edge = t[current_node];
		// cout<<"current_node "<<current_node<<endl;
		if(curr_edge.size()==0){
			// cout<<"LOL1"<<endl;
			return true;
		}
		else if(curr_edge.find(c) != curr_edge.end()){
			// cout<<"LOL2"<<endl;
			current_node = t[current_node][c];
			idx ++;

			if(idx < text.size())
				c = text[idx];
			else
				c = '$';

		}
		else{
			// cout<<"LOL3"<<endl;
			return false;
		}
	}

}

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;
	trie t = build_trie(patterns);
  	// for (size_t i = 0; i < t.size(); ++i) {
	  //   for (const auto & j : t[i]) {
	  //     std::cout << i << "->" << j.second << ":" << j.first << "\n";
	  //   }
  	// }
	for (int i =0;i<text.size();i++){
		if(prefix_matching(text,i,t))
			result.push_back(i);
	}
	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
