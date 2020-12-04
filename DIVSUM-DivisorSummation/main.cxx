/*
 * Given a natural number n (1 <= n <= 500000),
 * please output the summation of all its proper divisors.

Definition: A proper divisor of a natural number is the divisor that is strictly less than the number.

e.g. number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.


 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        double sq = sqrt(num);
        int x = 1;

        int sum = 0;

        while (x < num && x <= sq) {
            if (num % x == 0) {
                sum += x;
                if (x != sq) {
                    if (num / x < num) {
                        sum += num / x;
                    }
                }
            }
            x++;
        }
        cout << sum << endl;
    }
    // your code goes here
    return 0;
}

