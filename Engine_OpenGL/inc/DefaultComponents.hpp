#pragma once

#include "Storage.hpp"

namespace Cow {
struct Position2D : public Component {
    float x, y;
};

struct Phsyics2D : public Component {
    double mass;
    double velocity[2];
    double acceleration[2];
};

struct Hitbox2D : public Component {

};

struct Animation2D : public Component {

};
};  // namespace Cow