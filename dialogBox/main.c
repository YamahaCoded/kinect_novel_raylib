#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_DIALOGUE_LENGTH 256
#define DIALOGUE_SPEED 0.018f

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Digitação RPG");

    char dialogue[MAX_DIALOGUE_LENGTH] = "Olá, eu sou um personagem de RPG!";
    int dialogueLength = strlen(dialogue);
    int currentLength = 0;
    float timer = 0;
    bool dialogueComplete = false;

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(TextSubtext(dialogue, 0, currentLength), 50, 50, 20, BLACK);
        if(!dialogueComplete){
            
            timer += GetFrameTime();
            if(timer >= DIALOGUE_SPEED && currentLength < dialogueLength){
                currentLength++;
                timer = 0;
            }

            if(currentLength == dialogueLength){
                dialogueComplete = true;
            }
        }else{
            DrawText("Pressione ENTER para continuar...", 50, 250, 20, BLACK);
            
            if(IsKeyPressed(KEY_ENTER)){
                //Do whatever you want
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
