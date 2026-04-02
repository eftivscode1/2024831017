// // #include <SDL2/SDL.h>
// // #include <stdio.h>

// // #define SCREEN_WIDTH 800
// // #define SCREEN_HEIGHT 700
// // int radius=100;
// // // Global variables
// // bool gameIsRunning = false;
// // SDL_Window *window = NULL;
// // SDL_Renderer *renderer = NULL;
// // int redColorCode = 0;
// // Uint32 startTime;
// // Uint32 currentTime;

// // bool initializeWindow(void)
// // {
// //     // Initialize SDL with video support
// //     // Automatically initializes the Event Handling, File I/O and Threading subsystems
// //     if (SDL_Init(SDL_INIT_VIDEO) < 0)
// //     {
// //         printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
// //         return false;
// //     }

// //     // Create an SDL window
// //     window = SDL_CreateWindow(
// //         "SDL Introduction",
// //         SDL_WINDOWPOS_UNDEFINED,
// //         SDL_WINDOWPOS_UNDEFINED,
// //         SCREEN_WIDTH,
// //         SCREEN_HEIGHT,
// //         0);

// //     if (!window)
// //     {
// //         printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
// //         return false;
// //     }

// //     // Create an SDL renderer for rendering graphics in the window
// //     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
// //     if (!renderer)
// //     {
// //         printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
// //         return false;
// //     }
// //     return true;
// // }

// // void process_input(void)
// // {
// //     // Poll SDL events (e.g., window close)
// //     SDL_Event event;
// //     while (SDL_PollEvent(&event))
// //     {
// //         switch (event.type)
// //         {
// //         case SDL_QUIT:
// //             gameIsRunning = false; // Exit the game loop
// //             break;

// //         default:
// //             break;
// //         }
// //     }
// // }

// // SDL_Rect getRectangleAttr()
// // {
// //     // Calculate the position of the rectangle in the center of the window
// //     int rectWidth = 100;
// //     int rectHeight = 80;
// //     int rectX = (SCREEN_WIDTH - rectWidth) / 2;
// //     int rectY = (SCREEN_HEIGHT - rectHeight) / 2;
// //     return SDL_Rect{rectX, rectY, rectWidth, rectHeight};
// // }

// // void drawcircle(int cx,int cy,int r){
// // int x=0;
// // int y=-r;
// // int p=-r;
// // while(x<-y){
// //     if(p>0){
// //         y+=1;
// //         p+=2*(x+y)+1;

// //     }
// //     else{
// //         p+=2*x+1;

// //     }
// // // SDL_RenderDrawPoint(renderer,cx+x,cy+y);
// // SDL_RenderDrawPoint(renderer,cx+x,cy+y);
// // SDL_RenderDrawPoint(renderer,cx-x,cy+y);
// // SDL_RenderDrawPoint(renderer,cx+x,cy-y);
// // SDL_RenderDrawPoint(renderer,cx-x,cy-y);
// // SDL_RenderDrawPoint(renderer,cx+y,cy+x);
// // SDL_RenderDrawPoint(renderer,cx-y,cy+x);
// // SDL_RenderDrawPoint(renderer,cx+y,cy-x);
// // SDL_RenderDrawPoint(renderer,cx-y,cy-x);
// // x+=1;
// // }
// // }

// // // void draw()
// // // {
// // //     // Set the render draw color (R, G, B, A)
// // //     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

// // //     // Clear the renderer with the specified draw color
// // //     SDL_RenderClear(renderer);
// // //     SDL_SetRenderDrawColor(renderer,0, 255, 0,255);

// // //     drawcircle(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,100);

// // //     // Present the renderer (draw the frame to the window)
// // //     SDL_RenderPresent(renderer);
// // // }

// // void draw()
// // {
// //     SDL_SetRenderDrawColor(renderer, redColorCode, 20, 205, 255);
// //     SDL_RenderClear(renderer);

// //     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

// //     int cx = SCREEN_WIDTH / 2;
// //     int cy = SCREEN_HEIGHT / 2;

// //     // Increase radius over time
// //     radius += 1;

// //     // Collision check with window boundaries
// //     if (cx + radius >= SCREEN_WIDTH ||
// //         cx - radius <= 0 ||
// //         cy + radius >= SCREEN_HEIGHT ||
// //         cy - radius <= 0)
// //     {
// //         radius = 10; // reset
// //     }

// //     drawcircle(cx, cy, radius);

// //     SDL_RenderPresent(renderer);
// // }

// // void destroyWindow(void)
// // {
// //     SDL_DestroyRenderer(renderer);
// //     SDL_DestroyWindow(window);
// //     SDL_Quit();
// // }

// // int main(int argc, char **argv)
// // {
// //     // The game loop control variable
// //     gameIsRunning = initializeWindow();
// //     startTime = SDL_GetTicks();

// //     // Game loop: keep the application running until 'running' is set to false
// //     while (gameIsRunning)
// //     {
// //         // Continuously polls for SDL events
// //         process_input();

// //         // Draw the rendered window
// //         draw();
// //     }

// //     // Clean up and exit the application
// //     destroyWindow();

// //     return 0;
// // }
// // //  //g++ main.cpp -I"C:/Users/mdzak/OneDrive/Desktop/sdl/include" -L"C:/Users/mdzak/OneDrive/Desktop/sdl/lib" -lmingw32 -lSDL2main -lSDL2 -o main.exe ; ./main.exe
// #include <SDL2/SDL.h>
// #include <iostream>
// #include <cmath>

// using namespace std;
// // Defining  screen
// #define SCREEN_WIDTH 1000
// #define SCREEN_HEIGHT 600

// // Global varible use
// bool gameIsRunning = false; // To control program is running or not
// SDL_Window* window = NULL;  // Main window
// SDL_Renderer* renderer = NULL; // Drawing tool

// // Circle properties
// int centerX; // X coordinate of center of circle
// int centerY; // Y coordinate of center of circle
// int radius = 1000/5; // Radius of a cirle

// bool initializeWindow() // Window intialize Funtion and three type of working
// {
//     if (SDL_Init(SDL_INIT_VIDEO) < 0)   // Work 1: SDL starting to continue graphic system
//     {
//         cout << "SDL failed to initialize\n";
//         return false;
//     }

//     window = SDL_CreateWindow(
//         "Hello! this is my circle",      
//         SDL_WINDOWPOS_UNDEFINED,
//         SDL_WINDOWPOS_UNDEFINED,      //Work 2: Creat a window
//         SCREEN_WIDTH,
//         SCREEN_HEIGHT,
//         0);

//     if (!window)
//     {
//         cout << "Failed to open window\n";  
//         return false;
//     }

//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // work 3: creat a renderer
//     if (!renderer)
//     {
//         cout << "Failed to create renderer\n";
//         return false;
//     }

//     // Center of window
//     centerX = SCREEN_WIDTH / 2;
//     centerY = SCREEN_HEIGHT / 2;

//     return true;
// }

// void process_input()
// {
//     SDL_Event event;

//     while (SDL_PollEvent(&event))
//     {
//         switch (event.type)
//         {
//         case SDL_QUIT:
//             gameIsRunning = false;
//             break;

//         default:
//             break;
//         }
//     }
// }

// // Function to draw circle
// void drawCircle(int cx, int cy, int r)
// {
//     //scan squar area 
//  for(int i = -r; i<=r; i++){
//     for(int j = -r; j<=r; j++){
//         if( i*i + j*j <= r * r){
//             SDL_RenderDrawPoint(renderer, cx+i , cy + j);
//         }
//     }
//  }
// }

// void draw()
// {
//     // Background color Green
//     SDL_SetRenderDrawColor(renderer, 0, 103, 71,0);
//     SDL_RenderClear(renderer);

//     // Circle color Red
//     SDL_SetRenderDrawColor(renderer, 218, 41, 28, 0);

//     drawCircle(centerX, centerY, radius);

//     SDL_RenderPresent(renderer); // Slow screen
// }

// // Closing renderer drawing tool
// void destroyWindow()
// {
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();
// }

// int main(int argc, char* argv[])
// {
//     gameIsRunning = initializeWindow();

//     while (gameIsRunning)
//     {
//         process_input();
//         draw();
//     }

//     destroyWindow();

//     return 0;
// }

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