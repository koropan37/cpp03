#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
: ClapTrap("_clap_name"), ScavTrap(), FragTrap(), name_("") {
	std::cout << "DiamondTrap Default constructor called " << name_ << std::endl;
	hit_points_ 	= default_hit_points;
	energy_points_ 	= default_energy_points;
	attack_damage_ 	= default_attack_damage;
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name) {
	std::cout << "DiamondTrap Copy name constructor called: " << name_ << std::endl;
  	hit_points_ 	= default_hit_points;
   	energy_points_ 	= default_energy_points;
	attack_damage_ 	= default_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& trap)
:  ClapTrap(trap), ScavTrap(trap), FragTrap(trap), name_(trap.name_)  {
	std::cout << "DiamondTrap Copy class constructor called: " << name_ << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& trap) {
	if(this != &trap) {
		ClapTrap::operator=(trap);
		name_ = trap.name_;
	}
	std::cout << "DiamondTrap Copy assignment operator called: " << name_ << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	if(!hasPoint()) return ;

	if(energy_points_ == 1) --energy_points_;
	else 					energy_points_ = 1;

	std::cout << className() << ": My Diamond name is " << name_ << std::endl;
	std::cout << ClapTrap::className() << ": My Clap name is " << ClapTrap::name_ <<std::endl;
}

std::string DiamondTrap::className() const { return "DiamondTrap "; }
