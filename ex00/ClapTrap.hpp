#ifndef CLAPTRAP_CPP_
#define CLAPTRAP_CPP_

#include <string>

class ClapTrap {
 private:
    std::string name_;
    int hit_points_;
    int energy_points_;
    int attack_damage_;

 public:
   ClapTrap();
   ClapTrap(const std::string& name);
   ClapTrap& operator=(const ClapTrap& trap);
   ClapTrap(const ClapTrap& trap);
   ~ClapTrap();

   void attack(const std::string& target);
   void takeDamage(unsigned int amount);
   void beRepaired(unsigned int amount);

   bool hasPoint() const;
};

#endif
