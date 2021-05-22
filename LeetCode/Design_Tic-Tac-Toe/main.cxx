#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Design Tic-Tac-Toe

*/

class TicTacToe {
 private:
  vector<pair<int, int>> rows, cols;
  pair<int, int> dia, adia;
  int _n = 0;

 public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
	rows.resize(n);
	cols.resize(n);
	_n = n;
  }

  /** Player {player} makes a move at ({row}, {col}).
	  @param row The row of the board.
	  @param col The column of the board.
	  @param player The player, can be either 1 or 2.
	  @return The current winning condition, can be either:
			  0: No one wins.
			  1: Player 1 wins.
			  2: Player 2 wins. */
  int move(int row, int col, int player) {
	if (rows[row].first == 0) {
	  rows[row] = make_pair(player, 1);
	} else if (rows[row].first == player) {
	  rows[row].second++;
	  if (rows[row].second == _n) return player;
	}

	if (cols[col].first == 0) {
	  cols[col] = make_pair(player, 1);
	} else if (cols[col].first == player) {
	  cols[col].second++;
	  if (cols[col].second == _n)return player;
	}

	if (row == col && row == _n / 2) {
	  if (adia.first == 0) {
		adia = make_pair(player, 1);
	  } else if (adia.first == player) {
		adia.second++;
	  }
	  if (dia.first == 0) {
		dia = make_pair(player, 1);
	  } else if (dia.first == player) {
		dia.second++;
	  }
	  if (dia.second == _n || adia.second == _n) return player;
	} else {
	  if (row == col) {
		if (dia.first == 0) {
		  dia = make_pair(player, 1);
		} else if (dia.first == player) {
		  dia.second++;
		  if (dia.second == _n) return player;
		}
	  } else if (row + col + 1 == _n) {
		if (adia.first == 0) {
		  adia = make_pair(player, 1);
		} else if (adia.first == player) {
		  adia.second++;
		  if (adia.second == _n) return player;
		}
	  }
	}
	return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */



//// END
struct T {

};

TEST(Solution, test) {
  T ts[] = {
	  {

	  },
	  {

	  },

  };

  for (T t : ts) {
	Solution solution;

  }
}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


