#include "NumCalc.h"
#include <iomanip>


int NumCalc::numRandom(int minimo, int maximo) {

	return rand() % ((maximo + 1) - minimo) + minimo;
}


int NumCalc::numMax(int a, int b)
{

	if (a > b)
		return a;
	if (b > a)
		return b;

}
