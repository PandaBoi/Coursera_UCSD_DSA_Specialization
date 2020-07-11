#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solver {
	string s;
	long long m1 = 1000000007;
	long long m2 = 1000000009;
	long long multiplier = 17;
	std::vector<long long> h1,h2,y1,y2;
	
public:	
	Solver(string s) : s(s){	
		// initialization, precalculation
			}
	void precomputeHash(){
		// cout<<"Called"<<endl;
		int n = s.length()+1;
		h1.resize(n);
		h2.resize(n);
		
		h1[0] =0;
		h2[0] = 0;
		
		for(int i =1;i<h1.size();i++){
			h1[i] = ((multiplier*h1[i-1]) + s[i-1])%m1;
			h2[i] = ((multiplier*h2[i-1]) + s[i-1])%m2;
		}

		y1.resize(n);
		y2.resize(n);
		y1[0] = 1;
		y2[0] = 1;
		for (int i = 1; i <y1.size(); ++i)
		{
			y1[i] = (y1[i-1]*multiplier)%m1;
			y2[i] = (y2[i-1]*multiplier)%m2;
		}

		// for(int i =0;i<h1.size();i++){
		// 	cout <<i<<" "<<s[i] <<":"<<" "<< h1[i]<<" ";	
		// }
		// cout<<endl;
		return;
	}
	bool hash_it(int a, int b, int l){

		
		long long hash1_a = (h1[a+l] - (y1[l]*h1[a]))%m1;
		while(hash1_a<0)
			hash1_a += m1;
		hash1_a = hash1_a%m1;

		long long hash1_b = (h1[b+l] - (y1[l]*h1[b]))%m1;
		while(hash1_b<0)
			hash1_b += m1;
		hash1_b = hash1_b%m1;

		long long hash2_a = (h2[a+l] - (y2[l]*h2[a]))%m2;
		while(hash2_a<0)
			hash2_a += m2;
		hash2_a = hash2_a%m2;

		long long hash2_b = (h2[b+l] - (y2[l]*h2[b]))%m2;
		while(hash2_b<0)
			hash2_b += m2;
		hash2_b = hash2_b%m2;
		// long long hash1_b = h1[b+l] - (y1*h1[b])%m1;
		// long long hash2_a = h2[a+l] - (y2*h2[a])%m2;
		// long long hash2_b = h2[b+l] - (y2*h2[b])%m2;
		
		// cout<<hash1_a<<" "<<hash1_b<<" "<<hash2_a<<" "<<hash2_b<<endl;
		// cout <<s.substr(a,l)<<" "<<s.substr(b,l)<<endl;
		
		if((hash1_a == hash1_b) && (hash2_a == hash2_b)){
			// cout<<"IN"<<endl;
			return true;
		}
		// cout<<"not IN"<<endl;
		return false;
	}
	bool ask(int a, int b, int l) {
		return hash_it(a,b,l);
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	solver.precomputeHash();
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
