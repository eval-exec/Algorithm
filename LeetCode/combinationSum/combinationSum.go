package main

import (
	"fmt"
	"sort"
)

func main() {
	candidate := []int{1,2,3}
	targer := 4
	ret :=combinationSum(candidate,targer)
	fmt.Println(ret)
}
func combinationSum(candidates []int, target int) [][]int {

	var ret [][]int

	sort.Ints(candidates)

	length  := len(candidates)

	for i := length - 1; i >= 0 ; i-- {
		for j := i; j >= 0; j-- {
			if candidates[j] == target {
				ret = append(ret,candidates[j])
			}
		}
	}




	return ret
}