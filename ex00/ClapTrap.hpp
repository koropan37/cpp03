#ifndef CLAPTRAP_CPP_
#define CLAPTRAP_CPP_

#include <string>

class ClapTrap {
 private:
    std::string name_;
 public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif