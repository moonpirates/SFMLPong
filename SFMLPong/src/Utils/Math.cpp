#include "Math.h"

float Utils::Math::GetVectorMagnitude(Vector2f vector)
{
	return std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
}

Vector2f Utils::Math::NormalizeVector(Vector2f vector)
{
	return vector / GetVectorMagnitude(vector);
}

Vector2f Utils::Math::FlattenVectorX(Vector2f vector)
{
	return Vector2f(0, vector.y);
}

Vector2f Utils::Math::FlattenVectorY(Vector2f vector)
{
	return Vector2f(vector.x, 0);
}
