#include <iostream>
#include <vector>
using std::vector;
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


int get_fibonacci_partial_sum_fast (long long from, long long to){

   
    if (to<=1)
        return to;

    int mods[60];
    mods[0] = 0;
    mods[1] = 1;
    mods[2] = 1;
    for (int i =3; i<=60;i++){

    	mods[i] = (mods[i-1] + mods[i-2])%10;
    }
    // for (int i =0; i<60;i++){
    // 	std::cout << mods[i] << ' ';
    // }

    int idx_to = to%60;
    int idx_from = from%60;

    if (idx_to < idx_from){
    	idx_to += 60;
    }
    int val = 0;
    for (int i = idx_from;i <=idx_to;i++){
    	val += mods[i%60];
    }
    // cout << "from " << idx_from << " to " << idx_to << '\n';
    return val%10;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
 	std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
       
}
