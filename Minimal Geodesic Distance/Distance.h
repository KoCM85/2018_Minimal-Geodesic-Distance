#ifndef DISTANCE_H
#define DISTANCE_H

#include "Coordinate.h"
#include <tuple>

class distance
{
	distance(const distance &) = delete;
	distance & operator=(const distance &) = delete;
public:
	distance() {}
	~distance() {}

	// Compute distance between two points. Based on the spherical law of cosines, commented haversine formula and Vincenty formula
	double computeDistance(const coordinate & startCoord, const coordinate & destCoord, double & radius);

	// Compute shortest distance between two points from two sets
	std::tuple<double, unsigned int, unsigned int> computeShorterDistance(const setCoordinates & setStartCoordinates, 
		const setCoordinates & setdestCoordinates, double & radius);

	// Outputs information for result of the function computeShorterDistance(const setCoordinates &, const setCoordinates &, double &)
	void info_computeShorterDistance(const setCoordinates & setStartCoordinates, const setCoordinates & setDestCoordinates,
		const std::tuple<double, unsigned int, unsigned int> & shorterDistance);
};

#endif //DISTANCE_H