// Ravinder Mangat - BoardEntity.cpp
// Purpose to create physical board to hold tiles

#include "BoardEntity.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include <SFML/Graphics.hpp>

using namespace Game;

BoardEntity::BoardEntity() {
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Board_Bg);
	m_renderComponent->SetZLevel(1);
	m_renderComponent->SetTileIndex(0, 0);

	this->SetPos(sf::Vector2f(400.f, 400.f));
	this->SetSize(sf::Vector2f(600.f, 600.f));

	AddComponent<GameEngine::CollidableComponent>();
}

BoardEntity::~BoardEntity() {

}

void BoardEntity::OnAddToWorld() {
	Entity::OnAddToWorld();
}