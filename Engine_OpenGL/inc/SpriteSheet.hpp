#pragma once

#include <stdint.h>
#include <vector>




namespace CowGraphics {
    //stores sprite sheet
    //SpriteData stores data in the following format: xPos|yPos|width|height| repeat
    struct SpriteSheet{
        unsigned char* Data;
        uint32_t Width, Height;
        std::vector<uint16_t> SpriteData;
    };
    std::size_t EmplaceSprite(SpriteSheet* sheet, uint16_t xPos, uint16_t yPos, uint16_t width, uint16_t height){
        sheet->SpriteData.push_back(xPos);
        sheet->SpriteData.push_back(yPos);
        sheet->SpriteData.push_back(width);
        sheet->SpriteData.push_back(height);
    }
};