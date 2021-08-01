#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Minimum Garden Perimeter to Collect Enough Apples

*/

/*
 *
 0.0
 1.0 1.1 1.2 1.3
 2.0 2.1 2.2 2.3
 3.0 3.1 3.2 3.3
 */


// (n+1)*n * n
class Solution {
 public:
  long long minimumPerimeter(long long neededApples) {
	long long left = 1;
	int n = cbrt(neededApples/4);
	while(sum(n) < neededApples){
	  n++;
	}
	return n*8;
  }
 private:
  long long sum(long long n) {
	return (n+1)*n /2 * (n+n+1) * 4;
  }
};

//// END
struct T {

};

TEST(Solution, test) {
  T ts[] = {
	  {

	  },
	  {

	  },

  };

  for (T t : ts) {
	Solution solution;

  }
}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


