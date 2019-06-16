package main

import (
	"fmt"
)

func main() {
	str := "{}[()[]]"

	fmt.Println(isValid(str))
}

func match(in byte) (out byte) {
	switch in {
	case byte("("[0]):
		return byte(")"[0])
	case byte("["[0]):
		return byte("]"[0])
	case byte("{"[0]):
		return byte("}"[0])
	}
	return byte(0)
}

func isValid(s string) bool {
	length := len(s)
	var left []byte
	if length == 0 {
		return true
	}
	if length%2 == 1 {
		return false
	}
	var leftLen int

	for i := 0; i < length; i++ {
		left = append(left, s[i])

		leftLen = len(left)
		if leftLen == 1 {
			continue
		}
		fmt.Println(string(left), leftLen)

		if match(left[leftLen-2]) == s[i] {
			left = left[:leftLen-2]
		}
		fmt.Println(string(left))
	}

	fmt.Println(string(left))
	if len(left) == 0 {
		return true
	}
	return false
}
