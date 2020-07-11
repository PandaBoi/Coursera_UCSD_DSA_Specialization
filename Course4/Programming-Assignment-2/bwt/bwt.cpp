#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


void leftrotate(string &s, int d) 
{ 
    reverse(s.begin(), s.begin()+d); 
    reverse(s.begin()+d, s.end()); 
    reverse(s.begin(), s.end()); 
} 
  
// In-place rotates s towards right by d 
string rightrotate(string &s, int d) 
{ 
	string ss = s;
   leftrotate(ss, ss.length()-d); 
   return ss;
} 
  
bool sortByChar (string& a, string& b){

	if(a[0] == '$')
		return true;
	if(b[0] == '$')
		return false;

	if(a[0] == b[0]){
		int i =1;
		while(a[i] == b[i])
		{
			i++;
		}
		return a[i]<b[i];
	}

	return a[0] < b[0];
}

string BWT(string& text) {
  
  string result = "";
  std::vector<string> matrix;
  matrix.push_back(text);

  for(int i =0 ;i<text.length()-1;i++){

  	string s = rightrotate(text,i+1);
  	matrix.push_back(s);
  }
  // cout<<endl;
  // for(auto s: matrix)
  // 	cout<< s<<endl;
  // cout<<endl;

  sort(matrix.begin(),matrix.end(),sortByChar);
  
  // cout<<endl;
  // for(auto s: matrix)
  // 	cout<< s<<endl;
  // cout<<endl;


  for(int i =0;i<matrix.size();i++)
  	result += matrix[i][matrix[i].length()-1];




  // write your code here

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}