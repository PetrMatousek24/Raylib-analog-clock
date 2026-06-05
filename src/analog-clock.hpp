#pragma once
#include <raylib.h>
#include <ctime>


// Colors
Color darkGrey = {45, 45, 45, 255};
Color lightGrey = {229, 229, 229, 255};


class AnalogClock {
private:
    int size;
    Vector2 position;
    int hour, minute, second;

    void DrawFace() {
        DrawBG();
        DrawHourMarks();
    }


    // Construct the static
    void DrawBG() {
        DrawCircleV(position, size, darkGrey);
        DrawCircleV(position, size - 15, lightGrey);
        DrawCircleV(position, size - 25, WHITE);
    }

    void DrawHourMarks() {
        for(int i = 0; i < 12; i++) {
            DrawHand(5.0, size, i*30, darkGrey);
        }
        DrawCircleV(position, size - 40, WHITE);
    }

    void DrawCenterDot() {
        DrawCircleV(position, 8, darkGrey);
    }


    // Helpers
    void DrawHand(float handWidth, float handLength, int angle, Color color, int offset = 0) {
        Rectangle handRect = Rectangle{position.x, position.y, handWidth, handLength};
        DrawRectanglePro(handRect, {handWidth/2, handLength - offset}, angle, color);
    }


    // Clock hands
    void DrawHourHand(int hour, int minute) {
        int angle = 30 * hour + (minute / 60.0) * 30;
        DrawHand(8.0, size * 0.6, angle, darkGrey, 0);
    }

    void DrawMinuteHand(int minute) {
        DrawHand(5.0, size*0.7, minute*6, darkGrey);
    }

    void DrawSecondHand(int second) {
        int offset = 40;
        DrawHand(3.0, size*1.05, second*6, RED, offset);
    }

public:
    AnalogClock(int size, Vector2 position) :size(size), position(position), hour(0), minute(0), second(0) {};

    void Draw() {
        DrawFace();
        
        DrawMinuteHand(minute);
        DrawHourHand(hour, minute);
        DrawSecondHand(second);

        DrawCenterDot();
    }

    void Update() {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);

        hour = now -> tm_hour % 12;
        minute = now -> tm_min;
        second = now -> tm_sec;
    }
};