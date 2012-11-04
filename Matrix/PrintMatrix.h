#pragma once

#include <vector>
#include <iostream>

using std::vector;

class PrintMatrix
{
public:
	PrintMatrix(void);
	~PrintMatrix(void);

	static void PrintCircular(const vector<vector<int> > & matrix, size_t left_b, size_t right_b, size_t top_b, size_t bottom_b)
	{
		if(left_b >= right_b && top_b >= bottom_b)
			return;

		for(size_t lr = left_b; lr <= right_b; ++lr)
			std::cout << matrix[top_b][lr] << ", ";
		++top_b;

		for(size_t top_boundary = top_b; top_boundary <= bottom_b; ++top_boundary)
			std::cout << matrix[top_boundary][right_b] << ", ";
		--right_b;

		if(top_b < bottom_b)
			for(int rl = right_b; rl >= static_cast<int>(left_b); --rl)
				std::cout << matrix[bottom_b][rl] << ", ";
		--bottom_b;

		for(int bu = bottom_b; bu >= static_cast<int>(top_b); --bu)
			std::cout << matrix[bu][left_b] << ", ";
		++left_b;

		PrintCircular(matrix, left_b, right_b, top_b, bottom_b);
	}

	typedef enum MovingDirection {Right, Down, Left, Top};
	static void circularOneLoop (const vector<vector<int> > &  matrix) 
	{
		const int step_down =  1, step_right =  1;
		const int step_left = -1, step_up	 = -1;
		const int do_not_move = 0;
		const size_t number_of_elements = matrix.size() * matrix[0].size();

		MovingDirection current_move_direction = Right;
		vector<std::pair<int, int> > move_directions;
										// vertically, horizontally
		std::pair<int, int> left_to_right(do_not_move, step_right);
		move_directions.push_back(left_to_right);

		std::pair<int, int> top_to_bottom(step_down, do_not_move);
		move_directions.push_back(top_to_bottom);
		
		std::pair<int, int> right_to_left(do_not_move, step_left);
		move_directions.push_back(right_to_left);
		
		std::pair<int, int> bottom_to_top(step_up, do_not_move);
		move_directions.push_back(bottom_to_top);

		size_t left_boundary = 0, top_boundary = 0;
		size_t right_boundary = matrix[0].size() - 1;
		size_t bottom_boundary = matrix.size() - 1;
		size_t current_element = 0;
		size_t row = 0, column = 0;

		std::cout << matrix[row][column] << ", ";
		while(++current_element < number_of_elements)
		{
			if(current_move_direction == Right && column == right_boundary) 
			{
				++top_boundary;
				current_move_direction = GetNextMoveDirection(current_move_direction);
			}
			else if(current_move_direction == Down && row == bottom_boundary)
			{
				--right_boundary;
				current_move_direction = GetNextMoveDirection(current_move_direction);
			}
			else if(current_move_direction == Left && column == left_boundary)
			{
				--bottom_boundary;
				current_move_direction = GetNextMoveDirection(current_move_direction);
			}
			else if(current_move_direction == Top && row == top_boundary)
			{
				++left_boundary;
				current_move_direction = GetNextMoveDirection(current_move_direction);
			}

			row += move_directions[current_move_direction].first;
			column += move_directions[current_move_direction].second;
			std::cout << matrix[row][column] << ", ";
		}
	}

	static MovingDirection GetNextMoveDirection(MovingDirection current_direction)
	{
		if(current_direction >= Top)
			return Right;

		return static_cast<MovingDirection>(current_direction + 1);
	}

};

