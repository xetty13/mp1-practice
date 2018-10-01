#include<stdio.h>
void main() {
	double pl_DVP, pl_DSP, pl_d, m, m_stenka, m_2bokovini, m_2krish, m_2dveri, m_polki;
	int w, h, d;
	printf("Vvedite: w (ot 80 do 120), h (ot 180 do 220), d (ot 50 do 90), pl_DVP, pl_DSP, pl_d");
	scanf_s("%d %d %d %lf %lf %lf", &w, &h, &d, &pl_DVP, &pl_DSP, &pl_d);
	if ((w < 80) || (w > 120) || (h < 180) || (h > 220) || (d < 50) || (d > 90) || (pl_DVP <= 0) || (pl_DSP <= 0) || (pl_d <= 0)) {
		printf("Vvedeny nepravilnie dannnie");
		return;
	}
	m_stenka = h * w * 0.5 * pl_DVP;
	m_2bokovini = 2 * pl_DSP * h * d * 1.5;
	m_2krish = 2 * pl_DSP * w * d * 1.5;
	m_2dveri = h * w * 1 * pl_d;
	m_polki = (h / 40) * pl_DSP * w * d * 1.5;
	m = m_stenka + m_2bokovini + m_2krish + m_polki;
	printf("%lf", m);
}