#ifndef ENEMY7_H
#define ENEMY7_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"
#include "Player.h"
#include "Bala.h"

using namespace std;
class Enemy7 : public Enemy
{
    public:
        Enemy7(SDL_Surface *screen, Player *player);
                Player *player;

        SDL_Surface *images[6];
        void logic(vector<Bala*>bullets);
        void render();
        void jump();
        int getx();
        int gety();
        int getvida();
        bool checkCollision();
        virtual ~Enemy7();
    protected:
    private:
};

#endif // ENEMY7_H
