// batch252015.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_4e2560_fastcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_4e2560");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_6616f0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  __builtin_memcpy(F + 0x300 + 40, &a8, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @0_6616f0
  edx = (edx & 0xffffff00u) | ((0) & 0xff);  // @1_6616f0
  FL[3] = (edx & 0xff);  // @2_6616f0
  eax = (eax + (u32)(-2));  // @3_6616f0
  FL[3] = eax;  // @4_6616f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_6616f0
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 11), &v, sizeof v); }  // @6_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @7_6616f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }); FL[1] = eax;  // @8_6616f0
  if (FL[0] >= FL[1]) goto L661935;  // @9_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 40), sizeof v); (u32)v; });  // @10_6616f0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; })) & 0xff);  // @11_6616f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @12_6616f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @13_6616f0
  esi = (esi + (u32)(4));  // @14_6616f0
  FL[3] = esi;  // @15_6616f0
  L661720:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @17_6616f0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @18_6616f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @19_6616f0
  PV[0] = (u32)(eax);  // @20_6616f0
  eax = (u32)(EBP + 24);  // @21_6616f0
  PV[1] = (u32)(eax);  // @22_6616f0
  if (FL[2] == 0) goto L66181b;  // @23_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 2), sizeof v); (u32)v; });  // @24_6616f0
  eax = (u32)(eax + eax*8);  // @25_6616f0
  eax = (u32)(edi + eax*4);  // @26_6616f0
  PV[2] = (u32)(eax);  // @27_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_6616f0
  eax = (u32)(eax + eax*8);  // @29_6616f0
  eax = (u32)(edi + eax*4);  // @30_6616f0
  PV[3] = (u32)(eax);  // @31_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @32_6616f0
  eax = (u32)(eax + eax*8);  // @33_6616f0
  eax = (u32)(edi + eax*4);  // @34_6616f0
  PV[4] = (u32)(eax);  // @35_6616f0
  eax = ext_4e2560_fastcall7(ecx, edx, PV[4], PV[3], PV[2], PV[1], PV[0]);  // @36_6616f0
    // @37_6616f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @38_6616f0
  if (FL[2] == 0) goto L6618ea;  // @39_6616f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 24) + 0), 4); v; });  // @40_6616f0
  X1[1] = 0;  // @41_6616f0
  X1[2] = 0;  // @42_6616f0
  X1[3] = 0;  // @43_6616f0
  X0[0] = 0;  // @44_6616f0
  X0[1] = 0;  // @45_6616f0
  X0[2] = 0;  // @46_6616f0
  X0[3] = 0;  // @47_6616f0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @48_6616f0
  if ((!(FA >= FB))) goto L6618ea;  // @49_6616f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @50_6616f0
  X0[1] = 0;  // @51_6616f0
  X0[2] = 0;  // @52_6616f0
  X0[3] = 0;  // @53_6616f0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @54_6616f0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L6618ea;  // @55_6616f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @56_6616f0
  X0[1] = 0;  // @57_6616f0
  X0[2] = 0;  // @58_6616f0
  X0[3] = 0;  // @59_6616f0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @60_6616f0
  if ((!(FA >= FB))) goto L6618ea;  // @61_6616f0
  __builtin_memcpy((void *)((u32)(ebx) + 0), &X1[0], 4);  // @62_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @63_6616f0
  eax = (u32)(eax + eax*8);  // @64_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @65_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 20), &v, sizeof v); }  // @66_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @67_6616f0
  eax = (u32)(eax + eax*8);  // @68_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; });  // @69_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @70_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @71_6616f0
  eax = (u32)(eax + eax*8);  // @72_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 8), sizeof v); (u32)v; });  // @73_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @74_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @75_6616f0
  eax = (u32)(eax + eax*8);  // @76_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @77_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @78_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @79_6616f0
  eax = (u32)(eax + eax*8);  // @80_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; });  // @81_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 36), &v, sizeof v); }  // @82_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @83_6616f0
  eax = (u32)(eax + eax*8);  // @84_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 8), sizeof v); (u32)v; });  // @85_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 40), &v, sizeof v); }  // @86_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 2), sizeof v); (u32)v; });  // @87_6616f0
  eax = (u32)(eax + eax*8);  // @88_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @89_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 44), &v, sizeof v); }  // @90_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 2), sizeof v); (u32)v; });  // @91_6616f0
  eax = (u32)(eax + eax*8);  // @92_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; });  // @93_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @94_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 2), sizeof v); (u32)v; });  // @95_6616f0
  L661801:;
  eax = (u32)(eax + eax*8);  // @97_6616f0
  edx = (edx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @98_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 8), sizeof v); (u32)v; });  // @99_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 52), &v, sizeof v); }  // @100_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @101_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 56), &v, sizeof v); }  // @102_6616f0
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 11), &v, sizeof v); }  // @103_6616f0
  goto L6618f0;  // @104_6616f0
  L66181b:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_6616f0
  eax = (u32)(eax + eax*8);  // @107_6616f0
  eax = (u32)(edi + eax*4);  // @108_6616f0
  PV[5] = (u32)(eax);  // @109_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 2), sizeof v); (u32)v; });  // @110_6616f0
  eax = (u32)(eax + eax*8);  // @111_6616f0
  eax = (u32)(edi + eax*4);  // @112_6616f0
  PV[6] = (u32)(eax);  // @113_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @114_6616f0
  eax = (u32)(eax + eax*8);  // @115_6616f0
  eax = (u32)(edi + eax*4);  // @116_6616f0
  PV[7] = (u32)(eax);  // @117_6616f0
  eax = ext_4e2560_fastcall7(ecx, edx, PV[7], PV[6], PV[5], PV[1], PV[0]);  // @118_6616f0
    // @119_6616f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @120_6616f0
  if (FL[2] == 0) goto L6618ea;  // @121_6616f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 24) + 0), 4); v; });  // @122_6616f0
  X1[1] = 0;  // @123_6616f0
  X1[2] = 0;  // @124_6616f0
  X1[3] = 0;  // @125_6616f0
  X0[0] = 0;  // @126_6616f0
  X0[1] = 0;  // @127_6616f0
  X0[2] = 0;  // @128_6616f0
  X0[3] = 0;  // @129_6616f0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @130_6616f0
  if ((!(FA >= FB))) goto L6618ea;  // @131_6616f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @132_6616f0
  X0[1] = 0;  // @133_6616f0
  X0[2] = 0;  // @134_6616f0
  X0[3] = 0;  // @135_6616f0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @136_6616f0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L6618ea;  // @137_6616f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @138_6616f0
  X0[1] = 0;  // @139_6616f0
  X0[2] = 0;  // @140_6616f0
  X0[3] = 0;  // @141_6616f0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @142_6616f0
  if ((!(FA >= FB))) goto L6618ea;  // @143_6616f0
  __builtin_memcpy((void *)((u32)(ebx) + 0), &X1[0], 4);  // @144_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @145_6616f0
  eax = (u32)(eax + eax*8);  // @146_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @147_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 20), &v, sizeof v); }  // @148_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @149_6616f0
  eax = (u32)(eax + eax*8);  // @150_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; });  // @151_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @152_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @153_6616f0
  eax = (u32)(eax + eax*8);  // @154_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 8), sizeof v); (u32)v; });  // @155_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @156_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 2), sizeof v); (u32)v; });  // @157_6616f0
  eax = (u32)(eax + eax*8);  // @158_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @159_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @160_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 2), sizeof v); (u32)v; });  // @161_6616f0
  eax = (u32)(eax + eax*8);  // @162_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; });  // @163_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 36), &v, sizeof v); }  // @164_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi - 2), sizeof v); (u32)v; });  // @165_6616f0
  eax = (u32)(eax + eax*8);  // @166_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 8), sizeof v); (u32)v; });  // @167_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 40), &v, sizeof v); }  // @168_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @169_6616f0
  eax = (u32)(eax + eax*8);  // @170_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @171_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 44), &v, sizeof v); }  // @172_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @173_6616f0
  eax = (u32)(eax + eax*8);  // @174_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; });  // @175_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @176_6616f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_6616f0
  goto L661801;  // @178_6616f0
  L6618ea:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; })) & 0xff);  // @180_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @181_6616f0
  L6618f0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @183_6616f0
  ecx = (ecx & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @184_6616f0
  eax = (eax + 1);  // @185_6616f0
  FL[3] = eax;  // @186_6616f0
  esi = (esi + (u32)(2));  // @187_6616f0
  FL[3] = esi;  // @188_6616f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @189_6616f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @190_6616f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 40), sizeof v); (u32)v; });  // @191_6616f0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 28), &v, sizeof v); }  // @192_6616f0
  if (FL[0] < FL[1]) goto L661720;  // @193_6616f0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @194_6616f0
  if (FL[2] == 0) goto L661935;  // @195_6616f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @196_6616f0
  X0[1] = 0;  // @197_6616f0
  X0[2] = 0;  // @198_6616f0
  X0[3] = 0;  // @199_6616f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @200_6616f0
  PV[8] = (u32)(ecx);  // @201_6616f0
  PV[9] = X0[0];  // @202_6616f0
  ecx = (u32)(ebx + 4);  // @203_6616f0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @204_6616f0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[10], PV[9]);  // @205_6616f0
  ecx = edx = 0;  // @206_6616f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; })) & 0xff);  // @207_6616f0
  return eax;  // @208_6616f0
  L661935:;
  eax = (eax & 0xffffff00u) | (((edx & 0xff)) & 0xff);  // @210_6616f0
  return eax;  // @211_6616f0
}
PCREG(6616f0, lifted_6616f0);

