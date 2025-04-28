#include "entrypoint.h"
#include "raylib.h"
#include <time.h>
#include <vector>
#include <iostream>
#define MAX_COL 14
#define MAX_ROW 14
#define WIN_W MAX_COL * RECT_SIZE
#define WIN_H MAX_ROW * RECT_SIZE
#define RECT_SIZE 64

float deltaTime = GetFrameTime();

void L3_1(void){
    InitWindow(WIN_W, WIN_H, "Laboratroire 3.1");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawRectangle(270,550,350,350,CLITERAL(Color){230,41,55,255});
        DrawRectangle(310,610,100,100,CLITERAL(Color){0,41,255,255});
            DrawLine(
                413,655,
                310,657,
                CLITERAL(Color){230,41,55,255}
                );
                DrawLine(
                    357,600,
                    357,710,
                    CLITERAL(Color){230,41,55,255}
                );
        DrawRectangle(470,610,100,100,CLITERAL(Color){0,41,255,255});
            DrawLine(
                573,655,
                470,657,
                CLITERAL(Color){230,41,55,255}
                );
                DrawLine(
                    517,600,
                    517,710,
                    CLITERAL(Color){230,41,55,255}
                    );
        DrawRectangle(390,750,100,150,CLITERAL(Color){0,255,55,255});
        DrawCircle(10, 10, 100,CLITERAL (Color){ 253, 249, 0, 255});
        EndDrawing();
    }
    WindowShouldClose;
}
void L3_2(){
    float x = 10;
    float y = 10;
    float GetFrameTime(void);
    int GetKeyPressed(void);  
    InitWindow(WIN_W, WIN_H, "Laboratroire 3.2");
    while (!WindowShouldClose())
    {
        BeginDrawing();
            float deltaTime = GetFrameTime();
            if(IsKeyDown(KEY_DOWN)){y += 100 * deltaTime;} // lorsque l'utilisateur appuye sur la fleche du bas, le rectangle va vers le bas
            if(IsKeyDown(KEY_UP)){y -= 100 * deltaTime;} // lorsque l'utilisateur appuye sur la fleche du haut, le rectangle va vers le haut
            if(IsKeyDown(KEY_LEFT)){x -= 100 * deltaTime;} // lorsque l'utilisateur appuye sur la fleche de gauche, le rectangle va vers la gauche
            if(IsKeyDown(KEY_RIGHT)){x += 100 * deltaTime;} // lorsque l'utilisateur appuye sur la fleche de droite, le rectangle va vers la droite

            // lorsque le rectangle atteint les limites de l'ecran, il reapparait de l'autre cote 

            if(x < -100){
                x += WIN_W;
            }
            else if(x > WIN_W){
                x -= WIN_W;
            }
            if(y < -100){
                y += WIN_H;
            }
            else if(y > WIN_H){
                y -= WIN_H;
            }
            ClearBackground(WHITE);
            DrawRectangle(x,y,100,100,CLITERAL(Color){ 41, 55, 230, 255});

            //simule une partie du rectangle lorsque celui-ci depasse les limites de l'ecran 
            
            DrawRectangle(x + WIN_W,y,100,100,CLITERAL(Color){230, 41, 55, 255}); 
            DrawRectangle(x - WIN_W,y,100,100,CLITERAL(Color){230, 41, 55, 255});
            DrawRectangle(x,y + WIN_H,100,100,CLITERAL(Color){230, 41, 55, 255});
            DrawRectangle(x,y - WIN_H,100,100,CLITERAL(Color){230, 41, 55, 255});
            EndDrawing();
    }
}
                
           
void L3_3(){
    InitWindow(WIN_W, WIN_H, "Laboratroire 3.3");
    void SetTargetFPS(int fps);
    SetTargetFPS(60);
    float x = 10;
    float y = 10;
    float dx = GetRandomValue(-3, 3) * 100; // distance en x
    float dy = GetRandomValue(-3, 3) * 100; // distance en y
    while (!WindowShouldClose())
    {
        BeginDrawing();
            float deltaTime = GetFrameTime();
            x += dx * deltaTime; // calculer le deplacement a l'interieur de ce frame dans l'axe des x
            y += dy * deltaTime; // calculer le deplacement a l'interieur de ce frame dans l'axe des y

            // si la balle atteint les limites de l'ecran, il retourne dans la direction opposer

            if(x < 0 || x > WIN_W - 10){
                dx *= - 1;
            }

            if(y < 0 || y > WIN_H - 10){
                dy *= - 1;
            }
            ClearBackground(WHITE);
            DrawRectangle(x,y,10,10,CLITERAL(Color){230, 41, 55, 255});
            EndDrawing();
        }
}

void Updateball(float* x, float* y, float* dx, float* dy, float dt){
    *x += *dx * dt; // calculer le deplacement a l'interieur de ce frame dans l'axe des x
    *y += *dy * dt; // calculer le deplacement a l'interieur de ce frame dans l'axe des y
    if(*x < 0 || *x > WIN_W - 10){
        *dx *= - 1;
    }
    
    if(*y < 0 || *y > WIN_H - 10){
        *dy *= - 1;
    }
}
void Movepaddle(float* x, float speed, int width, float dt){
    if(IsKeyDown(KEY_LEFT)){*x -= speed * dt;} // lorsque l'utilisateur appuye sur la fleche de gauche, le rectangle va vers la gauche
    if(IsKeyDown(KEY_RIGHT)){*x += speed * dt;} // lorsque l'utilisateur appuye sur la fleche de droite, le rectangle va vers la droite
    if(*x < 0){
        *x = 0;
    }
    else if(*x > WIN_W - width){
        *x = WIN_W - width;
    }
}
class Paddle{
    public:
    float x,y,w,h;
    bool isTouchingBall;
};
class Brick{
    public:
    float x, y, w, h;
    bool IsActive;
};
void L4_1(){
    float paddle_w = 200;
    float paddle_h = 50;
    float ball_size = 10;
    float ball_dx = GetRandomValue(-3, 3) * 100;
    float ball_dy = 100;
    float ball_x = (WIN_W - ball_size)/2;
    float ball_y = (WIN_H - ball_size)/2;
    float brick_x = 0;
    float brick_y = 100;
    float brick_dx = 0;
    float brick_dy = 0;
    float brick_w = 110;
    float brick_h = 40;
    float paddle_speed = 200;
    float paddle_x = (WIN_W - paddle_w)/2;
    float paddle_y = WIN_H - paddle_h * 2;
    InitWindow(WIN_W, WIN_H, "Laboratroire 4.1");
    std::vector<Brick*> bricks_xy;
    float dx = 0;
    float dy = 0;
    for(int i = 0; i < 5;++i){ // structure de generation de briques dans l'axe des y
        for(int j = 0; j < 10;++j){ // structure de generation de briques dans l'axe des x
            Brick* new_brick_xy = new Brick();
            new_brick_xy->w = 110;
            new_brick_xy->h = 40;
            new_brick_xy->x = dx;
            new_brick_xy->y = dy;
            dx += new_brick_xy->w + 5; // creer un espace entre les briques
            new_brick_xy->IsActive = true;
            bricks_xy.push_back(new_brick_xy); 
        }
        dx = 0; // lorsqu'une rangee de 10 briques est remplie, passer a la rangee suivante
        dy += brick_h + 5; // creer un espace entre les rangees
    } 
    while (!WindowShouldClose()){
        float deltaTime = GetFrameTime();
        Updateball(&ball_x, &ball_y, &ball_dx, &ball_dy, deltaTime);
        Movepaddle(&paddle_x, paddle_speed, paddle_w, deltaTime);
        BeginDrawing(); 
        ClearBackground(WHITE);
        DrawRectangle(ball_x, ball_y, ball_size, ball_size, BLACK);
        DrawRectangle(paddle_x, paddle_y, paddle_w, paddle_h, GREEN);
        Rectangle rec1 = {ball_x, ball_y, ball_size, ball_size};
        for(int j = 0; j < bricks_xy.size();++j){ 
            Brick* temp_brick = bricks_xy[j];
            if(!temp_brick->IsActive){
                continue;
            }
            Rectangle rec3 = {temp_brick->x, temp_brick->y, temp_brick->w, temp_brick->h};
            bool IsTouchingBrick = CheckCollisionRecs(rec1, rec3); 
            if(IsTouchingBrick){
                temp_brick->IsActive= false;
                ball_dx = GetRandomValue(-3, 3) * 100;
                ball_dy *= -1;
            }
        }
        Rectangle rec2 = {paddle_x, paddle_y, paddle_w, paddle_h};
        bool IsTouchingBall = CheckCollisionRecs(rec1, rec2); 
        if(IsTouchingBall){
            ball_dx = GetRandomValue(-3, 3) * 100;
            ball_dy *= -1;
        }
        for(int j = 0; j < bricks_xy.size(); ++j){
            Brick* temp_brick = bricks_xy[j];
            if(!temp_brick->IsActive){
                continue;
            }
            DrawRectangle(temp_brick->x, temp_brick->y, temp_brick->w, temp_brick->h, DARKBLUE);
        }
        EndDrawing();
    }
}
void raylib_start(){
SetRandomSeed(time(NULL));
//decommenter pour le fonctionnement de chaque algorithme

//  L3_1();
//  L3_2();
//  L3_3();
//  L4_1();
}

            
            
            
            