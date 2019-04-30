#include "catch.hpp"
#include "actor.h"
#include "attacker.h"
#include "Enemy.h"
#include "Skeleton.h"
#include "link.h"

TEST_CASE("Test Skeleton")
{
	int skeletonXPos = 10;
	int skeletonYPos = 12;
	Skeleton testSkeleton(skeletonXPos, skeletonYPos);
	int linkXPos = 224;
	int linkYPos = 123;
	Rose::Character::Link testLink(linkXPos, linkYPos);

	SECTION("Test Skeleton only methods") {
		REQUIRE(testSkeleton.xPos() == skeletonXPos);
		REQUIRE(testSkeleton.yPos() == skeletonYPos);
		SECTION("Move right!") {
			testSkeleton.moveRight();
			skeletonXPos += 4;
			REQUIRE(testSkeleton.xPos() == skeletonXPos);
			REQUIRE(testSkeleton.yPos() == skeletonYPos);
		}

		SECTION("Move left!") {
			testSkeleton.moveLeft();
			skeletonXPos -= 4;
			REQUIRE(testSkeleton.xPos() == skeletonXPos);
			REQUIRE(testSkeleton.yPos() == skeletonYPos);
		}

		SECTION("Move down!") {
			testSkeleton.moveDown();
			skeletonYPos += 4;
			REQUIRE(testSkeleton.xPos() == skeletonXPos);
			REQUIRE(testSkeleton.yPos() == skeletonYPos);
		}

		SECTION("Move up!") {
			testSkeleton.moveUp();
			skeletonYPos -= 4;
			REQUIRE(testSkeleton.xPos() == skeletonXPos);
			REQUIRE(testSkeleton.yPos() == skeletonYPos);
		}

	}


	SECTION("Test Link only methods") {
		REQUIRE(testLink.xPos() == linkXPos);
		REQUIRE(testLink.yPos() == linkYPos);
		SECTION("Move right!") {
			testLink.moveRight();
			linkXPos += 4;
			REQUIRE(testLink.xPos() == linkXPos);
			REQUIRE(testLink.yPos() == linkYPos);
		}

		SECTION("Move left!") {
			testLink.moveLeft();
			linkXPos -= 4;
			REQUIRE(testLink.xPos() == linkXPos);
			REQUIRE(testLink.yPos() == linkYPos);
		}

		SECTION("Move down!") {
			testLink.moveDown();
			linkYPos += 4;
			REQUIRE(testLink.xPos() == linkXPos);
			REQUIRE(testLink.yPos() == linkYPos);
		}

		SECTION("Move up!") {
			testLink.moveUp();
			linkYPos -= 4;
			REQUIRE(testLink.xPos() == linkXPos);
			REQUIRE(testLink.yPos() == linkYPos);
		}

	}

	

}