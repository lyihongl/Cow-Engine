#include "../inc/ShapeComponent.hpp"

cow::ShapeComponent::ShapeComponent(int id, shape s, int w, int h) : Component(id, -1){
    this->w = w;
    this->h = h;
    this->s = s;
}

int cow::ShapeComponent::GetWidth() const {
    return w;
}

int cow::ShapeComponent::GetHeight() const {
    return h;
}

cow::shape cow::ShapeComponent::GetShape() const {
    return s;
}

int cow::ShapeComponent::GetParentId() const{
    return parentId;
}