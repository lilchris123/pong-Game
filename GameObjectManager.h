#pragma once
#include "VisibleGameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();
	
	void Add(std::string name, VisibleGameObject* gameobject);
	void Remove(std::string name);
	int GetObjectCount() const;
	VisibleGameObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& renderWindow);

	void UpdateAll();

private:
	std::map < std::string, VisibleGameObject*> gameObjects;
	sf::Clock clock;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> &p)const
		{
			delete p.second;
		}
	};
};