#include "FragTrap.hpp"
#include <iostream>

int const FragTrap::default_hit_points 	  = 100;
int const FragTrap::default_energy_points = 100;
int const FragTrap::default_attack_damage = 30;

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default constructor called " << name_ << std::endl;
	hit_points_ 	= default_hit_points;
	energy_points_ 	= default_energy_points;
	attack_damage_ 	= default_attack_damage;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap Copy name constructor called: " << name_ << std::endl;
  	hit_points_ 	= default_hit_points;
   	energy_points_ 	= default_energy_points;
	attack_damage_ 	= default_attack_damage;
}

FragTrap::FragTrap(const FragTrap& trap) : ClapTrap(trap) {
	std::cout << "FragTrap Copy class constructor called: " << name_ << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& trap) {
	if(this != &trap) {
		ClapTrap::operator=(trap);
	}
	std::cout << "FragTrap Copy assignment operator called: " << name_ << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFiveGuys() {
	if(!hasPoint()) return ;

	if(energy_points_ == 1) --energy_points_;
	else 					energy_points_ = 1;

	std::cout << className() << name_ << ": Powering up five teammates!" << std::endl;
}

std::string FragTrap::className() const { return "FragTrap "; }
