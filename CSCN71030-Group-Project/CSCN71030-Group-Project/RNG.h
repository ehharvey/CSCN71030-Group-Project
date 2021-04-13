#ifndef RNG_H
#define RNG_H

#pragma once


struct CharacterValues {
    int value_one;
    int value_two;
    int value_three;
    int value_four;

    CharacterValues();
};

int getEncounterIndex();

int getEnemyIndex();

#endif  // !RNG_H