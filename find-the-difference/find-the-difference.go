package find_the_difference

func findTheDifference(s string, t string) byte {
	chars := make([]int, 26)

	for _, v := range []byte(s) {
		chars[v-'a'] += 1
	}
	for _, v := range []byte(t) {
		chars[v-'a'] -= 1
	}
	for _, b := range []byte(t) {
		if chars[b-'a'] < 0 {
			return b
		}
	}
	return 0
}
