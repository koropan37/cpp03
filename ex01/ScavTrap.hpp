#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 protected:
	static int const default_hit_points;
  	static int const default_energy_points;
  	static int const default_attack_damage;

	virtual std::string className() const;

 public:
 	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap& operator=(const ScavTrap& trap);
	ScavTrap(const ScavTrap& trap);
	~ScavTrap();

	virtual void attack(const std::string& target);
	void  guardGate();
};

#endif
