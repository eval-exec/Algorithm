package main

func main() {
	var in [][]int
	in = [][]int{ {5, 1, 9, 11},	{ 2, 4, 8, 10},{13, 3, 6, 7},	{15, 14, 12, 16}}
	printM(in)
	rotate(in)
	printM(in)
}

func printM(in [][]int){
	for _,val := range in {
		for _,x := range val {
			print(x)
			print(" ")
		}
		println()
	}
}

func rotate(matrix [][]int) {
	var all []int
	var length int
	for _, val := range matrix {
		for _, in := range val {
			all = append(all, in)
		}
		length = len(val)

	}

	for i := 0; i < length; i++ {
		for j := 0; j < length; j++ {
			matrix[i][j] = all[  length * length - j * length - length + i]
		}
	}

}
