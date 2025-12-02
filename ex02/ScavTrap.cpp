#include "ScavTrap.hpp"
#include <iostream>

int const ScavTrap::default_hit_points 	  = 100;
int const ScavTrap::default_energy_points = 50;
int const ScavTrap::default_attack_damage = 20;

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called " << name_ << std::endl;
	hit_points_ 	= default_hit_points;
	energy_points_ 	= default_energy_points;
	attack_damage_ 	= default_attack_damage;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap Copy name constructor called: " << name_ << std::endl;
  	hit_points_ 	= default_hit_points;
   	energy_points_ 	= default_energy_points;
	attack_damage_ 	= default_attack_damage;
}

ScavTrap::ScavTrap(const ScavTrap& trap) : ClapTrap(trap) {
	std::cout << "ScavTrap Copy class constructor called: " << name_ << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& trap) {
	if(this != &trap) {
		ClapTrap::operator=(trap);
	}
	std::cout << "ScavTrap Copy assignment operator called: " << name_ << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if(!hasPoint())
		return ;
	ClapTrap::attack(target);
	std::cout << "And speed up!" << std::endl;
}

void ScavTrap::guardGate() {
	if(!hasPoint()) return ;

	if(energy_points_ == 1) --energy_points_;
	else 					energy_points_ = 1;

	std::cout << className() << name_ << " create GuardGate!!!" << std::endl;
}

std::string ScavTrap::className() const { return "ScavTrap "; }
