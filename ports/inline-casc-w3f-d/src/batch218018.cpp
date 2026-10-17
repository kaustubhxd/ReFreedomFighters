// batch218018.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_43de40_thiscall4(u32, u32, u32, u32) __asm__("ext_43de40");
extern "C" u32 THISCALL ext_456b70_thiscall3(u32, u32, u32) __asm__("ext_456b70");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4c3e80_thiscall1(u32) __asm__("ext_4c3e80");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4d81f0_thiscall1(u32) __asm__("ext_4d81f0");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4db670_thiscall2(u32, u32) __asm__("ext_4db670");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e6330_thiscall2(u32, u32) __asm__("ext_4e6330");
extern "C" u32 THISCALL ext_523650_thiscall2(u32, u32) __asm__("ext_523650");
extern "C" u32 THISCALL ext_5ad790_thiscall1(u32) __asm__("ext_5ad790");
extern "C" u32 THISCALL ext_5f4630_thiscall1(u32) __asm__("ext_5f4630");
extern "C" u32 THISCALL ext_600e40_thiscall3(u32, u32, u32) __asm__("ext_600e40");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)



extern "C" u32 THISCALL lifted_6353d0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66e71f);  // @h_6353d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  esi = ecx;  // @0_6353d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6353d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @2_6353d0
  X0[1] = 0;  // @3_6353d0
  X0[2] = 0;  // @4_6353d0
  X0[3] = 0;  // @5_6353d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @6_6353d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @7_6353d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 37), &v, sizeof v); }  // @8_6353d0
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 77), &v, sizeof v); }  // @9_6353d0
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 81), &v, sizeof v); }  // @10_6353d0
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 85), &v, sizeof v); }  // @11_6353d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @12_6353d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @13_6353d0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @14_6353d0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @15_6353d0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @16_6353d0
  __builtin_memcpy((void *)((u32)(esi + 102) + 0), &X0[0], 4);  // @17_6353d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 106), &v, sizeof v); }  // @18_6353d0
  eax = ext_41e290_cdecl1((u32)(28));  // @19_6353d0
  ecx = edx = 0;  // @20_6353d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @21_6353d0
  reg.state = (s32)((u32)(0));  // @22_6353d0
  if ((eax & eax) == 0) goto L635466;  // @23_6353d0
  ecx = eax;  // @24_6353d0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(64), (u32)(30));  // @25_6353d0
  ecx = edx = 0;  // @26_6353d0
  goto L635468;  // @27_6353d0
  L635466:;
  eax = 0;  // @29_6353d0
  L635468:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @31_6353d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; })) & 0xff);  // @32_6353d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @33_6353d0
  eax = esi;  // @34_6353d0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @35_6353d0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 111), &v, sizeof v); }  // @36_6353d0
  SEH_LEAVE();  // @37_6353d0
  return eax;  // @38_6353d0
}
PCREG(6353d0, lifted_6353d0);




extern "C" u32 THISCALL lifted_4d3e00(u32 ecx_in) {
  SEH_ENTER(0x66942e);  // @h_4d3e00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4d3e00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4d3e00
  ecx = (u32)(esi + 4315);  // @2_4d3e00
  { u32 v = (u32)((u32)(6907264)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_4d3e00
  eax = ext_4d81f0_thiscall1(ecx);  // @4_4d3e00
  ecx = edx = 0;  // @5_4d3e00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7), &v, sizeof v); }  // @6_4d3e00
  edi = (u32)(esi + 15);  // @7_4d3e00
  { u32 v = (u32)((u32)(1045220557)); __builtin_memcpy((void *)(u32)(esi + 11), &v, sizeof v); }  // @8_4d3e00
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @9_4d3e00
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6), &v, sizeof v); }  // @10_4d3e00
  { u16 v = (u16)((u32)(62)); __builtin_memcpy((void *)(u32)(esi + 4103), &v, sizeof v); }  // @11_4d3e00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4303), &v, sizeof v); }  // @12_4d3e00
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4331), &v, sizeof v); }  // @13_4d3e00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4015), &v, sizeof v); }  // @14_4d3e00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4019), &v, sizeof v); }  // @15_4d3e00
  esi = (u32)(1000);  // @16_4d3e00
  reg.state = (s32)((u32)(0));  // @17_4d3e00
  L4d3e90:;
  eax = ext_41e290_cdecl1((u32)(150));  // @19_4d3e00
  ecx = edx = 0;  // @20_4d3e00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @21_4d3e00
  edi = (u32)(edi + 4);  // @22_4d3e00
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @23_4d3e00
  esi = (esi - (u32)(1));  // @24_4d3e00
  if (esi != 0) goto L4d3e90;  // @25_4d3e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @26_4d3e00
  X0[0] = 0;  // @27_4d3e00
  X0[1] = 0;  // @28_4d3e00
  X0[2] = 0;  // @29_4d3e00
  X0[3] = 0;  // @30_4d3e00
  eax = esi;  // @31_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4023) + 0), &X0[0], 4);  // @32_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4023) + 4), &X0[1], 4);  // @33_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4023) + 8), &X0[2], 4);  // @34_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4023) + 12), &X0[3], 4);  // @35_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4039) + 0), &X0[0], 4);  // @36_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4039) + 4), &X0[1], 4);  // @37_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4039) + 8), &X0[2], 4);  // @38_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4039) + 12), &X0[3], 4);  // @39_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4055) + 0), &X0[0], 4);  // @40_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4055) + 4), &X0[1], 4);  // @41_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4055) + 8), &X0[2], 4);  // @42_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4055) + 12), &X0[3], 4);  // @43_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4071) + 0), &X0[0], 4);  // @44_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4071) + 4), &X0[1], 4);  // @45_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4071) + 8), &X0[2], 4);  // @46_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4071) + 12), &X0[3], 4);  // @47_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4087) + 0), &X0[0], 4);  // @48_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4087) + 4), &X0[1], 4);  // @49_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4087) + 8), &X0[2], 4);  // @50_4d3e00
  __builtin_memcpy((void *)((u32)(esi + 4087) + 12), &X0[3], 4);  // @51_4d3e00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4311), &v, sizeof v); }  // @52_4d3e00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4307), &v, sizeof v); }  // @53_4d3e00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4336), &v, sizeof v); }  // @54_4d3e00
  SEH_LEAVE();  // @55_4d3e00
  return eax;  // @56_4d3e00
}
PCREG(4d3e00, lifted_4d3e00);

extern "C" u32 THISCALL lifted_460e40(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666568);  // @h_460e40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_460e40
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_460e40
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_460e40
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_460e40
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_460e40
  eax = ext_43de40_thiscall4(ecx, PV[2], PV[1], PV[0]);  // @5_460e40
  ecx = edx = 0;  // @6_460e40
  { u32 v = (u32)((u32)(6837472)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_460e40
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 278), &v, sizeof v); }  // @8_460e40
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 274), &v, sizeof v); }  // @9_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @10_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @11_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @12_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @13_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @14_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @15_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @16_460e40
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @17_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @18_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @19_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @20_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 282), &v, sizeof v); }  // @21_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 286), &v, sizeof v); }  // @22_460e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_460e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_460e40
  reg.state = (s32)((u32)(0));  // @25_460e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_460e40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6838368), (u32)(0), (u32)(6838324), (u32)(184));  // @27_460e40
  ecx = edx = 0;  // @28_460e40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 294), &v, sizeof v); }  // @29_460e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_460e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_460e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_460e40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6838388), (u32)(0), (u32)(6838324), (u32)(185));  // @33_460e40
  ecx = edx = 0;  // @34_460e40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 296), &v, sizeof v); }  // @35_460e40
  X0[0] = 0;  // @36_460e40
  X0[1] = 0;  // @37_460e40
  X0[2] = 0;  // @38_460e40
  X0[3] = 0;  // @39_460e40
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 290), &v, sizeof v); }  // @40_460e40
  eax = esi;  // @41_460e40
  __builtin_memcpy((void *)((u32)(esi + 298) + 0), &X0[0], 4);  // @42_460e40
  __builtin_memcpy((void *)((u32)(esi + 298) + 4), &X0[1], 4);  // @43_460e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 306), &v, sizeof v); }  // @44_460e40
  SEH_LEAVE();  // @45_460e40
  return eax;  // @46_460e40
}
PCREG(460e40, lifted_460e40);



extern "C" u32 THISCALL lifted_5bde30(u32 ecx_in) {
  SEH_ENTER(0x66c468);  // @h_5bde30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5bde30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5bde30
  eax = ext_469870_thiscall1(ecx);  // @2_5bde30
  ecx = edx = 0;  // @3_5bde30
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5bde30
  { u32 v = (u32)((u32)(7026024)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2346), &v, sizeof v); }  // @7_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2316), &v, sizeof v); }  // @8_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2320), &v, sizeof v); }  // @9_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2330), &v, sizeof v); }  // @10_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2334), &v, sizeof v); }  // @11_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2338), &v, sizeof v); }  // @12_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2342), &v, sizeof v); }  // @13_5bde30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @14_5bde30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_5bde30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_5bde30
  reg.state = (s32)((u32)(0));  // @17_5bde30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5bde30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7026212), (u32)(0), (u32)(7026156), (u32)(70));  // @19_5bde30
  ecx = edx = 0;  // @20_5bde30
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 2324), &v, sizeof v); }  // @21_5bde30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_5bde30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_5bde30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_5bde30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968680), (u32)(0), (u32)(7026156), (u32)(71));  // @25_5bde30
  ecx = edx = 0;  // @26_5bde30
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 2326), &v, sizeof v); }  // @27_5bde30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_5bde30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_5bde30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5bde30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6858892), (u32)(0), (u32)(7026156), (u32)(72));  // @31_5bde30
  ecx = edx = 0;  // @32_5bde30
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 2328), &v, sizeof v); }  // @33_5bde30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_5bde30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 88) + 0), 4); v; });  // @35_5bde30
  X0[1] = 0;  // @36_5bde30
  X0[2] = 0;  // @37_5bde30
  X0[3] = 0;  // @38_5bde30
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7026332) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7026332) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7026332) + 0), 4); v; }))))))) goto L5bdf6a;  // @39_5bde30
  { u32 v = (u32)((u32)(100)); __builtin_memcpy((void *)(u32)(esi + 2450), &v, sizeof v); }  // @40_5bde30
  eax = esi;  // @41_5bde30
  SEH_LEAVE();  // @42_5bde30
  return eax;  // @43_5bde30
  L5bdf6a:;
  eax = (u32)(30);  // @45_5bde30
  ecx = (u32)(50);  // @46_5bde30
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7026328) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7026328) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7026328) + 0), 4); v; }))))))) eax = ecx;  // @47_5bde30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2450), &v, sizeof v); }  // @48_5bde30
  eax = esi;  // @49_5bde30
  SEH_LEAVE();  // @50_5bde30
  return eax;  // @51_5bde30
}
PCREG(5bde30, lifted_5bde30);

extern "C" u32 THISCALL lifted_4bdaf0(u32 ecx_in) {
  SEH_ENTER(0x668d21);  // @h_4bdaf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4bdaf0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4bdaf0
  eax = ext_469870_thiscall1(ecx);  // @2_4bdaf0
  ecx = edx = 0;  // @3_4bdaf0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4bdaf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4bdaf0
  ecx = (u32)(esi + 76);  // @6_4bdaf0
  reg.state = (s32)((u32)(0));  // @7_4bdaf0
  { u32 v = (u32)((u32)(6896552)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_4bdaf0
  eax = ext_4ccba0_thiscall1(ecx);  // @9_4bdaf0
  ecx = edx = 0;  // @10_4bdaf0
  ecx = (u32)(esi + 252);  // @11_4bdaf0
  reg.state = (s32)((u32)(1));  // @12_4bdaf0
  eax = ext_4ccba0_thiscall1(ecx);  // @13_4bdaf0
  ecx = edx = 0;  // @14_4bdaf0
  eax = 0;  // @15_4bdaf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @16_4bdaf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 248), &v, sizeof v); }  // @17_4bdaf0
  X0[0] = 0;  // @18_4bdaf0
  X0[1] = 0;  // @19_4bdaf0
  X0[2] = 0;  // @20_4bdaf0
  X0[3] = 0;  // @21_4bdaf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 424), &v, sizeof v); }  // @22_4bdaf0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 428), &v, sizeof v); }  // @23_4bdaf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 429), &v, sizeof v); }  // @24_4bdaf0
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(esi + 441), &v, sizeof v); }  // @25_4bdaf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 455), &v, sizeof v); }  // @26_4bdaf0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 459), &v, sizeof v); }  // @27_4bdaf0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 463), &v, sizeof v); }  // @28_4bdaf0
  __builtin_memcpy((void *)((u32)(esi + 443) + 0), &X0[0], 4);  // @29_4bdaf0
  __builtin_memcpy((void *)((u32)(esi + 443) + 4), &X0[1], 4);  // @30_4bdaf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 451), &v, sizeof v); }  // @31_4bdaf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_4bdaf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_4bdaf0
  reg.state = (s32)((u32)(2));  // @34_4bdaf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4bdaf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6896856), (u32)(0), (u32)(6896704), (u32)(3856));  // @36_4bdaf0
  ecx = edx = 0;  // @37_4bdaf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 433), &v, sizeof v); }  // @38_4bdaf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_4bdaf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @40_4bdaf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_4bdaf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6896872), (u32)(0), (u32)(6896704), (u32)(3857));  // @42_4bdaf0
  ecx = edx = 0;  // @43_4bdaf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 435), &v, sizeof v); }  // @44_4bdaf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4bdaf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_4bdaf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4bdaf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6896892), (u32)(0), (u32)(6896704), (u32)(3858));  // @48_4bdaf0
  ecx = edx = 0;  // @49_4bdaf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 437), &v, sizeof v); }  // @50_4bdaf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_4bdaf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_4bdaf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_4bdaf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6896912), (u32)(0), (u32)(6896704), (u32)(3859));  // @54_4bdaf0
  ecx = edx = 0;  // @55_4bdaf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 439), &v, sizeof v); }  // @56_4bdaf0
  eax = esi;  // @57_4bdaf0
  SEH_LEAVE();  // @58_4bdaf0
  return eax;  // @59_4bdaf0
}
PCREG(4bdaf0, lifted_4bdaf0);



extern "C" u32 THISCALL lifted_5ab2e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c1b3);  // @h_5ab2e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5ab2e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_5ab2e0
  { u32 v = (u32)((u32)(7012852)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5ab2e0
  reg.state = (s32)((u32)(0));  // @3_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @4_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @5_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @6_5ab2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_5ab2e0
  ecx = 0;  // @8_5ab2e0
  reg.state = (s32)((u32)(1));  // @9_5ab2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 127), &v, sizeof v); }  // @10_5ab2e0
  if ((eax & eax) == 0) goto L5ab359;  // @11_5ab2e0
  eax = (u32)(esi + 66);  // @12_5ab2e0
  L5ab342:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 40), &v, sizeof v); }  // @14_5ab2e0
  eax = (u32)(eax + 4);  // @15_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @16_5ab2e0
  ecx = (ecx + 1);  // @17_5ab2e0
  if (ecx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 127), sizeof v); (u32)v; })) goto L5ab342;  // @18_5ab2e0
  L5ab359:;
  ecx = (u32)(esi + 132);  // @20_5ab2e0
  eax = ext_4de7a0_thiscall1(ecx);  // @21_5ab2e0
  ecx = edx = 0;  // @22_5ab2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @23_5ab2e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @24_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @25_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @26_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @27_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @28_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 106), &v, sizeof v); }  // @29_5ab2e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @30_5ab2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @31_5ab2e0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 122), &v, sizeof v); }  // @32_5ab2e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 126), &v, sizeof v); }  // @33_5ab2e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 131), &v, sizeof v); }  // @34_5ab2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 118), sizeof v); (u32)v; });  // @35_5ab2e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 110), sizeof v); (u32)v; });  // @36_5ab2e0
  eax = (eax - edi);  // @37_5ab2e0
  eax = (u32)((s32)eax >> (u32)(4));  // @38_5ab2e0
  if (eax >= ecx) goto L5ab43e;  // @39_5ab2e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 114), sizeof v); (u32)v; });  // @40_5ab2e0
  eax = edx;  // @41_5ab2e0
  eax = (eax - edi);  // @42_5ab2e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @43_5ab2e0
  eax = (u32)((s32)eax >> (u32)(4));  // @44_5ab2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @45_5ab2e0
  if ((ecx & ecx) != 0) goto L5ab3d6;  // @46_5ab2e0
  eax = 0;  // @47_5ab2e0
  goto L5ab3e7;  // @48_5ab2e0
  L5ab3d6:;
  eax = ecx;  // @50_5ab2e0
  ecx = (u32)(esi + 110);  // @51_5ab2e0
  eax = (eax << (u32)(4));  // @52_5ab2e0
  PV[0] = (u32)(eax);  // @53_5ab2e0
  eax = ext_6014a0_stdcall1(PV[0]);  // @54_5ab2e0
  ecx = edx = 0;  // @55_5ab2e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @56_5ab2e0
  L5ab3e7:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @58_5ab2e0
  if (edi == edx) goto L5ab406;  // @59_5ab2e0
  ecx = eax;  // @60_5ab2e0
  ecx = (ecx - edi);  // @61_5ab2e0
  L5ab3f2:;
  eax = (u32)(ecx + edi);  // @63_5ab2e0
  if ((eax & eax) == 0) goto L5ab3ff;  // @64_5ab2e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @65_5ab2e0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 4), 4); v; });  // @66_5ab2e0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 8), 4); v; });  // @67_5ab2e0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 12), 4); v; });  // @68_5ab2e0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @69_5ab2e0
  __builtin_memcpy((void *)((u32)(eax) + 4), &X0[1], 4);  // @70_5ab2e0
  __builtin_memcpy((void *)((u32)(eax) + 8), &X0[2], 4);  // @71_5ab2e0
  __builtin_memcpy((void *)((u32)(eax) + 12), &X0[3], 4);  // @72_5ab2e0
  L5ab3ff:;
  edi = (edi + (u32)(16));  // @74_5ab2e0
  if (edi != edx) goto L5ab3f2;  // @75_5ab2e0
  L5ab406:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 118), sizeof v); (u32)v; });  // @77_5ab2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 110), sizeof v); (u32)v; });  // @78_5ab2e0
  eax = (eax - ecx);  // @79_5ab2e0
  eax = (u32)((s32)eax >> (u32)(4));  // @80_5ab2e0
  if ((eax & eax) == 0) goto L5ab422;  // @81_5ab2e0
  eax = (eax << (u32)(4));  // @82_5ab2e0
  PV[1] = (u32)(eax);  // @83_5ab2e0
  PV[2] = (u32)(ecx);  // @84_5ab2e0
  ecx = (u32)(esi + 110);  // @85_5ab2e0
  eax = ext_54f870_stdcall2(PV[2], PV[1]);  // @86_5ab2e0
  ecx = edx = 0;  // @87_5ab2e0
  L5ab422:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @89_5ab2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @90_5ab2e0
  eax = (eax << (u32)(4));  // @91_5ab2e0
  eax = (eax + ecx);  // @92_5ab2e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @93_5ab2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @94_5ab2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @95_5ab2e0
  eax = (eax << (u32)(4));  // @96_5ab2e0
  eax = (eax + ecx);  // @97_5ab2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @98_5ab2e0
  L5ab43e:;
  eax = esi;  // @100_5ab2e0
  SEH_LEAVE();  // @101_5ab2e0
  return eax;  // @102_5ab2e0
}
PCREG(5ab2e0, lifted_5ab2e0);

extern "C" u32 THISCALL lifted_59aa30(u32 ecx_in) {
  SEH_ENTER(0x66bc7a);  // @h_59aa30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_59aa30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_59aa30
  eax = ext_469870_thiscall1(ecx);  // @2_59aa30
  ecx = edx = 0;  // @3_59aa30
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @4_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @5_59aa30
  ecx = (u32)(edi + 87);  // @6_59aa30
  reg.state = (s32)((u32)(0));  // @7_59aa30
  { u32 v = (u32)((u32)(7002848)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @8_59aa30
  eax = ext_5ad790_thiscall1(ecx);  // @9_59aa30
  ecx = edx = 0;  // @10_59aa30
  esi = (u32)(edi + 4196);  // @11_59aa30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @12_59aa30
  ecx = (u32)(esi + 74124);  // @13_59aa30
  { u32 v = (u32)((u32)(7002688)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_59aa30
  eax = ext_4ccd10_thiscall3(ecx, (u32)(1), (u32)(0));  // @15_59aa30
  ecx = edx = 0;  // @16_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 73988), &v, sizeof v); }  // @17_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 73992), &v, sizeof v); }  // @18_59aa30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6991560) + 0), 4); v; });  // @19_59aa30
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6991560) + 4), 4); v; });  // @20_59aa30
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6991560) + 8), 4); v; });  // @21_59aa30
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6991560) + 12), 4); v; });  // @22_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 74160), &v, sizeof v); }  // @23_59aa30
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(esi + 74156), &v, sizeof v); }  // @24_59aa30
  __builtin_memcpy((void *)((u32)(esi + 73996) + 0), &X0[0], 4);  // @25_59aa30
  __builtin_memcpy((void *)((u32)(esi + 73996) + 4), &X0[1], 4);  // @26_59aa30
  __builtin_memcpy((void *)((u32)(esi + 73996) + 8), &X0[2], 4);  // @27_59aa30
  __builtin_memcpy((void *)((u32)(esi + 73996) + 12), &X0[3], 4);  // @28_59aa30
  { u32 v = (u32)((u32)(7002768)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @29_59aa30
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78488), &v, sizeof v); }  // @30_59aa30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78490), &v, sizeof v); }  // @31_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78491), &v, sizeof v); }  // @32_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78495), &v, sizeof v); }  // @33_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78499), &v, sizeof v); }  // @34_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78503), &v, sizeof v); }  // @35_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78507), &v, sizeof v); }  // @36_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78511), &v, sizeof v); }  // @37_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78515), &v, sizeof v); }  // @38_59aa30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @39_59aa30
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 4155), &v, sizeof v); }  // @40_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4159), &v, sizeof v); }  // @41_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4176), &v, sizeof v); }  // @42_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 77), &v, sizeof v); }  // @43_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4164), &v, sizeof v); }  // @44_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78523), &v, sizeof v); }  // @45_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78535), &v, sizeof v); }  // @46_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 78539), &v, sizeof v); }  // @47_59aa30
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(edi + 4172), &v, sizeof v); }  // @48_59aa30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 81), &v, sizeof v); }  // @49_59aa30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4163), &v, sizeof v); }  // @50_59aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @51_59aa30
  reg.state = (s32)((u32)(1));  // @52_59aa30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 11285), &v, sizeof v); }  // @53_59aa30
  eax = ext_41e290_cdecl1((u32)(264));  // @54_59aa30
  ecx = edx = 0;  // @55_59aa30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @56_59aa30
  reg.state = (s32)((u32)(2));  // @57_59aa30
  if ((eax & eax) == 0) goto L59abda;  // @58_59aa30
  ecx = (u32)(edi + 4188);  // @59_59aa30
  PV[0] = (u32)(ecx);  // @60_59aa30
  ecx = eax;  // @61_59aa30
  eax = ext_4d8330_thiscall4(ecx, (u32)(7003020), (u32)(7002980), PV[0]);  // @62_59aa30
  ecx = edx = 0;  // @63_59aa30
  edx = eax;  // @64_59aa30
  goto L59abdc;  // @65_59aa30
  L59abda:;
  edx = 0;  // @67_59aa30
  L59abdc:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 4180), &v, sizeof v); }  // @69_59aa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_59aa30
  PV[1] = (u32)(edx);  // @71_59aa30
  reg.state = (s32)((u32)(1));  // @72_59aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_59aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[1]);  // @74_59aa30
  ecx = edx = 0;  // @75_59aa30
  eax = ext_41e290_cdecl1((u32)(264));  // @76_59aa30
  ecx = edx = 0;  // @77_59aa30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @78_59aa30
  reg.state = (s32)((u32)(3));  // @79_59aa30
  if ((eax & eax) == 0) goto L59ac29;  // @80_59aa30
  ecx = (u32)(edi + 4192);  // @81_59aa30
  PV[2] = (u32)(ecx);  // @82_59aa30
  ecx = eax;  // @83_59aa30
  eax = ext_4d8330_thiscall4(ecx, (u32)(7003052), (u32)(7003032), PV[2]);  // @84_59aa30
  ecx = edx = 0;  // @85_59aa30
  edx = eax;  // @86_59aa30
  goto L59ac2b;  // @87_59aa30
  L59ac29:;
  edx = 0;  // @89_59aa30
  L59ac2b:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 4184), &v, sizeof v); }  // @91_59aa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_59aa30
  PV[3] = (u32)(edx);  // @93_59aa30
  reg.state = (s32)((u32)(1));  // @94_59aa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_59aa30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[3]);  // @96_59aa30
  ecx = edx = 0;  // @97_59aa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4188), &v, sizeof v); }  // @98_59aa30
  eax = edi;  // @99_59aa30
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(edi + 4192), &v, sizeof v); }  // @100_59aa30
  SEH_LEAVE();  // @101_59aa30
  return eax;  // @102_59aa30
}
PCREG(59aa30, lifted_59aa30);

