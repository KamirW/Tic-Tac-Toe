#include "headers/main.h"
#include <iostream>

int main() { 
    // Creating the window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tic Tac Toe");

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        //Update the game -> O(1)
        updateGame();

        if(isGameOver()) {
            BeginDrawing();

            // Draw the grid -> O(n^2)
            drawGrid();
            DrawRectangle(0, GetScreenHeight() / GRID_SIZE, GetScreenWidth(), GetScreenHeight() / GRID_SIZE, BLACK);
            DrawText("Game Over", 30, GetScreenHeight() / GRID_SIZE + 50, 100, RED);

            EndDrawing();
            

        } else {
            BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw the grid -> O(n^2)
            drawGrid();

            EndDrawing();
        }

    }

    CloseWindow();

    return 0;
 }