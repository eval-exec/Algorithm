package sort_list

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

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	preslow, slow, fast := head, head, head

	for fast != nil && fast.Next != nil {
		preslow = slow
		slow = slow.Next
		fast = fast.Next.Next
	}

	preslow.Next = nil
	l1 := head
	l2 := slow


	if l1.Next != nil  {

		l1= sortList(l1)
	}
	if l2.Next != nil {

		l2= sortList(l2)
	}

	return merge(l1, l2)

}
//
//func printList(l *ListNode) {
//	if l == nil {
//		print("is nil")
//	}
//	for l != nil {
//		print(l.Val," ")
//		l = l.Next
//	}
//	println()
//}

func merge(l1, l2 *ListNode) *ListNode {


	ret := &ListNode{}
	head := ret
	var prev *ListNode
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			ret.Val = l1.Val
			l1 = l1.Next
		} else {
			ret.Val = l2.Val
			l2 = l2.Next
		}
		prev = ret
		ret.Next = &ListNode{}
		ret = ret.Next
	}


	if l1 != nil || l2 != nil {
		if l1 != nil {
			prev.Next = l1
		}
		if l2 != nil {
			prev.Next = l2
		}
	} else {
		prev.Next = nil
	}
	return head

}
