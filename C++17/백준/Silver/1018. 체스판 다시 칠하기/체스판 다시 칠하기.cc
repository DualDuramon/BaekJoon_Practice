#include<iostream>
#include<vector>
#include<limits.h>

int row, col = 0;
bool answerBoard[8][8] = {
	{true,false,true,false,true,false,true,false},
	{false,true,false,true,false,true,false,true},
	{true,false,true,false,true,false,true,false},
	{false,true,false,true,false,true,false,true},
	{true,false,true,false,true,false,true,false},
	{false,true,false,true,false,true,false,true},
	{true,false,true,false,true,false,true,false},
	{false,true,false,true,false,true,false,true}
};

int CalCulate_Board_Coloring(std::vector<std::vector<bool>>* board, int startRow, int startCol){
	int count = 0;
	int count2 = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board->at(startRow + i)[startCol + j] != answerBoard[i][j])
				count++;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board->at(startRow + i)[startCol + j] == answerBoard[i][j])
				count2++;
		}
	}

	return count < count2 ? count : count2;
}

int main(void) {

	std::cin >> row >> col;

	std::vector<std::vector<bool>> board(row, std::vector<bool>(col));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			char temp;
			std::cin >> temp;
			board[i][j] = temp == 'B' ? true : false;
		}
	}
	int minNum = INT_MAX;

	for (int i = 0; i < row - 7; i++) {
		for (int j = 0; j < col - 7; j++) {
			int result = CalCulate_Board_Coloring(&board, i, j);

			if (result == 0) {
				std::cout << result << std::endl;
				return 0;
			}
			else if(result < minNum){
				minNum = result;
			}
		}

	}

	std::cout << minNum << std::endl;
    return 0;
}