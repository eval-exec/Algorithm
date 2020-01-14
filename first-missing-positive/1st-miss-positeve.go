package main

/*

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

Note:

Your algorithm should run in O(n) time and uses constant extra space.


*/

func firstMissingPositive(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 1
	}
	nums2 := make([]int, length)
	for _, n := range nums {
		if n <= 0 || n > length {
			continue
		}
		nums2[n-1] = n
	}
	for i, n := range nums2 {
		if n == 0 {
			return i + 1
		}
	}
	return length + 1
}
