#include "PlayerEntity.h"
#include "Game/GameComponent/BoardControl.h"

using namespace Game;

PlayerEntity::PlayerEntity(BoardEntity* board)
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetZLevel(3);
	m_renderComponent->SetTexture(GameEngine::eTexture::Overlay);

	this->SetPos(sf::Vector2f(75.f,75.f));

	BoardControlComponent = AddComponent<BoardControl>();
	BoardControlComponent->SetBoard(board);
}


PlayerEntity::~PlayerEntity()
{

}



