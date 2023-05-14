#include "Player.hpp"

Player::Player()
:   name{def_name},
    health{def_health},
    maxHealth{def_health},
    minDamage{def_min_damage},
    maxDamage{def_max_damage},
    exp{def_exp},
    expNext{def_exp_next},
    level{def_level},
    stamina{def_stamina},
    staminaMax{def_stamina_max},
    defence{def_defence},
    strength{def_strength},
    dexterity{def_dexterity},
    intelligence{def_intelligence},
    luck{def_luck},
    statPoints{def_stat_points},
    skillPoints{def_skill_points},
    money{def_money} {
}

bool Player::isAlive() const {
    return health > 0 ? true : false; 
}

int Player::inflictDamage() {
    int givenDamage{};

    givenDamage = rand() % (maxDamage - minDamage + 1) + minDamage;

    return givenDamage;
}

void Player::initialize(const std::string &name) {
    this->name = name;
    this->health = def_health;
    this->maxHealth = def_health;
    this->minDamage = def_min_damage;
    this->maxDamage = def_max_damage;
    this->exp = def_exp;
    this->expNext = def_exp_next;
    this->level = def_level;
    this->stamina = def_stamina;
    this->staminaMax = def_stamina_max;
    this->defence = def_defence;
    this->strength = def_strength;
    this->dexterity = def_dexterity;
    this->intelligence = def_intelligence;
    this->luck = def_luck;
    this->statPoints = def_stat_points;
    this->skillPoints = def_skill_points;
    this->money = def_money;
    inventory.initialize();
}

void Player::levelUp() {
    if(exp >= expNext) {
        level++;
        exp -= expNext;

        expNext = def_exp_next * (level - 1) + def_exp_next * (level - 1) * 0.5;
        skillPoints++;
        statPoints += 5;
        std::cout << "Congratulations, you are now " << this->level << " level!" << std::endl;
    }
    else {
        std::cout << "You don't have enough experience" << std::endl;
    }
}

void Player::showStats() {
    std::cout << std::endl << "/* Player stats */" << std::endl
              << "Name: "                    << this->name << std::endl
              << "Level: "                   << this->level << std::endl
              << "XP: "                      << this->exp << " / " << this->expNext << std::endl
              << "Health: "                  << this->health << " / " << this->maxHealth << std::endl
              << "Stamina: "                 << this->stamina << " / " << this->staminaMax << std::endl
              << "Damage: "                  << this->minDamage << " - " << this->maxDamage << std::endl
              << "Defence: "                 << this->defence << std::endl
              << std::endl
              << "/* Player Atributtes */"   << std::endl
              << "Strength: "                << this->strength << std::endl
              << "Dexterity: "               << this->dexterity << std::endl
              << "Intelligence: "            << this->intelligence << std::endl
              << "Luck: "                    << this->luck << std::endl
              << "Available stats points: "  << this->statPoints << std::endl
              << "Available skill points: "  << this->skillPoints << std::endl;
}

void Player::increaseAttributes() {
    char choice{'n'};
    do {
        if(this->statPoints > 0) {
            this->statPoints--;
            std::cout << "(1) - Strength" << std::endl
                      << "(2) - Dexterity" << std::endl
                      << "(3) - Intelligence" << std::endl
                      << "(4) - Luck" << std::endl;
            int choice = getNumber("Enter which attribute you want to increase: ");
            if(choice == 1) {
                this->strength++;
                this->health += 1;
                this->maxHealth += 1;
                this->staminaMax += 1;
                this->stamina += 1;
            }
            else if(choice == 2) {
                this->dexterity++;
                this->minDamage+=1;
                this->maxDamage+=1;
            }
            else if(choice == 3) {
                this->intelligence++;
                this->defence += 1;
            }
            else if(choice == 4) {
                this->luck++;
                this->health -= 1;
                this->maxHealth -= 1;
                this->staminaMax += 2;
                this->stamina += 2;
            }
        }
        else {
            std::cout << "You don't have enough stats points" << std::endl;
        }
        std::cout << "You have " << this->statPoints << " points left.\n Do you want to continue? (y/n)";
        std::cin >> choice;
    } while(this->statPoints > 0 && choice != 'n');

}


int getNumber(const std::string &message) {
    int number{};
    std::cout << message;
    std::cin >> number;
    return number;    
}

void Player::buyItem(std::unique_ptr<Item> &item) {
    if(this->money >= item->getPurchasePrice()) {
        std::cout << "You successfully bought a " << item->getName() << std::endl;
        this->money -= item->getPurchasePrice();
        this->inventory.addItem(item);
    }
    else {
        std::cout << "You don't have enough money to buy " << item->getName() << std::endl;
    }
}

void shop(Player &p) {
    std::cout << "Welcome to the Golden street " << p.getName() << "!" << std::endl;
    std::cout << "In this street you can buy (almost) everything you want" << std::endl;
    std::cout << "What type of items you want to view?" << std::endl;
    std::cout << "(1) - Weapons\n(2) - Armor\n(3) - Potions" << std::endl;
    int choice = getNumber("Your choice: ");
    if(choice == 1) {
        weaponShop(p);
    }
    else if(choice == 2) {
        armorShop(p);
    }
    else if(choice == 3) {
        potionShop(p);
    }
    else {
        std::cout << "Such things are not sold on this street" << std::endl;
    }
}

void weaponShop(Player &p) {
    
}

void armorShop(Player &p) {

}

void potionShop(Player &p) {

}