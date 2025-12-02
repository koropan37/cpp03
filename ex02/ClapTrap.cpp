#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap()
: name_(""), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << "ClapTrap Default constructor called" << name_ << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << "ClapTrap Copy name constructor called: " << name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& trap)
: name_(trap.name_),
  hit_points_(trap.hit_points_),
  energy_points_(trap.energy_points_),
  attack_damage_(trap.attack_damage_) {
	std::cout << "ClapTrap Copy class constructor called: " << name_ << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& trap) {
	if(this != &trap) {
		name_ 		   = trap.name_;
		hit_points_	   = trap.hit_points_;
		energy_points_ = trap.energy_points_;
		attack_damage_ = trap.attack_damage_;
	}
	std::cout << "ClapTrap Copy assignment operator called: " << name_ << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

std::string ClapTrap::getName() const { return name_; }
int 		ClapTrap::getHitPoints() const { return hit_points_; }
int 		ClapTrap::getEnergyPoints() const { return energy_points_; }
void		ClapTrap::setEnergyPoints(const int& ep) { energy_points_ = ep; }

void ClapTrap::attack(const std::string& target) {
	if(!hasPoint()) return ;
	--energy_points_;
	std::cout
		<< className() << name_ << " attacks " << target << ", causing "
		<< attack_damage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if(!validateAmount(amount)) return;
	if(hit_points_ <= 0) {
		std::cout << className() << name_ << " is already dead (;;)" << std::endl;
		return ;
	}
	else
		std::cout << className() << name_ << " takes " <<amount << " damage," << std::endl;
	hit_points_ -= amount;
	if(hit_points_ > 0)
		std::cout << "remaining HP is " << hit_points_ << std::endl;
	else {
		hit_points_ = 0;
		std::cout << "and " << name_ << " is dead..." << std::endl;
	}
	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if(!validateAmount(amount)) return;
	if(!hasPoint()) return ;
	--energy_points_;
	long new_hp = static_cast<long>(hit_points_) + static_cast<long>(amount);
	hit_points_ = validateOverflow(new_hp);
	std::cout
		<< className() << name_ << " is repaired " << amount << " hit points! "
		<< "remaining HP is " << hit_points_ << std::endl;
}

bool ClapTrap::hasPoint() const {
	if(hit_points_ <= 0) {
		std::cout << className() << name_ << " is already dead (;;)" << std::endl;
		return false;
	}
	if(energy_points_ <= 0) {
		std::cout << className() << name_ << " doesn't have energy points (>_<)" << std::endl;
		return false;
	}
	return true;
}

bool ClapTrap::validateAmount(unsigned int amount) {
    if (amount > static_cast<unsigned int>(std::numeric_limits<int>::max())) {
        std::cout << "Invalid amount: " << amount << std::endl;
        return false;
    }
	return true;
}

int ClapTrap::validateOverflow(long& new_hp) {
	long tmp = static_cast<long>(new_hp);
    if (tmp > static_cast<long>(std::numeric_limits<int>::max())) {
        tmp = static_cast<long>(std::numeric_limits<int>::max());
    }
    return static_cast<int>(tmp);
}

std::string ClapTrap::className() const { return "ClapTrap "; }
