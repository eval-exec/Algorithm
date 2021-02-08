package main

import "testing"

func Test_firstMissingPositive(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{"test1",args{[]int{1,2,4}},3},
		{"test2",args{[]int{3,4,-1,1}},2},
		{"test3",args{[]int{7,8,9,10,4}},1},
		{"test4",args{[]int{1}},2},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := firstMissingPositive(tt.args.nums); got != tt.want {
				t.Errorf("firstMissingPositive() = %v, want %v", got, tt.want)
			}
		})
	}
}
