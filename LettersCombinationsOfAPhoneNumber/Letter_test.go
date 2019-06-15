package main

import (
	"testing"
)

func Letter_Testing(A *testing.T) {
	digitsMap := "23"
	resultMap := []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}

	for index, value := range letterCombinations(digitsMap) {
		if value != resultMap[index] {
			A.FailNow()
		}

	}

}
