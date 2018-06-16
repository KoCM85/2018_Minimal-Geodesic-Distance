#ifndef COORDINATE_H
#define COORDINATE_H

#include <vector>

// struct for save latitude and longtitude
struct coordinate
{
	double latitude;
	double longitude;
};

// alias
// set for storing points
using setCoordinates = std::vector<coordinate>;

#endif //COORDINATE_H