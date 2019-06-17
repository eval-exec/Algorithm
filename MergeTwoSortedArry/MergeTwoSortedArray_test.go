package main

import (
	"fmt"
	"testing"
)

func Test( t *testing.T){
	l13 := &ListNode{4,nil}
	l12 := &ListNode{2,l13}
	l1 := &ListNode{1,l12}


	l23 := &ListNode{4,nil}
	l22 := &ListNode{3,l23}
	l2 := &ListNode{1,l22}

	// x1 := &ListNode{}
	// x2 := &ListNode{}


	ret := mergeTwoLists(l1, l2)
	fmt.Println("---")
	for ; ret != nil ;{
		fmt.Println(ret.Val)
		ret = ret.Next
	}

}