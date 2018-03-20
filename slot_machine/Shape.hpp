//
//  Shape.hpp
//  slot_machine
//
//  Created by Mert Kaya on 2017-11-23.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Shape{
protected:
    SDL_Surface *image;
    SDL_Rect rect;
    int origin_x, origin_y, width, height;
    
public:
    Shape(Uint32 color, int xPos, int yPos, int w, int h);
    void draw(SDL_Surface *destination);
    void set_image(const char filename[]);
    SDL_Surface *get_image();
    void set_rect_x(int x);
    void set_rect_y(int y);
    int get_rect_x(void);
    int get_rect_y(void);
};
#endif /* Shape_hpp */
