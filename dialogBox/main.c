#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_DIALOGUE_LENGTH 256
#define DIALOGUE_SPEED 0.018f

struct initText{
    char dialogue[MAX_DIALOGUE_LENGTH];
    int dialogueLength;
    int currentLength;
    float timer;
    bool dialogueComplete;
};

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RPG");

    struct initText d1;
    strcpy(d1.dialogue, "This is a boring test...");
    d1.dialogueLength = strlen(d1.dialogue);
    d1.currentLength = 0;
    d1.timer = 0;
    d1.dialogueComplete = false;
    
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(TextSubtext(d1.dialogue, 0, d1.currentLength), 50, 50, 20, BLACK);
        if(!d1.dialogueComplete){
            
            d1.timer += GetFrameTime();
            if(d1.timer >= DIALOGUE_SPEED && d1.currentLength < d1.dialogueLength){
                d1.currentLength++;
                d1.timer = 0;
            }

            if(d1.currentLength == d1.dialogueLength){
                d1.dialogueComplete = true;
            }
        }else{
            DrawText("Press enter or whatever...", 50, 250, 20, BLACK);
            
            if(IsKeyPressed(KEY_ENTER)){
                //Do whatever you want
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
