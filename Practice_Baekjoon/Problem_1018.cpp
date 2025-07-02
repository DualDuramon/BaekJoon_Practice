#include"problem.h"
#include<iostream>
#include<vector>
#include<limits.h>


/*
* 문제 : https://www.acmicpc.net/problem/1018
* 티어 : 실버 IV
* Black = true / White = false;
*/

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

void Problem_1018::Solution() {

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
			int result = CalCulate_Board_Coloring(&board, i, j, minNum);

			if (result == 0) {
				std::cout << result << std::endl;
				return;
			}
			else if(result < minNum){
				minNum = result;
			}
		}

	}

	std::cout << minNum << std::endl;
}

int Problem_1018::CalCulate_Board_Coloring(std::vector<std::vector<bool>>* board, int startRow, int startCol, int nowMin) {
	int count = 0;
	int count2 = 0;

	for (int i = 0; i < 8; i++) { //좌측상단이 Black일때
		for (int j = 0; j < 8; j++) {
			if (board->at(startRow + i)[startCol + j] != answerBoard[i][j])
				count++;
		}
	}

	for (int i = 0; i < 8; i++) { //좌측상단이 White일때
		for (int j = 0; j < 8; j++) {
			if (board->at(startRow + i)[startCol + j] == answerBoard[i][j])
				count2++;
		}
	}

	return count < count2 ? count : count2;
}