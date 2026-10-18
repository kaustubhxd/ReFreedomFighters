// batch234009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_573b20_stdcall2(u32, u32) __asm__("ext_573b20");
extern "C" u32 STDCALL ext_573c70_stdcall2(u32, u32) __asm__("ext_573c70");
extern "C" u32 STDCALL ext_574680_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_574680");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_5743c0_thiscall3(u32, u32, u32) __asm__("ext_5743c0");
extern "C" u32 THISCALL ext_578430_thiscall4(u32, u32, u32, u32) __asm__("ext_578430");
extern "C" u32 THISCALL ext_5adee0_thiscall3(u32, u32, u32) __asm__("ext_5adee0");
extern "C" u32 THISCALL ext_5b15d0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5b15d0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_577ee0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_577ee0
  PV[0] = (u32)(ebx);  // @1_577ee0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_577ee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @3_577ee0
  eax = ext_5743c0_thiscall3(ecx, PV[1], PV[0]);  // @4_577ee0
  ecx = edx = 0;  // @5_577ee0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @6_577ee0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @7_577ee0
  if (FL[2] == 0) goto L577f19;  // @8_577ee0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 527), &v, sizeof v); }  // @9_577ee0
  L577f19:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 392), sizeof v); (u32)v; });  // @11_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @13_577ee0
  ecx = edx = 0;  // @14_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 396), sizeof v); (u32)v; });  // @15_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @17_577ee0
  ecx = edx = 0;  // @18_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 488), sizeof v); (u32)v; });  // @19_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @21_577ee0
  ecx = edx = 0;  // @22_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_577ee0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @25_577ee0
  ecx = edx = 0;  // @26_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_577ee0
  edi = eax;  // @28_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @29_577ee0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @31_577ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_577ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6973416), (u32)(6984772));  // @33_577ee0
  ecx = edx = 0;  // @34_577ee0
  PV[2] = (u32)(eax);  // @35_577ee0
  eax = (u32)(EBP - 84);  // @36_577ee0
  PV[3] = (u32)(eax);  // @37_577ee0
  PV[4] = (u32)(edi);  // @38_577ee0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)(esi + 408)))(PV[4], PV[3], (u32)(6985828), PV[2]);  // @39_577ee0   (w3g hand fix: cdecl logger, the caller pops 16 bytes)
  ecx = edx = 0;  // @40_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 392), sizeof v); (u32)v; });  // @41_577ee0
  edx = (u32)(EBP - 84);  // @42_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_577ee0
  PV[5] = (u32)(edx);  // @44_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, PV[5]);  // @45_577ee0
  ecx = edx = 0;  // @46_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @47_577ee0
  eax = (u32)(ebx + 518);  // @48_577ee0
  PV[6] = (u32)(eax);  // @49_577ee0
  eax = (u32)(EBP - 420);  // @50_577ee0
  ecx = (ecx + (u32)(87));  // @51_577ee0
  FL[3] = ecx;  // @52_577ee0
  PV[7] = (u32)(eax);  // @53_577ee0
  eax = ext_5adee0_thiscall3(ecx, PV[7], PV[6]);  // @54_577ee0
  ecx = 0;  // @55_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6985844), sizeof v); (u32)v; });  // @56_577ee0
  edi = (u32)(1);  // @57_577ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6985836) + 0), 4); v; });  // @58_577ee0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6985836) + 4), 4); v; });  // @59_577ee0
  X0[2] = 0;  // @60_577ee0
  X0[3] = 0;  // @61_577ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @62_577ee0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6985848), sizeof v); (u32)v; })) & 0xffff);  // @63_577ee0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @64_577ee0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 520), sizeof v); (u32)v; })) & 0xff);  // @65_577ee0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @66_577ee0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 4), &X0[1], 4);  // @67_577ee0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 18), &v, sizeof v); }  // @68_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 396), sizeof v); (u32)v; });  // @69_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 151), sizeof v); (u32)v; });  // @70_577ee0
  edx = ecx;  // @71_577ee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @72_577ee0
  ecx = (u32)(edx + 1);  // @73_577ee0
  L578001:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @75_577ee0
  edx = (edx + 1);  // @76_577ee0
  FL[3] = edx;  // @77_577ee0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @78_577ee0
  if (FL[2] != 0) goto L578001;  // @79_577ee0
  edx = (edx - ecx);  // @80_577ee0
  FL[3] = edx;  // @81_577ee0
  esi = 0;  // @82_577ee0
  FL[3] = esi;  // @83_577ee0
  FL[2] = (edx & edx);  // @84_577ee0
  if ((s32)FL[2] <= 0) goto L57802e;  // @85_577ee0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @86_577ee0
  L578016:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx), sizeof v); (u32)v; })) & 0xff);  // @88_577ee0
  ecx = (u32)(edi + 1);  // @89_577ee0
  esi = (esi + 1);  // @90_577ee0
  FL[3] = esi;  // @91_577ee0
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @92_577ee0
  if (FL[0] != FL[1]) ecx = edi;  // @93_577ee0
  edi = ecx;  // @94_577ee0
  FL[0] = esi; FL[1] = edx;  // @95_577ee0
  if ((s32)FL[0] < (s32)FL[1]) goto L578016;  // @96_577ee0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @97_577ee0
  L57802e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_577ee0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @101_577ee0
  ecx = edx = 0;  // @102_577ee0
  ecx = eax;  // @103_577ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @104_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 220), sizeof v); (u32)v; });  // @105_577ee0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @106_577ee0
  ecx = edx = 0;  // @107_577ee0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @108_577ee0
  if (FL[2] == 0) goto L57813b;  // @109_577ee0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 464), sizeof v); (u32)v; });  // @110_577ee0
  ecx = ebx;  // @111_577ee0
  eax = ext_573b20_stdcall2(PV[8], (u32)(6983588));  // @112_577ee0
  ecx = edx = 0;  // @113_577ee0
  PV[9] = (u32)(ecx);  // @114_577ee0
  ecx = (u32)(EBP - 120);  // @115_577ee0
  PV[10] = (u32)(ecx);  // @116_577ee0
  PV[11] = (u32)(ecx);  // @117_577ee0
  ecx = ebx;  // @118_577ee0
  PV[12] = (u32)(eax);  // @119_577ee0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 448), sizeof v); (u32)v; });  // @120_577ee0
  eax = ext_574680_stdcall5(PV[13], PV[12], (u32)(1040187392), PV[10], (u32)(3212836864));  // @121_577ee0
  ecx = edx = 0;  // @122_577ee0
  PV[14] = (u32)(ecx);  // @123_577ee0
  eax = (u32)(ebx + 498);  // @124_577ee0
  PV[15] = (u32)(eax);  // @125_577ee0
  PV[16] = (u32)(ecx);  // @126_577ee0
  ecx = ebx;  // @127_577ee0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 472), sizeof v); (u32)v; });  // @128_577ee0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 452), sizeof v); (u32)v; });  // @129_577ee0
  eax = ext_574680_stdcall5(PV[18], PV[17], (u32)(1035489772), PV[15], (u32)(3212836864));  // @130_577ee0
  ecx = edx = 0;  // @131_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 468), sizeof v); (u32)v; });  // @132_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @134_577ee0
  ecx = edx = 0;  // @135_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 472), sizeof v); (u32)v; });  // @136_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @138_577ee0
  ecx = edx = 0;  // @139_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 460), sizeof v); (u32)v; });  // @140_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @142_577ee0
  ecx = edx = 0;  // @143_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 464), sizeof v); (u32)v; });  // @144_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @146_577ee0
  ecx = edx = 0;  // @147_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @148_577ee0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 452), sizeof v); (u32)v; });  // @149_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @150_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[19]);  // @152_577ee0
  ecx = edx = 0;  // @153_577ee0
  esi = eax;  // @154_577ee0
  eax = (u32)(EBP - 96);  // @155_577ee0
  PV[20] = (u32)(eax);  // @156_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @157_577ee0
  eax = ext_4db500_thiscall2(ecx, PV[20]);  // @158_577ee0
  edx = 0;  // @159_577ee0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 506) + 0), 4); v; });  // @160_577ee0
  X1[1] = 0;  // @161_577ee0
  X1[2] = 0;  // @162_577ee0
  X1[3] = 0;  // @163_577ee0
  ecx = (u32)(EBP - 96);  // @164_577ee0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896928) + 0), 4); v; })));  // @165_577ee0
  PV[21] = (u32)(ecx);  // @166_577ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; });  // @167_577ee0
  X0[1] = 0;  // @168_577ee0
  X0[2] = 0;  // @169_577ee0
  X0[3] = 0;  // @170_577ee0
  ecx = esi;  // @171_577ee0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @172_577ee0
  __builtin_memcpy((void *)((u32)(EBP - 88) + 0), &X0[0], 4);  // @173_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @174_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[21]);  // @175_577ee0
  ecx = edx = 0;  // @176_577ee0
  L57813b:;
  esi = (u32)(ebx + 528);  // @178_577ee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @179_577ee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @180_577ee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @181_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 523), sizeof v); (u32)v; });  // @182_577ee0
  PV[22] = (u32)(esi);  // @183_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @184_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[22]);  // @185_577ee0
  ecx = edx = 0;  // @186_577ee0
  PV[23] = (u32)(esi);  // @187_577ee0
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 452), sizeof v); (u32)v; });  // @188_577ee0
  ecx = ebx;  // @189_577ee0
  eax = ext_573c70_stdcall2(PV[24], PV[23]);  // @190_577ee0
  ecx = edx = 0;  // @191_577ee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 536), &v, sizeof v); }  // @192_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @193_577ee0
  PV[25] = (u32)(esi);  // @194_577ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @195_577ee0
  X0[0] = F2U((float)(s32)X0[0]);  // @196_577ee0
  X0[1] = F2U((float)(s32)X0[1]);  // @197_577ee0
  X0[2] = F2U((float)(s32)X0[2]);  // @198_577ee0
  X0[3] = F2U((float)(s32)X0[3]);  // @199_577ee0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806028) + 0), 4); v; })));  // @200_577ee0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @201_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 396), sizeof v); (u32)v; });  // @202_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @203_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[25]);  // @204_577ee0
  ecx = edx = 0;  // @205_577ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @206_577ee0
  X0[1] = 0;  // @207_577ee0
  X0[2] = 0;  // @208_577ee0
  X0[3] = 0;  // @209_577ee0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; })));  // @210_577ee0
  eax = (u32)((s32)edi * (s32)(u32)(22));  // @211_577ee0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @212_577ee0
  eax = (eax + (u32)(10));  // @213_577ee0
  FL[3] = eax;  // @214_577ee0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @215_577ee0
  X0[0] = F2U((float)(s32)X0[0]);  // @216_577ee0
  X0[1] = F2U((float)(s32)X0[1]);  // @217_577ee0
  X0[2] = F2U((float)(s32)X0[2]);  // @218_577ee0
  X0[3] = F2U((float)(s32)X0[3]);  // @219_577ee0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 532) + 0), 4); v; })));  // @220_577ee0
  __builtin_memcpy((void *)((u32)(ebx + 532) + 0), &X0[0], 4);  // @221_577ee0
  { u32 v = (u32)((u32)(33)); __builtin_memcpy((void *)(u32)(ebx + 544), &v, sizeof v); }  // @222_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @223_577ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @224_577ee0
  X0[1] = 0;  // @225_577ee0
  X0[2] = 0;  // @226_577ee0
  X0[3] = 0;  // @227_577ee0
  esi = 0;  // @228_577ee0
  FL[3] = esi;  // @229_577ee0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @230_577ee0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; }); X2[1] = X2[2] = X2[3] = 0;  // @231_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @232_577ee0
  X2[0] = F2U((float)(s32)X2[0]);  // @233_577ee0
  X2[1] = F2U((float)(s32)X2[1]);  // @234_577ee0
  X2[2] = F2U((float)(s32)X2[2]);  // @235_577ee0
  X2[3] = F2U((float)(s32)X2[3]);  // @236_577ee0
  X1[0] = X2[0];  // @237_577ee0
  X1[1] = X2[1];  // @238_577ee0
  X1[2] = X2[2];  // @239_577ee0
  X1[3] = X2[3];  // @240_577ee0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806028) + 0), 4); v; })));  // @241_577ee0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @242_577ee0
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @243_577ee0
  __builtin_memcpy((void *)((u32)(ebx + 540) + 0), &X2[0], 4);  // @244_577ee0
  FL[2] = (eax & eax);  // @245_577ee0
  if ((s32)FL[2] <= 0) goto L5782cd;  // @246_577ee0
  L578220:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 292), sizeof v); (u32)v; }); FL[1] = (u32)(19);  // @248_577ee0
  if (FL[0] == FL[1]) goto L5782c4;  // @249_577ee0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 356), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @250_577ee0
  if (FL[0] != FL[1]) goto L578282;  // @251_577ee0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @252_577ee0
  if (FL[0] == FL[1]) goto L578279;  // @253_577ee0
  ecx = (u32)(6981524);  // @254_577ee0
  eax = (u32)(ebx + 518);  // @255_577ee0
  L578250:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @257_577ee0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @258_577ee0
  if (FL[0] != FL[1]) goto L578270;  // @259_577ee0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @260_577ee0
  if (FL[2] == 0) goto L57826c;  // @261_577ee0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @262_577ee0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @263_577ee0
  if (FL[0] != FL[1]) goto L578270;  // @264_577ee0
  eax = (eax + (u32)(2));  // @265_577ee0
  FL[3] = eax;  // @266_577ee0
  ecx = (ecx + (u32)(2));  // @267_577ee0
  FL[3] = ecx;  // @268_577ee0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @269_577ee0
  if (FL[2] != 0) goto L578250;  // @270_577ee0
  L57826c:;
  eax = 0;  // @272_577ee0
  FL[3] = eax;  // @273_577ee0
  goto L578275;  // @274_577ee0
  L578270:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @276_577ee0
  eax = (eax | (u32)(1));  // @277_577ee0
  FL[3] = eax;  // @278_577ee0
  L578275:;
  FL[2] = (eax & eax);  // @280_577ee0
  if (FL[2] != 0) goto L578282;  // @281_577ee0
  L578279:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @283_577ee0
  goto L578289;  // @284_577ee0
  L578282:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @286_577ee0
  L578289:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @288_577ee0
  edx = (u32)(EBP - 20);  // @289_577ee0
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 420), sizeof v); (u32)v; });  // @290_577ee0
  PV[27] = (u32)(edx);  // @291_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @292_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @293_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @294_577ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[27], PV[26]);  // @295_577ee0
  ecx = edx = 0;  // @296_577ee0
  PV[28] = (u32)(eax);  // @297_577ee0
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @298_577ee0
  ecx = ebx;  // @299_577ee0
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 292), sizeof v); (u32)v; });  // @300_577ee0
  eax = ext_578430_thiscall4(ecx, PV[30], PV[29], PV[28]);  // @301_577ee0
  ecx = edx = 0;  // @302_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @303_577ee0
  L5782c4:;
  esi = (esi + 1);  // @305_577ee0
  FL[3] = esi;  // @306_577ee0
  FL[0] = esi; FL[1] = eax;  // @307_577ee0
  if ((s32)FL[0] < (s32)FL[1]) goto L578220;  // @308_577ee0
  L5782cd:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @310_577ee0
  FL[0] = (u32)(s32)(s8)({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74), sizeof v); (u32)v; }); FL[1] = (u32)(52);  // @311_577ee0   (w3g: signed byte compare)
  if ((s32)FL[0] >= (s32)FL[1]) goto L5783d1;  // @312_577ee0
  { u32 v = (u32)((u32)(6984888)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @313_577ee0
  eax = (u32)(esi + 72);  // @314_577ee0
  { u32 v = (u32)((u32)(18)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @315_577ee0
  edi = (u32)(3);  // @316_577ee0
  { u32 v = (u32)((u32)(6985852)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @317_577ee0
  ecx = (u32)(6977544);  // @318_577ee0
  { u32 v = (u32)((u32)(17)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @319_577ee0
  { u32 v = (u32)((u32)(6985872)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @320_577ee0
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @321_577ee0
  L578314:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @323_577ee0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @324_577ee0
  if (FL[0] != FL[1]) goto L578334;  // @325_577ee0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @326_577ee0
  if (FL[2] == 0) goto L578330;  // @327_577ee0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @328_577ee0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @329_577ee0
  if (FL[0] != FL[1]) goto L578334;  // @330_577ee0
  eax = (eax + (u32)(2));  // @331_577ee0
  FL[3] = eax;  // @332_577ee0
  ecx = (ecx + (u32)(2));  // @333_577ee0
  FL[3] = ecx;  // @334_577ee0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @335_577ee0
  if (FL[2] != 0) goto L578314;  // @336_577ee0
  L578330:;
  eax = 0;  // @338_577ee0
  FL[3] = eax;  // @339_577ee0
  goto L578339;  // @340_577ee0
  L578334:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @342_577ee0
  eax = (eax | (u32)(1));  // @343_577ee0
  FL[3] = eax;  // @344_577ee0
  L578339:;
  FL[2] = (eax & eax);  // @346_577ee0
  ecx = (u32)(1);  // @347_577ee0
  if (FL[2] == 0) edi = ecx;  // @348_577ee0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4158), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @349_577ee0
  if (FL[0] == FL[1]) goto L578385;  // @350_577ee0
  eax = (u32)(EBP - 156);  // @351_577ee0
  PV[31] = (u32)(eax);  // @352_577ee0
  eax = (u32)(EBP - 120);  // @353_577ee0
  PV[32] = (u32)(eax);  // @354_577ee0
  eax = (u32)(EBP - 428);  // @355_577ee0
  PV[33] = (u32)(eax);  // @356_577ee0
  eax = (u32)(ebx + 518);  // @357_577ee0
  PV[34] = (u32)(eax);  // @358_577ee0
  ecx = (u32)(esi + 3803);  // @359_577ee0
  eax = ext_5b15d0_thiscall5(ecx, PV[34], PV[33], PV[32], PV[31]);  // @360_577ee0
  ecx = edx = 0;  // @361_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @362_577ee0
  ecx = (u32)(2);  // @363_577ee0
  eax = (eax + (u32)(3));  // @364_577ee0
  FL[3] = eax;  // @365_577ee0
  FL[0] = ecx; FL[1] = eax;  // @366_577ee0
  edi = (0u - (u32)((FL[0]) < (FL[1])));  // @367_577ee0
  edi = (edi & (u32)(1));  // @368_577ee0
  FL[3] = edi;  // @369_577ee0
  L578385:;
  esi = 0;  // @371_577ee0
  FL[3] = esi;  // @372_577ee0
  { u32 v = (u32)((u32)(20)); __builtin_memcpy((void *)(u32)(ebx + 544), &v, sizeof v); }  // @373_577ee0
  FL[2] = (edi & edi);  // @374_577ee0
  if (FL[2] == 0) goto L5783d1;  // @375_577ee0
  L5783a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @377_577ee0
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*8 - 108), sizeof v); (u32)v; });  // @378_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @379_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @380_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @381_577ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), PV[35]);  // @382_577ee0
  ecx = edx = 0;  // @383_577ee0
  PV[36] = (u32)(eax);  // @384_577ee0
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*8 - 104), sizeof v); (u32)v; });  // @385_577ee0
  ecx = ebx;  // @386_577ee0
  eax = ext_578430_thiscall4(ecx, PV[37], (u32)(1), PV[36]);  // @387_577ee0
  ecx = edx = 0;  // @388_577ee0
  esi = (esi + 1);  // @389_577ee0
  FL[3] = esi;  // @390_577ee0
  FL[0] = esi; FL[1] = edi;  // @391_577ee0
  if ((s32)FL[0] < (s32)FL[1]) goto L5783a0;  // @392_577ee0
  L5783d1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 484), sizeof v); (u32)v; });  // @394_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @395_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @396_577ee0
  ecx = edx = 0;  // @397_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 480), sizeof v); (u32)v; });  // @398_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @399_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @400_577ee0
  ecx = edx = 0;  // @401_577ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 248), sizeof v); (u32)v; });  // @402_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @403_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 532)))(ecx, (u32)(1024));  // @404_577ee0
  ecx = edx = 0;  // @405_577ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @406_577ee0
  ecx = ebx;  // @407_577ee0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @408_577ee0
  ecx = edx = 0;  // @409_577ee0
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; });  // @410_577ee0
  ecx = eax;  // @411_577ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @412_577ee0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, PV[38]);  // @413_577ee0
  ecx = edx = 0;  // @414_577ee0
  ext_633654(G(u32, 0x6f5630));  // @415_577ee0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @416_577ee0
  FL[3] = (eax & 0xff);  // @417_577ee0
  return eax;  // @418_577ee0
}
PCREG(577ee0, lifted_577ee0);

