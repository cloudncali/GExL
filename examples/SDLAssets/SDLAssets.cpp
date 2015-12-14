/**
* Provides a simple example showing case manipulation. 
*
* @file examples/Case/Case.cpp
* @author Jacob Dix
* @date 20151207 - Initial Release
*/
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <GExL/utils/StringUtil.hpp>
#include "TextureAsset.hpp"
#include "TextureHandler.hpp"
#include "FontHandler.hpp"

extern "C" { FILE __iob_func[3] = { *stdin,*stdout,*stderr }; }

//Primary asset class.
GExL::AssetManager gAssetManager;
SDL_Window* gWindow=NULL;
SDL_Renderer* gRenderer=NULL;
GExL::Uint32 gScreenWidth = 640;
GExL::Uint32 gScreenHeight = 480;
bool gRunning = false;
//Create window

GExL::Int32 init()
{
  gWindow = SDL_CreateWindow("GExL Asset Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gScreenWidth, gScreenHeight, SDL_WINDOW_SHOWN);
  if (gWindow == NULL)
  {
    FLOG(GExL::StatusAppInitFailed) << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    return GExL::StatusAppInitFailed;
  }
  //Create renderer for window
  gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
  if (gRenderer != NULL)
  {
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
      FLOG(GExL::StatusAppInitFailed) << "SDL_image could not be loaded! IMG_Error: " << IMG_GetError() << std::endl;
      return GExL::StatusAppInitFailed;
    }
    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
      FLOG(GExL::StatusAppInitFailed) << "SDL_ttf could not be loaded! TTF_Error: " << TTF_GetError() << std::endl;
      return GExL::StatusAppInitFailed;
    }
    //Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
      FLOG(GExL::StatusAppInitFailed) << "SDL_Mixer could not be loaded! Mix_Error: " << Mix_GetError() << std::endl;
      return GExL::StatusAppInitFailed;
    }
  }
  //Asset Handlers must be registerd prior to loading assets and only once per asset type.
  gAssetManager.RegisterHandler(new(std::nothrow) TextureHandler(gRenderer));
  gAssetManager.RegisterHandler(new(std::nothrow) FontHandler(16));


  return GExL::StatusAppOK;
}

int main(int argc, char** argv)
{
  GExL::Int32 anStatus = init();
  //If Init returned OK then start game loop. Otherwise exit program.
  if (anStatus == GExL::StatusAppOK)
  {
    gRunning = true;
  }
  //Load background texture. AssetLoadNow tells to begin loading imitately.
  TextureAsset anBackground(gAssetManager,"background.png",GExL::AssetLoadNow);

  while (gRunning)
  {
    SDL_Event anEvent;
    while(SDL_PollEvent(&anEvent))
    {
      //User requests quit
      if (anEvent.type == SDL_QUIT)
      {
        gRunning = false;
      }
    }
    SDL_RenderClear(gRenderer);
    anBackground.GetAsset().Render();
    SDL_RenderPresent(gRenderer);
  }
  return anStatus;
}