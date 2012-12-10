//============================================================================
// Name        : TicTacToe.cpp
// Author      : peter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "TicTacToe.hpp"

using namespace std;



void PrintMatrix(const TicTacToe::Matrix & grid)
{
	for(size_t r = 0; r < TicTacToe::Dimention; ++r)
		for(size_t c = 0; c < TicTacToe::Dimention; ++c)
		{
			//std::cout << "[" << r << "]" << "[" << c << "]";
			std::cout << grid[r][c];

			if(c == (TicTacToe::Dimention - 1))
				std::cout << std::endl;
			else
				std::cout << " . ";

		}
}

int main()
{
	TicTacToe tic_tac_toe;

	TicTacToe::Matrix play_grid;

	std::vector<char> row_1(3, 'o');
	std::vector<char> row_2(3, 'x');
	std::vector<char> row_3(3, 'o');

	play_grid.push_back(row_1);
	play_grid.push_back(row_2);
	play_grid.push_back(row_3);

	// o o o
	// x x x
	// o o o
	PrintMatrix(play_grid);
	std::cout << std::endl;
	tic_tac_toe.IsWinner(play_grid, 'x') ? (std::cout << "Passed for x") : (std::cout << "Failed for x");
	std::cout << std::endl;
	tic_tac_toe.IsWinner(play_grid, 'o') ? (std::cout << "Passed for o") : (std::cout << "Failed for o");
	std::cout << std::endl;

	// o o x
	// x 0 x
	// o o x
	play_grid[1][1] = 'o';
	play_grid[0][2] = 'x';
	play_grid[2][2] = 'x';

	PrintMatrix(play_grid);
	std::cout << std::endl;
	tic_tac_toe.IsWinner(play_grid, 'x') ? (std::cout << "Passed for x") : (std::cout << "Failed for x");
	std::cout << std::endl;
	tic_tac_toe.IsWinner(play_grid, 'o') ? (std::cout << "Passed for o") : (std::cout << "Failed for o");
	std::cout << std::endl;

	// o o x
	// x x x
	// x o 0
	play_grid[1][1] = 'x';
	play_grid[2][0] = 'x';
	play_grid[2][2] = 'o';
	play_grid[1][2] = 'o';

	PrintMatrix(play_grid);
	std::cout << std::endl;
	tic_tac_toe.IsWinner(play_grid, 'x') ? (std::cout << "Passed for x") : (std::cout << "Failed for x");
	std::cout << std::endl;
	tic_tac_toe.IsWinner(play_grid, 'o') ? (std::cout << "Failed for o") : (std::cout << "Passed for o");
	std::cout << std::endl;

	// x o 0
	// 0 x x
	// x o x
	play_grid[0][0] = 'x';
	play_grid[2][2] = 'x';
	play_grid[1][0] = 'o';
	play_grid[0][2] = 'o';

	PrintMatrix(play_grid);
	std::cout << std::endl;
	tic_tac_toe.IsWinner(play_grid, 'x') ? (std::cout << "Passed for x") : (std::cout << "Failed for x");
	std::cout << std::endl;
	tic_tac_toe.IsWinner(play_grid, 'o') ? (std::cout << "Failed for o") : (std::cout << "Passed for o");
	std::cout << std::endl;

	return 0;
}
