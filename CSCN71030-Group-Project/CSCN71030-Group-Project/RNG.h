#pragma once


struct EnemyMobValues {
    int max_health;
    int attack;
    int defence;
    int speed;

    EnemyMobValues();
};

struct BossValues : EnemyMobValues {
    BossValues();
};