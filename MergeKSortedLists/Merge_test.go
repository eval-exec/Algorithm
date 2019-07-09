package main

import (
	"fmt"
	"testing"
)

// [[1,4,5],[1,3,4],[2,6]]
func run_test(t testing.T) {

	listnodes := []*ListNode{
		&ListNode{1, &ListNode{4, &ListNode{5, nil}}},
		&ListNode{1, &ListNode{3, &ListNode{4, nil}}},
		&ListNode{2, &ListNode{6, nil}},
	}


	ret := mergeKLists(listnodes)
	for ret.Next != nil {
		fmt.Print(ret.Val)
		ret = ret.Next
	}
}
