#include <Pokemon.h>

int main(){
	Species sp = Species("Squirtle", types::WATER, types::GRASS,1,2,3,4,5,6);
	Pokemon p = Pokemon(&sp, "Hello", 12);
	std::cout << p.getLevel() << std::endl;
}
