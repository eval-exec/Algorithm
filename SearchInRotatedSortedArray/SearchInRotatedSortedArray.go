package search

func search(nums []int, target int) int {
	length := len(nums)
	halflength := length / 2

	left := 0
	right := length - 1
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

		if nums[halflength ] == target {
			return halflength
		} else if nums[halflength] < target {
			right = halflength
		} else {
			left = halflength
		}

	}

	return -1

}
