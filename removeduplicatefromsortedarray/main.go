package main

func removeDuplicates(nums []int) int {

	length := len(nums)
	if length == 0 {
		return 0
	}
	ins := 1
	for i := 1; i < length   ; i++ {
		if nums[i ] == nums[i - 1] {
			continue
		}else {
			nums[ins] = nums[i]
			ins++
		}

	}
	nums = append(nums[:ins],)
	return ins

}


