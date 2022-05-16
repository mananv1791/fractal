#include<SDL2/SDL.h>
//#include <src/include/SDL.h>
#include <iostream>
#include <vector>


using namespace std;

vector<float> lines;
vector<float> temp;
vector<vector<float>> tempo;
vector<float> point;

void fractals(SDL_Renderer *dest, float x1, float y1, float x2, float y2){

    float dy = y2-y1;
    float dx = x2-x1;

    float ypart4 = dy/4;
    float xpart4 = dx/4;

    point = { x1+xpart4, y1+ypart4 };
    tempo.push_back({point});
    point.clear();
    point = { x1+(2*xpart4), y1+(2*ypart4) };
    tempo.push_back({point});
    point = { x1+(3*xpart4), y1+(3*ypart4) };
    tempo.push_back({point});
    point = { x1+(4*xpart4), y1+(4*ypart4) };
    tempo.push_back({point});

}

int main(int argv, char** args)
{ 
    SDL_Init(SDL_INIT_EVERYTHING);  

    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    bool isRunning = true;
    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
            }
        }
        
        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_SetRenderDrawColor(renderer, 0, 255, 168, 255);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, 10,10,50,50);

        vector<vector<float>>::iterator i;
        vector<float>::iterator j;

        for (auto &i: tempo) {
            for (auto &j: i) {
                SDL_RenderDrawLine(renderer,  )
            }
        }
        

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}