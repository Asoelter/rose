#ifndef LINK_H
#define LINK_H

#include "attacker.h"


/**
 * @brief A class for drawing link from the best game
 * series of all time: The Legend of Zelda
 * 
 */
class Link : public Attacker 
{
	public:
		/**
		 * @brief Construct a new Link object
		 * 
		 * @param xPos 
		 * @param yPos 
		 */
		Link(float xPos = 0.0f, float yPos = 0.0f);

		/**
		 * @brief Destroy the Link object
		 * 
		 */
		~Link() = default;

		void moveUp()	 override;
		void moveRight() override;
		void moveDown()	 override;
		void moveLeft()	 override;
		
		virtual void attack()	 override;

		virtual void drawTo(sf::RenderWindow& window) override;
		virtual void damage() override;

	private:
		///////////////////
		//HelperFunctions//
		///////////////////

		/**
		 * @brief A helper function that moves the character in 
		 * The direction from the startingIndex to endingIndex
		 * 
		 * @param startingIndex The index of the first texture 
		 * in the progression of textures to display
		 * 
		 * @param endingIndex The index of the last texture 
		 * in the progression of textures to display  
		 */
		void genericMove(int startingIndex , int endingIndex);

		/**
		 * @brief A helper function that displays the attack 
		 * animations starting at startingIndex and ending at 
		 * endingIndex
		 * 
		 * @param startingIndex The index of the first texture 
		 * in the animation sequence
		 * 
		 * @param endingIndex The index of the last texture
		 * in the animation secquence 
		 */
		void genericAttack(int startingIndex, int endingIndex);

		/**
		 * @brief Displays the appropriate attack animation for
		 * when the character is facing towards the top of the
		 * screen 
		 * 
		 */
		void attackUp();

		/**
		 * @brief Displays the appropriate attack animation for 
		 * when the character is facing towards the right side 
		 * of the screen
		 * 
		 */
		void attackRight();

		/**
		 * @brief Displays the appropriate attack animation for 
		 * when the character is facing towards the bottom of 
		 * the screen
		 * 
		 */
		void attackDown();

		/**
		 * @brief Displays the appropriate attack animation for 
		 * when the character is facing towards the left side  
		 * of the screen
		 * 
		 */
		void attackLeft();

		/**
		 * @brief Loads all of the textures from the file into
		 * the texture_ array in the Actor base class
		 * 
		 * @param fileName The name of the file to load the 
		 * textures from 
		 */
		void loadTextures(const std::string&& fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is walking towards the bottom of the 
		 * screen
		 * 
		 * @param fileName The name of the file to load the
		 * textures from 
		 */
		void loadWalkDownTextures(const std::string& fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is walking towards the left side of the 
		 * screen
		 * 
		 * @param fileName The name of the file to load the 
		 * textures from 
		 */
		void loadWalkLeftTextures(const std::string& fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is walking towards the top of the screen
		 * 
		 * @param fileName The name of the file to load the 
		 * textures from 
		 */
		void loadWalkUpTextures(const std::string& fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is walking towards the right side of the 
		 * screen
		 * 
		 * @param fileName The name of the file to load the
		 * textures from 
		 */
		void loadWalkRightTextures(const std::string& fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is attacking and facing the bottom of the 
		 * screen
		 * 
		 * @param fileName The name of the file to load the
		 * textures from 
		 */
		void loadSwordDownTextures(const std::string& fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is attacking and facing the left side of  
		 * the screen
		 * 
		 * @param fileName The name of the file to load the
		 * textures from 
		 */
		void loadSwordLeftTextures(const std::string& fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is attacking and facing the top of  the 
		 * screen
		 * 
		 * @param fileName The name of the file to load the 
		 * textures from 
		 */
		void loadSwordUpTextures(const std::string& fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is attacking and facing the right side of  
		 * the screen
		 * 
		 * @param fileName The name of the file to load the 
		 * textures from 
		 */
		void loadSwordRightTextures(const std::string& fileName);

		/**
		 * @brief A debug function for printing useful info
		 * about the attack process. 
		 * 
		 */
		void printAttackDebugInfo() const;


		//////////////////
		//Helper Indices//
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

		bool 		isAttacking_;
};

#endif //LINK_H
