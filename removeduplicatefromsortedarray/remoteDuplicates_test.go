package main

import (
	"fmt"
	"testing"
)

func Test_RemoveT(t *testing.T) {
	given1 := []int{1, 1, 2}
	lens := removeDuplicates(given1)
	if lens != 2 {
		t.Errorf("erorr given1,expected :2, get %d",lens)
	}
	fmt.Println(given1)
	given2 := []int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
	lens = removeDuplicates(given2)
	if lens != 5 {
		t.Errorf("erorr given2,expected :5, get %d",lens)
	}
	fmt.Println(given2)
}
