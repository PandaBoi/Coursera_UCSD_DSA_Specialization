#include <iostream>
#include<vector>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}



long long get_fibonacci_huge_fast (long long n, long long m){
   

    int flag = -1;
    long long prev = 0;
    long long current = 1;
    vector<long> v;
    int i = 0;

    if (n <= 1){
        return n;
    }
    else{
        while(1){


            
            if (  i < 2){
                // cout << "first if "<<i%m<<'\n';
                v.push_back(i%m);
            }
            else{
                
                
                // cout << "current " << current<<" i "<< i <<'\n';
                // cout << "prev stuff " <<i-2<< v[i-2]<< "_" << i-1<<v[i-1] << '\n';
                if (v[i-2] == 0 && v[i-1] == 1){
                    
                    flag++;
                    // cout << "inc flag"<< '\n';
                    v.push_back((v[i-2]+v[i-1])%m);
                    if (flag == 1){
                        // cout << "FLAG" << '\n';
                        break;
                    }
                
                }
                else{
                    // cout <<"lol " << v[i-1] <<'_'<<v[i-2]<< '\n';
                    // cout << i<<"_"<<(v[i-2]+v[i-1])<<"_"<<(v[i-2]+v[i-1])%m<<'\n';
                    v.push_back((v[i-2]+v[i-1])%m);
                }
            }

            i++;
        }

        v.pop_back();
        v.pop_back();
        v.pop_back();


    }
    // cout << v.size() << '\n';
    // for (int i = 0; i < v.size(); i++) 
    //     cout <<v[i] << " ";
    cout << "v_size "<<v.size()<<'\n';
    int idx = n%v.size();
    if (idx == 0)
        return 0;
    // cout << "idx " << idx<<'\n';
    return v[idx];

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
