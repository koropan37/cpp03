#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 private:
	std::string name_;

 protected:
	using FragTrap::default_attack_damage;
	using FragTrap::default_hit_points;
	using ScavTrap::default_energy_points;

 	virtual std::string className() const ;

 public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

	void whoAmI();
	using ScavTrap::attack;
};

#endif
