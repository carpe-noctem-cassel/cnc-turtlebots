/*
 * Simulator.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <model/Simulator.h>
#include <model/Wumpus.h>
#include "model/Agent.h"
#include <model/GroundTile.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <QJsonObject>
#include <QJsonArray>

namespace wumpus_simulator
{

	Simulator* Simulator::get()
	{
		static Simulator instance;
		return &instance;
	}

	void Simulator::init(bool agentHasArrow, int wumpusCount, int trapCount, int playGroundSize)
	{
		this->playGround.clear();
		this->agentHasArrow = agentHasArrow;
		this->playGroundSize = playGroundSize;
		this->trapCount = trapCount;
		this->wumpusCount = wumpusCount;
		for (int i = 0; i < this->playGroundSize; i++)
		{
			this->playGround.push_back(vector<shared_ptr<GroundTile>>());
		}
		for (int i = 0; i < this->playGroundSize; i++)
		{
			for (int j = 0; j < this->playGroundSize; j++)
			{
				this->playGround.at(i).push_back(make_shared<GroundTile>(i, j));
			}
		}
		/* initialize random seed: */
		srand(time(NULL));
		// Place given number of traps on field
		for (int i = 0; i < trapCount; i++)
		{
			int randx = rand() % (this->playGroundSize - 1);
			int randy = rand() % (this->playGroundSize - 1);

			if (!playGround.at(randx).at(randy)->getTrap())
			{
				playGround.at(randx).at(randy)->setTrap(true);
				setBreeze(randx, randy);
			}
			else
			{
				i--;
			}
		}
		// Place Wumpus on field
		for (int i = 0; i < wumpusCount; i++)
		{
			int randx = rand() % (this->playGroundSize - 1);
			int randy = rand() % (this->playGroundSize - 1);

			if (playGround.at(randx).at(randy)->getTrap() || playGround.at(randx).at(randy)->hasMovable())
			{
				i--;
			}
			else
			{
				playGround.at(randx).at(randy)->setMovable(make_shared<Wumpus>(playGround.at(randx).at(randy)));
				setStench(randx, randy);
			}

		}
		// Place Gold on field
		bool placed = false;
		while (!placed)
		{
			int randx = rand() % (this->playGroundSize - 1);
			int randy = rand() % (this->playGroundSize - 1);

			if (!(playGround.at(randx).at(randy)->getTrap() || playGround.at(randx).at(randy)->hasMovable()))
			{
				playGround.at(randx).at(randy)->setGold(true);
				placed = true;
			}
		}
		for (int i = 0; i < this->playGround.size(); i++)
		{
			for (int j = 0; j < this->playGround.size(); j++)
			{
				if (this->playGround.at(i).at(j)->hasMovable() || this->playGround.at(i).at(j)->getTrap())
				{
					this->playGround.at(i).at(j)->setBreeze(false);
					this->playGround.at(i).at(j)->setStench(false);
				}
			}
		}
		cout << "Simulator: Finished initiating the playground!" << endl;
	}

	Simulator::Simulator()
	{
		rosNode = new ros::NodeHandle();
		this->agentHasArrow = false;
		this->playGroundSize = -1;
		this->trapCount = -1;
		this->wumpusCount = -1;

	}

	Simulator::~Simulator()
	{
	}

	void Simulator::setBreeze(int x, int y)
	{
		if (x == 0)
		{
			playGround.at(x + 1).at(y)->setBreeze(true);

		}
		else if (x == playGroundSize - 1)
		{
			playGround.at(x - 1).at(y)->setBreeze(true);

		}
		else
		{
			playGround.at(x - 1).at(y)->setBreeze(true);
			playGround.at(x + 1).at(y)->setBreeze(true);
		}

		if (y > 0)
		{
			playGround.at(x).at(y - 1)->setBreeze(true);
		}

		if (y < playGroundSize - 1)
		{
			playGround.at(x).at(y + 1)->setBreeze(true);
		}
	}

	bool Simulator::isAgentHasArrow()
	{
		return agentHasArrow;
	}

	int Simulator::getPlayGroundSize()
	{
		return playGroundSize;
	}

	int Simulator::getTrapCount()
	{
		return trapCount;
	}

	int Simulator::getWumpusCount()
	{
		return wumpusCount;
	}

	vector<vector<shared_ptr<GroundTile>>> Simulator::getPlayGround()
	{
		return playGround;
	}

	void Simulator::setStench(int x, int y)
	{
		if (x == 0)
		{
			playGround.at(x + 1).at(y)->setStench(true);

		}
		else if (x == playGroundSize - 1)
		{
			playGround.at(x - 1).at(y)->setStench(true);

		}
		else
		{
			playGround.at(x - 1).at(y)->setStench(true);
			playGround.at(x + 1).at(y)->setStench(true);
		}

		if (y > 0)
		{
			playGround.at(x).at(y - 1)->setStench(true);
		}

		if (y < playGroundSize - 1)
		{
			playGround.at(x).at(y + 1)->setStench(true);
		}
	}

	shared_ptr<GroundTile> Simulator::getTile(int x, int y)
	{
		return this->playGround.at(x).at(y);
	}

	QJsonObject Simulator::toJSON()
	{
		//Root JSON object
		QJsonObject world;

		//Add attributes of the world like size and so on
		world["playGroundSize"] = playGroundSize;
		world["wumpusCount"] = wumpusCount;
		world["trapCount"] = trapCount;
		world["agentHasArrow"] = agentHasArrow;

		//JSON Array to hold the playground
		QJsonArray playground;
		for (int i = 0; i < playGroundSize; i++)
		{

			for (int j = 0; j < playGroundSize; j++)
			{

				QJsonObject ground;
				ground["x"] = playGround.at(i).at(j)->getX();
				ground["y"] = playGround.at(i).at(j)->getY();
				ground["hasTrap"] = playGround.at(i).at(j)->getTrap();
				ground["hasGold"] = playGround.at(i).at(j)->getGold();
				ground["hasStench"] = playGround.at(i).at(j)->getStench();
				ground["hasBreeze"] = playGround.at(i).at(j)->getBreeze();
				ground["isStartpoint"] = playGround.at(i).at(j)->getStartpoint();
				ground["startAgentID"] = playGround.at(i).at(j)->getStartAgentID();
				if (playGround.at(i).at(j)->getMovable() != nullptr)
				{
					ground["movableType"] = playGround.at(i).at(j)->getMovable()->getType();
				}
				else
				{
					ground["movableType"] = "unknown";
				}

				playground.append(ground);

			}
		}

		world["playground"] = playground;

		return world;

	}

	void Simulator::fromJSON(QJsonObject root)
	{

		//Clear the old vectors
		this->playGround.clear();
		//Reset global variables
		this->agentHasArrow = root["agentHasArrow"].toBool();
		this->playGroundSize = root["playGroundSize"].toInt();
		this->trapCount = root["trapCount"].toInt();
		this->wumpusCount = root["wumpusCount"].toInt();
		// Init the playground
		for (int i = 0; i < this->playGroundSize; i++)
		{
			this->playGround.push_back(vector<shared_ptr<GroundTile>>());
		}
		for (int i = 0; i < this->playGroundSize; i++)
		{
			for (int j = 0; j < this->playGroundSize; j++)
			{
				this->playGround.at(i).push_back(make_shared<GroundTile>(i, j));
			}
		}
		//Load the playground
		QJsonArray tiles = root["playground"].toArray();
		for (int i = 0; i < tiles.size(); i++)
		{
			QJsonObject tile = tiles[i].toObject();
			auto x = tile["x"].toInt();
			auto y = tile["y"].toInt();
			auto groundTile = this->playGround.at(x).at(y);
			groundTile->setBreeze(tile["hasBreeze"].toBool());
			groundTile->setGold(tile["hasGold"].toBool());
			groundTile->setStench(tile["hasStench"].toBool());
			groundTile->setStartAgentID(tile["startAgentID"].toInt());
			groundTile->setStartpoint(tile["isStartpoint"].toBool());
			groundTile->setTrap(tile["hasTrap"].toBool());
			if(tile["movableType"].toString().contains("wumpus"))
			{
				auto wumpus = make_shared<Wumpus>(this->playGround.at(x).at(y));
				groundTile->setMovable(wumpus);
			}
			else if(tile["movableType"].toString().contains("agent"))
			{
				auto agent = make_shared<Agent>(this->playGround.at(x).at(y));
				groundTile->setMovable(agent);
			}

		}
	}

} /* namespace wumpus_simulator */

