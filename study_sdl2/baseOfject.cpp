#include "baseOfject.h"

BaseObject::BaseObject()
{
    p_object_=NULL;
    rect_.x=0;
    rect_.y=0;
    rect_.w=0;
    rect_.h=0;
}

bool BaseObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;

    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if(load_surface!= NULL)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format,COLOR_KEY_R, COLOR_KEY_G,COLOR_KEY_B));
        new_texture =SDL_CreateTextureFromSurface(screen, load_surface);
    }
}
