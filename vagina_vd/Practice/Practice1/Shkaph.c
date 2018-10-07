#include <stdio.h> 
#include <math.h> 
void main() {

	double h, d, w, p_dvp, p_dsp, p_der, t_dvp, t_dsp, t_der, M, m_zst, m_bok, m_dv, m_kr, m_p;

	int k;
	printf("Vvedite plotnost dereva v g/cm^3 \n");
	scanf_s("%lf", &p_der);
	if (p_der <= 0)
	{
		printf("Plotnost dereva zadana neverno. Vvedennoe chislo ne yavlyaetsa polozhitelnym.\n");
		return;
	}
	printf("Vvedite plotnost DSP v g/cm^3 \n");
	scanf_s("%lf", &p_dsp);
	if (p_dsp <= 0)
	{
		printf("Plotnost DSP zadana neverno. Vvedennoe chislo ne yavlyaetsa polozhitelnym.\n");
		return 0;
	}
	printf("Vvedite plotnost DVP v g/cm^3 \n");
	scanf_s("%lf", &p_dvp);
	if (p_dvp <= 0)
	{
		printf("Plotnost DVP zadana neverno. Vvedennoe chislo ne yavlyaetsa polozhitelnym.\n");
		return 0;
	}

	t_der = 1;
	t_dsp = 1.5;
	t_dvp = 0.5;
	printf("Vvedite vysotu skapha v santimetrah (ot 180 do 220 cm) \n");
	scanf_s("%lf", &h);
	if ((h < 180) || (h > 220))
	{
		printf("Vysota zadana neverno. Vvedennoe chislo ne vhodit v predely ot 180 do 220 cm \n");
		return 0;
	}
	printf("Vvedite shirinu skapha v santimetrah  (ot 80 do 120 cm) \n ");
	scanf_s("%lf", &w);
	if ((w < 80) || (w > 120))
	{
		printf("Shirina zadana neverno. Vvedennoe chislo ne vhodit v predely ot 80 do 120 cm \n");
		return 0;
	}
	printf("Vvedite glubinu skapha v santimetrah  (ot 50 do 90 cm) \n");
	scanf_s("%lf", &d);
	if ((d < 50) || (d > 90))
	{
		printf("Glubina zadana neverno. Vvedennoe chislo ne vhodit v predely ot 50 do 90 cm \n");
		return 0;
	}
	k = h / 41;
	m_zst = p_dvp * t_dvp * h * w;
	m_bok = 2 * p_dsp * t_dsp * h * d;
	m_kr = 2 * p_dsp * w * d * t_dsp;
	m_dv = p_der * h * t_der * w;
	m_p = k * p_dsp * (w - 3)  * d;
	M = (m_p + m_kr + m_bok + m_zst + m_dv) / 1000;
	printf("Massa shkapha ravna (v kg) %lf", M);

}