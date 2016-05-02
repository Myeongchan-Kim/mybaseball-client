#include "header.h"
#include "Batter.h"


Batter::Batter() : Batter(0)
{
}

Batter::Batter(int elo) : m_batELO(elo)
{}

Batter::~Batter()
{
}
