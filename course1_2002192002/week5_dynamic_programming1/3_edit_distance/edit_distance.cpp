#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
	int T[str1.length()+1][str2.length()+1];

	for (size_t i = 0;i<= str1.length();i++){
		for (size_t j =0; j <= str2.length();j++){

			if(i ==0 )
				T[i][j] =j;
			else if (j ==0)
				T[i][j] = i;
			else
				T[i][j] = INT_MAX;

		}


	}
		
	
		

	for (size_t i =1;i<=str1.length();i++){
		for(size_t j =1;j<=str2.length();j++){

			if (str1[i-1] == str2[j-1]){

				T[i][j] = min(min(min(T[i][j],T[i][j-1]+1),T[i-1][j] + 1),T[i-1][j-1]);
			}
			else
				T[i][j] = min(min(min(T[i][j],T[i][j-1]+1),T[i-1][j] + 1),T[i-1][j-1]+1);


		}
	}

	// for (size_t i = 0;i<= str1.length();i++){
	// 	for (size_t j =0; j <= str2.length();j++){
	// 		cout << T[i][j] << ' ';

	// 	}
	// 	cout << endl;
	// }



  return T[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
