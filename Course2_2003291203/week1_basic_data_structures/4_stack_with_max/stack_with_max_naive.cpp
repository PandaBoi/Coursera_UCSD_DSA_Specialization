#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;
using namespace std;

class StackWithMax {
    vector<int> stack;
    std::vector<int> maxStack;

  public:

    void Push(int value) {
        stack.push_back(value);
        
        if(maxStack.empty())
        	maxStack.push_back(value);
        
        else{
        	if(value>=maxStack.back())
        		maxStack.push_back(value);
        }
    }

    void Pop() {
        assert(stack.size());
        int val = stack.back();

        if(val == maxStack.back())
        	maxStack.pop_back();

        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return maxStack.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}