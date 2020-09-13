#include <iostream>

/*
 * find first item equal to target
 */



class Bisect {

private:

private:
    int bisect(const int nums[], const int length, const int target) {
        int low = 0;
        int high = length - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

public:
    int find(const int nums[], const int length, const int target) {


        int index = bisect(nums, length, target);
        if (index <= 0) {
            return index;
        }


        while (index > 0) {
            if (target == nums[index]) {
                index--;
                continue;
            } else {
                return index + 1;
            }
        }

        return -1;
    }
};

void test(char *name, int result, int nums, ...) {
}

int main() {

    Bisect b;

    int nums[] = {1, 2, 3, 4, 4, 4, 4, 4, 5, 6};
    int index = b.find(nums, sizeof(nums) / sizeof(nums[0]), 4);
    if (index != 3) {
        std::cout << "failed" << std::endl;
        return -1;
    }


    int nums2[] = {1, 3, 4, 4, 4, 4, 4, 5, 6};
    index = b.find(nums2, sizeof(nums2) / sizeof(nums2[0]), 4);
    if (index != 2) {
        std::cout << "failed" << std::endl;
        return -1;
    }


    int nums3[] = {1};
    index = b.find(nums3, sizeof(nums3) / sizeof(nums3[0]), 4);
    if (index != -1) {
        std::cout << "failed" << std::endl;
        return -1;
    }
    index = b.find(nums3, sizeof(nums3) / sizeof(nums3[0]), 1);
    if (index != 0) {
        std::cout << "failed,get" << index << std::endl;
        return -1;
    }
    return 0;
}