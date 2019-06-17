package main

/**
 * Definition for singly-linked list.
 **/

type ListNode struct {
	Val  int
	Next *ListNode
}


func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	ret  := &ListNode{}
	var temp = ret
	if l1 == nil && l2 == nil {
		return nil
	}
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	for {

		if l1.Val < l2.Val {
			ret.Val = l1.Val
			ret.Next = &ListNode{}
			ret = ret.Next
			if l1.Next != nil {
				l1 = l1.Next
			} else {
				for ;l2.Next != nil ; {
					ret.Val = l2.Val
					ret.Next = &ListNode{}
					ret = ret.Next
					l2 =l2.Next
				}
				ret.Val = l2.Val
				ret.Next = nil
				break
			}
		} else {
			ret.Val = l2.Val
			ret.Next = &ListNode{}
			ret = ret.Next
			if l2.Next != nil {
				l2 = l2.Next
			} else {
				for ;l1.Next != nil ; {
					ret.Val = l1.Val
					ret.Next = &ListNode{}
					ret = ret.Next
					l1 =l1.Next
				}
				ret.Val = l1.Val
				ret.Next = nil
				break
			}
		}

	}
	return temp
}

