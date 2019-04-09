#ifndef LINK_H
#define LINK_H

#include "attacker.h"

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
		
		static constexpr int startOfWalkDown		= 0;	/*<The first index of the first texture in the walk down  	animation*/
		static constexpr int startOfWalkLeft		= 8;	/*<The first index of the first texture in the walk left  	animation*/
		static constexpr int startOfWalkUp			= 14;	/*<The first index of the first texture in the walk up    	animation*/
		static constexpr int startOfWalkRight		= 22;	/*<The first index of the first texture in the walk right 	animation*/

		static constexpr int startOfSwordDown		= 28;	/*<The first index of the first texture in the attack down  animation*/
		static constexpr int startOfSwordLeft		= 34;	/*<The first index of the first texture in the attack left  animation*/
		static constexpr int startOfSwordUp			= 39;	/*<The first index of the first texture in the attack up    animation*/
		static constexpr int startOfSwordRight		= 44;	/*<The first index of the first texture in the attack right animation*/

		static constexpr int endOfWalkDown			= 7;	/*<The last index of the first texture in the walk down 	animation*/
		static constexpr int endOfWalkLeft			= 13;	/*<The last index of the first texture in the walk left	 	animation*/
		static constexpr int endOfWalkUp			= 21;	/*<The last index of the first texture in the walk up 		animation*/
		static constexpr int endOfWalkRight			= 27;	/*<The last index of the first texture in the walk right 	animation*/

		static constexpr int endOfSwordDown			= 33;	/*<The last index of the first texture in the attack down 	animation*/
		static constexpr int endOfSwordLeft			= 38;	/*<The last index of the first texture in the attack left 	animation*/
		static constexpr int endOfSwordUp			= 43;	/*<The last index of the first texture in the attack up 	animation*/
		static constexpr int endOfSwordRight		= 48;	/*<The last index of the first texture in the attack right 	animation*/

		static constexpr int downIdle				= 0;	/*<The index of the down  idle animation*/
		static constexpr int leftIdle				= 10;	/*<The index of the left  idle animation*/
		static constexpr int upIdle					= 17;	/*<The index of the up	  idle animation*/
		static constexpr int rightIdle				= 25;	/*<The index of the right idle animation*/

		////////////////
		//Private data//
		////////////////

		Orientation currentOrientation_;
		bool 		isAttacking_;
};

#endif //LINK_H
