#include "../inc/PositionComponent.hpp"

cow::PositionComponent::PositionComponent(int id) : Component(id, -1, ECompType::Position){

}
cow::PositionComponent::PositionComponent(int id, int x, int y) : Component(id, -1, ECompType::Position){
    this->parentId = parentId;
    this->x = x;
    this->y = y;
}

int cow::PositionComponent::GetX() const {
    return x;
}

int cow::PositionComponent::GetY() const {
    return y;
}

void cow::PositionComponent::RelativeX(int x){
    this->x+=x;
}

void cow::PositionComponent::RelativeY(int y){
    this->y+=y;
}