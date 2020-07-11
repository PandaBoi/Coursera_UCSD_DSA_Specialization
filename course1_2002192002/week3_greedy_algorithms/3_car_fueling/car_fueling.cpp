#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here

    if (dist <=tank)
        return 0;

    int n = stops.size();
    int fills = 0;
    int prev_stop = 0;
    int curr_stop = 0;
    stops.push_back(dist);
    stops.insert(stops.begin(),0);  
    while(curr_stop <= n){

        prev_stop = curr_stop;

        while(curr_stop <= n &&(stops[curr_stop+1] - stops[prev_stop]<=tank))
            curr_stop++;
        // cout << curr_stop<<' '<<prev_stop<<'\n';
        
        if (curr_stop == prev_stop)
            return -1;
       
       else if(curr_stop<=n){
            fills+=1;
        }


        // if(curr_stop >= n){
        //     // cout <<"inside "<< dist -stops[curr_stop]<<'\n';
        //     if (dist -stops[curr_stop] <= tank)
        //         return fills;
        //     else
        //         return -1;
        // }

    }






    return fills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
