#include "header.h"
#include "ConstVar.h"
#include "Player.h"
#include "Batter.h"
#include "Pitcher.h"
#include "Fielder.h"

USING_NS_CC;

Player::Player(int id, std::string name, int batELO, int pitELO) : m_name(name)
{

	m_batter = new Batter(batELO);
	m_pitcher = new Pitcher(pitELO);
	m_fielder = new Fielder();
	m_spr = Sprite::create(
		ConstVar::SQUARE_IMG,
		Rect(0, 0, ConstVar::playerRect.size.width, ConstVar::playerRect.size.height));
	m_spr->retain();

	request_stat(id);
}


Player::~Player()
{
	m_spr->release();
	delete m_batter;
	delete m_pitcher;
	delete m_fielder;
}

void Player::request_stat(int id)
{

}