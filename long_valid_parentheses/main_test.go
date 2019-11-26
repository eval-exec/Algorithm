package main

import "testing"

func Test_longestValidParentheses(t *testing.T) {
	type args struct {
		s string
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{name: "test1", args: struct{ s string }{s: "(()"}, want: 2},
		{name: "test2", args: struct{ s string }{s: ")()())"}, want: 4},
		{name: "test3", args: struct{ s string }{s: "()()())"}, want: 6},
		{name: "test4", args: struct{ s string }{s: "))()())"}, want: 4},
		{name: "test5", args: struct{ s string }{s: ")()()(()"}, want: 4},
		{name: "test6", args: struct{ s string }{s: ")(())"}, want: 4},
		{name: "test7", args: struct{ s string }{s: ")()((("}, want: 2},
		{name: "test8", args: struct{ s string }{s: "))"}, want: 0},
		{name: "test9", args: struct{ s string }{s: "((()))())"}, want: 8},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := longestValidParentheses(tt.args.s); got != tt.want {
				t.Errorf("longestValidParentheses() = %v, want %v", got, tt.want)
			}
		})
	}
}
