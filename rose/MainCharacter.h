//#ifndef MAIN_CHARACTER_H
//#define MAIN_CHARACTER_H
//
//#include <iostream>
//#include "CharacterStats.h"
//#include "StateOfCharacter.h"
//#include <SFML/Graphics.hpp>
//#include <vector>
//#include "actor.h"
//
//class MainCharacter 
//{
//	int animationPicNumber;
//	bool dying;
//	CharacterStats mainCharacter;
//	StateOfCharacter currentCharacterState;
//	StateOfCharacter nextCharacterState;
//	std::vector<sf::Texture> textures;
//
//public:
//
//	/**
//	 * @brief Construct a new Main Character object
//	 * 
//	 */
//	MainCharacter(std::vector<sf::Texture> &texturesList);
//
//
//	/**
//	 * @brief Draws the character to the window
//	 * 
//	 * @param window The window to be drawn to 
//	 */
//	void drawCharacter(sf::RenderWindow& window);
//
//	/**
//	 * @brief The horizontal position of the character
//	 * 
//	 * @return float The Horizontal position of 
//	 * the character in pixels
//	 */
//	float getXLocation();
//
//	/**
//	 * @brief The vertical position of the character
//	 * 
//	 * @return float The vertical position of 
//	 * the character in pixels
//	 */
//	float getYLocation();
//
//	/**
//	 * @brief Moves the character right
//	 * 
//	 * @param amount The number of pixels 
//	 * to move by 
//	 */
//	void moveRight(float amount);
//
//	/**
//	 * @brief Moves the character left
//	 * 
//	 * @param amount The number of pixels 
//	 * to move by 
//	 */
//	void moveLeft(float amount);
//
//	/**
//	 * @brief Moves the character up
//	 * 
//	 * @param amount The number of pixels 
//	 * to move by 
//	 */
//	void moveUp(float amount);
//
//	/**
//	 * @brief Moves the character down
//	 * 
//	 * @param amount The number of pixels 
//	 * to move by 
//	 */
//	void moveDown(float amount);
//
//	/**
//	 * @brief Chases the user 
//	 * 
//	 * @param UserXPosition The horizontal position of the user 
//	 * 
//	 * @param UserYPosition The vertical position of the user 
//	 */
//	void chaseUser(float UserXPosition, float UserYPosition);
//
//	/**
//	 * @brief Set the State object
//	 * 
//	 * @param state The state to be set to 
//	 */
//	void setState(StateOfCharacter state);
//};
//
//#endif //MAIN_CHARACTER_H



#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "attacker.h"
#include "MainCharacterTextures.h"


/**
 * @brief A class for drawing maincharacter
 *
 */
namespace Rose::Character
{
	class MainCharacter : public Attacker
	{
	public:
		/**
		 * @brief Construct a new MainCharacter object
		 *
		 * @param xPos
		 * @param yPos
		 */
		MainCharacter(float xPos = 0.0f, float yPos = 0.0f);

		/**
		 * @brief Destroy the MainCharacter object
		 *
		 */
		~MainCharacter() = default;

		void moveUp()	 override;
		void moveRight() override;
		void moveDown()	 override;
		void moveLeft()	 override;

		void runTests();
		void testMoveUp();
		void testMoveRight();
		void testMoveDown();
		void testMoveLeft();

		int getHealth();
		float getXPos();
		float getYPos();
		sf::Vector2f MainCharacter::getPos();

		virtual void attack()	 override;

		virtual void drawTo(sf::RenderWindow& window) override;
		virtual void damage() override;

	private:
		float xOffset;
		float yOffset;
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
		void genericMove();

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
		void genericAttack();

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
		void loadTextures(const std::string fileName);

		/**
		 * @brief Loads the approprate textures for when the
		 * character is walking towards the bottom of the
		 * screen
		 *
		 * @param fileName The name of the file to load the
		 * textures from
		 */
		void printAttackDebugInfo() const;

		void animate();

		////////////////
		//Private data//
		////////////////

		static std::vector<sf::Texture> textures_;
		static bool						loaded_;
		bool							isAttacking_;
		int animationPicNumber;
	};
}
#endif //MAINCHARACTER_H

