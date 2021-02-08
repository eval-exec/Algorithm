package main

import (
	"fmt"
)


func main() {
	s := "abb"
	fmt.Println(longestPalindrome(s))
}

func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}

	for i := len(s); i > 0; i-- {
		for j := 0; j < len(s) - i + 1; j++ {
			fmt.Println(j,i,s[j:i + j],checkPalindromic(s[j:i + j]))
			if checkPalindromic(s[j:i + j]) {
				return s[j:i + j]
			}
		}
	}
	return string(s[0])
}

func checkPalindromic(s string) bool {
	for i := 0; i <= len(s) / 2; i++ {
		if s[i] != s[len(s) - i - 1] {
			return false
		}
	}
	return true
}