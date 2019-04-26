#pragma once
#include <iostream>
#include "Math.h"
#include <vector>

/**
 * @brief Get the Chase User Movement Amount object
 * 
 * @param UserXPosition The horizontal position of the user
 * @param UserYPosition The vertical position of the user 
 * @param enemyXPosition The horizontal position of the enemy
 * @param enemyYPosition the vertical position of the enemy
 * @param enemySpeed The speed of the enemy
 * @param userPersonalBubble The hitbox of the user
 * @return std::vector<float> A list of movements to move by
 */
std::vector<float> getChaseUserMovementAmount(float UserXPosition, 
											  float UserYPosition, 
											  float enemyXPosition, 
											  float enemyYPosition, 
											  float enemySpeed = 4.f, 
											  float userPersonalBubble = 16.f) 
{
	std::vector<float> xyMovement;
	float XPositionDifference = UserXPosition - enemyXPosition;
	float YPositionDifference = UserYPosition - enemyYPosition;
	float totalMagnitudeDifference = (absoluteValue(XPositionDifference) + absoluteValue(YPositionDifference));
	float xMovementAmount = (enemySpeed * XPositionDifference) / totalMagnitudeDifference;
	xMovementAmount = MinByMagnitude(xMovementAmount, magnitudeSub(XPositionDifference, userPersonalBubble));
	float yMovementAmount = (enemySpeed * YPositionDifference) / totalMagnitudeDifference;
	yMovementAmount = MinByMagnitude(yMovementAmount, YPositionDifference);
	if (totalMagnitudeDifference < 250)
	{
		xyMovement.push_back(xMovementAmount);
		xyMovement.push_back(yMovementAmount);
	}
	else {
		xyMovement.push_back(0.f);
		xyMovement.push_back(0.f);
	}
	xyMovement.push_back(XPositionDifference);
	xyMovement.push_back(YPositionDifference);
	xyMovement.push_back(totalMagnitudeDifference);
	return xyMovement;
}
