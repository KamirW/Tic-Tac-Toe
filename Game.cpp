#include "headers/Game.h"

int grid[GRID_SIZE][GRID_SIZE] = { 0 };
int currentPlayer = 1;

void drawGrid() {

    // Drawing Horizontal lines -> O(n)
    for(int i = 0; i < GRID_SIZE; i++) {
        DrawLine(0, i * (GetScreenHeight() / GRID_SIZE), GetScreenWidth(), i * (GetScreenHeight() / GRID_SIZE), DARKGRAY);
    }

    // Drawing Vertical Lines -> O(n)
    for(int j = 1; j < GRID_SIZE; j++) {
        DrawLine(j * (GetScreenWidth() / GRID_SIZE), 0, j * (GetScreenWidth() / GRID_SIZE), GetScreenHeight(), DARKGRAY);
    }

    // Draw X & O -> O(n^2)
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(grid[i][j] == 1) DrawText("X", i * (GetScreenWidth() / GRID_SIZE) + 10, j * (GetScreenHeight() / GRID_SIZE) + 10, 150, BLACK);

            else if(grid[i][j] == 2) DrawText("O", i * (GetScreenWidth() / GRID_SIZE) + 10, j * (GetScreenHeight() / GRID_SIZE) + 10, 150, BLACK);
        }
    }
}

void updateGame() {
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        int cellX = mouseX / (GetScreenWidth() / GRID_SIZE);
        int cellY = mouseY / (GetScreenHeight() / GRID_SIZE);

        // Check if cell is empty -> O(1)
        if(grid[cellX][cellY] == 0) {
            grid[cellX][cellY] = currentPlayer;  // Setting the letter to be X or O depending on player

            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }

    }
}

bool isGameOver() {
    bool win = true;

    // Check rows and columns
    for(int i = 0; i < GRID_SIZE; i++) {

        // Check Rows
        if(grid[i][0] != 0) {
            win = true;

            for(int j = 1; j < GRID_SIZE; j++) {
                if(grid[i][j] != grid[i][0]) {
                    win = false;
                    break;
                }
            }

            if(win) return win; // All rows are filled
        }

        // Check Columns
        if(grid[0][i] != 0) {
            win = true;

            for(int j = 1; j < GRID_SIZE; j++) {
                if(grid[j][i] != grid[0][i]) {
                    win = false;
                    break;
                }
            }

            if(win) return win; // All rows are filled
        }

        // Check Diagonals

    }
    return false;
}