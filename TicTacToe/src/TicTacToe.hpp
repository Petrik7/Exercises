/*
 * TicTacToe.hpp
 *
 *  Created on: Dec 9, 2012
 *      Author: peter
 */

#ifndef TICTACTOE_HPP_
#define TICTACTOE_HPP_

#include <vector>

class TicTacToe
{
public:
	TicTacToe(){};
	~TicTacToe(){};

	typedef std::vector< std::vector<char> > Matrix;
	static const size_t Dimention = 3;

	bool IsWinner(const Matrix & grid, char player)
	{
		// Check rows
		for(size_t r = 0; r < Dimention; ++r)
			for(size_t c = 0; c < Dimention; ++c)
			{
				if(grid[r][c] != player)
					break;
				else if(c == (Dimention - 1))
					return true;
			}
		// Check columns
		for(size_t c = 0; c < Dimention; ++c)
			for(size_t r = 0; r < Dimention; ++r)
			{
				if(grid[r][c] != player)
					break;
				else if(r == (Dimention - 1))
					return true;
			}
		// Check right to bottom-left diagonal
		for(size_t r = 0, c = Dimention - 1; r < Dimention && c >= 0; ++r, --c)
		{
			if(grid[r][c] != player)
				break;
			else if(r == (Dimention - 1) && c == 0)
				return true;
		}
		// Check left to bottom-right diagonal
		for(size_t c = 0, r = 0; r < Dimention && c < Dimention; ++r, ++c)
		{
			if(grid[r][c] != player)
				break;
			else if(r == (Dimention - 1) && c == (Dimention - 1))
				return true;
		}

		return false;
	}

};

#endif /* TICTACTOE_HPP_ */
