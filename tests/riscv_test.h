#ifndef _ENV_PICORV32_TEST_H
#define _ENV_PICORV32_TEST_H

#ifndef TEST_FUNC_NAME
#  define TEST_FUNC_NAME mytest
#  define TEST_FUNC_TXT "mytest"
#  define TEST_FUNC_RET mytest_ret
#endif

#define RVTEST_RV32U
#define TESTNUM x14

#define RVTEST_CODE_BEGIN		\
	.text;
	
#define RVTEST_PASS			\
	addi	a1,zero,'O';		\
	addi	a2,zero,'K';		\
	addi	a3,zero,'\n';		\
	ebreak;

#define RVTEST_FAIL			\
	addi	a1,zero,'E';		\
	addi	a2,zero,'R';		\
	addi	a3,zero,'O';		\
	addi	a4,zero,'\n';		\
	ebreak;

#define RVTEST_CODE_END
#define RVTEST_DATA_BEGIN .balign 4;
#define RVTEST_DATA_END

#endif
