package main

import "testing"

func strStr_test(t testing.T){
	input := [][]string{{"x","x"},
		{"hack","ck"},
		{"fjeiowjfei","x"},
	}
	result := []int{0,2,-1}
	for index, value := range input {
		if strStr(value[0],value[1]) !=  result[index] {
			t.Fail()
		}
	}
}