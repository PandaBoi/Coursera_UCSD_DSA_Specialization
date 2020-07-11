#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

long long hash_func(const string& s,long long p, int x){

    long long hash = 0;
    
    for (long long i = static_cast<long long> (s.size()) - 1; i >= 0; --i){
        hash = (hash*x + s[i])%p;
    }
    // cout << hash<<endl;
    return hash;
}

bool areEqual(const string& t,const string& s,size_t i){

    for(size_t j = i;j<s.size();j++){
        if(t[j]!=s[j-i]){
            // cout << t[j]<<"_"<<s[j-i];
            return false;
        }
    }
    return true;

}

void precomputeHashes(std::vector<long long>& H,const string& t,long long p, int x,int pattern_size){

    string subs = t.substr(t.size()-pattern_size,pattern_size);
    // cout << subs<<endl;
    H[t.size() - pattern_size] = hash_func(subs,p,x);
    // cout<<t.size() - pattern_size<<" "<<H[t.size() - pattern_size]<<endl;
    long long y = 1;
    

    for(size_t i = 1;i<=pattern_size;i++){
        // cout<<"times "<<i<<endl;
        y = (y*x)%p;
    }
    // cout<<y<<endl;
    for(int i = t.size() - pattern_size -1;i>=0;--i){
        long long temp =  (x*H[i+1]+ t[i]- y*t[i+pattern_size]);
        // cout<<i<<" "<<temp<<endl;
        while(temp<0){
            temp +=p;
        }
        H[i] = temp%p;
        // cout << i<<" "<<H[i]<<" "<<hash_func(t.substr(i,pattern_size),p,x)<<endl;
    }

}

std::vector<int> get_occurrences(const Data& input) {
   
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    long long p = 999999937;
    int x = 12;
    std::vector<long long> H(t.size()-s.size()+1);
    long long  pattern_hash = hash_func(s,p,x);
    precomputeHashes(H,t,p,x,s.size());
    
    // cout <<"pattern hash"<<pattern_hash<<endl;
    // for(auto x: H)
    //     cout<<x<<endl;
    

    for (size_t i = 0; i + s.size() <= t.size(); ++i){
       
        // cout << t.substr(i,s.size())<<endl;
       
        if (H[i]==pattern_hash){
            if(areEqual(t,s,i)){
                // cout <<"lol"<<endl;
                ans.push_back(i);
            }
        }
    }
            
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
