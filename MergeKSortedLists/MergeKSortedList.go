package main

import (
	"fmt"
	"sort"
)

func main() {
	// lemonades := []*ListNode{
	// 	{1, &ListNode{4, &ListNode{5, nil}}},
	// 	{1, &ListNode{3, &ListNode{4, nil}}},
	// 	{2, &ListNode{6, nil}},
	// }

	nilList := []*ListNode{{},{0,nil},

	}

	ret := mergeKLists(nilList)
	fmt.Println("we get return")
	for ret != nil {
		fmt.Print(ret.Val)
		ret = ret.Next
	}
}

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	var inits []int
	fmt.Println(len(lists),"is len lists")
	for index, list := range lists {
		fmt.Println("equ nil", lists[index] == nil  ,list)
		// for lists[index] != nil {
		// 	fmt.Println(list.Val)
		// 	inits = append(inits,list.Val)
		// 	list = list.Next
		// }
	}
	sort.Ints(inits)

	var ret  = &ListNode{}
	temp := ret

	length := len(inits)
	fmt.Println("sorty iniys")
	for indedx, value := range inits {
		ret.Val = value
		ret.Next = &ListNode{}
		fmt.Println(ret.Val)
		if indedx == length - 1 {
			ret.Next = nil
		}
		ret = ret.Next

	}

	return temp


}
