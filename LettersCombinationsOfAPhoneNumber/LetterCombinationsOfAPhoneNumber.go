package main

import "fmt"

func main() {
	var digits string
	digits = "23"
	out := letterCombinations(digits)
	fmt.Println(out)

}

func letterCombinations(digits string) []string {
	length := len(digits)
	var outstring []string
	letters := map[string][]string{
		"2": {"a", "b", "c"},
		"3": {"d", "e", "f"},
		"4": {"g", "h", "i"},
		"5": {"j", "k", "l"},
		"6": {"m", "n", "o"},
		"7": {"p", "q", "r", "s"},
		"8": {"t", "u", "v"},
		"9": {"w", "x", "y", "z"},
	}

	for i := 0; i < length; i++ {
		outstring = stun(outstring, letters[string(digits[i])])
		fmt.Println(outstring)
	}
	return outstring

}

func stun(fronter []string, after []string) (output []string) {
	if len(fronter) == 0 {
		return after
	}
	for _, value1 := range fronter {
		for _, value2 := range after {
			output = append(output, value1+value2)
		}

	}
	return output
}
