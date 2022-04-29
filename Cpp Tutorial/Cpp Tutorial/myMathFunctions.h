#pragma once

int add(int a, int b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

int substraction(int a, int b)
{
	return a - b;
}

int multiplication(int a, int b)
{
	return a * b;
}

float division(float a, float b)
{
	if (b == 0) return -1.f;

	return a / b;
}

int division(int a, int b)
{
	if (b == 0) return -1;

	return a / b;
}
