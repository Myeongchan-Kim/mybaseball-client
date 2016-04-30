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
	static Rect countBoardRect = Rect(260, 280, 50, 50);
}
