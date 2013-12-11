#ifndef ENEMY7_H
#define ENEMY7_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"

class Enemy7 : public Enemy
{
    public:
        Enemy7(SDL_Surface *screen);
        SDL_Surface *images[6];
        void logic();
        void render();
        void jump();
        virtual ~Enemy7();
    protected:
    private:
};

#endif // ENEMY7_H