package spiral_order

type Pixel struct {
	row int
	col int
}

func spiralOrder(matrix [][]int) []int {
	var ret []int
	if len(matrix) == 0 {
		return []int{}
	}

	rowNum := len(matrix)
	columnNum := len(matrix[0])

	M := Pixel{
		row: 0,
		col: 0,
	}
	N := Pixel{
		row: rowNum - 1,
		col: columnNum - 1,
	}

	for M.row <= N.row && M.col <= N.col {
		ret = append(ret, stripMatrix(&matrix, M, N)...)
		M.row++
		M.col++
		N.row--
		N.col--
	}
	return ret
}

func stripMatrix(matrix *[][]int, m, n Pixel) (outer []int) {
	if matrix == nil {
		return []int{}
	}
	if m.row == n.row {
		for i := m.col; i <= n.col; i++ {
			outer = append(outer, (*matrix)[m.row][i])
		}
		return
	}
	if m.col == n.col {
		for i := m.row; i <= n.row; i++ {
			outer = append(outer, (*matrix)[m.col][i])
		}
		return
	}

	for i := m.col; i <= n.col; i++ {
		outer = append(outer, (*matrix)[m.row][i])
	}

	for i := m.row + 1; i < n.row; i++ {
		outer = append(outer, (*matrix)[i][n.col])
	}

	for i := n.col; i > m.col; i-- {
		outer = append(outer, (*matrix)[n.row][i])
	}

	for i := n.row; i > m.row; i-- {
		outer = append(outer, (*matrix)[i][m.col])
	}

	return
}
