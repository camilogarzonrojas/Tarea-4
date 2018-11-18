#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

float a_arr(float magnitud, float v_x_y)
{
	float arr=-v_x_y*magnitud;
	return arr;
}

int main()
{
	float a1x, a1y, a2x, a2y, a3x, a3y, a4x, a4y, b1x, b1y, b2x, b2y, b3x, b3y, b4x, b4y, x, y, vx, vy, t, theta, v;
	theta=3.1416/4;
	vx=300*cos(theta);
	vy=300*cos(theta);
	x=0;
	y=0;
	t=0.001;
	return 0;
}
