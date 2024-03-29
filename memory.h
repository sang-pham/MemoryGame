#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

const int MEMORY_CELL_SIZE = 50;   // kich thuoc anh goc
const int MEMORY_CELL_TIME = 20;   // kich thuoc thanh thoi gian
const int WINDOW_CELL_SIZE = 50;   // kich thuoc khi hien thi cua 1 o
const int DEFAULT_NUM_ROWS = 6;    // so luong o theo chieu ngang
const int DEFAULT_NUM_COLS = 6;    // so luong o theo chieu doc

const string SCREEN_TITLE = "MEMORY";   // Tieu de cua so
const string MEMORY_PATH = "image.jpg";
const string WIN = "win.jpg";
const string LOST = "lost.jpg";
Mix_Chunk* mix_click;
Mix_Chunk* mix_game;
//-------------------------------------------------//

int Pos[36], Time = -1, click = 0, NowAction[36], PreviousValue = 0, Opened[36], dem = 0;

struct Graphic
{
    SDL_Window* window;                 // Cua so hien thi
    SDL_Texture* MemoryTexture;         // Anh load dc tu file anh
    vector<SDL_Rect> MemoryRects;       // Vi tri cac hinh trong file anh
    SDL_Renderer* renderer;             // Load anh len man hinh
};

//------------------------------------------------------//



bool initGraphic(Graphic& g, int nRows, int nCols);


void finalizeGraphic(Graphic& g);


SDL_Texture* createTexture(SDL_Renderer* renderer, const string& path);


void initMemoryRects(vector<SDL_Rect>& rects);


void random(int nRows, int nCols);


void initGame(Graphic& g, int nRows, int nCols);


void update(Graphic& g, int time, int NumberOfClick, int value , int PreviousValue);


void ClickAction(SDL_Event& event, Graphic& raphic);


void err(const string& msg);

#endif // MEMORY_H_INCLUDED
