package main

func main() {
	input := [][]byte{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}


	printSudoku(input)
	solveSudoku(input)
	printSudoku(input)
}

func printSudoku(board [][]byte){
	for _, value1 := range board{
		for _, value2 := range value1 {
			print(string(value2)," ")
		}
		println()
	}
	println()
}

func prinLine(line []byte) {
	for _, value := range line{
		print(string(value)," ")
	}
	println()
}

var nums = []byte{'1', '2', '3', '4', '5', '6', '7', '8', '9'}

func solveSudoku(board [][]byte) {
	for {

		if checkFinish(board) {
			break
		}
		for i := 0; i < len(board); i++ {
			for j := 0; j < len(board); j++ {
				if board[i][j] != byte('.') {
					continue
				}
				columnRes := filterColumn(i, j, board)
				rowRes := filterRow(i, j, board)
				gridRes := filterGrid(i, j, board)
				result, resBool := checkIntersect(columnRes, rowRes, gridRes)
				if resBool == true {
					board[i][j] = result
					print(string(result)," ")
					println(i,j)
				}

			}
		}
		printSudoku(board)
	}

}

func checkFinish(board [][]byte) bool {
	for _, value1 := range board {
		for _, value2 := range value1 {
			if value2 == byte('.') {
				return false
			}
		}
	}
	return true
}

func filterColumn(x, y int, board [][]byte) (ret []byte) {

	for _, value := range nums {

		if ! checkIn(value, board[x]) {
			ret = append(ret, value)
		}
	}
	return
}


func filterRow(x, y int, board [][]byte) (ret []byte) {

	row := make([]byte, len(board[0]))

	for index, value := range board {
		for index2, value2 := range value {
			if index2 == x {
				row[index] = value2
			}
		}
	}

	for _, value := range nums {
		if ! checkIn(value, row ) {
			ret = append(ret, value)
		}
	}
	return
}

func filterGrid(x, y int, board [][]byte) (ret []byte) {

	var grid []byte
	for index1, value1 := range board {
		for index2, value2 := range value1 {
			if value2 == byte('.'){
				continue
			}
			if index1 >= (x/3)*3 && index1 <= (x/3+1)*3 && index2 >= (y/3)*3 && index2 <= (y/3+1)*3 {
				grid = append(grid, value2)
			}

		}
	}

	for _, value := range nums {
		if ! checkIn(value, grid ) {
			ret = append(ret, value)
		}
	}
	return

}

func checkIntersect(column, row, grid []byte) (ret byte, single bool) {
	var colRowRet []byte
	for _, valueCol := range column {
		if checkIn(valueCol, row) {
			colRowRet = append(colRowRet , valueCol)
		}
	}

	var retSlice  []byte
	for _, valueRow := range colRowRet{
		if checkIn(valueRow, grid) {
			retSlice = append(retSlice, valueRow)
		}
	}

	if len(retSlice) == 1 {
		return retSlice[0], true
	}

	return ret, false

}

func checkIn(in byte, nums []byte) bool {
	for _, value := range nums {
		if in == value {
			return true
		}
	}
	return false
}
