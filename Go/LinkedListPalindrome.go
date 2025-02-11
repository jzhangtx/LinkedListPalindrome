package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) *ListNode {
	if len(v) == 0 {
		return nil
	}

	if len(v) == 1 {
		return &ListNode{v[0], nil}
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func Palindrome(pHead, pTail *ListNode) (bool, *ListNode, bool) {
	if pTail.next == nil {
		return pHead.data == pTail.data, pHead.next, false
	}

	isPalindrome, pHead, finished := Palindrome(pHead, pTail.next)
	if finished {
		return isPalindrome, nil, true
	}

	if pHead == pTail || pHead.next == pTail {
		finished = true
	}
	return (isPalindrome && pHead.data == pTail.data), pHead.next, finished
}

func IsPalindrome(list *ListNode) bool {
	isPalindrome, _, _ := Palindrome(list, list.next)

	return isPalindrome
}

func main() {
	for {
		fmt.Print("Number of nodes: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the list: ")
		pHead := GetListFromArray(vec)
		if IsPalindrome(pHead) {
			fmt.Println("The list is palindrome")
		} else {
			fmt.Println("The list is not palindrome")
		}
	}
}
