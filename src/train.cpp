// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() :countOp(-1), first(nullptr) {}

void Train::addCage(bool light) {
    Cage* nc = new Cage;
    nc->light = light;
    if (first == nullptr) {
        first = nc;
        first->next = first;
        first->prev = first;
    } else {
        nc->next = first;
        nc->prev = first->prev;
        first->prev = nc;
        nc->prev->next = nc;
    }
}

int Train::getLength() {
    Cage* temp = first;
    temp->light = 1;
    int countTemp = 1;
    countOp = 0;
    while (temp) {
        temp = temp->next;
        if (!temp->light) {
            countOp++;
            countTemp++;
        } else {
            countOp++;
            temp->light = false;
            for (int i = countTemp; i > 0; i--) {
                temp = temp->prev;
                countOp++;
            }
            if (!temp->light) {
                return countTemp;
            }
            countTemp = 1;
        }
    }
    return -1;
}
int Train::getOpCount() {
    if (countOp == -1) getLength();
    return countOp;
}
