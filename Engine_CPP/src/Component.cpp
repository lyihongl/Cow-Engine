#include "../inc/Component.hpp"

cow::Component::Component(int id, int parentId){
    this->id = id;
    this->parentId = parentId;
}

int cow::Component::GetParentId() const{
    return parentId;
}

int cow::Component::GetId() const {
    return id;
}

void cow::Component::SetParentId(int id){
    parentId = id;
}