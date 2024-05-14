#include <iostream>
#define MAX_COLS 9
#define MAX_ROW 9
#define UNASSIGNED 0

static int board[9][9] = {
					{3, 0, 6, 5, 0, 8, 4, 0, 0},
					{5, 2, 0, 0, 0, 0, 0, 0, 0},
					{0, 8, 7, 0, 0, 0, 0, 3, 1},
					{0, 0, 3, 0, 1, 0, 0, 8, 0},
					{9, 0, 0, 8, 6, 3, 0, 0, 5},
					{0, 5, 0, 0, 9, 0, 6, 0, 0},
					{1, 3, 0, 0, 0, 0, 2, 5, 0},
					{0, 0, 0, 0, 0, 0, 0, 7, 4},
					{0, 0, 5, 2, 0, 6, 3, 0, 0}
};
/* Display Board */
/**
 * @brief Affiche le plateau de jeu
 */
void displayBoard() {

	std::cout << "     |     |     |     |     |     |     |     |     \n";
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			if (j == MAX_COLS - 1) {
				std::cout << "   " << board[i][j] << "  ";
			}
			else {
				std::cout << "  " << board[i][j] << "  |";
			}
		}

		std::cout << "\n";
		if (i < MAX_ROW - 1)
			std::cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____ \n";
		std::cout << "     |     |     |     |     |     |     |     |     \n";

	}
	std::cout << "\n";

}

static bool isAlreadyInColumn(int value, int col) {
	for (int row = 0; row < MAX_ROW; row++) {
		if (board[row][col] == value)
			return true;
	}
	return false;
}

static bool isAlreadyInLine(int value, int row) {
	for (int col = 0; col < MAX_COLS; col++) {
		if (board[row][col] == value)
			return true;
	}
	return false;
}

static bool isAlreadyInSquare(int value, int row, int col) {

	int squareRow = (row / 3) * 3;
	int squareCol = (col / 3) * 3;

	for (int row = squareRow; row < squareRow + 3; row++) {
		for (int col = squareCol; col < squareCol + 3; col++) {
			
			if (board[row][col] == value) {
				return true;
			}
		}
	}
	return false;
}

bool isValid(int value, int row, int col) {
	if (!isAlreadyInColumn(value, col) && !isAlreadyInLine(value, row) && !isAlreadyInSquare(value, row, col)) {
		return true;
	}

	return false;
}

static bool isUnassigned(int &row, int &col) {
	// on passe row et col par référence comme ça quand une case non assigné est trouvée , row et col sont updaté dans le fonction solve sudoku.
	for ( row  = 0; row < MAX_ROW; row++)
		for ( col = 0; col < MAX_COLS; col++)
			if (board[row][col] == UNASSIGNED)
				return true;
	return false;
}


/* solveur */
bool solveSudoku(void) {
	int row = -1;
	int col = -1;

	// Si pas de case non assignée trouver alors c'est qu'on a fini
	if (!isUnassigned(row, col))
		// success!
		return true;

	// Boucle de 1 à 9 
	for (int num = 1; num <= 9; num++)
	{
		// Vérification si placement possible 
		if (isValid(num, row, col))
		{
			// Placement du numéro 
			board[row][col] = num;

			// Return, if success
			if (solveSudoku())
				return true;

			// Failure, unmake & try again
			board[row][col] = UNASSIGNED;
		}
	}
	// This triggers backtracking
	return false;
}