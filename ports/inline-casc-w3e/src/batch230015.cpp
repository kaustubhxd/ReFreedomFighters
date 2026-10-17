// batch230015.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 FASTCALL ext_52b390_fastcall3(u32, u32, u32) __asm__("ext_52b390");
extern "C" u32 THISCALL ext_52b0c0_thiscall1(u32) __asm__("ext_52b0c0");
extern "C" u32 THISCALL ext_52b170_thiscall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_52b170");
extern "C" u32 THISCALL ext_52b4e0_thiscall2(u32, u32) __asm__("ext_52b4e0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_52c6e0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_52c6e0
  ebx = ecx;  // @1_52c6e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_52c6e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @3_52c6e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @4_52c6e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @5_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @6_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 77), &v, sizeof v); }  // @7_52c6e0
  if (FL[0] == FL[1]) goto L52c71c;  // @8_52c6e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @9_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 73), &v, sizeof v); }  // @10_52c6e0
  L52c71c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @12_52c6e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 77), &v, sizeof v); }  // @13_52c6e0
  FL[2] = (eax & eax);  // @14_52c6e0
  if (FL[2] == 0) goto L52c744;  // @15_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @16_52c6e0
  if (FL[0] == FL[1]) goto L52c744;  // @17_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @18_52c6e0
  if (FL[0] != FL[1]) goto L52cab6;  // @19_52c6e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 73), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_52c6e0
  if (FL[0] != FL[1]) goto L52cab6;  // @21_52c6e0
  L52c744:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_52c6e0
  if (FL[0] == FL[1]) goto L52c772;  // @24_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @25_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(8979));  // @27_52c6e0
  ecx = edx = 0;  // @28_52c6e0
  PV[0] = (u32)(eax);  // @29_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_52c6e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6950972));  // @31_52c6e0
  ecx = edx = 0;  // @32_52c6e0
  goto L52cab6;  // @33_52c6e0
  L52c772:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7347032), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @35_52c6e0
  if (FL[0] == FL[1]) goto L52c79e;  // @36_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @37_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(8983));  // @39_52c6e0
  ecx = edx = 0;  // @40_52c6e0
  PV[1] = (u32)(eax);  // @41_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @42_52c6e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6951128));  // @43_52c6e0
  ecx = edx = 0;  // @44_52c6e0
  L52c79e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @46_52c6e0
  X0[1] = 0;  // @47_52c6e0
  X0[2] = 0;  // @48_52c6e0
  X0[3] = 0;  // @49_52c6e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @50_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @51_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @52_52c6e0
  X0[1] = 0;  // @53_52c6e0
  X0[2] = 0;  // @54_52c6e0
  X0[3] = 0;  // @55_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @56_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @57_52c6e0
  X0[1] = 0;  // @58_52c6e0
  X0[2] = 0;  // @59_52c6e0
  X0[3] = 0;  // @60_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @61_52c6e0
  FL[2] = (edx & edx);  // @62_52c6e0
  if (FL[2] == 0) goto L52c816;  // @63_52c6e0
  FL[0] = edx; FL[1] = (u32)(-1);  // @64_52c6e0
  if (FL[0] == FL[1]) goto L52c816;  // @65_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_52c6e0
  PV[2] = (u32)(edx);  // @67_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @68_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_52c6e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[2]);  // @70_52c6e0
  ecx = edx = 0;  // @71_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @72_52c6e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @73_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @75_52c6e0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097268));  // @76_52c6e0
  ecx = edx = 0;  // @77_52c6e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @78_52c6e0
  if (FL[2] == 0) goto L52c816;  // @79_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @80_52c6e0
  edx = (u32)(EBP - 16);  // @81_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @82_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @83_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @84_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_52c6e0
  PV[3] = (u32)(edx);  // @86_52c6e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1584)))(ecx, PV[3]);  // @87_52c6e0
  ecx = edx = 0;  // @88_52c6e0
  L52c816:;
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; });  // @90_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 44) + 0), 4); v; });  // @91_52c6e0
  X0[1] = 0;  // @92_52c6e0
  X0[2] = 0;  // @93_52c6e0
  X0[3] = 0;  // @94_52c6e0
  eax = (u32)(edi + 81);  // @95_52c6e0
  PV[5] = (u32)(eax);  // @96_52c6e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 49), sizeof v); (u32)v; });  // @97_52c6e0
  ecx = (u32)(esi + 20);  // @98_52c6e0
  PV[6] = (u32)(eax);  // @99_52c6e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @100_52c6e0
  PV[7] = (u32)(eax);  // @101_52c6e0
  PV[8] = (u32)(ecx);  // @102_52c6e0
  PV[9] = X0[0];  // @103_52c6e0
  eax = (u32)(EBP - 16);  // @104_52c6e0
  PV[10] = (u32)(ecx);  // @105_52c6e0
  PV[11] = (u32)(eax);  // @106_52c6e0
  ecx = ebx;  // @107_52c6e0
  eax = ext_52b170_thiscall8(ecx, PV[11], PV[10], PV[9], PV[7], PV[6], PV[5], PV[4]);  // @108_52c6e0
  ecx = edx = 0;  // @109_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 153), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @110_52c6e0
  ebx = eax;  // @111_52c6e0
  if (FL[0] != FL[1]) goto L52c8a9;  // @112_52c6e0
  FL[2] = (ebx & ebx);  // @113_52c6e0
  if (FL[2] == 0) goto L52caec;  // @114_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @115_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(9004));  // @117_52c6e0
  ecx = edx = 0;  // @118_52c6e0
  PV[12] = (u32)(eax);  // @119_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @120_52c6e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[12], (u32)(6951152));  // @121_52c6e0
  ecx = edx = 0;  // @122_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @123_52c6e0
  FL[2] = (eax & eax);  // @124_52c6e0
  if (FL[2] == 0) goto L52c895;  // @125_52c6e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @126_52c6e0
  ecx = edx = 0;  // @127_52c6e0
  ext_633654(G(u32, 0x6f5630));  // @128_52c6e0
  return eax;  // @129_52c6e0
  L52c895:;
  __builtin_trap();  // @131_52c6e0
  L52c8a9:;
  FL[2] = (ebx & ebx);  // @133_52c6e0
  if (FL[2] == 0) goto L52c8b8;  // @134_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @135_52c6e0
  PV[13] = (u32)(ebx);  // @136_52c6e0
  eax = ext_52b4e0_thiscall2(ecx, PV[13]);  // @137_52c6e0
  ecx = edx = 0;  // @138_52c6e0
  ebx = eax;  // @139_52c6e0
  L52c8b8:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @141_52c6e0
  FL[2] = (edx & edx);  // @142_52c6e0
  if (FL[2] == 0) goto L52ca9f;  // @143_52c6e0
  FL[0] = edx; FL[1] = (u32)(-1);  // @144_52c6e0
  if (FL[0] == FL[1]) goto L52ca9f;  // @145_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @146_52c6e0
  PV[14] = (u32)(edx);  // @147_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @148_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_52c6e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[14]);  // @150_52c6e0
  ecx = edx = 0;  // @151_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @152_52c6e0
  FL[2] = (eax & eax);  // @153_52c6e0
  if (FL[2] == 0) goto L52ca9f;  // @154_52c6e0
  FL[2] = (ebx & ebx);  // @155_52c6e0
  if (FL[2] == 0) goto L52c9fd;  // @156_52c6e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @157_52c6e0
  if ((s32)FL[0] <= (s32)FL[1]) goto L52c9fd;  // @158_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @159_52c6e0
  X0[1] = 0;  // @160_52c6e0
  X0[2] = 0;  // @161_52c6e0
  X0[3] = 0;  // @162_52c6e0
  ecx = (u32)(EBP - 28);  // @163_52c6e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @164_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @165_52c6e0
  edx = (edx + (u32)(4));  // @166_52c6e0
  FL[3] = edx;  // @167_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @168_52c6e0
  X0[1] = 0;  // @169_52c6e0
  X0[2] = 0;  // @170_52c6e0
  X0[3] = 0;  // @171_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @172_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @173_52c6e0
  X0[1] = 0;  // @174_52c6e0
  X0[2] = 0;  // @175_52c6e0
  X0[3] = 0;  // @176_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @177_52c6e0
  eax = ext_4e0870_fastcall2(ecx, edx);  // @178_52c6e0
  ecx = edx = 0;  // @179_52c6e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; });  // @180_52c6e0
  X1[1] = 0;  // @181_52c6e0
  X1[2] = 0;  // @182_52c6e0
  X1[3] = 0;  // @183_52c6e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 32)) :: "st");  // @184_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @185_52c6e0
  X0[1] = 0;  // @186_52c6e0
  X0[2] = 0;  // @187_52c6e0
  X0[3] = 0;  // @188_52c6e0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L52c97b;  // @189_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @190_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @191_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(9034));  // @192_52c6e0
  ecx = edx = 0;  // @193_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @194_52c6e0
  X0[1] = 0;  // @195_52c6e0
  X0[2] = 0;  // @196_52c6e0
  X0[3] = 0;  // @197_52c6e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @198_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @199_52c6e0
  PV[15] = X0[0]; PV[16] = X0[1];  // @200_52c6e0
  PV[17] = (u32)(eax);  // @201_52c6e0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[17], (u32)(6951192), PV[15], PV[16]);  // @202_52c6e0
  ecx = edx = 0;  // @203_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @204_52c6e0
  X0[1] = 0;  // @205_52c6e0
  X0[2] = 0;  // @206_52c6e0
  X0[3] = 0;  // @207_52c6e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; });  // @208_52c6e0
  X1[1] = 0;  // @209_52c6e0
  X1[2] = 0;  // @210_52c6e0
  X1[3] = 0;  // @211_52c6e0
  L52c97b:;
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; }))))))) goto L52c9fd;  // @213_52c6e0
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L52c9fd;  // @214_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @215_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @216_52c6e0
  X0[1] = 0;  // @217_52c6e0
  X0[2] = 0;  // @218_52c6e0
  X0[3] = 0;  // @219_52c6e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @220_52c6e0
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X0[0], 4);  // @221_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @222_52c6e0
  X0[1] = 0;  // @223_52c6e0
  X0[2] = 0;  // @224_52c6e0
  X0[3] = 0;  // @225_52c6e0
  __builtin_memcpy((void *)((u32)(eax + 8) + 0), &X0[0], 4);  // @226_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @227_52c6e0
  X0[1] = 0;  // @228_52c6e0
  X0[2] = 0;  // @229_52c6e0
  X0[3] = 0;  // @230_52c6e0
  __builtin_memcpy((void *)((u32)(eax + 12) + 0), &X0[0], 4);  // @231_52c6e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @232_52c6e0
  if ((s32)FL[0] <= (s32)FL[1]) goto L52c9ee;  // @233_52c6e0
  edi = (u32)(16);  // @234_52c6e0
  L52c9c0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @236_52c6e0
  edx = (u32)(edi + 4);  // @237_52c6e0
  ecx = (u32)(edi - 12);  // @238_52c6e0
  edx = (edx + esi);  // @239_52c6e0
  FL[3] = edx;  // @240_52c6e0
  ecx = (ecx + esi);  // @241_52c6e0
  FL[3] = ecx;  // @242_52c6e0
  eax = ext_4e0870_fastcall2(ecx, edx);  // @243_52c6e0
  ecx = edx = 0;  // @244_52c6e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi + edi - 16)) : "st");  // @245_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @246_52c6e0
  eax = (eax + 1);  // @247_52c6e0
  FL[3] = eax;  // @248_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @249_52c6e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + edi)) :: "st");  // @250_52c6e0
  edi = (edi + (u32)(16));  // @251_52c6e0
  FL[3] = edi;  // @252_52c6e0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @253_52c6e0
  if ((s32)FL[0] < (s32)FL[1]) goto L52c9c0;  // @254_52c6e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @255_52c6e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @256_52c6e0
  L52c9ee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @258_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @259_52c6e0
  ecx = (ecx + ecx);  // @260_52c6e0
  FL[3] = ecx;  // @261_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 - 16), sizeof v); (u32)v; });  // @262_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @263_52c6e0
  L52c9fd:;
  eax = ext_41e290_cdecl1((u32)(32));  // @265_52c6e0
  ecx = edx = 0;  // @266_52c6e0
  ecx = eax;  // @267_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @268_52c6e0
  FL[2] = (ecx & ecx);  // @269_52c6e0
  if (FL[2] == 0) goto L52ca1c;  // @270_52c6e0
  X0[0] = 0;  // @271_52c6e0
  X0[1] = 0;  // @272_52c6e0
  X0[2] = 0;  // @273_52c6e0
  X0[3] = 0;  // @274_52c6e0
  __builtin_memcpy((void *)((u32)(ecx) + 0), &X0[0], 4);  // @275_52c6e0
  __builtin_memcpy((void *)((u32)(ecx) + 4), &X0[1], 4);  // @276_52c6e0
  __builtin_memcpy((void *)((u32)(ecx) + 8), &X0[2], 4);  // @277_52c6e0
  __builtin_memcpy((void *)((u32)(ecx) + 12), &X0[3], 4);  // @278_52c6e0
  __builtin_memcpy((void *)((u32)(ecx + 16) + 0), &X0[0], 4);  // @279_52c6e0
  __builtin_memcpy((void *)((u32)(ecx + 16) + 4), &X0[1], 4);  // @280_52c6e0
  __builtin_memcpy((void *)((u32)(ecx + 16) + 8), &X0[2], 4);  // @281_52c6e0
  __builtin_memcpy((void *)((u32)(ecx + 16) + 12), &X0[3], 4);  // @282_52c6e0
  goto L52ca21;  // @283_52c6e0
  L52ca1c:;
  ecx = 0;  // @285_52c6e0
  FL[3] = ecx;  // @286_52c6e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @287_52c6e0
  L52ca21:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @289_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @290_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @291_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @292_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @293_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @294_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @295_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @296_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @297_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @298_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @299_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @300_52c6e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @301_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @302_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @303_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7347032), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @304_52c6e0
  if (FL[0] == FL[1]) goto L52ca7d;  // @305_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @306_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @307_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(9055));  // @308_52c6e0
  ecx = edx = 0;  // @309_52c6e0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @310_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @311_52c6e0
  PV[19] = (u32)(eax);  // @312_52c6e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[19], (u32)(6951288), PV[18]);  // @313_52c6e0
  ecx = edx = 0;  // @314_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @315_52c6e0
  L52ca7d:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @317_52c6e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @318_52c6e0
  FL[2] = (ebx & ebx);  // @319_52c6e0
  if (FL[2] == 0) goto L52ca9f;  // @320_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @321_52c6e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @322_52c6e0
  PV[20] = (u32)(ecx);  // @323_52c6e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 149), sizeof v); (u32)v; });  // @324_52c6e0
  ecx = ebx;  // @325_52c6e0
  PV[21] = (u32)(eax);  // @326_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[21], PV[20], (u32)(0));  // @327_52c6e0
  ecx = edx = 0;  // @328_52c6e0
  L52ca9f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @330_52c6e0
  PV[22] = (u32)(esi);  // @331_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 121), sizeof v); (u32)v; });  // @332_52c6e0
  eax = ext_52b390_fastcall3(ecx, edx, PV[22]);  // @333_52c6e0
  ecx = edx = 0;  // @334_52c6e0
  ecx = edi;  // @335_52c6e0
  eax = ext_52b0c0_thiscall1(ecx);  // @336_52c6e0
  ecx = edx = 0;  // @337_52c6e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @338_52c6e0
  if (FL[2] != 0) goto L52caec;  // @339_52c6e0
  L52cab6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @341_52c6e0
  FL[2] = (eax & eax);  // @342_52c6e0
  if (FL[2] == 0) goto L52cae8;  // @343_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @344_52c6e0
  if (FL[0] == FL[1]) goto L52cae8;  // @345_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @346_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @347_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @348_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6950568), (u32)(61));  // @349_52c6e0
  ecx = edx = 0;  // @350_52c6e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @351_52c6e0
  ecx = eax;  // @352_52c6e0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @353_52c6e0
  FL[3] = ecx;  // @354_52c6e0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @355_52c6e0
  if (FL[0] <= FL[1]) goto L52cae8;  // @356_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @357_52c6e0
  L52cae8:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @359_52c6e0
  L52caec:;
  ext_633654(G(u32, 0x6f5630));  // @361_52c6e0
  return eax;  // @362_52c6e0
}
PCREG(52c6e0, lifted_52c6e0);

