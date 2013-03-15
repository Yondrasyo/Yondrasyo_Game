/*

*/

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include <iostream>
#include <string>




using namespace std;

bool Init ()
{

	if (SDL_Init (SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	SDL_WM_SetCaption("yondrasyo",NULL);

	return true;
}



int main (int argc ,char* args[])
{
	Init();	

        SDL_Surface *screen;
        screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
//      screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_FULLSCREEN);
        bool running = true;
        const int FPS = 30;
        Uint32 start;
        while(running) {
                start = SDL_GetTicks();
                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = false;
                                        break;
                        }
                }
                //logic && render
 
 
                SDL_Flip(screen);
 
                if(1000/FPS > SDL_GetTicks()-start) {
                        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                }
        }
        SDL_Quit();
        return 0;

	}
  