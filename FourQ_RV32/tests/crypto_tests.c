/***********************************************************************************
* FourQlib: a high-performance crypto library based on the elliptic curve FourQ
*
*    Copyright (c) Microsoft Corporation. All rights reserved.
*
* Abstract: testing code for cryptographic functions based on FourQ 
************************************************************************************/   

#include <stdlib.h>

#include "../FourQ_api.h"
#include "../FourQ_params.h"
#include "test_extras.h"
#include "print.h"

// Benchmark and test parameters  
#if defined(GENERIC_IMPLEMENTATION)
    #define BENCH_LOOPS       1       // Number of iterations per bench
    #define TEST_LOOPS        1       // Number of iterations per test
#else 
    #define BENCH_LOOPS       1
    #define TEST_LOOPS        1
#endif

// #define print_str printf
// #define print_dec printf

ECCRYPTO_STATUS SchnorrQ_test()
{ // Test the SchnorrQ digital signature scheme
    int n, passed;       
    void *msg = NULL; 
    unsigned int len, valid = false;
    unsigned char SecretKey[32], PublicKey[32], Signature[64];
    ECCRYPTO_STATUS Status = ECCRYPTO_SUCCESS;

    print_str("\n--------------------------------------------------------------------------------------------------------\n\n"); 
    print_str("Testing the SchnorrQ signature scheme: \n\n"); 

    passed = 1;
    for (n = 0; n < TEST_LOOPS; n++)
    {    
        // Signature key generation
        Status = SchnorrQ_FullKeyGeneration(SecretKey, PublicKey);
        if (Status != ECCRYPTO_SUCCESS) {
            passed = 0;
            break;
        }  

        // Signature computation
        msg = "a";  
        len = 1;
        Status = SchnorrQ_Sign(SecretKey, PublicKey, msg, len, Signature);
        if (Status != ECCRYPTO_SUCCESS) {
            passed = 0;
            break;
        }    

        // Valid signature test
        Status = SchnorrQ_Verify(PublicKey, msg, len, Signature, &valid);
        if (Status != ECCRYPTO_SUCCESS) {
            passed = 0;
            break;
        }    

        if (valid == false) {
            passed = 0;
            break;
        }

        // Invalid signature test (flipping one bit of the message)
        msg = "b";  
        Status = SchnorrQ_Verify(PublicKey, msg, len, Signature, &valid);
        if (Status != ECCRYPTO_SUCCESS) {
            passed = 0;
            break;
        }

        if (valid == true) {
            passed = 0;
            break;
        }
    } 
    if (passed==1) print_str("  Signature tests.................................................................. PASSED");
    else { print_str("  Signature tests... FAILED"); print_str("\n"); Status = ECCRYPTO_ERROR_SIGNATURE_VERIFICATION; }
    print_str("\n");
    
    return Status;
}


ECCRYPTO_STATUS SchnorrQ_run()
{ // Benchmark the SchnorrQ digital signature scheme 
    int n;
    unsigned long long nsec, nsec1, nsec2;   
    void *msg = NULL;
    unsigned int len = 0, valid = false;
    unsigned char SecretKey[32], PublicKey[32], Signature[64];
    ECCRYPTO_STATUS Status = ECCRYPTO_SUCCESS;

    print_str("\n--------------------------------------------------------------------------------------------------------\n\n"); 
    print_str("Benchmarking the SchnorrQ signature scheme: \n\n"); 
    
    nsec = 0;
    for (n = 0; n < BENCH_LOOPS; n++)
    {
        nsec1 = cpu_nseconds(); 
        Status = SchnorrQ_FullKeyGeneration(SecretKey, PublicKey);
        if (Status != ECCRYPTO_SUCCESS) {
            return Status;
        }    
        nsec2 = cpu_nseconds();
        nsec = nsec+(nsec2-nsec1);
    }
    print_str("  SchnorrQ's key generation runs in ............................................... ");
    print_dec(nsec);
    print_str(" clk \n");
    
    nsec = 0;
    for (n = 0; n < BENCH_LOOPS; n++)
    {
        nsec1 = cpu_nseconds(); 
        Status = SchnorrQ_Sign(SecretKey, PublicKey, msg, len, Signature);
        if (Status != ECCRYPTO_SUCCESS) {
            return Status;
        }    
        nsec2 = cpu_nseconds();
        nsec = nsec+(nsec2-nsec1);
    }

    print_str("  SchnorrQ's signing runs in ............................................... ");
    print_dec(nsec);
    print_str(" clk \n");

    nsec = 0;
    for (n = 0; n < BENCH_LOOPS; n++)
    {
        nsec1 = cpu_nseconds(); 
        Status = SchnorrQ_Verify(PublicKey, msg, len, Signature, &valid);
        if (Status != ECCRYPTO_SUCCESS) {
            return Status;
        }    
        nsec2 = cpu_nseconds();
        nsec = nsec+(nsec2-nsec1);
    }

    print_str("  SchnorrQ's verification runs in ............................................... ");
    print_dec(nsec);
    print_str(" clk \n");
    
    return Status;
}


ECCRYPTO_STATUS compressedkex_test()
{ // Test ECDH key exchange based on FourQ
	int n, passed;
	unsigned int i;
	unsigned char SecretKeyA[32], PublicKeyA[32], SecretAgreementA[32];
	unsigned char SecretKeyB[32], PublicKeyB[32], SecretAgreementB[32];
	ECCRYPTO_STATUS Status = ECCRYPTO_SUCCESS;

	print_str("\n--------------------------------------------------------------------------------------------------------\n\n");
	print_str("Testing DH key exchange using compressed, 32-byte public keys: \n\n");

	passed = 1;
	for (n = 0; n < TEST_LOOPS; n++)
	{
		// Alice's keypair generation
		Status = CompressedKeyGeneration(SecretKeyA, PublicKeyA);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}
		// Bob's keypair generation
		Status = CompressedKeyGeneration(SecretKeyB, PublicKeyB);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}

		// Alice's shared secret computation
		Status = CompressedSecretAgreement(SecretKeyA, PublicKeyB, SecretAgreementA);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}

		// Bob's shared secret computation
		Status = CompressedSecretAgreement(SecretKeyB, PublicKeyA, SecretAgreementB);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}

		for (i = 0; i < 32; i++) {
		    if (SecretAgreementA[i] != SecretAgreementB[i]) {
				passed = 0;
				break;
			}
		}
	}
	if (passed==1) print_str("  DH key exchange tests............................................................ PASSED");
	else { print_str("  DH key exchange tests... FAILED"); print_str("\n"); Status = ECCRYPTO_ERROR_SHARED_KEY; }
	print_str("\n");

	return Status;
}


ECCRYPTO_STATUS compressedkex_run()
{ // Benchmark ECDH key exchange based on FourQ 
	int n;
	unsigned long long nsec, nsec1, nsec2;
	unsigned char SecretKeyA[32], PublicKeyA[32], SecretAgreementA[32];
	unsigned char SecretKeyB[32], PublicKeyB[32];
	ECCRYPTO_STATUS Status = ECCRYPTO_SUCCESS;

	print_str("\n--------------------------------------------------------------------------------------------------------\n\n");
	print_str("Benchmarking DH key exchange using compressed, 32-byte public keys: \n\n");

	nsec = 0;
	for (n = 0; n < BENCH_LOOPS; n++)
	{
		nsec1 = cpu_nseconds();
		Status = CompressedKeyGeneration(SecretKeyA, PublicKeyA);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}
		nsec2 = cpu_nseconds();
		nsec = nsec + (nsec2 - nsec1);
	}

    print_str("  Keypair generation runs in ............................................... ");
    print_dec(nsec);
    print_str(" clk \n");
	
	Status = CompressedKeyGeneration(SecretKeyB, PublicKeyB);
	nsec = 0;
	for (n = 0; n < BENCH_LOOPS; n++)
	{
		nsec1 = cpu_nseconds();
		Status = CompressedSecretAgreement(SecretKeyA, PublicKeyB, SecretAgreementA);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}
		nsec2 = cpu_nseconds();
		nsec = nsec + (nsec2 - nsec1);
	}
    print_str("  Secret agreement runs in ............................................... ");
    print_dec(nsec);
    print_str(" clk \n");

	return Status;
}


ECCRYPTO_STATUS kex_test()
{ // Test ECDH key exchange based on FourQ
	int n, passed;
	unsigned int i;
	unsigned char SecretKeyA[32], PublicKeyA[64], SecretAgreementA[32];
	unsigned char SecretKeyB[32], PublicKeyB[64], SecretAgreementB[32];
	ECCRYPTO_STATUS Status = ECCRYPTO_SUCCESS;

	print_str("\n--------------------------------------------------------------------------------------------------------\n\n");
	print_str("Testing DH key exchange using uncompressed, 64-byte public keys: \n\n");

	passed = 1;
	for (n = 0; n < TEST_LOOPS; n++)
	{
		// Alice's keypair generation
		Status = KeyGeneration(SecretKeyA, PublicKeyA);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}
		// Bob's keypair generation
		Status = KeyGeneration(SecretKeyB, PublicKeyB);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}

		// Alice's shared secret computation
		Status = SecretAgreement(SecretKeyA, PublicKeyB, SecretAgreementA);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}
		// Bob's shared secret computation
		Status = SecretAgreement(SecretKeyB, PublicKeyA, SecretAgreementB);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}

		for (i = 0; i < 32; i++) {
			if (SecretAgreementA[i] != SecretAgreementB[i]) {
				passed = 0;
				break;
			}
		}
	}
	if (passed==1) print_str("  DH key exchange tests............................................................ PASSED");
	else { print_str("  DH key exchange tests... FAILED"); print_str("\n"); Status = ECCRYPTO_ERROR_SHARED_KEY; }
	print_str("\n");

	return Status;
}


ECCRYPTO_STATUS kex_run()
{ // Benchmark ECDH key exchange based on FourQ 
	int n;
	unsigned long long nsec, nsec1, nsec2;
	unsigned char SecretKeyA[32], PublicKeyA[64], SecretAgreementA[32];
	unsigned char SecretKeyB[32], PublicKeyB[64];
	ECCRYPTO_STATUS Status = ECCRYPTO_SUCCESS;

	print_str("\n--------------------------------------------------------------------------------------------------------\n\n");
	print_str("Benchmarking DH key exchange using uncompressed, 64-byte public keys: \n\n");

	nsec = 0;
	for (n = 0; n < BENCH_LOOPS; n++)
	{
		nsec1 = cpu_nseconds();
		Status = KeyGeneration(SecretKeyA, PublicKeyA);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}
		nsec2 = cpu_nseconds();
		nsec = nsec + (nsec2 - nsec1);
	}
    print_str("  Keypair generation runs in ............................................... ");
    print_dec(nsec);
    print_str(" clk \n");

	Status = KeyGeneration(SecretKeyB, PublicKeyB);
	nsec = 0;
	for (n = 0; n < BENCH_LOOPS; n++)
	{
		nsec1 = cpu_nseconds();
		Status = SecretAgreement(SecretKeyA, PublicKeyB, SecretAgreementA);
		if (Status != ECCRYPTO_SUCCESS) {
			return Status;
		}
		nsec2 = cpu_nseconds();
		nsec = nsec + (nsec2 - nsec1);
	}
    print_str("  Secret agreement runs in ............................................... ");
    print_dec(nsec);
    print_str(" clk \n");

	return Status;
}


int main()
{
    ECCRYPTO_STATUS Status = ECCRYPTO_SUCCESS;

/*


    Status = SchnorrQ_test();         // Test SchnorrQ signature scheme
    if (Status != ECCRYPTO_SUCCESS) {
        return false;
    }
*/
    Status = SchnorrQ_run();          // Benchmark SchnorrQ signature scheme
    if (Status != ECCRYPTO_SUCCESS) {
		print_str("\n\n   Error detected: compressedkex_run \n\n");
        return false;
    }
/*	Status = compressedkex_test();    // Test Diffie-Hellman key exchange using compressed public keys
	if (Status != ECCRYPTO_SUCCESS) {
		printf("\n\n   Error detected: %s \n\n", FourQ_get_error_message(Status));
		return false;
	}
*/

	Status = compressedkex_run();     // Benchmark Diffie-Hellman key exchange using compressed public keys
	if (Status != ECCRYPTO_SUCCESS) {
		print_str("\n\n   Error detected: compressedkex_run \n\n");
		return false;
	}

/*
	Status = kex_test();              // Test Diffie-Hellman key exchange using uncompressed public keys
	if (Status != ECCRYPTO_SUCCESS) {
//		printf("\n\n   Error detected: %s \n\n", FourQ_get_error_message(Status));
		return false;
	}
*/
	Status = kex_run();               // Benchmark Diffie-Hellman key exchange using uncompressed public keys
	if (Status != ECCRYPTO_SUCCESS) {
		print_str("\n\n   Error detected: kex_run \n\n");
		return false;
	}
    return true;
}