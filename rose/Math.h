#ifndef MATH_H
#define MATH_H

/**
 * @brief Returns the absolute value of the parameter
 * 
 * @param valueToBeForcedPositive The value who's absolute value is returned
 * 
 * @return float The absolute value of the parameter 
 */
float absoluteValue(float valueToBeForcedPositive) {
	if (valueToBeForcedPositive >= 0)
	{
		return valueToBeForcedPositive;
	}
	else
	{
		return -1 * valueToBeForcedPositive;
	}
}

/**
 * @brief Returns the absolute value of the parameter
 * 
 * @param valueToBeForcedPositive The value who's absolute value is returned
 * 
 * @return int The absolute value of the parameter
 */
int absoluteValue(int valueToBeForcedPositive) {
	if (valueToBeForcedPositive >= 0)
	{
		return valueToBeForcedPositive;
	}
	else
	{
		return -1 * valueToBeForcedPositive;
	}
}

/**
 * @brief Returns the value of the parameter
 * with the highest value
 * 
 * @param num1 The first parameter to be tested
 * for having the max value
 * 
 * @param num2 The second parameter to be tested 
 * for having the max value
 *  
 * @return int The maximum value of num1 and num2 
 */
int Max(int num1, int num2) {
	if (num1>num2)
	{
		return num1;
	}
	return num2;
}

/**
 * @brief Returns the value of the parameter
 * with the highest value
 * 
 * @param num1 The first parameter to be tested
 * for having the max value
 * 
 * @param num2 The second parameter to be tested 
 * for having the max value
 *  
 * @return int The maximum value of num1 and num2 
 */
float Max(float num1, float num2) {
	if (num1 > num2)
	{
		return num1;
	}
	return num2;
}

#pragma once

/**
 * @brief Returns the value with the highest absolute
 * value
 * 
 * @param num1 The first parameter to be tested
 * for having the max value
 * 
 * @param num2 The second parameter to be tested
 * for having the max value
 * 
 * @return int The max of the absolute value 
 * of num1 and num2
 */
int MaxByMagnitude(int num1, int num2) {
	if (absoluteValue(num1) > absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

/**
 * @brief Returns the value with the highest absolute
 * value
 * 
 * @param num1 The first parameter to be tested
 * for having the max value
 * 
 * @param num2 The second parameter to be tested
 * for having the max value
 * 
 * @return int The max of the absolute value 
 * of num1 and num2
 */
float MaxByMagnitude(float num1, float num2) {
	if (absoluteValue(num1) > absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

/**
 * @brief Returns the minimum value of 
 * num1 and num2
 * 
 * @param num1 The first parameter to be tested for
 * having the minimum value
 * 
 * @param num2 num1 The second parameter to be tested for
 * having the minimum value
 * 
 * @return int The minimum value of num1 and num2
 */
int Min(int num1, int num2) {
	if (num1 < num2)
	{
		return num1;
	}
	return num2;
}

/**
 * @brief Returns the minimum value of 
 * num1 and num2
 * 
 * @param num1 The first parameter to be tested for
 * having the minimum value
 * 
 * @param num2 num1 The second parameter to be tested for
 * having the minimum value
 * 
 * @return int The minimum value of num1 and num2
 */
float Min(float num1, float num2) {
	if (num1 < num2)
	{
		return num1;
	}
	return num2;
}

/**
 * @brief Returns the value with the lowest absolute
 * value
 * 
 * @param num1 The first parameter to be tested
 * for having the min value
 * 
 * @param num2 The second parameter to be tested
 * for having the min value
 * 
 * @return int The minimum of the absolute value 
 * of num1 and num2
 */
int MinByMagnitude(int num1, int num2) {
	if (absoluteValue(num1) < absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

/**
 * @brief Returns the value with the lowest absolute
 * value
 * 
 * @param num1 The first parameter to be tested
 * for having the min value
 * 
 * @param num2 The second parameter to be tested
 * for having the min value
 * 
 * @return int The minimum of the absolute value 
 * of num1 and num2
 */
float MinByMagnitude(float num1, float num2) {
	if (absoluteValue(num1) < absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

/**
 * @brief Returns the sum of the absolute values of
 * the two parameters
 * 
 * @param valueToBeAddedTo The value who's absolute value 
 * gets added to
 * 
 * @param valueToAdd The value that is added to the first
 * parameter
 * 
 * @return int The summation of the absolute value of 
 * the two parameters 
 */
int magnitudeAdd(int valueToBeAddedTo, int valueToAdd) {
	if (valueToBeAddedTo >= 0)
	{
		return Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0);
	}
	return -Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0);
}

/**
 * @brief Returns the sum of the absolute values of
 * the two parameters
 * 
 * @param valueToBeAddedTo The value who's absolute value 
 * gets added to
 * 
 * @param valueToAdd The value that is added to the first
 * parameter
 * 
 * @return int The summation of the absolute value of 
 * the two parameters 
 */
float magnitudeAdd(float valueToBeAddedTo, float valueToAdd) {
	if (valueToBeAddedTo >= 0)
	{
		return Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0.f);
	}
	return -Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0.f);
}

/**
 * @brief Returns the difference of the absolute values of
 * the two parameters
 * 
 * @param valueToBeAddedTo The value who's absolute value 
 * gets subtracted from 
 * 
 * @param valueToAdd The value that is subtacted from the first
 * parameter
 * 
 * @return int The difference of the absolute value of 
 * the two parameters 
 */
int magnitudeSub(int valueToBeSubedTo, int valueToSub) {
	if (valueToBeSubedTo >= 0)
	{
		return Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0);
	}
	return -Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0);
}

/**
 * @brief Returns the difference of the absolute values of
 * the two parameters
 * 
 * @param valueToBeAddedTo The value who's absolute value 
 * gets subtracted from 
 * 
 * @param valueToAdd The value that is subtacted from the first
 * parameter
 * 
 * @return int The difference of the absolute value of 
 * the two parameters 
 */
float magnitudeSub(float valueToBeSubedTo, float valueToSub) {
	if (valueToBeSubedTo >= 0)
	{
		return Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0.f);
	}
	return -Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0.f);
}

#endif //MATH_H
