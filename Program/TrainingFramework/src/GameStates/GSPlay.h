#pragma once
#include "gamestatebase.h"
#include<string>
class Player;
class Bullet;
class Enermy;
class Text;
class ExplosiveEffect;
class Meteor;
class UFO;
class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init()override;
	void Exit()override;

	void Pause()override;
	void Resume()override;

	void HandleEvents() override;
	void HandleKeyEvents(int key, bool bIsPressed) override;
	void HandleMouseEvents(int x, int y) override;

	void HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void Update(float deltaTime) override;
	void Draw() override;
	
	static int m_score;

private:
	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_scoreText;
	std::shared_ptr<Text>  m_playerHealText;
	std::shared_ptr<Player> m_Player;
	
	std::vector<std::shared_ptr<Bullet>> m_listBullet;
	std::vector<std::shared_ptr<Enermy>> m_listEnermy;
	std::vector<std::shared_ptr<UFO>> m_listEnermy2;
	std::vector<std::shared_ptr<ExplosiveEffect>> m_listExplosiveEffect;
	std::vector<std::shared_ptr<Meteor>> m_listMeteor;
	float m_SpawnCooldown;
	float m_SpawnCooldown2;
	float m_SpawnCooldown3;
	void CreateRandomEnermy();
	void CreateRandomMeteor();
	void CreateRandomUFO();
	void SpawnExplosive(Vector2 pos);
	int hp = 100;
	//std::string  player_img="player";
};

