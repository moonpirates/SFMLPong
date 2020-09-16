#include "Math.h"

float Math::GetVectorMagnitude(Vector2f vector)
{
	return std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
}

Vector2f Math::NormalizeVector(Vector2f vector)
{
	return vector / GetVectorMagnitude(vector);
}

Vector2f Math::FlattenVectorX(Vector2f vector)
{
	return Vector2f(0, vector.y);
}

Vector2f Math::FlattenVectorY(Vector2f vector)
{
	return Vector2f(vector.x, 0);
}
