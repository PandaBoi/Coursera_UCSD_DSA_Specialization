#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast (long long n){

    if (n<=1)
        return n;

    int idx = (long long)n%60; //pisano number for mod 10
    int prev = 1;
    int curr = 1;
    int temp = 0;

    for (int i = 0 ; i < idx;i++){

        temp = prev;
        prev = curr;

        curr = (temp + curr)%10;

    }

    if (curr <= 0)
        return curr +9;

    return (curr -1) %10;






    
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
