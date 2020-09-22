package car

/*
trips, trip[i] = [num_passengers, start_location, end_location]
*/

import "sort"
import "fmt"

func carPooling(trips [][]int, capacity int) bool {

	var picks = make(map[int]int)

	for _, trip := range trips {
		num_passengers, start_location, end_location := trip[0], trip[1], trip[2]
		picks[start_location] += num_passengers
		picks[end_location] -= num_passengers
	}

	var locs []int
	for loc := range picks {
		locs = append(locs, loc)
	}

	sort.Ints(locs)

	var count int
	for _, loc := range locs {
		count += picks[loc]
		if count > capacity {
			return false
		}
	}

	return true
}

func printTrip(trips [][]int) {
	for _, trip := range trips {
		println(trip[0], " ", trip[1], "  ", trip[2])
	}
}
