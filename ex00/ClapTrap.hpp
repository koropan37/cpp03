#ifndef CLAPTRAP_CPP_
#define CLAPTRAP_CPP_

#include <string>
#include <limits>

class ClapTrap {
 private:
   std::string name_;
   int hit_points_;
   int energy_points_;
   int attack_damage_;

   bool hasPoint() const;
   bool validateAmount(unsigned int amount);
   int validateOverflow(long& new_hp);
   std::string className() const;

 public:
   ClapTrap();
   ClapTrap(const std::string& name);
   ClapTrap& operator=(const ClapTrap& trap);
   ClapTrap(const ClapTrap& trap);
   ~ClapTrap();

   std::string getName() const;
   int getHitPoints() const;
   int getEnergyPoints() const;

   void attack(const std::string& target);
   void takeDamage(unsigned int amount);
   void beRepaired(unsigned int amount);
};

#endif
