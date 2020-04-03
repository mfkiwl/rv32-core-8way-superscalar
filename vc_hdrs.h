#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>
#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _VC_TYPES_
#define _VC_TYPES_
/* common definitions shared with DirectC.h */

typedef unsigned int U;
typedef unsigned char UB;
typedef unsigned char scalar;
typedef struct { U c; U d;} vec32;

#define scalar_0 0
#define scalar_1 1
#define scalar_z 2
#define scalar_x 3

extern long long int ConvUP2LLI(U* a);
extern void ConvLLI2UP(long long int a1, U* a2);
extern long long int GetLLIresult();
extern void StoreLLIresult(const unsigned int* data);
typedef struct VeriC_Descriptor *vc_handle;

#ifndef SV_3_COMPATIBILITY
#define SV_STRING const char*
#else
#define SV_STRING char*
#endif

#endif /* _VC_TYPES_ */

void print_header(const char* str);
void print_cycles(int cycle_count);
void print_stage(const char* div, int inst, int valid_inst);
void print_rs(const char* div, int inst, int valid_inst, int num_free, int load_in_hub, int is_free_hub, int ready_hub);
void print_rob(const char* div, int except, int direction, int PC, int num_free, int dest_ARN_out, int valid_out);
void print_ex_out(const char* div, int alu_result, int valid, int alu_occupied, int brand_results);
void print_valids(int opa_valid, int opb_valid);
void print_opaopb(int opa_valid, int opb_valid, int rs1_value, int rs2_value);
void print_reg(int wb_reg_wr_data_out_hi, int wb_reg_wr_data_out_lo, int wb_reg_wr_idx_out, int wb_reg_wr_en_out);
void print_membus(int proc2mem_command, int mem2proc_response, int proc2mem_addr_hi, int proc2mem_addr_lo, int proc2mem_data_hi, int proc2mem_data_lo);
void print_close();

#ifdef __cplusplus
}
#endif

