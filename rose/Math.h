#pragma once

/**
 * @brief 
 * 
 * @param valueToBeForcedPositive 
 * @return float 
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
 * @brief 
 * 
 * @param valueToBeForcedPositive 
 * @return int 
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
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return int 
 */
int Max(int num1, int num2) {
	if (num1>num2)
	{
		return num1;
	}
	return num2;
}

/**
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return float 
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
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return int 
 */
int MaxByMagnitude(int num1, int num2) {
	if (absoluteValue(num1) > absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

/**
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return float 
 */
float MaxByMagnitude(float num1, float num2) {
	if (absoluteValue(num1) > absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

/**
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return int 
 */
int Min(int num1, int num2) {
	if (num1 < num2)
	{
		return num1;
	}
	return num2;
}

/**
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return float 
 */
float Min(float num1, float num2) {
	if (num1 < num2)
	{
		return num1;
	}
	return num2;
}

/**
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return int 
 */
int MinByMagnitude(int num1, int num2) {
	if (absoluteValue(num1) < absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

/**
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return float 
 */
float MinByMagnitude(float num1, float num2) {
	if (absoluteValue(num1) < absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

/**
 * @brief 
 * 
 * @param valueToBeAddedTo 
 * @param valueToAdd 
 * @return int 
 */
int magnitudeAdd(int valueToBeAddedTo, int valueToAdd) {
	if (valueToBeAddedTo >= 0)
	{
		return Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0);
	}
	return -Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0);
}

/**
 * @brief 
 * 
 * @param valueToBeAddedTo 
 * @param valueToAdd 
 * @return float 
 */
float magnitudeAdd(float valueToBeAddedTo, float valueToAdd) {
	if (valueToBeAddedTo >= 0)
	{
		return Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0.f);
	}
	return -Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0.f);
}

/**
 * @brief 
 * 
 * @param valueToBeSubedTo 
 * @param valueToSub 
 * @return int 
 */
int magnitudeSub(int valueToBeSubedTo, int valueToSub) {
	if (valueToBeSubedTo >= 0)
	{
		return Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0);
	}
	return -Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0);
}

/**
 * @brief 
 * 
 * @param valueToBeSubedTo 
 * @param valueToSub 
 * @return float 
 */
float magnitudeSub(float valueToBeSubedTo, float valueToSub) {
	if (valueToBeSubedTo >= 0)
	{
		return Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0.f);
	}
	return -Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0.f);
}

