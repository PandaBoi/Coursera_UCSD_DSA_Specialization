#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;
using namespace std;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.

std::vector<int> prefix_fn(string& text){
	std::vector<int> s(text.length(),0);
	int border = 0;

	for(int i =1;i<text.length();i++){

		while(border > 0 && text[i] != text[border])
			border = s[border-1];

		if( text[i] == text[border])
			border++;
		else
			border = 0;
		s[i] = border;
		// cout<<i<<" "<<s[i]<<endl;
	}

	return s;
} 

vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  std::vector<int> s;
  string str = pattern + '$' + text;
  s = prefix_fn(str);
  // for(auto x:s)
  // 	cout<<x<<" ";
  // cout<<endl;
  for(int i = pattern.length()+1;i<str.length();i++){

  	if(s[i] == pattern.length())
  		result.push_back(i - 2*pattern.length());

  }

  // Implement this function yourself
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
