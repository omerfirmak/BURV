#include "gpio.h"

int main()
{
	while (1) {
		hgio->data ^= 1;
		for (unsigned long long i = 0; i < 1000000000UL; i++);
	}
}
