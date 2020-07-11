#include <ios>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int from;
    int to;
};

struct ConvertGSMNetworkProblemToSat {
    int numVertices;
    vector<Edge> edges;

    ConvertGSMNetworkProblemToSat(int n, int m) :
        numVertices(n),
        edges(m)
    {  }

    int varnum(int i, int j){
    	return 3*(i-1) + j;
    }

    void eq_some_color(std::vector<std::vector<int> >& clauses){
    	for(int i =1;i<=numVertices;i++){
    		std::vector<int> temp;
    		for(int j = 1;j<=3;j++){
    			temp.push_back(varnum(i,j));
    		}
    		clauses.push_back(temp);
    	}
    }

    void eq_one_color(std::vector<std::vector<int> >& clauses){
    	for(int i = 1;i<=numVertices;i++){
    		std::vector<std::vector<int> > temp = {{1,2},{1,3},{2,3}};

    		for(int j =0;j<3;j++)
    		clauses.push_back({-varnum(i,temp[j][0]),-varnum(i,temp[j][1])});	
    	}
    }

    void not_same_color(std::vector<std::vector<int> >& clauses ){
    	for(int j = 1;j<=3;j++){
    		for(auto ed:edges)
    			clauses.push_back({-varnum(ed.to,j),-varnum(ed.from,j)});
    	}
    }
    void count_var(std::vector<std::vector<int> >& clauses,std::vector<int>& vars){
    	for(auto cl:clauses){
    		for(auto v:cl){
    			if(find(vars.begin(),vars.end(),abs(v)) == vars.end()){
    				vars.push_back(abs(v));
    			}
    		}
    	}
    }
    void printEquisatisfiableSatFormula() {
        // This solution prints a simple satisfiable formula
        // and passes about half of the tests.
        // Change this function to solve the problem.
    	std::vector<std::vector<int> > clauses;
    	std::vector<int> vars;
    	eq_some_color(clauses);
    	eq_one_color(clauses);
    	not_same_color(clauses);
    	// for(auto cl:clauses){
    	// 	for(auto x:cl)
    	// 		cout<<x<<" ";
    	// 	cout<<endl;
    	// }
    	count_var(clauses,vars);
    	// for(auto x:vars)
    	// 	cout<<x<<" ";
    	// cout<<endl;
    	cout<<clauses.size()<<" "<<vars.size()<<endl;

    	for(auto cl:clauses){
    		for(auto n:cl){
    			if(n<0)
    				cout<<"-"<<find(vars.begin(),vars.end(),abs(n))-vars.begin() +1<<" ";
    			else
    				cout<<find(vars.begin(),vars.end(),abs(n))-vars.begin() +1<<" ";

    		}
    		cout<<0<<endl;
    	}

        // cout << "3 2" << endl;
        // cout << "1 2 0" << endl;
        // cout << "-1 -2 0" << endl;
        // cout << "1 -2 0" << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    ConvertGSMNetworkProblemToSat converter(n, m);
    for (int i = 0; i < m; ++i) {
        cin >> converter.edges[i].from >> converter.edges[i].to;
    }

    converter.printEquisatisfiableSatFormula();

    return 0;
}
