#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using namespace std;

typedef struct worker{

	long long finish_time;
	int idx;
}worker;

class JobQueue {
 private:
  int num_workers_;
  vector<long long> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
  std::vector<worker> workers_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    
    for(int i = 0; i < m; i++){
      cin >> jobs_[i];
     
    }

  }

  int parent(int i){
  	return (i-1)/2;
  }

  int leftchild(int i){
  	return 2*i +1;
  }
  int rightchild(int i){
  	return 2*i +2;
  }

  void siftDown(int i){
  	int minIdx = i;
  	int l = leftchild(i);
  	int r = rightchild(i);

  	if(l<num_workers_ && workers_[minIdx].finish_time > workers_[l].finish_time)
  		minIdx = l;

  	if(r<num_workers_ && workers_[minIdx].finish_time > workers_[r].finish_time)
  		minIdx = r;

  	if(l<num_workers_ && workers_[minIdx].finish_time == workers_[l].finish_time){
  		if(workers_[minIdx].idx> workers_[l].idx)
  			minIdx = l;
  	}

  	if(r<num_workers_ && workers_[minIdx].finish_time == workers_[r].finish_time){
  		if(workers_[minIdx].idx> workers_[r].idx)
  			minIdx = r;
  	}

  	if(i != minIdx){
  		swap(workers_[i],workers_[minIdx]);
  		siftDown(minIdx);
  	}


  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    workers_.resize(num_workers_);
    for (int i =0; i<num_workers_;i++){
    	workers_[i].finish_time = 0;
    	workers_[i].idx = i;
    }
    // vector<long long> next_free_time(num_workers_, 0);

  //   for (int i = 0; i < jobs_.size(); ++i) {
  //     int duration = jobs_[i];
  //     int next_worker = 0;
  //     for (int j = 0; j < num_workers_; ++j) {
  //       if (next_free_time[j] < next_free_time[next_worker])
  //         next_worker = j;
  //     }
  //     assigned_workers_[i] = next_worker;
  //     start_times_[i] = next_free_time[next_worker];
  //     next_free_time[next_worker] += duration;
  //   }


    for(int i =0; i < jobs_.size();++i){

    	int duration = jobs_[i];
    	int next_worker = 0;
    	assigned_workers_[i] = workers_[0].idx;
    	start_times_[i] = workers_[0].finish_time;
    	long long new_finish = workers_[0].finish_time+ duration;
		workers_[0].finish_time = new_finish;
    	siftDown(0); 



    }
  



  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
