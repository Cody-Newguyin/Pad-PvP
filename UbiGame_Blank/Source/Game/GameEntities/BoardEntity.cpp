// Ravinder Mangat - BoardEntity.cpp
// Purpose to create physical board to hold tiles

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BoardEntity.h"
#include "OrbEntity.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Graphics.hpp>

using namespace Game;

BoardEntity::BoardEntity() 
	:orb(nullptr)
{
	srand((unsigned)time(0));
	this->SetPos(sf::Vector2f(400.f, 400.f));
	initBoardPos();

	std::cout << "Random: " << randomizeId()<<std::endl;
	std::cout << "Random: " << randomizeId()<<std::endl;
	std::cout << "Random: " << randomizeId()<<std::endl;


	for (int i = 0; i < 6; i++) {
		tiles.push_back(std::vector < OrbEntity* >());
		for (int j = 0; j < 5; j++) {
			orb = new OrbEntity();
			GameEngine::GameEngineMain::GetInstance()->AddEntity(orb);
			tiles[i].push_back(orb);
			orb->SetPos(tilesPos[i][j]);
			orb->SetId(randomizeId());
			orb->setTexture();
		}
	}

	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Board_Bg);
	m_renderComponent->SetZLevel(1);
	m_renderComponent->SetTileIndex(0, 0);

	
	this->SetSize(sf::Vector2f(480.f, 405.f));


}

BoardEntity::~BoardEntity() {

}

void BoardEntity::OnAddToWorld() {
	Entity::OnAddToWorld();
}

int BoardEntity::randomizeId() {
	return (rand() % 6) + 1;

}

void BoardEntity::initBoardPos() {
	for (int i = 0; i < 6; i++) {
		int x = (i - 2.5) * 75;
		for (int j = 0; j < 5; j++) {
			int y = (j - 2) * 75;
			tilesPos[i][j] = sf::Vector2f(x,y) + this->GetPos();
		}
	}
}