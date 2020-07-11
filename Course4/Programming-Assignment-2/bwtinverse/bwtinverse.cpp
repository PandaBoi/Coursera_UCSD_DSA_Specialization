#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


#define p pair<int,char>
#define mp make_pair
#define Node map<int,char> 
typedef vector<p> matrix ;
#define f first
#define s second

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

bool sortByChar (p& a, p& b){

	// if(a.s == '$')
	// 	return true;
	// if(b.s == '$')
	// 	return false;

	// if(a.s == b.s){
	// 	int i =1;
	// 	while(a[i] == b[i])
	// 	{
	// 		i++;
	// 	}
	// 	return a[i]<b[i];
	// }

	if(a.s == b.s)
		return a.f < b.f;

	return a.s < b.s;
}

void countSort(string& text, string&output){

	output[0] = '$';
	std::vector<int> count(text.length(),0);
	std::vector<char> letters = {'A','C','G','T'};
	
	for(int i =0;i<text.length();i++){
		if (text[i] == '$')
			continue;
		count[letterToIndex(text[i])-1]++;
	}
	// for (auto x:count)
	// 	cout<<x<<" ";
	// cout<<endl;
	int letter = 0;
	
	for (int i =1;i<text.length();i++){

		while(count[letter] <=0){
			// cout<<i<<" in"<<endl;
			letter++;
		}

		
			output[i] = letters[letter];
			count[letter]--;
			// cout<<i<<" "<<count[letter]<<" "<<output[i]<<endl;
		

	}

}

string InverseBWT(string& bwt) {
  string text = "";
  // matrix normal_bwt;
  // matrix sorted_bwt;

  // for(int i =0; i<bwt.length();i++){
  // 	normal_bwt.push_back(mp(i,bwt[i]));
  // }

  // sorted_bwt = normal_bwt;

  // sort(sorted_bwt.begin(),sorted_bwt.end(),sortByChar);
  // // for(int i =0;i<normal_bwt.size();i++)
  // // 	cout<< sorted_bwt[i].s<<" "<<normal_bwt[i].s<<endl;

  // int idx = 0;
  // for(int i =0;i<normal_bwt.size();i++){

  // 	text += sorted_bwt[idx].s;
  	

  // 	auto itr = find(sorted_bwt.begin(),sorted_bwt.end(),normal_bwt[idx]);

  // 	idx = itr - sorted_bwt.begin();



  // }

  string output = bwt;
  countSort(bwt,output);
  // cout<<"output "<<output<<endl;

  std::vector<int> K(5,0);
  std::vector<int> C(bwt.length(),0);

  for(int i =0;i<bwt.length();i++){
  	// if(bwt[i]=='$')
  	// 	continue;
  	C[i] = K[letterToIndex(bwt[i])];
  	K[letterToIndex(bwt[i])] ++;
  }
 
  // for(auto x:C)
  // 	cout<<x<<" ";
  // cout<<endl;
  
  // for(auto x:K)
  // 	cout<<x<<" ";
  // cout<<endl;
  
  int sum = 1;

  std::vector<int> M(5,0);
  for(int i =0;i<5;i++){
  	M[i] = sum;
  	sum += K[i];
  }

  // for(auto x:M)
  // 	cout<<x<<" ";
  // cout<<endl;

  int i =0;
  for(int j = bwt.size()-1;j>0;j--){
  	// cout<<bwt[i]<<" "<<i<<endl;
  	text += bwt[i];

  	i = C[i] + M[letterToIndex(bwt[i])] - 1;
  	

  }
  
  reverse(text.begin(),text.end());
  text+= '$';
  // write your code here

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
