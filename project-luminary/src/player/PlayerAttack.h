#ifndef PROJECT_LUMINARY_PLAYERATTACK_H
#define PROJECT_LUMINARY_PLAYERATTACK_H


class PlayerAttack {
private:
    std::string m_name;
    float m_damage;
public:
    PlayerAttack(std::string name, float damage);
    std::string getName();
    float getDamage();
};


#endif //PROJECT_LUMINARY_PLAYERATTACK_H
