

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

using namespace std;

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

// Core system
bool gameIsRunning = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

// Enemy (auto moving circle)
int enemyX = 0;
int enemyY = SCREEN_HEIGHT / 2;
int enemyRadius = 50;
int enemySpeed = 30;

// Player (controlled circle)
int playerX = SCREEN_WIDTH / 2;
int playerY = 0;
int playerRadius = 50;

// Collision flag
bool isColliding = false;

// Initialize SDL
bool initializeWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL init failed\n";
        return false;
    }

    window = SDL_CreateWindow(
        "Circle Collision",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0);

    if (!window)
    {
        cout << "Window creation failed\n";
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        cout << "Renderer failed\n";
        return false;
    }

    return true;
}

// Input handling
void process_input()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            gameIsRunning = false;

        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:    playerY -= 50; break;
            case SDLK_DOWN:  playerY +=50; break;
            case SDLK_LEFT:  playerX -= 50; break;
            case SDLK_RIGHT: playerX += 50; break;
            }
        }
    }
}

// Draw filled circle
void drawCircle(int cx, int cy, int r)
{
    for (int i = -r; i <= r; i++)
    {
        for (int j = -r; j <= r; j++)
        {
            if (i * i + j * j <= r * r)
            {
                SDL_RenderDrawPoint(renderer, cx + i, cy + j);
            }
        }
    }
}

// Collision check
bool checkCollision()
{
    int dx = playerX - enemyX;
    int dy = playerY - enemyY;

    float distance = sqrt(dx * dx + dy * dy);

    return distance <= (playerRadius + enemyRadius);
}

// Update logic
void update()
{
    // Move enemy left → right
    enemyX += enemySpeed;

    if (enemyX > SCREEN_WIDTH)
        enemyX = 0;

    // Collision check
    isColliding = checkCollision();
}

// Render everything
void draw()
{
    // Background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Change color on collision
    if (isColliding)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // RED
    else
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // GREEN

    // Draw enemy
    drawCircle(enemyX, enemyY, enemyRadius);

    // Draw player
    drawCircle(playerX, playerY, playerRadius);

    SDL_RenderPresent(renderer);
}

// Cleanup
void destroyWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Main loop
int main(int argc, char* argv[])
{
    gameIsRunning = initializeWindow();

    while (gameIsRunning)
    {
        process_input();
        update();
        draw();

        SDL_Delay(16); // ~60 FPS
    }

    destroyWindow();
    return 0;
}
//g++ main.cpp -I"C:/Users/mdzak/OneDrive/Desktop/sdl/include" -L"C:/Users/mdzak/OneDrive/Desktop/sdl/lib" -lmingw32 -lSDL2main -lSDL2 -o main.exe ; ./main.exe