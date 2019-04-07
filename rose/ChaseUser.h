#pragma once
#include <iostream>
#include "Math.h"
#include <vector>

std::vector<float> getChaseUserMovementAmount(float UserXPosition, float UserYPosition, float enemyXPosition, float enemyYPosition, float enemySpeed = 4.f, float userPersonalBubble = 16.f) {
	std::vector<float> xyMovement;
	float XPositionDifference = UserXPosition - enemyXPosition;
	float YPositionDifference = UserYPosition - enemyYPosition;
	float totalMagnitudeDifference = (absoluteValue(XPositionDifference) + absoluteValue(YPositionDifference));
	float xMovementAmount = (enemySpeed * XPositionDifference) / totalMagnitudeDifference;
	xMovementAmount = MinByMagnitude(xMovementAmount, magnitudeSub(XPositionDifference, userPersonalBubble));
	float yMovementAmount = (enemySpeed * YPositionDifference) / totalMagnitudeDifference;
	yMovementAmount = MinByMagnitude(yMovementAmount, YPositionDifference);
	xyMovement.push_back(xMovementAmount);
	xyMovement.push_back(yMovementAmount);
	xyMovement.push_back(XPositionDifference);
	xyMovement.push_back(YPositionDifference);
	xyMovement.push_back(totalMagnitudeDifference);
	return xyMovement;
}
