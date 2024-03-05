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

void setDefault(struct initText *dialogue){
    dialogue->dialogueLength = strlen(dialogue->dialogue);
    dialogue->currentLength = 0;
    dialogue->timer = 0;
    dialogue->dialogueComplete = false;
}

void drawDialogue(struct initText *dialogue){
    DrawText(TextSubtext(dialogue->dialogue, 0, dialogue->currentLength), 50, 300, 20, BLACK);
    if(!dialogue->dialogueComplete){
        
        dialogue->timer += GetFrameTime();
        if(dialogue->timer >= DIALOGUE_SPEED && dialogue->currentLength < dialogue->dialogueLength){
            dialogue->currentLength++;
            dialogue->timer = 0;
        }

        if(dialogue->currentLength == dialogue->dialogueLength){
            dialogue->dialogueComplete = true;
        }
    }else{
        DrawText("Press enter or whatever...", 500, 400, 20, BLACK);
        
        if(IsKeyPressed(KEY_ENTER)){
            setDefault(dialogue);
        }
    }
}

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RPG");

    struct initText d1;
    strcpy(d1.dialogue, "This is a boring test...");
    setDefault(&d1);
    
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawDialogue(&d1);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
