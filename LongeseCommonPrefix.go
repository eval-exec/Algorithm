package main

import (
	"fmt"
)

var input = []string{"flower", "flg", "flight"}

func main() {
	ret := longestCommonPrefix(input)
	fmt.Println(ret)
}

func longestCommonPrefix(strs []string) string {
	var ret []byte
	var lenstr = len(strs)
	if lenstr == 0 {
		return ""
	}
	var length = len(strs[0])
	for _, item := range strs {
		lenitem := len(item)
		if lenitem < length {
			length = lenitem
		}
	}
	for i := 0; i < length; i++ {
		for j := 1; j < lenstr; j++ {
			if strs[0][i] != strs[j][i] {
				fmt.Println(string(strs[0][i]))

				return string(ret)
			}
		}
		//		fmt.Println(string((strs[0][i])))
		ret = append(ret, byte(strs[0][i]))
	}
	return string(ret)
}
