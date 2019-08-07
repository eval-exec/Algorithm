package main

import (
	"fmt"
)

func main() {
	str := countAndSay(5)
	println(str)
}
func countAndSay(n int) string {
	if n == 1 {
		return "11"
	}
	var out = "11"
	for i := 0 ; i < n ; i++ {
		out =  getAndSay(out)
	}
	return out
}

func getAndSay(str string) string {

	var out string
	var cc int
	var c int
	for i := 0 ; i < len(str) ; i ++ {
		c = count(str[cc:])
		cc = cc +  c

		if c == 0 {
			break
		}
		out = out +  say(str[cc - 1:cc],c)
	}
	return out
}


func count(str string) (count int) {

	for i := 0; i < len(str); i++ {
		if str[0] == str[i] {
			count++
		} else {
			break
		}
	}
	return count
}

func say(str string,count int)(say string){

	return fmt.Sprint(count) + str[:1]
}
