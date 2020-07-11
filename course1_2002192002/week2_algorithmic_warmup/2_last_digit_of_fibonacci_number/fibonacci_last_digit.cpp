#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n){


    if (n<2){
        return n;
    }
    else{

        int lis[n] = {0};
        lis[1] = 1;
        for (int i =2; i < n+1; ++i){
            lis[i] = (lis[i-1] + lis[i-2])%10;
        }
    return lis[n];

    }
}

int main() {
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int x = get_fibonacci_last_digit_fast(n);
    std::cout << x << '\n';
    }
