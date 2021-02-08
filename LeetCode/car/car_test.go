package car

import "testing"

func TestCarPooling(t *testing.T) {
	type args struct {
		trips    [][]int
		capacity int
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{"t1", args{[][]int{{2, 1, 5}, {3, 3, 7}}, 4}, false},
		{"t2", args{[][]int{{2, 1, 5}, {3, 3, 7}}, 5}, true},
		{"t3", args{[][]int{{2, 1, 5}, {3, 5, 7}}, 3}, true},
		{"t4", args{[][]int{{2, 1, 5}, {3, 3, 7}}, 4}, false},
		{"t6", args{[][]int{{3, 2, 7}, {3, 7, 9}, {8, 3, 9}}, 11}, true},
		{"t6", args{[][]int{{3, 2, 8}, {4, 4, 6}, {10, 8, 9}}, 11}, true},
		{"t5", args{[][]int{{2, 1, 5}, {3, 3, 7}}, 4}, false},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := carPooling(tt.args.trips, tt.args.capacity); got != tt.want {
				t.Errorf("CarPooling() = %v, want %v", got, tt.want)
			}
		})
	}
}
