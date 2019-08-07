package main

import "fmt"

func main() {
	haystack := "leetcodePracticx"
	needle := "x"
	ret := strStr(haystack,needle)
	fmt.Println(ret)
}

func strStr(haystack string, needle string) int {
	lengthHatstck := len(haystack)
	lengthNeedle := len(needle)
	if lengthNeedle == 0 {
		return 0
	}
	if  lengthHatstck < lengthNeedle{
		return -1
	}
	for i := 0; i < lengthHatstck - lengthNeedle + 1; i++ {
		if strEqul([]byte(needle),[]byte(haystack[i:i+ lengthNeedle])) {
			return i
		}else {
			continue
		}
	}
	return -1

}

func strEqul(str1, str2 []byte) bool {
	for index, value := range str1{
		if value != str2[index] {
			return false
		}
	}
	return true
}
