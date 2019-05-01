#include "catch.hpp"
#include "actor.h"
#include "attacker.h"
#include "Enemy.h"
#include "Skeleton.h"
#include "link.h"
#include <iostream>



	SCENARIO("Test Skeleton only methods") {

		int skeletonXPos = 10;
		int skeletonYPos = 12;
		Skeleton testSkeleton(skeletonXPos, skeletonYPos);
		int linkXPos = 224;
		int linkYPos = 123;
		Rose::Character::Link testLink(linkXPos, linkYPos);
		REQUIRE(testSkeleton.xPos() == skeletonXPos);
		REQUIRE(testSkeleton.yPos() == skeletonYPos);
		GIVEN("Move right!") {
			testSkeleton.moveRight();
			skeletonXPos += 4;
			REQUIRE(testSkeleton.xPos() == skeletonXPos);
			REQUIRE(testSkeleton.yPos() == skeletonYPos);
		}

		GIVEN("Move left!") {
			testSkeleton.moveLeft();
			skeletonXPos -= 4;
			REQUIRE(testSkeleton.xPos() == skeletonXPos);
			REQUIRE(testSkeleton.yPos() == skeletonYPos);
		}

		GIVEN("Move down!") {
			testSkeleton.moveDown();
			skeletonYPos += 4;
			REQUIRE(testSkeleton.xPos() == skeletonXPos);
			REQUIRE(testSkeleton.yPos() == skeletonYPos);
		}

		GIVEN("Move up!") {
			testSkeleton.moveUp();
			skeletonYPos -= 4;
			REQUIRE(testSkeleton.xPos() == skeletonXPos);
			REQUIRE(testSkeleton.yPos() == skeletonYPos);
		}

		GIVEN("GetHealth!") {
			REQUIRE(testSkeleton.getHealth() == 1);
			WHEN("Damage!") {
				testSkeleton.damage();
				REQUIRE(testSkeleton.getHealth() == 0);
			}
		}

	}


	SCENARIO("Test Link only methods") {

		int skeletonXPos = 10;
		int skeletonYPos = 12;
		Skeleton testSkeleton(skeletonXPos, skeletonYPos);
		int linkXPos = 224;
		int linkYPos = 123;
		Rose::Character::Link testLink(linkXPos, linkYPos);
		REQUIRE(testLink.xPos() == testLink.getXPos());
		REQUIRE(testLink.yPos() == testLink.getYPos());
		REQUIRE(testLink.xPos() == linkXPos);
		REQUIRE(testLink.yPos() == linkYPos);
		GIVEN("Move right!") {
			testLink.moveRight();
			linkXPos += 4;
			REQUIRE(testLink.xPos() == linkXPos);
			REQUIRE(testLink.yPos() == linkYPos);
		}

		GIVEN("Move left!") {
			testLink.moveLeft();
			linkXPos -= 4;
			REQUIRE(testLink.xPos() == linkXPos);
			REQUIRE(testLink.yPos() == linkYPos);
		}

		GIVEN("Move down!") {
			testLink.moveDown();
			linkYPos += 4;
			REQUIRE(testLink.xPos() == linkXPos);
			REQUIRE(testLink.yPos() == linkYPos);
		}

		GIVEN("Move up!") {
			testLink.moveUp();
			linkYPos -= 4;
			REQUIRE(testLink.xPos() == linkXPos);
			REQUIRE(testLink.yPos() == linkYPos);
		}

		GIVEN("GetHealth!") {
			REQUIRE(testLink.getHealth() == 1);
			WHEN("Damage!") {
				testLink.damage();
				REQUIRE(testLink.getHealth() == 0);
			}
		}

	}

	SCENARIO("Test Link and Skeleton interaction methods") {

		int skeletonXPos = 10;
		int skeletonYPos = 12;
		Skeleton testSkeleton(skeletonXPos, skeletonYPos);
		int linkXPos = 224;
		int linkYPos = 123;
		Rose::Character::Link testLink(linkXPos, linkYPos);
		GIVEN("Link and Skeleton have moved as closely as possible") {
			float previousXPos = testSkeleton.xPos();
			float previousYPos = testSkeleton.yPos();
			int numberOfIterations = 0;
			while (((previousXPos != testSkeleton.xPos()) || (previousXPos != testSkeleton.xPos()) && (numberOfIterations < 100)))
			{
				float previousXPos = testSkeleton.xPos();
				float previousYPos = testSkeleton.yPos();
				testSkeleton.chasePlayer(testLink.getXPos(), testLink.getYPos());
				numberOfIterations++;
			}
			REQUIRE(numberOfIterations < 100);//Tests to see if the chasePlayer worked within 100 iterations
			WHEN("Test skeleton attacks") {
				REQUIRE(testLink.getHealth() == 1);
				testSkeleton.attack();
				REQUIRE(testLink.getHealth() == 0);
			}

			WHEN("Test link attacks") {
				REQUIRE(testSkeleton.getHealth() == 1);
				testLink.attack();
				REQUIRE(testSkeleton.getHealth() == 0);
			}
		}
		
		std::cout << "Done with the tests\n";
	}
