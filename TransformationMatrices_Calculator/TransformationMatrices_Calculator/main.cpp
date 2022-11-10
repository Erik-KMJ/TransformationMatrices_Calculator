#include <iostream>
#include <cmath>

void DisplayMatrix(float matrix[4][4])
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			std::cout << matrix[x][y];
		}
		std::cout << std::endl;
	}
}

int main()
{
	int selection = 0;
	int x, y, z;

	float scalingMatrix[4][4];
	float translationMatrix[4][4];
	float rotationXMatrix[4][4];
	float rotationYMatrix[4][4];
	float rotationZMatrix[4][4];
	float projectionXMatrix[4][4];
	float projectionYMatrix[4][4];
	float projectionZMatrix[4][4];
	float resultantMatrix[4][4];

	std::cout << "Scaling Matrix\n\n"
		"Select 1 for uniform scale, 2 for non-uniform scale: ";

	std::cin >> selection;

	if (selection == 1)
	{
		std::cout << "\n\nInput amount to scale: ";
		std::cin >> x;
	}
	else if (selection == 2)
	{
		std::cout << "\n\nInput x scale: ";
		std::cin >> x;
		std::cout << "\nInput y scale: ";
		std::cin >> y;
		std::cout << "\nInput z scale: ";
		std::cin >> z;
	}

	// set matrix here

	std::cout << "\n\n\nTranslation Matrix\n\n"
		"Input x Translation: ";
	std::cin >> x;
	std::cout << "\nInput y Translation: ";
	std::cin >> y;
	std::cout << "\nInput z Translation: ";
	std::cin >> z;

	// set matrix here

	std::cout << "\n\n\nRotation Matrix\n\n"
		"Input x axis rotation: ";
	std::cin >> x;
	std::cout << "\nInput y axis rotation: ";
	std::cin >> y;
	std::cout << "\nInput z rotation: ";
	std::cin >> z;

	// set matrix here

	std::cout << "\n\n\nProjection Matrix\n\n"
		"Input x axis projection: ";
	std::cin >> x;
	std::cout << "\nInput y axis projection: ";
	std::cin >> y;
	std::cout << "\nInput z projection: ";
	std::cin >> z;

	// set matrix here

	

	system("PAUSE");

	return 0;
}