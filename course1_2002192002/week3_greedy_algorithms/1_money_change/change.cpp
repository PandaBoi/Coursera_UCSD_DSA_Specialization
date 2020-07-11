#include <iostream>

int get_change(int m) {
  //write your code here
	int n = 0;
	int amt = m;
	int denom[3] = {10,5,1};
	while(amt >0){

		for (int i = 0; i < 3;i++){

			if ( amt >= denom[i]){
			
				n += amt/denom[i];
				amt = amt%denom[i];
			
				if (amt <= 0)
					break;
			}
		}


	}
	return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
