#include <iostream>
#include <cmath>

void DisplayMatrix(float matrix[4][4])
{
	std::cout << std::endl;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			std::cout << "|";
			std::cout << matrix[x][y];
		}
		std::cout << std::endl;
	}
}

int main()
{
	enum menu
	{
		main = 0,
		scaling = 1,
		translation = 2,
		rotation,
		projection,
		exit
	};

	bool run = true;
	int x, y, z, menuSelection = 0;
	int selection = 0;

	float scalingMatrix[4][4];
	float translationMatrix[4][4];
	float rotationXMatrix[4][4];
	float rotationYMatrix[4][4];
	float rotationZMatrix[4][4];
	float projectionXMatrix[4][4];
	float projectionYMatrix[4][4];
	float projectionZMatrix[4][4];
	float resultantMatrix[4][4];

	while (run)
	{
		switch (menuSelection)
		{
		case main:
			system("CLS");

			std::cout << "Translation Matrices Calculator\n\n"
				"Choose matrix to generate\n"
				"1) Scaling Matrix\n"
				"2) Translation Matrix\n"
				"3) Rotation Matrix\n"
				"4) Projection Matrix\n"
				"5) Exit Program\n"
				"Selection: ";
			std::cin >> menuSelection;

			break;

		case scaling:
			std::cout << "Scaling Matrix\n\n"
				"Select 1 for uniform scale, 2 for non-uniform scale: ";

			std::cin >> selection;

			if (selection == 1)
			{
				std::cout << "\n\nInput amount to scale: ";
				std::cin >> x;

				for (int column = 0; column < 4; column++)
				{
					for (int row = 0; row < 4; row++)
					{
						if (row == column)
						{
							scalingMatrix[row][column] = x;
						}
						else
						{
							scalingMatrix[row][column] = 0;
						}
					}
				}
				scalingMatrix[3][3] = 1;
				DisplayMatrix(scalingMatrix);
			}
			else if (selection == 2)
			{
				std::cout << "\n\nInput x scale: ";
				std::cin >> x;
				std::cout << "Input y scale: ";
				std::cin >> y;
				std::cout << "Input z scale: ";
				std::cin >> z;

				for (int column = 0; column < 4; column++)
				{
					for (int row = 0; row < 4; row++)
					{
						scalingMatrix[row][column] = 0;
					}
				}
				scalingMatrix[0][0] = x;
				scalingMatrix[1][1] = y;
				scalingMatrix[2][2] = z;
				scalingMatrix[3][3] = 1;



				system("PAUSE");
				menuSelection = 0;
				break;

		case rotation:
			std::cout << "Rotation Matrix\n\n"
				"Choose axis to rotate about\n"
				"1) x-axis\n"
				"2) y-axis\n"
				"3) z-axis\n"
				"Selection: ";
			std::cin >> selection;

			if (selection == 1)
			{
				"\nInput x axis rotation angle: ";
				std::cin >> x;
				for (int column = 0; column < 4; column++)
				{
					for (int row = 0; row < 4; row++)
					{
						if (row == column)
						{
							rotationXMatrix[row][column] = 1;
						}
						else
						{
							rotationXMatrix[row][column] = 0;
						}
					}
				}
				rotationXMatrix[1][1] = cos(x);
				rotationXMatrix[2][1] = -sin(x);
				rotationXMatrix[1][2] = sin(x);
				rotationXMatrix[2][2] = cos(x);
				DisplayMatrix(rotationXMatrix);
			}
			else if (selection == 2)
			{
				std::cout << "\nInput y axis rotation: ";
				std::cin >> y;
				for (int column = 0; column < 4; column++)
				{
					for (int row = 0; row < 4; row++)
					{
						if (row == column)
						{
							rotationYMatrix[row][column] = 1;
						}
						else
						{
							rotationYMatrix[row][column] = 0;
						}
					}
				}
				rotationYMatrix[0][0] = cos(y);
				rotationYMatrix[2][0] = sin(y);
				rotationYMatrix[0][2] = -sin(y);
				rotationYMatrix[2][2] = cos(y);
				DisplayMatrix(rotationYMatrix);
			}
			else if (selection == 3)
			{
				std::cout << "\nInput z rotation: ";
				std::cin >> z;
				for (int column = 0; column < 4; column++)
				{
					for (int row = 0; row < 4; row++)
					{
						if (row == column)
						{
							rotationZMatrix[row][column] = 1;
						}
						else
						{
							rotationZMatrix[row][column] = 0;
						}
					}
				}
				rotationZMatrix[0][0] = cos(z);
				rotationZMatrix[1][0] = -sin(z);
				rotationZMatrix[0][1] = sin(z);
				rotationZMatrix[1][1] = cos(z);
				DisplayMatrix(rotationZMatrix);
			}

			system("PAUSE");
			menuSelection = 0;
			break;

		case projection:
			std::cout << "Projection Matrix\n\n"
				"Choose axis to project about\n"
				"1) x-axis\n"
				"2) y-axis\n"
				"3) z-axis\n"
				"Selection: ";
			std::cin >> selection;
			if (selection == 1)
			{
				std::cout << "\nInput X axis projection: ";
				std::cin >> x;
				for (int column = 0; column < 4; column++)
				{
					for (int row = 0; row < 4; row++)
					{
						if (row == column)
						{
							projectionXMatrix[row][column] = 1;
						}
						else
						{
							projectionXMatrix[row][column] = 0;
						}
					}
				}
				projectionXMatrix[3][3] = 0;
				projectionXMatrix[0][3] = 1.f / x;
				DisplayMatrix(projectionXMatrix);
			}
			else if (selection == 2)
			{
				std::cout << "\nInput y axis projection: ";
				std::cin >> y;
				for (int column = 0; column < 4; column++)
				{
					for (int row = 0; row < 4; row++)
					{
						if (row == column)
						{
							projectionYMatrix[row][column] = 1;
						}
						else
						{
							projectionYMatrix[row][column] = 0;
						}
					}
				}
				projectionYMatrix[3][3] = 0;
				projectionYMatrix[1][3] = 1.f / y;
				DisplayMatrix(projectionYMatrix);
			}
			else if (selection == 3)
			{
				std::cout << "\nInput z projection: ";
				std::cin >> z;

				for (int column = 0; column < 4; column++)
				{
					for (int row = 0; row < 4; row++)
					{
						if (row == column)
						{
							projectionZMatrix[row][column] = 1;
						}
						else
						{
							projectionZMatrix[row][column] = 0;
						}
					}
				}
				projectionZMatrix[3][3] = 0;
				projectionZMatrix[2][3] = 1.f / z;
				DisplayMatrix(projectionZMatrix);
				
			}
			
			}

			system("PAUSE");
			menuSelection = 0;
			break;

		case translation:
			std::cout << "\n\nTranslation Matrix\n\n"
				"Input x Translation: ";
			std::cin >> x;
			std::cout << "\nInput y Translation: ";
			std::cin >> y;
			std::cout << "\nInput z Translation: ";
			std::cin >> z;

			for (int column = 0; column < 4; column++)
			{
				for (int row = 0; row < 4; row++)
				{
					if (row == column)
					{
						translationMatrix[row][column] = 1;
					}
					else
					{
						translationMatrix[row][column] = 0;
					}
				}
			}
			translationMatrix[3][0] = x;
			translationMatrix[3][1] = y;
			translationMatrix[3][2] = z;
			DisplayMatrix(translationMatrix);
			system("PAUSE");
			menuSelection = 0;
			break;

		case exit:
			run = false;
			break;
		}
	}
	
	return 0;
}