#include <raylib.h>
#include "analog-clock.hpp"


int main() 
{
    // Constants
    const int WINDOW_WIDTH = 400;
    const int WINDOW_HEIGHT = 400;
    const int TARGET_FPS = 60;

    // Initialize window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Analog Clock");
    SetWindowPosition(GetMonitorWidth(0)/2 - GetScreenWidth()/2, GetMonitorHeight(0)/2 - GetScreenHeight()/2);
    SetTargetFPS(TARGET_FPS);

    // Variables
    AnalogClock clock {150, {200, 200}};


    // Main loop
    while(WindowShouldClose() == false)
    {
        // Core Game loop
        clock.Update();

        // Rendering
        BeginDrawing();
            ClearBackground(SKYBLUE);
            clock.Draw();
        EndDrawing();
    }


    // End Game 
    CloseWindow();
    return 0;
}