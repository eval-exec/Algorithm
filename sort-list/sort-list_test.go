package sort_list

import (
	"reflect"
	"testing"
)

func genList(list []int) *ListNode {
	if len(list) == 0 {
		return nil
	}
	ret := &ListNode{}

	head := ret
	prev := ret

	for _, val := range list {
		prev = ret
		ret.Val = val
		ret.Next = &ListNode{}
		ret = ret.Next
	}
	prev.Next = nil
	return head

}

func Test_sortList(t *testing.T) {

	type args struct {
		head *ListNode
	}

	tests := []struct {
		name string
		args args
		want *ListNode
	}{
		{name: "t1", args: struct{ head *ListNode }{head: genList([]int{1, 2, 3, 4})}, want: genList([]int{1, 2, 3, 4})},
		{name: "t2", args: struct{ head *ListNode }{head: genList([]int{4, 2, 1, 3})}, want: genList([]int{1, 2, 3, 4})},
		{name: "t3", args: struct{ head *ListNode }{head: genList([]int{-4, 1, 0, 7, 3})}, want: genList([]int{-4, 0, 1, 3, 7})},
		{name: "t4", args: struct{ head *ListNode }{head: genList([]int{0})}, want: genList([]int{0})},
		{name: "t5", args: struct{ head *ListNode }{head: genList([]int{})}, want: genList([]int{})},
		{name: "t6", args: struct{ head *ListNode }{head: genList([]int{1,2})}, want: genList([]int{1,2})},
		{name: "t7", args: struct{ head *ListNode }{head: genList([]int{2,1})}, want: genList([]int{1,2})},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := sortList(tt.args.head); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("sortList() = %v, want %v", got, tt.want)
			}
		})
	}
}
