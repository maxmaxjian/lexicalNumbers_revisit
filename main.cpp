#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class solution {
public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> result(n);
    std::generate(result.begin(), result.end(), [&](){return n--;});
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // std::sort(result.begin(), result.end(),
    // 	      [](int i, int j){
    // 		std::vector<int> v1, v2;
    // 		while (i > 0) {
    // 		  v1.push_back(i%10);
    // 		  i /= 10;
    // 		}
    // 		while (j > 0) {
    // 		  v2.push_back(j%10);
    // 		  j /= 10;
    // 		}
    // 		std::reverse(v1.begin(), v1.end());
    // 		std::reverse(v2.begin(), v2.end());
    // 		return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
    // 	      });
    std::sort(result.begin(), result.end(),
	      [](int i, int j){
		auto stri = std::to_string(i), strj = std::to_string(j);
		return stri < strj;
	      });
    
    return result;
  }
};

int main() {
  int n = 12;
  solution soln;

  auto sorted = soln.lexicalOrder(n);
  std::copy(sorted.begin(), sorted.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
