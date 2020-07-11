#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using namespace std;

struct Segment {
  int start, end;
};

bool sortByEnd(const Segment& a,const Segment& b){
  
  return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  
  sort(segments.begin(),segments.end(),sortByEnd);

  // for(auto it : segments){
  //   cout <<it.start<<' '<<it.end <<'\n';
  // }

  int i = 0;

  while (i < segments.size()){

    points.push_back(segments[i].end);

    while (i<segments.size() && (points.back()>=segments[i].start) && (points.back()<=segments[i].end))
      i++;

    // cout << " now at " << segments[i].start <<' ' << segments[i].end <<'\n';  


  }
  


  
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
