package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	// f := &ListNode{5, nil}
	// e := &ListNode{4, f}
	// d := &ListNode{3, e}
	// c := &ListNode{2, d}
	b := &ListNode{1, nil}
	x := b
	for ; ; {
		if x.Next == nil {
			break
		}
		x = x.Next
	}
	out := removeNthFromEnd(b, 1)

	for ; ; {
		if out == nil {
			break
		}
		out = out.Next
	}
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	var sliceAnother []**ListNode
	var length int
	temped := &head
	for ; ; {
		length++
		sliceAnother = append(sliceAnother, temped)
		if (*temped).Next == nil {
			break
		}
		temped = &(*temped).Next
	}
	if length == 1 {
		return nil
	}
	// 0 1
	if length == 2 {
		if n == 1 {
			(**(sliceAnother[0])).Next = nil
			return *(sliceAnother[0])
		}
		if n == 2 {
			return *(sliceAnother[1])
		}
	}
	if n == length {
		return *(sliceAnother[1])
	}
	if n == 1 {
		(**(sliceAnother[length-n-1 ])).Next = nil
		return *(sliceAnother[0])

	}
	*((**(sliceAnother[length-n-1 ])).Next) = **(sliceAnother[length-n+1])
	return *(sliceAnother[0])
}
