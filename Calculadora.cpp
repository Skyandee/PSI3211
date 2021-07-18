#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define PI 3.14159265

// Made with love - by Miaut


void Clear () {
	std::cout << "\x1B[2J\x1B[H";
}


void Menu () {

	printf ("Escolha uma opção:\n\n");
	printf ("1 - Estrela-Delta\n");
	printf ("2 - Delta-Estrela \n");
	printf ("3 - Fasores\n");
	printf ("4 - Divisor de Tensão\n");
	printf ("5 - Divisor de Corrente\n");
	printf ("6 - Limpar Tela\n");
	printf ("7 - Sair\n\n");

}

void DeltaEstrela () {

	double REQ;
	double RAB, RBC, RAC;

	printf ("RAB: ");
	scanf ("%lf", &RAB);
	printf ("RBC: ");
	scanf ("%lf", &RBC);
	printf ("RAC: ");
	scanf ("%lf", &RAC);
	
	Clear ();

	REQ = RAB + RBC + RAC;

	printf ("RA0: %.4lf\n", RAB * RAC / REQ);
	printf ("RB0: %.4lf\n", RAB * RBC / REQ);
	printf ("RC0: %.4lf\n", RAC * RBC / REQ);
	printf ("\n");
}

void EstrelaDelta () {

	double REQ;
	double RA0, RB0, RC0;

	printf ("RA0: ");
	scanf ("%lf", &RA0);
	printf ("RB0: ");
	scanf ("%lf", &RB0);
	printf ("RC0: ");
	scanf ("%lf", &RC0);

	printf ("\n\n");

	REQ = RA0 * RB0 + RA0 * RC0 + RB0 * RC0;

	printf ("RAB: %.4lf\n", REQ / RC0);
	printf ("RBC: %.4lf\n", REQ / RA0);
	printf ("RAC: %.4lf\n", REQ / RB0);
	printf ("\n");

}

void Fasor () {

	double A, B, C, D, E, F;
	double R1, I1, R2, I2;
	double modsum, modsub, angsum, angsub;
	double AI1, AI2, AD1, AD2;
	double PI1, PI2, PD1, PD2;

	printf ("F(t) = A cos(Bt + C)\n");
	printf ("A: ");
	scanf ("%lf", &A);
	printf ("B: ");
	scanf ("%lf", &B);
	printf ("C: ");
	scanf ("%lf", &C);

	printf ("\n");

	printf ("G(t) = D cos(Et + F)\n");
	printf ("D: ");
	scanf ("%lf", &D);
	printf ("E: ");
	scanf ("%lf", &E);
	printf ("F: ");
	scanf ("%lf", &F);

	R1 = A * cos (C * PI / 180.0);
	I1 = A * sin (C * PI / 180.0);

	R2 = D * cos (F * PI / 180.0);
	I2 = D * sin (F * PI / 180.0);

	modsum = hypot (R1 + R2, I1 + I2);
	modsub = hypot (R1 - R2, I1 - I2);

	angsum = atan2 ((R1 + R2) / modsum, (I1 + I2) / modsum) * 180.0 / PI;
	angsub = atan ((R1 - R2) / (I1 - I2)) * 180.0 / PI;
	
	AI1 = hypot (I1 * B, R1 * B);
	PI1 = atan2 (I1 * B / AI1, R1 * B / AI1) * 180.0 / PI;

	AD1 = hypot (I1 / B, R1 / B);
	PD1 = atan2 ((I1 / B) / AD1, (R1 / B) / AD1) * 180.0 / PI;

	AI2 = hypot (I2 * E, R2 * E);
	PI2 = atan2 (I2 * E / AI2, R2 * E / AI2) * 180.0 / PI;

	AD2 = hypot (I2 / E, R2 / E);
	PD2 = atan2 ((I2 / E) / AD2, (R2 / E) / AD2) * 180.0 / PI;

	printf ("\n\n");

	printf ("F = %.4lf < %.4lf°\n", A, C);
	printf ("G = %.4lf < %.4lf°\n", D, F);

	printf ("\n");

	printf ("F = (%.4lf) + (%.4lf)i\n", R1, I1);
	printf ("G = (%.4lf) + (%.4lf)i\n", R2, I2);

	printf ("\n");
	
	if (A != 0)
		printf ("1/F = %.4lf < %.4lf°\n", 1/A, -C);
	else
		printf ("1/F = -\n", 1/A, -C);

	if (D != 0)
		printf ("1/G = %.4lf < %.4lf°\n", 1/D, -F);
	else
		printf ("1/G = -\n", 1/D, -F);

	printf ("\n");

	printf ("F+G = %.4lf < %.4lf°\n", modsum, + 90 - angsum);
	printf ("F-G = %.4lf < %.4lf°\n", modsub, - 90 - angsub);

	printf ("\n");

	printf ("F*G = %.4lf < %.4lf°\n", A * D, C + F);
	printf ("F/G = %.4lf < %.4lf°\n", A / D, C - F);

	printf ("\n");
	
	printf ("Derivada F = %.4lf < %.4lf°\n", AD1, PD1);
	printf ("Derivada G = %.4lf < %.4lf°\n", AD2, PD2);

	printf ("\n");

	printf ("Integral F = %.4lf < %.4lf°\n", AI1, PI1);
	printf ("Integral G = %.4lf < %.4lf°\n", AI2, PI2);

	printf ("\n");

}

void DivisorT () {

	double R1, R2, V;

	printf ("R1: ");
	scanf ("%lf", &R1);
	printf ("R2: ");
	scanf ("%lf", &R2);
	printf ("V: ");
	scanf ("%lf", &V);

	printf ("\n\n");

	printf ("V1: %.4lf V\n", R1 * V / (R1 + R2));
	printf ("V2: %.4lf V\n", R2 * V / (R1 + R2));

	printf ("\n");

}


void DivisorC () {

	double R1, R2, I;

	printf ("R1: ");
	scanf ("%lf", &R1);
	printf ("R2: ");
	scanf ("%lf", &R2);
	printf ("I: ");
	scanf ("%lf", &I);

	printf ("\n\n");

	printf ("I1: %.4lf A\n", R2 * I / (R1 + R2));
	printf ("I2: %.4lf A\n", R1 * I / (R1 + R2));

	printf ("\n");

}

int main() {

	int option, i = 0;

	while (1) {

		if (i == 0) {
			Clear ();
			i++;
		}

		Menu ();
		printf ("Opção: ");
		scanf ("%d", &option);
		Clear ();

		switch (option) {

			case 1:
				EstrelaDelta ();
			break;
				
			case 2:
				DeltaEstrela ();
			break;
				
			case 3:
				Fasor ();
			break;

			case 4:
				DivisorT ();
			break;

			case 5:
				DivisorC ();
			break;

			case 6:
				Clear ();
			break;

			case 7:
				exit (0);
			break;

			default:
				exit (0);
				
		}
	}

	return 0;
}
