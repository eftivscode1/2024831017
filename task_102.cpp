#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600
int radius=100;
int initialRadius=100;
int radiusIncrement=15;
// Global variables
bool gameIsRunning = false;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int redColorCode = 0;
Uint32 startTime;
Uint32 currentTime;

bool initializeWindow(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
        "Task_102",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0);

    if (!window)
    {
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return false;
    }
    return true;
}

void process_input(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gameIsRunning = false;
            break;

        default:
            break;
        }
    }
}

SDL_Rect getRectangleAttr()
{
    int rectWidth = 100;
    int rectHeight = 80;
    int rectX = (SCREEN_WIDTH - rectWidth) / 2;
    int rectY = (SCREEN_HEIGHT - rectHeight) / 2;
    return SDL_Rect{rectX, rectY, rectWidth, rectHeight};
}

void drawcircle(int cx, int cy, int r)
{
    for (int y = -r; y <= r; y++)
    {
        for (int x = -r; x <= r; x++)
        {
            if (x * x + y * y <= r * r)
            {
                SDL_RenderDrawPoint(renderer, cx + x, cy + y);
            }
        }
    }
}

void draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 103, 71,0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,218, 41, 28, 0);

    drawcircle(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,radius);

    SDL_RenderPresent(renderer);

    // Increase radius
    radius += radiusIncrement;

    // Reset if circle touches window boundaries
    if(radius >= SCREEN_WIDTH/2 || radius >= SCREEN_HEIGHT/2)
    {
        radius = initialRadius;
    }
}

void destroyWindow(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char **argv)
{
    gameIsRunning = initializeWindow();
    startTime = SDL_GetTicks();

    while (gameIsRunning)
    {
        process_input();
        draw();
        // SDL_Delay(16);
       
    }

    destroyWindow();

    return 0;
}
