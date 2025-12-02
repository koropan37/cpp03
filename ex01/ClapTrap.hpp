#ifndef CLAPTRAP_CPP_
#define CLAPTRAP_CPP_

#include <string>
#include <limits>

class ClapTrap {
 protected:
    std::string name_;
    int hit_points_;
    int energy_points_;
    int attack_damage_;

	bool hasPoint() const;
	bool validateAmount(unsigned int amount);
	int validateOverflow(long& new_hp);
	virtual std::string className() const;
	//std::string className() const;
	//基底型のポインタ/参照を通じて派生クラスの実装を呼ぶときに,virtualが必要
	//あれば実行時に、実際の型を見て派生の関数が呼ばれる
	//ないと常に基底のもの

 public:
    ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap& operator=(const ClapTrap& trap);
	ClapTrap(const ClapTrap& trap);
	virtual ~ClapTrap();
	//virtualがないと基底ポインタでdeleteしたときに
	//派生クラスのデストラクタが呼ばれず、未定義になる

	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	void setEnergyPoints(const int& ep);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
