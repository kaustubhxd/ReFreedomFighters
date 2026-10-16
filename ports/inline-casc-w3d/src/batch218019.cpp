// batch218019.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_472fd0_thiscall1(u32) __asm__("ext_472fd0");
extern "C" u32 THISCALL ext_48b530_thiscall3(u32, u32, u32) __asm__("ext_48b530");
extern "C" u32 THISCALL ext_49d220_thiscall4(u32, u32, u32, u32) __asm__("ext_49d220");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4d6400_thiscall1(u32) __asm__("ext_4d6400");
extern "C" u32 THISCALL ext_4d6a10_thiscall2(u32, u32) __asm__("ext_4d6a10");
extern "C" u32 THISCALL ext_4d6c60_thiscall1(u32) __asm__("ext_4d6c60");
extern "C" u32 THISCALL ext_4d8ce0_thiscall2(u32, u32) __asm__("ext_4d8ce0");
extern "C" u32 THISCALL ext_4da6d0_thiscall1(u32) __asm__("ext_4da6d0");
extern "C" u32 THISCALL ext_57c500_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_57c500");
extern "C" u32 THISCALL ext_57c910_thiscall2(u32, u32) __asm__("ext_57c910");
extern "C" u32 THISCALL ext_57d780_thiscall1(u32) __asm__("ext_57d780");
extern "C" u32 THISCALL ext_57d950_thiscall2(u32, u32) __asm__("ext_57d950");
extern "C" u32 THISCALL ext_57ee90_thiscall1(u32) __asm__("ext_57ee90");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5acad0_thiscall3(u32, u32, u32) __asm__("ext_5acad0");
extern "C" u32 THISCALL ext_5ebae0_thiscall2(u32, u32) __asm__("ext_5ebae0");
extern "C" u32 THISCALL ext_5ec720_thiscall2(u32, u32) __asm__("ext_5ec720");
extern "C" u32 THISCALL ext_5ed460_thiscall1(u32) __asm__("ext_5ed460");
extern "C" u32 THISCALL ext_5edd80_thiscall2(u32, u32) __asm__("ext_5edd80");
extern "C" u32 THISCALL ext_5eec40_thiscall1(u32) __asm__("ext_5eec40");
extern "C" u32 THISCALL ext_5ef080_thiscall1(u32) __asm__("ext_5ef080");
extern "C" u32 THISCALL ext_5efd10_thiscall1(u32) __asm__("ext_5efd10");
extern "C" u32 THISCALL ext_5f0020_thiscall1(u32) __asm__("ext_5f0020");
extern "C" u32 THISCALL ext_5fe3b0_thiscall3(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 THISCALL ext_5fe920_thiscall3(u32, u32, u32) __asm__("ext_5fe920");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42ab0d_cdecl6(...) __asm__("ext_42ab0d");
extern "C" u32 ext_4a2f90_cdecl0(void) __asm__("ext_4a2f90");
extern "C" u32 ext_5fa630_cdecl0(void) __asm__("ext_5fa630");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)









extern "C" u32 THISCALL lifted_5c0a60(u32 ecx_in) {
  SEH_ENTER(0x66c588);  // @h_5c0a60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5c0a60
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5c0a60
  eax = ext_469870_thiscall1(ecx);  // @2_5c0a60
  ecx = edx = 0;  // @3_5c0a60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5c0a60
  { u32 v = (u32)((u32)(7027184)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5c0a60
  edi = (u32)(esi + 256);  // @7_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @8_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 224), &v, sizeof v); }  // @9_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @11_5c0a60
  reg.state = (s32)((u32)(0));  // @12_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027368), (u32)(0), (u32)(7027316), (u32)(61));  // @14_5c0a60
  ecx = edx = 0;  // @15_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422728), &v, sizeof v); }  // @16_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968644), (u32)(0), (u32)(7027316), (u32)(62));  // @20_5c0a60
  ecx = edx = 0;  // @21_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422732), &v, sizeof v); }  // @22_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968584), (u32)(0), (u32)(7027316), (u32)(63));  // @26_5c0a60
  ecx = edx = 0;  // @27_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422736), &v, sizeof v); }  // @28_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027380), (u32)(0), (u32)(7027316), (u32)(64));  // @32_5c0a60
  ecx = edx = 0;  // @33_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422740), &v, sizeof v); }  // @34_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968508), (u32)(0), (u32)(7027316), (u32)(65));  // @38_5c0a60
  ecx = edx = 0;  // @39_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422744), &v, sizeof v); }  // @40_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @42_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027400), (u32)(0), (u32)(7027316), (u32)(66));  // @44_5c0a60
  ecx = edx = 0;  // @45_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422748), &v, sizeof v); }  // @46_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @48_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027416), (u32)(0), (u32)(7027316), (u32)(67));  // @50_5c0a60
  ecx = edx = 0;  // @51_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422752), &v, sizeof v); }  // @52_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @54_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027432), (u32)(0), (u32)(7027316), (u32)(68));  // @56_5c0a60
  ecx = edx = 0;  // @57_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422756), &v, sizeof v); }  // @58_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_5c0a60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @60_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_5c0a60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027452), (u32)(0), (u32)(7027316), (u32)(69));  // @62_5c0a60
  ecx = edx = 0;  // @63_5c0a60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422760), &v, sizeof v); }  // @64_5c0a60
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @65_5c0a60
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @66_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 228), &v, sizeof v); }  // @67_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 236), &v, sizeof v); }  // @68_5c0a60
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 240), &v, sizeof v); }  // @69_5c0a60
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @70_5c0a60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @71_5c0a60
  X1[1] = 0;  // @72_5c0a60
  X1[2] = 0;  // @73_5c0a60
  X1[3] = 0;  // @74_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @75_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @76_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @77_5c0a60
  eax = (eax - (u32)(5120));  // @78_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @79_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @80_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @81_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @82_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @83_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @84_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @85_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 148) + 0), &X0[0], 4);  // @86_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @87_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @88_5c0a60
  eax = (eax - (u32)(5120));  // @89_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @90_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @91_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @92_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @93_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @94_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @95_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @96_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 156) + 0), &X0[0], 4);  // @97_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @98_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @99_5c0a60
  eax = (eax - (u32)(5120));  // @100_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @101_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @102_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @103_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @104_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @105_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @106_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @107_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 164) + 0), &X0[0], 4);  // @108_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @110_5c0a60
  eax = (eax - (u32)(5120));  // @111_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @112_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @113_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @114_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @115_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @116_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @117_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @118_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 172) + 0), &X0[0], 4);  // @119_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @120_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @121_5c0a60
  eax = (eax - (u32)(5120));  // @122_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @123_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @124_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @125_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @126_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @127_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @128_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @129_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 180) + 0), &X0[0], 4);  // @130_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @131_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @132_5c0a60
  eax = (eax - (u32)(5120));  // @133_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 192), &v, sizeof v); }  // @134_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @135_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @136_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @137_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @138_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @139_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @140_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 188) + 0), &X0[0], 4);  // @141_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @142_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @143_5c0a60
  eax = (eax - (u32)(5120));  // @144_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 200), &v, sizeof v); }  // @145_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @146_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @147_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @148_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @149_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @150_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @151_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 196) + 0), &X0[0], 4);  // @152_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @153_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @154_5c0a60
  eax = (eax - (u32)(5120));  // @155_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 208), &v, sizeof v); }  // @156_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @157_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @158_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @159_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @160_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @161_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @162_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 204) + 0), &X0[0], 4);  // @163_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @164_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @165_5c0a60
  eax = (eax - (u32)(5120));  // @166_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 216), &v, sizeof v); }  // @167_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @168_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @169_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @170_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @171_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @172_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @173_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 212) + 0), &X0[0], 4);  // @174_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @175_5c0a60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @176_5c0a60
  eax = (eax - (u32)(5120));  // @177_5c0a60
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @178_5c0a60
  eax = (u32)(EBP - 20);  // @179_5c0a60
  X0[0] = F2U((float)(s32)X0[0]);  // @180_5c0a60
  X0[1] = F2U((float)(s32)X0[1]);  // @181_5c0a60
  X0[2] = F2U((float)(s32)X0[2]);  // @182_5c0a60
  X0[3] = F2U((float)(s32)X0[3]);  // @183_5c0a60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @184_5c0a60
  __builtin_memcpy((void *)((u32)(esi + 220) + 0), &X0[0], 4);  // @185_5c0a60
  if (edi == eax) goto L5c0e0d;  // @186_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @187_5c0a60
  L5c0e0d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 232), &v, sizeof v); }  // @189_5c0a60
  eax = esi;  // @190_5c0a60
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 260), &v, sizeof v); }  // @191_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 264), &v, sizeof v); }  // @192_5c0a60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @193_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 269), &v, sizeof v); }  // @194_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 273), &v, sizeof v); }  // @195_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 277), &v, sizeof v); }  // @196_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 281), &v, sizeof v); }  // @197_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 136), &v, sizeof v); }  // @198_5c0a60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @199_5c0a60
  { u32 v = (u32)((u32)(1028443341)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @200_5c0a60
  { u32 v = (u32)((u32)(16777215)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @201_5c0a60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 262), &v, sizeof v); }  // @202_5c0a60
  SEH_LEAVE();  // @203_5c0a60
  return eax;  // @204_5c0a60
}
PCREG(5c0a60, lifted_5c0a60);




