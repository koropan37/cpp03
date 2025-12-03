#include <iostream>
#include <string>
#include "ScavTrap.hpp"

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
void testScav();

int main(void) {
	// testClap();
	// std::cout << std::endl;
	testScav();
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

void testScav() {
	printColor("ScavTrap TEST", B_GREEN);
	std::cout << std::endl;

	printColor("INITIALIZATION", CYAN);
	ScavTrap a;
	ScavTrap b("B");
	ScavTrap c(b);
	ScavTrap d = c;
	a = d;
	ScavTrap e("rob");
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
	e.guardGate();
	e.guardGate();
	e.guardGate();
	std::cout << std::endl;

	{
	printColor("POINT", WHITE);
	ClapTrap *p = new ScavTrap("P"); //基底クラスに派生クラスのポインタ
	p->attack("d");
	printStatus(*p);
	p->beRepaired(10);
	printStatus(*p);
	p->takeDamage(10);
	printStatus(*p);
	delete p;

	std::cout << std::endl;
	ScavTrap f("F");
	ClapTrap& s = f; //基底クラスに派生クラスの参照
	s.attack("d");
	printStatus(f);
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
