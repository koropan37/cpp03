#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
: name_(""), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << "ClapTrap Copy name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& trap)
: name_(trap.name_),
  hit_points_(trap.hit_points_),
  energy_points_(trap.energy_points_),
  attack_damage_(trap.attack_damage_) {
	std::cout << "ClapTrap Copy class constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& trap) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if(this != &trap) {
		name_ 		   = trap.name_;
		hit_points_	   = trap.hit_points_;
		energy_points_ = trap.energy_points_;
		attack_damage_ = trap.attack_damage_;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

bool ClapTrap::hasPoint() const {
	if(hit_points_ <= 0) {
		std::cout << "ClapTrap " << name_ << "is already dead (;;)";
		return false;
	}
	if(energy_points_ <= 0) {
		std::cout << "ClapTrap " << name_ << "doesn't have energy points (>_<)";
		return false;
	}
	return true;
}

void ClapTrap::attack(const std::string& target) {
	if(!hasPoint())
		return ;
	--energy_points_;
	std::cout
		<< "ClapTrap " << name_ << "attacks " << target << ", causing "
		<< attack_damage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if(hit_points_ <= 0) {
		std::cout << "ClapTrap " << name_ << "is already dead (;;)";
		return ;
	}
	else
		std::cout << "ClapTrap " << name_ << "takes " <<amount << "damage, ";
	hit_points_ -= amount;
	if(hit_points_ > 0)
		std::cout << "remaining HP is " << hit_points_;
	else
		std::cout << "and " << name_ << "is dead";
	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if(!hasPoint())
		return ;
	--energy_points_;
	hit_points_ += amount;
	std::cout
		<< "ClapTrap " << name_ << "is repaired " << amount << "hit points! "
		<< "remaining HP is " << hit_points_ << std::endl;
}
