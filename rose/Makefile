CXX_FLAGS   = clang++ -std=c++17 -O2 -g -Wall -Wextra -pedantic -Wno-unknown-pragmas
HEADERS     = actor.h attacker.h Cowboy.h tile.h MainCharacter.h CharacterStats.h link.h map.h Skeleton.h Enemy.h MainCharacterTextures.h log.h
OBJECTS     = main.o actor.o attacker.o Cowboy.o tile.o MainCharacter.o CharacterStats.o link.o map.o Skeleton.o Enemy.o MainCharacterTextures.o log.o

main: $(OBJECTS)
	$(CXX_FLAGS) $(OBJECTS) -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Math.h ChaseUser.h $(HEADERS)
	$(CXX_FLAGS) -c main.cpp                             

actor.o: actor.h actor.cpp
	$(CXX_FLAGS) -c actor.cpp

attacker.o: attacker.h attacker.cpp
	$(CXX_FLAGS) -c attacker.cpp

Cowboy.o: Cowboy.h Cowboy.cpp
	$(CXX_FLAGS) -c Cowboy.cpp 

tile.o: tile.h tile.cpp     
	$(CXX_FLAGS) -c tile.cpp

MainCharacter.o: MainCharacter.h MainCharacter.cpp
	$(CXX_FLAGS) -c MainCharacter.cpp

CharacterStats.o: CharacterStats.h CharacterStats.cpp
	$(CXX_FLAGS) -c CharacterStats.cpp             

link.o: link.h link.cpp
	$(CXX_FLAGS) -c link.cpp             

map.o: map.h map.cpp
	$(CXX_FLAGS) -c map.cpp             

Skeleton.o: Skeleton.h Skeleton.cpp
	$(CXX_FLAGS) -c Skeleton.cpp             

Enemy.o: Enemy.h Enemy.cpp
	$(CXX_FLAGS) -c Enemy.cpp             

MainCharacterTextures.o: MainCharacterTextures.h MainCharacterTextures.cpp
	$(CXX_FLAGS) -c MainCharacterTextures.cpp

log.o: log.h log.cpp
	$(CXX_FLAGS) -c log.cpp

clean: 
	rm *.o main
