#pragma once


struct EnemyMobValues {
    int max_health;
    int attack;
    int defence;
    int speed;

    EnemyMobValues(int user_max_health, int user_attack, int user_defence, int user_speed);
};

struct BossValues : EnemyMobValues {
    BossValues(int user_max_health, int user_attack, int user_defence, int user_speed);
};

int getEncounterIndex();

int getEnemyIndex();