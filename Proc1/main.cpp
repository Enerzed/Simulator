#include "Program.h"

int main()
{
	Program simulator;
	simulator.run();
}

//else if (tempName == "cell")
//{
//	bool isSame = false;
//	auto seeCell = cells.begin();
//	for (auto j = cells.begin(); j != cells.end(); j++)
//	{
//		seeCell = cells.begin();
//		if ((*j)->getGen() == (*i)->getGen())
//		{
//			isSame = true;
//			break;
//		}
//	}
//	if (isSame)
//	{
//		switch ((*i)->getGen().sameCell)
//		{
//		case 0:
//		{
//			(*i)->facingTurnRight();
//			break;
//		}
//		case 1:
//		{
//			(*i)->facingTurnLeft();
//			break;
//		}
//		case 3:
//		{
//			if (seeCell != cells.end())
//			{
//				std::cout << "KILLED\n";
//				i = cells.erase(seeCell);
//				map.at(seeY * MAP_WIDTH + seeX).setName("food");
//			}
//		}
//		}
//	}
//	else
//	{
//		switch ((*i)->getGen().otherCell)
//		{
//		case 0:
//		{
//			(*i)->facingTurnRight();
//			break;
//		}
//		case 1:
//		{
//			(*i)->facingTurnLeft();
//			break;
//		}
//		case 3:
//		{
//			if (seeCell != cells.end())
//			{
//				std::cout << "KILLED\n";
//				i = cells.erase(seeCell);
//				map.at(seeY * MAP_WIDTH + seeX).setName("food");
//			}
//			break;
//		}
//		}
//	}
//				}