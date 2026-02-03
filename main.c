#include "raylib.h"

typedef enum MainMenu{
  MAINSCREEN=0, GAMEPLAY
}MainMenu;

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;
  const char *title = "TETRIS BETA V0.1 by edutavr";
  int fontSize = 45; 

  InitWindow(screenWidth, screenHeight, "TETRIS BETA V0.1");

  MainMenu currentScreen = MAINSCREEN;
  
  SetTargetFPS(60);
  
  int textWidth = MeasureText(title, fontSize);
  int textWidth2 = MeasureText("Teste", 40);
  int centerCalc = (screenWidth - textWidth)/2; //Center title
  int centerPlay = (screenWidth - textWidth2)/2; //Center play button
  Color textColor = DARKPURPLE;
  Rectangle playButton = { centerPlay, 240, textWidth2, 40 };

  
  while (!WindowShouldClose()) {

    switch(currentScreen){
      
    case(MAINSCREEN):
      textColor = DARKPURPLE; //resets the main color when mouse is off
      Vector2 mousePoint = GetMousePosition();
      if (CheckCollisionPointRec(mousePoint, playButton)) {
	textColor = BLACK;
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
	      currentScreen = GAMEPLAY;
            }
      }
      BeginDrawing(); 
      ClearBackground(PURPLE);   
      DrawText(title, centerCalc, 20, fontSize, DARKPURPLE);
      DrawText("Teste", centerPlay , 240, 40, textColor);
      EndDrawing();
      break;
      
    case(GAMEPLAY):
      BeginDrawing(); 
      ClearBackground(BLACK);   
      DrawText("TELA DO JOGO", 20, 20, 20, WHITE);  
      EndDrawing();
      break;
    }
    
   
  }
  
  CloseWindow();
  return 0;
}
