#pragma once
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

int Max(int num1, int num2) {
	if (num1>num2)
	{
		return num1;
	}
	return num2;
}

float Max(float num1, float num2) {
	if (num1 > num2)
	{
		return num1;
	}
	return num2;
}

#pragma once
int MaxByMagnitude(int num1, int num2) {
	if (absoluteValue(num1) > absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

float MaxByMagnitude(float num1, float num2) {
	if (absoluteValue(num1) > absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

int Min(int num1, int num2) {
	if (num1 < num2)
	{
		return num1;
	}
	return num2;
}

float Min(float num1, float num2) {
	if (num1 < num2)
	{
		return num1;
	}
	return num2;
}

int MinByMagnitude(int num1, int num2) {
	if (absoluteValue(num1) < absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

float MinByMagnitude(float num1, float num2) {
	if (absoluteValue(num1) < absoluteValue(num2))
	{
		return num1;
	}
	return num2;
}

int magnitudeAdd(int valueToBeAddedTo, int valueToAdd) {
	if (valueToBeAddedTo >= 0)
	{
		return Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0);
	}
	return -Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0);
}

float magnitudeAdd(float valueToBeAddedTo, float valueToAdd) {
	if (valueToBeAddedTo >= 0)
	{
		return Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0.f);
	}
	return -Max(absoluteValue(valueToBeAddedTo) + absoluteValue(valueToAdd), 0.f);
}

int magnitudeSub(int valueToBeSubedTo, int valueToSub) {
	if (valueToBeSubedTo >= 0)
	{
		return Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0);
	}
	return -Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0);
}

float magnitudeSub(float valueToBeSubedTo, float valueToSub) {
	if (valueToBeSubedTo >= 0)
	{
		return Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0.f);
	}
	return -Max(absoluteValue(valueToBeSubedTo) - absoluteValue(valueToSub), 0.f);
}

