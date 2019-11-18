package main

import "sort"

var input = []string{"eat", "tea", "tan", "ate", "nat", "bat"}

func main() {
	out := groupAnagrams(input)

	printStrSlice(out)

}

func printStrSlice(in [][]string) {
	for _, item := range in {
		for _, str := range item {
			print(str)
			print(" ")
		}
		println()
	}
}

func groupAnagrams(strs []string) [][]string {

	// ret := make([][]string, length, length)
	ret := make([][]string,len(strs),len(strs))

	for i := 0; i < len(strs); i++ {
		ret[i] = append(ret[i],strs[i])

		for j := i+1; j < len(strs); j++ {
			if isAnagram(strs[i],strs[j]){
				ret[i] = append(ret[i],strs[j])
				strs = append(strs[j:],strs[j+1:]...)
			}
		}
	}
	return ret
}

func isAnagram(s1, s2 string) bool {
	return sortString(s1) == sortString(s2)

}

func sortString(s string) string {
	var ret []int
	for _, b := range s {
		ret = append(ret, int(b))
	}
	sort.Ints(ret)

	var retb []byte
	for _, p := range ret {
		retb = append(retb, byte(p))
	}
	return string(retb)
}
