#include <stdio.h>
#include "status.h"

void show_element(struct Element* e) {
    printf("id: %s, name: %s, alive: %d, price: %d\n", e->id, e->name, e->alive, e->price);
    printf("rank: %d, job: %d, job(f): %d, job(m): %d\n", e->status.rank, e->status.job, e->status.jobF, e->status.jobM);
    printf("age: %d / %d, sex: %d, health: %d, weight: %d, skeleton: %d, hp: %d\n"
        , e->status.age, e->status.life, e->status.sex, e->status.health
        , e->status.weight, e->status.skeleton, e->status.hp
    );
    printf("str: %d, def: %d, vit: %d, spd: %d, dex: %d, luk: %d, int: %d spi: %d, lov: %d, evi: %d\n"
        , e->status.str, e->status.def, e->status.vital, e->status.speed
        , e->status.dex, e->status.luck, e->status.intel, e->status.spirits
        , e->status.love, e->status.evil
    );
}

int main() {
    struct Element elm;
    int i;
    printf("-----\n");
    for (i = 0; i < 6; i++) {
        make_element(&elm, job_spirit, job_spirit, "hoge", "hoge");
        show_element(&elm);
        printf("-----\n");
    }
    return 0;
}