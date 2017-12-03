#include <string.h>
#include <stdlib.h>
#include "rand.h"
#include "status.h"

// エレメントを創る
void make_element(struct Element* element, enum Job jobF, enum Job jobM, const char* id, const char* name) {
    memset(element, 0, sizeof(struct Element));
    strncpy(element->id, id, sizeof(element->id) - 1);
    strncpy(element->name, name, sizeof(element->name) - 1);
    element->alive = 1;
    element->status.hp = 1;
    element->status.sex = get_rand1024() < 512 ? sex_female : sex_male;
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
    if (jobF & job_noble) element->status.life += 5;
    if (jobM & job_noble) element->status.life += 7;
    if (jobF & job_warrior) element->status.life -= 1;
    if (jobM & job_warrior) element->status.life -= 2;
    if (jobF & job_knight) element->status.life -= 3;
    if (jobM & job_knight) element->status.life -= 4;
    if (jobF & job_priest) element->status.life += 4;
    if (jobM & job_priest) element->status.life += 6;
    if (jobF & job_witch) element->status.life += 3;
    if (jobM & job_witch) element->status.life += 5;
    if (jobF & job_gambler) element->status.life -= 4;
    if (jobM & job_gambler) element->status.life -= 5;
    if (jobF & job_theif) element->status.life -= 5;
    if (jobM & job_theif) element->status.life -= 7;
    if (jobF & job_criminal) element->status.life -= 12;
    if (jobM & job_criminal) element->status.life -= 15;
    if (jobF & job_evil) element->status.life += 203;
    if (jobM & job_evil) element->status.life += 403;
    if (jobF & job_spirit) element->status.life += 440;
    if (jobM & job_spirit) element->status.life += 500;
    if (jobF & job_animal || jobM & job_animal) element->status.life /= 3;
    element->status.life += get_rand1024() % element->status.life - element->status.life / 2;

    // 天命 (先天的な職業) を決定する
    if (jobF & job_spirit && jobM & job_spirit) element->status.job |= job_spirit;
    if (jobF & job_evil && jobM & job_evil) element->status.job |= job_evil;
    if (jobF & job_animal && jobM & job_animal) element->status.job |= job_animal;
    if (jobF & job_noble && jobM & job_noble) element->status.job |= job_noble;

    // 体重を決定する
    if (jobF & job_spirit && jobM & job_spirit) {
        // 精霊の子は1kg未満
        element->status.weight = 1 + get_rand1024() % 999;
    } else if (jobF & job_evil && jobM & job_evil) {
        // 魔族は6kg以上だいたい12kg以下
        element->status.weight = 6000 + get_rand1024() * 6;
    } else {
        // その他は1kg以上だいたい6kg未満
        element->status.weight = 1000 + get_rand1024() * 48 / 10;
    }

    // 骨格を決定する
    if (element->status.weight < 1000) {
        element->status.skeleton = sk_dwarf;
    } else if (6000 <= element->status.weight) {
        element->status.skeleton = sk_giant;
    } else if (element->status.weight < 1500) {
        element->status.skeleton = sk_slender;
    } else if (5500 <= element->status.weight) {
        element->status.skeleton = sk_fat;
    } else if (4800 <= element->status.weight) {
        element->status.skeleton = sk_big;
    } else {
        element->status.skeleton = sk_medium;
    }
    element->status.hp += element->status.skeleton;
}

// 年齢を上げる
void age_up(struct Element* target, struct Element* result) {
    memset(result, 0, sizeof(struct Element));
    result->status.age = 1;

}
