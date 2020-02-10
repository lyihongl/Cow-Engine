#include "../inc/PositionComponent.hpp"

cow::PositionComponent::PositionComponent() {}
cow::PositionComponent::PositionComponent(int parentId) {
    this->parentId = parentId;
}

int cow::PositionComponent::GetX() const {
    return x;
}

int cow::PositionComponent::GetY() const {
    return y;
}