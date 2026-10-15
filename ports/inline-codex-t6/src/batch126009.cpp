#include "ff.h"
extern "C" double ext_634dca(double);
static long double powx(long double base,long double exponent){
 long double result;asm volatile("fldt %1; fldt %2; call ext_634e00; fstpt %0":"=m"(result):"m"(base),"m"(exponent):"eax","ecx","edx","st","st(1)");return result;
}
static void curve(float* source,float* output,s32 n,float scale){
 s32 index=0;
 for(s32 k=1;k<=26;++k){float x=(float)k;
 long double value=(long double)x*G(float,0x6be050);
 value=value-2*powx(x,G(double,0x6be028));
 value=value+powx(x,G(double,0x6be048))*G(double,0x6be040);
 value=value+powx(G(double,0x6be038),x);
 value=value-G(double,0x6be018);value=value*(double)n;value=value+value;value=value/(long double)scale;value=value+G(double,0x6be020);
 s32 end=(s32)ext_634dca((double)value);
 long double sample=source[k-1];
 if(index<end){float delta=(float)(((long double)source[k]-sample)/(long double)(end-index));
 while(index<end && index<n){output[index]=sample;sample=sample+(long double)delta;++index;}}
 }
}
PCREG(4039c0,curve);

// Harness CRT stand-ins, shared by original and port.
asm(
    ".text\n"
    ".globl stub_ci_pow\n"
    "stub_ci_pow:\n"
    "  fxch %st(1)\n"
    "  fyl2x\n"
    "  fld %st(0)\n"
    "  frndint\n"
    "  fxch %st(1)\n"
    "  fsub %st(1), %st\n"
    "  f2xm1\n"
    "  fld1\n"
    "  faddp\n"
    "  fscale\n"
    "  fstp %st(1)\n"
    "  faddl stub_pow_bias\n"
    "  ret\n"
    ".globl stub_pow_bias\n"
    ".balign 8\n"
    "stub_pow_bias:\n"
    "  .double 0.0\n"
    ".globl stub_floor\n"
    "stub_floor:\n"
    "  subl $8, %esp\n"
    "  fnstcw (%esp)\n"
    "  movw (%esp), %ax\n"
    "  andw $0xf3ff, %ax\n"
    "  orw $0x0400, %ax\n"
    "  movw %ax, 2(%esp)\n"
    "  fldcw 2(%esp)\n"
    "  fldl 12(%esp)\n"
    "  frndint\n"
    "  fldcw (%esp)\n"
    "  addl $8, %esp\n"
    "  ret\n"
    ".globl stub_ftol\n"
    "stub_ftol:\n"
    "  subl $12, %esp\n"
    "  fnstcw (%esp)\n"
    "  movw (%esp), %ax\n"
    "  orw $0x0c00, %ax\n"
    "  movw %ax, 2(%esp)\n"
    "  fldcw 2(%esp)\n"
    "  fistpll 4(%esp)\n"
    "  fldcw (%esp)\n"
    "  movl 4(%esp), %eax\n"
    "  movl 8(%esp), %edx\n"
    "  addl $12, %esp\n"
    "  ret\n");
