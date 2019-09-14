package search

import "fmt"

func search(nums []int, target int) int {
	length := len(nums)
	halflength := length / 2

	left := 0
	right := length - 1
	fmt.Println(nums,"is nums")
	fmt.Println(target,"is target")
	for left < right {
		if nums[left] == target {
			return left
		} else {
			left++
		}
		if nums[right] == target {
			return right
		} else {
			right--
		}
		halflength = (left + right) / 2

		fmt.Print(left,",")
		fmt.Print(right,",")
		fmt.Println(halflength)
		if nums[halflength ] == target {
			return halflength
		}
		
		if nums[halflength] < target {
			if nums[left] >  target {
				right = halflength
				continue
			}else{
				left = halflength
				continue
			}
		}
		if nums[halflength] > target {
			if nums[right] > target {
				left = halflength
				continue
			}
			right = halflength
		}
	}
	return -1

}
