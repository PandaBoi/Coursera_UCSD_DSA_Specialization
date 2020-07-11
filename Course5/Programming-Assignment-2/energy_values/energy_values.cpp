#include <cmath>
#include <iostream>
#include <vector>

const double EPS = 1e-6;
const int PRECISION = 20;
using namespace std;
typedef std::vector<double> Column;
typedef std::vector<double> Row;
typedef std::vector<Row> Matrix;

struct Equation {
    Equation(const Matrix &a, const Column &b):
        a(a),
        b(b)
    {}

    Matrix a;
    Column b;
};

struct Position {
    Position(int column, int row):
        column(column),
        row(row)
    {}

    int column;
    int row;
};

Equation ReadEquation() {
    int size;
    std::cin >> size;
    Matrix a(size, std::vector <double> (size, 0.0));
    Column b(size, 0.0);
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column)
            std::cin >> a[row][column];
        std::cin >> b[row];
    }
    return Equation(a, b);
}

Position SelectPivotElement(
  const Matrix &a, 
  std::vector <bool> &used_rows, 
  std::vector <bool> &used_columns) {
    // This algorithm selects the first free element.
    // You'll need to improve it to pass the problem.
    Position pivot_element(0, 0);
    while (used_rows[pivot_element.row])
        ++pivot_element.row;
    while (used_columns[pivot_element.column])
        ++pivot_element.column;
    while(a[pivot_element.row][pivot_element.column] == 0 || used_rows[pivot_element.row])
    	pivot_element.row++;
    return pivot_element;
}

void SwapLines(Matrix &a, Column &b, std::vector <bool> &used_rows, Position &pivot_element) {
    std::swap(a[pivot_element.column], a[pivot_element.row]);
    std::swap(b[pivot_element.column], b[pivot_element.row]);
    std::swap(used_rows[pivot_element.column], used_rows[pivot_element.row]);
    pivot_element.row = pivot_element.column;
}

void ProcessPivotElement(Matrix &a, Column &b, const Position &pivot_element) {
    // Write your code here
	// cout<<a[pivot_element.row][pivot_element.column]<<endl;
	double piv_num = a[pivot_element.row][pivot_element.column];
    for(int i = pivot_element.column;i<a[0].size();i++){
    	a[pivot_element.row][i] /= piv_num;
    }
    b[pivot_element.row] /= piv_num;

    // for(auto row:a){
    // 	for(auto col:row){
    // 		cout<< col<<" ";
    // 	}

    // 	cout<<endl;
    // }

    // for(auto x:b)
    // 	cout<<x<<" ";
    // cout<<endl;

    for(int i =0;i<a.size();i++){

    	if(i == pivot_element.row)
    		continue;

    	double multiplicand = a[i][pivot_element.column] == 0 ? 0 :
    							-1*(a[i][pivot_element.column]/a[pivot_element.row][pivot_element.column]);
    	// cout<<"multiplicand "<<multiplicand<<endl;
    	for(int j = pivot_element.column;j<a[0].size();j++){
    		a[i][j] = a[i][j] + multiplicand*(a[pivot_element.row][j]);
    	}
    	b[i] = b[i] + multiplicand*b[pivot_element.row];
    }

    // for(auto row:a){
    // 	for(auto col:row){
    // 		cout<< col<<" ";
    // 	}

    // 	cout<<endl;
    // }

    // for(auto x:b)
    // 	cout<<x<<" ";
    // cout<<endl;
    // cout<<endl;


}

void MarkPivotElementUsed(const Position &pivot_element, std::vector <bool> &used_rows, std::vector <bool> &used_columns) {
    used_rows[pivot_element.row] = true;
    used_columns[pivot_element.column] = true;
}

Column SolveEquation(Equation equation) {
    Matrix &a = equation.a;
    Column &b = equation.b;
    int size = a.size();

    std::vector <bool> used_columns(size, false);
    std::vector <bool> used_rows(size, false);
    // Position piv_prev(0,0);
    for (int step = 0; step < size; ++step) {
        Position pivot_element = SelectPivotElement(a, used_rows, used_columns);
        SwapLines(a, b, used_rows, pivot_element);
        ProcessPivotElement(a, b, pivot_element);
        MarkPivotElementUsed(pivot_element, used_rows, used_columns);
        // piv_prev = pivot_element;
    }

    return b;
}

void PrintColumn(const Column &column) {
    int size = column.size();
    std::cout.precision(PRECISION);
    for (int row = 0; row < size; ++row)
        std::cout << column[row] << std::endl;
}

int main() {
    Equation equation = ReadEquation();
    Column solution = SolveEquation(equation);
    PrintColumn(solution);
    return 0;
}
