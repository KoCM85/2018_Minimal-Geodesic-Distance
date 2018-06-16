#include "Converter.h"
#include "Distance.h"
#include "Coordinate.h"
#include "Tests.h"
#include <iostream>
#include <algorithm>

// if defined, runs testing
// if not defined, runs all below testing
#define testing

int main()
{
#ifdef testing

	test & test1 = test::getInstance();
	test1.testAll();

	std::cin.get();
	return 0;

#endif // testing

	double radius = 6371.008; // 6371.008 Earth radius
	distance distance1;

	setCoordinates setPoints1;
	setCoordinates setPoints2;
	std::tuple<double, unsigned int, unsigned int> shortDistance1;

	setCoordinates setPoints3 = { { -40.71277, 177.00583 },{ 1.71277, 74.00583 },{ 40.71277, 74.00583 } };
	setCoordinates setPoints4 = { { 40.71277, 77.00583 },{ 4.71277, 72.00583 } };
	std::tuple<double, unsigned int, unsigned int> shortDistance2;

	setCoordinates setPoints5;
	setCoordinates setPoints6 = { { 40.71277, 77.00583 },{ 4.71277, 72.00583 } };
	std::tuple<double, unsigned int, unsigned int> shortDistance3;

	setCoordinates setPoints7 = { { 1.332, 89.12343 } };
	setCoordinates setPoints8 = { { 40.71277, -77.00583 },{ -4.71277, -72.00583 } };
	std::tuple<double, unsigned int, unsigned int> shortDistance4;


	shortDistance1 = distance1.computeShorterDistance(setPoints1, setPoints2, radius);
	distance1.info_computeShorterDistance(setPoints1, setPoints2, shortDistance1);

	shortDistance2 = distance1.computeShorterDistance(setPoints3, setPoints4, radius);
	distance1.info_computeShorterDistance(setPoints3, setPoints4, shortDistance2);

	shortDistance3 = distance1.computeShorterDistance(setPoints5, setPoints6, radius);
	distance1.info_computeShorterDistance(setPoints5, setPoints6, shortDistance3);

	shortDistance4 = distance1.computeShorterDistance(setPoints7, setPoints8, radius);
	distance1.info_computeShorterDistance(setPoints7, setPoints8, shortDistance4);

	std::cin.get();

	return 0;
}