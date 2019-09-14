package search

import (
	"fmt"
	"math/rand"
	"testing"
	"time"
)

func Test_search(t *testing.T) {
	type args struct {
		nums   []int
		target int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			"test-1",
			args{
				nums:   []int{4, 5, 6, 7, 0, 1, 2},
				target: 0,
			},
			4},
		{
			"test-2",
			args{
				nums:   []int{4, 5, 6, 7, 0, 1, 2},
				target: 3,
			},
			-1},
	}

	for i := 0; i < 10; i++ {
		nums := generateArray()
		fmt.Println(nums,"is nums")
		nums = rotateArray(nums)
		target := generateRandInt()
		fmt.Println(nums,"is rotated")
		fmt.Println(target," is target")

		want := findTarget(nums, target)
		fmt.Println(want,"is wanted")
		if want != -1 {
			fmt.Println(nums[want],"is reference wanted")
		}

		tests = append(tests,
			struct {
				name string
				args args
				want int
			}{name: "generateTest", args: args{
				nums:   nums,
				target: target,
			}, want: want},
		)
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := search(tt.args.nums, tt.args.target); got != tt.want {
				t.Errorf("search() = %v, want %v", got, tt.want)
			}
		})
	}
}

func generateArray() []int {
	s := rand.NewSource(time.Now().UnixNano())
	r := rand.New(s)
	length := r.Int31n(1000)

	var ret []int
	for i := 0; int32(i) < length; i++ {
		bs := rand.NewSource(time.Now().UnixNano())
		br := rand.New(bs)

		randBool := br.Int()%2 == 0
		if randBool == true {
			continue
		} else {
			ret = append(ret, i)
		}
	}
	return ret
}

func rotateArray(nums []int)[]int {
	length := len(nums)
	s := rand.NewSource(time.Now().UnixNano())
	r := rand.New(s)
	pivot := r.Intn(length)
	nums = append(append(nums[pivot:], ), nums[:pivot]...)
	return nums

}

func findTarget(nums []int, target int) int {
	for index, item := range nums {
		if item == target {
			return index
		}
	}
	return -1
}

func generateRandInt() int {
	s := rand.NewSource(time.Now().UnixNano())
	r := rand.New(s)
	return r.Intn(500)
}
