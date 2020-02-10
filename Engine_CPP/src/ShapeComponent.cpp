#include "../inc/ShapeComponent.hpp"

cow::ShapeComponent::ShapeComponent(int parentId, shape s, int w, int h) {
    this->w = w;
    this->h = h;
    this->s = s;
    this->parentId = parentId;
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