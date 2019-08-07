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
		fmt.Println(out,"is out")
		out =  getAndSay(out)
	}
	return out
}

func getAndSay(str string) string {

	fmt.Println("getAndSay str :",str)
	var out string
	var cc int
	var c int
	for i := 0 ; i < len(str) ; i ++ {
		fmt.Println("before : c is ", c, "cc is ",cc)
		c = count(str[cc:])
		cc = cc +  c
		fmt.Println("after : c is ", c, "cc is ",cc)

		if c == 0 {
			fmt.Println("cc is full, break")
			break
		}
		fmt.Println("c is ",c,"; cc is ",cc,";str[cc - 1:cc] is ",str[cc - 1: cc])
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

	fmt.Printf("say() get %s,%d",str,count)
	fmt.Println("say()",str,count)
	return fmt.Sprint(count) + str[:1]
}
