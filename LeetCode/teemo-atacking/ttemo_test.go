package teemo_atacking

import "testing"

func Test_findPoisonedDuration(t *testing.T) {
	type args struct {
		timeSeries []int
		duration   int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{name: "t1", args: struct {
			timeSeries []int
			duration   int
		}{timeSeries: []int{1, 4}, duration: 2}, want: 4},

		{"t2", struct {
			timeSeries []int
			duration   int
		}{[]int{1, 2}, 2}, 3},
		{"t3", struct {
			timeSeries []int
			duration   int
		}{[]int{}, 2}, 0},
		{"t4", struct {
			timeSeries []int
			duration   int
		}{[]int{1}, 0}, 0},
		{"t5", struct {
			timeSeries []int
			duration   int
		}{[]int{1, 2, 3}, 3}, 5},
		{"t6", struct {
			timeSeries []int
			duration   int
		}{[]int{0, 1, 2, 3}, 1}, 4},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := findPoisonedDuration(tt.args.timeSeries, tt.args.duration); got != tt.want {
				t.Errorf("findPoisonedDuration() = %v, want %v", got, tt.want)
			}
		})
	}
}
