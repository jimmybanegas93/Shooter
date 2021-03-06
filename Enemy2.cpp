#include "Enemy2.h"

Enemy2::Enemy2(SDL_Surface *screen, Player *player)
{
    this->player=player;
    this->screen = screen;
    this->images[0] = IMG_Load( "enemy/bandit-interceptor1.png" );
    this->images[1] = IMG_Load( "enemy/bandit-interceptor2.png" );
    this->x = 800;
    this->y = 100;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    this->vida=30;
    //ctor
}

Enemy2::~Enemy2()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );

}

void Enemy2::logic(vector<Bala*>bullets, SDL_Surface *screen, Player *player)
{
   for(int x=0;x<bullets.size();x++)
   {
     if((((bullets[x]->getx()>= this->getx())&& (bullets[x]->getx()<= this->getx()+10)) ||
        ((bullets[x]->getx()+10 >= this->getx())&& (bullets[x]->getx()+10 <= this->getx()+10))) &&
        (((bullets[x]->gety() >= this->gety()) && (bullets[x]->gety() <= this->gety()+20)) ||
        ((bullets[x]->gety()+20 >= this->gety()) && (bullets[x]->gety()+20 <= this->gety()+20))))
    {
      this->vida-=5;
      player->score+=5;
    }
   }

   for(int x=0;x<this->bullets.size();x++)
   {
     if((((this->bullets[x]->getx()>= player->getx())&& (this->bullets[x]->getx()<= player->getx()+10)) ||
        ((this->bullets[x]->getx()+10 >= player->getx())&& (this->bullets[x]->getx()+10 <= player->getx()+10))) &&
        (((this->bullets[x]->gety() >= player->gety()) && (this->bullets[x]->gety() <= player->gety()+20)) ||
        ((this->bullets[x]->gety()+20 >= player->gety()) && (this->bullets[x]->gety()+20 <= player->gety()+20))))
    {
      player->vida-=0.5;
    }
   }

    x-=6;
    if(x<-100)
        x=1000;

    disparar(screen);

}

void Enemy2::jump()
{
    velocity=-30;
}


int Enemy2::getx()
{
   return this->x;
}

int Enemy2::getvida()
{
    return this->vida;
}


int Enemy2::gety()
{
    return this->y;
}

void Enemy2::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    if(vida>0)
    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>1)
        current_frame=0;
}

bool Enemy2::checkCollision()
{
 if(
    (((player->getx()>= this->getx())&& (player->getx()<= this->getx()+10)) ||
    ((player->getx()+10 >= this->getx())&& (player->getx()+10 <= this->getx()+10))) &&
    (((player->gety() >= this->gety()) && (player->gety() <= this->gety()+20)) ||
    ((player->gety()+20 >= this->gety()) && (player->gety()+20 <= this->gety()+20))))
  {
   return true;
  }

  return false;
}

void Enemy2::disparar(SDL_Surface * screen)
{
   for(int i=0;i<bullets.size();i++){
    bullets[i]->draw(screen,bullets[i]->x,bullets[i]->y);
    bullets[i]->x-=50;
    bullets[i]->y+=10;
   }
}
