#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h> 
using namespace std; 
using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};


vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}


class Hash{

	int M = 1000; int P = 10000019; int a = 32; int b = 2; 

	std::vector<std::vector<Query> > table;
	
public:
	Hash(){
		table.resize(M);
	}
	void insert_key (Query q);// insert a new element in the table

	void delete_key(Query q);

	string find_key (Query q);

	int hashfn (int x){
		return ((a*x + b)%P)%M;
	}

};

void Hash :: insert_key(Query q){

	int idx = hashfn(q.number);



	for( int i = 0;i < table[idx].size();i++){

		if(table[idx][i].number == q.number){
			table[idx][i].name = q.name;
			return;
		}
	}
	table[idx].push_back(q);

}

void Hash :: delete_key(Query q){

	int idx = hashfn(q.number);

	for(int i = 0; i< table[idx].size();i++){
		
		if(table[idx][i].number == q.number){
			table[idx].erase(table[idx].begin()+i);
			return;
		}
		
	}

	return;

}

string Hash :: find_key ( Query q){

	int idx = hashfn(q.number);
	string res = "not found";

	for(int i = 0; i< table[idx].size();i++){
		
		if(table[idx][i].number == q.number){
			res = table[idx][i].name;
			return res;
		}
		
	}

	return res;

}



vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    Hash h;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            
        	h.insert_key(queries[i]);

        }
        else if (queries[i].type == "del") {
            
        	h.delete_key(queries[i]);


        } 
        else {
            
            string response = h.find_key(queries[i]);
            result.push_back(response);
        }



    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
