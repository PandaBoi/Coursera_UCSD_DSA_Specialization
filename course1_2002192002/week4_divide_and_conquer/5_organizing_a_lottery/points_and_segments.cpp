#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using std::vector;

typedef struct holder{
    long long val; 
    char type;
    long long idx ;
}holder;

bool compare ( holder a, holder b){

    if(a.val == b.val){
        // must keep [L, P, R] order
        if((a.type == 'L' && b.type == 'P' ) || (a.type == 'P' && b.type == 'L'))
            return a.type<b.type;
        if((a.type == 'P' && b.type == 'R' ) || (a.type == 'R' && b.type == 'P'))
            return a.type < b.type;
        if((a.type == 'L' && b.type == 'R' ) || (a.type == 'R' && b.type == 'L'))
            return a.type< b.type;
    }
    return a.val < b.val;
}


vector<long long> fast_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points) {
  vector<long long> cnt(points.size());
  
  std::vector<holder> v(points.size() + 2*starts.size());

  long long j = 0;
  for (size_t i =0;i < points.size();i++){
    holder h ;
    h.val = points[i];
    h.type = 'P';
    h.idx = i;
    v[j] = h;
    j++;

  }

  for (size_t i =0;i < starts.size();i++){
    
    holder h ;
    h.val = starts[i];
    h.type = 'L';
    h.idx = -1;
    v[j] = h;
    j++;
  }


  for (size_t i =0;i < ends.size();i++){
    
    holder h ;
    h.val = ends[i];
    h.type = 'R';
    h.idx = -1;
    v[j] = h;
    j++;
  }
  

  sort(v.begin(),v.end(), compare);

  int counter = 0;
  for (size_t i = 0; i < v.size(); i++)
  {


    if(v[i].type == 'L'){
      counter++;
    }

    else if ( v[i].type == 'P'){
      cnt[v[i].idx] = counter;
    }

    else if(v[i].type == 'R'){
      counter--;
    }

  
  }




  //write your code here
  return cnt;
}

vector<long long> naive_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points) {
  vector<long long> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  long long n, m;
  std::cin >> n >> m;
  vector<long long> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<long long> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<long long> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
