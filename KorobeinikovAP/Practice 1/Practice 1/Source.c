#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	float Qdsp, Qdvp, Q, h, w, d, t_back, t_covers, t_sides, t_door, t_shelves, m_back, m_sides, m_covers, m_door, k_shelves, m_shelves, res;
	Qdsp = 800;
	Qdvp = 750;
	Q    = 640;
	printf("Input h ");
	scanf("%f", &h);
	if ((h < 1.8) || (h > 2.2)) {
		printf("Incorrect data,  1.8 <= h <= 2.2 ");
		return 0;
	}
	printf("Input w ");
	scanf("%f", &w);
	if ((w < 0.8) || (w > 1.2)) {
		printf("Incorrect data,  0.8 <= w <= 1.2 ");
		return 0;
	}
	printf("Input d ");
	scanf("%f", &d);
	if ((d < 0.5) || (d > 0.9)) {
		printf("Incorrect data,  0.5 <= d <= 0.9 ");
		return 0;
	}
	t_back    = 0.005;
	t_sides   = 0.015;
	t_covers  = 0.015;
	t_door    = 0.01;
	t_shelves = 0.015;
	m_back    = Qdvp * (t_back * h * w);
	m_sides   = 2 * (Qdsp * (t_sides * h * d));
	m_covers  = 2 * (Qdsp * (t_covers * w * d));
	m_door    = Q * (t_door * h * w);
	k_shelves = h / (0.415) - 1;
	m_shelves = k_shelves * (Qdsp * (t_shelves * w * d)); //не вычитал толщину стенок и крышки, потому что шкафы бывают разные и не поймёшь что вычитать (условия не заданы)
	res       = m_back + m_covers + m_door + m_shelves + m_sides;
	printf ("mass = %f ", res);
}