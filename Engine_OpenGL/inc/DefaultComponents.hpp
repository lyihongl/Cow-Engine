#pragma once

#include "Storage.hpp"

namespace Cow {
struct Position2D : public Component {
    Position2D(float x, float y) {
        this->x = x;
        this->y = y;
    };
    float x, y;
};

struct Physics2D : public Component {
    double mass;
    double velocity[2];
    double acceleration[2];
};

struct Hitbox2D : public Component {
};

struct Animation2D : public Component {
};

void InitDefault2D(ComponentManager& c) {
    c.Register<Position2D>();
    c.Register<Physics2D>();
    c.Register<Hitbox2D>();
    c.Register<Animation2D>();
}

};  // namespace Cow