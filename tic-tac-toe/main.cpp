#include <iostream>

using namespace std;

char board[3][3] = {
	{0, 'x', 0},
	{0, 0, 0},
	{'o', 0, 0},
};

const char first_player_char = 'x';
const char second_player_char = 'o';

int turn = 1;

/*
  prints out board to output
*/
void print_board()
{
	char c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c = board[i][j] == 0 ? '-' : board[i][j];
			cout << c;
			if (j != 2)
				cout << "    "  << '|' << "    ";
		}
		cout << endl;
	}
}

/*
  checks if given pos is not filled, if given pos value is not 0
  it means a player selected it before 
*/
bool pos_available(int pos)
{
	int current_pos = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (pos == current_pos)
				return board[i][j] == 0;
			current_pos++;
		}
	}
	return true;
}

int get_pos_from_player()
{
	bool get = true;
	int pos = 0;
	do {
		cin >> pos;
		/*
		  checks if given position is valid for our board .
		  board positions are from 1 to 9 , like this :
		  1 | 2 | 3
		  4 | 5 | 6
		  7 | 8 | 9
		*/
		if (pos < 1 || pos > 9)
			continue;
		get = !pos_available(pos);
	} while (get);
	return pos;
}

int main()
{
	print_board();
	cout << get_pos_from_player() << endl;
	return 0;
}
