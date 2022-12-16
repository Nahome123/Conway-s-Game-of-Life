

#include <iostream>
#include <vector>
#include <cstdlib>

const int SIZE = 50;

// Life grid
int grid[SIZE][SIZE];

// Create a new grid with random cells
void initializeGrid()
{
    // Fill the grid with random cells
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the grid
void printGrid()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Calculate the number of neighbors
int countNeighbors(int x, int y)
{
    int count = 0;
    
    // Check the 3x3 grid around the cell
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            // Don't count the cell itself
            if (i == 0 && j == 0)
            {
                continue;
            }
            
            // Wrap around the edges
            int col = (x + i + SIZE) % SIZE;
            int row = (y + j + SIZE) % SIZE;
            
            count += grid[col][row];
        }
    }
    
    return count;
}

// Apply the rules of the game
void updateGrid()
{
    // Create a new grid
    int newGrid[SIZE][SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int neighbors = countNeighbors(i, j);
            
            // Cell is alive
            if (grid[i][j] == 1)
            {
                // Rule 1 or 3
                if (neighbors < 2 || neighbors > 3)
                {
                    newGrid[i][j] = 0;
                }
                // Rule 2
                else
                {
                    newGrid[i][j] = 1;
                }
            }
            // Cell is dead
            else
            {
                // Rule 4
                if (neighbors == 3)
                {
                    newGrid[i][j] = 1;
                }
                // Rule 5
                else
                {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    
    // Copy the new grid to the old grid
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main()
{
    initializeGrid();
    
    // Run the game for 10 iterations
    for (int i = 0; i < 10; i++)
    {
        printGrid();
        updateGrid();
    }
    
    return 0;
}