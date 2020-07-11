#include <iostream>
#include <vector>
#include <algorithm>


// int MaxPairwiseProduct(const std::vector<int>& numbers) {
//     int max_product = 0;
//     int n = numbers.size();

//     for (int first = 0; first < n; ++first) {
//         for (int second = first + 1; second < n; ++second) {
//             max_product = std::max(max_product,
//                 numbers[first] * numbers[second]);
//         }
//     }

//     return max_product;
// }

int64_t MaxPairwiseProductfast(const std::vector<long>& numbers){

	int siz = numbers.size();
	int idx1 = -1;
	int idx2 = -1;
	int64_t max = 0;

	for ( int first = 0; first <siz; ++first){
		if (numbers[first] > max){
			idx1 = first;
			max = numbers[first];
			// std:: cout << max <<' '<<first<<'\n';
		}
	}
	max = -1;
	// std::cout << max <<' ' ;
	for(int second = 0; second <siz; ++second){

		if ((numbers[second]> max) && (second != idx1)){

			idx2 = second;
			max = numbers[second];
			

		}

	}
	// std::cout << numbers[idx1] << ' ' << numbers[idx2]<<'\n' ;

	max = (long long)(numbers[idx1]) * numbers[idx2];
	// std:: cout << max<<'\n';
	return max;




}

int main() {
    int n;
    std::cin >> n;
    std::vector<long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductfast(numbers) << "\n";
    return 0;
}
