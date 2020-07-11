#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<vector<string>> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {

    	elems.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void add_key(const Query& query){
    	
    	if (!find_key(query)){
	    	size_t idx = hash_func(query.s);
	    	elems[idx].push_back(query.s);
	    	return;
    	}

    }

    void del_key(const Query& query){

    	size_t idx = hash_func(query.s);

    	for (int i =0;i<elems[idx].size();i++){
    		if(elems[idx][i] == query.s){
    			elems[idx].erase(elems[idx].begin() + i);
    			return;
    		}
    	}
    }

    bool find_key(const Query& query){

    	size_t idx = hash_func(query.s);

    	for(int i =0; i<elems[idx].size();i++){

    		if(elems[idx][i] == query.s){
    			return true;
    		}

    	}
    	return false;
    }

    void processQuery(const Query& query) {
        
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = static_cast<int>(elems[query.ind].size()) - 1; i >= 0; --i)
                std::cout << elems[query.ind][i] << " ";
            std::cout << "\n";
        }

        else if(query.type == "add")
        	add_key(query);
        else if(query.type == "del")
        	del_key(query);
        else if(query.type == "find"){
        	bool found = find_key(query);
        	writeSearchResult(found);
        }




    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
