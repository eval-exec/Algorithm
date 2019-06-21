package main

import "fmt"

func main() {
	int1 := 101
	int2 := 2
	ret := divide(int1, int2)
	fmt.Println(ret)
}

func divide(dividend int, divisor int) int {
	var stat bool
	if dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0 {
		stat = true
	} else {
		stat = false
	}
	if dividend < 0 {
		dividend = - dividend
	}
	if divisor < 0 {
		divisor = - divisor
	}
	var ret int
	for ;; {
		if dividend >= divisor {
			dividend -= divisor
			ret++
		} else {
				break
		}
	}
	if stat {
		return ret
	} else {
		return -ret
	}
}
