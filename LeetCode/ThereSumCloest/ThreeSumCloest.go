package main

import (
	"fmt"
	"sort"
)

func main() {
	nums := []int{-1, 2, 1, -4}
	target := 1

	fmt.Println(threeSumClosest(nums, target))
}

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	var ret int
	length := len(nums)
	sum := nums[0] + nums[1] + nums[2]
	diff := abs(sum - target)

	for i := 0; i < length-2; i++ {
		for j, k := i+1, length-1; j < k; {
			sum = nums[i] + nums[j] + nums[k]
			if sum-target < 0 {
				j++
			} else {
				k--
			}
			if diff > abs(sum-target) {
				ret = sum
				diff = abs(sum - target)
			}
		}
	}
	return ret
	f
}

func abs(in int) int {
	if in < 0 {
		return -in
	}
	return in
}
