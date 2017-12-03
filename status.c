#include <string.h>
#include <stdlib.h>
#include "status.h"

// 人間を創る
void make_human(struct Element* element, enum Job jobF, enum Job jobM, const char* id, const char* name) {
    memset(element, 0, sizeof(struct Element));
    strncpy(element->id, id, sizeof(element->id) - 1);
    strncpy(element->name, name, sizeof(element->name) - 1);
    element->alive = 1;
    element->status.hp = 1;
    element->status.jobF = jobF;
    element->status.jobM = jobM;

    // 寿命を決定する (寿命は親の職業により増減する)
    element->status.life = 60;
    if (jobF & job_farmers) element->status.life += 3;
    if (jobM & job_farmers) element->status.life += 5;
    if (jobF & job_hunter) element->status.life += 1;
    if (jobM & job_hunter) element->status.life += 2;
    if (jobF & job_enginner) element->status.life -= 4;
    if (jobM & job_enginner) element->status.life -= 6;
    if (jobF & job_merchant) element->status.life -= 3;
    if (jobM & job_merchant) element->status.life -= 5;
    if (jobM & job_noble) element->status.life += 10;
    if (jobF & job_noble) element->status.life += 9;
    if (jobF & job_evil) element->status.life += 203;
    if (jobM & job_evil) element->status.life += 403;
    if (jobF & job_spirit) element->status.life += 440;
    if (jobM & job_spirit) element->status.life += 500;
    if (jobF & job_criminal) element->status.life = element->status.life * 10 / 50;
    if (jobM & job_criminal) element->status.life = element->status.life * 10 / 50;
    if (jobF & job_animal || jobM & job_animal) element->status.life /= 3;
}

// 年齢を上げる
void age_up(struct Element* target, struct Element* result) {
    memset(result, 0, sizeof(struct Element));
    result->status.age = 1;

}
