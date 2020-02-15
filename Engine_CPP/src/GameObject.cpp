#include "../inc/GameObject.hpp"

cow::GameObject::GameObject(){
    id = -1;
}

cow::GameObject::GameObject(int id){
    this -> id = id;
}

cow::GameObject::GameObject(GameObject &g){
    this->id = g.id;
}

int cow::GameObject::GetId() const {
    return id;
}

void cow::GameObject::EnableComponent(cow::Components c){
    this->components | (1<<c);
}