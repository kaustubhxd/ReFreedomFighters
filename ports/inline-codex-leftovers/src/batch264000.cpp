// batch264000.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4b5620_thiscall2(u32, u32) __asm__("ext_4b5620");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4b56b0(u32 ecx_in) {
  SEH_ENTER(0x6685bb);  // @h_4b56b0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4b56b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_4b56b0
  ecx = edx = 0;  // @5_4b56b0
  ecx = (u32)(EBP - 148);  // @6_4b56b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @7_4b56b0
  PV[0] = (u32)(ecx);  // @8_4b56b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_4b56b0
  ecx = eax;  // @10_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6852480), PV[0]);  // @11_4b56b0
  ecx = edx = 0;  // @12_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @13_4b56b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 140), &v, sizeof v); }  // @14_4b56b0
  eax = 0;  // @15_4b56b0
  FL[3] = eax;  // @16_4b56b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @17_4b56b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 238), sizeof v); (u32)v; }); FL[1] = eax;  // @18_4b56b0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4b5818;  // @19_4b56b0
  L4b5733:;
  PV[1] = (u32)(eax);  // @21_4b56b0
  ecx = ebx;  // @22_4b56b0
  eax = ext_4b5620_thiscall2(ecx, PV[1]);  // @23_4b56b0
  ecx = edx = 0;  // @24_4b56b0
  edi = eax;  // @25_4b56b0
  FL[2] = (edi & edi);  // @26_4b56b0
  if (FL[2] == 0) goto L4b57ff;  // @27_4b56b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @28_4b56b0
  eax = (u32)(EBP - 148);  // @29_4b56b0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @30_4b56b0
  PV[2] = (u32)(eax);  // @31_4b56b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @32_4b56b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @33_4b56b0
  PV[3] = (u32)(ecx);  // @34_4b56b0
  PV[4] = (u32)(edi);  // @35_4b56b0
  ecx = edx;  // @36_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, PV[4], PV[3], PV[2]);  // @37_4b56b0
  ecx = edx = 0;  // @38_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @39_4b56b0
  FL[2] = (eax & eax);  // @40_4b56b0
  if (FL[2] != 0) goto L4b57a6;  // @41_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @42_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(518));  // @44_4b56b0
  ecx = edx = 0;  // @45_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @46_4b56b0
  edx = (u32)(6801640);  // @47_4b56b0
  FL[2] = (ecx & ecx);  // @48_4b56b0
  if (FL[2] != 0) edx = ecx;  // @49_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @50_4b56b0
  PV[5] = (u32)(edx);  // @51_4b56b0
  PV[6] = (u32)(eax);  // @52_4b56b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[6], (u32)(6889600), PV[5]);  // @53_4b56b0
  ecx = edx = 0;  // @54_4b56b0
  goto L4b57ff;  // @55_4b56b0
  L4b57a6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @57_4b56b0
  X0[1] = 0;  // @58_4b56b0
  X0[2] = 0;  // @59_4b56b0
  X0[3] = 0;  // @60_4b56b0
  FC0 = U2F(X0[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 222) + 0), 4); v; }));  // @61_4b56b0
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L4b57bc;  // @62_4b56b0
  __builtin_memcpy((void *)((u32)(ebx + 222) + 0), &X0[0], 4);  // @63_4b56b0
  L4b57bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @65_4b56b0
  ecx = (u32)(6801640);  // @66_4b56b0
  FL[2] = (eax & eax);  // @67_4b56b0
  if (FL[2] != 0) ecx = eax;  // @68_4b56b0
  eax = (u32)(6889640);  // @69_4b56b0
  L4b57d0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @71_4b56b0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @72_4b56b0
  if (FL[0] != FL[1]) goto L4b57f0;  // @73_4b56b0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @74_4b56b0
  if (FL[2] == 0) goto L4b57ec;  // @75_4b56b0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @76_4b56b0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @77_4b56b0
  if (FL[0] != FL[1]) goto L4b57f0;  // @78_4b56b0
  ecx = (ecx + (u32)(2));  // @79_4b56b0
  FL[3] = ecx;  // @80_4b56b0
  eax = (eax + (u32)(2));  // @81_4b56b0
  FL[3] = eax;  // @82_4b56b0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @83_4b56b0
  if (FL[2] != 0) goto L4b57d0;  // @84_4b56b0
  L4b57ec:;
  eax = 0;  // @86_4b56b0
  FL[3] = eax;  // @87_4b56b0
  goto L4b57f5;  // @88_4b56b0
  L4b57f0:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @90_4b56b0
  eax = (eax | (u32)(1));  // @91_4b56b0
  FL[3] = eax;  // @92_4b56b0
  L4b57f5:;
  FL[2] = (eax & eax);  // @94_4b56b0
  if (FL[2] != 0) goto L4b57ff;  // @95_4b56b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 222), &v, sizeof v); }  // @96_4b56b0
  L4b57ff:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @98_4b56b0
  eax = (eax + 1);  // @99_4b56b0
  FL[3] = eax;  // @100_4b56b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @101_4b56b0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 238), sizeof v); (u32)v; });  // @102_4b56b0
  if ((s32)FL[0] < (s32)FL[1]) goto L4b5733;  // @103_4b56b0
  L4b5818:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @105_4b56b0
  if (FL[0] == FL[1]) goto L4b58b2;  // @106_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @107_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(534));  // @109_4b56b0
  ecx = edx = 0;  // @110_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @111_4b56b0
  edi = eax;  // @112_4b56b0
  eax = (u32)(EBP - 144);  // @113_4b56b0
  PV[7] = (u32)(eax);  // @114_4b56b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 476)))(ecx, PV[7], (u32)(1));  // @116_4b56b0
  ecx = edx = 0;  // @117_4b56b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @118_4b56b0
  ecx = eax;  // @119_4b56b0
  reg.state = (s32)((u32)(0));  // @120_4b56b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @121_4b56b0
    // @122_4b56b0
  PV[8] = (u32)(eax);  // @123_4b56b0
  PV[9] = (u32)(edi);  // @124_4b56b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[9], (u32)(6889660), PV[8]);  // @125_4b56b0
  ecx = edx = 0;  // @126_4b56b0
  reg.state = (s32)((u32)(4294967295));  // @127_4b56b0
  ecx = (u32)(EBP - 144);  // @128_4b56b0
  eax = ext_4cbec0_thiscall1(ecx);  // @129_4b56b0
  ecx = edx = 0;  // @130_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @131_4b56b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @132_4b56b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @133_4b56b0
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx + 155), &v, sizeof v); }  // @134_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 292)))(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @136_4b56b0
  ecx = edx = 0;  // @137_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @138_4b56b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 78), sizeof v); (u32)v; });  // @139_4b56b0
  PV[10] = (u32)(eax);  // @140_4b56b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_4b56b0
  PV[11] = (u32)(ecx);  // @142_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[11], PV[10], (u32)(0));  // @143_4b56b0
  ecx = edx = 0;  // @144_4b56b0
  L4b58b2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @146_4b56b0
  ecx = ebx;  // @147_4b56b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 140)))(ecx);  // @148_4b56b0
  ecx = edx = 0;  // @149_4b56b0
  SEH_LEAVE();  // @150_4b56b0
  ext_633654(G(u32, 0x6f5630));  // @151_4b56b0
  return eax;  // @152_4b56b0
}
PCREG(4b56b0, lifted_4b56b0);

