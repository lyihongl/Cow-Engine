#include "../inc/PositionComponent.hpp"

cow::PositionComponent::PositionComponent() {}
cow::PositionComponent::PositionComponent(int parentId) {
    this->parentId = parentId;
}