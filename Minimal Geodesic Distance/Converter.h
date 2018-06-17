#ifndef CONVERTER_H
#define CONVERTER_H

#define pi 3.14159265 // PI

// Singleton
class converter
{
	converter() {}
	converter(const converter &) = delete;
	converter & operator=(const converter &) = delete;
public:
	// Convert degrees to radians
	double degreesToRadians(const double & degrees);

	// Convert degrees minutes seconds to degrees
	double degreesMinutesSecondsToDegrees(const double & degrees, const double & minutes, const double & seconds, const char & hemisphere);

	// return instance of class
	static converter & getInstance();
};

#endif //CONVERTER_H