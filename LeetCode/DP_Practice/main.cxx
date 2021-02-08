
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

int GetMinCoinCountHelper(int total, int *values, int valueCount) {
    int rest = total;
    int count = 0;

    // 从大到小遍历所有面值
    for (int i = 0; i < valueCount; ++i) {
        int currentCount = rest / values[i]; // 计算当前面值最多能用多少个
        rest -= currentCount * values[i]; // 计算使用完当前面值后的余额
        count += currentCount; // 增加当前面额用量

        if (rest == 0) {
            return count;
        }
    }

    return -1; // 如果到这里说明无法凑出总价，返回-1
}

void GetMinCoinCount() {
    int values[] = {5, 3}; // 硬币面值
    int total = 11; // 总价
    int minCoinCount = GetMinCoinCountHelper(total, values, 2);

    std::cout << minCoinCount << std::endl; // 输出结果
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

int GetMinCoinCountOfValueHelper(int total, int *values, int valueIndex, int valueCount) {
    if (valueIndex == valueCount) {
        return -1;
    }

    int currentValue = values[valueIndex];
    int maxCount = total / currentValue;

    for (int count = maxCount; count >= 0; count--) {
        int rest = total - count * currentValue;
        // 如果rest为0，表示余额已除尽，组合完成
        if (rest == 0) {
            return count;
        }

        // 否则尝试用剩余面值求当前余额的硬币总数
        int restCount = GetMinCoinCountOfValueHelper(rest, values, valueIndex + 1, valueCount);

        // 如果后续没有可用组合
        if (restCount == -1) {
            // 如果当前面值已经为0，返回-1表示尝试失败
            if (count == 0) { return -1; }
            continue; // 否则尝试把当前面值-1
        }

        return count + restCount;
    }

    return -1;
}

void GetMinCoinCountOfValue() {
    int values[] = {5, 3}; // 硬币面值
    int total = 11; // 总价
    int minCoinCount = GetMinCoinCountOfValueHelper(total, values, 0, 2);

    std::cout << minCoinCount << std::endl; // 输出结果
}


