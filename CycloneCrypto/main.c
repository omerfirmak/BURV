#include <stdio.h>

#include "encoding.h"
#include "print.h"

#include "core/crypto.h"
#include "common/error.h"
#include "ecc/ed25519.h"

/* typedef struct
{
   const char_t *name;
   size_t contextSize;
   PrngAlgoInit init;
   PrngAlgoRelease release;
   PrngAlgoSeed seed;
   PrngAlgoAddEntropy addEntropy;
   PrngAlgoRead read;
} PrngAlgo; */

_error_t _PrngAlgoInit(void *context) 
{
	return NO_ERROR;
}

void 	_PrngAlgoRelease(void *context)
{

}

_error_t _PrngAlgoSeed(void *context, const uint8_t *input, size_t length)
{
	return NO_ERROR;
}

_error_t _PrngAlgoAddEntropy(void *context, uint_t source, const uint8_t *input, size_t length, size_t entropy)
{
	return NO_ERROR;
}

_error_t _PrngAlgoRead(void *context, uint8_t *output, size_t length)
{
	static unsigned char x = 0;
	int i = 0;

	for (i = 0; i < length; i++) {
		output[i] = x++;
	}

	return NO_ERROR;
}

PrngAlgo _PrngAlgo = {
	.name = NULL,
	.contextSize = 0,
	.init = &_PrngAlgoInit,
	.release = &_PrngAlgoRelease,
	.seed = &_PrngAlgoSeed,
	.addEntropy = &_PrngAlgoAddEntropy,
	.read = &_PrngAlgoRead
};


int main(int argc, char const *argv[])
{
	uint32_t start, end;
	uint8_t ctxt;
	uint8_t msg = 'a';

#if (HARD_GF == 2)
	write_csr(0x800, 1);
#endif

	uint8_t privKey[ED25519_PRIVATE_KEY_LEN],
			pubKey[ED25519_PUBLIC_KEY_LEN],
			sign[ED25519_SIGNATURE_LEN];

	print_str("Starting C25519 benchmark..\n");


	start = read_csr(mcycle);
	_error_t err = ed25519GenerateKeyPair(&_PrngAlgo, &ctxt, privKey, pubKey);
	end = read_csr(mcycle);

	print_str("ed25519GenerateKeyPair runs in ");
	print_dec(end - start);
	print_str(" clk Error = ");
	print_dec(err);
	print_str("\n");

	start = read_csr(mcycle);
	err = ed25519GenerateSignature(privKey, pubKey, &msg, 1, NULL, 0, 0, sign);
	end = read_csr(mcycle);

	print_str("ed25519GenerateSignature runs in ");
	print_dec(end - start);
	print_str(" clk Error = ");
	print_dec(err);
	print_str("\n");


	print_str("\n SIGNATURE \n\n");
	for (int i = 0; i < ED25519_SIGNATURE_LEN; i++) {
		print_hex(sign[i],2);
	}
	print_str("\n\n");

	start = read_csr(mcycle);
	err = ed25519VerifySignature(pubKey, &msg, 1, NULL, 0, 0, sign);
	end = read_csr(mcycle);

	print_str("ed25519VerifySignature runs in ");
	print_dec(end - start);
	print_str(" clk Error = ");
	print_dec(err);
	print_str("\n");

	return 0;
}