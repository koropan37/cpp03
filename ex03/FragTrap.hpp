#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 protected:
	static int const default_hit_points;
  	static int const default_energy_points;
  	static int const default_attack_damage;

	virtual std::string className() const;

 public:
 	FragTrap();
	FragTrap(const std::string& name);
	FragTrap& operator=(const FragTrap& trap);
	FragTrap(const FragTrap& trap);
	~FragTrap(); //基底にvirtualがあれば、派生は暗黙的にvirtual

	void highFiveGuys();
};

#endif
