#include <stdint.h>

#define hgio ((volatile gpio_t * const)0x100000)

typedef struct
{
	uint32_t dir;
	uint32_t data;
} gpio_t;
