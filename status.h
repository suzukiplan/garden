// 魔術パラメタ
struct Magic {
    int fire;       // 火: 水に弱く, 風に強い, 得意分野=攻撃
    int water;      // 水: 土に弱く, 火に強い, 得意分野=回復
    int wind;       // 風: 炎に弱く, 土に強い, 得意分野=攻撃系の補助
    int soil;       // 土: 風に弱い, 水に弱い, 得意分野=防御系の補助
    int light;      // 光: 弱点なし, 闇に強い, 得意分野=なし
    int dark;       // 闇: 弱点なし, 光に強い, 得意分野=なし
};

// 職業 (論理和で複合職業)
enum Job {
    job_none = 0,           // 無し
    job_farmers = 1,        // 農夫
    job_hunter = 2,         // 狩人
    job_enginner = 4,       // 技師
    job_merchant = 8,       // 商人
    job_noble = 16,         // 貴族
    job_warrior = 32,       // 戦士
    job_knight = 64,        // 騎士
    job_priest = 128,       // 神官
    job_witch = 256,        // 魔術師
    job_gambler = 512,      // 山師
    job_theif = 1024,       // 泥棒
    job_criminal = 2048,    // 犯罪者
    job_animal = 4096,      // 畜生
    job_evil = 8192,        // 魔族
    job_spirit = 16384      // 精霊
};

// 異常状態 (論理和で複合状態)
enum Health {
    health_normal = 0,      // 健康
    health_sleep = 1,       // 睡眠
    health_poison = 2,      // 毒
    health_paralysis = 4,   // 麻痺
    health_faint = 8,       // フェイント（スタン）
    health_confusion = 16,  // とんらん
    health_temptation = 32, // 誘惑
    health_stone = 64,      // 石
    health_zombie = 128     // ゾンビ
};
    
// 性別
enum Sex {
    sex_unknown = 0,
    sex_male = 1,           // Y
    sex_female = 2          // X
};

// 骨格
enum Skeleton {
    sk_none = 0,            // 軟体
    sk_dwarf = 1,           // 小人
    sk_slender = 2,         // 細身
    sk_medium = 3,          // 中肉中背
    sk_big = 4,             // 大柄
    sk_fat = 5,             // デブ
    sk_giant = 6            // 巨人
};

// 基本パラメタ
struct Status {
    int rank;       // 熟練度: 低いほどよく成長する
    int job;        // 職業: 成長度合いに影響（大）
    int jobF;       // 父親の職業: 成長度合いに影響（微量）
    int jobM;       // 母親の職業: 成長度合いに影響（微量）
    int age;        // 年齢: 成長度合い, 劣化率に影響
    int sex;        // 性別: 0=♂, 1=♀
    int life;       // 寿命: 年齢が寿命に達すると, 人物や魔物は死に, 装備品は壊れる
    int health;     // 健康: 異常状態
    int weight;     // 体重: 先制確率+回避率+攻撃力に影響
    int skeleton;   // 骨格: 体重の増加具合や得意分野に影響する先天的性質
    int hp;         // HP: 0以下で人物や魔物は死に, 装備品は壊れる
    int str;        // 腕力: 与えるダメージ量に影響
    int def;        // 守備: 受けるダメージ量に影響
    int vital;      // 体力: HPの成長度合いに影響
    int speed;      // 素早さ: 先制確率に影響
    int dex;        // 器用さ: 攻撃の成功率, 武器の成長度合いに影響
    int luck;       // 運: 全般的な成功率に影響
    int intel;      // 賢さ: 魔法の基本効力に影響
    int spirits;    // 霊力: 魔法の基本耐性に影響
    int love;       // 愛: 光の効力を増し, 闇の耐性を上げる
    int evil;       // 悪: 闇の効力を増し, 光の耐性を上げる
    struct Magic magic;
};

// 人物, 魔物, 装備品など全てのモノの総称
struct Element {
    char id[256];           // 識別子 (ユニーク値)
    char name[32];          // 名称
    int alive;              // 生存フラグ
    int price;              // 値段
    struct Status status;   // 基本パラメタ
};

void make_element(struct Element* element, enum Job jobF, enum Job jobM, const char* id, const char* name);
