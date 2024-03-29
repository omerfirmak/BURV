/***********************************************************************************
* FourQlib: a high-performance crypto library based on the elliptic curve FourQ
*
*    Copyright (c) Microsoft Corporation. All rights reserved.
*
* Abstract: testing code for FourQ's field arithmetic 
************************************************************************************/    

#include "../FourQ_internal.h"
#include "test_extras.h"

#include "print.h"
#include "encoding.h"

// Benchmark and test parameters 
#define BENCH_LOOPS       1      // Number of iterations per bench
#define SHORT_BENCH_LOOPS 1       // Number of iterations per bench (for expensive operations)
#define TEST_LOOPS        1       // Number of iterations per test


bool fp2_test()
{ // Tests for the quadratic extension field arithmetic
    bool OK = true;
    int n, passed;
    f2elm_t a, b, c, d, e, f;

    print_str("\n--------------------------------------------------------------------------------------------------------\n\n"); 
    print_str("Testing quadratic extension field arithmetic over GF((2^127-1)^2): \n\n"); 

    // GF(p^2) multiplication using p = 2^127-1
    passed = 1;
    for (n=0; n<TEST_LOOPS; n++)
    {    
        fp2random1271_test(a); fp2random1271_test(b); fp2random1271_test(c); 
        fp2random1271_test(d); fp2random1271_test(e); fp2random1271_test(f);
       
        fp2mul1271(a, b, d);                                             // d = a*b 
        mod1271(d[0]); mod1271(d[1]);
        fp2mul1271(b, a, e);                                             // e = b*a 
        mod1271(e[0]); mod1271(e[1]);
        if (fp2compare64((uint64_t*)d,(uint64_t*)e)!=0) { passed=0; break; }
        
        fp2mul1271(a, b, d); fp2mul1271(d, c, e);                        // e = (a*b)*c
        mod1271(e[0]); mod1271(e[1]);
        fp2mul1271(b, c, d); fp2mul1271(d, a, f);                        // f = a*(b*c)
        mod1271(f[0]); mod1271(f[1]);
        if (fp2compare64((uint64_t*)e,(uint64_t*)f)!=0) { passed=0; break; }
      
        fp2add1271(b, c, d); fp2mul1271(a, d, e);                        // e = a*(b+c)
        mod1271(e[0]); mod1271(e[1]);
        fp2mul1271(a, b, d); fp2mul1271(a, c, f); fp2add1271(d, f, f);   // f = a*b+a*c
        mod1271(f[0]); mod1271(f[1]);
        if (fp2compare64((uint64_t*)e,(uint64_t*)f)!=0) { passed=0; break; }
        
        fp2zero1271(b); b[0][0] = 1;
        fp2mul1271(a, b, d);                                             // d = a*1 
        mod1271(d[0]); mod1271(d[1]);                                                                     
        if (fp2compare64((uint64_t*)a,(uint64_t*)d)!=0) { passed=0; break; }
        
        fp2zero1271(b);
        fp2mul1271(a, b, d);                                             // d = a*0  
        mod1271(d[0]); mod1271(d[1]); 
        if (fp2compare64((uint64_t*)b,(uint64_t*)d)!=0) { passed=0; break; }
    }
    if (passed==1) print_str("  GF(p^2) multiplication tests .................................................................... PASSED");
    else { print_str("  GF(p^2) multiplication tests... FAILED"); print_str("\n"); return false; }
    print_str("\n");
    
    // GF(p^2) squaring using p = 2^127-1
    passed = 1;
    for (n=0; n<TEST_LOOPS; n++)
    {
        fp2random1271_test(a); fp2random1271_test(b); fp2random1271_test(c);

        fp2sqr1271(a, b);                                            // b = a^2
        fp2mul1271(a, a, c);                                         // c = a*a 
        if (fp2compare64((uint64_t*)b,(uint64_t*)c)!=0) { passed=0; break; }
        
        fp2zero1271(a);
        fp2sqr1271(a, d);                                            // d = 0^2 
        if (fp2compare64((uint64_t*)a,(uint64_t*)d)!=0) { passed=0; break; }
    }
    if (passed==1) print_str("  GF(p^2) squaring tests........................................................................... PASSED");
    else { print_str("  GF(p^2) squaring tests... FAILED"); print_str("\n"); return false; }
    print_str("\n");

    // GF(p^2) inversion using p = 2^127-1
    passed = 1;
    for (n=0; n<TEST_LOOPS; n++)
    {
        fp2random1271_test(a);  
        
        fp2zero1271(d); d[0][0] = 1;           
        fp2copy1271(a, b);                        
        fp2inv1271(a);                                
        fp2mul1271(a, b, c);                                        // c = a*a^-1 = 1
        mod1271(c[0]); mod1271(c[1]);
        if (fp2compare64((uint64_t*)c,(uint64_t*)d)!=0) { passed=0; break; }
    }
    if (passed==1) print_str("  GF(p^2) inversion tests.......................................................................... PASSED");
    else { print_str("  GF(p^2) inversion tests... FAILED"); print_str("\n"); return false; }
    print_str("\n");
    
    return OK;
}


bool fp2_run()
{
    bool OK = true;
    int n, i;
    unsigned long long nsec, nsec1, nsec2;
    f2elm_t a, b, c, d, e, f;
        
    print_str("\n--------------------------------------------------------------------------------------------------------\n\n"); 
    print_str("Benchmarking quadratic extension field arithmetic over GF((2^127-1)^2): \n\n"); 

/*
    // GF(p^2) addition using p = 2^127-1
    nsec = 0;
    fp2random1271_test(a); fp2random1271_test(b);
    nsec1 = cpu_nseconds();
    fp2add1271(a, b, c);
    nsec2 = cpu_nseconds();
    nsec = nsec+(nsec2-nsec1);

    print_str("  GF(p^2) addition runs in ............... ");
    print_dec(nsec);
    print_str("clk\n"); 

    // GF(p^2) subtraction using p = 2^127-1
    nsec = 0;
    fp2random1271_test(a); fp2random1271_test(b);  
    nsec1 = cpu_nseconds();
    fp2sub1271(a, b, c);
    nsec2 = cpu_nseconds();
    nsec = nsec+(nsec2-nsec1);

    print_str("  GF(p^2) subtraction runs in ............... ");
    print_dec(nsec);
    print_str("clk\n"); 
*/
    // GF(p^2) squaring using p = 2^127-1
    nsec = 0;
    fp2random1271_test(a);         
    nsec1 = cpu_nseconds();
    fp2sqr1271(a, b);
    nsec2 = cpu_nseconds();
    nsec = nsec2-nsec1;
    
    print_str("  GF(p^2) squaring runs in ............... ");
    print_dec(nsec);
    print_str(" clk\n"); 

    // GF(p^2) multiplication using p = 2^127-1
    nsec = 0;
    fp2random1271_test(a); fp2random1271_test(b); fp2random1271_test(c);
    nsec1 = cpu_nseconds();
    fp2mul1271(a, b, c);
    nsec2 = cpu_nseconds();
    nsec = nsec2-nsec1;

    print_str("  GF(p^2) multiplication runs in ............... ");
    print_dec(nsec);
    print_str(" clk\n"); 


    // GF(p^2) inversion using p = 2^127-1
    nsec = 0;
    fp2random1271_test(a); fp2random1271_test(b); fp2random1271_test(c);  
    nsec1 = cpu_nseconds();
    fp2inv1271(a);
    nsec2 = cpu_nseconds();
    nsec = nsec2-nsec1;
    
    print_str("  GF(p^2) inversion runs in ............... ");
    print_dec(nsec);
    print_str(" clk\n"); 
    
    return OK;
}


int main()
{
    bool OK = true;

#if (HARD_GF == 2)
	write_csr(0x800, 1);
#endif

    OK = OK && fp2_test();     // Test quadratic extension field operations using p = 2^127-1
    OK = OK && fp2_run();      // Benchmark quadratic extension field operations using p = 2^127-1
    
    return OK;
}
