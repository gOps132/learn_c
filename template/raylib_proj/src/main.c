#include <stdio.h>
#include <raylib.h>

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   450

typedef struct rect_t {
    int x, y;
    int w, h;
} rect_t;

int main(){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "basic window");
    int toggle = 0;
    
    rect_t rect = { 0, 100, 100, 100 };

    int velocityX = 100;

    SetTargetFPS(24);

    while(!WindowShouldClose())
    {
        if (rect.x >=  WINDOW_WIDTH-rect.w)
            velocityX = -100;
        else if (rect.x <= 0)
            velocityX = 100;
             
        rect.x += GetFrameTime() * velocityX;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(rect.x,rect.y,rect.w,rect.h, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
