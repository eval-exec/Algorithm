package main

func longestValidParentheses(s string) int {
	var ret int
	length := len(s)
	for i := 0; i < length; i++ {
		for j := length; j > i+1; j-- {
			if parenthesesValid(s[i:j]) {
				if j-i > ret {
					ret = j - i
				}
			}
		}
	}
	return ret
}

func parenthesesValid(s string) bool {
	var parentheses = "()"
	length := len(s)
	if length%2 != 0 || length < 2 {
		return false
	}
	if length == 2 {
		if s[0] == parentheses[0] && s[1] == parentheses[1] {
			return true
		} else {
			return false
		}
	}
	if s[length-2] == parentheses[0] && s[length-1 ] == parentheses[1] {
		return parenthesesValid(s[:length-2])
	}
	if s[0] == parentheses[0] && s[1] == parentheses[1] {
		return parenthesesValid(s[2:])
	}
	if s[0] == parentheses[0] && s[length-1 ] == parentheses[1] {
		return parenthesesValid(s[1 : length-1])
	}
	return false
}
