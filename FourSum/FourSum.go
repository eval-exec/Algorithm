package main

import (
	"fmt"
	"sort"
)

func main() {
	nums := []int{5, 5, 3, 5, 1, -5, 1, -2}
	fmt.Println(len(nums), "is length")

	targer := 14
	result := fourSum(nums, targer)
	fmt.Println(result)
}

// 0 1 2 3 4 5 6

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	length := len(nums)
	var out [][]int
	for i := 0; i < length-3; i++ {
		for j := i + 1; j < length-2; j++ {
			m, n := j+1, length-1
			for ; m < n; {
				sums := sumNums(nums, i, j, m, n)
				if sums == target {
					out = append(out, []int{nums[i], nums[j], nums[m], nums[n]})
					m++
					n--
				} else if sums < target {
					m++
				} else {
					n--
				}
			}
		}
	}
	out = removeDup(out)
	return out
}

func sumNums(nums []int, a, b, c, d int) int {
	return nums[a] + nums[b] + nums[c] + nums[d]
}

func removeDup(input [][]int) (output [][]int) {
	output = append(output, input[0])
	for index := 1; index < len(input); index++ {
		if !checkSlice(input[index], input[index-1]) {
			fmt.Println(checkSlice(input[index], input[index-1]))
			output = append(output, input[index])
			index++
		}
		index++
	}
	return output
}

func checkSlice(in1 []int, in2 []int) bool {
	for index, value := range in1 {
		fmt.Println(value, in2[index])
		if string(value) != string(in2[index]) {
			return false
		}

	}

	return true

}
