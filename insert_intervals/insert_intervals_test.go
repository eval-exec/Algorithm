package insert_intervals

import (
	"reflect"
	"testing"
)

func Test_insert(t *testing.T) {
	type args struct {
		intervals   [][]int
		newInterval []int
	}
	tests := []struct {
		name string
		args args
		want [][]int
	}{
		{name: "test1", args: struct {
			intervals   [][]int
			newInterval []int
		}{intervals: [][]int{{1, 3}, {6, 9}}, newInterval: []int{2, 5}}, want: [][]int{{1, 5}, {6, 9}}},
		{name: "test2", args: struct {
			intervals   [][]int
			newInterval []int
		}{intervals: [][]int{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, newInterval: []int{4, 8}}, want: [][]int{{1, 2}, {3, 10}, {12, 16}}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := insert(tt.args.intervals, tt.args.newInterval); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("insert() = %v, want %v", got, tt.want)
			}
		})
	}
}
