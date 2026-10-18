// batch218028.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5a0_thiscall1(u32) __asm__("ext_4cc5a0");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4da2f0_thiscall3(u32, u32, u32) __asm__("ext_4da2f0");
extern "C" u32 THISCALL ext_4db550_thiscall1(u32) __asm__("ext_4db550");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_6633d0(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_6633d0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_6633d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_6633d0
  edx = (u32)(EBP - 144);  // @3_6633d0
  PV[0] = (u32)(edx);  // @4_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_6633d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 412)))(ecx, PV[0]);  // @6_6633d0
  ecx = edx = 0;  // @7_6633d0
  ecx = eax;  // @8_6633d0
  reg.state = (s32)((u32)(0));  // @9_6633d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @10_6633d0
  ecx = edx = 0;  // @11_6633d0
  ebx = (ebx + (u32)(74164));  // @12_6633d0
  FL[3] = ebx;  // @13_6633d0
  edx = ebx;  // @14_6633d0
  edx = (edx - eax);  // @15_6633d0
  FL[3] = edx;  // @16_6633d0
  L663433:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @18_6633d0
  eax = (u32)(eax + 1);  // @19_6633d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @20_6633d0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @21_6633d0
  if (FL[2] != 0) goto L663433;  // @22_6633d0
  ecx = (u32)(EBP - 144);  // @23_6633d0
  reg.state = (s32)((u32)(4294967295));  // @24_6633d0
  eax = ext_4cbec0_thiscall1(ecx);  // @25_6633d0
  ecx = edx = 0;  // @26_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @29_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_6633d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @31_6633d0
  ecx = edx = 0;  // @32_6633d0
  esi = eax;  // @33_6633d0
  L663473:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @35_6633d0
  eax = (eax + 1);  // @36_6633d0
  FL[3] = eax;  // @37_6633d0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @38_6633d0
  if (FL[2] != 0) goto L663473;  // @39_6633d0
  eax = (eax - esi);  // @40_6633d0
  FL[3] = eax;  // @41_6633d0
  edi = (u32)(ebx - 1);  // @42_6633d0
  L663480:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @44_6633d0
  edi = (edi + 1);  // @45_6633d0
  FL[3] = edi;  // @46_6633d0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @47_6633d0
  if (FL[2] != 0) goto L663480;  // @48_6633d0
  ecx = eax;  // @49_6633d0
  ecx = (ecx >> (u32)(2));  // @50_6633d0
  FL[3] = ecx;  // @51_6633d0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @52_6633d0
  ecx = eax;  // @53_6633d0
  ecx = (ecx & (u32)(3));  // @54_6633d0
  FL[3] = ecx;  // @55_6633d0
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @56_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @57_6633d0
  PV[1] = (u32)(ebx);  // @58_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @60_6633d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[1], (u32)(0));  // @61_6633d0
  ecx = edx = 0;  // @62_6633d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @63_6633d0
  if (FL[2] != 0) goto L6634d1;  // @64_6633d0
  edi = (u32)(ebx - 1);  // @65_6633d0
  L6634b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @67_6633d0
  edi = (u32)(edi + 1);  // @68_6633d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @69_6633d0
  if (FL[2] != 0) goto L6634b0;  // @70_6633d0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @71_6633d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @72_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @73_6633d0
  PV[2] = (u32)(ebx);  // @74_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_6633d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @76_6633d0
  ecx = edx = 0;  // @77_6633d0
  goto L6634e5;  // @78_6633d0
  L6634d1:;
  ebx = (ebx - 1);  // @80_6633d0
  FL[3] = ebx;  // @81_6633d0
  L6634d2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; })) & 0xff);  // @83_6633d0
  ebx = (ebx + 1);  // @84_6633d0
  FL[3] = ebx;  // @85_6633d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @86_6633d0
  if (FL[2] != 0) goto L6634d2;  // @87_6633d0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @88_6633d0
  edi = ebx;  // @89_6633d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @90_6633d0
  L6634e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @92_6633d0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 73992), &v, sizeof v); }  // @93_6633d0
  SEH_LEAVE();  // @94_6633d0
  ext_633654(G(u32, 0x6f5630));  // @95_6633d0
  return eax;  // @96_6633d0
}
PCREG(6633d0, lifted_6633d0);

extern "C" u32 THISCALL lifted_493260(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667e5f);  // @h_493260
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_493260
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_493260
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 23845), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 23845), &v, sizeof v); }  // @2_493260
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 23845), sizeof v); (u32)v; });  // @3_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @4_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_493260
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6870936), (u32)(4077));  // @6_493260
  ecx = edx = 0;  // @7_493260
  PV[0] = (u32)(eax);  // @8_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_493260
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6873000));  // @10_493260
  ecx = edx = 0;  // @11_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @14_493260
  ecx = edx = 0;  // @15_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_493260
  ecx = edi;  // @17_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 232)))(ecx);  // @18_493260
  ecx = edx = 0;  // @19_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_493260
  ecx = edi;  // @21_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 412)))(ecx);  // @22_493260
  ecx = edx = 0;  // @23_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_493260
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @25_493260
  FL[2] = (edx & edx);  // @26_493260
  if (FL[2] == 0) goto L4932f0;  // @27_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @28_493260
  ecx = edx;  // @29_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 24)))(ecx);  // @30_493260
  ecx = edx = 0;  // @31_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_493260
  L4932f0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @34_493260
  FL[2] = (edx & edx);  // @35_493260
  if (FL[2] == 0) goto L493307;  // @36_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @37_493260
  ecx = edx;  // @38_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 24)))(ecx);  // @39_493260
  ecx = edx = 0;  // @40_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_493260
  L493307:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @43_493260
  FL[2] = (edx & edx);  // @44_493260
  if (FL[2] == 0) goto L49331e;  // @45_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @46_493260
  ecx = edx;  // @47_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 24)))(ecx);  // @48_493260
  ecx = edx = 0;  // @49_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_493260
  L49331e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @53_493260
  ecx = edx = 0;  // @54_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @55_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 164)))(ecx);  // @57_493260
  ecx = edx = 0;  // @58_493260
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @59_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4424), sizeof v); (u32)v; });  // @60_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @61_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4420), sizeof v); (u32)v; });  // @62_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7261), &v, sizeof v); }  // @63_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 132), sizeof v); (u32)v; });  // @64_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2780), &v, sizeof v); }  // @65_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4432), sizeof v); (u32)v; });  // @66_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 3017), &v, sizeof v); }  // @67_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4436), sizeof v); (u32)v; });  // @68_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2796), &v, sizeof v); }  // @69_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4428), sizeof v); (u32)v; });  // @70_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @71_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @72_493260
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @73_493260
  if (FL[0] == FL[1]) goto L4933de;  // @74_493260
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 272), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @75_493260
  if (FL[0] != FL[1]) goto L4933c8;  // @76_493260
  eax = ext_41e290_cdecl1((u32)(44));  // @77_493260
  ecx = edx = 0;  // @78_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @79_493260
  reg.state = (s32)((u32)(0));  // @80_493260
  FL[2] = (eax & eax);  // @81_493260
  if (FL[2] == 0) goto L4933b3;  // @82_493260
  ecx = eax;  // @83_493260
  eax = ext_4ccad0_thiscall3(ecx, (u32)(8), (u32)(0));  // @84_493260
  ecx = edx = 0;  // @85_493260
  goto L4933b5;  // @86_493260
  L4933b3:;
  eax = 0;  // @88_493260
  FL[3] = eax;  // @89_493260
  L4933b5:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 272), &v, sizeof v); }  // @91_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_493260
  reg.state = (s32)((u32)(4294967295));  // @93_493260
  L4933c8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @95_493260
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 272), sizeof v); (u32)v; });  // @96_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_493260
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, PV[1]);  // @98_493260
  ecx = edx = 0;  // @99_493260
  goto L4933ee;  // @100_493260
  L4933de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 272), sizeof v); (u32)v; });  // @102_493260
  FL[2] = (ecx & ecx);  // @103_493260
  if (FL[2] == 0) goto L4933ee;  // @104_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_493260
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @106_493260
  ecx = edx = 0;  // @107_493260
  L4933ee:;
  esi = (u32)(ebx + 140);  // @109_493260
  edi = (edi + (u32)(72));  // @110_493260
  FL[3] = edi;  // @111_493260
  ecx = (u32)(32);  // @112_493260
  eax = (u32)(ebx + 284);  // @113_493260
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @114_493260
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @115_493260
  PV[2] = (u32)(eax);  // @116_493260
  eax = (u32)(esi + 3149);  // @117_493260
  PV[3] = (u32)(eax);  // @118_493260
  eax = ext_634d22_cdecl3(PV[3], PV[2], (u32)(4104));  // @119_493260
  ecx = edx = 0;  // @120_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4388), sizeof v); (u32)v; });  // @121_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 7253), &v, sizeof v); }  // @122_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 128), sizeof v); (u32)v; });  // @123_493260
  FL[2] = (ecx & ecx);  // @124_493260
  if (FL[2] == 0) goto L49343a;  // @125_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @126_493260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @127_493260
  L49343a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @129_493260
  eax = (u32)(ebx + 4396);  // @130_493260
  edx = (u32)(ecx + 64);  // @131_493260
  FL[0] = edx; FL[1] = eax;  // @132_493260
  if (FL[0] == FL[1]) goto L493457;  // @133_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @134_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @135_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_493260
  L493457:;
  eax = (u32)(ebx + 4400);  // @138_493260
  edx = (u32)(ecx + 68);  // @139_493260
  FL[0] = edx; FL[1] = eax;  // @140_493260
  if (FL[0] == FL[1]) goto L49346e;  // @141_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @142_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @143_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @144_493260
  L49346e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_493260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 364)))(ecx);  // @147_493260
  ecx = edx = 0;  // @148_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_493260
  eax = (u32)(ebx + 4404);  // @150_493260
  edx = (u32)(ecx + 48);  // @151_493260
  FL[0] = edx; FL[1] = eax;  // @152_493260
  if (FL[0] == FL[1]) goto L493493;  // @153_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @154_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @155_493260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_493260
  L493493:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4408), sizeof v); (u32)v; });  // @158_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 6407), &v, sizeof v); }  // @159_493260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4440), sizeof v); (u32)v; });  // @160_493260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 200), &v, sizeof v); }  // @161_493260
  SEH_LEAVE();  // @162_493260
  return eax;  // @163_493260
}
PCREG(493260, lifted_493260);

extern "C" u32 THISCALL lifted_45f430(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666866);  // @h_45f430
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_45f430
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @1_45f430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @2_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_45f430
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @4_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @5_45f430
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(262144));  // @6_45f430
  if (FL[2] == 0) goto L45f4a9;  // @7_45f430
  ecx = (u32)(EBP - 272);  // @8_45f430
  ecx = (ecx - 1);  // @9_45f430
  FL[3] = ecx;  // @10_45f430
  L45f490:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @12_45f430
  ecx = (u32)(ecx + 1);  // @13_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @14_45f430
  if (FL[2] != 0) goto L45f490;  // @15_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836280), sizeof v); (u32)v; });  // @16_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @17_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836284), sizeof v); (u32)v; });  // @18_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @19_45f430
  L45f4a9:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(16384));  // @21_45f430
  if (FL[2] == 0) goto L45f5c3;  // @22_45f430
  edx = (u32)(EBP - 272);  // @23_45f430
  edx = (edx - 1);  // @24_45f430
  FL[3] = edx;  // @25_45f430
  L45f4c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @27_45f430
  edx = (u32)(edx + 1);  // @28_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @29_45f430
  if (FL[2] != 0) goto L45f4c0;  // @30_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802596), sizeof v); (u32)v; });  // @31_45f430
  ecx = esi;  // @32_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @33_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802600), sizeof v); (u32)v; });  // @34_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @35_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802604), sizeof v); (u32)v; });  // @36_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @37_45f430
  eax = ext_4db550_thiscall1(ecx);  // @38_45f430
  ecx = edx = 0;  // @39_45f430
  ecx = eax;  // @40_45f430
  FL[2] = (ecx & ecx);  // @41_45f430
  if (FL[2] == 0) goto L45f599;  // @42_45f430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @43_45f430
  if (FL[0] == FL[1]) goto L45f599;  // @44_45f430
  edi = (u32)(EBP - 272);  // @45_45f430
  edi = (edi - 1);  // @46_45f430
  FL[3] = edi;  // @47_45f430
  L45f503:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @49_45f430
  edi = (u32)(edi + 1);  // @50_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @51_45f430
  if (FL[2] != 0) goto L45f503;  // @52_45f430
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6802608), sizeof v); (u32)v; })) & 0xffff);  // @53_45f430
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @54_45f430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @55_45f430
  if (FL[0] <= FL[1]) goto L45f520;  // @56_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_45f430
  goto L45f522;  // @58_45f430
  L45f520:;
  ecx = 0;  // @60_45f430
  FL[3] = ecx;  // @61_45f430
  L45f522:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_45f430
  edx = (u32)(EBP - 400);  // @64_45f430
  PV[0] = (u32)(edx);  // @65_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[0], (u32)(1));  // @66_45f430
  ecx = edx = 0;  // @67_45f430
  ecx = eax;  // @68_45f430
  reg.state = (s32)((u32)(0));  // @69_45f430
  eax = ext_4cc1d0_thiscall1(ecx);  // @70_45f430
  ecx = edx = 0;  // @71_45f430
  edx = eax;  // @72_45f430
  esi = eax;  // @73_45f430
  L45f545:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @75_45f430
  edx = (edx + 1);  // @76_45f430
  FL[3] = edx;  // @77_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @78_45f430
  if (FL[2] != 0) goto L45f545;  // @79_45f430
  edi = (u32)(EBP - 272);  // @80_45f430
  edx = (edx - esi);  // @81_45f430
  FL[3] = edx;  // @82_45f430
  edi = (edi - 1);  // @83_45f430
  FL[3] = edi;  // @84_45f430
  L45f555:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @86_45f430
  edi = (edi + 1);  // @87_45f430
  FL[3] = edi;  // @88_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @89_45f430
  if (FL[2] != 0) goto L45f555;  // @90_45f430
  ecx = edx;  // @91_45f430
  reg.state = (s32)((u32)(4294967295));  // @92_45f430
  ecx = (ecx >> (u32)(2));  // @93_45f430
  FL[3] = ecx;  // @94_45f430
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @95_45f430
  ecx = edx;  // @96_45f430
  ecx = (ecx & (u32)(3));  // @97_45f430
  FL[3] = ecx;  // @98_45f430
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @99_45f430
  ecx = (u32)(EBP - 400);  // @100_45f430
  eax = ext_4cbec0_thiscall1(ecx);  // @101_45f430
  ecx = edx = 0;  // @102_45f430
  edi = (u32)(EBP - 272);  // @103_45f430
  edi = (edi - 1);  // @104_45f430
  FL[3] = edi;  // @105_45f430
  L45f584:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @107_45f430
  edi = (u32)(edi + 1);  // @108_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @109_45f430
  if (FL[2] != 0) goto L45f584;  // @110_45f430
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6802612), sizeof v); (u32)v; })) & 0xffff);  // @111_45f430
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @112_45f430
  goto L45f5c3;  // @113_45f430
  L45f599:;
  ecx = (u32)(EBP - 272);  // @115_45f430
  ecx = (ecx - 1);  // @116_45f430
  FL[3] = ecx;  // @117_45f430
  L45f5a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @119_45f430
  ecx = (u32)(ecx + 1);  // @120_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @121_45f430
  if (FL[2] != 0) goto L45f5a0;  // @122_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802616), sizeof v); (u32)v; });  // @123_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @124_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802620), sizeof v); (u32)v; });  // @125_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @126_45f430
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6802624), sizeof v); (u32)v; })) & 0xffff);  // @127_45f430
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @128_45f430
  L45f5c3:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @130_45f430
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; }) & (u32)(2048));  // @131_45f430
  if (FL[2] == 0) goto L45f5f9;  // @132_45f430
  ecx = (u32)(EBP - 272);  // @133_45f430
  ecx = (ecx - 1);  // @134_45f430
  FL[3] = ecx;  // @135_45f430
  L45f5d6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @137_45f430
  ecx = (u32)(ecx + 1);  // @138_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @139_45f430
  if (FL[2] != 0) goto L45f5d6;  // @140_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836288), sizeof v); (u32)v; });  // @141_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @142_45f430
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6836292), sizeof v); (u32)v; })) & 0xffff);  // @143_45f430
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @144_45f430
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6836294), sizeof v); (u32)v; })) & 0xff);  // @145_45f430
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 6), &v, sizeof v); }  // @146_45f430
  L45f5f9:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; }) & (u32)(1024));  // @148_45f430
  if (FL[2] == 0) goto L45f631;  // @149_45f430
  ecx = (u32)(EBP - 272);  // @150_45f430
  ecx = (ecx - 1);  // @151_45f430
  FL[3] = ecx;  // @152_45f430
  L45f610:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @154_45f430
  ecx = (u32)(ecx + 1);  // @155_45f430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @156_45f430
  if (FL[2] != 0) goto L45f610;  // @157_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836296), sizeof v); (u32)v; });  // @158_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @159_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836300), sizeof v); (u32)v; });  // @160_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @161_45f430
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6836304), sizeof v); (u32)v; })) & 0xff);  // @162_45f430
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @163_45f430
  L45f631:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @165_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @166_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(535));  // @167_45f430
  ecx = edx = 0;  // @168_45f430
  ebx = eax;  // @169_45f430
  edx = (u32)(6801640);  // @170_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @171_45f430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @172_45f430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @173_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @174_45f430
  edi = (edi + (u32)(36));  // @175_45f430
  FL[3] = edi;  // @176_45f430
  FL[2] = (ecx & ecx);  // @177_45f430
  if (FL[2] != 0) edx = ecx;  // @178_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @179_45f430
  eax = (u32)(EBP - 272);  // @180_45f430
  PV[1] = (u32)(eax);  // @181_45f430
  PV[2] = (u32)(edi);  // @182_45f430
  PV[3] = (u32)(edx);  // @183_45f430
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @184_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 536), sizeof v); (u32)v; });  // @185_45f430
  eax = ext_4cc5a0_thiscall1(ecx);  // @186_45f430
  ecx = edx = 0;  // @187_45f430
  PV[5] = (u32)(eax);  // @188_45f430
  PV[6] = (u32)(ebx);  // @189_45f430
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[6], (u32)(6802628), PV[5], PV[4], PV[3], PV[2], PV[1]);  // @190_45f430
  ecx = edx = 0;  // @191_45f430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @192_45f430
  if ((s32)FL[0] <= (s32)FL[1]) goto L45f796;  // @193_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @195_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23861), sizeof v); (u32)v; });  // @196_45f430
  FL[2] = (ecx & ecx);  // @197_45f430
  if (FL[2] == 0) goto L45f796;  // @198_45f430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @199_45f430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @200_45f430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 104), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @201_45f430
  if (FL[0] == FL[1]) goto L45f796;  // @202_45f430
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 104), sizeof v); (u32)v; });  // @203_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @204_45f430
  edx = (u32)(EBP - 532);  // @205_45f430
  PV[8] = (u32)(edx);  // @206_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[8], PV[7]);  // @207_45f430
  ecx = edx = 0;  // @208_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @209_45f430
  esi = eax;  // @210_45f430
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @211_45f430
  FL[2] = (ecx & ecx);  // @212_45f430
  if (FL[2] == 0) goto L45f765;  // @213_45f430
  ebx = 0;  // @214_45f430
  FL[3] = ebx;  // @215_45f430
  FL[2] = (ecx & ecx);  // @216_45f430
  if (FL[2] == 0) goto L45f796;  // @217_45f430
  L45f6f0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @219_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @220_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(548));  // @221_45f430
  ecx = edx = 0;  // @222_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx*4), sizeof v); (u32)v; });  // @223_45f430
  edi = eax;  // @224_45f430
  eax = (u32)(EBP - 528);  // @225_45f430
  PV[9] = (u32)(eax);  // @226_45f430
  eax = ext_4da2f0_thiscall3(ecx, PV[9], (u32)(1));  // @227_45f430
  ecx = edx = 0;  // @228_45f430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @229_45f430
  ecx = eax;  // @230_45f430
  reg.state = (s32)((u32)(1));  // @231_45f430
  eax = ext_4cc1d0_thiscall1(ecx);  // @232_45f430
  ecx = edx = 0;  // @233_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 536), sizeof v); (u32)v; });  // @234_45f430
  PV[10] = (u32)(eax);  // @235_45f430
  PV[11] = (u32)(ebx);  // @236_45f430
  eax = ext_4cc5a0_thiscall1(ecx);  // @237_45f430
  ecx = edx = 0;  // @238_45f430
  PV[12] = (u32)(eax);  // @239_45f430
  PV[13] = (u32)(edi);  // @240_45f430
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[13], (u32)(6836348), PV[12], PV[11], PV[10]);  // @241_45f430
  ecx = edx = 0;  // @242_45f430
  reg.state = (s32)((u32)(4294967295));  // @243_45f430
  ecx = (u32)(EBP - 528);  // @244_45f430
  eax = ext_4cbec0_thiscall1(ecx);  // @245_45f430
  ecx = edx = 0;  // @246_45f430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @247_45f430
  ebx = (ebx + 1);  // @248_45f430
  FL[3] = ebx;  // @249_45f430
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @250_45f430
  if (FL[0] < FL[1]) goto L45f6f0;  // @251_45f430
  goto L45f796;  // @252_45f430
  L45f765:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @254_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @255_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(553));  // @256_45f430
  ecx = edx = 0;  // @257_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 536), sizeof v); (u32)v; });  // @258_45f430
  esi = eax;  // @259_45f430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @260_45f430
  eax = ext_4cc5a0_thiscall1(ecx);  // @261_45f430
  ecx = edx = 0;  // @262_45f430
  PV[14] = (u32)(eax);  // @263_45f430
  PV[15] = (u32)(esi);  // @264_45f430
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[15], (u32)(6836364), PV[14]);  // @265_45f430
  ecx = edx = 0;  // @266_45f430
  L45f796:;
  SEH_LEAVE();  // @268_45f430
  ext_633654(G(u32, 0x6f5630));  // @269_45f430
  return eax;  // @270_45f430
}
PCREG(45f430, lifted_45f430);

