// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to turn one unit left
void turn_left(int& r, int& c)
{
	c -= 1;
}

// Function to turn one unit right
void turn_right(int& r, int& c)
{
	c += 1;
}

// Function to turn one unit up
void turn_up(int& r, int& c)
{
	r -= 1;
}

// Function to turn one unit down
void turn_down(int& r, int& c)
{
	r += 1;
}

// For checking whether a cell lies
// outside the matrix or not
bool is_outside(int row, int col,
				int r, int c)
{
	if (r >= row || c >= col
		|| r < 0 || c < 0)
		return true;
	return false;
}

// Function to rotate in clockwise manner
void next_turn(char& previous_direction,
			int& r, int& c)
{
	if (previous_direction == 'u') {
		turn_right(r, c);
		previous_direction = 'r';
	}
	else if (previous_direction == 'r') {
		turn_down(r, c);
		previous_direction = 'd';
	}
	else if (previous_direction == 'd') {
		turn_left(r, c);
		previous_direction = 'l';
	}
	else if (previous_direction == 'l') {
		turn_up(r, c);
		previous_direction = 'u';
	}
}

// Function to move in the same direction
// as its prev_direction
void move_in_same_direction(
	char previous_direction,
	int& r, int& c)
{
	if (previous_direction == 'r')
		c++;
	else if (previous_direction == 'u')
		r--;
	else if (previous_direction == 'd')
		r++;
	else if (previous_direction == 'l')
		c--;
}

// Function to find the spiral order of
// of matrix according to given rules
vector<vector<int> > spiralMatrixIII(
	int rows, int cols, int r, int c)
{
	// For storing the co-ordinates
	vector<vector<int> > res;
	char previous_direction = 'r';

	// For keeping track of no of steps
	// to go without turn
	int turning_elements = 2;

	// Count is for counting total cells
	// put in the res
	int count = 0;

	// Current_count is for keeping track
	// of how many cells need to
	// traversed in the same direction
	int current_count = 0;

	// For keeping track the number
	// of turns we have made
	int turn_count = 0;
	int limit = rows * cols;

	while (count < limit) {

		// If the current cell is within
		// the board
		if (!is_outside(rows, cols, r, c)) {
			res.push_back({ r, c });
			count++;
		}
		current_count++;

		// After visiting turning elements
		// of cells we change our turn
		if (current_count == turning_elements) {

			// Changing our direction
			// we have to increase the
			// turn count
			turn_count++;

			// In Every 2nd turn increasing
			// the elements the turn visiting
			if (turn_count == 2)
				turning_elements++;

			// After every 3rd turn reset
			// the turn_count to 1
			else if (turn_count == 3) {
				turn_count = 1;
			}

			// Changing direction to next
			// direction based on the
			// previous direction
			next_turn(previous_direction, r, c);

			// Reset the current_count
			current_count = 1;
		}
		else {
			move_in_same_direction(
				previous_direction, r, c);
		}
	}

	// Return the traversal
	return res;
}

// Driver Code
int main()
{
	int N = 5, M = 6, X = 1, Y = 4;
	auto res = spiralMatrixIII(N, M, X, Y);

	// Display answer
	for (auto it : res) {
		cout << '(' << it[0] << ", "
			<< it[1] << ')' << ' ';
	}
	return 0;
}
