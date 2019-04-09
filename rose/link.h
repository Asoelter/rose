#ifndef LINK_H
#define LINK_H

#include "attacker.h"

class Link : public Attacker 
{
	public:
		Link(float xPos = 0.0f, float yPos = 0.0f);

		void moveUp();
		void moveRight();
		void moveDown();
		void moveLeft();
		
		void attack();

		virtual void drawTo(sf::RenderWindow& window);

	private:
		///////////////////
		//HelperFunctions//
		///////////////////
		void genericMove(int startingIndex , int endingIndex);

		void genericAttack(int startingIndex, int endingIndex);
		void attackUp();
		void attackRight();
		void attackDown();
		void attackLeft();

		void loadTextures(const std::string&& fileName);
		void loadWalkDownTextures(const std::string& fileName);
		void loadWalkLeftTextures(const std::string& fileName);
		void loadWalkUpTextures(const std::string& fileName);
		void loadWalkRightTextures(const std::string& fileName);
		void loadSwordDownTextures(const std::string& fileName);
		void loadSwordLeftTextures(const std::string& fileName);
		void loadSwordUpTextures(const std::string& fileName);
		void loadSwordRightTextures(const std::string& fileName);

		void printAttackDebugInfo() const;


		//////////////////
		//Helper Indexes//
		//////////////////
		static constexpr int startOfWalkDown		= 0;
		static constexpr int startOfWalkLeft		= 8;
		static constexpr int startOfWalkUp			= 14;
		static constexpr int startOfWalkRight		= 22;

		static constexpr int startOfSwordDown		= 28;
		static constexpr int startOfSwordLeft		= 34;
		static constexpr int startOfSwordUp			= 39;
		static constexpr int startOfSwordRight		= 44;

		static constexpr int endOfWalkDown			= 7;
		static constexpr int endOfWalkLeft			= 13;
		static constexpr int endOfWalkUp			= 21;
		static constexpr int endOfWalkRight			= 27;

		static constexpr int endOfSwordDown			= 33;
		static constexpr int endOfSwordLeft			= 38;
		static constexpr int endOfSwordUp			= 43;
		static constexpr int endOfSwordRight		= 48;

		static constexpr int downIdle				= 0;
		static constexpr int leftIdle				= 10;
		static constexpr int upIdle					= 17;
		static constexpr int rightIdle				= 25;

		////////////////
		//Private data//
		////////////////

		Orientation currentOrientation_;
		bool isAttacking_;
};

#endif //LINK_H
