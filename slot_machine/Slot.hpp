//
//  Slot.hpp
//  slot_machine
//
//  Created by Mert Kaya on 2017-11-24.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#ifndef Slot_hpp
#define Slot_hpp

#include <stdio.h>
#include "Shape.hpp"
struct sshape{
    sshape *next,*prev;
    Shape *current;
};
class Slot{
public:
    Slot();
    void add(Shape *the_shape);
    void draw(SDL_Surface *destination);
    Shape pop(void);
    int get_size(void);
    void change_slot(int num, Shape *nshape);
    sshape *end_shape(void);
private:
    sshape *shapes;
    int shape_count;
};
#endif /* Slot_hpp */
