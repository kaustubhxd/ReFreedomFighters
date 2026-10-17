// batch234007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_573af0_stdcall1(u32) __asm__("ext_573af0");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_561720_thiscall3(u32, u32, u32) __asm__("ext_561720");
extern "C" u32 THISCALL ext_5743c0_thiscall3(u32, u32, u32) __asm__("ext_5743c0");
extern "C" u32 THISCALL ext_574bc0_thiscall1(u32) __asm__("ext_574bc0");
extern "C" u32 THISCALL ext_576e50_thiscall1(u32) __asm__("ext_576e50");
extern "C" u32 THISCALL ext_5b1000_thiscall2(u32, u32) __asm__("ext_5b1000");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_576670(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_576670
  ebx = ecx;  // @1_576670
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_576670
  eax = ext_5743c0_thiscall3(ecx, PV[1], PV[0]);  // @3_576670
  ecx = edx = 0;  // @4_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_576670
  ecx = ebx;  // @6_576670
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 476), sizeof v); (u32)v; });  // @7_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; });  // @8_576670
  eax = (eax - (u32)(40));  // @9_576670
  FL[3] = eax;  // @10_576670
  { u32 v = (u32)((u32)(1114636288)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @11_576670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @12_576670
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @13_576670
  X0[0] = F2U((float)(s32)X0[0]);  // @14_576670
  X0[1] = F2U((float)(s32)X0[1]);  // @15_576670
  X0[2] = F2U((float)(s32)X0[2]);  // @16_576670
  X0[3] = F2U((float)(s32)X0[3]);  // @17_576670
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @18_576670
  eax = ext_561720_thiscall3(ecx, PV[2], (u32)(0));  // @19_576670
  ecx = edx = 0;  // @20_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 476), sizeof v); (u32)v; });  // @21_576670
  edx = (u32)(EBP - 80);  // @22_576670
  PV[3] = (u32)(edx);  // @23_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[3]);  // @25_576670
  ecx = edx = 0;  // @26_576670
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 545), sizeof v); (u32)v; });  // @27_576670
  ecx = ebx;  // @28_576670
  eax = ext_561720_thiscall3(ecx, PV[4], (u32)(0));  // @29_576670
  ecx = edx = 0;  // @30_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 545), sizeof v); (u32)v; });  // @31_576670
  edx = (u32)(EBP - 80);  // @32_576670
  PV[5] = (u32)(edx);  // @33_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[5]);  // @35_576670
  ecx = edx = 0;  // @36_576670
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 549), sizeof v); (u32)v; });  // @37_576670
  ecx = ebx;  // @38_576670
  eax = ext_561720_thiscall3(ecx, PV[6], (u32)(0));  // @39_576670
  ecx = edx = 0;  // @40_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 549), sizeof v); (u32)v; });  // @41_576670
  edx = (u32)(EBP - 80);  // @42_576670
  PV[7] = (u32)(edx);  // @43_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[7]);  // @45_576670
  ecx = edx = 0;  // @46_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 476), sizeof v); (u32)v; });  // @47_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @49_576670
  ecx = edx = 0;  // @50_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 549), sizeof v); (u32)v; });  // @51_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @53_576670
  ecx = edx = 0;  // @54_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 545), sizeof v); (u32)v; });  // @55_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @57_576670
  ecx = edx = 0;  // @58_576670
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 523), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @59_576670
  if (FL[0] == FL[1]) goto L57675e;  // @60_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 476), sizeof v); (u32)v; });  // @61_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @63_576670
  ecx = edx = 0;  // @64_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 476), sizeof v); (u32)v; });  // @65_576670
  goto L576791;  // @66_576670
  L57675e:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 524), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @68_576670
  if (FL[0] == FL[1]) goto L57677d;  // @69_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 549), sizeof v); (u32)v; });  // @70_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @72_576670   (w3g hand fix: the `push 0` before the diamond belongs to every arm)
  ecx = edx = 0;  // @73_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 549), sizeof v); (u32)v; });  // @74_576670
  goto L576791;  // @75_576670
  L57677d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 545), sizeof v); (u32)v; });  // @77_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @79_576670   (w3g hand fix: see @72)
  ecx = edx = 0;  // @80_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 545), sizeof v); (u32)v; });  // @81_576670
  L576791:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_576670
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6984440), (u32)(0));  // @84_576670
  ecx = edx = 0;  // @85_576670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @86_576670
  ecx = ebx;  // @87_576670
  esi = eax;  // @88_576670
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 132)))(ecx);  // @89_576670
  ecx = edx = 0;  // @90_576670
  PV[8] = (u32)(esi);  // @91_576670
  ecx = eax;  // @92_576670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @93_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, PV[8]);  // @94_576670
  ecx = edx = 0;  // @95_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 480), sizeof v); (u32)v; });  // @96_576670
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 524), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @97_576670
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @98_576670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_576670
  eax = (eax & 0xff);  // @100_576670
  PV[9] = (u32)(eax);  // @101_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, PV[9]);  // @102_576670
  ecx = edx = 0;  // @103_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 484), sizeof v); (u32)v; });  // @104_576670
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 524), sizeof v); (u32)v; });  // @105_576670
  PV[10] = (u32)(eax);  // @106_576670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, PV[10]);  // @108_576670
  ecx = edx = 0;  // @109_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 392), sizeof v); (u32)v; });  // @110_576670
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 524), sizeof v); (u32)v; });  // @111_576670
  PV[11] = (u32)(eax);  // @112_576670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, PV[11]);  // @114_576670
  ecx = edx = 0;  // @115_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_576670
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @118_576670
  ecx = edx = 0;  // @119_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @120_576670
  esi = eax;  // @121_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @122_576670
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @123_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @124_576670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_576670
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6973416), (u32)(6984772));  // @126_576670
  ecx = edx = 0;  // @127_576670
  PV[12] = (u32)(eax);  // @128_576670
  eax = (u32)(EBP - 68);  // @129_576670
  PV[13] = (u32)(eax);  // @130_576670
  PV[14] = (u32)(esi);  // @131_576670
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)(edi + 408)))(PV[14], PV[13], (u32)(6984780), PV[12]);  // @132_576670   (w3g hand fix: cdecl logger, the caller pops 16 bytes; ECX is not an argument)
  ecx = edx = 0;  // @133_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 392), sizeof v); (u32)v; });  // @134_576670
  edx = (u32)(EBP - 68);  // @135_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_576670
  PV[15] = (u32)(edx);  // @137_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, PV[15]);  // @138_576670
  ecx = edx = 0;  // @139_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 392), sizeof v); (u32)v; });  // @140_576670
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 524), sizeof v); (u32)v; });  // @141_576670
  PV[16] = (u32)(eax);  // @142_576670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, PV[16]);  // @144_576670
  ecx = edx = 0;  // @145_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 553), sizeof v); (u32)v; });  // @146_576670
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 524), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @147_576670
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @148_576670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_576670
  eax = (eax & 0xff);  // @150_576670
  PV[17] = (u32)(eax);  // @151_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, PV[17]);  // @152_576670
  ecx = edx = 0;  // @153_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 553), sizeof v); (u32)v; });  // @154_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_576670
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @156_576670
  ecx = edx = 0;  // @157_576670
  ecx = (u32)(EBP - 80);  // @158_576670
  PV[18] = (u32)(ecx);  // @159_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @160_576670
  eax = ext_4db500_thiscall2(ecx, PV[18]);  // @161_576670
  edx = 0;  // @162_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @163_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 111), sizeof v); (u32)v; });  // @164_576670
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @165_576670
  eax = (eax - edx);  // @166_576670
  FL[3] = eax;  // @167_576670
  eax = (u32)((s32)eax >> (u32)(1));  // @168_576670
  FL[3] = eax;  // @169_576670
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @170_576670
  X0[0] = F2U((float)(s32)X0[0]);  // @171_576670
  X0[1] = F2U((float)(s32)X0[1]);  // @172_576670
  X0[2] = F2U((float)(s32)X0[2]);  // @173_576670
  X0[3] = F2U((float)(s32)X0[3]);  // @174_576670
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; })));  // @175_576670
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @176_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 115), sizeof v); (u32)v; });  // @177_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 553), sizeof v); (u32)v; });  // @178_576670
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @179_576670
  eax = (eax - edx);  // @180_576670
  FL[3] = eax;  // @181_576670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @182_576670
  eax = (u32)((s32)eax >> (u32)(1));  // @183_576670
  FL[3] = eax;  // @184_576670
  edx = (u32)(EBP - 80);  // @185_576670
  PV[19] = (u32)(edx);  // @186_576670
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @187_576670
  X0[0] = F2U((float)(s32)X0[0]);  // @188_576670
  X0[1] = F2U((float)(s32)X0[1]);  // @189_576670
  X0[2] = F2U((float)(s32)X0[2]);  // @190_576670
  X0[3] = F2U((float)(s32)X0[3]);  // @191_576670
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; })));  // @192_576670
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @193_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @194_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[19]);  // @195_576670
  ecx = edx = 0;  // @196_576670
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 440), sizeof v); (u32)v; });  // @197_576670
  ecx = ebx;  // @198_576670
  eax = ext_573af0_stdcall1(PV[20]);  // @199_576670
  ecx = edx = 0;  // @200_576670
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 524), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @201_576670
  if (FL[0] == FL[1]) goto L57691d;  // @202_576670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 248), sizeof v); (u32)v; });  // @203_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @204_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 532)))(ecx, (u32)(2048));  // @205_576670
  ecx = edx = 0;  // @206_576670
  goto L576924;  // @207_576670
  L57691d:;
  ecx = ebx;  // @209_576670
  eax = ext_576e50_thiscall1(ecx);  // @210_576670
  ecx = edx = 0;  // @211_576670
  L576924:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @213_576670
  if (FL[0] == FL[1]) goto L576974;  // @214_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @215_576670
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4158), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @216_576670
  if (FL[0] == FL[1]) goto L576957;  // @217_576670
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 526), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @218_576670
  if (FL[0] == FL[1]) goto L576950;  // @219_576670
  ecx = ebx;  // @220_576670
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 526), &v, sizeof v); }  // @221_576670
  eax = ext_574bc0_thiscall1(ecx);  // @222_576670
  ecx = edx = 0;  // @223_576670
  L576950:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 527), &v, sizeof v); }  // @225_576670
  L576957:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @227_576670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @228_576670
  X0[0] = F2U((float)(s32)X0[0]);  // @229_576670
  X0[1] = F2U((float)(s32)X0[1]);  // @230_576670
  X0[2] = F2U((float)(s32)X0[2]);  // @231_576670
  X0[3] = F2U((float)(s32)X0[3]);  // @232_576670
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @233_576670
  __builtin_memcpy((void *)((u32)(ebx + 529) + 0), &X0[0], 4);  // @234_576670
  L576974:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @236_576670
  eax = (u32)(ebx + 518);  // @237_576670
  PV[21] = (u32)(eax);  // @238_576670
  ecx = (ecx + (u32)(1295));  // @239_576670
  FL[3] = ecx;  // @240_576670
  eax = ext_5b1000_thiscall2(ecx, PV[21]);  // @241_576670
  ecx = edx = 0;  // @242_576670
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @243_576670
  if (FL[2] == 0) goto L576997;  // @244_576670
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 527), &v, sizeof v); }  // @245_576670
  L576997:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 488), sizeof v); (u32)v; });  // @247_576670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @248_576670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @249_576670
  ecx = edx = 0;  // @250_576670
  ext_633654(G(u32, 0x6f5630));  // @251_576670
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @252_576670
  FL[3] = (eax & 0xff);  // @253_576670
  return eax;  // @254_576670
}
PCREG(576670, lifted_576670);

