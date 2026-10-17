__asm__(".text\n.globl w3e_vacall\nw3e_vacall:\n push %ebp\n mov %esp,%ebp\n push %esi\n mov 16(%ebp),%edx\n mov 20(%ebp),%esi\n1: test %edx,%edx\n jz 2f\n pushl -4(%esi,%edx,4)\n dec %edx\n jmp 1b\n2: mov 12(%ebp),%ecx\n call *8(%ebp)\n lea -4(%ebp),%esp\n pop %esi\n pop %ebp\n ret\n");
extern "C" unsigned w3e_vacall(unsigned fn, unsigned ecx_, unsigned n, const unsigned *a);
// batch230003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_58aa40_fastcall2(u32, u32) __asm__("ext_58aa40");
extern "C" u32 FASTCALL ext_58aaf0_fastcall2(u32, u32) __asm__("ext_58aaf0");
extern "C" u32 STDCALL ext_4947c0_stdcall1(u32) __asm__("ext_4947c0");
extern "C" u32 STDCALL ext_573ba0_stdcall1(u32) __asm__("ext_573ba0");
extern "C" u32 STDCALL ext_574af0_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_574af0");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_484d20_thiscall2(u32, u32) __asm__("ext_484d20");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4db2c0_thiscall3(u32, u32, u32) __asm__("ext_4db2c0");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1440_thiscall2(u32, u32) __asm__("ext_4e1440");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_5057e0_thiscall3(u32, u32, u32) __asm__("ext_5057e0");
extern "C" u32 THISCALL ext_562b50_thiscall2(u32, u32) __asm__("ext_562b50");
extern "C" u32 THISCALL ext_5761c0_thiscall2(u32, u32) __asm__("ext_5761c0");
extern "C" u32 THISCALL ext_589c20_thiscall2(u32, u32) __asm__("ext_589c20");
extern "C" u32 THISCALL ext_591d30_thiscall2(u32, u32) __asm__("ext_591d30");
extern "C" u32 THISCALL ext_59a5e0_thiscall2(u32, u32) __asm__("ext_59a5e0");
extern "C" u32 THISCALL ext_59d3f0_thiscall2(u32, u32) __asm__("ext_59d3f0");
extern "C" u32 THISCALL ext_59ffc0_thiscall1(u32) __asm__("ext_59ffc0");
extern "C" u32 THISCALL ext_5a4f70_thiscall3(u32, u32, u32) __asm__("ext_5a4f70");
extern "C" u32 THISCALL ext_5adee0_thiscall3(u32, u32, u32) __asm__("ext_5adee0");
extern "C" u32 THISCALL ext_5b7c70_thiscall2(u32, u32) __asm__("ext_5b7c70");
extern "C" u32 THISCALL ext_5b7eb0_thiscall2(u32, u32) __asm__("ext_5b7eb0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5947b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[94], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5947b0
  PV[0] = (u32)(ebx);  // @1_5947b0
  edi = ecx;  // @2_5947b0
  eax = ext_484d20_thiscall2(ecx, PV[0]);  // @3_5947b0
  ecx = edx = 0;  // @4_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_5947b0
  ecx = ebx;  // @6_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1619), sizeof v); (u32)v; });  // @7_5947b0
  PV[1] = (u32)(eax);  // @8_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[1]);  // @9_5947b0
  ecx = edx = 0;  // @10_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_5947b0
  ecx = ebx;  // @12_5947b0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1611), sizeof v); (u32)v; });  // @13_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[2]);  // @14_5947b0
  ecx = edx = 0;  // @15_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @16_5947b0
  ecx = ebx;  // @17_5947b0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1620), sizeof v); (u32)v; });  // @18_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[3]);  // @19_5947b0
  ecx = edx = 0;  // @20_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @21_5947b0
  ecx = ebx;  // @22_5947b0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1624), sizeof v); (u32)v; });  // @23_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[4]);  // @24_5947b0
  ecx = edx = 0;  // @25_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_5947b0
  ecx = ebx;  // @27_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1628), sizeof v); (u32)v; });  // @28_5947b0
  PV[5] = (u32)(eax);  // @29_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[5]);  // @30_5947b0
  ecx = edx = 0;  // @31_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_5947b0
  ecx = ebx;  // @33_5947b0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1659), sizeof v); (u32)v; });  // @34_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[6]);  // @35_5947b0
  ecx = edx = 0;  // @36_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_5947b0
  ecx = ebx;  // @38_5947b0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1664), sizeof v); (u32)v; });  // @39_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[7]);  // @40_5947b0
  ecx = edx = 0;  // @41_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_5947b0
  ecx = ebx;  // @43_5947b0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1676), sizeof v); (u32)v; });  // @44_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[8]);  // @45_5947b0
  ecx = edx = 0;  // @46_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1680), sizeof v); (u32)v; });  // @47_5947b0
  PV[9] = (u32)(ecx);  // @48_5947b0
  ecx = 0;  // @49_5947b0
  PV[10] = eax;  // @50_5947b0
  ecx = ebx;  // @51_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @52_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[10]);  // @53_5947b0
  ecx = edx = 0;  // @54_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1684), sizeof v); (u32)v; });  // @55_5947b0
  PV[11] = (u32)(ecx);  // @56_5947b0
  ecx = 0;  // @57_5947b0
  PV[12] = eax;  // @58_5947b0
  ecx = ebx;  // @59_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @60_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[12]);  // @61_5947b0
  ecx = edx = 0;  // @62_5947b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @63_5947b0
  ecx = (u32)(edi + 1688);  // @64_5947b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_5947b0
  ecx = edx = 0;  // @66_5947b0
  PV[13] = (u32)(eax);  // @67_5947b0
  ecx = ebx;  // @68_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 92)))(ecx, PV[13]);  // @69_5947b0
  ecx = edx = 0;  // @70_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @71_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2028) + 0), 4); v; });  // @72_5947b0
  X0[1] = 0;  // @73_5947b0
  X0[2] = 0;  // @74_5947b0
  X0[3] = 0;  // @75_5947b0
  PV[14] = (u32)(ecx);  // @76_5947b0
  ecx = ebx;  // @77_5947b0
  PV[15] = X0[0];  // @78_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[15]);  // @79_5947b0
  ecx = edx = 0;  // @80_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @81_5947b0
  ecx = ebx;  // @82_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2032), sizeof v); (u32)v; });  // @83_5947b0
  PV[16] = (u32)(eax);  // @84_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[16]);  // @85_5947b0
  ecx = edx = 0;  // @86_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_5947b0
  ecx = ebx;  // @88_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2033), sizeof v); (u32)v; });  // @89_5947b0
  PV[17] = (u32)(eax);  // @90_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[17]);  // @91_5947b0
  ecx = edx = 0;  // @92_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2034), sizeof v); (u32)v; });  // @93_5947b0
  ecx = ebx;  // @94_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @95_5947b0
  PV[18] = (u32)(eax);  // @96_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[18]);  // @97_5947b0
  ecx = edx = 0;  // @98_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @99_5947b0
  ecx = ebx;  // @100_5947b0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2035), sizeof v); (u32)v; });  // @101_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[19]);  // @102_5947b0
  ecx = edx = 0;  // @103_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @104_5947b0
  ecx = ebx;  // @105_5947b0
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2039), sizeof v); (u32)v; });  // @106_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[20]);  // @107_5947b0
  ecx = edx = 0;  // @108_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @109_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2043) + 0), 4); v; });  // @110_5947b0
  X0[1] = 0;  // @111_5947b0
  X0[2] = 0;  // @112_5947b0
  X0[3] = 0;  // @113_5947b0
  PV[21] = (u32)(ecx);  // @114_5947b0
  ecx = ebx;  // @115_5947b0
  PV[22] = X0[0];  // @116_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[22]);  // @117_5947b0
  ecx = edx = 0;  // @118_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2047) + 0), 4); v; });  // @119_5947b0
  X0[1] = 0;  // @120_5947b0
  X0[2] = 0;  // @121_5947b0
  X0[3] = 0;  // @122_5947b0
  PV[23] = (u32)(ecx);  // @123_5947b0
  ecx = eax;  // @124_5947b0
  PV[24] = X0[0];  // @125_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @126_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[24]);  // @127_5947b0
  ecx = edx = 0;  // @128_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @129_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2051) + 0), 4); v; });  // @130_5947b0
  X0[1] = 0;  // @131_5947b0
  X0[2] = 0;  // @132_5947b0
  X0[3] = 0;  // @133_5947b0
  PV[25] = (u32)(ecx);  // @134_5947b0
  ecx = ebx;  // @135_5947b0
  PV[26] = X0[0];  // @136_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[26]);  // @137_5947b0
  ecx = edx = 0;  // @138_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @139_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2055) + 0), 4); v; });  // @140_5947b0
  X0[1] = 0;  // @141_5947b0
  X0[2] = 0;  // @142_5947b0
  X0[3] = 0;  // @143_5947b0
  PV[27] = (u32)(ecx);  // @144_5947b0
  ecx = ebx;  // @145_5947b0
  PV[28] = X0[0];  // @146_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[28]);  // @147_5947b0
  ecx = edx = 0;  // @148_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @149_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2059) + 0), 4); v; });  // @150_5947b0
  X0[1] = 0;  // @151_5947b0
  X0[2] = 0;  // @152_5947b0
  X0[3] = 0;  // @153_5947b0
  PV[29] = (u32)(ecx);  // @154_5947b0
  ecx = ebx;  // @155_5947b0
  PV[30] = X0[0];  // @156_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[30]);  // @157_5947b0
  ecx = edx = 0;  // @158_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @159_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2063) + 0), 4); v; });  // @160_5947b0
  X0[1] = 0;  // @161_5947b0
  X0[2] = 0;  // @162_5947b0
  X0[3] = 0;  // @163_5947b0
  PV[31] = (u32)(ecx);  // @164_5947b0
  ecx = ebx;  // @165_5947b0
  PV[32] = X0[0];  // @166_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[32]);  // @167_5947b0
  ecx = edx = 0;  // @168_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @169_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2067) + 0), 4); v; });  // @170_5947b0
  X0[1] = 0;  // @171_5947b0
  X0[2] = 0;  // @172_5947b0
  X0[3] = 0;  // @173_5947b0
  PV[33] = (u32)(ecx);  // @174_5947b0
  ecx = ebx;  // @175_5947b0
  PV[34] = X0[0];  // @176_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[34]);  // @177_5947b0
  ecx = edx = 0;  // @178_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @179_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2071) + 0), 4); v; });  // @180_5947b0
  X0[1] = 0;  // @181_5947b0
  X0[2] = 0;  // @182_5947b0
  X0[3] = 0;  // @183_5947b0
  PV[35] = (u32)(ecx);  // @184_5947b0
  ecx = ebx;  // @185_5947b0
  PV[36] = X0[0];  // @186_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[36]);  // @187_5947b0
  ecx = edx = 0;  // @188_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @189_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2075) + 0), 4); v; });  // @190_5947b0
  X0[1] = 0;  // @191_5947b0
  X0[2] = 0;  // @192_5947b0
  X0[3] = 0;  // @193_5947b0
  PV[37] = (u32)(ecx);  // @194_5947b0
  ecx = ebx;  // @195_5947b0
  PV[38] = X0[0];  // @196_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[38]);  // @197_5947b0
  ecx = edx = 0;  // @198_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @199_5947b0
  ecx = ebx;  // @200_5947b0
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2114), sizeof v); (u32)v; });  // @201_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[39]);  // @202_5947b0
  ecx = edx = 0;  // @203_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @204_5947b0
  ecx = ebx;  // @205_5947b0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2118), sizeof v); (u32)v; });  // @206_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[40]);  // @207_5947b0
  ecx = edx = 0;  // @208_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @209_5947b0
  ecx = ebx;  // @210_5947b0
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2126), sizeof v); (u32)v; });  // @211_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[41]);  // @212_5947b0
  ecx = edx = 0;  // @213_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @214_5947b0
  eax = (u32)(edi + 2146);  // @215_5947b0
  PV[42] = (u32)(eax);  // @216_5947b0
  ecx = ebx;  // @217_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[42]);  // @218_5947b0
  ecx = edx = 0;  // @219_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @220_5947b0
  eax = (u32)(edi + 2182);  // @221_5947b0
  ecx = ebx;  // @222_5947b0
  PV[43] = (u32)(eax);  // @223_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[43]);  // @224_5947b0
  ecx = edx = 0;  // @225_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @226_5947b0
  eax = (u32)(edi + 2194);  // @227_5947b0
  PV[44] = (u32)(eax);  // @228_5947b0
  ecx = ebx;  // @229_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[44]);  // @230_5947b0
  ecx = edx = 0;  // @231_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @232_5947b0
  eax = (u32)(edi + 2230);  // @233_5947b0
  PV[45] = (u32)(eax);  // @234_5947b0
  ecx = ebx;  // @235_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[45]);  // @236_5947b0
  ecx = edx = 0;  // @237_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @238_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2531) + 0), 4); v; });  // @239_5947b0
  X0[1] = 0;  // @240_5947b0
  X0[2] = 0;  // @241_5947b0
  X0[3] = 0;  // @242_5947b0
  PV[46] = (u32)(ecx);  // @243_5947b0
  ecx = ebx;  // @244_5947b0
  PV[47] = X0[0];  // @245_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[47]);  // @246_5947b0
  ecx = edx = 0;  // @247_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @248_5947b0
  ecx = ebx;  // @249_5947b0
  PV[48] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2110), sizeof v); (u32)v; });  // @250_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[48]);  // @251_5947b0
  ecx = edx = 0;  // @252_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @253_5947b0
  ecx = ebx;  // @254_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1647), sizeof v); (u32)v; });  // @255_5947b0
  PV[49] = (u32)(eax);  // @256_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[49]);  // @257_5947b0
  ecx = edx = 0;  // @258_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @259_5947b0
  ecx = ebx;  // @260_5947b0
  PV[50] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3822), sizeof v); (u32)v; });  // @261_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[50]);  // @262_5947b0
  ecx = edx = 0;  // @263_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @264_5947b0
  eax = (u32)(edi + 1629);  // @265_5947b0
  PV[51] = (u32)(eax);  // @266_5947b0
  ecx = ebx;  // @267_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[51]);  // @268_5947b0
  ecx = edx = 0;  // @269_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @270_5947b0
  ecx = ebx;  // @271_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1641), sizeof v); (u32)v; });  // @272_5947b0
  PV[52] = (u32)(eax);  // @273_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[52]);  // @274_5947b0
  ecx = edx = 0;  // @275_5947b0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1642), sizeof v); (u32)v; });  // @276_5947b0
  PV[53] = (u32)(ecx);  // @277_5947b0
  ecx = eax;  // @278_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @279_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[53]);  // @280_5947b0
  ecx = edx = 0;  // @281_5947b0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1644), sizeof v); (u32)v; });  // @282_5947b0
  PV[54] = (u32)(ecx);  // @283_5947b0
  ecx = eax;  // @284_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @285_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[54]);  // @286_5947b0
  ecx = edx = 0;  // @287_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @288_5947b0
  ecx = ebx;  // @289_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1645), sizeof v); (u32)v; });  // @290_5947b0
  PV[55] = (u32)(eax);  // @291_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[55]);  // @292_5947b0
  ecx = edx = 0;  // @293_5947b0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1646), sizeof v); (u32)v; });  // @294_5947b0
  PV[56] = (u32)(ecx);  // @295_5947b0
  ecx = eax;  // @296_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @297_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[56]);  // @298_5947b0
  ecx = edx = 0;  // @299_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @300_5947b0
  ecx = ebx;  // @301_5947b0
  PV[57] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1654), sizeof v); (u32)v; });  // @302_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[57]);  // @303_5947b0
  ecx = edx = 0;  // @304_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @305_5947b0
  ecx = ebx;  // @306_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1663), sizeof v); (u32)v; });  // @307_5947b0
  PV[58] = (u32)(eax);  // @308_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[58]);  // @309_5947b0
  ecx = edx = 0;  // @310_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @311_5947b0
  ecx = ebx;  // @312_5947b0
  PV[59] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1668), sizeof v); (u32)v; });  // @313_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[59]);  // @314_5947b0
  ecx = edx = 0;  // @315_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @316_5947b0
  eax = (u32)(edi + 1069);  // @317_5947b0
  PV[60] = (u32)(eax);  // @318_5947b0
  ecx = ebx;  // @319_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[60]);  // @320_5947b0
  ecx = edx = 0;  // @321_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @322_5947b0
  ecx = ebx;  // @323_5947b0
  PV[61] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2110), sizeof v); (u32)v; });  // @324_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[61]);  // @325_5947b0
  ecx = edx = 0;  // @326_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @327_5947b0
  eax = (u32)(edi + 1081);  // @328_5947b0
  PV[62] = (u32)(eax);  // @329_5947b0
  ecx = ebx;  // @330_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[62]);  // @331_5947b0
  ecx = edx = 0;  // @332_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @333_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1105) + 0), 4); v; });  // @334_5947b0
  X0[1] = 0;  // @335_5947b0
  X0[2] = 0;  // @336_5947b0
  X0[3] = 0;  // @337_5947b0
  PV[63] = (u32)(ecx);  // @338_5947b0
  ecx = ebx;  // @339_5947b0
  PV[64] = X0[0];  // @340_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[64]);  // @341_5947b0
  ecx = edx = 0;  // @342_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @343_5947b0
  ecx = ebx;  // @344_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2097), sizeof v); (u32)v; });  // @345_5947b0
  PV[65] = (u32)(eax);  // @346_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[65]);  // @347_5947b0
  ecx = edx = 0;  // @348_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @349_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2079) + 0), 4); v; });  // @350_5947b0
  X0[1] = 0;  // @351_5947b0
  X0[2] = 0;  // @352_5947b0
  X0[3] = 0;  // @353_5947b0
  PV[66] = (u32)(ecx);  // @354_5947b0
  ecx = ebx;  // @355_5947b0
  PV[67] = X0[0];  // @356_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[67]);  // @357_5947b0
  ecx = edx = 0;  // @358_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @359_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2083) + 0), 4); v; });  // @360_5947b0
  X0[1] = 0;  // @361_5947b0
  X0[2] = 0;  // @362_5947b0
  X0[3] = 0;  // @363_5947b0
  PV[68] = (u32)(ecx);  // @364_5947b0
  ecx = ebx;  // @365_5947b0
  PV[69] = X0[0];  // @366_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[69]);  // @367_5947b0
  ecx = edx = 0;  // @368_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @369_5947b0
  ecx = ebx;  // @370_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2548), sizeof v); (u32)v; });  // @371_5947b0
  PV[70] = (u32)(eax);  // @372_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[70]);  // @373_5947b0
  ecx = edx = 0;  // @374_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @375_5947b0
  ecx = ebx;  // @376_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2549), sizeof v); (u32)v; });  // @377_5947b0
  PV[71] = (u32)(eax);  // @378_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[71]);  // @379_5947b0
  ecx = edx = 0;  // @380_5947b0
  edx = (u32)(edi + 2582);  // @381_5947b0
  ecx = ebx;  // @382_5947b0
  eax = ext_58aa40_fastcall2(ecx, edx);  // @383_5947b0
  ecx = edx = 0;  // @384_5947b0
  edx = (u32)(edi + 3402);  // @385_5947b0
  ecx = ebx;  // @386_5947b0
  eax = ext_58aaf0_fastcall2(ecx, edx);  // @387_5947b0
  ecx = edx = 0;  // @388_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @389_5947b0
  eax = (u32)(edi + 3763);  // @390_5947b0
  PV[72] = (u32)(eax);  // @391_5947b0
  ecx = ebx;  // @392_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[72]);  // @393_5947b0
  ecx = edx = 0;  // @394_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @395_5947b0
  eax = (u32)(edi + 3775);  // @396_5947b0
  PV[73] = (u32)(eax);  // @397_5947b0
  ecx = ebx;  // @398_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[73]);  // @399_5947b0
  ecx = edx = 0;  // @400_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @401_5947b0
  ecx = ebx;  // @402_5947b0
  PV[74] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3787), sizeof v); (u32)v; });  // @403_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[74]);  // @404_5947b0
  ecx = edx = 0;  // @405_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @406_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3795) + 0), 4); v; });  // @407_5947b0
  X0[1] = 0;  // @408_5947b0
  X0[2] = 0;  // @409_5947b0
  X0[3] = 0;  // @410_5947b0
  PV[75] = (u32)(ecx);  // @411_5947b0
  ecx = ebx;  // @412_5947b0
  PV[76] = X0[0];  // @413_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[76]);  // @414_5947b0
  ecx = edx = 0;  // @415_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @416_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @417_5947b0
  X0[1] = 0;  // @418_5947b0
  X0[2] = 0;  // @419_5947b0
  X0[3] = 0;  // @420_5947b0
  PV[77] = (u32)(ecx);  // @421_5947b0
  ecx = ebx;  // @422_5947b0
  PV[78] = X0[0];  // @423_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[78]);  // @424_5947b0
  ecx = edx = 0;  // @425_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @426_5947b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3803) + 0), 4); v; });  // @427_5947b0
  X0[1] = 0;  // @428_5947b0
  X0[2] = 0;  // @429_5947b0
  X0[3] = 0;  // @430_5947b0
  PV[79] = (u32)(ecx);  // @431_5947b0
  ecx = ebx;  // @432_5947b0
  PV[80] = X0[0];  // @433_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[80]);  // @434_5947b0
  ecx = edx = 0;  // @435_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @436_5947b0
  PV[81] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @437_5947b0
  ecx = ebx;  // @438_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[81]);  // @439_5947b0
  ecx = edx = 0;  // @440_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @441_5947b0
  ecx = ebx;  // @442_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3820), sizeof v); (u32)v; });  // @443_5947b0
  PV[82] = (u32)(eax);  // @444_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[82]);  // @445_5947b0
  ecx = edx = 0;  // @446_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @447_5947b0
  ecx = ebx;  // @448_5947b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3821), sizeof v); (u32)v; });  // @449_5947b0
  PV[83] = (u32)(eax);  // @450_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[83]);  // @451_5947b0
  ecx = edx = 0;  // @452_5947b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @453_5947b0
  ecx = ebx;  // @454_5947b0
  PV[84] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3934), sizeof v); (u32)v; });  // @455_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[84]);  // @456_5947b0
  ecx = edx = 0;  // @457_5947b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @458_5947b0
  PV[85] = (u32)(ebx);  // @459_5947b0
  eax = ext_59d3f0_thiscall2(ecx, PV[85]);  // @460_5947b0
  ecx = edx = 0;  // @461_5947b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1615), sizeof v); (u32)v; });  // @462_5947b0
  eax = (u32)(1126548799);  // @463_5947b0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; }));  // @464_5947b0
  FL[3] = edx;  // @465_5947b0
  ecx = ebx;  // @466_5947b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @467_5947b0
  edx = (edx - (u32)(3473));  // @468_5947b0
  FL[3] = edx;  // @469_5947b0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @470_5947b0
  edx = (u32)((s32)edx >> (u32)(6));  // @471_5947b0
  FL[3] = edx;  // @472_5947b0
  eax = edx;  // @473_5947b0
  eax = (eax >> (u32)(31));  // @474_5947b0
  FL[3] = eax;  // @475_5947b0
  eax = (eax + edx);  // @476_5947b0
  FL[3] = eax;  // @477_5947b0
  PV[86] = (u32)(eax);  // @478_5947b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 68)))(ecx, PV[86]);  // @479_5947b0
  ecx = edx = 0;  // @480_5947b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @481_5947b0
  return eax;  // @482_5947b0
}
PCREG(5947b0, lifted_5947b0);


extern "C" u32 THISCALL lifted_576e50(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @1_576e50
  eax = (u32)(edi + 518);  // @2_576e50
  PV[0] = (u32)(eax);  // @3_576e50
  eax = (u32)(EBP - 348);  // @4_576e50
  ecx = (ecx + (u32)(87));  // @5_576e50
  FL[3] = ecx;  // @6_576e50
  PV[1] = (u32)(eax);  // @7_576e50
  eax = ext_5adee0_thiscall3(ecx, PV[1], PV[0]);  // @8_576e50
  ecx = edx = 0;  // @9_576e50
  ebx = 0;  // @10_576e50
  FL[3] = ebx;  // @11_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @12_576e50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; }); FL[1] = ebx;  // @13_576e50
  if (FL[0] <= FL[1]) goto L577046;  // @14_576e50
  eax = (u32)(edi + 400);  // @15_576e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 372), &v, sizeof v); }  // @16_576e50
  L576eb0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 284), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @18_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 220), sizeof v); (u32)v; });  // @19_576e50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 348), sizeof v); (u32)v; });  // @20_576e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @21_576e50
  if (FL[0] != FL[1]) goto L576f18;  // @22_576e50
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_576e50
  if (FL[0] == FL[1]) goto L576f0f;  // @24_576e50
  ecx = (u32)(6981524);  // @25_576e50
  eax = (u32)(edi + 518);  // @26_576e50
  L576ee0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @28_576e50
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_576e50
  if (FL[0] != FL[1]) goto L576f00;  // @30_576e50
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @31_576e50
  if (FL[2] == 0) goto L576efc;  // @32_576e50
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @33_576e50
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @34_576e50
  if (FL[0] != FL[1]) goto L576f00;  // @35_576e50
  eax = (eax + (u32)(2));  // @36_576e50
  FL[3] = eax;  // @37_576e50
  ecx = (ecx + (u32)(2));  // @38_576e50
  FL[3] = ecx;  // @39_576e50
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @40_576e50
  if (FL[2] != 0) goto L576ee0;  // @41_576e50
  L576efc:;
  eax = 0;  // @43_576e50
  FL[3] = eax;  // @44_576e50
  goto L576f05;  // @45_576e50
  L576f00:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @47_576e50
  eax = (eax | (u32)(1));  // @48_576e50
  FL[3] = eax;  // @49_576e50
  L576f05:;
  FL[2] = (eax & eax);  // @51_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 360), sizeof v); (u32)v; });  // @52_576e50
  if (FL[2] != 0) goto L576f18;  // @53_576e50
  L576f0f:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 376), &v, sizeof v); }  // @55_576e50
  goto L576f1f;  // @56_576e50
  L576f18:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 376), &v, sizeof v); }  // @58_576e50
  L576f1f:;
  PV[2] = (u32)(eax);  // @60_576e50
  ecx = edi;  // @61_576e50
  eax = ext_573ba0_stdcall1(PV[2]);  // @62_576e50
  ecx = edx = 0;  // @63_576e50
  FL[2] = (eax & eax);  // @64_576e50
  if (FL[2] == 0) goto L57703c;  // @65_576e50
  PV[3] = (u32)(eax);  // @66_576e50
  ecx = edi;  // @67_576e50
  eax = ext_5761c0_thiscall2(ecx, PV[3]);  // @68_576e50
  ecx = edx = 0;  // @69_576e50
  FL[2] = (eax & eax);  // @70_576e50
  if (FL[2] == 0) goto L57703c;  // @71_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @72_576e50
  ecx = (u32)(EBP - 36);  // @73_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @74_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @75_576e50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @76_576e50
  PV[4] = (u32)(ecx);  // @77_576e50
  ecx = eax;  // @78_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[4]);  // @79_576e50
  ecx = edx = 0;  // @80_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; });  // @81_576e50
  eax = 0;  // @82_576e50
  FL[3] = eax;  // @83_576e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @84_576e50
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 510), sizeof v); (u32)v; });  // @85_576e50
  if (FL[0] >= FL[1]) goto L577022;  // @86_576e50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6984968) + 0), 4); v; });  // @87_576e50
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6984968) + 4), 4); v; });  // @88_576e50
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6984968) + 8), 4); v; });  // @89_576e50
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6984968) + 12), 4); v; });  // @90_576e50
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 520), sizeof v); (u32)v; })) & 0xff);  // @91_576e50
  edx = (u32)(EBP - 20);  // @92_576e50
  PV[5] = (u32)(esi);  // @93_576e50
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @94_576e50
  __builtin_memcpy((void *)((u32)(EBP - 20) + 4), &X0[1], 4);  // @95_576e50
  __builtin_memcpy((void *)((u32)(EBP - 20) + 8), &X0[2], 4);  // @96_576e50
  __builtin_memcpy((void *)((u32)(EBP - 20) + 12), &X0[3], 4);  // @97_576e50
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 18), &v, sizeof v); }  // @98_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_576e50
  PV[6] = (u32)(edx);  // @100_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @101_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @102_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_576e50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[6], PV[5]);  // @104_576e50
  ecx = edx = 0;  // @105_576e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 364), &v, sizeof v); }  // @106_576e50
  ecx = eax;  // @107_576e50
  L576fb2:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @109_576e50
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_576e50
  if (FL[0] != FL[1]) goto L576fd2;  // @111_576e50
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @112_576e50
  if (FL[2] == 0) goto L576fce;  // @113_576e50
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @114_576e50
  FL[0] = (eax & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @115_576e50
  if (FL[0] != FL[1]) goto L576fd2;  // @116_576e50
  esi = (esi + (u32)(2));  // @117_576e50
  FL[3] = esi;  // @118_576e50
  ecx = (ecx + (u32)(2));  // @119_576e50
  FL[3] = ecx;  // @120_576e50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @121_576e50
  if (FL[2] != 0) goto L576fb2;  // @122_576e50
  L576fce:;
  eax = 0;  // @124_576e50
  FL[3] = eax;  // @125_576e50
  goto L576fd7;  // @126_576e50
  L576fd2:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @128_576e50
  eax = (eax | (u32)(1));  // @129_576e50
  FL[3] = eax;  // @130_576e50
  L576fd7:;
  FL[2] = (eax & eax);  // @132_576e50
  if (FL[2] == 0) goto L57701c;  // @133_576e50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; });  // @134_576e50
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 364), sizeof v); (u32)v; });  // @135_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @136_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, PV[7]);  // @138_576e50
  ecx = edx = 0;  // @139_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @140_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @142_576e50
  ecx = edx = 0;  // @143_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 608)))(ecx, (u32)(20));  // @146_576e50
  ecx = edx = 0;  // @147_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @148_576e50
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @149_576e50
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; });  // @150_576e50
  esi = (esi + (u32)(4));  // @151_576e50
  FL[3] = esi;  // @152_576e50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 372), &v, sizeof v); }  // @153_576e50
  goto L577022;  // @154_576e50
  L57701c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 368), sizeof v); (u32)v; });  // @156_576e50
  L577022:;
  PV[8] = (u32)(eax);  // @158_576e50
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 376), sizeof v); (u32)v; });  // @159_576e50
  eax = (u32)(EBP - 36);  // @160_576e50
  ecx = edi;  // @161_576e50
  PV[10] = (u32)(eax);  // @162_576e50
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 360), sizeof v); (u32)v; });  // @163_576e50
  eax = ext_574af0_stdcall5(PV[11], PV[10], PV[9], (u32)(1), PV[8]);  // @164_576e50
  ecx = edx = 0;  // @165_576e50
  L57703c:;
  ebx = (ebx + 1);  // @167_576e50
  FL[3] = ebx;  // @168_576e50
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @169_576e50
  if (FL[0] < FL[1]) goto L576eb0;  // @170_576e50
  L577046:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 456), sizeof v); (u32)v; });  // @172_576e50
  esi = 0;  // @173_576e50
  FL[3] = esi;  // @174_576e50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @175_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @176_576e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 380), &v, sizeof v); }  // @177_576e50
  FL[2] = (eax & eax);  // @178_576e50
  if (FL[2] == 0) goto L5770c2;  // @179_576e50
  L577061:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @181_576e50
  ecx = (u32)(6801640);  // @182_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @183_576e50
  FL[2] = (eax & eax);  // @184_576e50
  if (FL[2] != 0) ecx = eax;  // @185_576e50
  eax = (u32)(6984888);  // @186_576e50
  L577076:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @188_576e50
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @189_576e50
  if (FL[0] != FL[1]) goto L577096;  // @190_576e50
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @191_576e50
  if (FL[2] == 0) goto L577092;  // @192_576e50
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @193_576e50
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @194_576e50
  if (FL[0] != FL[1]) goto L577096;  // @195_576e50
  ecx = (ecx + (u32)(2));  // @196_576e50
  FL[3] = ecx;  // @197_576e50
  eax = (eax + (u32)(2));  // @198_576e50
  FL[3] = eax;  // @199_576e50
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @200_576e50
  if (FL[2] != 0) goto L577076;  // @201_576e50
  L577092:;
  eax = 0;  // @203_576e50
  FL[3] = eax;  // @204_576e50
  goto L57709b;  // @205_576e50
  L577096:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @207_576e50
  eax = (eax | (u32)(1));  // @208_576e50
  FL[3] = eax;  // @209_576e50
  L57709b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 456), sizeof v); (u32)v; });  // @211_576e50
  edx = (u32)(EBP - 380);  // @212_576e50
  FL[2] = (eax & eax);  // @213_576e50
  PV[12] = (u32)(edx);  // @214_576e50
  if (FL[2] == 0) esi = ebx;  // @215_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @216_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[12]);  // @217_576e50
  ecx = edx = 0;  // @218_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 380), sizeof v); (u32)v; });  // @219_576e50
  FL[2] = (eax & eax);  // @220_576e50
  if (FL[2] != 0) goto L577061;  // @221_576e50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @222_576e50
  L5770c2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @224_576e50
  edx = (u32)(edi + 518);  // @225_576e50
  eax = (eax + (u32)(72));  // @226_576e50
  FL[3] = eax;  // @227_576e50
  L5770d1:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @229_576e50
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @230_576e50
  if (FL[0] != FL[1]) goto L5770f1;  // @231_576e50
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @232_576e50
  if (FL[2] == 0) goto L5770ed;  // @233_576e50
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @234_576e50
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @235_576e50
  if (FL[0] != FL[1]) goto L5770f1;  // @236_576e50
  edx = (edx + (u32)(2));  // @237_576e50
  FL[3] = edx;  // @238_576e50
  eax = (eax + (u32)(2));  // @239_576e50
  FL[3] = eax;  // @240_576e50
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @241_576e50
  if (FL[2] != 0) goto L5770d1;  // @242_576e50
  L5770ed:;
  eax = 0;  // @244_576e50
  FL[3] = eax;  // @245_576e50
  goto L5770f6;  // @246_576e50
  L5770f1:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @248_576e50
  eax = (eax | (u32)(1));  // @249_576e50
  FL[3] = eax;  // @250_576e50
  L5770f6:;
  FL[2] = (eax & eax);  // @252_576e50
  if (FL[2] != 0) goto L5771fc;  // @253_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @254_576e50
  eax = (u32)(EBP - 48);  // @255_576e50
  PV[13] = (u32)(eax);  // @256_576e50
  eax = ext_4db500_thiscall2(ecx, PV[13]);  // @257_576e50
  ecx = edx = 0;  // @258_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 144), sizeof v); (u32)v; });  // @259_576e50
  ebx = 0;  // @260_576e50
  FL[3] = ebx;  // @261_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2582), sizeof v); (u32)v; });  // @262_576e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 364), &v, sizeof v); }  // @263_576e50
  FL[2] = (eax & eax);  // @264_576e50
  if (FL[2] == 0) goto L5771f1;  // @265_576e50
  L577130:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 144), sizeof v); (u32)v; });  // @267_576e50
  PV[14] = (u32)(ebx);  // @268_576e50
  eax = ext_591d30_thiscall2(ecx, PV[14]);  // @269_576e50
  ecx = edx = 0;  // @270_576e50
  esi = eax;  // @271_576e50
  ecx = esi;  // @272_576e50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @273_576e50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @274_576e50
  ecx = edx = 0;  // @275_576e50
  ecx = (u32)(EBP - 16);  // @276_576e50
  PV[15] = (u32)(ecx);  // @277_576e50
  ecx = (u32)(EBP - 84);  // @278_576e50
  PV[16] = (u32)(ecx);  // @279_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @280_576e50
  eax = ext_4db2c0_thiscall3(ecx, PV[16], PV[15]);  // @281_576e50
  ecx = edx = 0;  // @282_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; });  // @283_576e50
  edx = (u32)(EBP - 16);  // @284_576e50
  PV[17] = (u32)(edx);  // @285_576e50
  { u32 v = (u32)((u32)(1109393408)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @286_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @287_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[17]);  // @288_576e50
  ecx = edx = 0;  // @289_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; });  // @290_576e50
  edx = (u32)(EBP - 16);  // @291_576e50
  PV[18] = (u32)(edx);  // @292_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @293_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @294_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @295_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @296_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[18]);  // @297_576e50
  ecx = edx = 0;  // @298_576e50
  ecx = esi;  // @299_576e50
  { u32 v = (u32)((u32)(19)); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @300_576e50
  eax = ext_59ffc0_thiscall1(ecx);  // @301_576e50
  ecx = edx = 0;  // @302_576e50
  FL[2] = (eax & eax);  // @303_576e50
  if ((s32)FL[2] <= 0) goto L5771c7;  // @304_576e50
  FL[0] = eax; FL[1] = (u32)(4);  // @305_576e50
  if ((s32)FL[0] <= (s32)FL[1]) goto L5771b8;  // @306_576e50
  FL[0] = eax; FL[1] = (u32)(5);  // @307_576e50
  if (FL[0] != FL[1]) goto L5771bf;  // @308_576e50
  eax = (u32)(16);  // @309_576e50
  goto L5771cc;  // @310_576e50
  L5771b8:;
  eax = (u32)(17);  // @312_576e50
  goto L5771cc;  // @313_576e50
  L5771bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 368), sizeof v); (u32)v; });  // @315_576e50
  goto L5771cc;  // @316_576e50
  L5771c7:;
  eax = (u32)(19);  // @318_576e50
  L5771cc:;
  ecx = (u32)(EBP - 16);  // @320_576e50
  PV[19] = (u32)(ecx);  // @321_576e50
  PV[20] = (u32)(eax);  // @322_576e50
  ecx = edi;  // @323_576e50
  eax = ext_574af0_stdcall5(PV[20], PV[19], (u32)(0), (u32)(1), (u32)(0));  // @324_576e50
  ecx = edx = 0;  // @325_576e50
  ebx = (ebx + 1);  // @326_576e50
  FL[3] = ebx;  // @327_576e50
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 364), sizeof v); (u32)v; });  // @328_576e50
  if (FL[0] < FL[1]) goto L577130;  // @329_576e50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; });  // @330_576e50
  L5771f1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @332_576e50
  ecx = (u32)(EBP - 48);  // @333_576e50
  PV[21] = (u32)(ecx);  // @334_576e50
  ecx = esi;  // @335_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[21]);  // @336_576e50
  ecx = edx = 0;  // @337_576e50
  L5771fc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @339_576e50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @340_576e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @341_576e50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @342_576e50
  ecx = edx = 0;  // @343_576e50
  ecx = (u32)(EBP - 349);  // @344_576e50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 349), &v, sizeof v); }  // @345_576e50
  PV[22] = (u32)(ecx);  // @346_576e50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @347_576e50
  ecx = eax;  // @348_576e50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6976892), PV[22]);  // @349_576e50
  ecx = edx = 0;  // @350_576e50
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 349), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @351_576e50
  if (FL[0] != FL[1]) goto L5772ab;  // @352_576e50
  { u32 v = (u32)((u32)(6984984)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @353_576e50
  esi = 0;  // @354_576e50
  FL[3] = esi;  // @355_576e50
  { u32 v = (u32)((u32)(6984996)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @356_576e50
  { u32 v = (u32)((u32)(6985012)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @357_576e50
  { u32 v = (u32)((u32)(6985028)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @358_576e50
  { u32 v = (u32)((u32)(6985044)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @359_576e50
  L577260:;
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 24), sizeof v); (u32)v; });  // @361_576e50
  ecx = edi;  // @362_576e50
  eax = ext_5761c0_thiscall2(ecx, PV[23]);  // @363_576e50
  ecx = edx = 0;  // @364_576e50
  FL[2] = (eax & eax);  // @365_576e50
  if (FL[2] == 0) goto L5772a5;  // @366_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @367_576e50
  ecx = (u32)(EBP - 36);  // @368_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @369_576e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @370_576e50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @371_576e50
  PV[24] = (u32)(ecx);  // @372_576e50
  ecx = eax;  // @373_576e50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[24]);  // @374_576e50
  ecx = edx = 0;  // @375_576e50
  eax = (u32)(EBP - 36);  // @376_576e50
  ecx = edi;  // @377_576e50
  PV[25] = (u32)(eax);  // @378_576e50
  eax = ext_574af0_stdcall5((u32)(13), PV[25], (u32)(0), (u32)(1), (u32)(0));  // @379_576e50
  ecx = edx = 0;  // @380_576e50
  L5772a5:;
  esi = (esi + 1);  // @382_576e50
  FL[3] = esi;  // @383_576e50
  FL[0] = esi; FL[1] = (u32)(5);  // @384_576e50
  if (FL[0] < FL[1]) goto L577260;  // @385_576e50
  L5772ab:;
  ext_633654(G(u32, 0x6f5630));  // @387_576e50
  return eax;  // @388_576e50
}
PCREG(576e50, lifted_576e50);

extern "C" u32 THISCALL lifted_5ea470(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[80], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_5ea470
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5ea470
  ecx = edi;  // @2_5ea470
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_5ea470
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @4_5ea470
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @5_5ea470
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8118), sizeof v); (u32)v; });  // @6_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[0]);  // @8_5ea470
  ecx = edx = 0;  // @9_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_5ea470
  ecx = edi;  // @11_5ea470
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8122), sizeof v); (u32)v; });  // @12_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[1]);  // @13_5ea470
  ecx = edx = 0;  // @14_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_5ea470
  ecx = edi;  // @16_5ea470
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8126), sizeof v); (u32)v; });  // @17_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[2]);  // @18_5ea470
  ecx = edx = 0;  // @19_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_5ea470
  ecx = edi;  // @21_5ea470
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7423), sizeof v); (u32)v; });  // @22_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[3]);  // @23_5ea470
  ecx = edx = 0;  // @24_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_5ea470
  ecx = edi;  // @26_5ea470
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8898), sizeof v); (u32)v; });  // @27_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[4]);  // @28_5ea470
  ecx = edx = 0;  // @29_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_5ea470
  ecx = edi;  // @31_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8910), sizeof v); (u32)v; });  // @32_5ea470
  PV[5] = (u32)(eax);  // @33_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[5]);  // @34_5ea470
  ecx = edx = 0;  // @35_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8911) + 0), 4); v; });  // @37_5ea470
  X0[1] = 0;  // @38_5ea470
  X0[2] = 0;  // @39_5ea470
  X0[3] = 0;  // @40_5ea470
  PV[6] = (u32)(ecx);  // @41_5ea470
  ecx = edi;  // @42_5ea470
  PV[7] = X0[0];  // @43_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @44_5ea470
  ecx = edx = 0;  // @45_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_5ea470
  ecx = edi;  // @47_5ea470
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8114), sizeof v); (u32)v; });  // @48_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[8]);  // @49_5ea470
  ecx = edx = 0;  // @50_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_5ea470
  ecx = edi;  // @52_5ea470
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8110), sizeof v); (u32)v; });  // @53_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[9]);  // @54_5ea470
  ecx = edx = 0;  // @55_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_5ea470
  ecx = edi;  // @57_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7573), sizeof v); (u32)v; });  // @58_5ea470
  PV[10] = (u32)(eax);  // @59_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[10]);  // @60_5ea470
  ecx = edx = 0;  // @61_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 7569) + 0), 4); v; });  // @63_5ea470
  X0[1] = 0;  // @64_5ea470
  X0[2] = 0;  // @65_5ea470
  X0[3] = 0;  // @66_5ea470
  PV[11] = (u32)(ecx);  // @67_5ea470
  ecx = edi;  // @68_5ea470
  PV[12] = X0[0];  // @69_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[12]);  // @70_5ea470
  ecx = edx = 0;  // @71_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @72_5ea470
  eax = (u32)(ebx + 7574);  // @73_5ea470
  PV[13] = (u32)(eax);  // @74_5ea470
  ecx = edi;  // @75_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[13]);  // @76_5ea470
  ecx = edx = 0;  // @77_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_5ea470
  ecx = edi;  // @79_5ea470
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7499), sizeof v); (u32)v; });  // @80_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[14]);  // @81_5ea470
  ecx = edx = 0;  // @82_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @83_5ea470
  ecx = edi;  // @84_5ea470
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7495), sizeof v); (u32)v; });  // @85_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[15]);  // @86_5ea470
  ecx = edx = 0;  // @87_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 7447) + 0), 4); v; });  // @89_5ea470
  X0[1] = 0;  // @90_5ea470
  X0[2] = 0;  // @91_5ea470
  X0[3] = 0;  // @92_5ea470
  PV[16] = (u32)(ecx);  // @93_5ea470
  ecx = edi;  // @94_5ea470
  PV[17] = X0[0];  // @95_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[17]);  // @96_5ea470
  ecx = edx = 0;  // @97_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @98_5ea470
  ecx = edi;  // @99_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 750), sizeof v); (u32)v; });  // @100_5ea470
  PV[18] = (u32)(eax);  // @101_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[18]);  // @102_5ea470
  ecx = edx = 0;  // @103_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @104_5ea470
  ecx = edi;  // @105_5ea470
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 746), sizeof v); (u32)v; });  // @106_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[19]);  // @107_5ea470
  ecx = edx = 0;  // @108_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @109_5ea470
  ecx = edi;  // @110_5ea470
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 742), sizeof v); (u32)v; });  // @111_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[20]);  // @112_5ea470
  ecx = edx = 0;  // @113_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @114_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 109) + 0), 4); v; });  // @115_5ea470
  X0[1] = 0;  // @116_5ea470
  X0[2] = 0;  // @117_5ea470
  X0[3] = 0;  // @118_5ea470
  PV[21] = (u32)(ecx);  // @119_5ea470
  ecx = edi;  // @120_5ea470
  PV[22] = X0[0];  // @121_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[22]);  // @122_5ea470
  ecx = edx = 0;  // @123_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @124_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 105) + 0), 4); v; });  // @125_5ea470
  X0[1] = 0;  // @126_5ea470
  X0[2] = 0;  // @127_5ea470
  X0[3] = 0;  // @128_5ea470
  PV[23] = (u32)(ecx);  // @129_5ea470
  ecx = edi;  // @130_5ea470
  PV[24] = X0[0];  // @131_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[24]);  // @132_5ea470
  ecx = edx = 0;  // @133_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @134_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 101) + 0), 4); v; });  // @135_5ea470
  X0[1] = 0;  // @136_5ea470
  X0[2] = 0;  // @137_5ea470
  X0[3] = 0;  // @138_5ea470
  PV[25] = (u32)(ecx);  // @139_5ea470
  ecx = edi;  // @140_5ea470
  PV[26] = X0[0];  // @141_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[26]);  // @142_5ea470
  ecx = edx = 0;  // @143_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @144_5ea470
  ecx = edi;  // @145_5ea470
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1263), sizeof v); (u32)v; });  // @146_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[27]);  // @147_5ea470
  ecx = edx = 0;  // @148_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @149_5ea470
  eax = (u32)(ebx + 8130);  // @150_5ea470
  PV[28] = (u32)(eax);  // @151_5ea470
  ecx = edi;  // @152_5ea470
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[28], (u32)(768));  // @153_5ea470
  ecx = edx = 0;  // @154_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @155_5ea470
  eax = (u32)(ebx + 1279);  // @156_5ea470
  PV[29] = (u32)(eax);  // @157_5ea470
  ecx = edi;  // @158_5ea470
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[29], (u32)(6144));  // @159_5ea470
  ecx = edx = 0;  // @160_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @161_5ea470
  eax = (u32)(ebx + 751);  // @162_5ea470
  PV[30] = (u32)(eax);  // @163_5ea470
  ecx = edi;  // @164_5ea470
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[30], (u32)(512));  // @165_5ea470
  ecx = edx = 0;  // @166_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @167_5ea470
  eax = (u32)(ebx + 230);  // @168_5ea470
  PV[31] = (u32)(eax);  // @169_5ea470
  ecx = edi;  // @170_5ea470
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[31], (u32)(512));  // @171_5ea470
  ecx = edx = 0;  // @172_5ea470
  esi = (u32)(ebx + 7598);  // @173_5ea470
  ebx = (u32)(128);  // @174_5ea470
  L5ea626:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @176_5ea470
  ecx = edi;  // @177_5ea470
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @178_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[32]);  // @179_5ea470
  ecx = edx = 0;  // @180_5ea470
  esi = (u32)(esi + 4);  // @181_5ea470
  ebx = (ebx - (u32)(1));  // @182_5ea470
  FL[3] = ebx;  // @183_5ea470
  if (FL[3] != 0) goto L5ea626;  // @184_5ea470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @185_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @186_5ea470
  PV[33] = (u32)(ecx);  // @187_5ea470
  ecx = edi;  // @188_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 84) + 0), 4); v; });  // @189_5ea470
  X0[1] = 0;  // @190_5ea470
  X0[2] = 0;  // @191_5ea470
  X0[3] = 0;  // @192_5ea470
  PV[34] = X0[0];  // @193_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[34]);  // @194_5ea470
  ecx = edx = 0;  // @195_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @196_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 109) + 0), 4); v; });  // @197_5ea470
  X0[1] = 0;  // @198_5ea470
  X0[2] = 0;  // @199_5ea470
  X0[3] = 0;  // @200_5ea470
  PV[35] = (u32)(ecx);  // @201_5ea470
  ecx = edi;  // @202_5ea470
  PV[36] = X0[0];  // @203_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[36]);  // @204_5ea470
  ecx = edx = 0;  // @205_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @206_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7451) + 0), 4); v; });  // @207_5ea470
  X0[1] = 0;  // @208_5ea470
  X0[2] = 0;  // @209_5ea470
  X0[3] = 0;  // @210_5ea470
  PV[37] = (u32)(ecx);  // @211_5ea470
  ecx = edi;  // @212_5ea470
  PV[38] = X0[0];  // @213_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[38]);  // @214_5ea470
  ecx = edx = 0;  // @215_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @216_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7455) + 0), 4); v; });  // @217_5ea470
  X0[1] = 0;  // @218_5ea470
  X0[2] = 0;  // @219_5ea470
  X0[3] = 0;  // @220_5ea470
  PV[39] = (u32)(ecx);  // @221_5ea470
  ecx = edi;  // @222_5ea470
  PV[40] = X0[0];  // @223_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[40]);  // @224_5ea470
  ecx = edx = 0;  // @225_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @226_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7459) + 0), 4); v; });  // @227_5ea470
  X0[1] = 0;  // @228_5ea470
  X0[2] = 0;  // @229_5ea470
  X0[3] = 0;  // @230_5ea470
  PV[41] = (u32)(ecx);  // @231_5ea470
  ecx = edi;  // @232_5ea470
  PV[42] = X0[0];  // @233_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[42]);  // @234_5ea470
  ecx = edx = 0;  // @235_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @236_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7463) + 0), 4); v; });  // @237_5ea470
  X0[1] = 0;  // @238_5ea470
  X0[2] = 0;  // @239_5ea470
  X0[3] = 0;  // @240_5ea470
  PV[43] = (u32)(ecx);  // @241_5ea470
  ecx = edi;  // @242_5ea470
  PV[44] = X0[0];  // @243_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[44]);  // @244_5ea470
  ecx = edx = 0;  // @245_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @246_5ea470
  ecx = edi;  // @247_5ea470
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7435), sizeof v); (u32)v; });  // @248_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[45]);  // @249_5ea470
  ecx = edx = 0;  // @250_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @251_5ea470
  ecx = edi;  // @252_5ea470
  PV[46] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7431), sizeof v); (u32)v; });  // @253_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[46]);  // @254_5ea470
  ecx = edx = 0;  // @255_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @256_5ea470
  ecx = edi;  // @257_5ea470
  PV[47] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1267), sizeof v); (u32)v; });  // @258_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[47]);  // @259_5ea470
  ecx = edx = 0;  // @260_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @261_5ea470
  ecx = edi;  // @262_5ea470
  PV[48] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 97), sizeof v); (u32)v; });  // @263_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[48]);  // @264_5ea470
  ecx = edx = 0;  // @265_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @266_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7443) + 0), 4); v; });  // @267_5ea470
  X0[1] = 0;  // @268_5ea470
  X0[2] = 0;  // @269_5ea470
  X0[3] = 0;  // @270_5ea470
  PV[49] = (u32)(ecx);  // @271_5ea470
  ecx = edi;  // @272_5ea470
  PV[50] = X0[0];  // @273_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[50]);  // @274_5ea470
  ecx = edx = 0;  // @275_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @276_5ea470
  ecx = edi;  // @277_5ea470
  PV[51] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7483), sizeof v); (u32)v; });  // @278_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[51]);  // @279_5ea470
  ecx = edx = 0;  // @280_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @281_5ea470
  ecx = edi;  // @282_5ea470
  PV[52] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7487), sizeof v); (u32)v; });  // @283_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[52]);  // @284_5ea470
  ecx = edx = 0;  // @285_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @286_5ea470
  ecx = edi;  // @287_5ea470
  PV[53] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7491), sizeof v); (u32)v; });  // @288_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[53]);  // @289_5ea470
  ecx = edx = 0;  // @290_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @291_5ea470
  ecx = edi;  // @292_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @293_5ea470
  PV[54] = (u32)(eax);  // @294_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[54]);  // @295_5ea470
  ecx = edx = 0;  // @296_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @297_5ea470
  ecx = edi;  // @298_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7503), sizeof v); (u32)v; });  // @299_5ea470
  PV[55] = (u32)(eax);  // @300_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[55]);  // @301_5ea470
  ecx = edx = 0;  // @302_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @303_5ea470
  eax = (u32)(esi + 7504);  // @304_5ea470
  PV[56] = (u32)(eax);  // @305_5ea470
  ecx = edi;  // @306_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[56]);  // @307_5ea470
  ecx = edx = 0;  // @308_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @309_5ea470
  eax = (u32)(esi + 7516);  // @310_5ea470
  PV[57] = (u32)(eax);  // @311_5ea470
  ecx = edi;  // @312_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[57]);  // @313_5ea470
  ecx = edx = 0;  // @314_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @315_5ea470
  eax = (u32)(esi + 7528);  // @316_5ea470
  PV[58] = (u32)(eax);  // @317_5ea470
  ecx = edi;  // @318_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[58]);  // @319_5ea470
  ecx = edx = 0;  // @320_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @321_5ea470
  eax = (u32)(esi + 7540);  // @322_5ea470
  PV[59] = (u32)(eax);  // @323_5ea470
  ecx = edi;  // @324_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[59]);  // @325_5ea470
  ecx = edx = 0;  // @326_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @327_5ea470
  ecx = edi;  // @328_5ea470
  PV[60] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7552), sizeof v); (u32)v; });  // @329_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[60]);  // @330_5ea470
  ecx = edx = 0;  // @331_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @332_5ea470
  ecx = edi;  // @333_5ea470
  PV[61] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7556), sizeof v); (u32)v; });  // @334_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[61]);  // @335_5ea470
  ecx = edx = 0;  // @336_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @337_5ea470
  ecx = edi;  // @338_5ea470
  PV[62] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7560), sizeof v); (u32)v; });  // @339_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[62]);  // @340_5ea470
  ecx = edx = 0;  // @341_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @342_5ea470
  ecx = edi;  // @343_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7564), sizeof v); (u32)v; });  // @344_5ea470
  PV[63] = (u32)(eax);  // @345_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[63]);  // @346_5ea470
  ecx = edx = 0;  // @347_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @348_5ea470
  ecx = edi;  // @349_5ea470
  PV[64] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7565), sizeof v); (u32)v; });  // @350_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[64]);  // @351_5ea470
  ecx = edx = 0;  // @352_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @353_5ea470
  ecx = edi;  // @354_5ea470
  PV[65] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7439), sizeof v); (u32)v; });  // @355_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[65]);  // @356_5ea470
  ecx = edx = 0;  // @357_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; });  // @358_5ea470
  ecx = edi;  // @359_5ea470
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7586), sizeof v); (u32)v; }));  // @360_5ea470
  FL[3] = eax;  // @361_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @362_5ea470
  eax = (u32)((s32)eax >> (u32)(2));  // @363_5ea470
  FL[3] = eax;  // @364_5ea470
  PV[66] = (u32)(eax);  // @365_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[66]);  // @366_5ea470
  ecx = edx = 0;  // @367_5ea470
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7586), sizeof v); (u32)v; });  // @368_5ea470
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; });  // @369_5ea470
  if (FL[0] == FL[1]) goto L5ea824;  // @370_5ea470
  L5ea7e7:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @372_5ea470
  ecx = edi;  // @373_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @374_5ea470
  PV[67] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @375_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[67]);  // @376_5ea470
  ecx = edx = 0;  // @377_5ea470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @378_5ea470
  PV[68] = (u32)(edi);  // @379_5ea470
  eax = ext_5b7eb0_thiscall2(ecx, PV[68]);  // @380_5ea470
  ecx = edx = 0;  // @381_5ea470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @382_5ea470
  PV[69] = (u32)(edi);  // @383_5ea470
  eax = ext_5b7c70_thiscall2(ecx, PV[69]);  // @384_5ea470
  ecx = edx = 0;  // @385_5ea470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @386_5ea470
  PV[70] = (u32)(edi);  // @387_5ea470
  eax = ext_5b7c70_thiscall2(ecx, PV[70]);  // @388_5ea470
  ecx = edx = 0;  // @389_5ea470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @390_5ea470
  PV[71] = (u32)(edi);  // @391_5ea470
  eax = ext_5b7c70_thiscall2(ecx, PV[71]);  // @392_5ea470
  ecx = edx = 0;  // @393_5ea470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @394_5ea470
  ebx = (ebx + (u32)(4));  // @395_5ea470
  FL[3] = ebx;  // @396_5ea470
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; });  // @397_5ea470
  if (FL[0] != FL[1]) goto L5ea7e7;  // @398_5ea470
  L5ea824:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @400_5ea470
  ecx = edi;  // @401_5ea470
  PV[72] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8927), sizeof v); (u32)v; });  // @402_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[72]);  // @403_5ea470
  ecx = edx = 0;  // @404_5ea470
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @405_5ea470
  return eax;  // @406_5ea470
}
PCREG(5ea470, lifted_5ea470);

extern "C" u32 THISCALL lifted_445800(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_445800
  PV[0] = (u32)(esi);  // @1_445800
  edi = ecx;  // @2_445800
  eax = ext_610100_stdcall1(PV[0]);  // @3_445800
  ecx = edx = 0;  // @4_445800
  ebx = (u32)(edi + 100);  // @5_445800
  ecx = esi;  // @6_445800
  PV[1] = (u32)(ebx);  // @7_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[1], (u32)(1));  // @8_445800
  ecx = edx = 0;  // @9_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @10_445800
  X0[1] = 0;  // @11_445800
  X0[2] = 0;  // @12_445800
  X0[3] = 0;  // @13_445800
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; }))))))) goto L44583e;  // @14_445800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @15_445800
  L44583e:;
  eax = (u32)(edi + 104);  // @17_445800
  ecx = esi;  // @18_445800
  PV[2] = (u32)(eax);  // @19_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[2], (u32)(1));  // @20_445800
  ecx = edx = 0;  // @21_445800
  eax = (u32)(EBP - 32);  // @22_445800
  ecx = esi;  // @23_445800
  PV[3] = (u32)(eax);  // @24_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[3], (u32)(3));  // @25_445800
  ecx = edx = 0;  // @26_445800
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @27_445800
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @28_445800
  ecx = (ecx << (u32)(8));  // @29_445800
  FL[3] = ecx;  // @30_445800
  ecx = (ecx + eax);  // @31_445800
  FL[3] = ecx;  // @32_445800
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @33_445800
  ecx = (ecx << (u32)(8));  // @34_445800
  FL[3] = ecx;  // @35_445800
  ecx = (ecx + eax);  // @36_445800
  FL[3] = ecx;  // @37_445800
  eax = (u32)(edi + 96);  // @38_445800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 108), &v, sizeof v); }  // @39_445800
  ecx = esi;  // @40_445800
  PV[4] = (u32)(eax);  // @41_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[4], (u32)(1));  // @42_445800
  ecx = edx = 0;  // @43_445800
  eax = (u32)(EBP - 44);  // @44_445800
  ecx = esi;  // @45_445800
  PV[5] = (u32)(eax);  // @46_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[5], (u32)(1));  // @47_445800
  ecx = edx = 0;  // @48_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @49_445800
  X0[1] = 0;  // @50_445800
  X0[2] = 0;  // @51_445800
  X0[3] = 0;  // @52_445800
  eax = (u32)(EBP - 52);  // @53_445800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @54_445800
  ecx = esi;  // @55_445800
  PV[6] = (u32)(eax);  // @56_445800
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806056) + 0), 4); v; })));  // @57_445800
  __builtin_memcpy((void *)((u32)(edi + 92) + 0), &X0[0], 4);  // @58_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[6], (u32)(1));  // @59_445800
  ecx = edx = 0;  // @60_445800
  eax = (u32)(EBP - 48);  // @61_445800
  ecx = esi;  // @62_445800
  PV[7] = (u32)(eax);  // @63_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[7], (u32)(1));  // @64_445800
  ecx = edx = 0;  // @65_445800
  eax = (u32)(edi + 76);  // @66_445800
  ecx = esi;  // @67_445800
  PV[8] = (u32)(eax);  // @68_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[8], (u32)(1));  // @69_445800
  ecx = edx = 0;  // @70_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @71_445800
  FL[2] = (ecx & ecx);  // @72_445800
  if (FL[2] == 0) goto L445928;  // @73_445800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_445800
  eax = (u32)(1);  // @75_445800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 6415), sizeof v); (u32)v; });  // @76_445800
  FL[0] = ecx; FL[1] = eax;  // @77_445800
  if (FL[0] == FL[1]) goto L4458f4;  // @78_445800
  L4458e8:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @80_445800
  FL[2] = (ebx & ebx);  // @81_445800
  if (FL[2] == 0) goto L445928;  // @82_445800
  eax = (eax + 1);  // @83_445800
  FL[3] = eax;  // @84_445800
  FL[0] = eax; FL[1] = ecx;  // @85_445800
  if (FL[0] != FL[1]) goto L4458e8;  // @86_445800
  L4458f4:;
  FL[2] = (ebx & ebx);  // @88_445800
  if (FL[2] == 0) goto L445928;  // @89_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 155), sizeof v); (u32)v; });  // @90_445800
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; });  // @91_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @92_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_445800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 840)))(ecx, PV[9]);  // @94_445800
  ecx = edx = 0;  // @95_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @96_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @97_445800
  X0[0] = F2U((float)(s32)X0[0]);  // @98_445800
  X0[1] = F2U((float)(s32)X0[1]);  // @99_445800
  X0[2] = F2U((float)(s32)X0[2]);  // @100_445800
  X0[3] = F2U((float)(s32)X0[3]);  // @101_445800
  PV[10] = (u32)(ecx);  // @102_445800
  ecx = ebx;  // @103_445800
  PV[11] = X0[0];  // @104_445800
  PV[12] = (u32)(edi);  // @105_445800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[12], PV[11]);  // @106_445800
  ecx = edx = 0;  // @107_445800
  L445928:;
  ecx = esi;  // @109_445800
  eax = ext_4e1600_thiscall1(ecx);  // @110_445800
  ecx = edx = 0;  // @111_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @112_445800
  if (FL[0] != FL[1]) goto L445ae6;  // @113_445800
  eax = (u32)(EBP - 40);  // @114_445800
  ecx = esi;  // @115_445800
  PV[13] = (u32)(eax);  // @116_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[13], (u32)(1));  // @117_445800
  ecx = edx = 0;  // @118_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @119_445800
  FL[0] = eax; FL[1] = (u32)(1);  // @120_445800
  if (FL[0] != FL[1]) goto L4459b5;  // @121_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @122_445800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806028) + 0), 4); v; });  // @123_445800
  X2[1] = 0;  // @124_445800
  X2[2] = 0;  // @125_445800
  X2[3] = 0;  // @126_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 99), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @127_445800
  if (FL[0] == FL[1]) goto L44599e;  // @128_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @129_445800
  FL[2] = (ecx & ecx);  // @130_445800
  if (FL[2] == 0) goto L44597a;  // @131_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @132_445800
  if (FL[0] == FL[1]) goto L44597a;  // @133_445800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; });  // @134_445800
  X2[1] = 0;  // @135_445800
  X2[2] = 0;  // @136_445800
  X2[3] = 0;  // @137_445800
  L44597a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @139_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @140_445800
  X0[0] = F2U((float)(s32)X0[0]);  // @141_445800
  X0[1] = F2U((float)(s32)X0[1]);  // @142_445800
  X0[2] = F2U((float)(s32)X0[2]);  // @143_445800
  X0[3] = F2U((float)(s32)X0[3]);  // @144_445800
  X1[0] = F2U((float)(s32)X1[0]);  // @145_445800
  X1[1] = F2U((float)(s32)X1[1]);  // @146_445800
  X1[2] = F2U((float)(s32)X1[2]);  // @147_445800
  X1[3] = F2U((float)(s32)X1[3]);  // @148_445800
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @149_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806036) + 0), 4); v; });  // @150_445800
  X0[1] = 0;  // @151_445800
  X0[2] = 0;  // @152_445800
  X0[3] = 0;  // @153_445800
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @154_445800
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @155_445800
  L44599e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @157_445800
  X0[1] = 0;  // @158_445800
  X0[2] = 0;  // @159_445800
  X0[3] = 0;  // @160_445800
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X2[0], 4);  // @161_445800
  X2[0] = F2U(U2F(X2[0]) + U2F(X2[0]));  // @162_445800
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @163_445800
  goto L445a29;  // @164_445800
  L4459b5:;
  FL[0] = eax; FL[1] = (u32)(2);  // @166_445800
  if (FL[0] != FL[1]) goto L445a56;  // @167_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @168_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @169_445800
  FL[2] = (eax & eax);  // @170_445800
  if (FL[2] == 0) goto L4459d7;  // @171_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @172_445800
  if (FL[0] != FL[1]) goto L445a02;  // @173_445800
  L4459d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @175_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @176_445800
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @177_445800
  ecx = edx = 0;  // @178_445800
  ecx = (u32)(EBP - 33);  // @179_445800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 33), &v, sizeof v); }  // @180_445800
  PV[14] = (u32)(ecx);  // @181_445800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @182_445800
  ecx = eax;  // @183_445800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6805980), PV[14]);  // @184_445800
  ecx = edx = 0;  // @185_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 33), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @186_445800
  if (FL[0] == FL[1]) goto L445a0c;  // @187_445800
  L445a02:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806024) + 0), 4); v; });  // @189_445800
  X1[1] = 0;  // @190_445800
  X1[2] = 0;  // @191_445800
  X1[3] = 0;  // @192_445800
  goto L445a14;  // @193_445800
  L445a0c:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806032) + 0), 4); v; });  // @195_445800
  X1[1] = 0;  // @196_445800
  X1[2] = 0;  // @197_445800
  X1[3] = 0;  // @198_445800
  L445a14:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @200_445800
  X0[1] = 0;  // @201_445800
  X0[2] = 0;  // @202_445800
  X0[3] = 0;  // @203_445800
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X1[0], 4);  // @204_445800
  X1[0] = F2U(U2F(X1[0]) + U2F(X1[0]));  // @205_445800
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @206_445800
  L445a29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @208_445800
  ecx = (u32)(EBP - 20);  // @209_445800
  PV[15] = (u32)(ecx);  // @210_445800
  ecx = edi;  // @211_445800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @212_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @213_445800
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @214_445800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[15]);  // @215_445800
  ecx = edx = 0;  // @216_445800
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @217_445800
  goto L445ae6;  // @218_445800
  L445a56:;
  FL[0] = eax; FL[1] = (u32)(3);  // @220_445800
  if (FL[0] != FL[1]) goto L445ae6;  // @221_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @222_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @223_445800
  FL[2] = (eax & eax);  // @224_445800
  if (FL[2] == 0) goto L445a78;  // @225_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @226_445800
  if (FL[0] != FL[1]) goto L445aa3;  // @227_445800
  L445a78:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @229_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @230_445800
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @231_445800
  ecx = edx = 0;  // @232_445800
  ecx = (u32)(EBP - 33);  // @233_445800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 33), &v, sizeof v); }  // @234_445800
  PV[16] = (u32)(ecx);  // @235_445800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @236_445800
  ecx = eax;  // @237_445800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6805980), PV[16]);  // @238_445800
  ecx = edx = 0;  // @239_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 33), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @240_445800
  if (FL[0] == FL[1]) goto L445aad;  // @241_445800
  L445aa3:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806028) + 0), 4); v; });  // @243_445800
  X1[1] = 0;  // @244_445800
  X1[2] = 0;  // @245_445800
  X1[3] = 0;  // @246_445800
  goto L445ab0;  // @247_445800
  L445aad:;
  X1[0] = 0;  // @249_445800
  X1[1] = 0;  // @250_445800
  X1[2] = 0;  // @251_445800
  X1[3] = 0;  // @252_445800
  L445ab0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @254_445800
  X0[1] = 0;  // @255_445800
  X0[2] = 0;  // @256_445800
  X0[3] = 0;  // @257_445800
  ecx = (u32)(EBP - 20);  // @258_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @259_445800
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @260_445800
  X1[0] = F2U(U2F(X1[0]) + U2F(X1[0]));  // @261_445800
  PV[17] = (u32)(ecx);  // @262_445800
  ecx = edi;  // @263_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @264_445800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @265_445800
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @266_445800
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @267_445800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[17]);  // @268_445800
  ecx = edx = 0;  // @269_445800
  L445ae6:;
  ecx = esi;  // @271_445800
  eax = ext_4e1600_thiscall1(ecx);  // @272_445800
  ecx = edx = 0;  // @273_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @274_445800
  if (FL[0] != FL[1]) goto L445b12;  // @275_445800
  eax = (u32)(EBP - 40);  // @276_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @277_445800
  PV[18] = (u32)(eax);  // @278_445800
  ecx = esi;  // @279_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[18], (u32)(1));  // @280_445800
  ecx = edx = 0;  // @281_445800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @282_445800
  if (FL[0] != FL[1]) goto L445b12;  // @283_445800
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }) | (u32)(524288))); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @284_445800
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @285_445800
  L445b12:;
  ecx = esi;  // @287_445800
  eax = ext_4e1600_thiscall1(ecx);  // @288_445800
  ecx = edx = 0;  // @289_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @290_445800
  if (FL[0] != FL[1]) goto L445b2a;  // @291_445800
  eax = (u32)(edi + 112);  // @292_445800
  ecx = esi;  // @293_445800
  PV[19] = (u32)(eax);  // @294_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[19], (u32)(1));  // @295_445800
  ecx = edx = 0;  // @296_445800
  L445b2a:;
  ecx = esi;  // @298_445800
  eax = ext_4e1600_thiscall1(ecx);  // @299_445800
  ecx = edx = 0;  // @300_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @301_445800
  if (FL[0] != FL[1]) goto L445b42;  // @302_445800
  eax = (u32)(edi + 116);  // @303_445800
  ecx = esi;  // @304_445800
  PV[20] = (u32)(eax);  // @305_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[20], (u32)(1));  // @306_445800
  ecx = edx = 0;  // @307_445800
  L445b42:;
  ecx = esi;  // @309_445800
  eax = ext_4e1600_thiscall1(ecx);  // @310_445800
  ecx = edx = 0;  // @311_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @312_445800
  if (FL[0] != FL[1]) goto L445b58;  // @313_445800
  eax = (u32)(EBP - 40);  // @314_445800
  ecx = esi;  // @315_445800
  PV[21] = (u32)(eax);  // @316_445800
  eax = ext_4e1440_thiscall2(ecx, PV[21]);  // @317_445800
  ecx = edx = 0;  // @318_445800
  L445b58:;
  ecx = esi;  // @320_445800
  eax = ext_4e1600_thiscall1(ecx);  // @321_445800
  ecx = edx = 0;  // @322_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @323_445800
  if (FL[0] != FL[1]) goto L445b84;  // @324_445800
  eax = (u32)(EBP - 40);  // @325_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @326_445800
  PV[22] = (u32)(eax);  // @327_445800
  ecx = esi;  // @328_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[22], (u32)(1));  // @329_445800
  ecx = edx = 0;  // @330_445800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @331_445800
  if (FL[0] == FL[1]) goto L445b84;  // @332_445800
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }) | (u32)(65536))); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @333_445800
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @334_445800
  L445b84:;
  ecx = esi;  // @336_445800
  eax = ext_4e1600_thiscall1(ecx);  // @337_445800
  ecx = edx = 0;  // @338_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @339_445800
  if (FL[0] != FL[1]) goto L445c0a;  // @340_445800
  eax = (u32)(EBP - 20);  // @341_445800
  ecx = esi;  // @342_445800
  PV[23] = (u32)(eax);  // @343_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[23], (u32)(4));  // @344_445800
  ecx = edx = 0;  // @345_445800
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 377) + 0), 4); v; });  // @346_445800
  X5[1] = 0;  // @347_445800
  X5[2] = 0;  // @348_445800
  X5[3] = 0;  // @349_445800
  ecx = (u32)(EBP - 20);  // @350_445800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 369) + 0), 4); v; });  // @351_445800
  X1[1] = 0;  // @352_445800
  X1[2] = 0;  // @353_445800
  X1[3] = 0;  // @354_445800
  X0[0] = X5[0];  // @355_445800
  X0[1] = X5[1];  // @356_445800
  X0[2] = X5[2];  // @357_445800
  X0[3] = X5[3];  // @358_445800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @359_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @360_445800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @361_445800
  PV[24] = (u32)(ecx);  // @362_445800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 381) + 0), 4); v; });  // @363_445800
  X3[1] = 0;  // @364_445800
  X3[2] = 0;  // @365_445800
  X3[3] = 0;  // @366_445800
  ecx = edi;  // @367_445800
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @368_445800
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @369_445800
  X0[0] = X3[0];  // @370_445800
  X0[1] = X3[1];  // @371_445800
  X0[2] = X3[2];  // @372_445800
  X0[3] = X3[3];  // @373_445800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @374_445800
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @375_445800
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @376_445800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 373) + 0), 4); v; });  // @377_445800
  X1[1] = 0;  // @378_445800
  X1[2] = 0;  // @379_445800
  X1[3] = 0;  // @380_445800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @381_445800
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X5[0], 4);  // @382_445800
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X3[0], 4);  // @383_445800
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @384_445800
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X1[0], 4);  // @385_445800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[24]);  // @386_445800
  ecx = edx = 0;  // @387_445800
  L445c0a:;
  ecx = esi;  // @389_445800
  eax = ext_4e1600_thiscall1(ecx);  // @390_445800
  ecx = edx = 0;  // @391_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @392_445800
  if (FL[0] != FL[1]) goto L445c36;  // @393_445800
  eax = (u32)(EBP - 40);  // @394_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @395_445800
  PV[25] = (u32)(eax);  // @396_445800
  ecx = esi;  // @397_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[25], (u32)(1));  // @398_445800
  ecx = edx = 0;  // @399_445800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @400_445800
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @401_445800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 368), &v, sizeof v); }  // @402_445800
  L445c36:;
  ecx = esi;  // @404_445800
  eax = ext_4e1b30_thiscall1(ecx);  // @405_445800
  ecx = edx = 0;  // @406_445800
  ext_633654(G(u32, 0x6f5630));  // @407_445800
  return eax;  // @408_445800
}
PCREG(445800, lifted_445800);

extern "C" u32 THISCALL lifted_5a4120(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5a4120
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @1_5a4120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 267), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_5a4120
  if (FL[0] == FL[1]) goto L5a419f;  // @3_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 283), sizeof v); (u32)v; });  // @4_5a4120
  FL[2] = (ecx & ecx);  // @5_5a4120
  if (FL[2] == 0) goto L5a418c;  // @6_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_5a4120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @8_5a4120
  X0[1] = 0;  // @9_5a4120
  X0[2] = 0;  // @10_5a4120
  X0[3] = 0;  // @11_5a4120
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 295) + 0), 4); v; })));  // @12_5a4120
  __builtin_memcpy((void *)((u32)(ebx + 295) + 0), &X0[0], 4);  // @13_5a4120
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 275) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 275) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 275) + 0), 4); v; }))))))) goto L5a418c;  // @14_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @15_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5a4120
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @17_5a4120
  ecx = edx = 0;  // @18_5a4120
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @19_5a4120
  eax = (eax - edx);  // @20_5a4120
  FL[3] = eax;  // @21_5a4120
  esi = eax;  // @22_5a4120
  esi = (u32)((s32)esi >> (u32)(1));  // @23_5a4120
  FL[3] = esi;  // @24_5a4120
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x67644c))();  // @25_5a4120
  ecx = edx = 0;  // @26_5a4120
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @27_5a4120
  { s32 d_ = (s32)(esi); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @28_5a4120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 295), &v, sizeof v); }  // @29_5a4120
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 299), &v, sizeof v); }  // @30_5a4120
  L5a418c:;
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 299), sizeof v); (u32)v; });  // @32_5a4120
  ecx = ebx;  // @33_5a4120
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 283), sizeof v); (u32)v; });  // @34_5a4120
  eax = ext_5a4f70_thiscall3(ecx, PV[1], PV[0]);  // @35_5a4120
  ecx = edx = 0;  // @36_5a4120
  L5a419f:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 88), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @38_5a4120
  if (FL[0] == FL[1]) goto L5a42c4;  // @39_5a4120
  esi = (u32)(ebx + 111);  // @40_5a4120
  edi = (u32)(4);  // @41_5a4120
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @42_5a4120
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @43_5a4120
  L5a41c0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi - 14), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @45_5a4120
  if (FL[0] == FL[1]) goto L5a428a;  // @46_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_5a4120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @48_5a4120
  X0[1] = 0;  // @49_5a4120
  X0[2] = 0;  // @50_5a4120
  X0[3] = 0;  // @51_5a4120
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @52_5a4120
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @53_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @54_5a4120
  eax = ext_589c20_thiscall2(ecx, (u32)(0));  // @55_5a4120
  ecx = edx = 0;  // @56_5a4120
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @57_5a4120
  FL[0] = ecx; FL[1] = (u32)(5);  // @58_5a4120
  if (FL[0] == FL[1]) goto L5a4218;  // @59_5a4120
  FL[0] = ecx; FL[1] = (u32)(30);  // @60_5a4120
  if (FL[0] == FL[1]) goto L5a420a;  // @61_5a4120
  FL[0] = ecx; FL[1] = (u32)(60);  // @62_5a4120
  if (FL[0] != FL[1]) goto L5a422b;  // @63_5a4120
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 94), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @64_5a4120
  if (FL[0] != FL[1]) goto L5a422b;  // @65_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 94), &v, sizeof v); }  // @66_5a4120
  goto L5a4224;  // @67_5a4120
  L5a420a:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 95), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @69_5a4120
  if (FL[0] != FL[1]) goto L5a422b;  // @70_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 95), &v, sizeof v); }  // @71_5a4120
  goto L5a4224;  // @72_5a4120
  L5a4218:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @74_5a4120
  if (FL[0] != FL[1]) goto L5a422b;  // @75_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 96), &v, sizeof v); }  // @76_5a4120
  L5a4224:;
  ecx = eax;  // @78_5a4120
  eax = ext_59a5e0_thiscall2(ecx, (u32)(10));  // @79_5a4120
  ecx = edx = 0;  // @80_5a4120
  L5a422b:;
  X0[0] = 0;  // @82_5a4120
  X0[1] = 0;  // @83_5a4120
  X0[2] = 0;  // @84_5a4120
  X0[3] = 0;  // @85_5a4120
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; }))))) goto L5a42b2;  // @86_5a4120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @87_5a4120
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 265), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @88_5a4120
  if (FL[0] != FL[1]) goto L5a42b2;  // @89_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_5a4120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @91_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @92_5a4120
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_5a4120
  { u32 va_[] = {(u32)(7008556), (u32)(0), (u32)(7008460), (u32)(570), (u32)(1), (u32)(0)}; eax = w3e_vacall(*(u32 *)(eax + 276), ecx, 6, va_); }  // @95_5a4120
  ecx = edx = 0;  // @96_5a4120
  eax = (eax & 0xffff);  // @97_5a4120
  ecx = esi;  // @98_5a4120
  PV[2] = (u32)(eax);  // @99_5a4120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 296)))(ecx, PV[2]);  // @100_5a4120
  ecx = edx = 0;  // @101_5a4120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @102_5a4120
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @103_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 265), &v, sizeof v); }  // @104_5a4120
  goto L5a42b2;  // @105_5a4120
  L5a428a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @107_5a4120
  X1[1] = 0;  // @108_5a4120
  X1[2] = 0;  // @109_5a4120
  X1[3] = 0;  // @110_5a4120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 76) + 0), 4); v; });  // @111_5a4120
  X0[1] = 0;  // @112_5a4120
  X0[2] = 0;  // @113_5a4120
  X0[3] = 0;  // @114_5a4120
  if ((!(!(U2F(X1[0]) >= U2F(X0[0]))))) goto L5a42ae;  // @115_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_5a4120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @117_5a4120
  X0[1] = 0;  // @118_5a4120
  X0[2] = 0;  // @119_5a4120
  X0[3] = 0;  // @120_5a4120
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @121_5a4120
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @122_5a4120
  L5a42ae:;
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @124_5a4120
  L5a42b2:;
  esi = (esi + (u32)(18));  // @126_5a4120
  FL[3] = esi;  // @127_5a4120
  edi = (edi - (u32)(1));  // @128_5a4120
  FL[3] = edi;  // @129_5a4120
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @130_5a4120
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @131_5a4120
  if (FL[3] != 0) goto L5a41c0;  // @132_5a4120
  L5a42c4:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 89), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @134_5a4120
  if (FL[0] == FL[1]) goto L5a438a;  // @135_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_5a4120
  X1[0] = 0;  // @137_5a4120
  X1[1] = 0;  // @138_5a4120
  X1[2] = 0;  // @139_5a4120
  X1[3] = 0;  // @140_5a4120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 80) + 0), 4); v; });  // @141_5a4120
  X0[1] = 0;  // @142_5a4120
  X0[2] = 0;  // @143_5a4120
  X0[3] = 0;  // @144_5a4120
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @145_5a4120
  __builtin_memcpy((void *)((u32)(ebx + 80) + 0), &X0[0], 4);  // @146_5a4120
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L5a433a;  // @147_5a4120
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 265), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @148_5a4120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 80), &v, sizeof v); }  // @149_5a4120
  if (FL[0] != FL[1]) goto L5a433a;  // @150_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @151_5a4120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @152_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @153_5a4120
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @154_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_5a4120
  { u32 va_[] = {(u32)(7008556), (u32)(0), (u32)(7008460), (u32)(603), (u32)(0), (u32)(0)}; eax = w3e_vacall(*(u32 *)(eax + 276), ecx, 6, va_); }  // @156_5a4120
  ecx = edx = 0;  // @157_5a4120
  eax = (eax & 0xffff);  // @158_5a4120
  ecx = esi;  // @159_5a4120
  PV[3] = (u32)(eax);  // @160_5a4120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 296)))(ecx, PV[3]);  // @161_5a4120
  ecx = edx = 0;  // @162_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 265), &v, sizeof v); }  // @163_5a4120
  L5a433a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @165_5a4120
  eax = ext_589c20_thiscall2(ecx, (u32)(0));  // @166_5a4120
  ecx = edx = 0;  // @167_5a4120
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 80) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @168_5a4120
  FL[0] = ecx; FL[1] = (u32)(5);  // @169_5a4120
  if (FL[0] == FL[1]) goto L5a4377;  // @170_5a4120
  FL[0] = ecx; FL[1] = (u32)(30);  // @171_5a4120
  if (FL[0] == FL[1]) goto L5a4369;  // @172_5a4120
  FL[0] = ecx; FL[1] = (u32)(60);  // @173_5a4120
  if (FL[0] != FL[1]) goto L5a438a;  // @174_5a4120
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 94), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @175_5a4120
  if (FL[0] != FL[1]) goto L5a438a;  // @176_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 94), &v, sizeof v); }  // @177_5a4120
  goto L5a4383;  // @178_5a4120
  L5a4369:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 95), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @180_5a4120
  if (FL[0] != FL[1]) goto L5a438a;  // @181_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 95), &v, sizeof v); }  // @182_5a4120
  goto L5a4383;  // @183_5a4120
  L5a4377:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @185_5a4120
  if (FL[0] != FL[1]) goto L5a438a;  // @186_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 96), &v, sizeof v); }  // @187_5a4120
  L5a4383:;
  ecx = eax;  // @189_5a4120
  eax = ext_59a5e0_thiscall2(ecx, (u32)(10));  // @190_5a4120
  ecx = edx = 0;  // @191_5a4120
  L5a438a:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 90), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @193_5a4120
  if (FL[0] == FL[1]) goto L5a4437;  // @194_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 99), sizeof v); (u32)v; });  // @195_5a4120
  ecx = 0;  // @196_5a4120
  FL[3] = ecx;  // @197_5a4120
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @198_5a4120
  if ((s32)FL[0] < (s32)FL[1]) goto L5a43a7;  // @199_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 98), &v, sizeof v); }  // @200_5a4120
  ecx = (u32)(1);  // @201_5a4120
  L5a43a7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 117), sizeof v); (u32)v; });  // @203_5a4120
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @204_5a4120
  if ((s32)FL[0] < (s32)FL[1]) goto L5a43b8;  // @205_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 116), &v, sizeof v); }  // @206_5a4120
  ecx = (u32)(1);  // @207_5a4120
  L5a43b8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 135), sizeof v); (u32)v; });  // @209_5a4120
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @210_5a4120
  if ((s32)FL[0] < (s32)FL[1]) goto L5a43cf;  // @211_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 134), &v, sizeof v); }  // @212_5a4120
  ecx = (u32)(1);  // @213_5a4120
  L5a43cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 153), sizeof v); (u32)v; });  // @215_5a4120
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @216_5a4120
  if ((s32)FL[0] < (s32)FL[1]) goto L5a43e6;  // @217_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @218_5a4120
  ecx = (u32)(1);  // @219_5a4120
  L5a43e6:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 266), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @221_5a4120
  if (FL[0] != FL[1]) goto L5a4437;  // @222_5a4120
  FL[2] = (ecx & ecx);  // @223_5a4120
  if (FL[2] == 0) goto L5a4437;  // @224_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @225_5a4120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @226_5a4120
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422708), sizeof v); (u32)v; });  // @227_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @228_5a4120
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @229_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @230_5a4120
  { u32 va_[] = {(u32)(7008696), (u32)(0), (u32)(7008460), (u32)(657), PV[4], (u32)(0)}; eax = w3e_vacall(*(u32 *)(eax + 276), ecx, 6, va_); }  // @231_5a4120
  ecx = edx = 0;  // @232_5a4120
  eax = (eax & 0xffff);  // @233_5a4120
  ecx = esi;  // @234_5a4120
  PV[5] = (u32)(eax);  // @235_5a4120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 296)))(ecx, PV[5]);  // @236_5a4120
  ecx = edx = 0;  // @237_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 266), &v, sizeof v); }  // @238_5a4120
  L5a4437:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 91), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @240_5a4120
  if (FL[0] == FL[1]) goto L5a44e4;  // @241_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 103), sizeof v); (u32)v; });  // @242_5a4120
  ecx = 0;  // @243_5a4120
  FL[3] = ecx;  // @244_5a4120
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @245_5a4120
  if ((s32)FL[0] < (s32)FL[1]) goto L5a4454;  // @246_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 98), &v, sizeof v); }  // @247_5a4120
  ecx = (u32)(1);  // @248_5a4120
  L5a4454:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 121), sizeof v); (u32)v; });  // @250_5a4120
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @251_5a4120
  if ((s32)FL[0] < (s32)FL[1]) goto L5a4465;  // @252_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 116), &v, sizeof v); }  // @253_5a4120
  ecx = (u32)(1);  // @254_5a4120
  L5a4465:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 139), sizeof v); (u32)v; });  // @256_5a4120
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @257_5a4120
  if ((s32)FL[0] < (s32)FL[1]) goto L5a447c;  // @258_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 134), &v, sizeof v); }  // @259_5a4120
  ecx = (u32)(1);  // @260_5a4120
  L5a447c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 157), sizeof v); (u32)v; });  // @262_5a4120
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @263_5a4120
  if ((s32)FL[0] < (s32)FL[1]) goto L5a4493;  // @264_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @265_5a4120
  ecx = (u32)(1);  // @266_5a4120
  L5a4493:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 266), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @268_5a4120
  if (FL[0] != FL[1]) goto L5a44e4;  // @269_5a4120
  FL[2] = (ecx & ecx);  // @270_5a4120
  if (FL[2] == 0) goto L5a44e4;  // @271_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @272_5a4120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @273_5a4120
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262776), sizeof v); (u32)v; });  // @274_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @275_5a4120
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @276_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @277_5a4120
  { u32 va_[] = {(u32)(7008696), (u32)(0), (u32)(7008460), (u32)(684), PV[6], (u32)(0)}; eax = w3e_vacall(*(u32 *)(eax + 276), ecx, 6, va_); }  // @278_5a4120
  ecx = edx = 0;  // @279_5a4120
  eax = (eax & 0xffff);  // @280_5a4120
  ecx = esi;  // @281_5a4120
  PV[7] = (u32)(eax);  // @282_5a4120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 296)))(ecx, PV[7]);  // @283_5a4120
  ecx = edx = 0;  // @284_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 266), &v, sizeof v); }  // @285_5a4120
  L5a44e4:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @287_5a4120
  if (FL[0] == FL[1]) goto L5a457f;  // @288_5a4120
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 93), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @289_5a4120
  if (FL[0] != FL[1]) goto L5a457f;  // @290_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @291_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @292_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @293_5a4120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(1));  // @294_5a4120
  ecx = edx = 0;  // @295_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @296_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @297_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @298_5a4120
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @299_5a4120
  ecx = edx = 0;  // @300_5a4120
  ecx = (u32)(EBP - 8);  // @301_5a4120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @302_5a4120
  PV[8] = (u32)(ecx);  // @303_5a4120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @304_5a4120
  ecx = eax;  // @305_5a4120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6980304), PV[8]);  // @306_5a4120
  ecx = edx = 0;  // @307_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @308_5a4120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @309_5a4120
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @310_5a4120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @311_5a4120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @312_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @313_5a4120
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @314_5a4120
  { u32 va_[] = {(u32)(6973080), (u32)(0), (u32)(7008460), (u32)(695), (u32)(0)}; eax = w3e_vacall(*(u32 *)(eax + 276), ecx, 5, va_); }  // @315_5a4120
  ecx = edx = 0;  // @316_5a4120
  eax = (eax & 0xffff);  // @317_5a4120
  ecx = esi;  // @318_5a4120
  PV[9] = (u32)(eax);  // @319_5a4120
  PV[10] = (u32)(ebx);  // @320_5a4120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, PV[10], PV[9]);  // @321_5a4120
  ecx = edx = 0;  // @322_5a4120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @323_5a4120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 93), &v, sizeof v); }  // @324_5a4120
  L5a457f:;
  return eax;  // @326_5a4120
}
PCREG(5a4120, lifted_5a4120);

extern "C" u32 THISCALL lifted_505110(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_505110
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @1_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_505110
  ecx = edx = 0;  // @4_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_505110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @7_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @8_505110
  ecx = edx = 0;  // @9_505110
  edi = eax;  // @10_505110
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @11_505110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @12_505110
  if (FL[2] == 0) goto L505186;  // @13_505110
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @14_505110
  if (FL[0] == FL[1]) goto L505186;  // @15_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @16_505110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_505110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @18_505110
  ecx = edx = 0;  // @19_505110
  PV[0] = (u32)(eax);  // @20_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_505110
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @22_505110
  ecx = edx = 0;  // @23_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @24_505110
  FL[2] = (eax & eax);  // @25_505110
  if (FL[2] == 0) goto L505185;  // @26_505110
  eax = ((u32(STDCALL *)(void))(eax))();  // @27_505110
  ecx = edx = 0;  // @28_505110
  goto L505186;  // @29_505110
  L505185:;
  __builtin_trap();  // @31_505110
  L505186:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @33_505110
  X0[1] = 0;  // @34_505110
  X0[2] = 0;  // @35_505110
  X0[3] = 0;  // @36_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @37_505110
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @38_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @39_505110
  ecx = edx = 0;  // @40_505110
  edi = eax;  // @41_505110
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @42_505110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @43_505110
  if (FL[2] == 0) goto L5051dd;  // @44_505110
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @45_505110
  if (FL[0] == FL[1]) goto L5051dd;  // @46_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @47_505110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_505110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @49_505110
  ecx = edx = 0;  // @50_505110
  PV[1] = (u32)(eax);  // @51_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @52_505110
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6932144), (u32)(6932792));  // @53_505110
  ecx = edx = 0;  // @54_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @55_505110
  FL[2] = (eax & eax);  // @56_505110
  if (FL[2] == 0) goto L5051dc;  // @57_505110
  eax = ((u32(STDCALL *)(void))(eax))();  // @58_505110
  ecx = edx = 0;  // @59_505110
  goto L5051dd;  // @60_505110
  L5051dc:;
  __builtin_trap();  // @62_505110
  L5051dd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @64_505110
  X0[1] = 0;  // @65_505110
  X0[2] = 0;  // @66_505110
  X0[3] = 0;  // @67_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @68_505110
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @69_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @70_505110
  ecx = edx = 0;  // @71_505110
  edi = eax;  // @72_505110
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @73_505110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @74_505110
  if (FL[2] == 0) goto L505234;  // @75_505110
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @76_505110
  if (FL[0] == FL[1]) goto L505234;  // @77_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @78_505110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_505110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @80_505110
  ecx = edx = 0;  // @81_505110
  PV[2] = (u32)(eax);  // @82_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @83_505110
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6932144), (u32)(6932792));  // @84_505110
  ecx = edx = 0;  // @85_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @86_505110
  FL[2] = (eax & eax);  // @87_505110
  if (FL[2] == 0) goto L505233;  // @88_505110
  eax = ((u32(STDCALL *)(void))(eax))();  // @89_505110
  ecx = edx = 0;  // @90_505110
  goto L505234;  // @91_505110
  L505233:;
  __builtin_trap();  // @93_505110
  L505234:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @95_505110
  X0[1] = 0;  // @96_505110
  X0[2] = 0;  // @97_505110
  X0[3] = 0;  // @98_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @99_505110
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @100_505110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @101_505110
  X0[1] = 0;  // @102_505110
  X0[2] = 0;  // @103_505110
  X0[3] = 0;  // @104_505110
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @105_505110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @106_505110
  X0[1] = 0;  // @107_505110
  X0[2] = 0;  // @108_505110
  X0[3] = 0;  // @109_505110
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @110_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(6));  // @111_505110
  ecx = edx = 0;  // @112_505110
  edi = eax;  // @113_505110
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @114_505110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @115_505110
  if (FL[2] == 0) goto L50529f;  // @116_505110
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @117_505110
  if (FL[0] == FL[1]) goto L50529f;  // @118_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @119_505110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_505110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @121_505110
  ecx = edx = 0;  // @122_505110
  PV[3] = (u32)(eax);  // @123_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @124_505110
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6932144), (u32)(6932792));  // @125_505110
  ecx = edx = 0;  // @126_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @127_505110
  FL[2] = (eax & eax);  // @128_505110
  if (FL[2] == 0) goto L50529e;  // @129_505110
  eax = ((u32(STDCALL *)(void))(eax))();  // @130_505110
  ecx = edx = 0;  // @131_505110
  goto L50529f;  // @132_505110
  L50529e:;
  __builtin_trap();  // @134_505110
  L50529f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @136_505110
  X0[1] = 0;  // @137_505110
  X0[2] = 0;  // @138_505110
  X0[3] = 0;  // @139_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @140_505110
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @141_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(5));  // @142_505110
  ecx = edx = 0;  // @143_505110
  edi = eax;  // @144_505110
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @145_505110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @146_505110
  if (FL[2] == 0) goto L5052f6;  // @147_505110
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @148_505110
  if (FL[0] == FL[1]) goto L5052f6;  // @149_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @150_505110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_505110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @152_505110
  ecx = edx = 0;  // @153_505110
  PV[4] = (u32)(eax);  // @154_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @155_505110
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[4], (u32)(6932144), (u32)(6932792));  // @156_505110
  ecx = edx = 0;  // @157_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @158_505110
  FL[2] = (eax & eax);  // @159_505110
  if (FL[2] == 0) goto L5052f5;  // @160_505110
  eax = ((u32(STDCALL *)(void))(eax))();  // @161_505110
  ecx = edx = 0;  // @162_505110
  goto L5052f6;  // @163_505110
  L5052f5:;
  __builtin_trap();  // @165_505110
  L5052f6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @167_505110
  X0[1] = 0;  // @168_505110
  X0[2] = 0;  // @169_505110
  X0[3] = 0;  // @170_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @171_505110
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @172_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(4));  // @173_505110
  ecx = edx = 0;  // @174_505110
  edi = eax;  // @175_505110
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @176_505110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @177_505110
  if (FL[2] == 0) goto L50534d;  // @178_505110
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @179_505110
  if (FL[0] == FL[1]) goto L50534d;  // @180_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @181_505110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @182_505110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @183_505110
  ecx = edx = 0;  // @184_505110
  PV[5] = (u32)(eax);  // @185_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @186_505110
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6932144), (u32)(6932792));  // @187_505110
  ecx = edx = 0;  // @188_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @189_505110
  FL[2] = (eax & eax);  // @190_505110
  if (FL[2] == 0) goto L50534c;  // @191_505110
  eax = ((u32(STDCALL *)(void))(eax))();  // @192_505110
  ecx = edx = 0;  // @193_505110
  goto L50534d;  // @194_505110
  L50534c:;
  __builtin_trap();  // @196_505110
  L50534d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @198_505110
  X0[1] = 0;  // @199_505110
  X0[2] = 0;  // @200_505110
  X0[3] = 0;  // @201_505110
  ecx = (u32)(EBP - 16);  // @202_505110
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @203_505110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @204_505110
  X0[1] = 0;  // @205_505110
  X0[2] = 0;  // @206_505110
  X0[3] = 0;  // @207_505110
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @208_505110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @209_505110
  X0[1] = 0;  // @210_505110
  X0[2] = 0;  // @211_505110
  X0[3] = 0;  // @212_505110
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @213_505110
  eax = ext_4e09b0_thiscall1(ecx);  // @214_505110
  ecx = edx = 0;  // @215_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @216_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(7));  // @217_505110
  ecx = edx = 0;  // @218_505110
  edi = eax;  // @219_505110
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @220_505110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @221_505110
  if (FL[2] == 0) goto L5053c0;  // @222_505110
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @223_505110
  if (FL[0] == FL[1]) goto L5053c0;  // @224_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @225_505110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @226_505110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @227_505110
  ecx = edx = 0;  // @228_505110
  PV[6] = (u32)(eax);  // @229_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @230_505110
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[6], (u32)(6932144), (u32)(6932792));  // @231_505110
  ecx = edx = 0;  // @232_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @233_505110
  FL[2] = (eax & eax);  // @234_505110
  if (FL[2] == 0) goto L5053bf;  // @235_505110
  eax = ((u32(STDCALL *)(void))(eax))();  // @236_505110
  ecx = edx = 0;  // @237_505110
  goto L5053c0;  // @238_505110
  L5053bf:;
  __builtin_trap();  // @240_505110
  L5053c0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @242_505110
  X0[1] = 0;  // @243_505110
  X0[2] = 0;  // @244_505110
  X0[3] = 0;  // @245_505110
  ebx = 0;  // @246_505110
  FL[3] = ebx;  // @247_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @248_505110
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @249_505110
  FL[2] = (ecx & ecx);  // @250_505110
  if ((s32)FL[2] > 0) goto L5053e2;  // @251_505110
  PV[7] = (u32)(ecx);  // @252_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @253_505110
  eax = ext_5057e0_thiscall3(ecx, (u32)(6934352), PV[7]);  // @254_505110
  ecx = edx = 0;  // @255_505110
  goto L505460;  // @256_505110
  L5053e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @258_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @259_505110
  PV[8] = ebx;  // @260_505110
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @261_505110
  edi = (edi + ecx);  // @262_505110
  FL[3] = edi;  // @263_505110
  PV[9] = ebx;  // @264_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @265_505110
  PV[10] = (u32)(edi);  // @266_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @267_505110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[10], (u32)(0), PV[9], (u32)(3212836864), PV[8], (u32)(1065353216));  // @268_505110
  ecx = edx = 0;  // @269_505110
  ebx = eax;  // @270_505110
  FL[2] = (ebx & ebx);  // @271_505110
  if (FL[2] == 0) goto L505460;  // @272_505110
  edx = (u32)(EBP - 16);  // @273_505110
  ecx = (u32)(EBP - 64);  // @274_505110
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @275_505110
  ecx = edx = 0;  // @276_505110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @277_505110
  X0[1] = 0;  // @278_505110
  X0[2] = 0;  // @279_505110
  X0[3] = 0;  // @280_505110
  X1[0] = 0;  // @281_505110
  X1[1] = 0;  // @282_505110
  X1[2] = 0;  // @283_505110
  X1[3] = 0;  // @284_505110
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L505444;  // @285_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; });  // @286_505110
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; }));  // @287_505110
  FL[3] = eax;  // @288_505110
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @289_505110
  X0[0] = F2U((float)(s32)X0[0]);  // @290_505110
  X0[1] = F2U((float)(s32)X0[1]);  // @291_505110
  X0[2] = F2U((float)(s32)X0[2]);  // @292_505110
  X0[3] = F2U((float)(s32)X0[3]);  // @293_505110
  L505444:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @295_505110
  edx = (u32)(EBP - 28);  // @296_505110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @297_505110
  PV[11] = (u32)(ecx);  // @298_505110
  PV[12] = X0[0];  // @299_505110
  PV[13] = (u32)(edx);  // @300_505110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @301_505110
  edx = (u32)(EBP - 64);  // @302_505110
  PV[14] = (u32)(edx);  // @303_505110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 568)))(ecx, PV[14], PV[13], PV[12]);  // @304_505110
  ecx = edx = 0;  // @305_505110
  L505460:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @307_505110
  PV[15] = (u32)(ebx);  // @308_505110
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @309_505110
  ecx = edx = 0;  // @310_505110
  ecx = eax;  // @311_505110
  eax = ext_5002f0_thiscall2(ecx, PV[15]);  // @312_505110
  ecx = edx = 0;  // @313_505110
  ext_633654(G(u32, 0x6f5630));  // @314_505110
  return eax;  // @315_505110
}
PCREG(505110, lifted_505110);

extern "C" u32 THISCALL lifted_50ed00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @2_50ed00
  ecx = edx = 0;  // @3_50ed00
  edi = eax;  // @4_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @5_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @6_50ed00
  if (FL[2] == 0) goto L50ed57;  // @7_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @8_50ed00
  if (FL[0] == FL[1]) goto L50ed57;  // @9_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @12_50ed00
  ecx = edx = 0;  // @13_50ed00
  PV[0] = (u32)(eax);  // @14_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @16_50ed00
  ecx = edx = 0;  // @17_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_50ed00
  FL[2] = (eax & eax);  // @19_50ed00
  if (FL[2] == 0) goto L50ed56;  // @20_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @21_50ed00
  ecx = edx = 0;  // @22_50ed00
  goto L50ed57;  // @23_50ed00
  L50ed56:;
  __builtin_trap();  // @25_50ed00
  L50ed57:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_50ed00
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_50ed00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @31_50ed00
  ecx = edx = 0;  // @32_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @33_50ed00
  edi = eax;  // @34_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @35_50ed00
  ecx = edx = 0;  // @36_50ed00
  ebx = eax;  // @37_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @38_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @39_50ed00
  if (FL[2] == 0) goto L50edba;  // @40_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @41_50ed00
  if (FL[0] == FL[1]) goto L50edba;  // @42_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @43_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @45_50ed00
  ecx = edx = 0;  // @46_50ed00
  PV[2] = (u32)(eax);  // @47_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6932144), (u32)(6932792));  // @49_50ed00
  ecx = edx = 0;  // @50_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @51_50ed00
  FL[2] = (eax & eax);  // @52_50ed00
  if (FL[2] == 0) goto L50edb9;  // @53_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @54_50ed00
  ecx = edx = 0;  // @55_50ed00
  goto L50edba;  // @56_50ed00
  L50edb9:;
  __builtin_trap();  // @58_50ed00
  L50edba:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @60_50ed00
  X0[1] = 0;  // @61_50ed00
  X0[2] = 0;  // @62_50ed00
  X0[3] = 0;  // @63_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @64_50ed00
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @65_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @66_50ed00
  ecx = edx = 0;  // @67_50ed00
  ebx = eax;  // @68_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @69_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @70_50ed00
  if (FL[2] == 0) goto L50ee11;  // @71_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @72_50ed00
  if (FL[0] == FL[1]) goto L50ee11;  // @73_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @74_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @76_50ed00
  ecx = edx = 0;  // @77_50ed00
  PV[3] = (u32)(eax);  // @78_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @79_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6932144), (u32)(6932792));  // @80_50ed00
  ecx = edx = 0;  // @81_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @82_50ed00
  FL[2] = (eax & eax);  // @83_50ed00
  if (FL[2] == 0) goto L50ee10;  // @84_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @85_50ed00
  ecx = edx = 0;  // @86_50ed00
  goto L50ee11;  // @87_50ed00
  L50ee10:;
  __builtin_trap();  // @89_50ed00
  L50ee11:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @91_50ed00
  X0[1] = 0;  // @92_50ed00
  X0[2] = 0;  // @93_50ed00
  X0[3] = 0;  // @94_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @95_50ed00
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @96_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @97_50ed00
  ecx = edx = 0;  // @98_50ed00
  ebx = eax;  // @99_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @100_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @101_50ed00
  if (FL[2] == 0) goto L50ee68;  // @102_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @103_50ed00
  if (FL[0] == FL[1]) goto L50ee68;  // @104_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @105_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @107_50ed00
  ecx = edx = 0;  // @108_50ed00
  PV[4] = (u32)(eax);  // @109_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[4], (u32)(6932144), (u32)(6932792));  // @111_50ed00
  ecx = edx = 0;  // @112_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @113_50ed00
  FL[2] = (eax & eax);  // @114_50ed00
  if (FL[2] == 0) goto L50ee67;  // @115_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @116_50ed00
  ecx = edx = 0;  // @117_50ed00
  goto L50ee68;  // @118_50ed00
  L50ee67:;
  __builtin_trap();  // @120_50ed00
  L50ee68:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @122_50ed00
  X0[1] = 0;  // @123_50ed00
  X0[2] = 0;  // @124_50ed00
  X0[3] = 0;  // @125_50ed00
  __builtin_memcpy((void *)((u32)(7345268) + 0), &X0[0], 4);  // @126_50ed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @127_50ed00
  X0[1] = 0;  // @128_50ed00
  X0[2] = 0;  // @129_50ed00
  X0[3] = 0;  // @130_50ed00
  __builtin_memcpy((void *)((u32)(7345272) + 0), &X0[0], 4);  // @131_50ed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @132_50ed00
  X0[1] = 0;  // @133_50ed00
  X0[2] = 0;  // @134_50ed00
  X0[3] = 0;  // @135_50ed00
  __builtin_memcpy((void *)((u32)(7345276) + 0), &X0[0], 4);  // @136_50ed00
  FL[2] = (edi & edi);  // @137_50ed00
  if (FL[2] == 0) goto L50eea3;  // @138_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @139_50ed00
  ecx = edi;  // @140_50ed00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(7345268));  // @141_50ed00
  ecx = edx = 0;  // @142_50ed00
  goto L50ef18;  // @143_50ed00
  L50eea3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @145_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6937396), (u32)(688));  // @147_50ed00
  ecx = edx = 0;  // @148_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @149_50ed00
  edi = eax;  // @150_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @151_50ed00
  ecx = edx = 0;  // @152_50ed00
  ebx = eax;  // @153_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @154_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @155_50ed00
  if (FL[2] == 0) goto L50ef08;  // @156_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @157_50ed00
  if (FL[0] == FL[1]) goto L50ef08;  // @158_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @159_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @160_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @161_50ed00
  ecx = edx = 0;  // @162_50ed00
  PV[5] = (u32)(eax);  // @163_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @164_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6932144), (u32)(6932792));  // @165_50ed00
  ecx = edx = 0;  // @166_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @167_50ed00
  FL[2] = (eax & eax);  // @168_50ed00
  if (FL[2] == 0) goto L50ef07;  // @169_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @170_50ed00
  ecx = edx = 0;  // @171_50ed00
  goto L50ef08;  // @172_50ed00
  L50ef07:;
  __builtin_trap();  // @174_50ed00
  L50ef08:;
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @176_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @177_50ed00
  PV[7] = (u32)(edi);  // @178_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(eax + 44)))(PV[7], (u32)(6938384), PV[6]);  // @179_50ed00
  ecx = edx = 0;  // @180_50ed00
  L50ef18:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7345268) + 0), 4); v; });  // @182_50ed00
  X0[1] = 0;  // @183_50ed00
  X0[2] = 0;  // @184_50ed00
  X0[3] = 0;  // @185_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @186_50ed00
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @187_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @188_50ed00
  ecx = edx = 0;  // @189_50ed00
  edi = eax;  // @190_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @191_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @192_50ed00
  if (FL[2] == 0) goto L50ef74;  // @193_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @194_50ed00
  if (FL[0] == FL[1]) goto L50ef74;  // @195_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @196_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @197_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @198_50ed00
  ecx = edx = 0;  // @199_50ed00
  PV[8] = (u32)(eax);  // @200_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @201_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[8], (u32)(6932144), (u32)(6932792));  // @202_50ed00
  ecx = edx = 0;  // @203_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @204_50ed00
  FL[2] = (eax & eax);  // @205_50ed00
  if (FL[2] == 0) goto L50ef73;  // @206_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @207_50ed00
  ecx = edx = 0;  // @208_50ed00
  goto L50ef74;  // @209_50ed00
  L50ef73:;
  __builtin_trap();  // @211_50ed00
  L50ef74:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @213_50ed00
  X0[1] = 0;  // @214_50ed00
  X0[2] = 0;  // @215_50ed00
  X0[3] = 0;  // @216_50ed00
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @217_50ed00
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @218_50ed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7345272) + 0), 4); v; });  // @219_50ed00
  X0[1] = 0;  // @220_50ed00
  X0[2] = 0;  // @221_50ed00
  X0[3] = 0;  // @222_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @223_50ed00
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @224_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @225_50ed00
  ecx = edx = 0;  // @226_50ed00
  edi = eax;  // @227_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @228_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @229_50ed00
  if (FL[2] == 0) goto L50efdc;  // @230_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @231_50ed00
  if (FL[0] == FL[1]) goto L50efdc;  // @232_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @233_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @234_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @235_50ed00
  ecx = edx = 0;  // @236_50ed00
  PV[9] = (u32)(eax);  // @237_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @238_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[9], (u32)(6932144), (u32)(6932792));  // @239_50ed00
  ecx = edx = 0;  // @240_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @241_50ed00
  FL[2] = (eax & eax);  // @242_50ed00
  if (FL[2] == 0) goto L50efdb;  // @243_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @244_50ed00
  ecx = edx = 0;  // @245_50ed00
  goto L50efdc;  // @246_50ed00
  L50efdb:;
  __builtin_trap();  // @248_50ed00
  L50efdc:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @250_50ed00
  X0[1] = 0;  // @251_50ed00
  X0[2] = 0;  // @252_50ed00
  X0[3] = 0;  // @253_50ed00
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @254_50ed00
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @255_50ed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7345276) + 0), 4); v; });  // @256_50ed00
  X0[1] = 0;  // @257_50ed00
  X0[2] = 0;  // @258_50ed00
  X0[3] = 0;  // @259_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @260_50ed00
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @261_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @262_50ed00
  ecx = edx = 0;  // @263_50ed00
  esi = eax;  // @264_50ed00
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @265_50ed00
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @266_50ed00
  if (FL[2] == 0) goto L50f043;  // @267_50ed00
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @268_50ed00
  if (FL[0] == FL[1]) goto L50f043;  // @269_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @270_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @271_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @272_50ed00
  ecx = edx = 0;  // @273_50ed00
  PV[10] = (u32)(eax);  // @274_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @275_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[10], (u32)(6932144), (u32)(6932792));  // @276_50ed00
  ecx = edx = 0;  // @277_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @278_50ed00
  FL[2] = (eax & eax);  // @279_50ed00
  if (FL[2] == 0) goto L50f042;  // @280_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @281_50ed00
  ecx = edx = 0;  // @282_50ed00
  goto L50f043;  // @283_50ed00
  L50f042:;
  __builtin_trap();  // @285_50ed00
  L50f043:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @287_50ed00
  X0[1] = 0;  // @288_50ed00
  X0[2] = 0;  // @289_50ed00
  X0[3] = 0;  // @290_50ed00
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @291_50ed00
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @292_50ed00
  return eax;  // @293_50ed00
}
PCREG(50ed00, lifted_50ed00);

