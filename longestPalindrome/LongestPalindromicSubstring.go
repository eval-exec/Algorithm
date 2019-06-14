package longestpalindrome

import (
	"fmt"
)

func main() {
	s := "abac"
	longestPalindrome(s)
}

func longestPalindrome(s string) string {
	if len(s) == 1 {
		return s
	}
	var ret string
	fmt.Println(s)
	return ret
}
