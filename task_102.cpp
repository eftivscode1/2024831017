#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 700
int radius=100;
// Global variables
bool gameIsRunning = false;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int redColorCode = 0;
Uint32 startTime;
Uint32 currentTime;

bool initializeWindow(void)
{
    // Initialize SDL with video support
    // Automatically initializes the Event Handling, File I/O and Threading subsystems
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return false;
    }

    // Create an SDL window
    window = SDL_CreateWindow(
        "SDL Introduction",
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

    // Create an SDL renderer for rendering graphics in the window
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
    // Poll SDL events (e.g., window close)
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gameIsRunning = false; // Exit the game loop
            break;

        default:
            break;
        }
    }
}

SDL_Rect getRectangleAttr()
{
    // Calculate the position of the rectangle in the center of the window
    int rectWidth = 100;
    int rectHeight = 80;
    int rectX = (SCREEN_WIDTH - rectWidth) / 2;
    int rectY = (SCREEN_HEIGHT - rectHeight) / 2;
    return SDL_Rect{rectX, rectY, rectWidth, rectHeight};
}

void drawcircle(int cx,int cy,int r){
int x=0;
int y=-r;
int p=-r;
while(x<-y){
    if(p>0){
        y+=1;
        p+=2*(x+y)+1;

    }
    else{
        p+=2*x+1;

    }
// SDL_RenderDrawPoint(renderer,cx+x,cy+y);
SDL_RenderDrawPoint(renderer,cx+x,cy+y);
SDL_RenderDrawPoint(renderer,cx-x,cy+y);
SDL_RenderDrawPoint(renderer,cx+x,cy-y);
SDL_RenderDrawPoint(renderer,cx-x,cy-y);
SDL_RenderDrawPoint(renderer,cx+y,cy+x);
SDL_RenderDrawPoint(renderer,cx-y,cy+x);
SDL_RenderDrawPoint(renderer,cx+y,cy-x);
SDL_RenderDrawPoint(renderer,cx-y,cy-x);
x+=1;
}
}

void draw()
{
    // Set the render draw color (R, G, B, A)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Clear the renderer with the specified draw color
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,0, 255, 0,255);

    drawcircle(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,100);

    // Present the renderer (draw the frame to the window)
    SDL_RenderPresent(renderer);
}



void destroyWindow(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char **argv)
{
    // The game loop control variable
    gameIsRunning = initializeWindow();
    startTime = SDL_GetTicks();

    // Game loop: keep the application running until 'running' is set to false
    while (gameIsRunning)
    {
        // Continuously polls for SDL events
        process_input();

        // Draw the rendered window
        draw();
    }

    // Clean up and exit the application
    destroyWindow();

    return 0;
}
//  //g++ main.cpp -I"C:/Users/mdzak/OneDrive/Desktop/sdl/include" -L"C:/Users/mdzak/OneDrive/Desktop/sdl/lib" -lmingw32 -lSDL2main -lSDL2 -o main.exe ; ./main.exe
