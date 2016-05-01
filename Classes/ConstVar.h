#pragma once
#include <string>

USING_NS_CC;

namespace ConstVar
{
	static std::string SQUARE_IMG = "img/square.jpg";
	static std::string OUT_IMG = "img/out_count.png";
	static std::string BALL_IMG = "img/ball_count.png";
	static std::string STRIKE_IMG = "img/strike_count.png";
	static std::string OFFLIGHT_IMG = "img/off_count.png";
	static std::string STADIUM_IMG = "img/baseball_park.png";
	static Rect goundLayerRect = Rect(0, 0, 320, 320);
	static Rect batterListLayerRect = Rect(320, 0, 80, 320);
	static Rect countBoardRect = Rect(230, 260, 80, 50);
	static Rect scoreBoardRect = Rect(20, 260, 70, 50);

	static std::string OUTBOARD_NAME = "OUTCOUNT";
	static std::string STRIKEBOARD_NAME = "STRIKECOUNT";
	static std::string BALLBOARD_NAME = "BALLCOUNT";
	static std::string HSCOREBOARD_NAME = "HOMESCORE";
	static std::string ASCOREBOARD_NAME = "AWAYSCORE";
}
