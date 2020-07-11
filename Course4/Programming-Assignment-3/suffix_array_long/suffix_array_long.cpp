#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

#define NUM_CHARS 5

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.

int letterToIndex (char letter)
{
	switch (letter)
	{	
		case '$': return 0; break;
		case 'A': return 1; break;
		case 'C': return 2; break;
		case 'G': return 3; break;
		case 'T': return 4; break;
		default: assert (false); return -1;
	}
}

std::vector<int> sort_chars(string& S){
	std::vector<int> order(S.length(),0);
	std::vector<int> count(NUM_CHARS,0);

	for(int i =0;i<S.length();i++){
		count[letterToIndex(S[i])]++;
	}

	for(int i =1;i<NUM_CHARS;i++){
		count[i] += count[i-1];
	}

	for(int i = S.length() - 1;i>=0;i--){
		
		int idx = letterToIndex(S[i]);
		count[idx]--;
		order[count[idx]] = i;
	}

	return order;

}


std::vector<int> compute_class(string& S, std::vector<int>& order){
	std::vector<int> classes(S.length(),0);
	classes[order[0]] = 0;

	for(int i =1;i<S.length();i++){
		if( S[order[i]] != S[order[i-1]] )
		classes[order[i]] = classes[order[i-1]] +1;
		else
			classes[order[i]] = classes[order[i-1]];
	}

	return classes;
}

std::vector<int> sort_doubled(string& S,int L,std::vector<int>& order,std::vector<int>& classes
					){

	std::vector<int> count(S.length(),0);
	std::vector<int> newOrder(S.length(),0);
	for(int i =0;i<S.length();i++){
		count[classes[i]]++;
	}
	for(int i =1;i<S.length();i++)
		count[i] += count[i-1];

	for(int i = S.length()-1;i>=0;i--){

		int start = (order[i]-L+ S.length()) % S.length();
		int cl = classes[start];
		count[cl]--;
		newOrder[count[cl]] = start;
	}
	return newOrder;
}

std::vector<int> update_class(std::vector<int>& newOrder,
							std::vector<int>& classes, int L){

	int n = newOrder.size();
	std::vector<int> newClass(n,0);
	newClass[newOrder[0]] = 0;
	int curr,prev,mid,midPrev;
	for(int i =1;i<n;i++){
		 curr = newOrder[i];
		 prev = newOrder[i-1];
		 mid = (curr +L)%n;
		 midPrev = (prev+L)%n;

		 if(classes[curr] != classes[prev] || classes[mid] != classes[midPrev] )
		 	newClass[curr] = newClass[prev]+1;
		 else
		 	newClass[curr] = newClass[prev];

	}
	return newClass;
}

vector<int> BuildSuffixArray( string& text) {
  // vector<int> result;
  // Implement this function yourself
  std::vector<int> order;
  order = sort_chars(text);
  // cout<<"order done "<<endl;

  std::vector<int> classes;
  classes = compute_class(text,order);
  // cout<<"compute_class done "<<endl;
  int L = 1;

  while( L < text.length()){
  	// cout<<" curr L is "<<L<<endl;
  	order = sort_doubled(text,L,order,classes);
  	// cout<<"sort_doubled done "<<endl;
  	classes = update_class(order,classes,L);
  	// cout<<"update_class done "<<endl;
  	L = L*2;
  }
  // cout<<"while ended "<<endl;
  // for(auto x:order)
  // 	cout<<x<<" ";
  // cout<<endl;
  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
