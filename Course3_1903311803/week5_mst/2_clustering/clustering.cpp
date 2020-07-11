#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;
using namespace std;

#define mp make_pair
#define pi pair<int,int>
#define f first
#define s second

class DisjSet{

  std::vector<int> parent;
  std::vector<int> rank;

public:

  DisjSet(int siz ){
    parent.resize(siz);
    rank.resize(siz);

    for(int i =0;i<parent.size();i++){
      parent[i] = i;
      rank[i] = 1;
    }


  }

  void print_parent(){
    cout<<"printing parents"<<endl;
    for(auto x: parent)
      cout <<x<<" ";
    cout <<endl;
  }

  int find(int x){

    if ( parent[x] ==x ){
      return x;
    }
    else{
      parent[x] = find(parent[x]);

    }
    return parent[x];
  }

  void Union(int x,int y){
    int xset = find(x);
    int yset = find(y);

    if (xset == yset)
      return;

    if(rank[xset] < rank[yset]){
      parent[xset] = yset;
    }
    else if (rank[xset] > rank[yset]){
      parent[yset] = xset;
    }
    else{
      parent[xset] = yset;
      rank[yset] ++;
    }
    return;
  }




};

double euclid(pi x1, pi x2){
  double x= x1.f - x2.f;
  double y = x1.s - x2.s;

  double result = sqrt(pow(x,2) + pow(y,2));

  return result;
}

// bool sortbydist(const pair<int,pair<int,int>>& a,const pair<int,pair<int,int>>& b){

//   return a.f > b.f;

// }
double clustering(vector<int> x,vector<int> y, int k) {
  //write your code here
  std::vector< pair< double,pair<int,int> > > grand_vec;

  for(int i = 0;i<x.size();i++){
    for(int j =i+1 ;j<x.size();j++){
      pi pt_1 = mp(x[i],y[i]);
      pi pt_2 = mp(x[j],y[j]);
      double dist = euclid(pt_1,pt_2);

      grand_vec.push_back(mp(dist,mp(i,j)));

    }
  }

  

  DisjSet set(x.size());

  sort(grand_vec.begin(),grand_vec.end());
  // for(auto x:grand_vec)
  //   cout<< x.f<<" -- ( "<<x.s.f<<","<<x.s.s<<" )";
  // cout<<endl;
  int count = 0;
  int num_of_edges = x.size() - k;
  for(int i =0; i<grand_vec.size();i++){
    int pt_1 = grand_vec[i].s.f;
    int pt_2 = grand_vec[i].s.s;

    if(set.find(pt_1) != set.find(pt_2)){
      set.Union(pt_1,pt_2);
      count++;


    }
    if(count == num_of_edges+1){
      // cout<<grand_vec[i].f;
      return grand_vec[i].f;
    }
  }
  
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n),y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(15) << clustering(x,y, k) << std::endl;
}
