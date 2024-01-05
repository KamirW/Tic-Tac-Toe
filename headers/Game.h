#pragma once

#include "raylib.h"

#define GRID_SIZE 3

extern int grid[GRID_SIZE][GRID_SIZE];
extern int currentPlayer;

void drawGrid();

void updateGame();

bool isGameOver();