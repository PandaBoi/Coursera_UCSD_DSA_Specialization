#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;
  int size_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    size_ = n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int parent(int i){
  	return max(0,(i-1)/2);
  }
  int leftchild(int i){
  	return 2*(i+1) -1;
  }
  int rightchild(int i){
  	return 2*(i+1) ;
  }

  void SiftUp(int i){

  	while(i >= 0 && data_[parent(i)] > data_[i]){
  		swap(data_[parent(i)],data_[i]);
  		swaps_.push_back(make_pair(parent(i),i));
  		i = parent(i);
  	}

  }

  void SiftDown(int i){

  	int minIndex = i;
  	int l = leftchild(i);
  	int r = rightchild(i);
  	if(l<data_.size() && data_[l] < data_[minIndex])
  		minIndex = l;

  	if(r<data_.size() && data_[r] < data_[minIndex])
  		minIndex = r;

  	if(minIndex != i){
  		swap(data_[i],data_[minIndex]);
  		swaps_.push_back(make_pair(i,minIndex));
  		// printData();
  		// cout <<endl;
  		SiftDown(minIndex);
  	}

  }

  void printData(){
  	for (auto x: data_)
  		cout << x<<' ';
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
   	// printData();
   	int n = data_.size();
    for (int i = n/2; i >= 0; --i){

    	// cout << "DURING "<<i<<endl;

    	SiftDown(i);
    }




  }


 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
