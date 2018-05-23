#include <string>
#include <vector>
#include <iostream>

namespace types{
	enum Type { FIRE = 0,	GRASS, WATER,	NONE, SIZE_OF_ENUM };
	static const char* TypeNames[] = { "Fire", "Grass", "Water", ""};

	// statically check that the size of ColorNames fits the number of Colors
	//static_assert(sizeof(foo::ColorNames)/sizeof(char*) == foo::SIZE_OF_ENUM, "sizes dont match");
}


namespace stats{
	enum Stat { HP=0, ATK, DEF, SPATK, SPDEF, SPE, SIZE_OF_ENUM };
}


// Define a Pokemon species
class Species{
private:
	int baseStats_[6];
	int type1_;
	int type2_;
	std::string name_;
	
	
public:
	Species(std::string name, int type1, int type2,
			int bHp, int bAtk, int bDef, int bSpAtk, int bSpDef, int bSpe){
			name_ = name;
			type1_ = type1;
			type2_ = type2;
			
			baseStats_[stats::HP] = bHp;
			baseStats_[stats::ATK] = bAtk;
			baseStats_[stats::DEF] = bDef;
			baseStats_[stats::SPATK] = bSpAtk;
			baseStats_[stats::SPDEF] = bSpDef;
			baseStats_[stats::SPE] = bSpe;
		}

		/*char *getSpecies() { return m_species; }
		int getType1() { return m_type1; }
		int getType2() { return m_type2; }
		int getBaseStat(int index) { return m_baseStats[index]; };
		int getAttackAmount() { return m_levelVector.size(); }
		int getLevel(int index) { return m_levelVector[index]; };
		Attack getAttack(int index) { return m_attackVector[index]; };*/
};


// Define an instance of a Pokemon species
class Pokemon{
private:
	std::string nickname_;
	int level_;
	
	int ivs_[6];
	int stats_[6];
	// int {stat increase/decrease}[6]
	int hp_;
	
	Species* species_;
	//vector<Attack> m_fattackVector;
	
public:
	Pokemon(Species* species, std::string nickname, int level){				
			species_ = species;
			nickname_ = nickname;
			level_ = level;
			
			/* set IVs
			for (int iii=0; iii<6; iii++){
				int randIV = rand()%32;
				m_IVs.push_back(randIV);
			}
			
			// set stats
			int HPNum = (m_IVs[0]+species.getBaseStat(0)+50)*m_level/50+10;
			m_stats.push_back(HPNum);
			for (int iii=1; iii<6; iii++){
				int statNum = (m_IVs[iii]+species.getBaseStat(iii))*m_level/50+5;
				m_stats.push_back(statNum);
			}
			
			// set battle specific stats
			for (int iii=0; iii<30; iii++){
				m_statAils.push_back(0);
			}
			m_currHP = m_stats[0];*/
			
			
			/* Set attacks for individual Pokemon
			int attackSlotCount=0;
			for (int iii=m_species.getAttackAmount()-1; iii>=0; iii--){
				if (m_level>=m_species.getLevel(iii)){
					m_fattackVector.push_back(m_species.getAttack(iii));
					attackSlotCount++;
				}
				if (attackSlotCount>4){ break; }
			}
			for (int iii=attackSlotCount; iii<4; iii++){
				m_fattackVector.push_back(Empty);
			}*/
	}
	
	Species getSpecies() { 
		return *species_; 
	}
	
	std::string getName() { 
		return nickname_; 
	}
	
	int getStat(int index) { 
		return stats_[index]; 
	}
	
	void setHp (int deltaHp) { 
		hp_ += deltaHp;
		if (hp_ <= 0){
			hp_ = 0;
		}
	}
	
	int getHp () { 
		return hp_;	
	}
	
	int getLevel() { 
		return level_; 
	}
	/*Attack getAttack(int index) { return m_fattackVector[index]; }
	int getStatAil(int index) { return m_statAils[index]; }
	void setStatAil(int index, int newValue) { m_statAils[index]=newValue; }
	void healStats() { m_currHP = m_stats[0]; }*/
};

int main(){
	Species sp = Species("Squirtle", types::WATER, types::GRASS,1,2,3,4,5,6);
	Pokemon p = Pokemon(&sp, "Hello", 12);
	std::cout << p.getLevel() << std::endl;
}
