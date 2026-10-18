// batch200120.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4dfd10_fastcall2(u32, u32) __asm__("ext_4dfd10");
extern "C" u32 STDCALL ext_565360_stdcall1(u32) __asm__("ext_565360");
extern "C" u32 THISCALL ext_4519a0_thiscall4(u32, u32, u32, u32) __asm__("ext_4519a0");
extern "C" u32 THISCALL ext_456b70_thiscall3(u32, u32, u32) __asm__("ext_456b70");
extern "C" u32 THISCALL ext_4b5620_thiscall2(u32, u32) __asm__("ext_4b5620");
extern "C" u32 THISCALL ext_4c3e80_thiscall1(u32) __asm__("ext_4c3e80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1440_thiscall2(u32, u32) __asm__("ext_4e1440");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4ef660_thiscall2(u32, u32) __asm__("ext_4ef660");
extern "C" u32 THISCALL ext_562010_thiscall1(u32) __asm__("ext_562010");
extern "C" u32 THISCALL ext_562260_thiscall1(u32) __asm__("ext_562260");
extern "C" u32 THISCALL ext_564600_thiscall2(u32, u32) __asm__("ext_564600");
extern "C" u32 THISCALL ext_565100_thiscall2(u32, u32) __asm__("ext_565100");
extern "C" u32 THISCALL ext_57f960_thiscall1(u32) __asm__("ext_57f960");
extern "C" u32 THISCALL ext_57f9b0_thiscall3(u32, u32, u32) __asm__("ext_57f9b0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_64ea30(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_64ea30
  edi = ecx;  // @1_64ea30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_64ea30
  ebx = (u32)(edi + 98845);  // @3_64ea30
  ecx = (u32)(edi + 98809);  // @4_64ea30
  p0_ = ebx;  // @5_64ea30
  p1_ = ecx;  // @6_64ea30
  ecx = esi;  // @7_64ea30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, (u32)(p1_), (u32)(p0_));  // @8_64ea30
  ecx = edx = 0;  // @9_64ea30
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }) & (u32)(65536)) != 0) goto L64ea96;  // @10_64ea30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_64ea30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_64ea30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @13_64ea30
  ecx = edx = 0;  // @14_64ea30
  ecx = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(edi + 98853)));  // @15_64ea30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_64ea30
  p2_ = ecx;  // @17_64ea30
  ecx = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(edi + 98849)));  // @18_64ea30
  p3_ = ecx;  // @19_64ea30
  ecx = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(ebx)));  // @20_64ea30
  p4_ = ecx;  // @21_64ea30
  p5_ = eax;  // @22_64ea30
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 388)))((u32)(p5_), (u32)(93), (u32)(0), (u32)(7089780), (u32)(p4_), (u32)(p3_), (u32)(p2_));  // @23_64ea30
  ecx = edx = 0;  // @24_64ea30
  L64ea96:;
  esi = (u32)(edi + 98857);  // @26_64ea30
  edx = (u32)(edi + 98809);  // @27_64ea30
  ecx = esi;  // @28_64ea30
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @29_64ea30
  ecx = edx = 0;  // @30_64ea30
  p6_ = esi;  // @31_64ea30
  edx = ebx;  // @32_64ea30
  ecx = (u32)(edi + 98893);  // @33_64ea30
  eax = ext_441970_fastcall3(ecx, edx, (u32)(p6_));  // @34_64ea30
  ecx = edx = 0;  // @35_64ea30
  ecx = (u32)(edi + 98893);  // @36_64ea30
  eax = ext_4e09b0_thiscall1(ecx);  // @37_64ea30
  ecx = edx = 0;  // @38_64ea30
  __asm__ volatile("" :: "Yz"(x0));  // @39_64ea30
  return eax;  // @40_64ea30
}
PCREG(64ea30, lifted_64ea30);

extern "C" u32 THISCALL lifted_663d90(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @0_663d90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_663d90
  x0 = _mm_load_ss((const float *)(u32)(ecx + 12));  // @2_663d90
  x5 = _mm_load_ss((const float *)(u32)(ecx + 8));  // @3_663d90
  x4 = _mm_load_ss((const float *)(u32)(ecx + 20));  // @4_663d90
  x3 = _mm_load_ss((const float *)(u32)(edx + eax*4));  // @5_663d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_663d90
  x1 = _mm_load_ss((const float *)(u32)(ecx + 44));  // @7_663d90
  x0 = _mm_mul_ss(x0, x3);  // @8_663d90
  x5 = _mm_mul_ss(x5, _mm_load_ss((const float *)(u32)(edx + eax*4)));  // @9_663d90
  x4 = _mm_mul_ss(x4, _mm_load_ss((const float *)(u32)(edx + eax*4)));  // @10_663d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_663d90
  x5 = _mm_add_ss(x5, x0);  // @12_663d90
  x0 = _mm_load_ss((const float *)(u32)(ecx + 24));  // @13_663d90
  x0 = _mm_mul_ss(x0, x3);  // @14_663d90
  x5 = _mm_add_ss(x5, _mm_load_ss((const float *)(u32)(ecx + 16)));  // @15_663d90
  x4 = _mm_add_ss(x4, x0);  // @16_663d90
  x0 = _mm_load_ss((const float *)(u32)(ecx + 52));  // @17_663d90
  x5 = _mm_mul_ss(x5, _mm_load_ss((const float *)(u32)(ecx + 32)));  // @18_663d90
  x4 = _mm_add_ss(x4, _mm_load_ss((const float *)(u32)(ecx + 28)));  // @19_663d90
  x1 = _mm_mul_ss(x1, x5);  // @20_663d90
  x4 = _mm_mul_ss(x4, _mm_load_ss((const float *)(u32)(ecx + 32)));  // @21_663d90
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 36)));  // @22_663d90
  x0 = _mm_mul_ss(x0, x4);  // @23_663d90
  x1 = _mm_add_ss(x1, x0);  // @24_663d90
  _mm_store_ss((float *)(u32)(eax), x1);  // @25_663d90
  x1 = _mm_load_ss((const float *)(u32)(ecx + 48));  // @26_663d90
  x0 = _mm_load_ss((const float *)(u32)(ecx + 56));  // @27_663d90
  x1 = _mm_mul_ss(x1, x5);  // @28_663d90
  x0 = _mm_mul_ss(x0, x4);  // @29_663d90
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 40)));  // @30_663d90
  x1 = _mm_add_ss(x1, x0);  // @31_663d90
  _mm_store_ss((float *)(u32)(eax + 4), x1);  // @32_663d90
  __asm__ volatile("" :: "Yz"(x0));  // @33_663d90
  return eax;  // @34_663d90
}
PCREG(663d90, lifted_663d90);

extern "C" u32 FASTCALL lifted_6604c0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  x1 = _mm_load_ss((const float *)(u32)(ecx));  // @0_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 4));  // @1_6604c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6604c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 24)));  // @4_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 28)));  // @5_6604c0
  x1 = _mm_add_ss(x1, x0);  // @6_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 32));  // @7_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 8)));  // @8_6604c0
  x1 = _mm_add_ss(x1, x0);  // @9_6604c0
  _mm_store_ss((float *)(u32)(8466896), x1);  // @10_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx));  // @11_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 12)));  // @12_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 4));  // @13_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 16)));  // @14_6604c0
  x1 = _mm_add_ss(x1, x0);  // @15_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 8));  // @16_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @17_6604c0
  x1 = _mm_add_ss(x1, x0);  // @18_6604c0
  _mm_store_ss((float *)(u32)(8466900), x1);  // @19_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx));  // @20_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi)));  // @21_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 4));  // @22_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 4)));  // @23_6604c0
  x1 = _mm_add_ss(x1, x0);  // @24_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 8));  // @25_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 8)));  // @26_6604c0
  x1 = _mm_add_ss(x1, x0);  // @27_6604c0
  _mm_store_ss((float *)(u32)(8466904), x1);  // @28_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx));  // @29_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edi)));  // @30_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi + 4));  // @31_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 4)));  // @32_6604c0
  x1 = _mm_add_ss(x1, x0);  // @33_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi + 8));  // @34_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 8)));  // @35_6604c0
  x1 = _mm_add_ss(x1, x0);  // @36_6604c0
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 12)));  // @37_6604c0
  _mm_store_ss((float *)(u32)(8466908), x1);  // @38_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 20));  // @39_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 28)));  // @40_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 16));  // @41_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 24)));  // @42_6604c0
  x1 = _mm_add_ss(x1, x0);  // @43_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 32));  // @44_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 24)));  // @45_6604c0
  x1 = _mm_add_ss(x1, x0);  // @46_6604c0
  _mm_store_ss((float *)(u32)(8466912), x1);  // @47_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 20));  // @48_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 16)));  // @49_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 16));  // @50_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 12)));  // @51_6604c0
  x1 = _mm_add_ss(x1, x0);  // @52_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 24));  // @53_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @54_6604c0
  x1 = _mm_add_ss(x1, x0);  // @55_6604c0
  _mm_store_ss((float *)(u32)(8466916), x1);  // @56_6604c0
  x1 = _mm_load_ss((const float *)(u32)(esi));  // @57_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 16)));  // @58_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 4));  // @59_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 20)));  // @60_6604c0
  x1 = _mm_add_ss(x1, x0);  // @61_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 8));  // @62_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 24)));  // @63_6604c0
  x1 = _mm_add_ss(x1, x0);  // @64_6604c0
  _mm_store_ss((float *)(u32)(8466920), x1);  // @65_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edi + 4));  // @66_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 20)));  // @67_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @68_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 16)));  // @69_6604c0
  x1 = _mm_add_ss(x1, x0);  // @70_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi + 8));  // @71_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 24)));  // @72_6604c0
  x1 = _mm_add_ss(x1, x0);  // @73_6604c0
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 28)));  // @74_6604c0
  _mm_store_ss((float *)(u32)(8466924), x1);  // @75_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 36));  // @76_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 28)));  // @77_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 32));  // @78_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 24)));  // @79_6604c0
  x1 = _mm_add_ss(x1, x0);  // @80_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 40));  // @81_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 32)));  // @82_6604c0
  x1 = _mm_add_ss(x1, x0);  // @83_6604c0
  _mm_store_ss((float *)(u32)(8466928), x1);  // @84_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 36));  // @85_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 16)));  // @86_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 32));  // @87_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 12)));  // @88_6604c0
  x1 = _mm_add_ss(x1, x0);  // @89_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 40));  // @90_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @91_6604c0
  x1 = _mm_add_ss(x1, x0);  // @92_6604c0
  _mm_store_ss((float *)(u32)(8466932), x1);  // @93_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 36));  // @94_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 4)));  // @95_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 32));  // @96_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi)));  // @97_6604c0
  x1 = _mm_add_ss(x1, x0);  // @98_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 40));  // @99_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 8)));  // @100_6604c0
  x1 = _mm_add_ss(x1, x0);  // @101_6604c0
  _mm_store_ss((float *)(u32)(8466936), x1);  // @102_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 32));  // @103_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edi)));  // @104_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 36));  // @105_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 4)));  // @106_6604c0
  x1 = _mm_add_ss(x1, x0);  // @107_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 40));  // @108_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 8)));  // @109_6604c0
  x1 = _mm_add_ss(x1, x0);  // @110_6604c0
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 44)));  // @111_6604c0
  _mm_store_ss((float *)(u32)(8466940), x1);  // @112_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 52));  // @113_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 28)));  // @114_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 48));  // @115_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 24)));  // @116_6604c0
  x1 = _mm_add_ss(x1, x0);  // @117_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 32));  // @118_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 56)));  // @119_6604c0
  x1 = _mm_add_ss(x1, x0);  // @120_6604c0
  _mm_store_ss((float *)(u32)(8466944), x1);  // @121_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 52));  // @122_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 16)));  // @123_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 48));  // @124_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 12)));  // @125_6604c0
  x1 = _mm_add_ss(x1, x0);  // @126_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 56));  // @127_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @128_6604c0
  x1 = _mm_add_ss(x1, x0);  // @129_6604c0
  _mm_store_ss((float *)(u32)(8466948), x1);  // @130_6604c0
  x1 = _mm_load_ss((const float *)(u32)(esi));  // @131_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 48)));  // @132_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 4));  // @133_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 52)));  // @134_6604c0
  x1 = _mm_add_ss(x1, x0);  // @135_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 8));  // @136_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 56)));  // @137_6604c0
  x1 = _mm_add_ss(x1, x0);  // @138_6604c0
  _mm_store_ss((float *)(u32)(8466952), x1);  // @139_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edi + 4));  // @140_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 52)));  // @141_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @142_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 48)));  // @143_6604c0
  x1 = _mm_add_ss(x1, x0);  // @144_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi + 8));  // @145_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 56)));  // @146_6604c0
  x1 = _mm_add_ss(x1, x0);  // @147_6604c0
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 60)));  // @148_6604c0
  _mm_store_ss((float *)(u32)(8466956), x1);  // @149_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 68));  // @150_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 64));  // @151_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 28)));  // @152_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 24)));  // @153_6604c0
  x1 = _mm_add_ss(x1, x0);  // @154_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 72));  // @155_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 32)));  // @156_6604c0
  x1 = _mm_add_ss(x1, x0);  // @157_6604c0
  _mm_store_ss((float *)(u32)(8466960), x1);  // @158_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 68));  // @159_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 16)));  // @160_6604c0
  eax = (u32)(8466992);  // @161_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 64));  // @162_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 12)));  // @163_6604c0
  x1 = _mm_add_ss(x1, x0);  // @164_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 72));  // @165_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @166_6604c0
  x1 = _mm_add_ss(x1, x0);  // @167_6604c0
  _mm_store_ss((float *)(u32)(8466964), x1);  // @168_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 68));  // @169_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 4)));  // @170_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 64));  // @171_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi)));  // @172_6604c0
  x1 = _mm_add_ss(x1, x0);  // @173_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 72));  // @174_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 8)));  // @175_6604c0
  x1 = _mm_add_ss(x1, x0);  // @176_6604c0
  _mm_store_ss((float *)(u32)(8466968), x1);  // @177_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 64));  // @178_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edi)));  // @179_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 68));  // @180_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 4)));  // @181_6604c0
  x1 = _mm_add_ss(x1, x0);  // @182_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 72));  // @183_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 8)));  // @184_6604c0
  x1 = _mm_add_ss(x1, x0);  // @185_6604c0
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 76)));  // @186_6604c0
  _mm_store_ss((float *)(u32)(8466972), x1);  // @187_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 84));  // @188_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 28)));  // @189_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 80));  // @190_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 24)));  // @191_6604c0
  x1 = _mm_add_ss(x1, x0);  // @192_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 32));  // @193_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 88)));  // @194_6604c0
  x1 = _mm_add_ss(x1, x0);  // @195_6604c0
  _mm_store_ss((float *)(u32)(8466976), x1);  // @196_6604c0
  x1 = _mm_load_ss((const float *)(u32)(ecx + 84));  // @197_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 16)));  // @198_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 80));  // @199_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 12)));  // @200_6604c0
  x1 = _mm_add_ss(x1, x0);  // @201_6604c0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 88));  // @202_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @203_6604c0
  x1 = _mm_add_ss(x1, x0);  // @204_6604c0
  _mm_store_ss((float *)(u32)(8466980), x1);  // @205_6604c0
  x1 = _mm_load_ss((const float *)(u32)(esi));  // @206_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 80)));  // @207_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 4));  // @208_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 84)));  // @209_6604c0
  x1 = _mm_add_ss(x1, x0);  // @210_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 8));  // @211_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 88)));  // @212_6604c0
  x1 = _mm_add_ss(x1, x0);  // @213_6604c0
  _mm_store_ss((float *)(u32)(8466984), x1);  // @214_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @215_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 80)));  // @216_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edi + 4));  // @217_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 84)));  // @218_6604c0
  x1 = _mm_add_ss(x1, x0);  // @219_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi + 8));  // @220_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + 88)));  // @221_6604c0
  x1 = _mm_add_ss(x1, x0);  // @222_6604c0
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(ecx + 92)));  // @223_6604c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @224_6604c0
  _mm_store_ss((float *)(u32)(8466988), x1);  // @225_6604c0
  if ((ecx & ecx) == 0) goto L660bf2;  // @226_6604c0
  L660940:;
  x1 = _mm_load_ss((const float *)(u32)(edx + 4));  // @228_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 28)));  // @229_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx));  // @230_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 24)));  // @231_6604c0
  x1 = _mm_add_ss(x1, x0);  // @232_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 8));  // @233_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 32)));  // @234_6604c0
  x1 = _mm_add_ss(x1, x0);  // @235_6604c0
  _mm_store_ss((float *)(u32)(eax), x1);  // @236_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 4));  // @237_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 16)));  // @238_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx));  // @239_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 12)));  // @240_6604c0
  x1 = _mm_add_ss(x1, x0);  // @241_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 8));  // @242_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @243_6604c0
  x1 = _mm_add_ss(x1, x0);  // @244_6604c0
  _mm_store_ss((float *)(u32)(eax + 4), x1);  // @245_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 4));  // @246_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 4)));  // @247_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx));  // @248_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi)));  // @249_6604c0
  x1 = _mm_add_ss(x1, x0);  // @250_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 8));  // @251_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 8)));  // @252_6604c0
  x1 = _mm_add_ss(x1, x0);  // @253_6604c0
  _mm_store_ss((float *)(u32)(eax + 8), x1);  // @254_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx));  // @255_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edi)));  // @256_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 4));  // @257_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 4)));  // @258_6604c0
  x1 = _mm_add_ss(x1, x0);  // @259_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi + 8));  // @260_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 8)));  // @261_6604c0
  x1 = _mm_add_ss(x1, x0);  // @262_6604c0
  _mm_store_ss((float *)(u32)(eax + 12), x1);  // @263_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 28));  // @264_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 28)));  // @265_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 24));  // @266_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 24)));  // @267_6604c0
  x1 = _mm_add_ss(x1, x0);  // @268_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 32));  // @269_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 32)));  // @270_6604c0
  x1 = _mm_add_ss(x1, x0);  // @271_6604c0
  _mm_store_ss((float *)(u32)(eax + 16), x1);  // @272_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 28));  // @273_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 16)));  // @274_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 24));  // @275_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 12)));  // @276_6604c0
  x1 = _mm_add_ss(x1, x0);  // @277_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 32));  // @278_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @279_6604c0
  x1 = _mm_add_ss(x1, x0);  // @280_6604c0
  _mm_store_ss((float *)(u32)(eax + 20), x1);  // @281_6604c0
  x1 = _mm_load_ss((const float *)(u32)(esi));  // @282_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edx + 24)));  // @283_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 4));  // @284_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 28)));  // @285_6604c0
  x1 = _mm_add_ss(x1, x0);  // @286_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 8));  // @287_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 32)));  // @288_6604c0
  x1 = _mm_add_ss(x1, x0);  // @289_6604c0
  _mm_store_ss((float *)(u32)(eax + 24), x1);  // @290_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edi + 4));  // @291_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edx + 28)));  // @292_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @293_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 24)));  // @294_6604c0
  x1 = _mm_add_ss(x1, x0);  // @295_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi + 8));  // @296_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 32)));  // @297_6604c0
  x1 = _mm_add_ss(x1, x0);  // @298_6604c0
  _mm_store_ss((float *)(u32)(eax + 28), x1);  // @299_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 16));  // @300_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 12));  // @301_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 28)));  // @302_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 24)));  // @303_6604c0
  x1 = _mm_add_ss(x1, x0);  // @304_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 32));  // @305_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 20)));  // @306_6604c0
  x1 = _mm_add_ss(x1, x0);  // @307_6604c0
  _mm_store_ss((float *)(u32)(eax + 32), x1);  // @308_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 12));  // @309_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 12)));  // @310_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 16));  // @311_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 16)));  // @312_6604c0
  x1 = _mm_add_ss(x1, x0);  // @313_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 20));  // @314_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 20)));  // @315_6604c0
  x1 = _mm_add_ss(x1, x0);  // @316_6604c0
  _mm_store_ss((float *)(u32)(eax + 36), x1);  // @317_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 12));  // @318_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi)));  // @319_6604c0
  x1 = _mm_load_ss((const float *)(u32)(esi + 4));  // @320_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edx + 16)));  // @321_6604c0
  x1 = _mm_add_ss(x1, x0);  // @322_6604c0
  x0 = _mm_load_ss((const float *)(u32)(esi + 8));  // @323_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 20)));  // @324_6604c0
  x1 = _mm_add_ss(x1, x0);  // @325_6604c0
  _mm_store_ss((float *)(u32)(eax + 40), x1);  // @326_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 12));  // @327_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi)));  // @328_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edi + 4));  // @329_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edx + 16)));  // @330_6604c0
  x1 = _mm_add_ss(x1, x0);  // @331_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edi + 8));  // @332_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 20)));  // @333_6604c0
  x1 = _mm_add_ss(x1, x0);  // @334_6604c0
  _mm_store_ss((float *)(u32)(eax + 44), x1);  // @335_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 40));  // @336_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 28)));  // @337_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 36));  // @338_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 24)));  // @339_6604c0
  x1 = _mm_add_ss(x1, x0);  // @340_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 44));  // @341_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 32)));  // @342_6604c0
  x1 = _mm_add_ss(x1, x0);  // @343_6604c0
  _mm_store_ss((float *)(u32)(eax + 48), x1);  // @344_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 40));  // @345_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 16)));  // @346_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 36));  // @347_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 12)));  // @348_6604c0
  x1 = _mm_add_ss(x1, x0);  // @349_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 44));  // @350_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 20)));  // @351_6604c0
  x1 = _mm_add_ss(x1, x0);  // @352_6604c0
  _mm_store_ss((float *)(u32)(eax + 52), x1);  // @353_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 40));  // @354_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(esi + 4)));  // @355_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 36));  // @356_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi)));  // @357_6604c0
  x1 = _mm_add_ss(x1, x0);  // @358_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 44));  // @359_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(esi + 8)));  // @360_6604c0
  x1 = _mm_add_ss(x1, x0);  // @361_6604c0
  _mm_store_ss((float *)(u32)(eax + 56), x1);  // @362_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 40));  // @363_6604c0
  x1 = _mm_load_ss((const float *)(u32)(edx + 36));  // @364_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 4)));  // @365_6604c0
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edi)));  // @366_6604c0
  x1 = _mm_add_ss(x1, x0);  // @367_6604c0
  x0 = _mm_load_ss((const float *)(u32)(edx + 44));  // @368_6604c0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 8)));  // @369_6604c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 48), sizeof v); (u32)v; });  // @370_6604c0
  x1 = _mm_add_ss(x1, x0);  // @371_6604c0
  _mm_store_ss((float *)(u32)(eax + 60), x1);  // @372_6604c0
  eax = (eax + (u32)(64));  // @373_6604c0
  ecx = (ecx - (u32)(1));  // @374_6604c0
  if (ecx != 0) goto L660940;  // @375_6604c0
  L660bf2:;
  __asm__ volatile("" :: "Yz"(x0));  // @377_6604c0
  return eax;  // @378_6604c0
}
PCREG(6604c0, lifted_6604c0);

extern "C" u32 THISCALL lifted_5d0600(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_, p35_, p36_, p37_, p38_, p39_, p40_, p41_, p42_, p43_, p44_, p45_, p46_, p47_, p48_, p49_, p50_, p51_, p52_, p53_, p54_, p55_, p56_, p57_, p58_, p59_, p60_, p61_, p62_, p63_, p64_, p65_, p66_, p67_, p68_, p69_, p70_, p71_, p72_, p73_, p74_, p75_, p76_, p77_, p78_, p79_, p80_, p81_, p82_, p83_, p84_, p85_, p86_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d0600
  edi = ecx;  // @1_5d0600
  ecx = (u32)(EBP - 8);  // @2_5d0600
  p0_ = ecx;  // @3_5d0600
  ecx = esi;  // @4_5d0600
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @5_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(p0_));  // @7_5d0600
  ecx = edx = 0;  // @8_5d0600
  x1 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @9_5d0600
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(7000572)));  // @10_5d0600
  x0 = _mm_load_ss((const float *)(u32)(6806040));  // @11_5d0600
  if (fa_ > fb_) goto L5d063f;  // @12_5d0600
  x2 = _mm_load_ss((const float *)(u32)(7000628));  // @13_5d0600
  fa_ = _mm_cvtss_f32(x2); fb_ = _mm_cvtss_f32(x1);  // @14_5d0600
  if (!(fa_ > fb_)) goto L5d0642;  // @15_5d0600
  L5d063f:;
  x1 = x0;  // @17_5d0600
  L5d0642:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @19_5d0600
  ecx = (u32)(EBP - 8);  // @20_5d0600
  p1_ = ecx;  // @21_5d0600
  ecx = esi;  // @22_5d0600
  _mm_store_ss((float *)(u32)(edi + 2644), x1);  // @23_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(p1_));  // @24_5d0600
  ecx = edx = 0;  // @25_5d0600
  x0 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @26_5d0600
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(7000572)));  // @27_5d0600
  if (fa_ > fb_) goto L5d0670;  // @28_5d0600
  x1 = _mm_load_ss((const float *)(u32)(7000628));  // @29_5d0600
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x0);  // @30_5d0600
  if (!(fa_ > fb_)) goto L5d0678;  // @31_5d0600
  L5d0670:;
  x0 = _mm_load_ss((const float *)(u32)(6806040));  // @33_5d0600
  L5d0678:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_5d0600
  eax = (u32)(edi + 2652);  // @36_5d0600
  p2_ = eax;  // @37_5d0600
  ecx = esi;  // @38_5d0600
  _mm_store_ss((float *)(u32)(edi + 2648), x0);  // @39_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p2_));  // @40_5d0600
  ecx = edx = 0;  // @41_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_5d0600
  eax = (u32)(edi + 2656);  // @43_5d0600
  p3_ = eax;  // @44_5d0600
  ecx = esi;  // @45_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p3_));  // @46_5d0600
  ecx = edx = 0;  // @47_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_5d0600
  eax = (u32)(edi + 2660);  // @49_5d0600
  p4_ = eax;  // @50_5d0600
  ecx = esi;  // @51_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p4_));  // @52_5d0600
  ecx = edx = 0;  // @53_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_5d0600
  eax = (u32)(edi + 2664);  // @55_5d0600
  p5_ = eax;  // @56_5d0600
  ecx = esi;  // @57_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p5_));  // @58_5d0600
  ecx = edx = 0;  // @59_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_5d0600
  eax = (u32)(edi + 2668);  // @61_5d0600
  p6_ = eax;  // @62_5d0600
  ecx = esi;  // @63_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p6_));  // @64_5d0600
  ecx = edx = 0;  // @65_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_5d0600
  eax = (u32)(edi + 2672);  // @67_5d0600
  p7_ = eax;  // @68_5d0600
  ecx = esi;  // @69_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p7_));  // @70_5d0600
  ecx = edx = 0;  // @71_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_5d0600
  eax = (u32)(edi + 2673);  // @73_5d0600
  p8_ = eax;  // @74_5d0600
  ecx = esi;  // @75_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p8_));  // @76_5d0600
  ecx = edx = 0;  // @77_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @78_5d0600
  eax = (u32)(edi + 2674);  // @79_5d0600
  p9_ = eax;  // @80_5d0600
  ecx = esi;  // @81_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p9_));  // @82_5d0600
  ecx = edx = 0;  // @83_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_5d0600
  eax = (u32)(edi + 2686);  // @85_5d0600
  p10_ = eax;  // @86_5d0600
  ecx = esi;  // @87_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p10_));  // @88_5d0600
  ecx = edx = 0;  // @89_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_5d0600
  eax = (u32)(edi + 2698);  // @91_5d0600
  p11_ = eax;  // @92_5d0600
  ecx = esi;  // @93_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p11_));  // @94_5d0600
  ecx = edx = 0;  // @95_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @96_5d0600
  eax = (u32)(edi + 2710);  // @97_5d0600
  p12_ = eax;  // @98_5d0600
  ecx = esi;  // @99_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p12_));  // @100_5d0600
  ecx = edx = 0;  // @101_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_5d0600
  eax = (u32)(edi + 2714);  // @103_5d0600
  p13_ = eax;  // @104_5d0600
  ecx = esi;  // @105_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p13_));  // @106_5d0600
  ecx = edx = 0;  // @107_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_5d0600
  eax = (u32)(edi + 2718);  // @109_5d0600
  p14_ = eax;  // @110_5d0600
  ecx = esi;  // @111_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p14_));  // @112_5d0600
  ecx = edx = 0;  // @113_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_5d0600
  eax = (u32)(edi + 2722);  // @115_5d0600
  p15_ = eax;  // @116_5d0600
  ecx = esi;  // @117_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p15_));  // @118_5d0600
  ecx = edx = 0;  // @119_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @120_5d0600
  eax = (u32)(edi + 2734);  // @121_5d0600
  p16_ = eax;  // @122_5d0600
  ecx = esi;  // @123_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p16_));  // @124_5d0600
  ecx = edx = 0;  // @125_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @126_5d0600
  eax = (u32)(edi + 2742);  // @127_5d0600
  p17_ = eax;  // @128_5d0600
  ecx = esi;  // @129_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p17_));  // @130_5d0600
  ecx = edx = 0;  // @131_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_5d0600
  ecx = (u32)(EBP + 8);  // @133_5d0600
  p18_ = ecx;  // @134_5d0600
  ecx = esi;  // @135_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p18_));  // @136_5d0600
  ecx = edx = 0;  // @137_5d0600
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @138_5d0600
  ecx = esi;  // @139_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2773), &v, sizeof v); }  // @140_5d0600
  eax = (u32)(edi + 2777);  // @141_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_5d0600
  p19_ = eax;  // @143_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p19_));  // @144_5d0600
  ecx = edx = 0;  // @145_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_5d0600
  eax = (u32)(edi + 2781);  // @147_5d0600
  p20_ = eax;  // @148_5d0600
  ecx = esi;  // @149_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p20_));  // @150_5d0600
  ecx = edx = 0;  // @151_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @152_5d0600
  eax = (u32)(edi + 2772);  // @153_5d0600
  p21_ = eax;  // @154_5d0600
  ecx = esi;  // @155_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p21_));  // @156_5d0600
  ecx = edx = 0;  // @157_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_5d0600
  eax = (u32)(edi + 2785);  // @159_5d0600
  p22_ = eax;  // @160_5d0600
  ecx = esi;  // @161_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p22_));  // @162_5d0600
  ecx = edx = 0;  // @163_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @164_5d0600
  ecx = (u32)(EBP - 12);  // @165_5d0600
  p23_ = ecx;  // @166_5d0600
  ecx = esi;  // @167_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p23_));  // @168_5d0600
  ecx = edx = 0;  // @169_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @170_5d0600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @171_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @172_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @173_5d0600
  ecx = edx = 0;  // @174_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2789), &v, sizeof v); }  // @175_5d0600
  ecx = (u32)(EBP - 8);  // @176_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_5d0600
  p24_ = ecx;  // @178_5d0600
  ecx = esi;  // @179_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(p24_));  // @180_5d0600
  ecx = edx = 0;  // @181_5d0600
  x1 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @182_5d0600
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(7000572)));  // @183_5d0600
  if (!(fa_ > fb_)) goto L5d07f4;  // @184_5d0600
  L5d07ea:;
  x0 = _mm_load_ss((const float *)(u32)(6806040));  // @186_5d0600
  goto L5d0804;  // @187_5d0600
  L5d07f4:;
  x0 = _mm_load_ss((const float *)(u32)(7000628));  // @189_5d0600
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @190_5d0600
  if (fa_ > fb_) goto L5d07ea;  // @191_5d0600
  x0 = x1;  // @192_5d0600
  L5d0804:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @194_5d0600
  eax = (u32)(edi + 2797);  // @195_5d0600
  p25_ = eax;  // @196_5d0600
  ecx = esi;  // @197_5d0600
  _mm_store_ss((float *)(u32)(edi + 2793), x0);  // @198_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p25_));  // @199_5d0600
  ecx = edx = 0;  // @200_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @201_5d0600
  eax = (u32)(edi + 2801);  // @202_5d0600
  p26_ = eax;  // @203_5d0600
  ecx = esi;  // @204_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p26_));  // @205_5d0600
  ecx = edx = 0;  // @206_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @207_5d0600
  eax = (u32)(edi + 2805);  // @208_5d0600
  p27_ = eax;  // @209_5d0600
  ecx = esi;  // @210_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p27_));  // @211_5d0600
  ecx = edx = 0;  // @212_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @213_5d0600
  eax = (u32)(edi + 2809);  // @214_5d0600
  p28_ = eax;  // @215_5d0600
  ecx = esi;  // @216_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p28_));  // @217_5d0600
  ecx = edx = 0;  // @218_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @219_5d0600
  eax = (u32)(edi + 2813);  // @220_5d0600
  p29_ = eax;  // @221_5d0600
  ecx = esi;  // @222_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p29_));  // @223_5d0600
  ecx = edx = 0;  // @224_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @225_5d0600
  eax = (u32)(edi + 2817);  // @226_5d0600
  p30_ = eax;  // @227_5d0600
  ecx = esi;  // @228_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p30_));  // @229_5d0600
  ecx = edx = 0;  // @230_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @231_5d0600
  eax = (u32)(edi + 2821);  // @232_5d0600
  p31_ = eax;  // @233_5d0600
  ecx = esi;  // @234_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p31_));  // @235_5d0600
  ecx = edx = 0;  // @236_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @237_5d0600
  eax = (u32)(edi + 2825);  // @238_5d0600
  p32_ = eax;  // @239_5d0600
  ecx = esi;  // @240_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p32_));  // @241_5d0600
  ecx = edx = 0;  // @242_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @243_5d0600
  eax = (u32)(edi + 2829);  // @244_5d0600
  p33_ = eax;  // @245_5d0600
  ecx = esi;  // @246_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p33_));  // @247_5d0600
  ecx = edx = 0;  // @248_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @249_5d0600
  eax = (u32)(edi + 2833);  // @250_5d0600
  p34_ = eax;  // @251_5d0600
  ecx = esi;  // @252_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p34_));  // @253_5d0600
  ecx = edx = 0;  // @254_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @255_5d0600
  eax = (u32)(edi + 2837);  // @256_5d0600
  p35_ = eax;  // @257_5d0600
  ecx = esi;  // @258_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p35_));  // @259_5d0600
  ecx = edx = 0;  // @260_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @261_5d0600
  eax = (u32)(edi + 2841);  // @262_5d0600
  p36_ = eax;  // @263_5d0600
  ecx = esi;  // @264_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p36_));  // @265_5d0600
  ecx = edx = 0;  // @266_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @267_5d0600
  eax = (u32)(edi + 2842);  // @268_5d0600
  p37_ = eax;  // @269_5d0600
  ecx = esi;  // @270_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p37_));  // @271_5d0600
  ecx = edx = 0;  // @272_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @273_5d0600
  eax = (u32)(edi + 2847);  // @274_5d0600
  p38_ = eax;  // @275_5d0600
  ecx = esi;  // @276_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p38_));  // @277_5d0600
  ecx = edx = 0;  // @278_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @279_5d0600
  eax = (u32)(edi + 2851);  // @280_5d0600
  p39_ = eax;  // @281_5d0600
  ecx = esi;  // @282_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p39_));  // @283_5d0600
  ecx = edx = 0;  // @284_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @285_5d0600
  eax = (u32)(edi + 2855);  // @286_5d0600
  p40_ = eax;  // @287_5d0600
  ecx = esi;  // @288_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p40_));  // @289_5d0600
  ecx = edx = 0;  // @290_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @291_5d0600
  eax = (u32)(edi + 2859);  // @292_5d0600
  p41_ = eax;  // @293_5d0600
  ecx = esi;  // @294_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p41_));  // @295_5d0600
  ecx = edx = 0;  // @296_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @297_5d0600
  eax = (u32)(edi + 2863);  // @298_5d0600
  p42_ = eax;  // @299_5d0600
  ecx = esi;  // @300_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p42_));  // @301_5d0600
  ecx = edx = 0;  // @302_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @303_5d0600
  eax = (u32)(edi + 2864);  // @304_5d0600
  p43_ = eax;  // @305_5d0600
  ecx = esi;  // @306_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p43_));  // @307_5d0600
  ecx = edx = 0;  // @308_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @309_5d0600
  eax = (u32)(edi + 2865);  // @310_5d0600
  p44_ = eax;  // @311_5d0600
  ecx = esi;  // @312_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p44_));  // @313_5d0600
  ecx = edx = 0;  // @314_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @315_5d0600
  eax = (u32)(edi + 2866);  // @316_5d0600
  p45_ = eax;  // @317_5d0600
  ecx = esi;  // @318_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p45_));  // @319_5d0600
  ecx = edx = 0;  // @320_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @321_5d0600
  eax = (u32)(edi + 2867);  // @322_5d0600
  p46_ = eax;  // @323_5d0600
  ecx = esi;  // @324_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p46_));  // @325_5d0600
  ecx = edx = 0;  // @326_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @327_5d0600
  eax = (u32)(edi + 2868);  // @328_5d0600
  p47_ = eax;  // @329_5d0600
  ecx = esi;  // @330_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p47_));  // @331_5d0600
  ecx = edx = 0;  // @332_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @333_5d0600
  eax = (u32)(edi + 2869);  // @334_5d0600
  p48_ = eax;  // @335_5d0600
  ecx = esi;  // @336_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p48_));  // @337_5d0600
  ecx = edx = 0;  // @338_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @339_5d0600
  eax = (u32)(edi + 2873);  // @340_5d0600
  p49_ = eax;  // @341_5d0600
  ecx = esi;  // @342_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p49_));  // @343_5d0600
  ecx = edx = 0;  // @344_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @345_5d0600
  eax = (u32)(edi + 2885);  // @346_5d0600
  p50_ = eax;  // @347_5d0600
  ecx = esi;  // @348_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p50_));  // @349_5d0600
  ecx = edx = 0;  // @350_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @351_5d0600
  eax = (u32)(edi + 2887);  // @352_5d0600
  p51_ = eax;  // @353_5d0600
  ecx = esi;  // @354_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p51_));  // @355_5d0600
  ecx = edx = 0;  // @356_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @357_5d0600
  eax = (u32)(edi + 2888);  // @358_5d0600
  p52_ = eax;  // @359_5d0600
  ecx = esi;  // @360_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p52_));  // @361_5d0600
  ecx = edx = 0;  // @362_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @363_5d0600
  eax = (u32)(edi + 2889);  // @364_5d0600
  p53_ = eax;  // @365_5d0600
  ecx = esi;  // @366_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p53_));  // @367_5d0600
  ecx = edx = 0;  // @368_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @369_5d0600
  eax = (u32)(edi + 2893);  // @370_5d0600
  p54_ = eax;  // @371_5d0600
  ecx = esi;  // @372_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p54_));  // @373_5d0600
  ecx = edx = 0;  // @374_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @375_5d0600
  eax = (u32)(edi + 2895);  // @376_5d0600
  p55_ = eax;  // @377_5d0600
  ecx = esi;  // @378_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p55_));  // @379_5d0600
  ecx = edx = 0;  // @380_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @381_5d0600
  ecx = (u32)(EBP - 16);  // @382_5d0600
  p56_ = ecx;  // @383_5d0600
  ecx = esi;  // @384_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p56_));  // @385_5d0600
  ecx = edx = 0;  // @386_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @387_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2896), &v, sizeof v); }  // @388_5d0600
  ecx = esi;  // @389_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @390_5d0600
  eax = (u32)(edi + 3181);  // @391_5d0600
  p57_ = eax;  // @392_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p57_));  // @393_5d0600
  ecx = edx = 0;  // @394_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @395_5d0600
  eax = (u32)(edi + 3185);  // @396_5d0600
  p58_ = eax;  // @397_5d0600
  ecx = esi;  // @398_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p58_));  // @399_5d0600
  ecx = edx = 0;  // @400_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @401_5d0600
  eax = (u32)(edi + 3197);  // @402_5d0600
  p59_ = eax;  // @403_5d0600
  ecx = esi;  // @404_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p59_));  // @405_5d0600
  ecx = edx = 0;  // @406_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @407_5d0600
  eax = (u32)(edi + 3209);  // @408_5d0600
  p60_ = eax;  // @409_5d0600
  ecx = esi;  // @410_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(p60_));  // @411_5d0600
  ecx = edx = 0;  // @412_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @413_5d0600
  eax = (u32)(edi + 3245);  // @414_5d0600
  p61_ = eax;  // @415_5d0600
  ecx = esi;  // @416_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p61_));  // @417_5d0600
  ecx = edx = 0;  // @418_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @419_5d0600
  eax = (u32)(edi + 3257);  // @420_5d0600
  p62_ = eax;  // @421_5d0600
  ecx = esi;  // @422_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(p62_));  // @423_5d0600
  ecx = edx = 0;  // @424_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @425_5d0600
  eax = (u32)(edi + 3293);  // @426_5d0600
  p63_ = eax;  // @427_5d0600
  ecx = esi;  // @428_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(p63_));  // @429_5d0600
  ecx = edx = 0;  // @430_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @431_5d0600
  eax = (u32)(edi + 3329);  // @432_5d0600
  p64_ = eax;  // @433_5d0600
  ecx = esi;  // @434_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p64_));  // @435_5d0600
  ecx = edx = 0;  // @436_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @437_5d0600
  eax = (u32)(edi + 3341);  // @438_5d0600
  p65_ = eax;  // @439_5d0600
  ecx = esi;  // @440_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p65_));  // @441_5d0600
  ecx = edx = 0;  // @442_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @443_5d0600
  eax = (u32)(edi + 3345);  // @444_5d0600
  p66_ = eax;  // @445_5d0600
  ecx = esi;  // @446_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p66_));  // @447_5d0600
  ecx = edx = 0;  // @448_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @449_5d0600
  eax = (u32)(edi + 3349);  // @450_5d0600
  p67_ = eax;  // @451_5d0600
  ecx = esi;  // @452_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p67_));  // @453_5d0600
  ecx = edx = 0;  // @454_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @455_5d0600
  eax = (u32)(edi + 3361);  // @456_5d0600
  p68_ = eax;  // @457_5d0600
  ecx = esi;  // @458_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p68_));  // @459_5d0600
  ecx = edx = 0;  // @460_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @461_5d0600
  eax = (u32)(edi + 3362);  // @462_5d0600
  p69_ = eax;  // @463_5d0600
  ecx = esi;  // @464_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p69_));  // @465_5d0600
  ecx = edx = 0;  // @466_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @467_5d0600
  eax = (u32)(edi + 3374);  // @468_5d0600
  p70_ = eax;  // @469_5d0600
  ecx = esi;  // @470_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p70_));  // @471_5d0600
  ecx = edx = 0;  // @472_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @473_5d0600
  eax = (u32)(edi + 3378);  // @474_5d0600
  p71_ = eax;  // @475_5d0600
  ecx = esi;  // @476_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p71_));  // @477_5d0600
  ecx = edx = 0;  // @478_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @479_5d0600
  eax = (u32)(edi + 3379);  // @480_5d0600
  p72_ = eax;  // @481_5d0600
  ecx = esi;  // @482_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p72_));  // @483_5d0600
  ecx = edx = 0;  // @484_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @485_5d0600
  eax = (u32)(edi + 3380);  // @486_5d0600
  p73_ = eax;  // @487_5d0600
  ecx = esi;  // @488_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p73_));  // @489_5d0600
  ecx = edx = 0;  // @490_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @491_5d0600
  eax = (u32)(edi + 3381);  // @492_5d0600
  p74_ = eax;  // @493_5d0600
  ecx = esi;  // @494_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p74_));  // @495_5d0600
  ecx = edx = 0;  // @496_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @497_5d0600
  eax = (u32)(edi + 3544);  // @498_5d0600
  p75_ = eax;  // @499_5d0600
  ecx = esi;  // @500_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p75_));  // @501_5d0600
  ecx = edx = 0;  // @502_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @503_5d0600
  eax = (u32)(edi + 3573);  // @504_5d0600
  p76_ = eax;  // @505_5d0600
  ecx = esi;  // @506_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p76_));  // @507_5d0600
  ecx = edx = 0;  // @508_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @509_5d0600
  eax = (u32)(edi + 3577);  // @510_5d0600
  p77_ = eax;  // @511_5d0600
  ecx = esi;  // @512_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p77_));  // @513_5d0600
  ecx = edx = 0;  // @514_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @515_5d0600
  eax = (u32)(edi + 3581);  // @516_5d0600
  p78_ = eax;  // @517_5d0600
  ecx = esi;  // @518_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p78_));  // @519_5d0600
  ecx = edx = 0;  // @520_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @521_5d0600
  eax = (u32)(edi + 3585);  // @522_5d0600
  p79_ = eax;  // @523_5d0600
  ecx = esi;  // @524_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p79_));  // @525_5d0600
  ecx = edx = 0;  // @526_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @527_5d0600
  eax = (u32)(edi + 3589);  // @528_5d0600
  p80_ = eax;  // @529_5d0600
  ecx = esi;  // @530_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p80_));  // @531_5d0600
  ecx = edx = 0;  // @532_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @533_5d0600
  eax = (u32)(edi + 3593);  // @534_5d0600
  p81_ = eax;  // @535_5d0600
  ecx = esi;  // @536_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p81_));  // @537_5d0600
  ecx = edx = 0;  // @538_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @539_5d0600
  eax = (u32)(edi + 3597);  // @540_5d0600
  p82_ = eax;  // @541_5d0600
  ecx = esi;  // @542_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p82_));  // @543_5d0600
  ecx = edx = 0;  // @544_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @545_5d0600
  eax = (u32)(edi + 3598);  // @546_5d0600
  p83_ = eax;  // @547_5d0600
  ecx = esi;  // @548_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p83_));  // @549_5d0600
  ecx = edx = 0;  // @550_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @551_5d0600
  eax = (u32)(edi + 3607);  // @552_5d0600
  p84_ = eax;  // @553_5d0600
  ecx = esi;  // @554_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p84_));  // @555_5d0600
  ecx = edx = 0;  // @556_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @557_5d0600
  ecx = (u32)(EBP - 12);  // @558_5d0600
  p85_ = ecx;  // @559_5d0600
  ecx = esi;  // @560_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p85_));  // @561_5d0600
  ecx = edx = 0;  // @562_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @563_5d0600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @564_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @565_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @566_5d0600
  ecx = edx = 0;  // @567_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 3608), &v, sizeof v); }  // @568_5d0600
  ecx = (u32)(EBP - 4);  // @569_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @570_5d0600
  p86_ = ecx;  // @571_5d0600
  ecx = esi;  // @572_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p86_));  // @573_5d0600
  ecx = edx = 0;  // @574_5d0600
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @575_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 3612), &v, sizeof v); }  // @576_5d0600
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @577_5d0600
  __asm__ volatile("" :: "Yz"(x0));  // @578_5d0600
  return eax;  // @579_5d0600
}
PCREG(5d0600, lifted_5d0600);

extern "C" u32 THISCALL lifted_532f30(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_532f30
  edx = ecx;  // @1_532f30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_532f30
  x1 = _mm_load_ss((const float *)(u32)(edi + 136));  // @3_532f30
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edi + 132)));  // @4_532f30
  _mm_store_ss((float *)(u32)(esi + 76), x1);  // @5_532f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @6_532f30
  eax = (u32)(edx + ecx*8);  // @7_532f30
  x0 = _mm_load_ss((const float *)(u32)(ecx + eax + 20825));  // @8_532f30
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edx + 20913)));  // @9_532f30
  x0 = _mm_mul_ss(x0, x1);  // @10_532f30
  _mm_store_ss((float *)(u32)(esi + 76), x0);  // @11_532f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @12_532f30
  eax = (u32)(edx + ecx*8);  // @13_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax + 20830), sizeof v); (u32)v; });  // @14_532f30
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; }));  // @15_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @16_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @17_532f30
  eax = (eax - 1);  // @18_532f30
  if (eax > (u32)(9)) goto L5330c8;  // @19_532f30
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5452012), sizeof v); (u32)v; });  // @20_532f30
  switch (eax) { case 0: goto L53306d; case 1: goto L532fa0; case 2: goto L532fc0; default: __builtin_trap(); }  // @21_532f30
  L532fa0:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @23_532f30
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @24_532f30
  { u32 v = (u32)((u32)(116)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @25_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; });  // @26_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @27_532f30
  __asm__ volatile("" :: "Yz"(x0));  // @28_532f30
  return eax;  // @29_532f30
  L532fc0:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @31_532f30
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @32_532f30
  { u32 v = (u32)((u32)(192)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @33_532f30
  x0 = _mm_load_ss((const float *)(u32)(edi + 88));  // @34_532f30
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 84)));  // @35_532f30
  _mm_store_ss((float *)(u32)(esi + 172), x0);  // @36_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @37_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @38_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @39_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @40_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @41_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @42_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @43_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 188), &v, sizeof v); }  // @44_532f30
  L53300a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 224), sizeof v); (u32)v; });  // @46_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @47_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 228), sizeof v); (u32)v; });  // @48_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @49_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 232), sizeof v); (u32)v; });  // @50_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @51_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 212), sizeof v); (u32)v; });  // @52_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @53_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 216), sizeof v); (u32)v; });  // @54_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @55_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 220), sizeof v); (u32)v; });  // @56_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @57_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @58_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @59_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @60_532f30
  __asm__ volatile("" :: "Yz"(x0));  // @61_532f30
  return eax;  // @62_532f30
  L53306d:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @64_532f30
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @65_532f30
  { u32 v = (u32)((u32)(192)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @66_532f30
  x0 = _mm_load_ss((const float *)(u32)(edi + 88));  // @67_532f30
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 84)));  // @68_532f30
  _mm_store_ss((float *)(u32)(esi + 172), x0);  // @69_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @70_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @71_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @72_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @73_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @74_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @75_532f30
  x0 = _mm_load_ss((const float *)(u32)(edi + 76));  // @76_532f30
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6802752)));  // @77_532f30
  _mm_store_ss((float *)(u32)(esi + 188), x0);  // @78_532f30
  goto L53300a;  // @79_532f30
  L5330c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @81_532f30
  if ((eax & eax) == 0) goto L5330d9;  // @82_532f30
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @83_532f30
  ecx = edx = 0;  // @84_532f30
  __asm__ volatile("" :: "Yz"(x0));  // @85_532f30
  return eax;  // @86_532f30
  L5330d9:;
  __builtin_trap();  // @88_532f30
}
PCREG(532f30, lifted_532f30);

extern "C" u32 THISCALL lifted_564700(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_564700
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 395), sizeof v); (u32)v; }) == (u32)(0)) goto L564756;  // @1_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_564700
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @3_564700
  ecx = edx = 0;  // @4_564700
  ecx = (u32)(eax + 203);  // @5_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_564700
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @7_564700
  ecx = edx = 0;  // @8_564700
  edi = eax;  // @9_564700
  if ((edi & edi) == 0) goto L564749;  // @10_564700
  L564730:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_564700
  ecx = esi;  // @13_564700
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 132)))(ecx);  // @14_564700
  ecx = edx = 0;  // @15_564700
  ecx = eax;  // @16_564700
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_564700
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 768)))(ecx);  // @18_564700
  ecx = edx = 0;  // @19_564700
  edi = (edi - (u32)(1));  // @20_564700
  if (edi != 0) goto L564730;  // @21_564700
  L564749:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 395), &v, sizeof v); }  // @23_564700
  return eax;  // @24_564700
  L564756:;
  eax = ext_562260_thiscall1(ecx);  // @26_564700
  ecx = edx = 0;  // @27_564700
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3226), sizeof v); (u32)v; });  // @28_564700
  if (ebx == (u32)(10)) goto L5649bb;  // @29_564700
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 220), sizeof v); (u32)v; }) != (u32)(2)) goto L5649bb;  // @30_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 388), sizeof v); (u32)v; });  // @31_564700
  edi = (u32)(esi + 388);  // @32_564700
  eax = (eax + (u32)(-2));  // @33_564700
  if (eax > (u32)(30)) goto L5649ae;  // @34_564700
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5655068), sizeof v); (u32)v; });  // @35_564700
  switch (eax) { case 0: goto L56479e; case 1: goto L5648bb; case 2: goto L56492d; case 3: goto L564967; case 4: goto L564985; case 5: goto L5649ae; default: __builtin_trap(); }  // @36_564700
  L56479e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 393), sizeof v); (u32)v; }) == (u32)(0)) goto L564879;  // @38_564700
  x0 = _mm_load_ss((const float *)(u32)(esi + 3238));  // @39_564700
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784544)));  // @40_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_564700
  ecx = (u32)_mm_cvtss_si32(x0);  // @42_564700
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) <= (s32)ecx) goto L56483e;  // @43_564700
  L5647c9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 392), sizeof v); (u32)v; }) == (u32)(0)) goto L564824;  // @45_564700
  ecx = (u32)(EBP - 44);  // @46_564700
  eax = ext_57f960_thiscall1(ecx);  // @47_564700
  ecx = edx = 0;  // @48_564700
  eax = (u32)(EBP - 44);  // @49_564700
  p0_ = eax;  // @50_564700
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3226), sizeof v); (u32)v; }) * (s32)(u32)(172));  // @51_564700
  ecx = (u32)(esi + 1446);  // @52_564700
  p1_ = edi;  // @53_564700
  ecx = (ecx + eax);  // @54_564700
  eax = ext_57f9b0_thiscall3(ecx, (u32)(p1_), (u32)(p0_));  // @55_564700
  ecx = edx = 0;  // @56_564700
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) == (u32)(32)) goto L564806;  // @57_564700
  eax = (u32)(EBP - 44);  // @58_564700
  ecx = esi;  // @59_564700
  p2_ = eax;  // @60_564700
  eax = ext_565360_stdcall1((u32)(p2_));  // @61_564700
  ecx = edx = 0;  // @62_564700
  L564806:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3222), &v, sizeof v); }  // @64_564700
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 3222), &v, sizeof v); }  // @65_564700
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 393), &v, sizeof v); }  // @66_564700
  __asm__ volatile("" :: "Yz"(x0));  // @67_564700
  return eax;  // @68_564700
  L564824:;
  ecx = esi;  // @70_564700
  eax = ext_565100_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3210), sizeof v); (u32)v; }));  // @71_564700
  ecx = edx = 0;  // @72_564700
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 3222), &v, sizeof v); }  // @73_564700
  __asm__ volatile("" :: "Yz"(x0));  // @74_564700
  return eax;  // @75_564700
  L56483e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3210), sizeof v); (u32)v; }) == (u32)(1)) goto L5649ae;  // @77_564700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3166), sizeof v); (u32)v; });  // @78_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_564700
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @80_564700
  ecx = edx = 0;  // @81_564700
  if (eax != (u32)(1)) goto L5649ae;  // @82_564700
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 3222), &v, sizeof v); }  // @83_564700
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 392), &v, sizeof v); }  // @84_564700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 3210), &v, sizeof v); }  // @85_564700
  __asm__ volatile("" :: "Yz"(x0));  // @86_564700
  return eax;  // @87_564700
  L564879:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) != (u32)(2)) goto L5649ae;  // @89_564700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3166), sizeof v); (u32)v; });  // @90_564700
  eax = (u32)(esi + 3210);  // @91_564700
  { u32 v = (u32)((u32)(25)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @92_564700
  p3_ = eax;  // @93_564700
  p4_ = ebx;  // @94_564700
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @96_564700
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p4_), (u32)(p3_));  // @97_564700
  ecx = edx = 0;  // @98_564700
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 3222), &v, sizeof v); }  // @99_564700
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 392), &v, sizeof v); }  // @100_564700
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 393), &v, sizeof v); }  // @101_564700
  __asm__ volatile("" :: "Yz"(x0));  // @102_564700
  return eax;  // @103_564700
  L5648bb:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 393), sizeof v); (u32)v; }) == (u32)(0)) goto L5648eb;  // @105_564700
  x0 = _mm_load_ss((const float *)(u32)(esi + 3238));  // @106_564700
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784544)));  // @107_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_564700
  ecx = (u32)_mm_cvtss_si32(x0);  // @109_564700
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) <= (s32)ecx) goto L5649ae;  // @110_564700
  goto L5647c9;  // @111_564700
  L5648eb:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) != (u32)(2)) goto L5649ae;  // @113_564700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3166), sizeof v); (u32)v; });  // @114_564700
  eax = (u32)(esi + 3210);  // @115_564700
  { u32 v = (u32)((u32)(25)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @116_564700
  p5_ = eax;  // @117_564700
  p6_ = ebx;  // @118_564700
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @120_564700
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p6_), (u32)(p5_));  // @121_564700
  ecx = edx = 0;  // @122_564700
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 3222), &v, sizeof v); }  // @123_564700
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 392), &v, sizeof v); }  // @124_564700
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 393), &v, sizeof v); }  // @125_564700
  __asm__ volatile("" :: "Yz"(x0));  // @126_564700
  return eax;  // @127_564700
  L56492d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 393), sizeof v); (u32)v; }) != (u32)(0)) goto L5647c9;  // @129_564700
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) != (u32)(2)) goto L5649ae;  // @130_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @131_564700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @132_564700
  eax = (u32)(esi + 384);  // @133_564700
  p7_ = eax;  // @134_564700
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_564700
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 40)))(ecx, (u32)(p7_));  // @136_564700
  ecx = edx = 0;  // @137_564700
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 3222), &v, sizeof v); }  // @138_564700
  __asm__ volatile("" :: "Yz"(x0));  // @139_564700
  return eax;  // @140_564700
  L564967:;
  x0 = _mm_load_ss((const float *)(u32)(esi + 3238));  // @142_564700
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784544)));  // @143_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @144_564700
  ecx = (u32)_mm_cvtss_si32(x0);  // @145_564700
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) < (s32)ecx) goto L5649ae;  // @146_564700
  L564985:;
  eax = (u32)((s32)ebx * (s32)(u32)(172));  // @148_564700
  ecx = esi;  // @149_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 1614), sizeof v); (u32)v; });  // @150_564700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 3202), &v, sizeof v); }  // @151_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @152_564700
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 3226), &v, sizeof v); }  // @153_564700
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(0));  // @154_564700
  ecx = edx = 0;  // @155_564700
  L5649ae:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3222), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 3222), &v, sizeof v); }  // @157_564700
  __asm__ volatile("" :: "Yz"(x0));  // @158_564700
  return eax;  // @159_564700
  L5649bb:;
  ecx = esi;  // @161_564700
  eax = ext_562010_thiscall1(ecx);  // @162_564700
  ecx = edx = 0;  // @163_564700
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5649fa;  // @164_564700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3166), sizeof v); (u32)v; });  // @165_564700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @166_564700
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @167_564700
  ecx = edx = 0;  // @168_564700
  edi = eax;  // @169_564700
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3214), sizeof v); (u32)v; }) != (u32)(1)) goto L5649f4;  // @170_564700
  if (edi == (u32)(1)) goto L5649f4;  // @171_564700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3230), sizeof v); (u32)v; });  // @172_564700
  if (ecx == (u32)(10)) goto L5649f4;  // @173_564700
  p8_ = ecx;  // @174_564700
  ecx = esi;  // @175_564700
  eax = ext_564600_thiscall2(ecx, (u32)(p8_));  // @176_564700
  ecx = edx = 0;  // @177_564700
  L5649f4:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 3214), &v, sizeof v); }  // @179_564700
  L5649fa:;
  __asm__ volatile("" :: "Yz"(x0));  // @181_564700
  return eax;  // @182_564700
}
PCREG(564700, lifted_564700);

extern "C" u32 THISCALL lifted_457030(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666498);  // @h_457030
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_457030
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_457030
  eax = ext_4519a0_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_457030
  ecx = edx = 0;  // @3_457030
  { u32 v = (u32)((u32)(6828256)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_457030
  ecx = (u32)(esi + 68);  // @5_457030
  x1 = _mm_load_ss((const float *)(u32)(6806020));  // @6_457030
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 136), &v, sizeof v); }  // @7_457030
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @8_457030
  { u32 v = (u32)((u32)(1109393408)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @9_457030
  { u32 v = (u32)((u32)(1119092736)); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @10_457030
  { u32 v = (u32)((u32)(1117782016)); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @11_457030
  { u32 v = (u32)((u32)(1119092736)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @12_457030
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @13_457030
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @14_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 193), &v, sizeof v); }  // @15_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 197), &v, sizeof v); }  // @16_457030
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 201), &v, sizeof v); }  // @17_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 205), &v, sizeof v); }  // @18_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 209), &v, sizeof v); }  // @19_457030
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 213), &v, sizeof v); }  // @20_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @21_457030
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @22_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @23_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 172), &v, sizeof v); }  // @24_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @25_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @26_457030
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(esi + 189), &v, sizeof v); }  // @27_457030
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @28_457030
  x0 = _mm_load_ss((const float *)(u32)(esi + 144));  // @29_457030
  x0 = _mm_mul_ss(x0, x1);  // @30_457030
  reg.state = (s32)((u32)(0));  // @31_457030
  _mm_store_ss((float *)(u32)(esi + 144), x0);  // @32_457030
  x0 = _mm_load_ss((const float *)(u32)(esi + 148));  // @33_457030
  x0 = _mm_mul_ss(x0, x1);  // @34_457030
  _mm_store_ss((float *)(u32)(esi + 148), x0);  // @35_457030
  x0 = _mm_load_ss((const float *)(u32)(esi + 152));  // @36_457030
  x0 = _mm_mul_ss(x0, x1);  // @37_457030
  _mm_store_ss((float *)(u32)(esi + 152), x0);  // @38_457030
  x0 = _mm_load_ss((const float *)(u32)(esi + 156));  // @39_457030
  x0 = _mm_mul_ss(x0, x1);  // @40_457030
  _mm_store_ss((float *)(u32)(esi + 156), x0);  // @41_457030
  { u32 v = (u32)((u32)(1148846080)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @42_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @43_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @44_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @45_457030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @46_457030
  eax = ext_4de7a0_thiscall1(ecx);  // @47_457030
  ecx = edx = 0;  // @48_457030
  eax = esi;  // @49_457030
  SEH_LEAVE();  // @50_457030
  __asm__ volatile("" :: "Yz"(x0));  // @51_457030
  return eax;  // @52_457030
}
PCREG(457030, lifted_457030);

extern "C" u32 THISCALL lifted_4c44f0(u32 ecx_in) {
  SEH_ENTER(0x664d1b);  // @h_4c44f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4c44f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4c44f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 126), sizeof v); (u32)v; }));  // @4_4c44f0
  ecx = edx = 0;  // @5_4c44f0
  esi = eax;  // @6_4c44f0
  if ((esi & esi) == 0) goto L4c45a7;  // @7_4c44f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_4c44f0
  ecx = esi;  // @9_4c44f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @10_4c44f0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2097381));  // @11_4c44f0
  ecx = edx = 0;  // @12_4c44f0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4c45a7;  // @13_4c44f0
  eax = (u32)(ebx + 134);  // @14_4c44f0
  ecx = esi;  // @15_4c44f0
  p0_ = eax;  // @16_4c44f0
  eax = (u32)(ebx + 130);  // @17_4c44f0
  p1_ = eax;  // @18_4c44f0
  eax = ext_456b70_thiscall3(ecx, (u32)(p1_), (u32)(p0_));  // @19_4c44f0
  ecx = edx = 0;  // @20_4c44f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 162), &v, sizeof v); }  // @21_4c44f0
  L4c4570:;
  x0 = _mm_load_ss((const float *)(u32)(esi + 40));  // @23_4c44f0
  x0 = _mm_add_ss(x0, _mm_load_ss((const float *)(u32)(ebx + 162)));  // @24_4c44f0
  _mm_store_ss((float *)(u32)(ebx + 162), x0);  // @25_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_4c44f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @27_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4c44f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; }));  // @29_4c44f0
  ecx = edx = 0;  // @30_4c44f0
  esi = eax;  // @31_4c44f0
  if ((esi & esi) != 0) goto L4c4570;  // @32_4c44f0
  ecx = ebx;  // @33_4c44f0
  eax = ext_4c3e80_thiscall1(ecx);  // @34_4c44f0
  ecx = edx = 0;  // @35_4c44f0
  goto L4c4608;  // @36_4c44f0
  L4c45a7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @38_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4c44f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6897740), (u32)(201));  // @40_4c44f0
  ecx = edx = 0;  // @41_4c44f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @42_4c44f0
  edi = eax;  // @43_4c44f0
  eax = (u32)(EBP - 144);  // @44_4c44f0
  p2_ = eax;  // @45_4c44f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4c44f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p2_), (u32)(1));  // @47_4c44f0
  ecx = edx = 0;  // @48_4c44f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @49_4c44f0
  ecx = eax;  // @50_4c44f0
  reg.state = (s32)((u32)(0));  // @51_4c44f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @52_4c44f0
  ecx = edx = 0;  // @53_4c44f0
  p3_ = eax;  // @54_4c44f0
  p4_ = edi;  // @55_4c44f0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p4_), (u32)(6897844), (u32)(p3_));  // @56_4c44f0
  ecx = edx = 0;  // @57_4c44f0
  reg.state = (s32)((u32)(4294967295));  // @58_4c44f0
  ecx = (u32)(EBP - 144);  // @59_4c44f0
  eax = ext_4cbec0_thiscall1(ecx);  // @60_4c44f0
  ecx = edx = 0;  // @61_4c44f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_4c44f0
  ecx = ebx;  // @63_4c44f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @64_4c44f0
  ecx = edx = 0;  // @65_4c44f0
  L4c4608:;
  SEH_LEAVE();  // @67_4c44f0
  ext_633654(G(u32, 0x6f5630));  // @68_4c44f0
  __asm__ volatile("" :: "Yz"(x0));  // @69_4c44f0
  return eax;  // @70_4c44f0
}
PCREG(4c44f0, lifted_4c44f0);

extern "C" u32 THISCALL lifted_4b56b0(u32 ecx_in) {
  SEH_ENTER(0x6685bb);  // @h_4b56b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4b56b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_4b56b0
  ecx = edx = 0;  // @5_4b56b0
  ecx = (u32)(EBP - 148);  // @6_4b56b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @7_4b56b0
  p0_ = ecx;  // @8_4b56b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_4b56b0
  ecx = eax;  // @10_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6852480), (u32)(p0_));  // @11_4b56b0
  ecx = edx = 0;  // @12_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @13_4b56b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 140), &v, sizeof v); }  // @14_4b56b0
  eax = 0;  // @15_4b56b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @16_4b56b0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 238), sizeof v); (u32)v; }) <= (s32)eax) goto L4b5818;  // @17_4b56b0
  L4b5733:;
  p1_ = eax;  // @19_4b56b0
  ecx = ebx;  // @20_4b56b0
  eax = ext_4b5620_thiscall2(ecx, (u32)(p1_));  // @21_4b56b0
  ecx = edx = 0;  // @22_4b56b0
  edi = eax;  // @23_4b56b0
  if ((edi & edi) == 0) goto L4b57ff;  // @24_4b56b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @25_4b56b0
  eax = (u32)(EBP - 148);  // @26_4b56b0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @27_4b56b0
  p2_ = eax;  // @28_4b56b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @29_4b56b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @30_4b56b0
  p3_ = ecx;  // @31_4b56b0
  p4_ = edi;  // @32_4b56b0
  ecx = edx;  // @33_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, (u32)(p4_), (u32)(p3_), (u32)(p2_));  // @34_4b56b0
  ecx = edx = 0;  // @35_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @36_4b56b0
  if ((eax & eax) != 0) goto L4b57a6;  // @37_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @38_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(518));  // @40_4b56b0
  ecx = edx = 0;  // @41_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @42_4b56b0
  edx = (u32)(6801640);  // @43_4b56b0
  if ((ecx & ecx) != 0) edx = ecx;  // @44_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_4b56b0
  p5_ = edx;  // @46_4b56b0
  p6_ = eax;  // @47_4b56b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p6_), (u32)(6889600), (u32)(p5_));  // @48_4b56b0
  ecx = edx = 0;  // @49_4b56b0
  goto L4b57ff;  // @50_4b56b0
  L4b57a6:;
  x0 = _mm_load_ss((const float *)(u32)(eax + 4));  // @52_4b56b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(ebx + 222)));  // @53_4b56b0
  if (!(fa_ > fb_)) goto L4b57bc;  // @54_4b56b0
  _mm_store_ss((float *)(u32)(ebx + 222), x0);  // @55_4b56b0
  L4b57bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @57_4b56b0
  ecx = (u32)(6801640);  // @58_4b56b0
  if ((eax & eax) != 0) ecx = eax;  // @59_4b56b0
  eax = (u32)(6889640);  // @60_4b56b0
  L4b57d0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @62_4b56b0
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L4b57f0;  // @63_4b56b0
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L4b57ec;  // @64_4b56b0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @65_4b56b0
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L4b57f0;  // @66_4b56b0
  ecx = (ecx + (u32)(2));  // @67_4b56b0
  eax = (eax + (u32)(2));  // @68_4b56b0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L4b57d0;  // @69_4b56b0
  L4b57ec:;
  eax = 0;  // @71_4b56b0
  goto L4b57f5;  // @72_4b56b0
  L4b57f0:;
  eax = 0;  // @74_4b56b0
  eax = (eax | (u32)(1));  // @75_4b56b0
  L4b57f5:;
  if ((eax & eax) != 0) goto L4b57ff;  // @77_4b56b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 222), &v, sizeof v); }  // @78_4b56b0
  L4b57ff:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @80_4b56b0
  eax = (eax + 1);  // @81_4b56b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @82_4b56b0
  if ((s32)eax < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 238), sizeof v); (u32)v; })) goto L4b5733;  // @83_4b56b0
  L4b5818:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; }) == (u32)(0)) goto L4b58b2;  // @85_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @86_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(534));  // @88_4b56b0
  ecx = edx = 0;  // @89_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @90_4b56b0
  edi = eax;  // @91_4b56b0
  eax = (u32)(EBP - 144);  // @92_4b56b0
  p7_ = eax;  // @93_4b56b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 476)))(ecx, (u32)(p7_), (u32)(1));  // @95_4b56b0
  ecx = edx = 0;  // @96_4b56b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @97_4b56b0
  ecx = eax;  // @98_4b56b0
  reg.state = (s32)((u32)(0));  // @99_4b56b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @100_4b56b0
  ecx = edx = 0;  // @101_4b56b0
  p8_ = eax;  // @102_4b56b0
  p9_ = edi;  // @103_4b56b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p9_), (u32)(6889660), (u32)(p8_));  // @104_4b56b0
  ecx = edx = 0;  // @105_4b56b0
  reg.state = (s32)((u32)(4294967295));  // @106_4b56b0
  ecx = (u32)(EBP - 144);  // @107_4b56b0
  eax = ext_4cbec0_thiscall1(ecx);  // @108_4b56b0
  ecx = edx = 0;  // @109_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @110_4b56b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @111_4b56b0
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx + 155), &v, sizeof v); }  // @112_4b56b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 292)))(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @114_4b56b0
  ecx = edx = 0;  // @115_4b56b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @116_4b56b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 78), sizeof v); (u32)v; });  // @117_4b56b0
  p10_ = eax;  // @118_4b56b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4b56b0
  p11_ = ecx;  // @120_4b56b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, (u32)(p11_), (u32)(p10_), (u32)(0));  // @121_4b56b0
  ecx = edx = 0;  // @122_4b56b0
  L4b58b2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @124_4b56b0
  ecx = ebx;  // @125_4b56b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 140)))(ecx);  // @126_4b56b0
  ecx = edx = 0;  // @127_4b56b0
  SEH_LEAVE();  // @128_4b56b0
  ext_633654(G(u32, 0x6f5630));  // @129_4b56b0
  __asm__ volatile("" :: "Yz"(x0));  // @130_4b56b0
  return eax;  // @131_4b56b0
}
PCREG(4b56b0, lifted_4b56b0);

extern "C" u32 THISCALL lifted_4ef3f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66988b);  // @h_4ef3f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  float fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4ef3f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @1_4ef3f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4ef3f0
  p0_ = edi;  // @3_4ef3f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @4_4ef3f0
  eax = ext_4ef660_thiscall2(ecx, (u32)(p0_));  // @5_4ef3f0
  ecx = edx = 0;  // @6_4ef3f0
  eax = (u32)(EBP - 160);  // @7_4ef3f0
  ecx = edi;  // @8_4ef3f0
  p1_ = eax;  // @9_4ef3f0
  eax = ext_4e1440_thiscall2(ecx, (u32)(p1_));  // @10_4ef3f0
  ecx = edx = 0;  // @11_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 155), sizeof v); (u32)v; });  // @12_4ef3f0
  if ((edx & edx) == 0) goto L4ef45c;  // @13_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_4ef3f0
  p2_ = edx;  // @15_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, (u32)(p2_));  // @17_4ef3f0
  ecx = edx = 0;  // @18_4ef3f0
  L4ef45c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @20_4ef3f0
  ecx = (u32)(6915152);  // @21_4ef3f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @22_4ef3f0
  eax = edx;  // @23_4ef3f0
  L4ef473:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @25_4ef3f0
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L4ef493;  // @26_4ef3f0
  if (((ebx & 0xff) & (ebx & 0xff)) == 0) goto L4ef48f;  // @27_4ef3f0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @28_4ef3f0
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L4ef493;  // @29_4ef3f0
  eax = (eax + (u32)(2));  // @30_4ef3f0
  ecx = (ecx + (u32)(2));  // @31_4ef3f0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L4ef473;  // @32_4ef3f0
  L4ef48f:;
  eax = 0;  // @34_4ef3f0
  goto L4ef498;  // @35_4ef3f0
  L4ef493:;
  eax = 0;  // @37_4ef3f0
  eax = (eax | (u32)(1));  // @38_4ef3f0
  L4ef498:;
  if ((eax & eax) != 0) goto L4ef4d7;  // @40_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; });  // @41_4ef3f0
  if (eax == (u32)(55)) goto L4ef4ac;  // @42_4ef3f0
  if (eax != (u32)(56)) goto L4ef4d7;  // @43_4ef3f0
  L4ef4ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 248)))(ecx, (u32)(35));  // @47_4ef3f0
  ecx = edx = 0;  // @48_4ef3f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @49_4ef3f0
  edx = (u32)(6915192);  // @50_4ef3f0
  L4ef4c7:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @52_4ef3f0
  edx = (u32)(edx + 1);  // @53_4ef3f0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @54_4ef3f0
  eax = (u32)(eax + 1);  // @55_4ef3f0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L4ef4c7;  // @56_4ef3f0
  goto L4ef51e;  // @57_4ef3f0
  L4ef4d7:;
  ecx = (u32)(edx + 1);  // @59_4ef3f0
  L4ef4e0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @61_4ef3f0
  edx = (edx + 1);  // @62_4ef3f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4ef4e0;  // @63_4ef3f0
  edx = (edx - ecx);  // @64_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_4ef3f0
  eax = (u32)(edx + 1);  // @66_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_4ef3f0
  eax = (eax & 0xffff);  // @68_4ef3f0
  p3_ = eax;  // @69_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, (u32)(p3_));  // @70_4ef3f0
  ecx = edx = 0;  // @71_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @72_4ef3f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @73_4ef3f0
  L4ef510:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @75_4ef3f0
  edx = (u32)(edx + 1);  // @76_4ef3f0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @77_4ef3f0
  eax = (u32)(eax + 1);  // @78_4ef3f0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L4ef510;  // @79_4ef3f0
  L4ef51e:;
  eax = (u32)(EBP - 164);  // @81_4ef3f0
  ecx = edi;  // @82_4ef3f0
  p4_ = eax;  // @83_4ef3f0
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p4_), (u32)(1));  // @84_4ef3f0
  ecx = edx = 0;  // @85_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @86_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @87_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }));  // @89_4ef3f0
  ecx = edx = 0;  // @90_4ef3f0
  if ((eax & eax) == 0) goto L4ef555;  // @91_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_4ef3f0
  ecx = esi;  // @93_4ef3f0
  p5_ = eax;  // @94_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 636)))(ecx, (u32)(p5_));  // @95_4ef3f0
  ecx = edx = 0;  // @96_4ef3f0
  goto L4ef5c0;  // @97_4ef3f0
  L4ef555:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @99_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6912796), (u32)(1312));  // @101_4ef3f0
  ecx = edx = 0;  // @102_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @103_4ef3f0
  edi = eax;  // @104_4ef3f0
  eax = (u32)(EBP - 156);  // @105_4ef3f0
  ecx = esi;  // @106_4ef3f0
  p6_ = eax;  // @107_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p6_), (u32)(1));  // @108_4ef3f0
  ecx = edx = 0;  // @109_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @110_4ef3f0
  ecx = eax;  // @111_4ef3f0
  reg.state = (s32)((u32)(0));  // @112_4ef3f0
  eax = ext_4cc1d0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }));  // @113_4ef3f0
  ecx = edx = 0;  // @114_4ef3f0
  p7_ = eax;  // @115_4ef3f0
  p8_ = edi;  // @116_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(p8_), (u32)(6915228), (u32)(p7_));  // @117_4ef3f0
  ecx = edx = 0;  // @118_4ef3f0
  reg.state = (s32)((u32)(4294967295));  // @119_4ef3f0
  ecx = (u32)(EBP - 156);  // @120_4ef3f0
  eax = ext_4cbec0_thiscall1(ecx);  // @121_4ef3f0
  ecx = edx = 0;  // @122_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @123_4ef3f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @124_4ef3f0
  L4ef5c0:;
  eax = (u32)(EBP - 28);  // @126_4ef3f0
  ecx = edi;  // @127_4ef3f0
  p9_ = eax;  // @128_4ef3f0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(p9_), (u32)(3));  // @129_4ef3f0
  ecx = edx = 0;  // @130_4ef3f0
  x1 = _mm_load_ss((const float *)(u32)(6860568));  // @131_4ef3f0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 28));  // @132_4ef3f0
  x0 = _mm_div_ss(x0, x1);  // @133_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @134_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @135_4ef3f0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6915412)));  // @136_4ef3f0
  edx = (u32)_mm_cvtss_si32(x0);  // @137_4ef3f0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 20));  // @138_4ef3f0
  x0 = _mm_div_ss(x0, x1);  // @139_4ef3f0
  edx = (edx & (u32)(16711680));  // @140_4ef3f0
  x0 = _mm_mul_ss(x0, x1);  // @141_4ef3f0
  eax = (u32)_mm_cvtss_si32(x0);  // @142_4ef3f0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 24));  // @143_4ef3f0
  x0 = _mm_div_ss(x0, x1);  // @144_4ef3f0
  eax = (eax & 0xff);  // @145_4ef3f0
  edx = (edx | eax);  // @146_4ef3f0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6915408)));  // @147_4ef3f0
  eax = (u32)_mm_cvtss_si32(x0);  // @148_4ef3f0
  eax = (eax & (u32)(65280));  // @149_4ef3f0
  edx = (edx | eax);  // @150_4ef3f0
  p10_ = edx;  // @151_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 584)))(ecx, (u32)(p10_));  // @152_4ef3f0
  ecx = edx = 0;  // @153_4ef3f0
  ecx = edi;  // @154_4ef3f0
  eax = ext_4e1b30_thiscall1(ecx);  // @155_4ef3f0
  ecx = edx = 0;  // @156_4ef3f0
  SEH_LEAVE();  // @157_4ef3f0
  ext_633654(G(u32, 0x6f5630));  // @158_4ef3f0
  __asm__ volatile("" :: "Yz"(x0));  // @159_4ef3f0
  return eax;  // @160_4ef3f0
}
PCREG(4ef3f0, lifted_4ef3f0);

