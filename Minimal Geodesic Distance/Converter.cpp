#include "Converter.h"

#define pi 3.14159265 // PI

double converter::degreesToRadians(const double & degrees)
{
	return (degrees * pi) / 180;
}

double converter::degreesMinutesSecondsToDegrees(const double & degrees, const double & minutes, const double & seconds, const char & hemisphere)
{
	if (hemisphere == 's' || hemisphere == 'w' || hemisphere == 'S' || hemisphere == 'W')
		return -1 * (degrees + minutes / 60 + seconds / 3600);
	else
		return degrees + minutes / 60 + seconds / 3600;
}

converter & converter::getInstance()
{
	static converter instance;
	return instance;
}