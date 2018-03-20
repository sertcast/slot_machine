//
//  Shape.cpp
//  slot_machine
//
//  Created by Mert Kaya on 2017-11-23.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "Shape.hpp"
Shape::Shape(Uint32 color, int xPos, int yPos, int w, int h){
    this->image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    SDL_FillRect(this->image, NULL, color);
    this->rect = this->image->clip_rect;
    this->height = h;
    this->width = w;
    this->origin_x = this->width/2;
    this->origin_y = this->height/2;
    this->rect.x = xPos + this->origin_x;
    this->rect.y = yPos + this->origin_y;
}
void Shape::draw(SDL_Surface *destination){
    SDL_BlitSurface(this->image, NULL, destination, &this->rect);
}
SDL_Surface *Shape::get_image(){
    return this->image;
}
void Shape::set_image(const char filename[] = NULL){
    if(filename != NULL){
        SDL_Surface *loaded_image = NULL;
        loaded_image = IMG_Load(filename);
        if(loaded_image != NULL){
            this->image = loaded_image;
            int old_x = rect.x;
            int old_y = rect.y;
            this->rect = this->image->clip_rect;
            
            this->rect.x = old_x;
            this->rect.y = old_y;
        }
    }
}
void Shape::set_rect_x(int x){
    this->rect.x = x;
}
void Shape::set_rect_y(int y){
    this->rect.y = y;
}
int Shape::get_rect_x(void){
    return this->rect.x;
}
int Shape::get_rect_y(void){
    return this->rect.y;
}
