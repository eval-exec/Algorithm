package main

import "fmt"

func removeElement(nums []int, val int) int {
	for i := 0; i < len(nums); i++ {
		if val == nums[i] {
			fmt.Println(len(nums))
			nums = append(nums[:i], nums[i+1:]...)
			i--
		}
	}
	return len(nums)
}

func main() {
	elements := []int{1,2,2,3,4,5,5}
	target := 2
	ret := removeElement(elements,target)
	fmt.Println(ret)
}