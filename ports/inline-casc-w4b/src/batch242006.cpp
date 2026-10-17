// batch242006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_545c80_thiscall3(u32, u32, u32) __asm__("ext_545c80");
extern "C" u32 THISCALL ext_545cb0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_545cb0");
extern "C" u32 THISCALL ext_5477a0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5477a0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4b76b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4b76b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b76b0
  ecx = edi;  // @2_4b76b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_4b76b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4b76b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_4b76b0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 116), sizeof v); (u32)v; });  // @6_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[0]);  // @8_4b76b0
  ecx = edx = 0;  // @9_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_4b76b0
  ecx = edi;  // @11_4b76b0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 120), sizeof v); (u32)v; });  // @12_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[1]);  // @13_4b76b0
  ecx = edx = 0;  // @14_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_4b76b0
  ecx = edi;  // @16_4b76b0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; });  // @17_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[2]);  // @18_4b76b0
  ecx = edx = 0;  // @19_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_4b76b0
  ecx = edi;  // @21_4b76b0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; });  // @22_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[3]);  // @23_4b76b0
  ecx = edx = 0;  // @24_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_4b76b0
  ecx = edi;  // @26_4b76b0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @27_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[4]);  // @28_4b76b0
  ecx = edx = 0;  // @29_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_4b76b0
  ecx = edi;  // @31_4b76b0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 136), sizeof v); (u32)v; });  // @32_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[5]);  // @33_4b76b0
  ecx = edx = 0;  // @34_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_4b76b0
  ecx = edi;  // @36_4b76b0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @37_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[6]);  // @38_4b76b0
  ecx = edx = 0;  // @39_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_4b76b0
  ecx = edi;  // @41_4b76b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 157), sizeof v); (u32)v; });  // @42_4b76b0
  PV[7] = (u32)(eax);  // @43_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[7]);  // @44_4b76b0
  ecx = edx = 0;  // @45_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_4b76b0
  ecx = edi;  // @47_4b76b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 158), sizeof v); (u32)v; });  // @48_4b76b0
  PV[8] = (u32)(eax);  // @49_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[8]);  // @50_4b76b0
  ecx = edx = 0;  // @51_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_4b76b0
  ecx = edi;  // @53_4b76b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 159), sizeof v); (u32)v; });  // @54_4b76b0
  PV[9] = (u32)(eax);  // @55_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[9]);  // @56_4b76b0
  ecx = edx = 0;  // @57_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_4b76b0
  ecx = edi;  // @59_4b76b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 160), sizeof v); (u32)v; });  // @60_4b76b0
  PV[10] = (u32)(eax);  // @61_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[10]);  // @62_4b76b0
  ecx = edx = 0;  // @63_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @64_4b76b0
  ecx = edi;  // @65_4b76b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @66_4b76b0
  PV[11] = (u32)(eax);  // @67_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[11]);  // @68_4b76b0
  ecx = edx = 0;  // @69_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @70_4b76b0
  ecx = edi;  // @71_4b76b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 153), sizeof v); (u32)v; });  // @72_4b76b0
  PV[12] = (u32)(eax);  // @73_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[12]);  // @74_4b76b0
  ecx = edx = 0;  // @75_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @76_4b76b0
  ecx = edi;  // @77_4b76b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 154), sizeof v); (u32)v; });  // @78_4b76b0
  PV[13] = (u32)(eax);  // @79_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[13]);  // @80_4b76b0
  ecx = edx = 0;  // @81_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @82_4b76b0
  ecx = edi;  // @83_4b76b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 155), sizeof v); (u32)v; });  // @84_4b76b0
  PV[14] = (u32)(eax);  // @85_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[14]);  // @86_4b76b0
  ecx = edx = 0;  // @87_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 218), sizeof v); (u32)v; });  // @88_4b76b0
  PV[15] = (u32)(ecx);  // @89_4b76b0
  ecx = 0;  // @90_4b76b0
  PV[16] = eax;  // @91_4b76b0
  ecx = edi;  // @92_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @93_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[16]);  // @94_4b76b0
  ecx = edx = 0;  // @95_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @96_4b76b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 222) + 0), 4); v; });  // @97_4b76b0
  X0[1] = 0;  // @98_4b76b0
  X0[2] = 0;  // @99_4b76b0
  X0[3] = 0;  // @100_4b76b0
  PV[17] = (u32)(ecx);  // @101_4b76b0
  ecx = edi;  // @102_4b76b0
  PV[18] = X0[0];  // @103_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[18]);  // @104_4b76b0
  ecx = edx = 0;  // @105_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @106_4b76b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 226) + 0), 4); v; });  // @107_4b76b0
  X0[1] = 0;  // @108_4b76b0
  X0[2] = 0;  // @109_4b76b0
  X0[3] = 0;  // @110_4b76b0
  PV[19] = (u32)(ecx);  // @111_4b76b0
  ecx = edi;  // @112_4b76b0
  PV[20] = X0[0];  // @113_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[20]);  // @114_4b76b0
  ecx = edx = 0;  // @115_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @116_4b76b0
  ecx = edi;  // @117_4b76b0
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 238), sizeof v); (u32)v; });  // @118_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[21]);  // @119_4b76b0
  ecx = edx = 0;  // @120_4b76b0
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 238), sizeof v); (u32)v; });  // @121_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @122_4b76b0
  ecx = edi;  // @123_4b76b0
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 144), sizeof v); (u32)v; });  // @124_4b76b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[23], PV[22]);  // @125_4b76b0
  ecx = edx = 0;  // @126_4b76b0
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 238), sizeof v); (u32)v; });  // @127_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @128_4b76b0
  ecx = edi;  // @129_4b76b0
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 148), sizeof v); (u32)v; });  // @130_4b76b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[25], PV[24]);  // @131_4b76b0
  ecx = edx = 0;  // @132_4b76b0
  ebx = 0;  // @133_4b76b0
  FL[3] = ebx;  // @134_4b76b0
  esi = (esi + (u32)(170));  // @135_4b76b0
  FL[3] = esi;  // @136_4b76b0
  if (FL[3] == 0) goto L4b7840;  // @137_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_4b76b0
  ecx = (u32)(EBP - 16);  // @139_4b76b0
  PV[26] = (u32)(ecx);  // @140_4b76b0
  ecx = esi;  // @141_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[26]);  // @142_4b76b0
  ecx = edx = 0;  // @143_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_4b76b0
  ecx = (u32)(EBP - 16);  // @145_4b76b0
  PV[27] = (u32)(ecx);  // @146_4b76b0
  ecx = esi;  // @147_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[27]);  // @148_4b76b0
  ecx = edx = 0;  // @149_4b76b0
  FL[2] = (eax & eax);  // @150_4b76b0
  if (FL[2] == 0) goto L4b7840;  // @151_4b76b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @152_4b76b0
  L4b7825:;
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 214), sizeof v); (u32)v; });  // @154_4b76b0
  if (FL[0] == FL[1]) goto L4b783d;  // @155_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_4b76b0
  ecx = (u32)(EBP - 16);  // @157_4b76b0
  PV[28] = (u32)(ecx);  // @158_4b76b0
  ecx = esi;  // @159_4b76b0
  ebx = (ebx + 1);  // @160_4b76b0
  FL[3] = ebx;  // @161_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[28]);  // @162_4b76b0
  ecx = edx = 0;  // @163_4b76b0
  FL[2] = (eax & eax);  // @164_4b76b0
  if (FL[2] != 0) goto L4b7825;  // @165_4b76b0
  L4b783d:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @167_4b76b0
  L4b7840:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @169_4b76b0
  ecx = edi;  // @170_4b76b0
  PV[29] = (u32)(ebx);  // @171_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[29]);  // @172_4b76b0
  ecx = edx = 0;  // @173_4b76b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @174_4b76b0
  ecx = edi;  // @175_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @176_4b76b0
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 230), sizeof v); (u32)v; });  // @177_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[30]);  // @178_4b76b0
  ecx = edx = 0;  // @179_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @180_4b76b0
  eax = (u32)(ebx + 242);  // @181_4b76b0
  PV[31] = (u32)(eax);  // @182_4b76b0
  ecx = edi;  // @183_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[31]);  // @184_4b76b0
  ecx = edx = 0;  // @185_4b76b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @186_4b76b0
  eax = (u32)(ebx + 270);  // @187_4b76b0
  PV[32] = (u32)(eax);  // @188_4b76b0
  ecx = edi;  // @189_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[32]);  // @190_4b76b0
  ecx = edx = 0;  // @191_4b76b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @192_4b76b0
  ecx = edi;  // @193_4b76b0
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; });  // @194_4b76b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[33]);  // @195_4b76b0
  ecx = edx = 0;  // @196_4b76b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @197_4b76b0
  return eax;  // @198_4b76b0
}
PCREG(4b76b0, lifted_4b76b0);

extern "C" u32 THISCALL lifted_53f3b0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_53f3b0
  eax = (u32)(EBP - 16);  // @1_53f3b0
  PV[0] = (u32)(eax);  // @2_53f3b0
  eax = (u32)(EBP - 152);  // @3_53f3b0
  edi = ecx;  // @4_53f3b0
  PV[1] = (u32)(eax);  // @5_53f3b0
  eax = (u32)(EBP - 28);  // @6_53f3b0
  PV[2] = (u32)(eax);  // @7_53f3b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @8_53f3b0
  eax = (u32)(EBP - 112);  // @9_53f3b0
  PV[3] = (u32)(eax);  // @10_53f3b0
  eax = ext_545cb0_thiscall6(ecx, (u32)(1), PV[3], PV[2], PV[1], PV[0]);  // @11_53f3b0
  ecx = edx = 0;  // @12_53f3b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @13_53f3b0
  eax = (u32)(EBP - 40);  // @14_53f3b0
  PV[4] = (u32)(eax);  // @15_53f3b0
  eax = (u32)(EBP - 156);  // @16_53f3b0
  PV[5] = (u32)(eax);  // @17_53f3b0
  eax = (u32)(EBP - 52);  // @18_53f3b0
  PV[6] = (u32)(eax);  // @19_53f3b0
  eax = (u32)(EBP - 124);  // @20_53f3b0
  PV[7] = (u32)(eax);  // @21_53f3b0
  eax = ext_545cb0_thiscall6(ecx, (u32)(2), PV[7], PV[6], PV[5], PV[4]);  // @22_53f3b0
  ecx = edx = 0;  // @23_53f3b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @24_53f3b0
  eax = (u32)(EBP - 64);  // @25_53f3b0
  PV[8] = (u32)(eax);  // @26_53f3b0
  eax = (u32)(EBP - 160);  // @27_53f3b0
  PV[9] = (u32)(eax);  // @28_53f3b0
  eax = (u32)(EBP - 76);  // @29_53f3b0
  PV[10] = (u32)(eax);  // @30_53f3b0
  eax = (u32)(EBP - 136);  // @31_53f3b0
  PV[11] = (u32)(eax);  // @32_53f3b0
  eax = ext_545cb0_thiscall6(ecx, (u32)(3), PV[11], PV[10], PV[9], PV[8]);  // @33_53f3b0
  ecx = edx = 0;  // @34_53f3b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @35_53f3b0
  eax = (u32)(EBP - 88);  // @36_53f3b0
  PV[12] = (u32)(eax);  // @37_53f3b0
  eax = (u32)(EBP - 164);  // @38_53f3b0
  PV[13] = (u32)(eax);  // @39_53f3b0
  eax = (u32)(EBP - 100);  // @40_53f3b0
  PV[14] = (u32)(eax);  // @41_53f3b0
  eax = (u32)(EBP - 148);  // @42_53f3b0
  PV[15] = (u32)(eax);  // @43_53f3b0
  eax = ext_545cb0_thiscall6(ecx, (u32)(4), PV[15], PV[14], PV[13], PV[12]);  // @44_53f3b0
  ecx = edx = 0;  // @45_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @46_53f3b0
  X0[1] = 0;  // @47_53f3b0
  X0[2] = 0;  // @48_53f3b0
  X0[3] = 0;  // @49_53f3b0
  edx = esi;  // @50_53f3b0
  PV[16] = (u32)(ecx);  // @51_53f3b0
  ecx = (u32)(EBP - 28);  // @52_53f3b0
  PV[17] = X0[0];  // @53_53f3b0
  eax = ext_451890_fastcall3(ecx, edx, PV[17]);  // @54_53f3b0
  ecx = 0;  // @55_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @56_53f3b0
  X0[1] = 0;  // @57_53f3b0
  X0[2] = 0;  // @58_53f3b0
  X0[3] = 0;  // @59_53f3b0
  edx = esi;  // @60_53f3b0
  PV[18] = (u32)(ecx);  // @61_53f3b0
  ecx = (u32)(EBP - 52);  // @62_53f3b0
  PV[19] = X0[0];  // @63_53f3b0
  eax = ext_451890_fastcall3(ecx, edx, PV[19]);  // @64_53f3b0
  ecx = 0;  // @65_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @66_53f3b0
  X0[1] = 0;  // @67_53f3b0
  X0[2] = 0;  // @68_53f3b0
  X0[3] = 0;  // @69_53f3b0
  edx = esi;  // @70_53f3b0
  PV[20] = (u32)(ecx);  // @71_53f3b0
  ecx = (u32)(EBP - 76);  // @72_53f3b0
  PV[21] = X0[0];  // @73_53f3b0
  eax = ext_451890_fastcall3(ecx, edx, PV[21]);  // @74_53f3b0
  ecx = 0;  // @75_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 24) + 0), 4); v; });  // @76_53f3b0
  X0[1] = 0;  // @77_53f3b0
  X0[2] = 0;  // @78_53f3b0
  X0[3] = 0;  // @79_53f3b0
  edx = esi;  // @80_53f3b0
  PV[22] = (u32)(ecx);  // @81_53f3b0
  ecx = (u32)(EBP - 100);  // @82_53f3b0
  PV[23] = X0[0];  // @83_53f3b0
  eax = ext_451890_fastcall3(ecx, edx, PV[23]);  // @84_53f3b0
  ecx = 0;  // @85_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @86_53f3b0
  X0[1] = 0;  // @87_53f3b0
  X0[2] = 0;  // @88_53f3b0
  X0[3] = 0;  // @89_53f3b0
  edx = esi;  // @90_53f3b0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @91_53f3b0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @92_53f3b0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @93_53f3b0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @94_53f3b0
  PV[24] = (u32)(ecx);  // @95_53f3b0
  ecx = (u32)(EBP - 16);  // @96_53f3b0
  PV[25] = X0[0];  // @97_53f3b0
  eax = ext_451890_fastcall3(ecx, edx, PV[25]);  // @98_53f3b0
  ecx = 0;  // @99_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @100_53f3b0
  X0[1] = 0;  // @101_53f3b0
  X0[2] = 0;  // @102_53f3b0
  X0[3] = 0;  // @103_53f3b0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @104_53f3b0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @105_53f3b0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @106_53f3b0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @107_53f3b0
  PV[26] = (u32)(ecx);  // @108_53f3b0
  edx = esi;  // @109_53f3b0
  PV[27] = X0[0];  // @110_53f3b0
  ecx = (u32)(EBP - 40);  // @111_53f3b0
  eax = ext_451890_fastcall3(ecx, edx, PV[27]);  // @112_53f3b0
  ecx = 0;  // @113_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @114_53f3b0
  X0[1] = 0;  // @115_53f3b0
  X0[2] = 0;  // @116_53f3b0
  X0[3] = 0;  // @117_53f3b0
  edx = esi;  // @118_53f3b0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @119_53f3b0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @120_53f3b0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @121_53f3b0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @122_53f3b0
  PV[28] = (u32)(ecx);  // @123_53f3b0
  ecx = (u32)(EBP - 64);  // @124_53f3b0
  PV[29] = X0[0];  // @125_53f3b0
  eax = ext_451890_fastcall3(ecx, edx, PV[29]);  // @126_53f3b0
  ecx = 0;  // @127_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 24) + 0), 4); v; });  // @128_53f3b0
  X0[1] = 0;  // @129_53f3b0
  X0[2] = 0;  // @130_53f3b0
  X0[3] = 0;  // @131_53f3b0
  edx = esi;  // @132_53f3b0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @133_53f3b0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @134_53f3b0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @135_53f3b0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @136_53f3b0
  PV[30] = (u32)(ecx);  // @137_53f3b0
  ecx = (u32)(EBP - 88);  // @138_53f3b0
  PV[31] = X0[0];  // @139_53f3b0
  eax = ext_451890_fastcall3(ecx, edx, PV[31]);  // @140_53f3b0
  ecx = 0;  // @141_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; });  // @142_53f3b0
  X0[1] = 0;  // @143_53f3b0
  X0[2] = 0;  // @144_53f3b0
  X0[3] = 0;  // @145_53f3b0
  eax = (u32)(EBP - 16);  // @146_53f3b0
  PV[32] = (u32)(eax);  // @147_53f3b0
  PV[33] = (u32)(ecx);  // @148_53f3b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @149_53f3b0
  eax = (u32)(EBP - 28);  // @150_53f3b0
  PV[34] = X0[0];  // @151_53f3b0
  PV[35] = (u32)(eax);  // @152_53f3b0
  eax = (u32)(EBP - 112);  // @153_53f3b0
  PV[36] = (u32)(eax);  // @154_53f3b0
  eax = ext_5477a0_thiscall6(ecx, (u32)(1), PV[36], PV[35], PV[34], PV[32]);  // @155_53f3b0
  ecx = edx = 0;  // @156_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 156) + 0), 4); v; });  // @157_53f3b0
  X0[1] = 0;  // @158_53f3b0
  X0[2] = 0;  // @159_53f3b0
  X0[3] = 0;  // @160_53f3b0
  eax = (u32)(EBP - 40);  // @161_53f3b0
  PV[37] = (u32)(eax);  // @162_53f3b0
  PV[38] = (u32)(ecx);  // @163_53f3b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @164_53f3b0
  eax = (u32)(EBP - 52);  // @165_53f3b0
  PV[39] = X0[0];  // @166_53f3b0
  PV[40] = (u32)(eax);  // @167_53f3b0
  eax = (u32)(EBP - 124);  // @168_53f3b0
  PV[41] = (u32)(eax);  // @169_53f3b0
  eax = ext_5477a0_thiscall6(ecx, (u32)(2), PV[41], PV[40], PV[39], PV[37]);  // @170_53f3b0
  ecx = edx = 0;  // @171_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; });  // @172_53f3b0
  X0[1] = 0;  // @173_53f3b0
  X0[2] = 0;  // @174_53f3b0
  X0[3] = 0;  // @175_53f3b0
  eax = (u32)(EBP - 64);  // @176_53f3b0
  PV[42] = (u32)(eax);  // @177_53f3b0
  PV[43] = (u32)(ecx);  // @178_53f3b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @179_53f3b0
  eax = (u32)(EBP - 76);  // @180_53f3b0
  PV[44] = X0[0];  // @181_53f3b0
  PV[45] = (u32)(eax);  // @182_53f3b0
  eax = (u32)(EBP - 136);  // @183_53f3b0
  PV[46] = (u32)(eax);  // @184_53f3b0
  eax = ext_5477a0_thiscall6(ecx, (u32)(3), PV[46], PV[45], PV[44], PV[42]);  // @185_53f3b0
  ecx = edx = 0;  // @186_53f3b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @187_53f3b0
  X0[1] = 0;  // @188_53f3b0
  X0[2] = 0;  // @189_53f3b0
  X0[3] = 0;  // @190_53f3b0
  eax = (u32)(EBP - 88);  // @191_53f3b0
  PV[47] = (u32)(eax);  // @192_53f3b0
  PV[48] = (u32)(ecx);  // @193_53f3b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @194_53f3b0
  eax = (u32)(EBP - 100);  // @195_53f3b0
  PV[49] = X0[0];  // @196_53f3b0
  PV[50] = (u32)(eax);  // @197_53f3b0
  eax = (u32)(EBP - 148);  // @198_53f3b0
  PV[51] = (u32)(eax);  // @199_53f3b0
  eax = ext_5477a0_thiscall6(ecx, (u32)(4), PV[51], PV[50], PV[49], PV[47]);  // @200_53f3b0
  ecx = edx = 0;  // @201_53f3b0
  ext_633654(G(u32, 0x6f5630));  // @202_53f3b0
  return eax;  // @203_53f3b0
}
PCREG(53f3b0, lifted_53f3b0);

extern "C" u32 THISCALL lifted_5407c0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5407c0
  eax = (u32)(EBP - 40);  // @1_5407c0
  PV[0] = (u32)(eax);  // @2_5407c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @3_5407c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @4_5407c0
  eax = ext_545c80_thiscall3(ecx, (u32)(1), PV[0]);  // @5_5407c0
  ecx = edx = 0;  // @6_5407c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @7_5407c0
  eax = (u32)(EBP - 28);  // @8_5407c0
  PV[1] = (u32)(eax);  // @9_5407c0
  eax = ext_545c80_thiscall3(ecx, (u32)(2), PV[1]);  // @10_5407c0
  ecx = edx = 0;  // @11_5407c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @12_5407c0
  eax = (u32)(EBP - 52);  // @13_5407c0
  PV[2] = (u32)(eax);  // @14_5407c0
  eax = ext_545c80_thiscall3(ecx, (u32)(3), PV[2]);  // @15_5407c0
  ecx = edx = 0;  // @16_5407c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @17_5407c0
  eax = (u32)(EBP - 64);  // @18_5407c0
  PV[3] = (u32)(eax);  // @19_5407c0
  eax = ext_545c80_thiscall3(ecx, (u32)(4), PV[3]);  // @20_5407c0
  ecx = edx = 0;  // @21_5407c0
  eax = (u32)(EBP - 28);  // @22_5407c0
  ebx = (u32)(esi + 235);  // @23_5407c0
  PV[4] = (u32)(eax);  // @24_5407c0
  edx = (u32)(EBP - 40);  // @25_5407c0
  ecx = ebx;  // @26_5407c0
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @27_5407c0
  ecx = edx = 0;  // @28_5407c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @29_5407c0
  X0[1] = 0;  // @30_5407c0
  X0[2] = 0;  // @31_5407c0
  X0[3] = 0;  // @32_5407c0
  X1[0] = 0;  // @33_5407c0
  X1[1] = 0;  // @34_5407c0
  X1[2] = 0;  // @35_5407c0
  X1[3] = 0;  // @36_5407c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @37_5407c0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @38_5407c0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @39_5407c0
  if (!__builtin_parity(FL[2] & 0xff)) goto L54085f;  // @40_5407c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @41_5407c0
  X0[1] = 0;  // @42_5407c0
  X0[2] = 0;  // @43_5407c0
  X0[3] = 0;  // @44_5407c0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @45_5407c0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @46_5407c0
  if (!__builtin_parity(FL[2] & 0xff)) goto L54085f;  // @47_5407c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @48_5407c0
  X0[1] = 0;  // @49_5407c0
  X0[2] = 0;  // @50_5407c0
  X0[3] = 0;  // @51_5407c0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @52_5407c0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @53_5407c0
  if (__builtin_parity(FL[2] & 0xff)) goto L54089b;  // @54_5407c0
  L54085f:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @56_5407c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @57_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @58_5407c0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @59_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @60_5407c0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @61_5407c0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @62_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @63_5407c0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @64_5407c0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @65_5407c0
  __asm__ volatile("fsqrt" ::: "st");  // @66_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 68)) : "st");  // @67_5407c0
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @68_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @69_5407c0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @70_5407c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @71_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @72_5407c0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @73_5407c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @74_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @75_5407c0
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @76_5407c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @77_5407c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 68)) :: "st");  // @78_5407c0
  L54089b:;
  eax = (u32)(EBP - 28);  // @80_5407c0
  PV[5] = (u32)(eax);  // @81_5407c0
  edx = (u32)(EBP - 40);  // @82_5407c0
  ecx = (u32)(EBP - 16);  // @83_5407c0
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[5]);  // @84_5407c0
  ecx = edx = 0;  // @85_5407c0
  PV[6] = (u32)(ecx);  // @86_5407c0
  ecx = (u32)(EBP - 16);  // @87_5407c0
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @88_5407c0
    // @89_5407c0
  edx = (u32)(EBP - 52);  // @90_5407c0
  ecx = (u32)(EBP - 16);  // @91_5407c0
  eax = ext_43e960_fastcall2(ecx, edx);  // @92_5407c0
  ecx = edx = 0;  // @93_5407c0
  eax = (u32)(EBP - 16);  // @94_5407c0
  edx = ebx;  // @95_5407c0
  edi = (u32)(esi + 223);  // @96_5407c0
  PV[7] = (u32)(eax);  // @97_5407c0
  ecx = edi;  // @98_5407c0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[7]);  // @99_5407c0
  ecx = edx = 0;  // @100_5407c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @101_5407c0
  X0[1] = 0;  // @102_5407c0
  X0[2] = 0;  // @103_5407c0
  X0[3] = 0;  // @104_5407c0
  X1[0] = 0;  // @105_5407c0
  X1[1] = 0;  // @106_5407c0
  X1[2] = 0;  // @107_5407c0
  X1[3] = 0;  // @108_5407c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @109_5407c0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @110_5407c0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @111_5407c0
  if (!__builtin_parity(FL[2] & 0xff)) goto L540907;  // @112_5407c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @113_5407c0
  X0[1] = 0;  // @114_5407c0
  X0[2] = 0;  // @115_5407c0
  X0[3] = 0;  // @116_5407c0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @117_5407c0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @118_5407c0
  if (!__builtin_parity(FL[2] & 0xff)) goto L540907;  // @119_5407c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @120_5407c0
  X0[1] = 0;  // @121_5407c0
  X0[2] = 0;  // @122_5407c0
  X0[3] = 0;  // @123_5407c0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @124_5407c0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @125_5407c0
  if (__builtin_parity(FL[2] & 0xff)) goto L540943;  // @126_5407c0
  L540907:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @128_5407c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @129_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @130_5407c0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @131_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @132_5407c0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @133_5407c0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @134_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @135_5407c0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @136_5407c0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @137_5407c0
  __asm__ volatile("fsqrt" ::: "st");  // @138_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 68)) : "st");  // @139_5407c0
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @140_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @141_5407c0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @142_5407c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @143_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @144_5407c0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @145_5407c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @146_5407c0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @147_5407c0
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @148_5407c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @149_5407c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 68)) :: "st");  // @150_5407c0
  L540943:;
  esi = (esi + (u32)(211));  // @152_5407c0
  FL[3] = esi;  // @153_5407c0
  edx = ebx;  // @154_5407c0
  PV[8] = (u32)(edi);  // @155_5407c0
  ecx = esi;  // @156_5407c0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[8]);  // @157_5407c0
  ecx = edx = 0;  // @158_5407c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @159_5407c0
  eax = (u32)(EBP - 28);  // @160_5407c0
  PV[9] = (u32)(eax);  // @161_5407c0
  edx = (u32)(EBP - 40);  // @162_5407c0
  ecx = (u32)(ebx + 259);  // @163_5407c0
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[9]);  // @164_5407c0
  ecx = edx = 0;  // @165_5407c0
  edx = (u32)(EBP - 52);  // @166_5407c0
  ecx = (u32)(ebx + 259);  // @167_5407c0
  eax = ext_441940_fastcall2(ecx, edx);  // @168_5407c0
  ecx = edx = 0;  // @169_5407c0
  edx = (u32)(EBP - 64);  // @170_5407c0
  ecx = (u32)(ebx + 259);  // @171_5407c0
  eax = ext_441940_fastcall2(ecx, edx);  // @172_5407c0
  ecx = edx = 0;  // @173_5407c0
  PV[10] = (u32)(ecx);  // @174_5407c0
  ecx = (u32)(ebx + 259);  // @175_5407c0
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1048576000));  // @176_5407c0
    // @177_5407c0
  PV[11] = (u32)(esi);  // @178_5407c0
  edx = (u32)(ebx + 285);  // @179_5407c0
  ecx = (u32)(EBP - 88);  // @180_5407c0
  eax = ext_441970_fastcall3(ecx, edx, PV[11]);  // @181_5407c0
  ecx = edx = 0;  // @182_5407c0
  edx = (u32)(EBP - 88);  // @183_5407c0
  ecx = (u32)(ebx + 259);  // @184_5407c0
  eax = ext_43e960_fastcall2(ecx, edx);  // @185_5407c0
  ecx = edx = 0;  // @186_5407c0
  ext_633654(G(u32, 0x6f5630));  // @187_5407c0
  return eax;  // @188_5407c0
}
PCREG(5407c0, lifted_5407c0);

extern "C" u32 lifted_4c7330(void) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4c7330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @1_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(0));  // @3_4c7330
  ecx = edx = 0;  // @4_4c7330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_4c7330
  esi = eax;  // @6_4c7330
  PV[0] = (u32)(esi);  // @7_4c7330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @8_4c7330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[0]);  // @10_4c7330
  ecx = edx = 0;  // @11_4c7330
  FL[2] = (esi & esi);  // @12_4c7330
  if (FL[2] == 0) goto L4c757f;  // @13_4c7330
  FL[2] = (eax & eax);  // @14_4c7330
  if (FL[2] == 0) goto L4c757f;  // @15_4c7330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_4c7330
  PV[1] = (u32)(ecx);  // @17_4c7330
  ecx = (u32)((EBP - 100) + 68);  // @18_4c7330
  PV[2] = (u32)(ecx);  // @19_4c7330
  ecx = eax;  // @20_4c7330
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 652)))(ecx, PV[2], (u32)(1), (u32)(7), (u32)(0));  // @21_4c7330
  ecx = edx = 0;  // @22_4c7330
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 76), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_4c7330
  if (FL[0] == FL[1]) goto L4c757f;  // @24_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_4c7330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 64) + 0), 4); v; });  // @26_4c7330
  X0[1] = 0;  // @27_4c7330
  X0[2] = 0;  // @28_4c7330
  X0[3] = 0;  // @29_4c7330
  __builtin_memcpy((void *)((u32)((EBP - 96) + 12) + 0), &X0[0], 4);  // @30_4c7330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 68) + 0), 4); v; });  // @31_4c7330
  X0[1] = 0;  // @32_4c7330
  X0[2] = 0;  // @33_4c7330
  X0[3] = 0;  // @34_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_4c7330
  __builtin_memcpy((void *)((u32)((EBP - 96) + 20) + 0), &X0[0], 4);  // @36_4c7330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 72) + 0), 4); v; });  // @37_4c7330
  X0[1] = 0;  // @38_4c7330
  X0[2] = 0;  // @39_4c7330
  X0[3] = 0;  // @40_4c7330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @41_4c7330
  __builtin_memcpy((void *)((u32)((EBP - 104) + 24) + 0), &X0[0], 4);  // @42_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_4c7330
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @44_4c7330
  ecx = edx = 0;  // @45_4c7330
  ebx = eax;  // @46_4c7330
  FL[2] = (ebx & ebx);  // @47_4c7330
  if (FL[2] == 0) goto L4c757f;  // @48_4c7330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @49_4c7330
  FL[2] = (ecx & ecx);  // @50_4c7330
  if (FL[2] == 0) goto L4c757f;  // @51_4c7330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4c7330
  eax = (u32)((EBP - 96) + 28);  // @53_4c7330
  PV[3] = (u32)(eax);  // @54_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[3]);  // @55_4c7330
  ecx = edx = 0;  // @56_4c7330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @57_4c7330
  edx = (u32)((EBP - 96) + 28);  // @58_4c7330
  PV[4] = (u32)(edx);  // @59_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @61_4c7330
  ecx = edx = 0;  // @62_4c7330
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @63_4c7330
  edx = eax;  // @64_4c7330
  if (FL[0] == FL[1]) goto L4c757f;  // @65_4c7330
  L4c7423:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @67_4c7330
  PV[5] = (u32)(edx);  // @68_4c7330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @69_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[5]);  // @71_4c7330
  ecx = edx = 0;  // @72_4c7330
  edi = eax;  // @73_4c7330
  ecx = edi;  // @74_4c7330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_4c7330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @76_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2099152));  // @77_4c7330
  ecx = edx = 0;  // @78_4c7330
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @79_4c7330
  if (FL[2] == 0) goto L4c7565;  // @80_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @81_4c7330
  ecx = edi;  // @82_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @83_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2149580820));  // @84_4c7330
  ecx = edx = 0;  // @85_4c7330
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @86_4c7330
  if (FL[2] != 0) goto L4c7565;  // @87_4c7330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 12) + 0), 4); v; });  // @88_4c7330
  X0[1] = 0;  // @89_4c7330
  X0[2] = 0;  // @90_4c7330
  X0[3] = 0;  // @91_4c7330
  ecx = (u32)((EBP - 96) + 80);  // @92_4c7330
  __builtin_memcpy((void *)((u32)((EBP - 96) + 40) + 0), &X0[0], 4);  // @93_4c7330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 16) + 0), 4); v; });  // @94_4c7330
  X0[1] = 0;  // @95_4c7330
  X0[2] = 0;  // @96_4c7330
  X0[3] = 0;  // @97_4c7330
  __builtin_memcpy((void *)((u32)((EBP - 96) + 48) + 0), &X0[0], 4);  // @98_4c7330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 20) + 0), 4); v; });  // @99_4c7330
  X0[1] = 0;  // @100_4c7330
  X0[2] = 0;  // @101_4c7330
  X0[3] = 0;  // @102_4c7330
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; })));  // @103_4c7330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 96) + 80), &v, sizeof v); }  // @104_4c7330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 96) + 84), &v, sizeof v); }  // @105_4c7330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 96) + 88), &v, sizeof v); }  // @106_4c7330
  PV[6] = (u32)(ecx);  // @107_4c7330
  __builtin_memcpy((void *)((u32)((EBP - 100) + 48) + 0), &X0[0], 4);  // @108_4c7330
  ecx = edi;  // @109_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @110_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[6]);  // @111_4c7330
  ecx = edx = 0;  // @112_4c7330
  eax = (u32)((EBP - 96) + 40);  // @113_4c7330
  PV[7] = (u32)(eax);  // @114_4c7330
  edx = (u32)((EBP - 100) + 84);  // @115_4c7330
  ecx = (u32)((EBP - 100) + 56);  // @116_4c7330
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @117_4c7330
  ecx = edx = 0;  // @118_4c7330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 52) + 0), 4); v; });  // @119_4c7330
  X1[1] = 0;  // @120_4c7330
  X1[2] = 0;  // @121_4c7330
  X1[3] = 0;  // @122_4c7330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 56) + 0), 4); v; });  // @123_4c7330
  X0[1] = 0;  // @124_4c7330
  X0[2] = 0;  // @125_4c7330
  X0[3] = 0;  // @126_4c7330
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @127_4c7330
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @128_4c7330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @129_4c7330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 60) + 0), 4); v; });  // @130_4c7330
  X0[1] = 0;  // @131_4c7330
  X0[2] = 0;  // @132_4c7330
  X0[3] = 0;  // @133_4c7330
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @134_4c7330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @135_4c7330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @136_4c7330
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @137_4c7330
  ecx = edx = 0;  // @138_4c7330
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @139_4c7330
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6901008) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6901008) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6901008) + 0), 4); v; }))))))) goto L4c7565;  // @140_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @141_4c7330
  ecx = edi;  // @142_4c7330
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1416)))(ecx);  // @143_4c7330
  ecx = edx = 0;  // @144_4c7330
  FL[2] = (eax & eax);  // @145_4c7330
  if (FL[2] == 0) goto L4c7557;  // @146_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @147_4c7330
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @148_4c7330
  { u32 v = (u32)((u32)(6889772)); __builtin_memcpy((void *)(u32)((EBP - 96) + 24), &v, sizeof v); }  // @149_4c7330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @150_4c7330
  eax = (u32)((EBP - 96) + 24);  // @151_4c7330
  PV[8] = (u32)(eax);  // @152_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_4c7330
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6900844), (u32)(0), (u32)(6900440), (u32)(769), PV[8]);  // @154_4c7330
  ecx = edx = 0;  // @155_4c7330
  eax = (eax & 0xffff);  // @156_4c7330
  ecx = edi;  // @157_4c7330
  PV[9] = (u32)(eax);  // @158_4c7330
  PV[10] = (u32)(edi);  // @159_4c7330
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, PV[10], PV[9]);  // @160_4c7330
  ecx = edx = 0;  // @161_4c7330
  L4c7557:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @163_4c7330
  FL[2] = (eax & eax);  // @164_4c7330
  if (FL[2] == 0) goto L4c7564;  // @165_4c7330
  eax = ((u32(STDCALL *)(void))(eax))();  // @166_4c7330
  ecx = edx = 0;  // @167_4c7330
  goto L4c7565;  // @168_4c7330
  L4c7564:;
  __builtin_trap();  // @170_4c7330
  L4c7565:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @172_4c7330
  edx = (u32)((EBP - 96) + 28);  // @173_4c7330
  PV[11] = (u32)(edx);  // @174_4c7330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_4c7330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[11]);  // @176_4c7330
  ecx = edx = 0;  // @177_4c7330
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @178_4c7330
  edx = eax;  // @179_4c7330
  if (FL[0] != FL[1]) goto L4c7423;  // @180_4c7330
  L4c757f:;
  ext_633654(G(u32, 0x6f5630));  // @182_4c7330
  return eax;  // @183_4c7330
}
PCREG(4c7330, lifted_4c7330);

