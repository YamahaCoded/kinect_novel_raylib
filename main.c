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

struct initCharacter{
    Texture2D texture;
    Vector2 position;
    float rotation;
    float scale;
    Color color;
};

void setTextDefault(struct initText *dialogue){
    dialogue->dialogueLength = strlen(dialogue->dialogue);
    dialogue->currentLength = 0;
    dialogue->timer = 0;
    dialogue->dialogueComplete = false;
}

void setCharacterDefault(struct initCharacter *character, char filename[]){
    character->texture = LoadTexture(filename);
    character->color = WHITE;
    character->scale = 5.0f;
    character->position = (Vector2){ GetScreenWidth() / 2 - (character->texture.width * character->scale) / 2 + 160, GetScreenHeight() / 2 - (character->texture.height * character->scale) / 2 - 10};
    character->rotation = 0;
}

void updateDialogue(struct initText *dialogue){
    static int i = 0; 
    
    char dialogs[5][256] = {
        "hallo welt",
        "hello world",
        "ola mundo",
        "hola mundo",
        "konnichiha sekai"
    };

    strcpy(dialogue->dialogue, dialogs[i]);
    i++;

    if(i >= 5){
        i = 0;
    }
}

void drawDialogue(struct initText *dialogue){
    DrawText(TextSubtext(dialogue->dialogue, 0, dialogue->currentLength), 114, 412, 30, WHITE);

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
        DrawRectangle(662, 498, 28, 28, WHITE);
        
        if(IsKeyPressed(KEY_ENTER)){
            updateDialogue(dialogue);
            setTextDefault(dialogue);
        }
    }
}

void drawCharacter(struct initCharacter *character){
    DrawTextureEx(character->texture, character->position, character->rotation, character->scale, character->color);
}

void drawTextRectangle(Texture2D texture){
    DrawTextureEx(texture, (Vector2){(float)(GetScreenWidth()/2 - (640 / 2)), (float) (GetScreenHeight() - (160 + 50))}, 0, 5.0f, WHITE);
}

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "KN Test");

    struct initText d1;
    strcpy(d1.dialogue, "ehrm...\nthis is just another small test...\nhell yeah");
    setTextDefault(&d1);
    
    SetTargetFPS(60);
    
    struct initCharacter c1;
    setCharacterDefault(&c1, "./YaChan.png");
    
    Texture2D textBoxTexture = LoadTexture("./textRectangle.png");

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawCharacter(&c1);
        drawTextRectangle(textBoxTexture);
        drawDialogue(&d1);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}