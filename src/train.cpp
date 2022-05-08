// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}
Train::~Train() {
    int num = getLength();
    while (num--) {
        Cage* current = first;
        first = first->next;
        delete current;
    }
}
void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage;
        first->light = light;
        first->next = first->prev = nullptr;
    }
    else {
        Cage* current = first;
        while (current->next != nullptr) current = current->next;
        current->next = new Cage;
        Cage* last = current->next;
        last->light = light;
        last->prev = current;
        last->next = first;
        first->prev = last;
    }
    
}

int Train::getLength() {
    Cage* current = first;
    current->light = true;

    while (1) {
        int length_way = 0;
        do {
            current = current->next;
            length_way++;
        } while (!current->light);
        int length_fixed = countOp = length_way;
        current->light = false;
        while (length_way) {
            current = current->prev;
            length_way--;
            countOp++;
        }
        length_way = 0;
        if (!current->light) {
            return length_fixed;
        }
    }
}

 int Train::getOpCount(){
     return countOp;
 }
