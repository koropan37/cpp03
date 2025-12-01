#include <iostream>
#include <string>
#include "ClapTrap.hpp"

// 色コードは文字列リテラルで定義する
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"

void printcolor(std::string const& str, std::string const& color) {
    std::cout << color << str << std::endl;
}


void resetcolor() {
    std::cout << RESET << std::endl;
}

int main(void) {

	printcolor("INITIALIZATION", CYAN);
	ClapTrap a;
	ClapTrap b("B");
	ClapTrap c(b);
	ClapTrap d = c;
	a = d;
}
