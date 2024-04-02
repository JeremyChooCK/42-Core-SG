#include <iostream>
#include "Point.hpp" // Include your Point class header

// Declaration of the bsp function

void	testBSP(void)
{
	Point		a(0.0f, 0.0f);
	Point		b(1.0f, 0.0f);
	Point		c(0.5f, 1.0f);
	const int	numPoints = 7;
	Point		testPoints[] = {
		Point(0.25f, 0.25f),
		Point(0.0f, 0.0f),
		Point(0.5f, 0.5f),
		Point(1.0f, 0.0f),
		Point(0.5f, 0.0f),
		Point(0.75f, 0.75f),
		Point(-0.1f, 0.1f)
	};

	for (int i = 0; i < numPoints; ++i)
	{
		Point	&point = testPoints[i];
		bool	isInside = bsp(a, b, c, point);
		std::cout << "Point (" << point.getX() << ", " << point.getY()
				<< ") is " << (isInside ? "inside" : "outside")
				<< " the triangle." << std::endl;
	}
}

int main() {
    // Test cases
    Point testPoints[10][4] = {
        {Point(0, 0), Point(1, 0), Point(0, 1), Point(0.1, 0.1)},
        {Point(0, 0), Point(1, 0), Point(0, 1), Point(0.5, 0.5)},
        {Point(0, 0), Point(1, 0), Point(0, 1), Point(1, 1)},
        {Point(0, 0), Point(1, 0), Point(0, 1), Point(0, 0)},
        {Point(0, 0), Point(1, 0), Point(0, 1), Point(-0.1, -0.1)},
        {Point(-1, -1), Point(2, 0), Point(0, 3), Point(0.5, 1)},
        {Point(-1, -1), Point(2, 0), Point(0, 3), Point(2, 2)},
        {Point(-1, -1), Point(2, 0), Point(0, 3), Point(-1, -1)},
        {Point(-1, -1), Point(2, 0), Point(0, 3), Point(0, 0)},
    };

    bool expectedResults[19] = {true, false, false, false, false, true, false, false, true};

    for (int i = 0; i < 9; ++i) {
        bool result = bsp(testPoints[i][0], testPoints[i][1], testPoints[i][2], testPoints[i][3]);
        std::cout << "Test case " << i + 1 << ": Expected " << expectedResults[i] 
                  << ", got " << result << ". "
                  << (result == expectedResults[i] ? "Passed" : "Failed") << std::endl;
    }

    return 0;
}
