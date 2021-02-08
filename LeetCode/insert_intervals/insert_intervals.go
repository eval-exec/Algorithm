package insert_intervals

func insert(intervals [][]int, newInterval []int) [][]int {
	var left, right [][]int

	for _, interval := range intervals {
		if first(newInterval) > interval[1] {
			left = append(left, interval)
		} else if end(newInterval) < interval[0] {
			right = append(right, interval)
		} else {
			newInterval[0] = min(interval[0], newInterval[0])
			newInterval[1] = max(interval[1], newInterval[1])
		}
	}
	return append(append(left, newInterval), right...)
}

func first(s []int) int {
	return s[0]
}
func end(s []int) int {
	return s[1]
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
func max(x, y int) int {
	if x > y {
		return x
	}
	return y

}
