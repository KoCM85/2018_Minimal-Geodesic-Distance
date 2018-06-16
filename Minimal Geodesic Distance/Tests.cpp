#include "Tests.h"
#include "Converter.h"
#include "Distance.h"
#include "Coordinate.h"
#include <iostream>

test & test::getInstance()
{
	static test instance;
	return instance;
}

void test::test_degreesToRadians()
{
	converter & converter1 = converter::getInstance();

	{
		if (converter1.degreesToRadians(100) - 1.7453292519943 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		if (converter1.degreesToRadians(-100) + 1.7453292519943 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		if (converter1.degreesToRadians(0) == 0);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	std::cout << "test degreesToRadians OK \n";
}
void test::test_degreesMinutesSecondsToDegrees()
{
	converter & converter1 = converter::getInstance();

	{
		if (converter1.degreesMinutesSecondsToDegrees(0, 45, 0, 'n') == 0.75);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		if (converter1.degreesMinutesSecondsToDegrees(0, 45, 0, 's') == -0.75);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		if (converter1.degreesMinutesSecondsToDegrees(100, 100, 96, 'E') - 101.6933333 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		if (converter1.degreesMinutesSecondsToDegrees(0, 0, 0, 'W') == 0);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	std::cout << "test degreesMinutesSecondsToDegrees OK \n";
}
void test::test_computeDistance()
{
	converter & converter1 = converter::getInstance();
	double radius = 6371.008; // 6371.008 Earth radius
	distance distance1;
	coordinate startCoord;
	coordinate destCoord;

	{
		startCoord = { converter1.degreesMinutesSecondsToDegrees(0, 45, 0, 'n'), converter1.degreesMinutesSecondsToDegrees(10, 100, 0, 'E') };
		destCoord = { converter1.degreesMinutesSecondsToDegrees(59, 53, 0, 'N'), converter1.degreesMinutesSecondsToDegrees(30, 15, 0, 'e') };
		
		if (distance1.computeDistance(startCoord, destCoord, radius) - 6767.787542862 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		startCoord = { converter1.degreesMinutesSecondsToDegrees(0, 45, 0, 'S'), converter1.degreesMinutesSecondsToDegrees(10, 100, 0, 'w') };
		destCoord = { converter1.degreesMinutesSecondsToDegrees(59, 53, 0, 'N'), converter1.degreesMinutesSecondsToDegrees(30, 15, 0, 'e') };

		if (distance1.computeDistance(startCoord, destCoord, radius) - 7647.5499863 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		startCoord = { converter1.degreesMinutesSecondsToDegrees(0, 45, 0, 'S'), converter1.degreesMinutesSecondsToDegrees(10, 1, 0, 'w') };
		destCoord = { converter1.degreesMinutesSecondsToDegrees(9, 53, 0, 's'), converter1.degreesMinutesSecondsToDegrees(30, 5, 0, 'W') };

		if (distance1.computeDistance(startCoord, destCoord, radius) - 2440.5395851 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		startCoord = { converter1.degreesMinutesSecondsToDegrees(0, 0, 0, 'S'), converter1.degreesMinutesSecondsToDegrees(0, 0, 0, 'w') };
		destCoord = { converter1.degreesMinutesSecondsToDegrees(9, 0, 0, 's'), converter1.degreesMinutesSecondsToDegrees(0, 0, 0, 'e') };

		if (distance1.computeDistance(startCoord, destCoord, radius) - 1000.7557176 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	std::cout << "test computeDistance OK \n";
}

void test::test_computeShorterDistance()
{
	distance distance1;
	double radius = 6371.008; // 6371.008 Earth radius

	{
		setCoordinates setPoints1 = { { -40.71277, 177.00583 },{ 1.71277, 74.00583 },{ 40.71277, 74.00583 } };
		setCoordinates setPoints2 = { { 40.71277, 77.00583 },{ 4.71277, 72.00583 } };

		if (std::get<0>(distance1.computeShorterDistance(setPoints1, setPoints2, radius)) - 252.841614 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}

	}

	{
		setCoordinates setPoints1;
		setCoordinates setPoints2;

		if (std::get<0>(distance1.computeShorterDistance(setPoints1, setPoints2, radius)) == std::numeric_limits<double>::max());
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		setCoordinates setPoints1 = { { -40.71277, 177.00583 },{ 1.71277, 74.00583 },{ 40.71277, 74.00583 } };
		setCoordinates setPoints2;

		if (std::get<0>(distance1.computeShorterDistance(setPoints1, setPoints2, radius)) == std::numeric_limits<double>::max());
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		setCoordinates setPoints1;
		setCoordinates setPoints2 = { { 40.71277, 77.00583 },{ 4.71277, 72.00583 } };

		if (std::get<0>(distance1.computeShorterDistance(setPoints1, setPoints2, radius)) == std::numeric_limits<double>::max());
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	{
		setCoordinates setPoints1 = { {1.332, 89.12343} };
		setCoordinates setPoints2 = { { 40.71277, -77.00583 },{ -4.71277, -72.00583 } };

		if (std::get<0>(distance1.computeShorterDistance(setPoints1, setPoints2, radius)) - 15133.403995 < 0.0000001);
		else
		{
			std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << '\n';
			return;
		}
	}

	std::cout << "test computeShorterDistance OK \n";
}

void test::testAll()
{
	test_degreesToRadians();
	test_degreesMinutesSecondsToDegrees();
	test_computeDistance();
	test_computeShorterDistance();
	std::cout << "All test Ok \n";
}