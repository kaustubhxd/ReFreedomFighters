// batch242033.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_4e2120_fastcall2(u32, u32) __asm__("ext_4e2120");
extern "C" u32 THISCALL ext_44b610_thiscall1(u32) __asm__("ext_44b610");
extern "C" u32 THISCALL ext_4681d0_thiscall1(u32) __asm__("ext_4681d0");
extern "C" u32 THISCALL ext_581870_thiscall4(u32, u32, u32, u32) __asm__("ext_581870");
extern "C" u32 THISCALL ext_582aa0_thiscall1(u32) __asm__("ext_582aa0");
extern "C" u32 ext_44b740_cdecl1(...) __asm__("ext_44b740");
extern "C" u32 ext_634dca_cdecl0(void) __asm__("ext_634dca");
extern "C" u32 ext_634dca_cdecl2(...) __asm__("ext_634dca");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_583b80(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(64)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_583b80
  edi = ecx;  // @1_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @2_583b80
  X0[0] = F2U((float)(s32)X0[0]);  // @3_583b80
  X0[1] = F2U((float)(s32)X0[1]);  // @4_583b80
  X0[2] = F2U((float)(s32)X0[2]);  // @5_583b80
  X0[3] = F2U((float)(s32)X0[3]);  // @6_583b80
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 264) + 112), &v, sizeof v); }  // @7_583b80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @8_583b80
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @9_583b80
  __builtin_memcpy((void *)((u32)((EBP - 264) + 104) + 0), &X0[0], 4);  // @10_583b80
  __builtin_memcpy((void *)((u32)((EBP - 264) + 104) + 4), &X0[1], 4);  // @11_583b80
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 264) + 104)) : "st");  // @12_583b80
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[0] = (u32)v_; PV[1] = (u32)(v_ >> 32); }  // @13_583b80
  eax = ext_634dca_cdecl2(PV[0], PV[1]);  // @14_583b80
    // @15_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @16_583b80
  X0[0] = F2U((float)(s32)X0[0]);  // @17_583b80
  X0[1] = F2U((float)(s32)X0[1]);  // @18_583b80
  X0[2] = F2U((float)(s32)X0[2]);  // @19_583b80
  X0[3] = F2U((float)(s32)X0[3]);  // @20_583b80
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 264) + 84)) :: "st");  // @21_583b80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @22_583b80
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @23_583b80
  __builtin_memcpy((void *)((u32)((EBP - 264) + 104) + 0), &X0[0], 4);  // @24_583b80
  __builtin_memcpy((void *)((u32)((EBP - 264) + 104) + 4), &X0[1], 4);  // @25_583b80
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 264) + 104)) : "st");  // @26_583b80
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 264))) :: "st");  // @27_583b80
  { u32 lo_ = *(u32 *)(u32)(EBP - 264), hi_ = *(u32 *)(u32)(EBP - 260); eax = ext_634dca_cdecl2(lo_, hi_); }   // hand fix: the double was stored into the reserved slot, the lifter dropped the argument  // @28_583b80
    // @29_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @30_583b80
  ecx = (u32)(1);  // @31_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; });  // @32_583b80
  X0[1] = 0;  // @33_583b80
  X0[2] = 0;  // @34_583b80
  X0[3] = 0;  // @35_583b80
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 256) + 80)) :: "st");  // @36_583b80
  __builtin_memcpy((void *)((u32)((EBP - 256) + 96) + 0), &X0[0], 4);  // @37_583b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11281), sizeof v); (u32)v; });  // @38_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1872), sizeof v); (u32)v; });  // @39_583b80
  FL[0] = eax; FL[1] = ecx;  // @40_583b80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 256) + 64), &v, sizeof v); }  // @41_583b80
  if (FL[0] > FL[1]) eax = ecx;  // @42_583b80
  FL[2] = (eax & eax);  // @43_583b80
  if (FL[2] == 0) goto L58416f;  // @44_583b80
  L583c33:;
  eax = (eax - 1);  // @46_583b80
  FL[3] = eax;  // @47_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 256) + 88), &v, sizeof v); }  // @48_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1872), sizeof v); (u32)v; });  // @49_583b80
  eax = (eax + (u32)(469));  // @50_583b80
  FL[3] = eax;  // @51_583b80
  eax = (u32)(edi + eax*4);  // @52_583b80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2644), sizeof v); (u32)v; }); FL[1] = eax;  // @53_583b80
  if (FL[0] != FL[1]) goto L583c5a;  // @54_583b80
  eax = (u32)(edi + 1876);  // @55_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2644), &v, sizeof v); }  // @56_583b80
  L583c5a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2644), sizeof v); (u32)v; });  // @58_583b80
  PV[2] = (u32)(ecx);  // @59_583b80
  ecx = (u32)((EBP - 260) + 196);  // @60_583b80
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @61_583b80
  eax = (eax + (u32)(4));  // @62_583b80
  FL[3] = eax;  // @63_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2644), &v, sizeof v); }  // @64_583b80
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 260) + 56), &v, sizeof v); }  // @65_583b80
  eax = (u32)(ebx + 12);  // @66_583b80
  edx = eax;  // @67_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 260) + 64), &v, sizeof v); }  // @68_583b80
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1075838976));  // @69_583b80
    // @70_583b80
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 192) + 0), 4); v; });  // @71_583b80
  X1[1] = 0;  // @72_583b80
  X1[2] = 0;  // @73_583b80
  X1[3] = 0;  // @74_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 196) + 0), 4); v; });  // @75_583b80
  X0[1] = 0;  // @76_583b80
  X0[2] = 0;  // @77_583b80
  X0[3] = 0;  // @78_583b80
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @79_583b80
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @80_583b80
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @81_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 200) + 0), 4); v; });  // @82_583b80
  X0[1] = 0;  // @83_583b80
  X0[2] = 0;  // @84_583b80
  X0[3] = 0;  // @85_583b80
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @86_583b80
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @87_583b80
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @88_583b80
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @89_583b80
  ecx = edx = 0;  // @90_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @91_583b80
  ecx = (u32)((EBP - 256) + 92);  // @92_583b80
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @93_583b80
  PV[3] = (u32)(ecx);  // @94_583b80
  PV[4] = (u32)(ecx);  // @95_583b80
  ecx = esi;  // @96_583b80
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)((EBP - 268) + 104), &v, sizeof v); }  // @97_583b80
  PV[5] = X0[0];  // @98_583b80
  PV[6] = (u32)(ebx);  // @99_583b80
  __builtin_memcpy((void *)((u32)((EBP - 272) + 84) + 0), &X0[0], 4);  // @100_583b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[6], PV[5], PV[3], (u32)(-1));  // @101_583b80
  ecx = edx = 0;  // @102_583b80
  edx = eax;  // @103_583b80
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 256) + 72), &v, sizeof v); }  // @104_583b80
  FL[2] = (edx & edx);  // @105_583b80
  if (FL[2] == 0) goto L583faa;  // @106_583b80
  esi = (u32)(edi + 80);  // @107_583b80
  L583d00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_583b80
  PV[7] = (u32)(edx);  // @110_583b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @111_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_583b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @113_583b80
  ecx = edx = 0;  // @114_583b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @115_583b80
  ebx = eax;  // @116_583b80
  edx = (u32)(ecx*8);  // @117_583b80
  edx = (edx - ecx);  // @118_583b80
  FL[3] = edx;  // @119_583b80
  ecx = (u32)(edx + 20);  // @120_583b80
  ecx = (u32)(edi + ecx*4);  // @121_583b80
  FL[0] = esi; FL[1] = ecx;  // @122_583b80
  if (FL[0] == FL[1]) goto L583d4f;  // @123_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @124_583b80
  ecx = (u32)(eax*8);  // @125_583b80
  ecx = (ecx - eax);  // @126_583b80
  FL[3] = ecx;  // @127_583b80
  eax = (u32)(ecx + 20);  // @128_583b80
  eax = (u32)(edi + eax*4);  // @129_583b80
  L583d40:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = ebx;  // @131_583b80
  if (FL[0] == FL[1]) goto L583f76;  // @132_583b80
  esi = (esi + (u32)(28));  // @133_583b80
  FL[3] = esi;  // @134_583b80
  FL[0] = esi; FL[1] = eax;  // @135_583b80
  if (FL[0] != FL[1]) goto L583d40;  // @136_583b80
  L583d4f:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 72), sizeof v); (u32)v; });  // @138_583b80
  ecx = esi;  // @139_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @140_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @141_583b80
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @142_583b80
  ecx = edx = 0;  // @143_583b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @144_583b80
  if (FL[2] != 0) goto L583f76;  // @145_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_583b80
  ecx = (u32)((EBP - 256) + 228);  // @147_583b80
  PV[8] = (u32)(ecx);  // @148_583b80
  ecx = (u32)((EBP - 260) + 124);  // @149_583b80
  PV[9] = (u32)(ecx);  // @150_583b80
  ecx = esi;  // @151_583b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 900)))(ecx, PV[9], PV[8]);  // @152_583b80
  ecx = edx = 0;  // @153_583b80
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 52), sizeof v); (u32)v; });  // @154_583b80
  edx = (u32)((EBP - 260) + 232);  // @155_583b80
  ecx = (u32)((EBP - 260) + 220);  // @156_583b80
  eax = ext_43e920_fastcall3(ecx, edx, PV[10]);  // @157_583b80
  ecx = edx = 0;  // @158_583b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 52), sizeof v); (u32)v; });  // @159_583b80
  ecx = (u32)((EBP - 256) + 216);  // @160_583b80
  edx = (u32)(edx + 24);  // @161_583b80
  eax = ext_441a60_fastcall2(ecx, edx);  // @162_583b80
  ecx = edx = 0;  // @163_583b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 60), sizeof v); (u32)v; });  // @164_583b80
  ecx = (u32)((EBP - 256) + 216);  // @165_583b80
  eax = ext_4e2120_fastcall2(ecx, edx);  // @166_583b80
  ecx = edx = 0;  // @167_583b80
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 256) + 84)) :: "st");  // @168_583b80
  X0[0] = 0;  // @169_583b80
  X0[1] = 0;  // @170_583b80
  X0[2] = 0;  // @171_583b80
  X0[3] = 0;  // @172_583b80
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 84) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 84) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 84) + 0), 4); v; }))))))) goto L583de0;  // @173_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 52), sizeof v); (u32)v; });  // @174_583b80
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @175_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @176_583b80
  X0[1] = 0;  // @177_583b80
  X0[2] = 0;  // @178_583b80
  X0[3] = 0;  // @179_583b80
  PV[12] = (u32)(ecx);  // @180_583b80
  PV[13] = X0[0];  // @181_583b80
  ecx = edi;  // @182_583b80
  PV[14] = (u32)(ebx);  // @183_583b80
  eax = ext_581870_thiscall4(ecx, PV[14], PV[13], PV[11]);  // @184_583b80
  ecx = edx = 0;  // @185_583b80
  L583de0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 76) + 0), 4); v; });  // @187_583b80
  X0[1] = 0;  // @188_583b80
  X0[2] = 0;  // @189_583b80
  X0[3] = 0;  // @190_583b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @191_583b80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @192_583b80
  if (__builtin_parity(FL[2] & 0xff)) goto L583e99;  // @193_583b80
  edx = (u32)((EBP - 256) + 192);  // @194_583b80
  ecx = (u32)((EBP - 256) + 216);  // @195_583b80
  eax = ext_4e2120_fastcall2(ecx, edx);  // @196_583b80
  ecx = edx = 0;  // @197_583b80
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 256) + 84)) :: "st");  // @198_583b80
  X0[0] = 0;  // @199_583b80
  X0[1] = 0;  // @200_583b80
  X0[2] = 0;  // @201_583b80
  X0[3] = 0;  // @202_583b80
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 84) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 84) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 84) + 0), 4); v; }))))))) goto L583e99;  // @203_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 52), sizeof v); (u32)v; });  // @204_583b80
  ecx = esi;  // @205_583b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @206_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @207_583b80
  X0[1] = 0;  // @208_583b80
  X0[2] = 0;  // @209_583b80
  X0[3] = 0;  // @210_583b80
  __builtin_memcpy((void *)((u32)((EBP - 260) + 172) + 0), &X0[0], 4);  // @211_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @212_583b80
  X0[1] = 0;  // @213_583b80
  X0[2] = 0;  // @214_583b80
  X0[3] = 0;  // @215_583b80
  __builtin_memcpy((void *)((u32)((EBP - 260) + 176) + 0), &X0[0], 4);  // @216_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @217_583b80
  X0[1] = 0;  // @218_583b80
  X0[2] = 0;  // @219_583b80
  X0[3] = 0;  // @220_583b80
  eax = (u32)((EBP - 260) + 172);  // @221_583b80
  __builtin_memcpy((void *)((u32)((EBP - 260) + 180) + 0), &X0[0], 4);  // @222_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 260) + 196) + 0), 4); v; });  // @223_583b80
  X0[1] = 0;  // @224_583b80
  X0[2] = 0;  // @225_583b80
  X0[3] = 0;  // @226_583b80
  __builtin_memcpy((void *)((u32)((EBP - 260) + 184) + 0), &X0[0], 4);  // @227_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 260) + 200) + 0), 4); v; });  // @228_583b80
  X0[1] = 0;  // @229_583b80
  X0[2] = 0;  // @230_583b80
  X0[3] = 0;  // @231_583b80
  PV[15] = (u32)(eax);  // @232_583b80
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422576), sizeof v); (u32)v; });  // @233_583b80
  __builtin_memcpy((void *)((u32)((EBP - 264) + 192) + 0), &X0[0], 4);  // @234_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 208) + 0), 4); v; });  // @235_583b80
  X0[1] = 0;  // @236_583b80
  X0[2] = 0;  // @237_583b80
  X0[3] = 0;  // @238_583b80
  PV[16] = (u32)(eax);  // @239_583b80
  __builtin_memcpy((void *)((u32)((EBP - 268) + 200) + 0), &X0[0], 4);  // @240_583b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[16], PV[15], (u32)(0));  // @241_583b80
  ecx = edx = 0;  // @242_583b80
  L583e99:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @244_583b80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 7005), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @245_583b80
  if (FL[0] == FL[1]) goto L583f76;  // @246_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 52), sizeof v); (u32)v; });  // @247_583b80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }); FL[1] = ebx;  // @248_583b80
  if (FL[0] == FL[1]) goto L583f76;  // @249_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @250_583b80
  esi = (u32)(edi + 80);  // @251_583b80
  ecx = (u32)(eax*8);  // @252_583b80
  ecx = (ecx - eax);  // @253_583b80
  FL[3] = ecx;  // @254_583b80
  eax = (u32)(ecx + 20);  // @255_583b80
  eax = (u32)(edi + eax*4);  // @256_583b80
  FL[0] = esi; FL[1] = eax;  // @257_583b80
  if (FL[0] == FL[1]) goto L583f76;  // @258_583b80
  L583ed6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 155), sizeof v); (u32)v; });  // @260_583b80
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @261_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @262_583b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[17]);  // @263_583b80
  ecx = edx = 0;  // @264_583b80
  FL[2] = (eax & eax);  // @265_583b80
  if (FL[2] == 0) goto L583f52;  // @266_583b80
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 72), sizeof v); (u32)v; });  // @267_583b80
  if (FL[0] == FL[1]) goto L583f52;  // @268_583b80
  eax = (u32)(esi + 8);  // @269_583b80
  PV[18] = (u32)(eax);  // @270_583b80
  edx = (u32)((EBP - 260) + 232);  // @271_583b80
  ecx = (u32)((EBP - 260) + 112);  // @272_583b80
  eax = ext_43e920_fastcall3(ecx, edx, PV[18]);  // @273_583b80
  ecx = edx = 0;  // @274_583b80
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 108) + 0), 4); v; });  // @275_583b80
  X1[1] = 0;  // @276_583b80
  X1[2] = 0;  // @277_583b80
  X1[3] = 0;  // @278_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 112) + 0), 4); v; });  // @279_583b80
  X0[1] = 0;  // @280_583b80
  X0[2] = 0;  // @281_583b80
  X0[3] = 0;  // @282_583b80
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @283_583b80
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @284_583b80
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @285_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 116) + 0), 4); v; });  // @286_583b80
  X0[1] = 0;  // @287_583b80
  X0[2] = 0;  // @288_583b80
  X0[3] = 0;  // @289_583b80
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @290_583b80
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @291_583b80
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @292_583b80
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @293_583b80
  ecx = edx = 0;  // @294_583b80
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @295_583b80
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860564) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860564) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860564) + 0), 4); v; }))))))) goto L583f52;  // @296_583b80
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @297_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @298_583b80
  X0[1] = 0;  // @299_583b80
  X0[2] = 0;  // @300_583b80
  X0[3] = 0;  // @301_583b80
  PV[20] = (u32)(ecx);  // @302_583b80
  PV[21] = X0[0];  // @303_583b80
  ecx = edi;  // @304_583b80
  PV[22] = (u32)(ebx);  // @305_583b80
  eax = ext_581870_thiscall4(ecx, PV[22], PV[21], PV[19]);  // @306_583b80
  ecx = edx = 0;  // @307_583b80
  L583f52:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @309_583b80
  esi = (esi + (u32)(28));  // @310_583b80
  FL[3] = esi;  // @311_583b80
  ecx = (u32)(eax*8);  // @312_583b80
  ecx = (ecx - eax);  // @313_583b80
  FL[3] = ecx;  // @314_583b80
  eax = (u32)(ecx + 20);  // @315_583b80
  eax = (u32)(edi + eax*4);  // @316_583b80
  FL[0] = esi; FL[1] = eax;  // @317_583b80
  if (FL[0] == FL[1]) goto L583f76;  // @318_583b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @319_583b80
  goto L583ed6;  // @320_583b80
  L583f76:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 64), sizeof v); (u32)v; });  // @322_583b80
  edx = (u32)((EBP - 256) + 92);  // @323_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 68) + 0), 4); v; });  // @324_583b80
  X0[1] = 0;  // @325_583b80
  X0[2] = 0;  // @326_583b80
  X0[3] = 0;  // @327_583b80
  PV[23] = (u32)(edx);  // @328_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @329_583b80
  PV[24] = (u32)(ecx);  // @330_583b80
  PV[25] = X0[0];  // @331_583b80
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 268) + 64), sizeof v); (u32)v; });  // @332_583b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[26], PV[25], PV[23], (u32)(-1));  // @333_583b80
  ecx = edx = 0;  // @334_583b80
  edx = eax;  // @335_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 256) + 72), &v, sizeof v); }  // @336_583b80
  esi = (u32)(edi + 80);  // @337_583b80
  FL[2] = (edx & edx);  // @338_583b80
  if (FL[2] != 0) goto L583d00;  // @339_583b80
  L583faa:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 76) + 0), 4); v; });  // @341_583b80
  X0[1] = 0;  // @342_583b80
  X0[2] = 0;  // @343_583b80
  X0[3] = 0;  // @344_583b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @345_583b80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @346_583b80
  if (__builtin_parity(FL[2] & 0xff)) goto L584159;  // @347_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @348_583b80
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1184), sizeof v); (u32)v; });  // @349_583b80
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1188), sizeof v); (u32)v; });  // @350_583b80
  if (FL[0] == FL[1]) goto L584159;  // @351_583b80
  edi = (u32)(ebx + 4);  // @352_583b80
  L583fe0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @354_583b80
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @355_583b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @356_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @357_583b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[27]);  // @358_583b80
  ecx = edx = 0;  // @359_583b80
  esi = eax;  // @360_583b80
  FL[2] = (esi & esi);  // @361_583b80
  if (FL[2] != 0) goto L584035;  // @362_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @363_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 256) + 68), &v, sizeof v); }  // @364_583b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1188), sizeof v); (u32)v; });  // @365_583b80
  FL[0] = edi; FL[1] = edx;  // @366_583b80
  if (FL[0] == FL[1]) goto L584029;  // @367_583b80
  edx = (edx - edi);  // @368_583b80
  FL[3] = edx;  // @369_583b80
  esi = ebx;  // @370_583b80
  edx = (u32)((s32)edx >> (u32)(2));  // @371_583b80
  FL[3] = edx;  // @372_583b80
  FL[2] = (edx & edx);  // @373_583b80
  if ((s32)FL[2] <= 0) goto L584029;  // @374_583b80
  L584016:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @376_583b80
  ecx = (u32)(esi + 4);  // @377_583b80
  edx = (edx - 1);  // @378_583b80
  FL[3] = edx;  // @379_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @380_583b80
  esi = ecx;  // @381_583b80
  FL[2] = (edx & edx);  // @382_583b80
  if ((s32)FL[2] > 0) goto L584016;  // @383_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 68), sizeof v); (u32)v; });  // @384_583b80
  L584029:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1188), sizeof v); (u32)v; }) + (u32)(-4))); __builtin_memcpy((void *)(u32)(eax + 1188), &v, sizeof v); }  // @386_583b80
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1188), sizeof v); (u32)v; });  // @387_583b80
  goto L58413e;  // @388_583b80
  L584035:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 256) + 212), &v, sizeof v); }  // @390_583b80
  ecx = (u32)((EBP - 256) + 204);  // @391_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 256) + 208), &v, sizeof v); }  // @392_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 256) + 204), &v, sizeof v); }  // @393_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @394_583b80
  PV[28] = (u32)(ecx);  // @395_583b80
  ecx = esi;  // @396_583b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[28]);  // @397_583b80
  ecx = edx = 0;  // @398_583b80
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 52), sizeof v); (u32)v; });  // @399_583b80
  edx = (u32)((EBP - 260) + 208);  // @400_583b80
  ecx = (u32)((EBP - 260) + 244);  // @401_583b80
  eax = ext_43e920_fastcall3(ecx, edx, PV[29]);  // @402_583b80
  ecx = edx = 0;  // @403_583b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 60), sizeof v); (u32)v; });  // @404_583b80
  ecx = (u32)((EBP - 256) + 240);  // @405_583b80
  eax = ext_4e2120_fastcall2(ecx, edx);  // @406_583b80
  ecx = edx = 0;  // @407_583b80
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 256) + 68)) :: "st");  // @408_583b80
  X0[0] = 0;  // @409_583b80
  X0[1] = 0;  // @410_583b80
  X0[2] = 0;  // @411_583b80
  X0[3] = 0;  // @412_583b80
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 68) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 68) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 68) + 0), 4); v; }))))))) goto L58413e;  // @413_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 52), sizeof v); (u32)v; });  // @414_583b80
  ecx = esi;  // @415_583b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @416_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 260) + 128), &v, sizeof v); }  // @417_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @418_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 260) + 124), &v, sizeof v); }  // @419_583b80
  eax = (u32)((EBP - 260) + 124);  // @420_583b80
  PV[30] = (u32)(eax);  // @421_583b80
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422580), sizeof v); (u32)v; });  // @422_583b80
  PV[31] = (u32)(eax);  // @423_583b80
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)((EBP - 268) + 140), &v, sizeof v); }  // @424_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 144), &v, sizeof v); }  // @425_583b80
  { u32 v = (u32)((u32)(1106247680)); __builtin_memcpy((void *)(u32)((EBP - 268) + 172), &v, sizeof v); }  // @426_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 176), &v, sizeof v); }  // @427_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 160), &v, sizeof v); }  // @428_583b80
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 268) + 164), &v, sizeof v); }  // @429_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 168), &v, sizeof v); }  // @430_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 148), &v, sizeof v); }  // @431_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 152), &v, sizeof v); }  // @432_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 156), &v, sizeof v); }  // @433_583b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[31], PV[30], (u32)(0));  // @434_583b80
  ecx = edx = 0;  // @435_583b80
  L58413e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @437_583b80
  ebx = (ebx + (u32)(4));  // @438_583b80
  FL[3] = ebx;  // @439_583b80
  edi = (edi + (u32)(4));  // @440_583b80
  FL[3] = edi;  // @441_583b80
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1188), sizeof v); (u32)v; });  // @442_583b80
  if (FL[0] != FL[1]) goto L583fe0;  // @443_583b80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 104), sizeof v); (u32)v; });  // @444_583b80
  L584159:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 88), sizeof v); (u32)v; });  // @446_583b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 64), sizeof v); (u32)v; });  // @447_583b80
  FL[2] = (eax & eax);  // @448_583b80
  if (FL[2] != 0) goto L583c33;  // @449_583b80
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @450_583b80
  L58416f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @452_583b80
  esi = (u32)(edi + 80);  // @453_583b80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 256) + 60), &v, sizeof v); }  // @454_583b80
  ecx = (u32)(eax*8);  // @455_583b80
  ecx = (ecx - eax);  // @456_583b80
  FL[3] = ecx;  // @457_583b80
  eax = (u32)(ecx + 20);  // @458_583b80
  eax = (u32)(edi + eax*4);  // @459_583b80
  FL[0] = esi; FL[1] = eax;  // @460_583b80
  if (FL[0] == FL[1]) goto L5843af;  // @461_583b80
  L584190:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; });  // @463_583b80
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @464_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @465_583b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[32]);  // @466_583b80
  ecx = edx = 0;  // @467_583b80
  ebx = eax;  // @468_583b80
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 256) + 64), &v, sizeof v); }  // @469_583b80
  FL[2] = (ebx & ebx);  // @470_583b80
  if (FL[2] != 0) goto L5841b5;  // @471_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @472_583b80
  FL[2] = (eax & eax);  // @473_583b80
  if (FL[2] == 0) goto L5841b4;  // @474_583b80
  eax = ((u32(STDCALL *)(void))(eax))();  // @475_583b80
  ecx = edx = 0;  // @476_583b80
  goto L5841b5;  // @477_583b80
  L5841b4:;
  __builtin_trap();  // @479_583b80
  L5841b5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @481_583b80
  ecx = ebx;  // @482_583b80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 256) + 59), &v, sizeof v); }  // @483_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @484_583b80
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @485_583b80
  ecx = edx = 0;  // @486_583b80
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 59), sizeof v); (u32)v; });  // @487_583b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @488_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @489_583b80
  edx = (u32)(1);  // @490_583b80
  if (FL[2] != 0) ecx = edx;  // @491_583b80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(2098152);  // @492_583b80
  if (FL[0] != FL[1]) goto L5841f1;  // @493_583b80
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1047), sizeof v); (u32)v; }) & (u32)(201326592));  // @494_583b80
  ecx = (ecx & 0xff);  // @495_583b80
  if (FL[2] != 0) ecx = edx;  // @496_583b80
  L5841f1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @498_583b80
  X0[1] = 0;  // @499_583b80
  X0[2] = 0;  // @500_583b80
  X0[3] = 0;  // @501_583b80
  X1[0] = 0;  // @502_583b80
  X1[1] = 0;  // @503_583b80
  X1[2] = 0;  // @504_583b80
  X1[3] = 0;  // @505_583b80
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 96) + 0), 4); v; })));  // @506_583b80
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @507_583b80
  ebx = (ecx & 0xff);  // @508_583b80
  __builtin_memcpy((void *)((u32)(esi + 20) + 0), &X0[0], 4);  // @509_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @510_583b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @511_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @512_583b80
  if ((!(!(U2F(X1[0]) >= U2F(X0[0]))) && !(!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) ebx = edx;  // @513_583b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[33]);  // @514_583b80
  ecx = edx = 0;  // @515_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 256) + 88), &v, sizeof v); }  // @516_583b80
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @517_583b80
  if (FL[2] == 0) goto L5842ab;  // @518_583b80
  FL[2] = (eax & eax);  // @519_583b80
  if (FL[2] == 0) goto L584243;  // @520_583b80
  ecx = eax;  // @521_583b80
  eax = ext_44b610_thiscall1(ecx);  // @522_583b80
  ecx = edx = 0;  // @523_583b80
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 88), sizeof v); (u32)v; });  // @524_583b80
  eax = ext_44b740_cdecl1(PV[34]);  // @525_583b80
  ecx = edx = 0;  // @526_583b80
  L584243:;
  ecx = esi;  // @528_583b80
  ebx = (u32)(edi + 76);  // @529_583b80
  ecx = (ecx - ebx);  // @530_583b80
  FL[3] = ecx;  // @531_583b80
  eax = (u32)(2454267027);  // @532_583b80
  ecx = (ecx - (u32)(4));  // @533_583b80
  FL[3] = ecx;  // @534_583b80
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @535_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @536_583b80
  edx = (edx + ecx);  // @537_583b80
  FL[3] = edx;  // @538_583b80
  eax = (eax - 1);  // @539_583b80
  FL[3] = eax;  // @540_583b80
  edx = (u32)((s32)edx >> (u32)(4));  // @541_583b80
  FL[3] = edx;  // @542_583b80
  esi = edx;  // @543_583b80
  esi = (esi >> (u32)(31));  // @544_583b80
  FL[3] = esi;  // @545_583b80
  esi = (esi + edx);  // @546_583b80
  FL[3] = esi;  // @547_583b80
  FL[0] = esi; FL[1] = eax;  // @548_583b80
  if (FL[0] >= FL[1]) goto L584297;  // @549_583b80
  ecx = (u32)(esi*8);  // @550_583b80
  ecx = (ecx - esi);  // @551_583b80
  FL[3] = ecx;  // @552_583b80
  ecx = (ecx + 1);  // @553_583b80
  FL[3] = ecx;  // @554_583b80
  ecx = (u32)(ebx + ecx*4);  // @555_583b80
  L584274:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 28) + 0), 4); v; });  // @557_583b80
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 28) + 4), 4); v; });  // @558_583b80
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 28) + 8), 4); v; });  // @559_583b80
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 28) + 12), 4); v; });  // @560_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 52), sizeof v); (u32)v; });  // @561_583b80
  ecx = (u32)(ecx + 28);  // @562_583b80
  esi = (esi + 1);  // @563_583b80
  FL[3] = esi;  // @564_583b80
  __builtin_memcpy((void *)((u32)(ecx - 28) + 0), &X0[0], 4);  // @565_583b80
  __builtin_memcpy((void *)((u32)(ecx - 28) + 4), &X0[1], 4);  // @566_583b80
  __builtin_memcpy((void *)((u32)(ecx - 28) + 8), &X0[2], 4);  // @567_583b80
  __builtin_memcpy((void *)((u32)(ecx - 28) + 12), &X0[3], 4);  // @568_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 16) + 0), 4); v; });  // @569_583b80
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 16) + 4), 4); v; });  // @570_583b80
  X0[2] = 0;  // @571_583b80
  X0[3] = 0;  // @572_583b80
  __builtin_memcpy((void *)((u32)(ecx - 12) + 0), &X0[0], 4);  // @573_583b80
  __builtin_memcpy((void *)((u32)(ecx - 12) + 4), &X0[1], 4);  // @574_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @575_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @576_583b80
  eax = (eax - 1);  // @577_583b80
  FL[3] = eax;  // @578_583b80
  FL[0] = esi; FL[1] = eax;  // @579_583b80
  if (FL[0] < FL[1]) goto L584274;  // @580_583b80
  L584297:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 64), sizeof v); (u32)v; });  // @582_583b80
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @583_583b80
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @584_583b80
  eax = ext_4681d0_thiscall1(ecx);  // @585_583b80
  ecx = edx = 0;  // @586_583b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 60), sizeof v); (u32)v; });  // @587_583b80
  goto L58438f;  // @588_583b80
  L5842ab:;
  FL[2] = (eax & eax);  // @590_583b80
  if (FL[2] == 0) goto L5842d5;  // @591_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; });  // @592_583b80
  X0[1] = 0;  // @593_583b80
  X0[2] = 0;  // @594_583b80
  X0[3] = 0;  // @595_583b80
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; }))))))) goto L5842d5;  // @596_583b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 132) + 0), 4); v; });  // @597_583b80
  X0[1] = 0;  // @598_583b80
  X0[2] = 0;  // @599_583b80
  X0[3] = 0;  // @600_583b80
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818396) + 0), 4); v; })));  // @601_583b80
  __builtin_memcpy((void *)((u32)(eax + 132) + 0), &X0[0], 4);  // @602_583b80
  L5842d5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 76) + 0), 4); v; });  // @604_583b80
  X0[1] = 0;  // @605_583b80
  X0[2] = 0;  // @606_583b80
  X0[3] = 0;  // @607_583b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @608_583b80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 256) + 80) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @609_583b80
  if (__builtin_parity(FL[2] & 0xff)) goto L584385;  // @610_583b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @611_583b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 256) + 64), sizeof v); (u32)v; });  // @612_583b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 256) + 120), &v, sizeof v); }  // @613_583b80
  eax = (u32)((EBP - 256) + 120);  // @614_583b80
  PV[35] = (u32)(eax);  // @615_583b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @616_583b80
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422580), sizeof v); (u32)v; });  // @617_583b80
  PV[36] = (u32)(eax);  // @618_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 136), &v, sizeof v); }  // @619_583b80
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)((EBP - 268) + 140), &v, sizeof v); }  // @620_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 144), &v, sizeof v); }  // @621_583b80
  { u32 v = (u32)((u32)(1114636288)); __builtin_memcpy((void *)(u32)((EBP - 268) + 172), &v, sizeof v); }  // @622_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 176), &v, sizeof v); }  // @623_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 160), &v, sizeof v); }  // @624_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 164), &v, sizeof v); }  // @625_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 168), &v, sizeof v); }  // @626_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 148), &v, sizeof v); }  // @627_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 152), &v, sizeof v); }  // @628_583b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 268) + 156), &v, sizeof v); }  // @629_583b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[36], PV[35], (u32)(0));  // @630_583b80
  ecx = edx = 0;  // @631_583b80
  L584385:;
  esi = (esi + (u32)(28));  // @633_583b80
  FL[3] = esi;  // @634_583b80
  ebx = (u32)(edi + 76);  // @635_583b80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 256) + 60), &v, sizeof v); }  // @636_583b80
  L58438f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @638_583b80
  ecx = (u32)(eax*8);  // @639_583b80
  ecx = (ecx - eax);  // @640_583b80
  FL[3] = ecx;  // @641_583b80
  eax = (u32)(ecx + 1);  // @642_583b80
  eax = (u32)(ebx + eax*4);  // @643_583b80
  FL[0] = esi; FL[1] = eax;  // @644_583b80
  if (FL[0] == FL[1]) goto L5843af;  // @645_583b80
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @646_583b80
  goto L584190;  // @647_583b80
  L5843af:;
  ecx = edi;  // @649_583b80
  eax = ext_582aa0_thiscall1(ecx);  // @650_583b80
  ecx = edx = 0;  // @651_583b80
  ext_633654(G(u32, 0x6f5630));  // @652_583b80
  return eax;  // @653_583b80
}
PCREG(583b80, lifted_583b80);

