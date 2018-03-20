//
//  main.cpp
//  slot_machine
//
//  Created by Mert Kaya on 2017-11-23.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Shape.hpp"
#include "Slot.hpp"

#define fps 60
#define WIDTH 1000
#define HEIGHT 600

void cap_framerate(Uint32 ticks){
    if((1000/fps) > SDL_GetTicks() - ticks){
        SDL_Delay((1000/fps)-(SDL_GetTicks() - ticks));
    }
}

int main(int argc, const char * argv[]) {
    bool running = true;
    bool turning = true;
    SDL_Event event;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = NULL;
    window = SDL_CreateWindow("SLOT MACHINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    
    SDL_Surface *screen = SDL_GetWindowSurface(window);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    
    Shape circle(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    circle.set_image("/Users/mert/Desktop/images_for_program/ellipse.png");
    Shape triangle(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    triangle.set_image("/Users/mert/Desktop/images_for_program/triangle.png");
    Shape rectangle(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    rectangle.set_image("/Users/mert/Desktop/images_for_program/rect.png");
    
    Shape circle1(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    circle1.set_image("/Users/mert/Desktop/images_for_program/ellipse.png");
    Shape triangle1(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    triangle1.set_image("/Users/mert/Desktop/images_for_program/triangle.png");
    Shape rectangle1(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    rectangle1.set_image("/Users/mert/Desktop/images_for_program/rect.png");
    
    Shape circle2(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    circle2.set_image("/Users/mert/Desktop/images_for_program/ellipse.png");
    Shape triangle2(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    triangle2.set_image("/Users/mert/Desktop/images_for_program/triangle.png");
    Shape rectangle2(SDL_MapRGB(screen->format, 255, 255, 255), 0, 0, 0, 0);
    rectangle2.set_image("/Users/mert/Desktop/images_for_program/rect.png");
    
    Shape first_slot[] = {
        circle,
        triangle,
        rectangle
    };
    Shape second_slot[] = {
        circle1,
        triangle1,
        rectangle1
    };
    Shape third_slot[] = {
        circle2,
        triangle2,
        rectangle2
    };
    Slot the_slot;
    the_slot.add(&circle);
    the_slot.add(&triangle);
    the_slot.add(&rectangle);
    

    int ran1,i,z = 25;
    Uint32 delay = 100;
    
    Uint32 starting_tick;
    while(running){
        starting_tick = SDL_GetTicks();
        
        while(SDL_PollEvent(&event)){
            if(event.type ==SDL_QUIT){
                running = false;
                break;
            }
        }
        while(turning){
            if(delay == 900){
                turning = false;
            }
            for(i = 0; i < z; i++){
                ran1 = rand()%3;
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                the_slot.change_slot(0, &(first_slot[ran1]));
                ran1 = rand()%3;
                the_slot.change_slot(1, &(second_slot[ran1]));
                ran1 = rand()%3;
                the_slot.change_slot(2, &(third_slot[ran1]));
                the_slot.draw(screen);
                SDL_UpdateWindowSurface(window);
                SDL_Delay(delay);
            }
            delay+=400;
            z-=15;
        }
        cap_framerate(starting_tick);
        
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
