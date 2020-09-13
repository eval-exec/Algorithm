#include <iostream>


/*
 *
 * find last item equal to target in a sorted array
 *
 */


class Solution {

private:
    int bisect_eq_last(const int nums[], const int length, const int target) {
        if (length == 0 || nums[0] > target || nums[length - 1] < target) {
            return -1;
        }

        if (nums[length - 1] == target) {
            return length - 1;
        }


        int low = 0, high = length - 1;


        while (low <= high) {
            int mid = low + ((high - low) >> 2);
            if (nums[mid] == target) {
                if (nums[mid + 1] != target) {
                    return mid;
                }
                low = mid;
                continue;
            }

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid + 1;
            }
        }


        return -1;
    }

public:

    int find(const int nums[], const int length, const int target) {
        return bisect_eq_last(nums, length, target);
    }

};

int main() {

    Solution s;
    int nums[] = {1, 2, 3, 4, 4, 4, 4, 4, 5};

    int index = s.find(nums, 9, 4);
    if (index != 7) {
        std::cout << "failed,get " << index << std::endl;
        return -1;
    }
    return 0;
}