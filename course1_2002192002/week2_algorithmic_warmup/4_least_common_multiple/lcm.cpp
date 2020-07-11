#include <iostream>
#include <algorithm>
using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


int gcd_fast (int a, int b){

	// int gcd = 1;

	int dividend = max(a,b);
	int divisor = min(a,b);
	int temp = 0;
	while( divisor > 0){
		temp = divisor;
		divisor = dividend%divisor;
		dividend = temp;
	}



	return dividend;
}

long long lcm_fast(int a, int b){

	int gcd = gcd_fast( a, b);

	long long lcm = (long long) a * b /gcd;

	return lcm;


}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout <<lcm_fast(a,b) << std::endl;
  return 0;
}
