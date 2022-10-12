#include <stdio.h>
int main()
{
	double h, w, d, m_z_st, m_bk, m_kr, m_dvr, h_plk, m_plk = 0, m;
	printf("Введите высоту задней стенки h(см.)=");
	scanf_s("%lf", &h);
	printf("Введите ширину задней стенки w(см.)=");
	scanf_s("%lf", &w);
	printf("Введите глубину боковины d(см.)=");
	scanf_s("%lf", &d);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
	{
		printf("Неверно введенные данные");
		return 1;
	}
	m_z_st = h * w * 0.5 * 0.8;
	m_bk = 2 * h * d * 1.5 * 0.65;
	m_kr = 2 * w * d * 1.5 * 0.65;
	m_dvr = h * w * 0.55;
	h_plk = 41.5;
	while (h_plk < h)
	{
		m_plk = m_plk + d * (w - 3) * 1.5 * 0.65;
		h_plk = h_plk + 41.5;
	}
	printf("Общая масса шкафа(кг.)=%lf", (m_z_st + m_bk + m_kr + m_dvr + m_plk) / 1000);
	return 0;
}
