#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"
#define B_RED	"\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_CYAN  "\033[1;36m"

void printColor(std::string const& str, std::string const& color) {
    std::cout
	<< RESET << "======="
	<< color << str
	<< RESET << "=======" << color << std::endl;
}

//void testClap();
//void testScav();
//void testFrag();
void testDiamond();

int main(void) {
	// testClap();
	// std::cout << std::endl;
	// testScav();
	// std::cout << std::endl;
	// testFrag();
	// std::cout << std::endl;
	testDiamond();
	std::cout << std::endl;
}

void printStatus(ClapTrap &trap) {
	std::cout
		<< "Name: " << trap.getName()
		<< " HP: " << trap.getHitPoints()
		<< " EP: " << trap.getEnergyPoints()
		<< std::endl;
}

// void testClap() {

// 	printColor("ClapTrap TEST", B_GREEN);
// 	std::cout << std::endl;

// 	printColor("INITIALIZATION", CYAN);
// 	ClapTrap a;
// 	ClapTrap b("B");
// 	ClapTrap c(b);
// 	ClapTrap d = c;
// 	a = d;
// 	std::cout << std::endl;

// 	printColor("ATTACK", MAGENTA);
// 	for(int i = 1; i < 12; ++i) {
// 		std::cout << i << ": ";
// 		a.attack("d");
// 		printStatus(a);
// 	}
// 	std::cout << std::endl;
// 	printColor("REPAIR", GREEN);
// 	for (int i = 1; i < 12; ++i) {
// 		std::cout << i << ": ";
// 		b.beRepaired(1);
// 		printStatus(b);
// 	}
// 	std::cout << std::endl;

// 	printColor("TAKE DAMAGE", RED);
// 	c.takeDamage(5);
// 	printStatus(c);
// 	c.takeDamage(100);
// 	printStatus(c);
// 	c.takeDamage(0);
// 	printStatus(c);
// 	c.attack("d");
// 	printStatus(c);
// 	c.beRepaired(100);
// 	printStatus(c);
// 	std::cout << std::endl;

// 	printColor("POINT", B_CYAN);
// 	{
// 	ClapTrap *p = new ClapTrap("P");
// 	p->attack("d");
// 	p->beRepaired(10);
// 	p->takeDamage(10);
// 	delete p;
// 	std::cout << std::endl;
// 	}

// 	printColor("ERROR", B_RED);
// 	d.beRepaired(2147483647);
// 	printStatus(d);
// 	d.takeDamage(-1);
// 	printStatus(d);
// 	d.takeDamage(2147483647);
// 	printStatus(d);
// 	d.takeDamage(2147483647);
// 	printStatus(d);
// 	std::cout << std::endl;

// 	printColor("DESTRUCTOR", YELLOW);
// }

void printStatus(ScavTrap &trap) {
	std::cout
		<< "Name: " << trap.getName()
		<< " HP: " << trap.getHitPoints()
		<< " EP: " << trap.getEnergyPoints()
		<< std::endl;
}

// void testScav() {
// 	printColor("ScavTrap TEST", B_GREEN);
// 	std::cout << std::endl;

// 	printColor("INITIALIZATION", CYAN);
// 	ScavTrap a;
// 	ScavTrap b("B");
// 	ScavTrap c(b);
// 	ScavTrap d = c;
// 	a = d;
// 	ScavTrap e("rob");
// 	std::cout << std::endl;

// 	printColor("ATTACK", MAGENTA);
// 	for(int i = 1; i < 5; ++i) {
// 		std::cout << i << ": ";
// 		a.attack("d");
// 		printStatus(a);
// 	}
// 	a.setEnergyPoints(0);
// 	std::cout << "setEnergyPoints(0)" <<std::endl;
// 	printStatus(a);
// 	a.attack("d");
// 	printStatus(a);
// 	std::cout << std::endl;
// 	printColor("REPAIR", GREEN);
// 	for (int i = 1; i < 5; ++i) {
// 		std::cout << i << ": ";
// 		b.beRepaired(1);
// 		printStatus(b);
// 	}
// 	b.setEnergyPoints(0);
// 	std::cout << "setEnergyPoints(0)" <<std::endl;
// 	printStatus(b);
// 	b.beRepaired(10);
// 	printStatus(b);
// 	std::cout << std::endl;

// 	printColor("TAKE DAMAGE", RED);
// 	c.takeDamage(5);
// 	printStatus(c);
// 	c.takeDamage(100);
// 	printStatus(c);
// 	c.takeDamage(0);
// 	printStatus(c);
// 	c.attack("d");
// 	printStatus(c);
// 	c.beRepaired(100);
// 	printStatus(c);
// 	std::cout << std::endl;

// 	printColor("SPECIAL ABILITY", BLUE);
// 	e.guardGate();
// 	e.guardGate();
// 	e.guardGate();
// 	std::cout << std::endl;

// 	{
// 	printColor("POINT", B_CYAN);
// 	ClapTrap *p = new ScavTrap("P");
// 	p->attack("d");
// 	p->beRepaired(10);
// 	printStatus(*p);
// 	p->takeDamage(10);
// 	printStatus(*p);
// 	ScavTrap f("F");
// 	ClapTrap& s = f;
// 	s.attack("d");
// 	printStatus(f);
// 	delete p;
// 	}
// 	std::cout << std::endl;

// 	printColor("ERROR", B_RED);
// 	d.beRepaired(2147483647);
// 	printStatus(d);
// 	d.takeDamage(-1);
// 	printStatus(d);
// 	d.takeDamage(2147483647);
// 	printStatus(d);
// 	d.takeDamage(2147483647);
// 	printStatus(d);
// 	std::cout << std::endl;

// 	printColor("DESTRUCTOR", YELLOW);
// }

void printStatus(FragTrap &trap) {
	std::cout
		<< "Name: " << trap.getName()
		<< " HP: " << trap.getHitPoints()
		<< " EP: " << trap.getEnergyPoints()
		<< std::endl;
}

// void testFrag() {
// 	printColor("FragTrap TEST", B_GREEN);
// 	std::cout << std::endl;

// 	printColor("INITIALIZATION", CYAN);
// 	FragTrap a;
// 	FragTrap b("B");
// 	FragTrap c(b);
// 	FragTrap d = c;
// 	a = d;
// 	FragTrap e("rob");
// 	std::cout << std::endl;

// 	printColor("ATTACK", MAGENTA);
// 	for(int i = 1; i < 5; ++i) {
// 		std::cout << i << ": ";
// 		a.attack("d");
// 		printStatus(a);
// 	}
// 	a.setEnergyPoints(0);
// 	std::cout << "setEnergyPoints(0)" <<std::endl;
// 	printStatus(a);
// 	a.attack("d");
// 	printStatus(a);
// 	std::cout << std::endl;
// 	printColor("REPAIR", GREEN);
// 	for (int i = 1; i < 5; ++i) {
// 		std::cout << i << ": ";
// 		b.beRepaired(1);
// 		printStatus(b);
// 	}
// 	b.setEnergyPoints(0);
// 	std::cout << "setEnergyPoints(0)" <<std::endl;
// 	printStatus(b);
// 	b.beRepaired(10);
// 	printStatus(b);
// 	std::cout << std::endl;

// 	printColor("TAKE DAMAGE", RED);
// 	c.takeDamage(5);
// 	printStatus(c);
// 	c.takeDamage(100);
// 	printStatus(c);
// 	c.takeDamage(0);
// 	printStatus(c);
// 	c.attack("d");
// 	printStatus(c);
// 	c.beRepaired(100);
// 	printStatus(c);
// 	std::cout << std::endl;

// 	printColor("SPECIAL ABILITY", BLUE);
// 	e.highFiveGuys();
// 	e.highFiveGuys();
// 	e.highFiveGuys();
// 	std::cout << std::endl;

// 	{
// 	printColor("POINT", B_CYAN);
// 	ClapTrap *p = new FragTrap("P");
// 	p->attack("d");
// 	printStatus(*p);
// 	p->beRepaired(10);
// 	printStatus(*p);
// 	p->takeDamage(10);
// 	printStatus(*p);
// 	delete p;

// 	std::cout << std::endl;
// 	FragTrap f("F");
// 	ClapTrap& s = f;
// 	s.attack("d");
// 	printStatus(f);
// 	}
// 	std::cout << std::endl;

// 	printColor("ERROR", B_RED);
// 	d.beRepaired(2147483647);
// 	printStatus(d);
// 	d.takeDamage(-1);
// 	printStatus(d);
// 	d.takeDamage(2147483647);
// 	printStatus(d);
// 	d.takeDamage(2147483647);
// 	printStatus(d);
// 	std::cout << std::endl;

// 	printColor("DESTRUCTOR", YELLOW);
// }

void printStatus(DiamondTrap &trap) {
	std::cout
		<< "Name: " << trap.getName()
		<< " HP: " << trap.getHitPoints()
		<< " EP: " << trap.getEnergyPoints()
		<< std::endl;
}

void testDiamond() {
	printColor("DiamondTrap TEST", B_GREEN);
	std::cout << std::endl;

	printColor("INITIALIZATION", CYAN);
	DiamondTrap a;
	DiamondTrap b("B");
	DiamondTrap c(b);
	DiamondTrap d = c;
	a = d;
	DiamondTrap e("rob");
	std::cout << std::endl;

	printColor("ATTACK", MAGENTA);
	for(int i = 1; i < 5; ++i) {
		std::cout << i << ": ";
		a.attack("d");
		printStatus(a);
	}
	a.setEnergyPoints(0);
	std::cout << "setEnergyPoints(0)" <<std::endl;
	printStatus(a);
	a.attack("d");
	printStatus(a);
	std::cout << std::endl;
	printColor("REPAIR", GREEN);
	for (int i = 1; i < 5; ++i) {
		std::cout << i << ": ";
		b.beRepaired(1);
		printStatus(b);
	}
	b.setEnergyPoints(0);
	std::cout << "setEnergyPoints(0)" <<std::endl;
	printStatus(b);
	b.beRepaired(10);
	printStatus(b);
	std::cout << std::endl;

	printColor("TAKE DAMAGE", RED);
	c.takeDamage(5);
	printStatus(c);
	c.takeDamage(100);
	printStatus(c);
	c.takeDamage(0);
	printStatus(c);
	c.attack("d");
	printStatus(c);
	c.beRepaired(100);
	printStatus(c);
	std::cout << std::endl;

	printColor("SPECIAL ABILITY", BLUE);
	e.highFiveGuys();
	e.highFiveGuys();
	e.highFiveGuys();
	e.setEnergyPoints(3);
	std::cout << "setEnergyPoints(3)" <<std::endl;
	e.highFiveGuys();
	e.highFiveGuys();
	e.highFiveGuys();
	e.setEnergyPoints(3);
	std::cout << "setEnergyPoints(3)" <<std::endl;
	e.whoAmI();
	e.whoAmI();
	e.whoAmI();
	std::cout << std::endl;

	{
	printColor("POINT", WHITE);
	ClapTrap *p = new DiamondTrap("P");

	p->attack("d");
	printStatus(*p);
	p->ClapTrap::attack("enemy");
	printStatus(*p);
	p->beRepaired(10);
	printStatus(*p);
	p->takeDamage(10);
	printStatus(*p);
	delete p;
	std::cout << std::endl;

	ScavTrap *st = new DiamondTrap("St");
	st->attack("d");
	printStatus(*st);
	st->beRepaired(10);
	printStatus(*st);
	st->takeDamage(10);
	printStatus(*st);
	delete st;
	std::cout << std::endl;

	FragTrap *ft = new DiamondTrap("Ft");
	ft->attack("d");
	printStatus(*ft);
	ft->beRepaired(10);
	printStatus(*ft);
	ft->takeDamage(10);
	printStatus(*ft);
	delete ft;
	std::cout << std::endl;

	DiamondTrap f("F");
	ClapTrap& s = f;
	ScavTrap& sc = f;
	FragTrap& fg = f;
	s.attack("d");
	printStatus(f);
	sc.attack("d");
	printStatus(sc);
	fg.attack("d");
	printStatus(fg);
	}
	std::cout << std::endl;

	printColor("ERROR", B_RED);
	d.beRepaired(2147483647);
	printStatus(d);
	d.takeDamage(-1);
	printStatus(d);
	d.takeDamage(2147483647);
	printStatus(d);
	d.takeDamage(2147483647);
	printStatus(d);
	std::cout << std::endl;

	printColor("DESTRUCTOR", YELLOW);
}
