package longestpalindrome


func main() {
	s := "abac"
	longestPalindrome(s)
}

func longestPalindrome(s string) string {
	if len(s) == 1 {
		return s
	}
	var ret string


	

	return ret
}

// 0 1 2 3 4 5 6 
func checkPalindromic(s string) bool {
	for i := 0; i < len(s) / 2; i++ {
		if s[i] != s[len(s) - i] {
			return false
		}
	}
	return true
}