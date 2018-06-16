#include "Distance.h"
#include "Converter.h"
#include "Coordinate.h"
#include <cmath>
#include <iostream>
#include <limits>

double distance::computeDistance(const coordinate & startCoord, const coordinate & destCoord, double & radius)
{
	converter & converter1 = converter::getInstance();
	double startLatRad = converter1.degreesToRadians(startCoord.latitude);
	double startLongRad = converter1.degreesToRadians(startCoord.longitude);
	double destLatRad = converter1.degreesToRadians(destCoord.latitude);
	double destLongRad = converter1.degreesToRadians(destCoord.longitude);

	/* Based on the spherical law of cosines */
	return std::acos(std::sin(startLatRad) * sin(destLatRad) +
		std::cos(startLatRad) * std::cos(destLatRad) * std::cos(startLongRad - destLongRad)) * radius;

	/* Vincenty formula */
	//return std::atan(std::sqrt(std::pow(std::cos(destLatRad) * std::sin(startLongRad - destLongRad), 2) + 
	//	std::pow(std::cos(startLatRad) * std::sin(destLatRad) - 
	//		std::sin(startLatRad) * std::cos(destLatRad) * std::cos(startLongRad - destLongRad), 2))/
	//		(std::sin(startLatRad) * std::sin(destLatRad) + std::cos(startLatRad) * std::cos(destLatRad) * 
	//			std::cos(startLongRad - destLongRad))) * radius;


	/* Haversine formula */
	//return 2 * std::asin(std::sqrt(std::pow(std::sin((startLatRad - destLatRad) / 2), 2) +
	//	std::cos(startLatRad) * std::cos(destLatRad) * std::pow(std::sin((startLongRad - destLongRad) / 2), 2))) * radius;
}

std::tuple<double, unsigned int, unsigned int> distance::computeShorterDistance(const setCoordinates & setStartCoordinates, 
	const setCoordinates & setDestCoordinates, double & radius)
{
	std::tuple<double, unsigned int, unsigned int> shorterDistance(std::numeric_limits<double>::max(), 0, 0);

	if (setStartCoordinates.size() == 0 || setDestCoordinates.size() == 0)
	{
		return shorterDistance;
	}

	for (unsigned int index_setStartCoordinates = 0; index_setStartCoordinates < setStartCoordinates.size(); ++index_setStartCoordinates)
	{
		for (unsigned int index_setDestCoordinates = 0; index_setDestCoordinates < setDestCoordinates.size(); ++index_setDestCoordinates)
		{
			double tempDistance = computeDistance(setStartCoordinates[index_setStartCoordinates], setDestCoordinates[index_setDestCoordinates], radius);

			if (tempDistance < std::get<0>(shorterDistance))
			{
				std::get<0>(shorterDistance) = tempDistance;
				std::get<1>(shorterDistance) = index_setStartCoordinates;
				std::get<2>(shorterDistance) = index_setDestCoordinates;
			}
		}
	}
	return shorterDistance;
}

void distance::info_computeShorterDistance(const setCoordinates & setStartCoordinates, const setCoordinates & setDestCoordinates,
	const std::tuple<double, unsigned int, unsigned int> & shorterDistance)
{
	if (std::get<0>(shorterDistance) == std::numeric_limits<double>::max())
		std::cout << "Route does not exist \n";
	else
	{
		std::cout << "Shorter distance: " << std::get<0>(shorterDistance)
			<< " Points: (" << setStartCoordinates[std::get<1>(shorterDistance)].latitude
			<< ", " << setStartCoordinates[std::get<1>(shorterDistance)].longitude << ") ("
			<< setDestCoordinates[std::get<2>(shorterDistance)].latitude << ", "
			<< setDestCoordinates[std::get<2>(shorterDistance)].longitude << ") \n";
	}
}