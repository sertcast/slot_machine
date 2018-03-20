//
//  Slot.cpp
//  slot_machine
//
//  Created by Mert Kaya on 2017-11-24.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "Slot.hpp"
Slot::Slot(){
    this->shape_count = 0;
    this->shapes = (sshape*)malloc(sizeof(sshape));
    this->shapes->current = NULL;
    this->shapes->next = NULL;
    this->shapes->prev = NULL;
}
int Slot::get_size(){
    return this->shape_count;
}
void Slot::add(Shape *the_shape){
    sshape *tcurrent = this->end_shape();
    if(tcurrent->current != NULL){
        the_shape->set_rect_x(tcurrent->current->get_rect_x() + 250);
        sshape *new_shape = (sshape*)malloc(sizeof(sshape));
        tcurrent->next = new_shape;
        new_shape->prev = tcurrent;
        new_shape->current = the_shape;
    }else{
        tcurrent->current = the_shape;
    }
    this->shape_count++;
}
sshape *Slot::end_shape(){
    sshape *tcurrent = this->shapes;
    while(tcurrent->next != NULL && tcurrent->current != NULL){
        tcurrent = tcurrent->next;
    }
    return tcurrent;
}
void Slot::draw(SDL_Surface*destination){
    sshape *tcurrent = this->shapes;
    Shape tshape = *(tcurrent->current);
    tshape.draw(destination);
    while(tcurrent->next != NULL){
        tcurrent = tcurrent->next;
        tshape = *(tcurrent->current);
        tshape.draw(destination);
    }
}
Shape Slot::pop(){
    sshape *end = this->end_shape();
    sshape *tcurrent = end->prev;
    tcurrent->next = NULL;
    end->prev = NULL;
    Shape *rtrn = end->current;
    end->current = NULL;
    free(end);
    return *rtrn;
}
void Slot::change_slot(int num, Shape *nshape){
    int i;
    if(num >= this->shape_count){
    }else{
        sshape *tcurrent = this->shapes;
        for(i = 0; i < num; i ++){
            tcurrent = tcurrent->next;
        }
        nshape->set_rect_x(tcurrent->current->get_rect_x());
        nshape->set_rect_y(tcurrent->current->get_rect_y());
        tcurrent->current = nshape;
    }
}
