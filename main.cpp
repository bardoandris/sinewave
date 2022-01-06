#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <cmath>
#include <math.h>
class Sinewave : public olc::PixelGameEngine{
	public:
		Sinewave(){
			sAppName = "Sinewave";
		}
	public:
	float offset = 0;
		bool OnUserCreate() override{
			return true;
		}
		bool OnUserUpdate(float fElapsedTime) override{
			offset += fElapsedTime;
			Clear(olc::BLACK);
			for (int x=0; x<ScreenWidth(); x++) {
			Draw(x, 
				std::sin((offset + M_PI*x/ScreenWidth())) * ScreenHeight() / 2 + ScreenHeight()/2);
			}
			return true;
		}
};
int main(){
	Sinewave sin;
	sin.Construct(100, 100, 5, 5);
	sin.Start();
	return 0;
}