#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

#define mp make_pair
#define pi pair<double, int>
#define s second
#define f first


double euclid(int x1, int y1, int x2, int y2){

	double dist = 0.0;
	double x = x1 - x2;
	double y = y1 - y2;

	dist = (double)sqrt(  pow(x,2) + pow(y,2) );
	// cout<<x1<<y1<<x2<<y2<<dist<<endl;

	return dist;
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  std::vector<double> cost(x.size(),INT_MAX);
  std::vector<int> parent(x.size(),-1);
  std::vector<bool> points(x.size(),false);

  // for(int i = 0; i<points.size();i++){
  // 	points[i] = i;
  // }

  cost[0] = 0;
  priority_queue<pi, vector<pi>,greater<pi> > pq;
  pq.push(mp(0,0));

  points[0] = true;
  while(pq.size()>0){
  
  	int u = pq.top().s;
  	// result += pq.top().f;
  	// cout<< " current distance "<<result<<endl;

  	pq.pop();
  	points[u] = true;

  	for(int i =0;i<points.size();i++){
  		
  		int point = i;
  		
  		// cout<<"checking "<<u<<" --> "<<point<<endl;
  		double weight = euclid(x[u],y[u],x[point],y[point]);
  		// cout<<" cost of "<<u<<" --> "<<point<<" = "<<weight<<endl;
  		
  		// for(auto x: points)
  		// 	cout<<x<<" ";
  		// cout<<endl;

  		if(points[point] == false && cost[point] > weight ){
  		
  			// cout<<" changing cost "<<endl;
  			cost[point] = weight;
  			// result += cost[point];
  			parent[point] = u;
  			pq.push(mp(cost[point],point));
  		}
  		
  		// for(auto x: cost)
  		// 	cout<<x<<" ";
  		// cout<<endl;
  	}

  }
  for( auto x: cost)
  	result += x;

  //write your code here

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
	std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(20) << minimum_distance(x, y) << std::endl;
}
