MODULE = riscv_top

TECH=osu018

COMMON_SRC = ./source/mem_bus_arbiter.v ./source/dp_ram.v ./source/dp_rom.v ./source/riscv_top.v ./source/uart.v ./source/uart_wrap.v ./source/gpio.v

VERILOG_SRC = 	./source/alu.v 				\
				./source/reg_file.v			\
				./source/riscv_core.v			\
				./source/riscv_core_axi.v			\
				./source/decoder.v			\
				./source/decompressor.v			\
				./source/controller.v			\
				./source/lsu.v			\
				./source/csr.v			\
				./source/fetch_stage.v		\
				./source/realign_buffer.v 	\
				./source/mont_mul.v 	\
				./source/axilite_master.v

POST_SYNTH_SRC = ./riscv_core.rtlnopwr.v 	\
			  	 /usr/local/share/qflow/tech/osu018/osu018_stdcells.v	

PULP_CORE_DIR = ./zeroriscy
PULP_SRCS = $(addprefix $(PULP_CORE_DIR)/, \
include/zeroriscy_defines.sv \
include/zeroriscy_tracer_defines.sv \
cluster_clock_gating.sv \
zeroriscy_alu.sv \
zeroriscy_compressed_decoder.sv \
zeroriscy_controller.sv \
zeroriscy_cs_registers.sv \
zeroriscy_debug_unit.sv \
zeroriscy_decoder.sv \
zeroriscy_int_controller.sv \
zeroriscy_ex_block.sv \
zeroriscy_id_stage.sv \
zeroriscy_if_stage.sv \
zeroriscy_load_store_unit.sv \
zeroriscy_multdiv_fast.sv \
zeroriscy_prefetch_buffer.sv \
zeroriscy_register_file_ff.sv \
zeroriscy_tracer.sv \
zeroriscy_fetch_fifo.sv \
zeroriscy_core.sv \
)

SIM_SRC = $(PULP_SRCS)


TESTNAMES = $(wildcard ./tests/*.S)

ECC_WORD_COUNT = 8
HARD_GF = 1
DUMP_TRACE = 1
BOOT_ADDRESS = 0
MEM_SIZE = 524288
#MEM_SIZE = 262144
DEFINE_FLAGS = -DECC_WORD_COUNT=$(ECC_WORD_COUNT) -DBOOT_ADDRESS=$(BOOT_ADDRESS) -DMEM_SIZE=$(MEM_SIZE) -DDUMP_TRACE=$(DUMP_TRACE) -DMEM_ORIGIN=$(MEM_ORIGIN) -DMEM_LENGTH=$(MEM_LENGTH) -DSTACK_LENGTH=$(STACK_LENGTH) -DSTACK_ORIGIN=$(STACK_ORIGIN) -DHARD_GF=$(HARD_GF)

all: firmware sim_iverilog
test: compile_test sim_verilator

clean:
	rm -rf $(shell (cat .gitignore))

lint:
	verilator $(DEFINE_FLAGS) -I./source --lint-only $(SIM_SRC) $(COMMON_SRC) --top-module $(MODULE)

MEM_ORIGIN=0
MEM_LENGTH=\(MEM_SIZE-STACK_LENGTH\)
STACK_LENGTH=98304
STACK_ORIGIN=\(MEM_SIZE-STACK_LENGTH\)
CFLAGS = -O2 -falign-functions=4 -falign-jumps=4 -falign-labels=4 -funroll-all-loops #-fdata-sections -ffunction-sections -Wl,--gc-sections

COMMON_C_SRC = software/start.S software/handlers.c software/print.c

compile_test: CFLAGS += -nostdlib
compile_test: COMMON_C_SRC = 
bootrom: CFLAGS=-Os -fdata-sections -ffunction-sections -Wl,--gc-sections
bootrom: MEM_SIZE=2048
bootrom: MEM_ORIGIN=0x100000
bootrom: MEM_LENGTH=MEM_SIZE 
bootrom: STACK_ORIGIN=0 
bootrom: STACK_LENGTH=MEM_SIZE 
bootrom: SRC=software/bootrom.c
compile_test bootrom firmware: prepare_ld
	/home/omer/riscv_e/bin/riscv32-unknown-elf-gcc -I./software $(CFLAGS) $(DEFINE_FLAGS) -march=rv32e -mabi=ilp32e -nostartfiles -T software/out.ld $(COMMON_C_SRC) $(SRC) -o firmware.elf 
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D firmware.elf > firmware.dump
	riscv32-unknown-elf-objcopy -O binary firmware.elf firmware.bin
	riscv32-unknown-elf-objcopy -O ihex firmware.elf firmware.ihex
	cat firmware.bin | od -t x4 -w4 -v -A n > firmware.txt

test_all:
	$(foreach var,$(TESTNAMES), echo "Test Name:$(var)"; make DUMP_TRACE=0 SRC=$(var) compile_test sim_iverilog;)

COREMARK_SRC =  coremark/core_list_join.c \
				coremark/core_main.c \
				coremark/core_matrix.c \
				coremark/core_portme.c \
				coremark/core_state.c \
				coremark/core_util.c \
				coremark/cvt.c \
				coremark/ee_printf.c

FOURQ_SRC = FourQ_RV32/random/random.c \
			FourQ_RV32/sha512/sha512.c \
			FourQ_RV32/tests/$(FOURQ_TEST).c \
			FourQ_RV32/tests/test_extras.c \
			FourQ_RV32/crypto_util.c \
			FourQ_RV32/eccp2.c \
			FourQ_RV32/eccp2_no_endo.c \
			FourQ_RV32/kex.c \
			FourQ_RV32/schnorrq.c \
			FourQ_RV32/tests/blake2/*.c

C25519_SRC = CycloneCrypto/ecc/curve25519.c \
			 CycloneCrypto/ecc/ed25519.c \
			 CycloneCrypto/hash/sha512.c \
			 CycloneCrypto/common/os_port_none.c \
		 	 CycloneCrypto/common/cpu_endian.c \
		 	 CycloneCrypto/main.c

P256_SRC =  tinycrypt/tests/test_ecc_dsa.c \
			tinycrypt/tests/test_ecc_utils.c \
			tinycrypt/source/*.c

# g++ -I./ -I./common ./ecc/curve25519.c ./ecc/ed25519.c ./hash/sha512.c ./common/os_port_none.c ./common/cpu_endian.c main.c

p256:	   CFLAGS += --std=gnu99 -I./tinycrypt/include -I./tinycrypt/tests/include
p256:	   SRC=$(P256_SRC)
c25519:	   CFLAGS += -ICycloneCrypto/ -ICycloneCrypto/common
c25519:	   SRC=$(C25519_SRC)
fourq:     CFLAGS += -fwrapv -fomit-frame-pointer -D_RV32_ -D__OSNONE__ -DUSE_ENDO -D_NO_CACHE_MEM_ -I./FourQ_RV32 -I./FourQ_RV32/tests/blake2
fourq:     SRC=$(FOURQ_SRC)
fourq:	   ECC_WORD_COUNT = 4
coremark:  SRC=$(COREMARK_SRC)
dhrystone: SRC=dhrystone/dhrystone.c dhrystone/dhrystone_main.c
p256 c25519 fourq coremark dhrystone: DUMP_TRACE=0
p256 c25519 fourq coremark dhrystone: firmware sim_verilator

sim_verilator: compile_verilator
	-./obj_dir/V$(MODULE)

compile_verilator:
	verilator -O3 --Wno-fatal $(DEFINE_FLAGS) --cc --trace --x-assign unique $(SIM_SRC) $(COMMON_SRC) -I./source -I$(PULP_CORE_DIR)/include --exe $(MODULE)_tb.cpp --top-module $(MODULE)
	make CXXFLAGS="$(DEFINE_FLAGS)" -j -C obj_dir/ -f V$(MODULE).mk V$(MODULE)

sim_iverilog: compile_iverilog
	vvp iv_exec

compile_iverilog:
	iverilog $(DEFINE_FLAGS) -g2012 -I./source -I$(PULP_CORE_DIR)/include $(SIM_SRC) $(COMMON_SRC) riscv_top_tb.v -o iv_exec

synth_vivado:
	vivado -mode batch -nojournal -nolog -source vivado_synth.tcl

synth:
	qflow synthesize --tech $(TECH) riscv_core > /dev/null

sta:
	qflow sta --tech $(TECH) riscv_core > /dev/null

prepare_ld:
	gcc -E -x c $(DEFINE_FLAGS) software/link.ld | grep -v '^#' > software/out.ld

synth_fpga:
	yosys -ql synth_fpga.log -p 'synth_ice40 -top riscv_top; write_verilog synth.v' $(SIM_SRC) $(COMMON_SRC)

gcc_fourq:
	gcc -O3 -fwrapv -fomit-frame-pointer -funroll-loops -D_RV32_ -D__OSNONE__ -DUSE_ENDO=1 -D_NO_CACHE_MEM_ -I./FourQ_RV32 $(CFLAGS) $(DEFINE_FLAGS) $(FOURQ_SRC)

sim_mmul:
	iverilog -g2012 -I./source ./source/mont_mul.v ./source/dp_ram.v mont_mul_tb.v -o iv_exec
	vvp iv_exec
