// SudokuSolver.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "solver.h"

int main()
{

    if (solveSudoku() == true)
        displayBoard();
    else
        std::cout << "No solution exists";
}


