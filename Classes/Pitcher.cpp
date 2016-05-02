#include "header.h"
#include "Pitcher.h"


Pitcher::Pitcher() : Pitcher(0)
{
}

Pitcher::Pitcher(int elo) : m_pitELO(elo)
{
}

Pitcher::~Pitcher()
{
}
