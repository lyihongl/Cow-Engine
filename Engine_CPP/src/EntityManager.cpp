#include "../inc/EntityManager.hpp"

cow::EntityManager::EntityManager() {}

void cow::EntityManager::AddShape(ShapeComponent &s){
    auto it = Shapes.begin();
    for(;it != Shapes.end() && it->GetParentId() < s.GetParentId(); it++);
    Shapes.insert(it, s);
}

void cow::EntityManager::AddPosition(PositionComponent &p){
    auto it = Positions.begin();
    for(;it != Positions.end() && it->GetParentId() < p.GetParentId(); it++);
    Positions.insert(it, p);
}