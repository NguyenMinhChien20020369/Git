#ifndef baseOfjectH
#define baseOfjectH

#include "commonFuntion.h"

struct BaseObject
{
    SDL_Texture* p_object_;
    SDL_Rect rect_;

    BaseObject();

    void SetRect(const int& x, const int& y)
    {
        rect_.x=x, rect_.y=y;
    }

    SDL_Rect GetRect() const
    {
        return rect_;
    }
    SDL_Texture* GetObject() const
    {
        return p_object_;
    }

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip=NULL);
};

#endif // baseOfjectH
