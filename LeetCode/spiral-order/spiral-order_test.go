package spiral_order

import (
	"reflect"
	"testing"
)

func Test_spiralOrder(t *testing.T) {
	type args struct {
		matrix [][]int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{name: "test1", args: struct{ matrix [][]int }{matrix: [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}, want: []int{1, 2, 3, 6, 9, 8, 7, 4, 5}},
		{name: "test2", args: struct{ matrix [][]int }{matrix: [][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}}, want: []int{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}},
		{"test3", struct{ matrix [][]int }{matrix: [][]int{{3}, {2}}}, []int{3, 2}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := spiralOrder(tt.args.matrix); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("spiralOrder() = %v, want %v", got, tt.want)
			}
		})
	}
}
