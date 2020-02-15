#include <SDL2\SDL.h>
#include <iostream>
#include "../inc/Engine.hpp"
#include "../inc/GameData.hpp"
#include "../inc/Input.hpp"

int main(int argc, char** argv) {
    cow::StartGame();
    return 0;
}

void cow::Tick(GameData& p_gd) {
    //KeyDownEvent(p_gd, keyArray);
    int speed = 5;
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    //std::cout << p_gd.P_getEntityManager()->Positions[0].GetX() << " " << p_gd.P_getEntityManager()->Positions[0].GetY()<<std::endl;
    int xPos = p_gd.P_getEntityManager()->Positions[0].GetX();
    int yPos = p_gd.P_getEntityManager()->Positions[0].GetY();
    if(keystate[SDL_SCANCODE_W]){
        if(yPos > 0)
            p_gd.P_getEntityManager()->Positions[0].RelativeY(-1*speed);
    }
    if(keystate[SDL_SCANCODE_A]){
        if(xPos > 0)
            p_gd.P_getEntityManager()->Positions[0].RelativeX(-1*speed);
    }
    if(keystate[SDL_SCANCODE_S]){
        if(yPos < p_gd.GetH() - p_gd.P_getEntityManager()->Shapes[0].GetHeight())
            p_gd.P_getEntityManager()->Positions[0].RelativeY(speed);
    }
    if(keystate[SDL_SCANCODE_D]){
        if(xPos < p_gd.GetW() - p_gd.P_getEntityManager()->Shapes[0].GetWidth())
            p_gd.P_getEntityManager()->Positions[0].RelativeX(speed);
    }
}

void cow::Render(GameData& p_gd) {
    p_gd.P_getRenderEngine()->RenderShape(p_gd.P_getEntityManager()->Positions, p_gd.P_getEntityManager()->Shapes);
}

void cow::Init(GameData& p_gd){
    cow::ShapeComponent s{0, cow::rect, 20, 20};
    cow::PositionComponent p{0, 100, 100};
    p_gd.P_getEntityManager()->AddShape(s);
    p_gd.P_getEntityManager()->AddPosition(p);
}