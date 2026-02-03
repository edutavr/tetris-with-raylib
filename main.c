#include "raylib.h"

typedef enum MainMenu{
  MAINSCREEN = 0, GAMEPLAY, SETTINGS
}MainMenu;

typedef enum ThemeOptions{
  PURPLE_THEME,RED_THEME, GREEN_THEME,BLUE_THEME, YELLOW_THEME, ORANGE_THEME, THEME_COUNT
}ThemeOptions;

typedef struct ThemeColors{
  Color background;
  Color text;
  Color highlight;
  const char *name;
}ThemeColors;

static const ThemeColors Themes[THEME_COUNT] = {
  [PURPLE_THEME]={PURPLE, DARKPURPLE, BLACK, "Purple"},
  [RED_THEME]={RED, MAROON, RAYWHITE, "Red"},
  [GREEN_THEME]={GREEN, DARKGREEN, LIME, "Green"},
  [BLUE_THEME]={BLUE, DARKBLUE, SKYBLUE, "Blue"},
  [YELLOW_THEME]={YELLOW, GOLD, (Color){111,118,17,255}, "Yellow"},
  [ORANGE_THEME]={ORANGE, (Color){230,76,20,255},(Color){168,63,24,255} , "Orange"},
};

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;
  const char *title = "TETRIS BETA V0.1 by edutavr";
  int fontSize = 45; 

  InitWindow(screenWidth, screenHeight, "TETRIS BETA V0.1");

  MainMenu currentScreen = MAINSCREEN;
  
  ThemeOptions currentTheme = PURPLE_THEME;
  
  SetTargetFPS(60);
  
  int textWidth = MeasureText(title, fontSize);
  int textWidth2 = MeasureText("Play Game", 40);
  int textWidth3 = MeasureText("Settings", 40);

  
  int centerTitle = (screenWidth - textWidth)/2;
  int centerPlay = (screenWidth - textWidth2)/2;
  int centerSettings = (screenWidth - textWidth3)/2;


  Rectangle playButton = { centerPlay, 240, textWidth2, 40 };
  Rectangle settingsButton = { centerSettings, 300, textWidth3, 40 };

  
  while (!WindowShouldClose()) {

    Color bgColor = Themes[currentTheme].background;
    Color textBase = Themes[currentTheme].text;
    Color highlight = Themes[currentTheme].highlight;

    switch(currentScreen){
    //menu-----------------------------------------------------------  
    case(MAINSCREEN):
      const char *themeLabel = TextFormat("Theme: %s", Themes[currentTheme].name);
      int textWidth4 = MeasureText(themeLabel, 20);
      Rectangle themeButton = {centerPlay+25, 550, textWidth4, 20};
      
      Vector2 mousePoint = GetMousePosition();
      Color titleColor = textBase;
      Color playColor = textBase;
      Color settingsColor = textBase;
      Color themeColor = textBase;
      
      if (CheckCollisionPointRec(mousePoint, playButton)) {
	playColor = highlight;
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
	  currentScreen = GAMEPLAY;
	}
      }
      if (CheckCollisionPointRec(mousePoint, settingsButton)) {
	settingsColor = highlight;
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
	  currentScreen = SETTINGS;
	}
      }
      if (CheckCollisionPointRec(mousePoint, themeButton)) {
	//settingsColor = highlight;
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
	  currentTheme = (ThemeOptions)((currentTheme + 1) % THEME_COUNT);
	}
      }
       
      BeginDrawing(); 
      ClearBackground(bgColor);   
      DrawText(title, centerTitle, 20, fontSize, titleColor);
      DrawText("Play Game", centerPlay , 240, 40, playColor);
      DrawText("Settings", centerSettings , 300, 40, settingsColor);
      DrawText(themeLabel, centerPlay + 25 , 550, 20, themeColor);
      EndDrawing();
      break;
      
    case(GAMEPLAY):
      BeginDrawing(); 
      ClearBackground(BLACK);   
      DrawText("TELA DO JOGO", 20, 20, 20, WHITE);  
      EndDrawing();
      break;

    case(SETTINGS):
      BeginDrawing();
      ClearBackground(bgColor);
      DrawText("SETTINGS", 20, 20, 40, DARKPURPLE);
      EndDrawing();
      break;      
    }
    //menu----------------------------------------------------------- 
   
  }
  
  CloseWindow();
  return 0;
}
