package main

import (
	"fmt"
	"strconv"
)

func main(){
	str := "22"
	out := myAtoi(str)
	fmt.Println(out,"is out")
}
func myAtoi(str string) int {
	var isPositive bool
	for str[:1] == " "{
		str = str[1:]
	}
	if str[:1] == "-" {
		isPositive = false
		str = str[1:]
	}

	for i := 0; i < len(str); i++ {
		if str[i:i+1] >= "0" || str[i:i+1] <= "9" {
			continue
		}else {
			str = str[:i]
			break
		}
	}

}