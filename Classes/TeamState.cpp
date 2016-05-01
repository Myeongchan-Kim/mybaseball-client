#include "header.h"
#include "TeamState.h"

TeamState::TeamState() :
	m_homeTeam(),
	m_awayTeam(),
	m_homeFielder(),
	m_awayFielder(),
	m_curFielder(),
	m_homeBatList(),
	m_awayBatList(),
	m_curBatList(),
	m_homePitcher(nullptr),
	m_awayPitcher(nullptr),
	m_curPitcher(nullptr),
	m_curBatter(nullptr)
{
}

TeamState::~TeamState()
{
}

void TeamState::SetSampleList()
{

}