package main

import "testing"

func Test_myPow(t *testing.T) {
	type args struct {
		x float64
		n int
	}
	tests := []struct {
		name string
		args args
		want float64
	}{
		{name: "test1", args: args{
			x: 2,
			n: 2,
		}, want: 4},
		{name: "test2", args: args{
			x: 2,
			n: 3,
		}, want: 8},
		{name: "test3", args: args{
			x: 3,
			n: 4,
		}, want: 81},
		{name: "test4", args: args{
			x: -2,
			n: 2,
		}, want: 4},
		{name: "test5", args: args{
			x: -2,
			n: -2,
		}, want: 1.0/4},
		{name: "test6", args: args{
			x: -3,
			n: 1,
		}, want: - 3},
		{name: "test7", args: args{
			x: -3,
			n: -1,
		}, want: - 1.0 / 3},
		{name: "test8", args: args{
			x: -3,
			n: 2,
		}, want: 9},
		{name: "test9", args: args{
			x: -3,
			n: -2,
		}, want:  1.0 / 9 },
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := myPow(tt.args.x, tt.args.n); got != tt.want {
				t.Errorf("myPow() = %v, want %v", got, tt.want)
			}
		})
	}
}
