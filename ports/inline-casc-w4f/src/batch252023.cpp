// batch252023.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634dac_dbl(double) __asm__("ext_634dac");
extern "C" double VECTORCALL ext_634de2_dbl(double) __asm__("ext_634de2");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4de4b0_fastcall3(u32, u32, u32) __asm__("ext_4de4b0");
extern "C" u32 THISCALL ext_63eab0_thiscall2(u32, u32) __asm__("ext_63eab0");
extern "C" u32 THISCALL ext_6590e0_thiscall1(u32) __asm__("ext_6590e0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_6593e0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 124) + 8), &v, sizeof v); }  // @2_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 6819), sizeof v); (u32)v; });  // @3_6593e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @5_6593e0
  edi = ecx;  // @6_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 136) + 52), &v, sizeof v); }  // @7_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @8_6593e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 136) + 28), &v, sizeof v); }  // @9_6593e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 136) + 32), &v, sizeof v); }  // @10_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; });  // @11_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 136) + 16), &v, sizeof v); }  // @12_6593e0
  FL[2] = (eax & eax);  // @13_6593e0
  if (FL[2] != 0) goto L659440;  // @14_6593e0
  ext_633654(G(u32, 0x6f5630));  // @15_6593e0
  return eax;  // @16_6593e0
  L659440:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 155), sizeof v); (u32)v; });  // @18_6593e0
  ebx = 0;  // @19_6593e0
  FL[3] = ebx;  // @20_6593e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 136) + 24), &v, sizeof v); }  // @21_6593e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23861), sizeof v); (u32)v; });  // @22_6593e0
  FL[2] = (ecx & ecx);  // @23_6593e0
  if (FL[2] == 0) goto L6594ca;  // @24_6593e0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 16), sizeof v); (u32)v; });  // @25_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_6593e0
  edx = (u32)((EBP - 140) + 20);  // @27_6593e0
  PV[1] = (u32)(edx);  // @28_6593e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[1], PV[0]);  // @29_6593e0
  ecx = edx = 0;  // @30_6593e0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(8));  // @31_6593e0
  edi = eax;  // @32_6593e0
  if (FL[2] == 0) goto L65948d;  // @33_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @34_6593e0
  FL[2] = (eax & eax);  // @35_6593e0
  if (FL[2] == 0) goto L65948d;  // @36_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @37_6593e0
  FL[2] = (eax & eax);  // @38_6593e0
  if (FL[2] == 0) goto L65948d;  // @39_6593e0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; }); FL[1] = (ebx & 0xffff);  // @40_6593e0
  if (FL[0] == FL[1]) goto L65948d;  // @41_6593e0
  ebx = (u32)(1);  // @42_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 136) + 84), &v, sizeof v); }  // @43_6593e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 136) + 24), &v, sizeof v); }  // @44_6593e0
  L65948d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 16), sizeof v); (u32)v; });  // @46_6593e0
  eax = 0;  // @47_6593e0
  FL[3] = eax;  // @48_6593e0
  FL[2] = (edx & edx);  // @49_6593e0
  if (FL[2] == 0) goto L6594c6;  // @50_6593e0
  L6594a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @52_6593e0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 90), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @53_6593e0
  if (FL[0] == FL[1]) goto L6594bd;  // @54_6593e0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(9216));  // @55_6593e0
  if (FL[2] != 0) goto L6594bd;  // @56_6593e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 136) + ebx*4 + 84), &v, sizeof v); }  // @57_6593e0
  ebx = (ebx + 1);  // @58_6593e0
  FL[3] = ebx;  // @59_6593e0
  FL[0] = ebx; FL[1] = (u32)(12);  // @60_6593e0
  if (FL[0] == FL[1]) goto L6594c2;  // @61_6593e0
  L6594bd:;
  eax = (eax + 1);  // @63_6593e0
  FL[3] = eax;  // @64_6593e0
  FL[0] = eax; FL[1] = edx;  // @65_6593e0
  if (FL[0] < FL[1]) goto L6594a0;  // @66_6593e0
  L6594c2:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 136) + 24), &v, sizeof v); }  // @68_6593e0
  L6594c6:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 28), sizeof v); (u32)v; });  // @70_6593e0
  L6594ca:;
  ecx = 0;  // @72_6593e0
  FL[3] = ecx;  // @73_6593e0
  eax = 0;  // @74_6593e0
  FL[3] = eax;  // @75_6593e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 136) + 36), &v, sizeof v); }  // @76_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 136) + 16), &v, sizeof v); }  // @77_6593e0
  FL[2] = (ebx & ebx);  // @78_6593e0
  if (FL[2] == 0) goto L659a90;  // @79_6593e0
  ecx = (u32)(esi + 44);  // @80_6593e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 20), sizeof v); (u32)v; });  // @81_6593e0
  esi = (esi + (u32)(508));  // @82_6593e0
  FL[3] = esi;  // @83_6593e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 136) + 56), &v, sizeof v); }  // @84_6593e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 136) + 20), &v, sizeof v); }  // @85_6593e0
  L6594f3:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + eax*4 + 84), sizeof v); (u32)v; });  // @87_6593e0
  ecx = edi;  // @88_6593e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 90), sizeof v); (u32)v; });  // @89_6593e0
  PV[2] = (u32)(eax);  // @90_6593e0
  eax = ext_63eab0_thiscall2(ecx, PV[2]);  // @91_6593e0
  edx = 0;  // @92_6593e0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 56), sizeof v); (u32)v; });  // @93_6593e0
  edi = eax;  // @94_6593e0
  ecx = (u32)(esi - 84);  // @95_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @96_6593e0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 140) + 56), sizeof v); (u32)v; }));  // @97_6593e0
  FL[3] = eax;  // @98_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 140) + 44), &v, sizeof v); }  // @99_6593e0
  edx = (u32)(edi + 44);  // @100_6593e0
  eax = ext_43e920_fastcall3(ecx, edx, PV[3]);  // @101_6593e0
  ecx = edx = 0;  // @102_6593e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 32), sizeof v); (u32)v; });  // @103_6593e0
  ecx = (u32)(esi - 84);  // @104_6593e0
  edx = (u32)(edx + 8);  // @105_6593e0
  eax = ext_441a60_fastcall2(ecx, edx);  // @106_6593e0
  ecx = edx = 0;  // @107_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 32), sizeof v); (u32)v; });  // @108_6593e0
  edx = (u32)(edi + 8);  // @109_6593e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 20), sizeof v); (u32)v; });  // @110_6593e0
  eax = (eax + (u32)(8));  // @111_6593e0
  FL[3] = eax;  // @112_6593e0
  PV[4] = (u32)(eax);  // @113_6593e0
  ecx = (u32)(edi - 72);  // @114_6593e0
  eax = ext_4de4b0_fastcall3(ecx, edx, PV[4]);  // @115_6593e0
  ecx = edx = 0;  // @116_6593e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 40), sizeof v); (u32)v; });  // @117_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @118_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 92), &v, sizeof v); }  // @119_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @120_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @121_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 88), &v, sizeof v); }  // @122_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @123_6593e0
  FL[0] = eax; FL[1] = (u32)(3);  // @124_6593e0
  if (FL[0] > FL[1]) goto L659a54;  // @125_6593e0
  switch (eax) {  // @126_6593e0
  case 0: goto L659653;  // @127_6593e0
  case 1: goto L65956d;  // @128_6593e0
  case 2: goto L65989d;  // @129_6593e0
  case 3: goto L659751;  // @130_6593e0
  default: __builtin_trap(); }  // @131_6593e0
  L65956d:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; });  // @133_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @134_6593e0
  X1[1] = 0;  // @135_6593e0
  X1[2] = 0;  // @136_6593e0
  X1[3] = 0;  // @137_6593e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6827704) + 0), 4); v; })));  // @138_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @139_6593e0
  X0[0] = F2U((float)(s32)X0[0]);  // @140_6593e0
  X0[1] = F2U((float)(s32)X0[1]);  // @141_6593e0
  X0[2] = F2U((float)(s32)X0[2]);  // @142_6593e0
  X0[3] = F2U((float)(s32)X0[3]);  // @143_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @144_6593e0
  __builtin_memcpy((void *)((u32)(edi - 36) + 0), &X0[0], 4);  // @145_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @146_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @147_6593e0
  X0[0] = F2U((float)(s32)X0[0]);  // @148_6593e0
  X0[1] = F2U((float)(s32)X0[1]);  // @149_6593e0
  X0[2] = F2U((float)(s32)X0[2]);  // @150_6593e0
  X0[3] = F2U((float)(s32)X0[3]);  // @151_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @152_6593e0
  __builtin_memcpy((void *)((u32)(edi - 32) + 0), &X0[0], 4);  // @153_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @154_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @155_6593e0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @156_6593e0
  eax = (eax >> (u32)(31));  // @157_6593e0
  FL[3] = eax;  // @158_6593e0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @159_6593e0
  eax = (u32)(4096);  // @160_6593e0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @161_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @162_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820736) + 0), 4); v; });  // @163_6593e0
  X1[1] = 0;  // @164_6593e0
  X1[2] = 0;  // @165_6593e0
  X1[3] = 0;  // @166_6593e0
  __builtin_memcpy((void *)((u32)(edi - 28) + 0), &X0[0], 4);  // @167_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 6), &v, sizeof v); }  // @168_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 36) + 0), 4); v; });  // @169_6593e0
  X0[1] = 0;  // @170_6593e0
  X0[2] = 0;  // @171_6593e0
  X0[3] = 0;  // @172_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @173_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @174_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 8), &v, sizeof v); }  // @175_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 32) + 0), 4); v; });  // @176_6593e0
  X0[1] = 0;  // @177_6593e0
  X0[2] = 0;  // @178_6593e0
  X0[3] = 0;  // @179_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @180_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @181_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 10), &v, sizeof v); }  // @182_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 28) + 0), 4); v; });  // @183_6593e0
  X0[1] = 0;  // @184_6593e0
  X0[2] = 0;  // @185_6593e0
  X0[3] = 0;  // @186_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @187_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @188_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 12), &v, sizeof v); }  // @189_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @190_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @191_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @192_6593e0
  X0[1] = 0;  // @193_6593e0
  X0[2] = 0;  // @194_6593e0
  X0[3] = 0;  // @195_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @196_6593e0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @197_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @198_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @199_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @200_6593e0
  X0[1] = 0;  // @201_6593e0
  X0[2] = 0;  // @202_6593e0
  X0[3] = 0;  // @203_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @204_6593e0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @205_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @206_6593e0
  X1[1] = 0;  // @207_6593e0
  X1[2] = 0;  // @208_6593e0
  X1[3] = 0;  // @209_6593e0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; })));  // @210_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @211_6593e0
  X0[1] = 0;  // @212_6593e0
  X0[2] = 0;  // @213_6593e0
  X0[3] = 0;  // @214_6593e0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @215_6593e0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X0[0], 4);  // @216_6593e0
  goto L659a54;  // @217_6593e0
  L659653:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; });  // @219_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @220_6593e0
  X1[1] = 0;  // @221_6593e0
  X1[2] = 0;  // @222_6593e0
  X1[3] = 0;  // @223_6593e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6827704) + 0), 4); v; })));  // @224_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @225_6593e0
  X0[0] = F2U((float)(s32)X0[0]);  // @226_6593e0
  X0[1] = F2U((float)(s32)X0[1]);  // @227_6593e0
  X0[2] = F2U((float)(s32)X0[2]);  // @228_6593e0
  X0[3] = F2U((float)(s32)X0[3]);  // @229_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @230_6593e0
  __builtin_memcpy((void *)((u32)(edi - 36) + 0), &X0[0], 4);  // @231_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @232_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @233_6593e0
  X0[0] = F2U((float)(s32)X0[0]);  // @234_6593e0
  X0[1] = F2U((float)(s32)X0[1]);  // @235_6593e0
  X0[2] = F2U((float)(s32)X0[2]);  // @236_6593e0
  X0[3] = F2U((float)(s32)X0[3]);  // @237_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @238_6593e0
  __builtin_memcpy((void *)((u32)(edi - 32) + 0), &X0[0], 4);  // @239_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @240_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @241_6593e0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @242_6593e0
  eax = (eax >> (u32)(31));  // @243_6593e0
  FL[3] = eax;  // @244_6593e0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @245_6593e0
  eax = (u32)(4096);  // @246_6593e0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @247_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @248_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820736) + 0), 4); v; });  // @249_6593e0
  X1[1] = 0;  // @250_6593e0
  X1[2] = 0;  // @251_6593e0
  X1[3] = 0;  // @252_6593e0
  __builtin_memcpy((void *)((u32)(edi - 28) + 0), &X0[0], 4);  // @253_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 6), &v, sizeof v); }  // @254_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 36) + 0), 4); v; });  // @255_6593e0
  X0[1] = 0;  // @256_6593e0
  X0[2] = 0;  // @257_6593e0
  X0[3] = 0;  // @258_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @259_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @260_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 8), &v, sizeof v); }  // @261_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 32) + 0), 4); v; });  // @262_6593e0
  X0[1] = 0;  // @263_6593e0
  X0[2] = 0;  // @264_6593e0
  X0[3] = 0;  // @265_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @266_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @267_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 10), &v, sizeof v); }  // @268_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 28) + 0), 4); v; });  // @269_6593e0
  X0[1] = 0;  // @270_6593e0
  X0[2] = 0;  // @271_6593e0
  X0[3] = 0;  // @272_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @273_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @274_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 12), &v, sizeof v); }  // @275_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @276_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @277_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @278_6593e0
  X0[1] = 0;  // @279_6593e0
  X0[2] = 0;  // @280_6593e0
  X0[3] = 0;  // @281_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @282_6593e0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @283_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @284_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @285_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @286_6593e0
  X0[1] = 0;  // @287_6593e0
  X0[2] = 0;  // @288_6593e0
  X0[3] = 0;  // @289_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @290_6593e0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @291_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @292_6593e0
  X1[1] = 0;  // @293_6593e0
  X1[2] = 0;  // @294_6593e0
  X1[3] = 0;  // @295_6593e0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; })));  // @296_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @297_6593e0
  X0[1] = 0;  // @298_6593e0
  X0[2] = 0;  // @299_6593e0
  X0[3] = 0;  // @300_6593e0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @301_6593e0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X0[0], 4);  // @302_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @303_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @304_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @305_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @306_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @307_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @308_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @309_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @310_6593e0
  goto L659a54;  // @311_6593e0
  L659751:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; });  // @313_6593e0
  edx = (u32)((EBP - 136) + 72);  // @314_6593e0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @315_6593e0
  X3[1] = 0;  // @316_6593e0
  X3[2] = 0;  // @317_6593e0
  X3[3] = 0;  // @318_6593e0
  ecx = (u32)(edi - 24);  // @319_6593e0
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6827704) + 0), 4); v; })));  // @320_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @321_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @322_6593e0
  X0[0] = F2U((float)(s32)X0[0]);  // @323_6593e0
  X0[1] = F2U((float)(s32)X0[1]);  // @324_6593e0
  X0[2] = F2U((float)(s32)X0[2]);  // @325_6593e0
  X0[3] = F2U((float)(s32)X0[3]);  // @326_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @327_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 136) + 72) + 0), &X0[0], 4);  // @328_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @329_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @330_6593e0
  X0[0] = F2U((float)(s32)X0[0]);  // @331_6593e0
  X0[1] = F2U((float)(s32)X0[1]);  // @332_6593e0
  X0[2] = F2U((float)(s32)X0[2]);  // @333_6593e0
  X0[3] = F2U((float)(s32)X0[3]);  // @334_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @335_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 136) + 76) + 0), &X0[0], 4);  // @336_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @337_6593e0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @338_6593e0
  eax = (eax >> (u32)(31));  // @339_6593e0
  FL[3] = eax;  // @340_6593e0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @341_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 26), sizeof v); (u32)v; });  // @342_6593e0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @343_6593e0
  X2[0] = eax; X2[1] = X2[2] = X2[3] = 0;  // @344_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @345_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @346_6593e0
  X2[0] = F2U((float)(s32)X2[0]);  // @347_6593e0
  X2[1] = F2U((float)(s32)X2[1]);  // @348_6593e0
  X2[2] = F2U((float)(s32)X2[2]);  // @349_6593e0
  X2[3] = F2U((float)(s32)X2[3]);  // @350_6593e0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @351_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @352_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 136) + 80) + 0), &X0[0], 4);  // @353_6593e0
  X1[0] = F2U((float)(s32)X1[0]);  // @354_6593e0
  X1[1] = F2U((float)(s32)X1[1]);  // @355_6593e0
  X1[2] = F2U((float)(s32)X1[2]);  // @356_6593e0
  X1[3] = F2U((float)(s32)X1[3]);  // @357_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @358_6593e0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @359_6593e0
  eax = (eax >> (u32)(31));  // @360_6593e0
  FL[3] = eax;  // @361_6593e0
  X2[0] = F2U(U2F(X2[0]) * U2F(X3[0]));  // @362_6593e0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @363_6593e0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @364_6593e0
  eax = (u32)((EBP - 136) + 60);  // @365_6593e0
  PV[5] = (u32)(eax);  // @366_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 140) + 64) + 0), &X2[0], 4);  // @367_6593e0
  __builtin_memcpy((void *)((u32)(edi - 36) + 0), &X2[0], 4);  // @368_6593e0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @369_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 140) + 68) + 0), &X1[0], 4);  // @370_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @371_6593e0
  __builtin_memcpy((void *)((u32)(edi - 32) + 0), &X1[0], 4);  // @372_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 140) + 72) + 0), &X0[0], 4);  // @373_6593e0
  __builtin_memcpy((void *)((u32)(edi - 28) + 0), &X0[0], 4);  // @374_6593e0
  eax = ext_43e920_fastcall3(ecx, edx, PV[5]);  // @375_6593e0
  ecx = edx = 0;  // @376_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820736) + 0), 4); v; });  // @377_6593e0
  X1[1] = 0;  // @378_6593e0
  X1[2] = 0;  // @379_6593e0
  X1[3] = 0;  // @380_6593e0
  ecx = (u32)(4096);  // @381_6593e0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 6), &v, sizeof v); }  // @382_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 36) + 0), 4); v; });  // @383_6593e0
  X0[1] = 0;  // @384_6593e0
  X0[2] = 0;  // @385_6593e0
  X0[3] = 0;  // @386_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @387_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @388_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 8), &v, sizeof v); }  // @389_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 32) + 0), 4); v; });  // @390_6593e0
  X0[1] = 0;  // @391_6593e0
  X0[2] = 0;  // @392_6593e0
  X0[3] = 0;  // @393_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @394_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @395_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 10), &v, sizeof v); }  // @396_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 28) + 0), 4); v; });  // @397_6593e0
  X0[1] = 0;  // @398_6593e0
  X0[2] = 0;  // @399_6593e0
  X0[3] = 0;  // @400_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @401_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @402_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 12), &v, sizeof v); }  // @403_6593e0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 2), &v, sizeof v); }  // @404_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 24) + 0), 4); v; });  // @405_6593e0
  X0[1] = 0;  // @406_6593e0
  X0[2] = 0;  // @407_6593e0
  X0[3] = 0;  // @408_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @409_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @410_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @411_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 20) + 0), 4); v; });  // @412_6593e0
  X0[1] = 0;  // @413_6593e0
  X0[2] = 0;  // @414_6593e0
  X0[3] = 0;  // @415_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @416_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @417_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 2), &v, sizeof v); }  // @418_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 16) + 0), 4); v; });  // @419_6593e0
  X0[1] = 0;  // @420_6593e0
  X0[2] = 0;  // @421_6593e0
  X0[3] = 0;  // @422_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @423_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @424_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 4), &v, sizeof v); }  // @425_6593e0
  goto L659a54;  // @426_6593e0
  L65989d:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; });  // @428_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @429_6593e0
  X1[1] = 0;  // @430_6593e0
  X1[2] = 0;  // @431_6593e0
  X1[3] = 0;  // @432_6593e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6827704) + 0), 4); v; })));  // @433_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @434_6593e0
  X0[0] = F2U((float)(s32)X0[0]);  // @435_6593e0
  X0[1] = F2U((float)(s32)X0[1]);  // @436_6593e0
  X0[2] = F2U((float)(s32)X0[2]);  // @437_6593e0
  X0[3] = F2U((float)(s32)X0[3]);  // @438_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @439_6593e0
  __builtin_memcpy((void *)((u32)(edi - 36) + 0), &X0[0], 4);  // @440_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @441_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @442_6593e0
  X0[0] = F2U((float)(s32)X0[0]);  // @443_6593e0
  X0[1] = F2U((float)(s32)X0[1]);  // @444_6593e0
  X0[2] = F2U((float)(s32)X0[2]);  // @445_6593e0
  X0[3] = F2U((float)(s32)X0[3]);  // @446_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @447_6593e0
  __builtin_memcpy((void *)((u32)(edi - 32) + 0), &X0[0], 4);  // @448_6593e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @449_6593e0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @450_6593e0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @451_6593e0
  eax = (eax >> (u32)(31));  // @452_6593e0
  FL[3] = eax;  // @453_6593e0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @454_6593e0
  eax = (u32)(4096);  // @455_6593e0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @456_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @457_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820736) + 0), 4); v; });  // @458_6593e0
  X1[1] = 0;  // @459_6593e0
  X1[2] = 0;  // @460_6593e0
  X1[3] = 0;  // @461_6593e0
  __builtin_memcpy((void *)((u32)(edi - 28) + 0), &X0[0], 4);  // @462_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 6), &v, sizeof v); }  // @463_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 36) + 0), 4); v; });  // @464_6593e0
  X0[1] = 0;  // @465_6593e0
  X0[2] = 0;  // @466_6593e0
  X0[3] = 0;  // @467_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @468_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @469_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 8), &v, sizeof v); }  // @470_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 32) + 0), 4); v; });  // @471_6593e0
  X0[1] = 0;  // @472_6593e0
  X0[2] = 0;  // @473_6593e0
  X0[3] = 0;  // @474_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @475_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @476_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 10), &v, sizeof v); }  // @477_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 28) + 0), 4); v; });  // @478_6593e0
  X0[1] = 0;  // @479_6593e0
  X0[2] = 0;  // @480_6593e0
  X0[3] = 0;  // @481_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @482_6593e0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @483_6593e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi - 12), &v, sizeof v); }  // @484_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @485_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @486_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @487_6593e0
  X0[1] = 0;  // @488_6593e0
  X0[2] = 0;  // @489_6593e0
  X0[3] = 0;  // @490_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @491_6593e0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @492_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @493_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @494_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @495_6593e0
  X0[1] = 0;  // @496_6593e0
  X0[2] = 0;  // @497_6593e0
  X0[3] = 0;  // @498_6593e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @499_6593e0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @500_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @501_6593e0
  X1[1] = 0;  // @502_6593e0
  X1[2] = 0;  // @503_6593e0
  X1[3] = 0;  // @504_6593e0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; })));  // @505_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @506_6593e0
  X0[1] = 0;  // @507_6593e0
  X0[2] = 0;  // @508_6593e0
  X0[3] = 0;  // @509_6593e0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @510_6593e0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X0[0], 4);  // @511_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @512_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @513_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @514_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @515_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @516_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @517_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @518_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @519_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; });  // @520_6593e0
  X0[1] = 0;  // @521_6593e0
  X0[2] = 0;  // @522_6593e0
  X0[3] = 0;  // @523_6593e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @524_6593e0
  { double r_ = ext_634dac_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @525_6593e0
  ecx = edx = 0;  // @526_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 136) + 40) + 0), &X0[0], 4);  // @527_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 136) + 40) + 4), &X0[1], 4);  // @528_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; });  // @529_6593e0
  X0[1] = 0;  // @530_6593e0
  X0[2] = 0;  // @531_6593e0
  X0[3] = 0;  // @532_6593e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @533_6593e0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @534_6593e0
  ecx = edx = 0;  // @535_6593e0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 136) + 40) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 136) + 40) + 4), 4); v; })));  // @536_6593e0
  { double r_ = ext_634de2_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @537_6593e0
  ecx = edx = 0;  // @538_6593e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @539_6593e0
  SD(&X0[0], (double)U2F(X0[0]));  // @540_6593e0
  { double r_ = ext_634dac_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @541_6593e0
  ecx = edx = 0;  // @542_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @543_6593e0
  X1[1] = 0;  // @544_6593e0
  X1[2] = 0;  // @545_6593e0
  X1[3] = 0;  // @546_6593e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @547_6593e0
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @548_6593e0
  __builtin_memcpy((void *)((u32)(edi + 40) + 0), &X1[0], 4);  // @549_6593e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; })));  // @550_6593e0
  __builtin_memcpy((void *)((u32)(edi + 44) + 0), &X1[0], 4);  // @551_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; });  // @552_6593e0
  X0[1] = 0;  // @553_6593e0
  X0[2] = 0;  // @554_6593e0
  X0[3] = 0;  // @555_6593e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @556_6593e0
  { double r_ = ext_634dac_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @557_6593e0
  ecx = edx = 0;  // @558_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @559_6593e0
  X1[1] = 0;  // @560_6593e0
  X1[2] = 0;  // @561_6593e0
  X1[3] = 0;  // @562_6593e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @563_6593e0
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @564_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 40) + 0), 4); v; });  // @565_6593e0
  X0[1] = 0;  // @566_6593e0
  X0[2] = 0;  // @567_6593e0
  X0[3] = 0;  // @568_6593e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @569_6593e0
  __builtin_memcpy((void *)((u32)((EBP - 136) + 40) + 0), &X1[0], 4);  // @570_6593e0
  { double r_ = ext_634dac_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @571_6593e0
  ecx = edx = 0;  // @572_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 136) + 40) + 0), 4); v; });  // @573_6593e0
  X1[1] = 0;  // @574_6593e0
  X1[2] = 0;  // @575_6593e0
  X1[3] = 0;  // @576_6593e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @577_6593e0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @578_6593e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @579_6593e0
  X0[1] = 0;  // @580_6593e0
  X0[2] = 0;  // @581_6593e0
  X0[3] = 0;  // @582_6593e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @583_6593e0
  __builtin_memcpy((void *)((u32)(edi + 48) + 0), &X1[0], 4);  // @584_6593e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 0), 4); v; }); X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 4), 4); v; }); X1[2] = X1[3] = 0;  // @585_6593e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @586_6593e0
  SD(&X1[0], U2D(X1[0], X1[1]) / U2D(X0[0], X0[1]));  // @587_6593e0
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @588_6593e0
  __builtin_memcpy((void *)((u32)(edi + 52) + 0), &X0[0], 4);  // @589_6593e0
  L659a54:;
  ecx = (u32)(edi - 508);  // @591_6593e0
  eax = ext_6590e0_thiscall1(ecx);  // @592_6593e0
  ecx = edx = 0;  // @593_6593e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 36), sizeof v); (u32)v; });  // @594_6593e0
  edi = (edi + (u32)(576));  // @595_6593e0
  FL[3] = edi;  // @596_6593e0
  ecx = (ecx + 1);  // @597_6593e0
  FL[3] = ecx;  // @598_6593e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 136) + 20), &v, sizeof v); }  // @599_6593e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 136) + 36), &v, sizeof v); }  // @600_6593e0
  FL[0] = ecx; FL[1] = (u32)(12);  // @601_6593e0
  if (FL[0] == FL[1]) goto L659a90;  // @602_6593e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 16), sizeof v); (u32)v; });  // @603_6593e0
  esi = edi;  // @604_6593e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 28), sizeof v); (u32)v; });  // @605_6593e0
  eax = (eax + 1);  // @606_6593e0
  FL[3] = eax;  // @607_6593e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 136) + 16), &v, sizeof v); }  // @608_6593e0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 24), sizeof v); (u32)v; });  // @609_6593e0
  if (FL[0] < FL[1]) goto L6594f3;  // @610_6593e0
  L659a90:;
  eax = ecx;  // @612_6593e0
  ext_633654(G(u32, 0x6f5630));  // @613_6593e0
  return eax;  // @614_6593e0
}
PCREG(6593e0, lifted_6593e0);

