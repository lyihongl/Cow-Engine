#include "../inc/PositionComponent.hpp"

cow::PositionComponent::PositionComponent() {}
cow::PositionComponent::PositionComponent(int parentId) {
    this->parentId = parentId;
}
cow::PositionComponent::PositionComponent(int parentId, int x, int y) {
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

int cow::PositionComponent::GetParentId() const {
    return parentId;
}