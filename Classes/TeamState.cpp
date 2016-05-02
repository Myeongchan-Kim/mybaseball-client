#include "header.h"
#include "TeamState.h"
#include "rapidjson\document.h"
#include <fstream>
USING_NS_CC;

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
	auto path = FileUtils::getInstance()->fullPathForFilename("sample.json");
	ssize_t size;
	auto str = FileUtils::getInstance()->getFileData(path, "r", &size);

	auto is = std::ifstream(path, std::ifstream::in);
	char buffer[65536] = { 0, };
	is.read(buffer, 65536);

	rapidjson::Document d;
	d.Parse(buffer);

	assert(d.IsObject());
	const auto& teamA = d["teamA"];
	m_teamNameA = teamA["name"].GetString();
	for (int i = 0; i < 25; i++ )
	{
		
	}

	const auto& teamH = d["teamB"];
	m_teamNameH = teamH["name"].GetString();
}