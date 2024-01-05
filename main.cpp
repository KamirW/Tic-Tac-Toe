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
            // BeginDrawing();

            // ClearBackground(RAYWHITE);

            // // Draw the grid -> O(n^2)
            // drawGrid();

            // EndDrawing();

            DrawRectangle(0, GetScreenHeight() / GRID_SIZE, GetScreenWidth(), GetScreenHeight() / GRID_SIZE, BLACK);

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