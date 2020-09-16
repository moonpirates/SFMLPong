#pragma once
#include <iostream>
#include <SFML\System\Vector2.hpp>

using namespace sf;

class Math
{
public:
	static float GetVectorMagnitude(Vector2f vector);
	static Vector2f NormalizeVector(Vector2f vector);
	static Vector2f FlattenVectorX(Vector2f vector);
	static Vector2f FlattenVectorY(Vector2f vector);
};

