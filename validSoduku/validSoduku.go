package main

func main() {

	input := [][]byte{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	}

	// input2 := [][]byte{
	//
	// 	{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
	// 	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	// 	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	// 	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	// 	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	// 	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	// 	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	// 	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	// 	{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	// }

	isS := isValidSudoku(input)
	println("result : ", isS)

}
func printBigByte(input [][]byte) {
	for _, item := range input {
		printByte(item)
	}
}

func printByte(input []byte) {
	for _, val := range input {
		print(string(val), " ")
	}
	println()
}

func validLine(line []byte) bool {
	for index, _ := range line {
		for _, val := range line[index+1:] {
			if val == byte('.') {
				continue
			}

			if line[index] == val {
				return false
			}
		}
	}
	return true
}
func isValidSudoku(board [][]byte) bool {

	for _, everyLine := range board {
		if !validLine(everyLine) {
			return false
		}
	}

	rowsBoard := getRows(board)

	for _, everyRow := range rowsBoard {
		if !validLine(everyRow) {
			return false
		}
	}

	gridsBoard := getGrids(board)

	for _, everyGrids := range gridsBoard {
		if !validLine(everyGrids) {
			return false
		}
	}

	return true
}

func getGrids(board [][]byte) (ret [][]byte) {
	type xy struct {
		X int
		Y int
	}
	pixel := make([]xy, 9)
	for index, _ := range pixel {
		pixel[index] = xy{
			X: 3 * (index / 3),
			Y: 3 * (index % 3),
		}
	}

	ret = make([][]byte, len(board))
	for index, _ := range ret {
		ret[index] = make([]byte, len(board[0]))
	}

	for i := 0; i < 9; i++ {

		var retIndex int
		retIndex = 0
		for index1, value1 := range board {

			for index2, _ := range value1 {
				if (index1-pixel[i].X >= 0) && (index2-pixel[i].Y >= 0) && (index1-pixel[i].X <= 2) && (index2-pixel[i].Y <= 2) {

					ret[i][retIndex] = board[index1][index2]
					retIndex++
				}

			}
		}
	}
	return
}

func getRows(board [][]byte) (ret [][]byte) {

	ret = make([][]byte, len(board))
	for index, _ := range ret {
		ret[index] = make([]byte, len(board[0]))
	}

	for index1, value1 := range board {
		for index2, value2 := range value1 {
			ret[index2][index1] = value2
		}
	}

	return

}
