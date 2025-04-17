#include "entrypoint.h"
#include "raylib.h"
#define MAX_COL 14
#define MAX_ROW 14
#define WIN_W MAX_COL * RECT_SIZE
#define WIN_H MAX_ROW * RECT_SIZE
#define RECT_SIZE 64

float deltaTime = GetFrameTime();

void raylib_start1(void){
    InitWindow(WIN_W, WIN_H, "Laboratroire 3");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(380,380,100,100,CLITERAL(Color){230,41,55,255});
        DrawCircle(10, 10, 100,CLITERAL (Color){230, 41, 55, 255});
        EndDrawing();
    }
    WindowShouldClose;
}
void raylib_start2(){
    float x = 10;
    InitWindow(WIN_W, WIN_H, "Laboratroire 3");
        while (!WindowShouldClose())
        {
            if(IsKeyDown(KEY_SPACE)){x += 100 * deltaTime;}
            BeginDrawing();
            ClearBackground(WHITE);
            DrawRectangle(10,10,100,100,CLITERAL(Color){230, 41, 55, 255});
            EndDrawing();
        }
        WindowShouldClose;
}
void raylib_start3(){
    float x = 10;
    InitWindow(WIN_W, WIN_H, "Laboratroire 3");
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(WHITE);
            DrawRectangle(10,10,100,100,CLITERAL(Color){230, 41, 55, 255});
            EndDrawing();
        }
        WindowShouldClose;
}
void raylib_start(){

//decommenter pour le fonctionnement de chaque algorithme

raylib_start1();
//  raylib_start2();
//  raylib_start3();
}