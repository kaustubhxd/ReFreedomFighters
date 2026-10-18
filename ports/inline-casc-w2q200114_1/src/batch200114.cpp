// batch200114.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_41d0c0_fastcall4(u32, u32, u32, u32) __asm__("ext_41d0c0");
extern "C" u32 FASTCALL ext_41d6a0_fastcall2(u32, u32) __asm__("ext_41d6a0");
extern "C" u32 FASTCALL ext_41dc60_fastcall3(u32, u32, u32) __asm__("ext_41dc60");
extern "C" u32 FASTCALL ext_430480_fastcall2(u32, u32) __asm__("ext_430480");
extern "C" u32 FASTCALL ext_4cc780_fastcall2(u32, u32) __asm__("ext_4cc780");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4ce1c0_fastcall4(u32, u32, u32, u32) __asm__("ext_4ce1c0");
extern "C" u32 STDCALL ext_41f190_stdcall1(u32) __asm__("ext_41f190");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_5fb2c0_stdcall1(u32) __asm__("ext_5fb2c0");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 STDCALL ext_658fb0_stdcall1(u32) __asm__("ext_658fb0");
extern "C" u32 THISCALL ext_41d540_thiscall1(u32) __asm__("ext_41d540");
extern "C" u32 THISCALL ext_41e180_thiscall1(u32) __asm__("ext_41e180");
extern "C" u32 THISCALL ext_41e1f0_thiscall1(u32) __asm__("ext_41e1f0");
extern "C" u32 THISCALL ext_41e4b0_thiscall1(u32) __asm__("ext_41e4b0");
extern "C" u32 THISCALL ext_41e590_thiscall1(u32) __asm__("ext_41e590");
extern "C" u32 THISCALL ext_41f3a0_thiscall1(u32) __asm__("ext_41f3a0");
extern "C" u32 THISCALL ext_420a60_thiscall1(u32) __asm__("ext_420a60");
extern "C" u32 THISCALL ext_421080_thiscall1(u32) __asm__("ext_421080");
extern "C" u32 THISCALL ext_421680_thiscall1(u32) __asm__("ext_421680");
extern "C" u32 THISCALL ext_421940_thiscall1(u32) __asm__("ext_421940");
extern "C" u32 THISCALL ext_423e60_thiscall1(u32) __asm__("ext_423e60");
extern "C" u32 THISCALL ext_42a4a0_thiscall2(u32, u32) __asm__("ext_42a4a0");
extern "C" u32 THISCALL ext_42bae0_thiscall1(u32) __asm__("ext_42bae0");
extern "C" u32 THISCALL ext_42cc30_thiscall1(u32) __asm__("ext_42cc30");
extern "C" u32 THISCALL ext_433f30_thiscall1(u32) __asm__("ext_433f30");
extern "C" u32 THISCALL ext_437b00_thiscall2(u32, u32) __asm__("ext_437b00");
extern "C" u32 THISCALL ext_4382e0_thiscall1(u32) __asm__("ext_4382e0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cbf30_thiscall2(u32, u32) __asm__("ext_4cbf30");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4cf940_thiscall4(u32, u32, u32, u32) __asm__("ext_4cf940");
extern "C" u32 THISCALL ext_4cfae0_thiscall1(u32) __asm__("ext_4cfae0");
extern "C" u32 THISCALL ext_4d0f30_thiscall4(u32, u32, u32, u32) __asm__("ext_4d0f30");
extern "C" u32 THISCALL ext_4d5440_thiscall1(u32) __asm__("ext_4d5440");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d8600_thiscall2(u32, u32) __asm__("ext_4d8600");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e7160_thiscall1(u32) __asm__("ext_4e7160");
extern "C" u32 THISCALL ext_54abf0_thiscall1(u32) __asm__("ext_54abf0");
extern "C" u32 THISCALL ext_562b50_thiscall2(u32, u32) __asm__("ext_562b50");
extern "C" u32 THISCALL ext_562c20_thiscall2(u32, u32) __asm__("ext_562c20");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5ebae0_thiscall2(u32, u32) __asm__("ext_5ebae0");
extern "C" u32 THISCALL ext_5ec720_thiscall2(u32, u32) __asm__("ext_5ec720");
extern "C" u32 THISCALL ext_5ed460_thiscall1(u32) __asm__("ext_5ed460");
extern "C" u32 THISCALL ext_5edd80_thiscall2(u32, u32) __asm__("ext_5edd80");
extern "C" u32 THISCALL ext_5eec40_thiscall1(u32) __asm__("ext_5eec40");
extern "C" u32 THISCALL ext_5ef080_thiscall1(u32) __asm__("ext_5ef080");
extern "C" u32 THISCALL ext_5efd10_thiscall1(u32) __asm__("ext_5efd10");
extern "C" u32 THISCALL ext_5f0020_thiscall1(u32) __asm__("ext_5f0020");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f9720_thiscall1(u32) __asm__("ext_5f9720");
extern "C" u32 THISCALL ext_5fa910_thiscall3(u32, u32, u32) __asm__("ext_5fa910");
extern "C" u32 THISCALL ext_5fe3b0_thiscall3(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 THISCALL ext_600be0_thiscall1(u32) __asm__("ext_600be0");
extern "C" u32 THISCALL ext_604170_thiscall2(u32, u32) __asm__("ext_604170");
extern "C" u32 THISCALL ext_605ba0_thiscall2(u32, u32) __asm__("ext_605ba0");
extern "C" u32 THISCALL ext_606a70_thiscall1(u32) __asm__("ext_606a70");
extern "C" u32 THISCALL ext_606ea0_thiscall3(u32, u32, u32) __asm__("ext_606ea0");
extern "C" u32 THISCALL ext_607310_thiscall2(u32, u32) __asm__("ext_607310");
extern "C" u32 THISCALL ext_6073b0_thiscall2(u32, u32) __asm__("ext_6073b0");
extern "C" u32 THISCALL ext_616150_thiscall3(u32, u32, u32) __asm__("ext_616150");
extern "C" u32 THISCALL ext_6162f0_thiscall3(u32, u32, u32) __asm__("ext_6162f0");
extern "C" u32 THISCALL ext_6166c0_thiscall3(u32, u32, u32) __asm__("ext_6166c0");
extern "C" u32 THISCALL ext_6168c0_thiscall3(u32, u32, u32) __asm__("ext_6168c0");
extern "C" u32 THISCALL ext_6168f0_thiscall3(u32, u32, u32) __asm__("ext_6168f0");
extern "C" u32 THISCALL ext_63faa0_thiscall2(u32, u32) __asm__("ext_63faa0");
extern "C" u32 THISCALL ext_6528a0_thiscall1(u32) __asm__("ext_6528a0");
extern "C" u32 THISCALL ext_657da0_thiscall3(u32, u32, u32) __asm__("ext_657da0");
extern "C" u32 THISCALL ext_658020_thiscall1(u32) __asm__("ext_658020");
extern "C" u32 THISCALL ext_658d30_thiscall1(u32) __asm__("ext_658d30");
extern "C" u32 THISCALL ext_658d50_thiscall1(u32) __asm__("ext_658d50");
extern "C" u32 THISCALL ext_662750_thiscall1(u32) __asm__("ext_662750");
extern "C" u32 THISCALL ext_662be0_thiscall1(u32) __asm__("ext_662be0");
extern "C" u32 THISCALL ext_662ed0_thiscall1(u32) __asm__("ext_662ed0");
extern "C" u32 ext_41d200_cdecl0(void) __asm__("ext_41d200");
extern "C" u32 ext_41dd70_cdecl0(void) __asm__("ext_41dd70");
extern "C" u32 ext_41dd90_cdecl0(void) __asm__("ext_41dd90");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_420ea0_cdecl1(...) __asm__("ext_420ea0");
extern "C" u32 ext_42ab62_cdecl1(...) __asm__("ext_42ab62");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl4(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_563500_cdecl0(void) __asm__("ext_563500");
extern "C" u32 ext_633f0f_cdecl1(...) __asm__("ext_633f0f");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_6344f2_cdecl1(...) __asm__("ext_6344f2");
extern "C" u32 ext_634879_cdecl1(...) __asm__("ext_634879");
extern "C" u32 ext_634aae_cdecl1(...) __asm__("ext_634aae");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" u32 ext_634d34_cdecl2(...) __asm__("ext_634d34");
extern "C" u32 ext_634d46_cdecl3(...) __asm__("ext_634d46");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_654c90(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_654c90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_654c90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(0));  // @2_654c90
  ecx = edx = 0;  // @3_654c90
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x67622c))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4593), sizeof v); (u32)v; }));  // @4_654c90
  ecx = edx = 0;  // @5_654c90
  return eax;  // @6_654c90
}
PCREG(654c90, lifted_654c90);

extern "C" u32 THISCALL lifted_4d0b10(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775536), sizeof v); (u32)v; });  // @0_4d0b10
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }) == (u32)(13)) goto L4d0b28;  // @1_4d0b10
  eax = ((u32( *)(u32))(*(u32 *)0x6762ec))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 4), sizeof v); (u32)v; }));  // @2_4d0b10
  ecx = edx = 0;  // @3_4d0b10
  return eax;  // @4_4d0b10
  L4d0b28:;
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x6762ec))();  // @6_4d0b10
  ecx = edx = 0;  // @7_4d0b10
  return eax;  // @8_4d0b10
}
PCREG(4d0b10, lifted_4d0b10);

extern "C" u32 lifted_427120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(EBP - 8);  // @0_427120
  p0_ = eax;  // @1_427120
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676124))((u32)(p0_));  // @2_427120
  ecx = edx = 0;  // @3_427120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @4_427120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @5_427120
  return eax;  // @6_427120
}
PCREG(427120, lifted_427120);

extern "C" u32 THISCALL lifted_4e6700(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @0_4e6700
  if ((eax & eax) != 0) goto L4e670e;  // @1_4e6700
  return eax;  // @2_4e6700
  L4e670e:;
  p0_ = eax;  // @4_4e6700
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760b4))((u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @5_4e6700
  ecx = edx = 0;  // @6_4e6700
  return eax;  // @7_4e6700
}
PCREG(4e6700, lifted_4e6700);

extern "C" u32 lifted_6078a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32( *)(u32))(*(u32 *)0x67649c))((u32)(1347780));  // @0_6078a0
  ecx = edx = 0;  // @1_6078a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6078c9;  // @2_6078a0
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x6764a4))();  // @3_6078a0
  ecx = edx = 0;  // @4_6078a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6078cc;  // @5_6078a0
  eax = ext_42ab62_cdecl1((u32)(7053028));  // @6_6078a0
  ecx = edx = 0;  // @7_6078a0
  L6078c9:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @9_6078a0
  return eax;  // @10_6078a0
  L6078cc:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @12_6078a0
  return eax;  // @13_6078a0
}
PCREG(6078a0, lifted_6078a0);

extern "C" u32 STDCALL lifted_427fd0(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676130))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @0_427fd0
  ecx = edx = 0;  // @1_427fd0
  if ((eax & eax) != 0) goto L428006;  // @2_427fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @3_427fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_427fd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6785452), (u32)(387));  // @5_427fd0
  ecx = edx = 0;  // @6_427fd0
  p0_ = eax;  // @7_427fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_427fd0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6786192));  // @9_427fd0
  ecx = edx = 0;  // @10_427fd0
  L428006:;
  return eax;  // @12_427fd0
}
PCREG(427fd0, lifted_427fd0);

extern "C" u32 THISCALL lifted_41cf20(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_41cf20
  eax = ext_41dd90_cdecl0();  // @1_41cf20
  ecx = edx = 0;  // @2_41cf20
  edx = 0;  // @3_41cf20
  ecx = esi;  // @4_41cf20
  eax = ext_41d0c0_fastcall4(ecx, edx, (u32)(0), (u32)(0));  // @5_41cf20
  ecx = edx = 0;  // @6_41cf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_41cf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @8_41cf20
  eax = ext_41d540_thiscall1(ecx);  // @9_41cf20
  ecx = edx = 0;  // @10_41cf20
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x676078))();  // @11_41cf20
  ecx = edx = 0;  // @12_41cf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @13_41cf20
  ecx = eax;  // @14_41cf20
  eax = ext_41dc60_fastcall3(ecx, edx, (u32)(20));  // @15_41cf20
  ecx = edx = 0;  // @16_41cf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_41cf20
  edx = (u32)(8);  // @18_41cf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @19_41cf20
  eax = ext_41d6a0_fastcall2(ecx, edx);  // @20_41cf20
  ecx = edx = 0;  // @21_41cf20
  eax = ext_41d200_cdecl0();  // @22_41cf20
  ecx = edx = 0;  // @23_41cf20
  eax = ext_41dd70_cdecl0();  // @24_41cf20
  ecx = edx = 0;  // @25_41cf20
  eax = (u32)(1);  // @26_41cf20
  return eax;  // @27_41cf20
}
PCREG(41cf20, lifted_41cf20);

extern "C" u32 THISCALL lifted_4b1bd0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4b1bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b1bd0
  eax = ext_4e5ea0_thiscall1(ecx);  // @2_4b1bd0
  ecx = edx = 0;  // @3_4b1bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @4_4b1bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_4b1bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @6_4b1bd0
  if ((ecx & ecx) == 0) goto L4b1c06;  // @7_4b1bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4b1bd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7236676), (u32)(6887628), (u32)(0));  // @9_4b1bd0
  ecx = edx = 0;  // @10_4b1bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4b1bd0
  L4b1c06:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @13_4b1bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4b1bd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6887828));  // @15_4b1bd0
  ecx = edx = 0;  // @16_4b1bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @17_4b1bd0
  return eax;  // @18_4b1bd0
}
PCREG(4b1bd0, lifted_4b1bd0);

extern "C" u32 THISCALL lifted_425a90(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edx = ecx;  // @0_425a90
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L425abd;  // @1_425a90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 36), sizeof v); (u32)v; }) == (u32)(0)) goto L425ae1;  // @2_425a90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @3_425a90
  eax = (eax << (u32)(8));  // @4_425a90
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @5_425a90
  p0_ = eax;  // @6_425a90
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x67621c))((u32)(0), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }), (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @7_425a90
  ecx = edx = 0;  // @8_425a90
  return eax;  // @9_425a90
  L425abd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 36), sizeof v); (u32)v; });  // @11_425a90
  eax = (u32)(65535);  // @12_425a90
  if ((ecx & ecx) == 0) ecx = eax;  // @13_425a90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @14_425a90
  eax = (eax << (u32)(8));  // @15_425a90
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @16_425a90
  p1_ = eax;  // @17_425a90
  p2_ = ecx;  // @18_425a90
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x6761d4))((u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }), (u32)(p1_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @19_425a90
  ecx = edx = 0;  // @20_425a90
  L425ae1:;
  return eax;  // @22_425a90
}
PCREG(425a90, lifted_425a90);

extern "C" u32 THISCALL lifted_4d29d0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4d29d0
  ebx = 0;  // @1_4d29d0
  esi = 0;  // @2_4d29d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) <= ebx) goto L4d2a0a;  // @3_4d29d0
  L4d29e0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @5_4d29d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi), sizeof v); (u32)v; });  // @6_4d29d0
  ecx = (u32)(edx + esi);  // @7_4d29d0
  esi = (esi + eax);  // @8_4d29d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4d2a05;  // @9_4d29d0
  edx = (edx + ebx);  // @10_4d29d0
  ebx = (ebx + eax);  // @11_4d29d0
  if (esi == ebx) goto L4d2a05;  // @12_4d29d0
  p0_ = eax;  // @13_4d29d0
  p1_ = ecx;  // @14_4d29d0
  p2_ = edx;  // @15_4d29d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676278))((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @16_4d29d0
  ecx = edx = 0;  // @17_4d29d0
  L4d2a05:;
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; })) goto L4d29e0;  // @19_4d29d0
  L4d2a0a:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @21_4d29d0
  return eax;  // @22_4d29d0
}
PCREG(4d29d0, lifted_4d29d0);

extern "C" u32 STDCALL lifted_635380(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_635380
  edi = 0;  // @1_635380
  esi = 0;  // @2_635380
  L635390:;
  p0_ = ebx;  // @4_635380
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))((u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7296809), sizeof v); (u32)v; }));  // @5_635380
  ecx = edx = 0;  // @6_635380
  if ((eax & eax) == 0) goto L6353b9;  // @7_635380
  esi = (esi + (u32)(5));  // @8_635380
  edi = (edi + 1);  // @9_635380
  if (esi != (u32)(390)) goto L635390;  // @10_635380
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @11_635380
  return eax;  // @12_635380
  L6353b9:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + edi*4 + 7296808), sizeof v); (u32)v; })) & 0xff);  // @14_635380
  return eax;  // @15_635380
}
PCREG(635380, lifted_635380);

extern "C" u32 THISCALL lifted_438c60(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_438c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4628), sizeof v); (u32)v; });  // @1_438c60
  if ((ecx & ecx) == 0) goto L438caf;  // @2_438c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_438c60
  edx = (u32)(EBP - 12);  // @4_438c60
  p0_ = edx;  // @5_438c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_438c60
  ecx = edx = 0;  // @7_438c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4628), sizeof v); (u32)v; });  // @8_438c60
  edx = (u32)(EBP - 12);  // @9_438c60
  p1_ = edx;  // @10_438c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_438c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @12_438c60
  ecx = edx = 0;  // @13_438c60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == (u32)(0)) goto L438caf;  // @14_438c60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_438c60
  L438c95:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 21), sizeof v); (u32)v; }) == esi) goto L438cb1;  // @17_438c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4628), sizeof v); (u32)v; });  // @18_438c60
  edx = (u32)(EBP - 12);  // @19_438c60
  p2_ = edx;  // @20_438c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_438c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @22_438c60
  ecx = edx = 0;  // @23_438c60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) != (u32)(0)) goto L438c95;  // @24_438c60
  L438caf:;
  eax = 0;  // @26_438c60
  L438cb1:;
  return eax;  // @28_438c60
}
PCREG(438c60, lifted_438c60);

extern "C" u32 THISCALL lifted_485ac0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_485ac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_485ac0
  eax = ext_4e5ea0_thiscall1(ecx);  // @2_485ac0
  ecx = edx = 0;  // @3_485ac0
  esi = eax;  // @4_485ac0
  edx = esi;  // @5_485ac0
  eax = (u32)(edx + 1);  // @6_485ac0
  L485ad6:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @8_485ac0
  edx = (edx + 1);  // @9_485ac0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L485ad6;  // @10_485ac0
  edx = (edx - eax);  // @11_485ac0
  if (edx < (u32)(128)) goto L485b08;  // @12_485ac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @13_485ac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_485ac0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6867104), (u32)(76));  // @15_485ac0
  ecx = edx = 0;  // @16_485ac0
  p0_ = esi;  // @17_485ac0
  p1_ = eax;  // @18_485ac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_485ac0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p1_), (u32)(6867152), (u32)(p0_));  // @20_485ac0
  ecx = edx = 0;  // @21_485ac0
  L485b08:;
  eax = (u32)(edi + 76);  // @23_485ac0
  p2_ = esi;  // @24_485ac0
  p3_ = eax;  // @25_485ac0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67642c))((u32)(p3_), (u32)(p2_), (u32)(128));  // @26_485ac0
  ecx = edx = 0;  // @27_485ac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @28_485ac0
  eax = ext_4e5e60_thiscall1(ecx);  // @29_485ac0
  ecx = edx = 0;  // @30_485ac0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @31_485ac0
  return eax;  // @32_485ac0
}
PCREG(485ac0, lifted_485ac0);

extern "C" u32 THISCALL lifted_420ae0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @0_420ae0
  ebx = ecx;  // @1_420ae0
  p0_ = ebx;  // @2_420ae0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_420ae0
  eax = ((u32(STDCALL *)(u32, u32))(esi))((u32)(p0_), (u32)(92));  // @4_420ae0
  ecx = edx = 0;  // @5_420ae0
  p1_ = ebx;  // @6_420ae0
  edi = eax;  // @7_420ae0
  eax = ((u32(STDCALL *)(u32, u32))(esi))((u32)(p1_), (u32)(92));  // @8_420ae0
  ecx = edx = 0;  // @9_420ae0
  ebx = eax;  // @10_420ae0
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @11_420ae0
  if ((edi & edi) == 0) goto L420b40;  // @12_420ae0
  if (ebx == (u32)(2)) goto L420b40;  // @13_420ae0
  ecx = (u32)(ebx + 1);  // @14_420ae0
  p2_ = ecx;  // @15_420ae0
  eax = ext_41e290_cdecl1((u32)(p2_));  // @16_420ae0
  ecx = edx = 0;  // @17_420ae0
  p3_ = ebx;  // @18_420ae0
  esi = eax;  // @19_420ae0
  p4_ = esi;  // @20_420ae0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67642c))((u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }), (u32)(p3_));  // @21_420ae0
  ecx = edx = 0;  // @22_420ae0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + ebx), &v, sizeof v); }  // @23_420ae0
  if ((esi & esi) == 0) goto L420b40;  // @24_420ae0
  ecx = esi;  // @25_420ae0
  eax = ext_420a60_thiscall1(ecx);  // @26_420ae0
  ecx = edx = 0;  // @27_420ae0
  p5_ = esi;  // @28_420ae0
  eax = ext_41e2c0_cdecl1((u32)(p5_));  // @29_420ae0
  ecx = edx = 0;  // @30_420ae0
  L420b40:;
  return eax;  // @32_420ae0
}
PCREG(420ae0, lifted_420ae0);

extern "C" u32 THISCALL lifted_41f9b0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  ebx = ecx;  // @0_41f9b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_41f9b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @2_41f9b0
  ecx = edx = 0;  // @3_41f9b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_41f9b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_41f9b0
  p0_ = esi;  // @6_41f9b0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))((u32)(p0_), (u32)(92));  // @7_41f9b0
  ecx = edx = 0;  // @8_41f9b0
  ecx = (u32)(eax + 1);  // @9_41f9b0
  if ((eax & eax) != 0) esi = ecx;  // @10_41f9b0
  ecx = esi;  // @11_41f9b0
  edx = (u32)(ecx + 1);  // @12_41f9b0
  L41f9e0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @14_41f9b0
  ecx = (ecx + 1);  // @15_41f9b0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L41f9e0;  // @16_41f9b0
  ecx = (ecx - edx);  // @17_41f9b0
  eax = (u32)(ecx + 1);  // @18_41f9b0
  p1_ = eax;  // @19_41f9b0
  eax = ((u32( *)(u32))(*(u32 *)0x6762f0))((u32)(p1_));  // @20_41f9b0
  ecx = edx = 0;  // @21_41f9b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 24), &v, sizeof v); }  // @22_41f9b0
  L41fa00:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @24_41f9b0
  esi = (u32)(esi + 1);  // @25_41f9b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @26_41f9b0
  eax = (u32)(eax + 1);  // @27_41f9b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L41fa00;  // @28_41f9b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @29_41f9b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi - 20), &v, sizeof v); }  // @30_41f9b0
  ecx = ebx;  // @31_41f9b0
  p2_ = edi;  // @32_41f9b0
  eax = ext_41f190_stdcall1((u32)(p2_));  // @33_41f9b0
  ecx = edx = 0;  // @34_41f9b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @35_41f9b0
  ecx = ebx;  // @36_41f9b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 232)))(ecx);  // @37_41f9b0
  ecx = edx = 0;  // @38_41f9b0
  eax = edi;  // @39_41f9b0
  return eax;  // @40_41f9b0
}
PCREG(41f9b0, lifted_41f9b0);

extern "C" u32 THISCALL lifted_536750(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 21250), sizeof v); (u32)v; });  // @0_536750
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_536750
  if ((edx & edx) != 0) goto L536769;  // @2_536750
  L536761:;
  eax = 0;  // @4_536750
  return eax;  // @5_536750
  L536769:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_536750
  if ((eax & eax) == 0) goto L536761;  // @8_536750
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_536750
  edx = (edx + eax);  // @10_536750
  esi = 0;  // @11_536750
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @12_536750
  if ((ebx & ebx) == 0) goto L5367a8;  // @13_536750
  L536781:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 21250), sizeof v); (u32)v; });  // @15_536750
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4), sizeof v); (u32)v; });  // @16_536750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @17_536750
  edi = (edi + eax);  // @18_536750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @19_536750
  ecx = (ecx + eax);  // @20_536750
  eax = ext_4cc850_fastcall2(ecx, edx);  // @21_536750
  ecx = edx = 0;  // @22_536750
  if ((eax & eax) == 0) goto L5367b3;  // @23_536750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @24_536750
  esi = (esi + 1);  // @25_536750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @26_536750
  if (esi < ebx) goto L536781;  // @27_536750
  L5367a8:;
  eax = 0;  // @29_536750
  return eax;  // @30_536750
  L5367b3:;
  eax = edi;  // @32_536750
  return eax;  // @33_536750
}
PCREG(536750, lifted_536750);

extern "C" u32 THISCALL lifted_533520(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_533520
  edi = ecx;  // @1_533520
  if ((ebx & ebx) != 0) goto L53353d;  // @2_533520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_533520
  p0_ = ebx;  // @4_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(p0_));  // @5_533520
  ecx = edx = 0;  // @6_533520
  return eax;  // @7_533520
  L53353d:;
  esi = 0;  // @9_533520
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21614), sizeof v); (u32)v; }) <= (s32)esi) goto L53356e;  // @10_533520
  L533548:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_533520
  ecx = edi;  // @13_533520
  p1_ = ebx;  // @14_533520
  p2_ = esi;  // @15_533520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(p2_), (u32)(p1_));  // @16_533520
  ecx = edx = 0;  // @17_533520
  eax = (eax + (u32)(4));  // @18_533520
  p3_ = eax;  // @19_533520
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676414))((u32)(p3_));  // @20_533520
  ecx = edx = 0;  // @21_533520
  if ((eax & eax) == 0) goto L533581;  // @22_533520
  esi = (esi + 1);  // @23_533520
  if ((s32)esi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21614), sizeof v); (u32)v; })) goto L533548;  // @24_533520
  L53356e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_533520
  ecx = edi;  // @27_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(0));  // @28_533520
  ecx = edx = 0;  // @29_533520
  return eax;  // @30_533520
  L533581:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_533520
  ecx = edi;  // @33_533520
  p4_ = esi;  // @34_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(p4_));  // @35_533520
  ecx = edx = 0;  // @36_533520
  return eax;  // @37_533520
}
PCREG(533520, lifted_533520);

extern "C" u32 THISCALL lifted_420a60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ecx;  // @0_420a60
  p0_ = ebx;  // @1_420a60
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760d8))((u32)(p0_));  // @2_420a60
  ecx = edx = 0;  // @3_420a60
  if (eax == (u32)(-1)) goto L420a77;  // @4_420a60
  if (((eax & 0xff) & (u32)(16)) != 0) goto L420ad9;  // @5_420a60
  L420a77:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @7_420a60
  p1_ = ebx;  // @8_420a60
  eax = ((u32(STDCALL *)(u32, u32))(esi))((u32)(p1_), (u32)(92));  // @9_420a60
  ecx = edx = 0;  // @10_420a60
  p2_ = ebx;  // @11_420a60
  edi = eax;  // @12_420a60
  eax = ((u32(STDCALL *)(u32, u32))(esi))((u32)(p2_), (u32)(92));  // @13_420a60
  ecx = edx = 0;  // @14_420a60
  eax = (eax - ebx);  // @15_420a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @16_420a60
  if ((edi & edi) == 0) goto L420ace;  // @17_420a60
  if (eax == (u32)(2)) goto L420ace;  // @18_420a60
  ecx = (u32)(eax + 1);  // @19_420a60
  p3_ = ecx;  // @20_420a60
  eax = ext_41e290_cdecl1((u32)(p3_));  // @21_420a60
  ecx = edx = 0;  // @22_420a60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @23_420a60
  esi = eax;  // @24_420a60
  p4_ = edi;  // @25_420a60
  p5_ = ebx;  // @26_420a60
  p6_ = esi;  // @27_420a60
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67642c))((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @28_420a60
  ecx = edx = 0;  // @29_420a60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @30_420a60
  if ((esi & esi) == 0) goto L420ace;  // @31_420a60
  ecx = esi;  // @32_420a60
  eax = ext_420a60_thiscall1(ecx);  // @33_420a60
  ecx = edx = 0;  // @34_420a60
  p7_ = esi;  // @35_420a60
  eax = ext_41e2c0_cdecl1((u32)(p7_));  // @36_420a60
  ecx = edx = 0;  // @37_420a60
  L420ace:;
  p8_ = ebx;  // @39_420a60
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760d4))((u32)(p8_), (u32)(0));  // @40_420a60
  ecx = edx = 0;  // @41_420a60
  L420ad9:;
  return eax;  // @43_420a60
}
PCREG(420a60, lifted_420a60);

extern "C" u32 THISCALL lifted_4d2b40(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_4d2b40
  ebx = ecx;  // @1_4d2b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4d2b40
  p0_ = esi;  // @3_4d2b40
  p1_ = edi;  // @4_4d2b40
  if ((eax & eax) != 0) goto L4d2b66;  // @5_4d2b40
  edx = ecx;  // @6_4d2b40
  esi = (u32)(edx + 1);  // @7_4d2b40
  L4d2b57:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @9_4d2b40
  edx = (edx + 1);  // @10_4d2b40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d2b57;  // @11_4d2b40
  edx = (edx - esi);  // @12_4d2b40
  eax = (u32)(edx + 1);  // @13_4d2b40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @14_4d2b40
  L4d2b66:;
  edi = 0;  // @16_4d2b40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; }) <= edi) goto L4d2bab;  // @17_4d2b40
  L4d2b70:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @19_4d2b40
  esi = (esi + edi);  // @20_4d2b40
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @21_4d2b40
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4d2b98;  // @22_4d2b40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) != eax) goto L4d2b98;  // @23_4d2b40
  p2_ = eax;  // @24_4d2b40
  eax = (u32)(esi + 17);  // @25_4d2b40
  p3_ = eax;  // @26_4d2b40
  p4_ = ecx;  // @27_4d2b40
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(*(u32 *)0x67640c))((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @28_4d2b40
  ecx = edx = 0;  // @29_4d2b40
  if ((eax & eax) == 0) goto L4d2ba2;  // @30_4d2b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @31_4d2b40
  L4d2b98:;
  if (edi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; })) goto L4d2bab;  // @33_4d2b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @34_4d2b40
  goto L4d2b70;  // @35_4d2b40
  L4d2ba2:;
  eax = esi;  // @37_4d2b40
  return eax;  // @38_4d2b40
  L4d2bab:;
  eax = 0;  // @40_4d2b40
  return eax;  // @41_4d2b40
}
PCREG(4d2b40, lifted_4d2b40);

extern "C" u32 THISCALL lifted_5d8340(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d8340
  esi = ecx;  // @1_5d8340
  ecx = edi;  // @2_5d8340
  eax = ext_4e5ea0_thiscall1(ecx);  // @3_5d8340
  ecx = edx = 0;  // @4_5d8340
  ebx = eax;  // @5_5d8340
  edx = ebx;  // @6_5d8340
  eax = (u32)(edx + 1);  // @7_5d8340
  L5d8360:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @9_5d8340
  edx = (edx + 1);  // @10_5d8340
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L5d8360;  // @11_5d8340
  edx = (edx - eax);  // @12_5d8340
  if (edx <= (u32)(99)) goto L5d837c;  // @13_5d8340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @14_5d8340
  if ((eax & eax) == 0) goto L5d837b;  // @15_5d8340
  eax = ((u32(STDCALL *)(void))(eax))();  // @16_5d8340
  ecx = edx = 0;  // @17_5d8340
  goto L5d837c;  // @18_5d8340
  L5d837b:;
  __builtin_trap();  // @20_5d8340
  L5d837c:;
  eax = (u32)(esi + 78);  // @22_5d8340
  p0_ = ebx;  // @23_5d8340
  p1_ = eax;  // @24_5d8340
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x67642c))((u32)(p1_), (u32)(p0_), (u32)(99));  // @25_5d8340
  ecx = edx = 0;  // @26_5d8340
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 177), &v, sizeof v); }  // @27_5d8340
  ecx = edi;  // @28_5d8340
  eax = ext_4e5e60_thiscall1(ecx);  // @29_5d8340
  ecx = edx = 0;  // @30_5d8340
  eax = (eax & 0xffffff00u) | (((u32)((eax & eax) != 0)) & 0xff);  // @31_5d8340
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 178), &v, sizeof v); }  // @32_5d8340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @33_5d8340
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @34_5d8340
  if ((eax & 0xff) == (u32)(255)) goto L5d83d2;  // @35_5d8340
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @36_5d8340
  if ((eax & 0xff) == (u32)(255)) goto L5d83d2;  // @37_5d8340
  ecx = edi;  // @38_5d8340
  eax = ext_4e5e60_thiscall1(ecx);  // @39_5d8340
  ecx = edx = 0;  // @40_5d8340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_5d8340
  p2_ = eax;  // @42_5d8340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @43_5d8340
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_5d8340
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p2_));  // @45_5d8340
  ecx = edx = 0;  // @46_5d8340
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 188), &v, sizeof v); }  // @47_5d8340
  L5d83d2:;
  return eax;  // @49_5d8340
}
PCREG(5d8340, lifted_5d8340);

extern "C" u32 THISCALL lifted_607260(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edi = ecx;  // @0_607260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 15), sizeof v); (u32)v; });  // @1_607260
  eax = (eax + 1);  // @2_607260
  p0_ = eax;  // @3_607260
  eax = ext_6073b0_thiscall2(ecx, (u32)(p0_));  // @4_607260
  ecx = edx = 0;  // @5_607260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7), sizeof v); (u32)v; });  // @6_607260
  ecx = edi;  // @7_607260
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3), sizeof v); (u32)v; }));  // @8_607260
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_607260
  eax = (u32)((s32)eax >> (u32)(2));  // @10_607260
  p1_ = eax;  // @11_607260
  p2_ = ebx;  // @12_607260
  eax = ext_606ea0_thiscall3(ecx, (u32)(p2_), (u32)(p1_));  // @13_607260
  ecx = edx = 0;  // @14_607260
  ecx = (u32)(eax*4);  // @15_607260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3), sizeof v); (u32)v; });  // @16_607260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @17_607260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @18_607260
  esi = eax;  // @19_607260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @20_607260
  if ((eax & eax) == 0) goto L6072b9;  // @21_607260
  L6072a1:;
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @23_607260
  ecx = edx = 0;  // @24_607260
  if ((eax & eax) == 0) goto L6072f7;  // @25_607260
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_607260
  if ((esi & esi) != 0) goto L6072a1;  // @27_607260
  L6072b9:;
  ecx = edi;  // @29_607260
  eax = ext_6014a0_stdcall1((u32)(10));  // @30_607260
  ecx = edx = 0;  // @31_607260
  edx = eax;  // @32_607260
  eax = (u32)(edx + 4);  // @33_607260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @34_607260
  if ((eax & eax) == 0) goto L6072dd;  // @35_607260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @36_607260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_607260
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xffff);  // @38_607260
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @39_607260
  L6072dd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @41_607260
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @42_607260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @43_607260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3), sizeof v); (u32)v; });  // @44_607260
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + ecx), &v, sizeof v); }  // @45_607260
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 15), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 15), &v, sizeof v); }  // @46_607260
  return eax;  // @47_607260
  L6072f7:;
  eax = (u32)(esi + 4);  // @49_607260
  return eax;  // @50_607260
}
PCREG(607260, lifted_607260);

extern "C" u32 THISCALL lifted_601720(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_601720
  esi = 0;  // @1_601720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) <= esi) goto L601784;  // @2_601720
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_601720
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; })) goto L601745;  // @4_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @5_601720
  if ((eax & eax) == 0) goto L601744;  // @6_601720
  eax = ((u32(STDCALL *)(void))(eax))();  // @7_601720
  ecx = edx = 0;  // @8_601720
  goto L601745;  // @9_601720
  L601744:;
  __builtin_trap();  // @11_601720
  L601745:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @13_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @14_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_601720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L60177e;  // @16_601720
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; })) goto L601765;  // @17_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_601720
  if ((eax & eax) == 0) goto L601764;  // @19_601720
  eax = ((u32(STDCALL *)(void))(eax))();  // @20_601720
  ecx = edx = 0;  // @21_601720
  goto L601765;  // @22_601720
  L601764:;
  __builtin_trap();  // @24_601720
  L601765:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @26_601720
  p0_ = ebx;  // @27_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @28_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @29_601720
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }), (u32)(p0_));  // @30_601720
  ecx = edx = 0;  // @31_601720
  if ((eax & eax) == 0) goto L60178d;  // @32_601720
  L60177e:;
  esi = (esi + 1);  // @34_601720
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; })) goto L601745;  // @35_601720
  L601784:;
  eax = 0;  // @37_601720
  return eax;  // @38_601720
  L60178d:;
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; })) goto L6017b0;  // @40_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @41_601720
  if ((eax & eax) == 0) goto L6017af;  // @42_601720
  eax = ((u32(STDCALL *)(void))(eax))();  // @43_601720
  ecx = edx = 0;  // @44_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @45_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @46_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @48_601720
  return eax;  // @49_601720
  L6017af:;
  __builtin_trap();  // @51_601720
  L6017b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @53_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @54_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @55_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @56_601720
  return eax;  // @57_601720
}
PCREG(601720, lifted_601720);

extern "C" u32 THISCALL lifted_4d3750(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_4d3750
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_4d3750
  if ((edi & edi) != 0) goto L4d377c;  // @2_4d3750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4d3750
  esi = (u32)(edx + 1);  // @4_4d3750
  L4d3770:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @6_4d3750
  edx = (edx + 1);  // @7_4d3750
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d3770;  // @8_4d3750
  edx = (edx - esi);  // @9_4d3750
  edi = (u32)(edx + 1);  // @10_4d3750
  L4d377c:;
  ebx = (u32)(ecx + 16392);  // @12_4d3750
  if ((ebx & ebx) == 0) goto L4d37d0;  // @13_4d3750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_4d3750
  ecx = (u32)(EBP - 16);  // @15_4d3750
  p0_ = ecx;  // @16_4d3750
  ecx = ebx;  // @17_4d3750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @18_4d3750
  ecx = edx = 0;  // @19_4d3750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @20_4d3750
  ecx = (u32)(EBP - 16);  // @21_4d3750
  p1_ = ecx;  // @22_4d3750
  ecx = ebx;  // @23_4d3750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @24_4d3750
  ecx = edx = 0;  // @25_4d3750
  esi = eax;  // @26_4d3750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) == (u32)(0)) goto L4d37d0;  // @27_4d3750
  L4d37a4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != edi) goto L4d37bd;  // @29_4d3750
  p2_ = edi;  // @30_4d3750
  eax = (u32)(esi + 12);  // @31_4d3750
  p3_ = eax;  // @32_4d3750
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x67640c))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p3_), (u32)(p2_));  // @33_4d3750
  ecx = edx = 0;  // @34_4d3750
  if ((eax & eax) == 0) goto L4d37db;  // @35_4d3750
  L4d37bd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_4d3750
  ecx = (u32)(EBP - 16);  // @38_4d3750
  p4_ = ecx;  // @39_4d3750
  ecx = ebx;  // @40_4d3750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p4_));  // @41_4d3750
  ecx = edx = 0;  // @42_4d3750
  esi = eax;  // @43_4d3750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) != (u32)(0)) goto L4d37a4;  // @44_4d3750
  L4d37d0:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @46_4d3750
  return eax;  // @47_4d3750
  L4d37db:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @49_4d3750
  eax = (u32)(esi - 4);  // @50_4d3750
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16388), sizeof v); (u32)v; }));  // @51_4d3750
  ecx = (ecx + (u32)(16564));  // @52_4d3750
  p5_ = eax;  // @53_4d3750
  eax = ext_4ce1c0_fastcall4(ecx, edx, (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @54_4d3750
  ecx = edx = 0;  // @55_4d3750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_4d3750
  ecx = (u32)(EBP - 16);  // @57_4d3750
  p6_ = ecx;  // @58_4d3750
  ecx = ebx;  // @59_4d3750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p6_));  // @60_4d3750
  ecx = edx = 0;  // @61_4d3750
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @62_4d3750
  return eax;  // @63_4d3750
}
PCREG(4d3750, lifted_4d3750);

extern "C" u32 THISCALL lifted_63e910(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63e910
  ebx = ecx;  // @1_63e910
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @3_63e910
  if ((edx & edx) == 0) goto L63e960;  // @4_63e910
  edi = 0;  // @5_63e910
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; }) == (u32)(0)) goto L63e949;  // @6_63e910
  L63e930:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @8_63e910
  if ((eax & eax) == 0) goto L63e93d;  // @9_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @10_63e910
  L63e93d:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; });  // @12_63e910
  edi = (edi + 1);  // @13_63e910
  edx = (edx + (u32)(8));  // @14_63e910
  if (edi != eax) goto L63e930;  // @15_63e910
  L63e949:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; });  // @17_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @18_63e910
  eax = (eax << (u32)(3));  // @19_63e910
  p0_ = eax;  // @20_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 36)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }), (u32)(p0_));  // @21_63e910
  ecx = edx = 0;  // @22_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @23_63e910
  L63e960:;
  ecx = esi;  // @25_63e910
  eax = ext_658d30_thiscall1(ecx);  // @26_63e910
  ecx = edx = 0;  // @27_63e910
  if ((eax & eax) == 0) goto L63e9cb;  // @28_63e910
  p1_ = esi;  // @29_63e910
  ecx = ebx;  // @30_63e910
  eax = ext_63faa0_thiscall2(ecx, (u32)(p1_));  // @31_63e910
  ecx = edx = 0;  // @32_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @33_63e910
  if ((eax & eax) == 0) goto L63e9b2;  // @34_63e910
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @35_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @36_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @37_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_63e910
  p2_ = edx;  // @39_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @40_63e910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @41_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_63e910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 196)))(ecx, (u32)(p2_));  // @43_63e910
  ecx = edx = 0;  // @44_63e910
  ecx = esi;  // @45_63e910
  edi = eax;  // @46_63e910
  eax = ext_658d30_thiscall1(ecx);  // @47_63e910
  ecx = edx = 0;  // @48_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_63e910
  ecx = ebx;  // @50_63e910
  p3_ = edi;  // @51_63e910
  p4_ = eax;  // @52_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 644)))(ecx, (u32)(p4_), (u32)(p3_));  // @53_63e910
  ecx = edx = 0;  // @54_63e910
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @55_63e910
  L63e9b2:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_63e910
  ecx = esi;  // @58_63e910
  eax = ext_658d50_thiscall1(ecx);  // @59_63e910
  ecx = edx = 0;  // @60_63e910
  p5_ = eax;  // @61_63e910
  ecx = ebx;  // @62_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 36)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }), (u32)(p5_));  // @63_63e910
  ecx = edx = 0;  // @64_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @65_63e910
  L63e9cb:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(8)) == 0) goto L63e9ea;  // @67_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @68_63e910
  if ((eax & eax) == 0) goto L63e9ea;  // @69_63e910
  ecx = (u32)(65535);  // @70_63e910
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 62), sizeof v); (u32)v; }) + (ecx & 0xffff))); __builtin_memcpy((void *)(u32)(eax + 62), &v, sizeof v); }  // @71_63e910
  ecx = esi;  // @72_63e910
  eax = ext_658fb0_stdcall1((u32)(0));  // @73_63e910
  ecx = edx = 0;  // @74_63e910
  L63e9ea:;
  return eax;  // @76_63e910
}
PCREG(63e910, lifted_63e910);

extern "C" u32 STDCALL lifted_49e140(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_49e140
  p0_ = esi;  // @1_49e140
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_49e140
  p1_ = edi;  // @3_49e140
  L49e150:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(47)) goto L49e15b;  // @5_49e140
  L49e155:;
  esi = (esi + 1);  // @7_49e140
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(47)) goto L49e155;  // @8_49e140
  L49e15b:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @10_49e140
  edi = 0;  // @11_49e140
  if ((eax & 0xff) == (u32)(47)) goto L49e170;  // @12_49e140
  L49e163:;
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L49e170;  // @14_49e140
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 1), sizeof v); (u32)v; })) & 0xff);  // @15_49e140
  edi = (edi + 1);  // @16_49e140
  if ((eax & 0xff) != (u32)(47)) goto L49e163;  // @17_49e140
  L49e170:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @19_49e140
  ecx = (u32)(edx + 1);  // @20_49e140
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @21_49e140
  ebx = eax;  // @22_49e140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @23_49e140
  ecx = (u32)(eax*4 - 3);  // @24_49e140
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @25_49e140
  ecx = 0;  // @26_49e140
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @27_49e140
  if ((eax & eax) == 0) goto L49e1ed;  // @28_49e140
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @29_49e140
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @30_49e140
  L49e197:;
  eax = ebx;  // @32_49e140
  eax = (u32)((s32)eax >> (u32)(1));  // @33_49e140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @34_49e140
  eax = (eax + ecx);  // @35_49e140
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @36_49e140
  if (eax == 0) goto L49e1ae;  // @37_49e140
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @38_49e140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4 - 4), sizeof v); (u32)v; });  // @39_49e140
  goto L49e1b0;  // @40_49e140
  L49e1ae:;
  eax = 0;  // @42_49e140
  L49e1b0:;
  p2_ = edi;  // @44_49e140
  eax = (eax + edx);  // @45_49e140
  p3_ = esi;  // @46_49e140
  p4_ = eax;  // @47_49e140
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(*(u32 *)0x676408))((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @48_49e140
  ecx = edx = 0;  // @49_49e140
  if ((s32)(eax & eax) >= 0) goto L49e1d3;  // @50_49e140
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @51_49e140
  eax = (eax | (u32)(4294967295));  // @52_49e140
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @53_49e140
  ecx = (ecx + 1);  // @54_49e140
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @55_49e140
  ebx = (ebx + eax);  // @56_49e140
  goto L49e1d9;  // @57_49e140
  L49e1d3:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @59_49e140
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @60_49e140
  L49e1d9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @62_49e140
  if ((s32)(ebx & ebx) > 0) goto L49e197;  // @63_49e140
  if ((ecx & ecx) == 0) goto L49e1ed;  // @64_49e140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @65_49e140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 - 4), sizeof v); (u32)v; });  // @66_49e140
  goto L49e1ef;  // @67_49e140
  L49e1ed:;
  eax = 0;  // @69_49e140
  L49e1ef:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @71_49e140
  ebx = (ebx + eax);  // @72_49e140
  if ((s32)ecx >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) goto L49e238;  // @73_49e140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @74_49e140
  p5_ = edi;  // @75_49e140
  eax = (eax + ebx);  // @76_49e140
  p6_ = esi;  // @77_49e140
  p7_ = eax;  // @78_49e140
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676408))((u32)(p7_), (u32)(p6_), (u32)(p5_));  // @79_49e140
  ecx = edx = 0;  // @80_49e140
  if ((eax & eax) != 0) goto L49e238;  // @81_49e140
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @82_49e140
  eax = (u32)(ebx + edi);  // @83_49e140
  esi = (esi + edi);  // @84_49e140
  edx = (edx + 1);  // @85_49e140
  edx = (edx + eax);  // @86_49e140
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @87_49e140
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(0)) goto L49e227;  // @88_49e140
  esi = (esi + 1);  // @89_49e140
  goto L49e150;  // @90_49e140
  L49e227:;
  eax = 0;  // @92_49e140
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx - 1), sizeof v); (u32)v; }) == (eax & 0xff)) eax = edx;  // @93_49e140
  return eax;  // @94_49e140
  L49e238:;
  eax = 0;  // @96_49e140
  return eax;  // @97_49e140
}
PCREG(49e140, lifted_49e140);

extern "C" u32 THISCALL lifted_56f2d0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ecx;  // @0_56f2d0
  edx = (u32)(EBP - 4);  // @1_56f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_56f2d0
  p0_ = edi;  // @3_56f2d0
  p1_ = edx;  // @4_56f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_56f2d0
  edi = 0;  // @6_56f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @7_56f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(6976900), (u32)(p1_), (u32)(p0_));  // @8_56f2d0
  ecx = edx = 0;  // @9_56f2d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L56f302;  // @10_56f2d0
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @11_56f2d0
  ecx = edx = 0;  // @12_56f2d0
  edi = eax;  // @13_56f2d0
  L56f302:;
  eax = (u32)(edi - 2);  // @15_56f2d0
  if (eax > (u32)(7)) goto L56f3f5;  // @16_56f2d0
  switch (eax) { case 0: goto L56f315; case 1: goto L56f331; case 2: goto L56f34d; case 3: goto L56f369; case 4: goto L56f385; case 5: goto L56f3a1; case 6: goto L56f3bd; case 7: goto L56f3d9; default: __builtin_trap(); }  // @17_56f2d0
  L56f315:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6980928), sizeof v); (u32)v; });  // @19_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @20_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6980932), sizeof v); (u32)v; })) & 0xff);  // @21_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @22_56f2d0
  return eax;  // @23_56f2d0
  L56f331:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6980936), sizeof v); (u32)v; });  // @25_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @26_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6980940), sizeof v); (u32)v; })) & 0xff);  // @27_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @28_56f2d0
  return eax;  // @29_56f2d0
  L56f34d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6980944), sizeof v); (u32)v; });  // @31_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @32_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6980948), sizeof v); (u32)v; })) & 0xff);  // @33_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @34_56f2d0
  return eax;  // @35_56f2d0
  L56f369:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6980952), sizeof v); (u32)v; });  // @37_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @38_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6980956), sizeof v); (u32)v; })) & 0xff);  // @39_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @40_56f2d0
  return eax;  // @41_56f2d0
  L56f385:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6977552), sizeof v); (u32)v; });  // @43_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @44_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6977556), sizeof v); (u32)v; })) & 0xff);  // @45_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @46_56f2d0
  return eax;  // @47_56f2d0
  L56f3a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6980960), sizeof v); (u32)v; });  // @49_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @50_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6980964), sizeof v); (u32)v; })) & 0xff);  // @51_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @52_56f2d0
  return eax;  // @53_56f2d0
  L56f3bd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6975068), sizeof v); (u32)v; });  // @55_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @56_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6975072), sizeof v); (u32)v; })) & 0xff);  // @57_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @58_56f2d0
  return eax;  // @59_56f2d0
  L56f3d9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6977560), sizeof v); (u32)v; });  // @61_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @62_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6977564), sizeof v); (u32)v; })) & 0xff);  // @63_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @64_56f2d0
  return eax;  // @65_56f2d0
  L56f3f5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6977544), sizeof v); (u32)v; });  // @67_56f2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 489), &v, sizeof v); }  // @68_56f2d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6977548), sizeof v); (u32)v; })) & 0xff);  // @69_56f2d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 493), &v, sizeof v); }  // @70_56f2d0
  return eax;  // @71_56f2d0
}
PCREG(56f2d0, lifted_56f2d0);

extern "C" u32 THISCALL lifted_41d220(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_41d220
  eax = edx;  // @1_41d220
  if (eax > (u32)(128)) goto L41d241;  // @2_41d220
  if (eax == (u32)(128)) goto L41d23b;  // @3_41d220
  if ((eax & eax) != 0) goto L41d3ae;  // @4_41d220
  eax = (u32)(6778152);  // @5_41d220
  return eax;  // @6_41d220
  L41d23b:;
  eax = (u32)(6778160);  // @8_41d220
  return eax;  // @9_41d220
  L41d241:;
  if (eax > (u32)(3221225612)) goto L41d336;  // @11_41d220
  if (eax == (u32)(3221225612)) goto L41d330;  // @12_41d220
  if (eax > (u32)(2147483652)) goto L41d2c2;  // @13_41d220
  if (eax == (u32)(2147483652)) goto L41d2bc;  // @14_41d220
  if (eax > (u32)(1073741829)) goto L41d291;  // @15_41d220
  if (eax == (u32)(1073741829)) goto L41d28b;  // @16_41d220
  eax = (eax - (u32)(192));  // @17_41d220
  if (eax == 0) goto L41d285;  // @18_41d220
  eax = (eax - (u32)(66));  // @19_41d220
  if (eax == 0) goto L41d27f;  // @20_41d220
  eax = (eax - (u32)(1));  // @21_41d220
  if (eax != 0) goto L41d3ae;  // @22_41d220
  eax = (u32)(6778200);  // @23_41d220
  return eax;  // @24_41d220
  L41d27f:;
  eax = (u32)(6778192);  // @26_41d220
  return eax;  // @27_41d220
  L41d285:;
  eax = (u32)(6778180);  // @29_41d220
  return eax;  // @30_41d220
  L41d28b:;
  eax = (u32)(6778208);  // @32_41d220
  return eax;  // @33_41d220
  L41d291:;
  if (eax == (u32)(2147483649)) goto L41d2b6;  // @35_41d220
  if (eax == (u32)(2147483650)) goto L41d2b0;  // @36_41d220
  if (eax != (u32)(2147483651)) goto L41d3ae;  // @37_41d220
  eax = (u32)(6778280);  // @38_41d220
  return eax;  // @39_41d220
  L41d2b0:;
  eax = (u32)(6778256);  // @41_41d220
  return eax;  // @42_41d220
  L41d2b6:;
  eax = (u32)(6778232);  // @44_41d220
  return eax;  // @45_41d220
  L41d2bc:;
  eax = (u32)(6778292);  // @47_41d220
  return eax;  // @48_41d220
  L41d2c2:;
  eax = (eax + (u32)(1073741819));  // @50_41d220
  if (eax > (u32)(33)) goto L41d3ae;  // @51_41d220
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4314096), sizeof v); (u32)v; });  // @52_41d220
  switch (eax) { case 0: goto L41d2de; case 1: goto L41d30c; case 2: goto L41d312; case 3: goto L41d318; case 4: goto L41d31e; case 5: goto L41d324; case 6: goto L41d32a; case 7: goto L41d3ae; default: __builtin_trap(); }  // @53_41d220
  L41d2de:;
  edx = (u32)(6778316);  // @55_41d220
  eax = (u32)(6778304);  // @56_41d220
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; }) == (u32)(0)) eax = edx;  // @57_41d220
  p0_ = eax;  // @58_41d220
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)0x6761e4))((u32)(7328168), (u32)(6778328), (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; }));  // @59_41d220
  ecx = edx = 0;  // @60_41d220
  eax = (u32)(7328168);  // @61_41d220
  return eax;  // @62_41d220
  L41d30c:;
  eax = (u32)(6778356);  // @64_41d220
  return eax;  // @65_41d220
  L41d312:;
  eax = (u32)(6778372);  // @67_41d220
  return eax;  // @68_41d220
  L41d318:;
  eax = (u32)(6778388);  // @70_41d220
  return eax;  // @71_41d220
  L41d31e:;
  eax = (u32)(6778400);  // @73_41d220
  return eax;  // @74_41d220
  L41d324:;
  eax = (u32)(6778420);  // @76_41d220
  return eax;  // @77_41d220
  L41d32a:;
  eax = (u32)(6778448);  // @79_41d220
  return eax;  // @80_41d220
  L41d330:;
  eax = (u32)(6778468);  // @82_41d220
  return eax;  // @83_41d220
  L41d336:;
  if (eax > (u32)(3221226164)) goto L41d3a7;  // @85_41d220
  if (eax == (u32)(3221226164)) goto L41d3a1;  // @86_41d220
  eax = (eax + (u32)(1073741683));  // @87_41d220
  if (eax > (u32)(173)) goto L41d3ae;  // @88_41d220
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4314184), sizeof v); (u32)v; });  // @89_41d220
  switch (eax) { case 0: goto L41d359; case 1: goto L41d35f; case 2: goto L41d365; case 3: goto L41d36b; case 4: goto L41d371; case 5: goto L41d377; case 6: goto L41d37d; case 7: goto L41d383; case 8: goto L41d389; case 9: goto L41d38f; case 10: goto L41d395; case 11: goto L41d39b; case 12: goto L41d3ae; default: __builtin_trap(); }  // @90_41d220
  L41d359:;
  eax = (u32)(6778492);  // @92_41d220
  return eax;  // @93_41d220
  L41d35f:;
  eax = (u32)(6778516);  // @95_41d220
  return eax;  // @96_41d220
  L41d365:;
  eax = (u32)(6778540);  // @98_41d220
  return eax;  // @99_41d220
  L41d36b:;
  eax = (u32)(6778564);  // @101_41d220
  return eax;  // @102_41d220
  L41d371:;
  eax = (u32)(6778588);  // @104_41d220
  return eax;  // @105_41d220
  L41d377:;
  eax = (u32)(6778604);  // @107_41d220
  return eax;  // @108_41d220
  L41d37d:;
  eax = (u32)(6778624);  // @110_41d220
  return eax;  // @111_41d220
  L41d383:;
  eax = (u32)(6778640);  // @113_41d220
  return eax;  // @114_41d220
  L41d389:;
  eax = (u32)(6778664);  // @116_41d220
  return eax;  // @117_41d220
  L41d38f:;
  eax = (u32)(6778684);  // @119_41d220
  return eax;  // @120_41d220
  L41d395:;
  eax = (u32)(6778708);  // @122_41d220
  return eax;  // @123_41d220
  L41d39b:;
  eax = (u32)(6778724);  // @125_41d220
  return eax;  // @126_41d220
  L41d3a1:;
  eax = (u32)(6778740);  // @128_41d220
  return eax;  // @129_41d220
  L41d3a7:;
  if (eax == (u32)(3221226165)) goto L41d3c8;  // @131_41d220
  L41d3ae:;
  p1_ = edx;  // @133_41d220
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6761e4))((u32)(7328168), (u32)(6778788), (u32)(p1_));  // @134_41d220
  ecx = edx = 0;  // @135_41d220
  eax = (u32)(7328168);  // @136_41d220
  return eax;  // @137_41d220
  L41d3c8:;
  eax = (u32)(6778764);  // @139_41d220
  return eax;  // @140_41d220
}
PCREG(41d220, lifted_41d220);

extern "C" u32 THISCALL lifted_577550(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_577550
  esi = ecx;  // @1_577550
  p0_ = edi;  // @2_577550
  eax = ext_562c20_thiscall2(ecx, (u32)(p0_));  // @3_577550
  ecx = edx = 0;  // @4_577550
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L57756c;  // @5_577550
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @6_577550
  return eax;  // @7_577550
  L57756c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_577550
  edx = (u32)(EBP + 8);  // @10_577550
  p1_ = ebx;  // @11_577550
  p2_ = edx;  // @12_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_577550
  ebx = 0;  // @14_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @15_577550
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(6976900), (u32)(p2_), (u32)(p1_));  // @16_577550
  ecx = edx = 0;  // @17_577550
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L577597;  // @18_577550
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @19_577550
  ecx = edx = 0;  // @20_577550
  ebx = eax;  // @21_577550
  L577597:;
  eax = (u32)(ebx + ebx*4);  // @23_577550
  eax = (eax + eax);  // @24_577550
  if (edi < eax) goto L57778f;  // @25_577550
  edi = (edi + (u32)(-11));  // @26_577550
  if (edi > (u32)(71)) goto L57776f;  // @27_577550
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5732316), sizeof v); (u32)v; });  // @28_577550
  switch (eax) { case 0: goto L5775bf; case 1: goto L577754; case 2: goto L5775da; case 3: goto L577697; case 4: goto L5775f5; case 5: goto L5776b2; case 6: goto L577610; case 7: goto L5776cd; case 8: goto L57762b; case 9: goto L5776e8; case 10: goto L577646; case 11: goto L577703; case 12: goto L577661; case 13: goto L57771e; case 14: goto L57767c; case 15: goto L577739; case 16: goto L57776f; default: __builtin_trap(); }  // @29_577550
  L5775bf:;
  ecx = esi;  // @31_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981620));  // @32_577550
  ecx = edx = 0;  // @33_577550
  ecx = esi;  // @34_577550
  eax = ext_563500_cdecl0();  // @35_577550
  ecx = edx = 0;  // @36_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @37_577550
  return eax;  // @38_577550
  L5775da:;
  ecx = esi;  // @40_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981564));  // @41_577550
  ecx = edx = 0;  // @42_577550
  ecx = esi;  // @43_577550
  eax = ext_563500_cdecl0();  // @44_577550
  ecx = edx = 0;  // @45_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @46_577550
  return eax;  // @47_577550
  L5775f5:;
  ecx = esi;  // @49_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981572));  // @50_577550
  ecx = edx = 0;  // @51_577550
  ecx = esi;  // @52_577550
  eax = ext_563500_cdecl0();  // @53_577550
  ecx = edx = 0;  // @54_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @55_577550
  return eax;  // @56_577550
  L577610:;
  ecx = esi;  // @58_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981580));  // @59_577550
  ecx = edx = 0;  // @60_577550
  ecx = esi;  // @61_577550
  eax = ext_563500_cdecl0();  // @62_577550
  ecx = edx = 0;  // @63_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @64_577550
  return eax;  // @65_577550
  L57762b:;
  ecx = esi;  // @67_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981588));  // @68_577550
  ecx = edx = 0;  // @69_577550
  ecx = esi;  // @70_577550
  eax = ext_563500_cdecl0();  // @71_577550
  ecx = edx = 0;  // @72_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @73_577550
  return eax;  // @74_577550
  L577646:;
  ecx = esi;  // @76_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981604));  // @77_577550
  ecx = edx = 0;  // @78_577550
  ecx = esi;  // @79_577550
  eax = ext_563500_cdecl0();  // @80_577550
  ecx = edx = 0;  // @81_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @82_577550
  return eax;  // @83_577550
  L577661:;
  ecx = esi;  // @85_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981612));  // @86_577550
  ecx = edx = 0;  // @87_577550
  ecx = esi;  // @88_577550
  eax = ext_563500_cdecl0();  // @89_577550
  ecx = edx = 0;  // @90_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @91_577550
  return eax;  // @92_577550
  L57767c:;
  ecx = esi;  // @94_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6984788));  // @95_577550
  ecx = edx = 0;  // @96_577550
  ecx = esi;  // @97_577550
  eax = ext_563500_cdecl0();  // @98_577550
  ecx = edx = 0;  // @99_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @100_577550
  return eax;  // @101_577550
  L577697:;
  ecx = esi;  // @103_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985408));  // @104_577550
  ecx = edx = 0;  // @105_577550
  ecx = esi;  // @106_577550
  eax = ext_563500_cdecl0();  // @107_577550
  ecx = edx = 0;  // @108_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @109_577550
  return eax;  // @110_577550
  L5776b2:;
  ecx = esi;  // @112_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985416));  // @113_577550
  ecx = edx = 0;  // @114_577550
  ecx = esi;  // @115_577550
  eax = ext_563500_cdecl0();  // @116_577550
  ecx = edx = 0;  // @117_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @118_577550
  return eax;  // @119_577550
  L5776cd:;
  ecx = esi;  // @121_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985424));  // @122_577550
  ecx = edx = 0;  // @123_577550
  ecx = esi;  // @124_577550
  eax = ext_563500_cdecl0();  // @125_577550
  ecx = edx = 0;  // @126_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @127_577550
  return eax;  // @128_577550
  L5776e8:;
  ecx = esi;  // @130_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985432));  // @131_577550
  ecx = edx = 0;  // @132_577550
  ecx = esi;  // @133_577550
  eax = ext_563500_cdecl0();  // @134_577550
  ecx = edx = 0;  // @135_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @136_577550
  return eax;  // @137_577550
  L577703:;
  ecx = esi;  // @139_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981596));  // @140_577550
  ecx = edx = 0;  // @141_577550
  ecx = esi;  // @142_577550
  eax = ext_563500_cdecl0();  // @143_577550
  ecx = edx = 0;  // @144_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @145_577550
  return eax;  // @146_577550
  L57771e:;
  ecx = esi;  // @148_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985440));  // @149_577550
  ecx = edx = 0;  // @150_577550
  ecx = esi;  // @151_577550
  eax = ext_563500_cdecl0();  // @152_577550
  ecx = edx = 0;  // @153_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @154_577550
  return eax;  // @155_577550
  L577739:;
  ecx = esi;  // @157_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985448));  // @158_577550
  ecx = edx = 0;  // @159_577550
  ecx = esi;  // @160_577550
  eax = ext_563500_cdecl0();  // @161_577550
  ecx = edx = 0;  // @162_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @163_577550
  return eax;  // @164_577550
  L577754:;
  ecx = esi;  // @166_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6980864));  // @167_577550
  ecx = edx = 0;  // @168_577550
  ecx = esi;  // @169_577550
  eax = ext_563500_cdecl0();  // @170_577550
  ecx = edx = 0;  // @171_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @172_577550
  return eax;  // @173_577550
  L57776f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @175_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @176_577550
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6985456), (u32)(97));  // @177_577550
  ecx = edx = 0;  // @178_577550
  p3_ = eax;  // @179_577550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @180_577550
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6985504));  // @181_577550
  ecx = edx = 0;  // @182_577550
  L57778f:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @184_577550
  return eax;  // @185_577550
}
PCREG(577550, lifted_577550);

extern "C" u32 STDCALL lifted_4d4a40(u32 a0) {
  SEH_ENTER(0x66adf6);  // @h_4d4a40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4d4a40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4d4a40
  p0_ = esi;  // @2_4d4a40
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763f4))((u32)(p0_));  // @3_4d4a40
  ecx = edx = 0;  // @4_4d4a40
  edi = eax;  // @5_4d4a40
  p1_ = esi;  // @6_4d4a40
  reg.state = (s32)((u32)(0));  // @7_4d4a40
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p1_));  // @8_4d4a40
  ecx = edx = 0;  // @9_4d4a40
  if ((eax & eax) == 0) goto L4d4a95;  // @10_4d4a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @11_4d4a40
  if ((eax & eax) == 0) goto L4d4a94;  // @12_4d4a40
  eax = ((u32(STDCALL *)(void))(eax))();  // @13_4d4a40
  ecx = edx = 0;  // @14_4d4a40
  goto L4d4a95;  // @15_4d4a40
  L4d4a94:;
  __builtin_trap();  // @17_4d4a40
  L4d4a95:;
  eax = edi;  // @19_4d4a40
  SEH_LEAVE();  // @20_4d4a40
  return eax;  // @21_4d4a40
}
PCREG(4d4a40, lifted_4d4a40);

extern "C" u32 STDCALL lifted_4d4c20(u32 a0) {
  SEH_ENTER(0x66adf6);  // @h_4d4c20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4d4c20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4d4c20
  p0_ = esi;  // @2_4d4c20
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763dc))((u32)(p0_));  // @3_4d4c20
  ecx = edx = 0;  // @4_4d4c20
  edi = eax;  // @5_4d4c20
  p1_ = esi;  // @6_4d4c20
  reg.state = (s32)((u32)(0));  // @7_4d4c20
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p1_));  // @8_4d4c20
  ecx = edx = 0;  // @9_4d4c20
  if ((eax & eax) == 0) goto L4d4c75;  // @10_4d4c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @11_4d4c20
  if ((eax & eax) == 0) goto L4d4c74;  // @12_4d4c20
  eax = ((u32(STDCALL *)(void))(eax))();  // @13_4d4c20
  ecx = edx = 0;  // @14_4d4c20
  goto L4d4c75;  // @15_4d4c20
  L4d4c74:;
  __builtin_trap();  // @17_4d4c20
  L4d4c75:;
  eax = edi;  // @19_4d4c20
  SEH_LEAVE();  // @20_4d4c20
  return eax;  // @21_4d4c20
}
PCREG(4d4c20, lifted_4d4c20);

extern "C" u32 STDCALL lifted_4d4ab0(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66adf6);  // @h_4d4ab0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4d4ab0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4d4ab0
  p0_ = esi;  // @2_4d4ab0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6763e8))((u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @3_4d4ab0
  ecx = edx = 0;  // @4_4d4ab0
  edi = eax;  // @5_4d4ab0
  p1_ = esi;  // @6_4d4ab0
  reg.state = (s32)((u32)(0));  // @7_4d4ab0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p1_));  // @8_4d4ab0
  ecx = edx = 0;  // @9_4d4ab0
  if ((eax & eax) == 0) goto L4d4b0b;  // @10_4d4ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @11_4d4ab0
  if ((eax & eax) == 0) goto L4d4b0a;  // @12_4d4ab0
  eax = ((u32(STDCALL *)(void))(eax))();  // @13_4d4ab0
  ecx = edx = 0;  // @14_4d4ab0
  goto L4d4b0b;  // @15_4d4ab0
  L4d4b0a:;
  __builtin_trap();  // @17_4d4ab0
  L4d4b0b:;
  eax = edi;  // @19_4d4ab0
  SEH_LEAVE();  // @20_4d4ab0
  return eax;  // @21_4d4ab0
}
PCREG(4d4ab0, lifted_4d4ab0);

extern "C" u32 STDCALL lifted_4d4b20(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66adf6);  // @h_4d4b20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_4d4b20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4d4b20
  p0_ = esi;  // @2_4d4b20
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(1), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p0_));  // @3_4d4b20
  ecx = edx = 0;  // @4_4d4b20
  edi = eax;  // @5_4d4b20
  p1_ = esi;  // @6_4d4b20
  reg.state = (s32)((u32)(0));  // @7_4d4b20
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p1_));  // @8_4d4b20
  ecx = edx = 0;  // @9_4d4b20
  if ((eax & eax) == 0) goto L4d4b7d;  // @10_4d4b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @11_4d4b20
  if ((eax & eax) == 0) goto L4d4b7c;  // @12_4d4b20
  eax = ((u32(STDCALL *)(void))(eax))();  // @13_4d4b20
  ecx = edx = 0;  // @14_4d4b20
  goto L4d4b7d;  // @15_4d4b20
  L4d4b7c:;
  __builtin_trap();  // @17_4d4b20
  L4d4b7d:;
  eax = edi;  // @19_4d4b20
  SEH_LEAVE();  // @20_4d4b20
  return eax;  // @21_4d4b20
}
PCREG(4d4b20, lifted_4d4b20);

extern "C" u32 STDCALL lifted_4d4ba0(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66adf6);  // @h_4d4ba0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_4d4ba0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4d4ba0
  p0_ = esi;  // @2_4d4ba0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x6763d4))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(1), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p0_));  // @3_4d4ba0
  ecx = edx = 0;  // @4_4d4ba0
  edi = eax;  // @5_4d4ba0
  p1_ = esi;  // @6_4d4ba0
  reg.state = (s32)((u32)(0));  // @7_4d4ba0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p1_));  // @8_4d4ba0
  ecx = edx = 0;  // @9_4d4ba0
  if ((eax & eax) == 0) goto L4d4bfd;  // @10_4d4ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @11_4d4ba0
  if ((eax & eax) == 0) goto L4d4bfc;  // @12_4d4ba0
  eax = ((u32(STDCALL *)(void))(eax))();  // @13_4d4ba0
  ecx = edx = 0;  // @14_4d4ba0
  goto L4d4bfd;  // @15_4d4ba0
  L4d4bfc:;
  __builtin_trap();  // @17_4d4ba0
  L4d4bfd:;
  eax = edi;  // @19_4d4ba0
  SEH_LEAVE();  // @20_4d4ba0
  return eax;  // @21_4d4ba0
}
PCREG(4d4ba0, lifted_4d4ba0);

extern "C" u32 THISCALL lifted_423ef0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_423ef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_423ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_423ef0
  ecx = (u32)(EBP - 144);  // @2_423ef0
  p0_ = eax;  // @3_423ef0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @4_423ef0
  ecx = edx = 0;  // @5_423ef0
  eax = (u32)(EBP - 144);  // @6_423ef0
  reg.state = (s32)((u32)(0));  // @7_423ef0
  p1_ = eax;  // @8_423ef0
  ecx = (u32)(edi + 8902);  // @9_423ef0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @10_423ef0
  ecx = edx = 0;  // @11_423ef0
  ecx = (u32)(EBP - 144);  // @12_423ef0
  reg.state = (s32)((u32)(4294967295));  // @13_423ef0
  eax = ext_4cbec0_thiscall1(ecx);  // @14_423ef0
  ecx = edx = 0;  // @15_423ef0
  ecx = (u32)(edi + 8902);  // @16_423ef0
  eax = ext_4cc1d0_thiscall1(ecx);  // @17_423ef0
  ecx = edx = 0;  // @18_423ef0
  p2_ = eax;  // @19_423ef0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6761b8))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2523), sizeof v); (u32)v; }), (u32)(p2_));  // @20_423ef0
  ecx = edx = 0;  // @21_423ef0
  SEH_LEAVE();  // @22_423ef0
  ext_633654(G(u32, 0x6f5630));  // @23_423ef0
  return eax;  // @24_423ef0
}
PCREG(423ef0, lifted_423ef0);

extern "C" u32 THISCALL lifted_41f280(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669286);  // @h_41f280
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_41f280
  reg.state = (s32)((u32)(0));  // @1_41f280
  { u32 v = (u32)((u32)(6779760)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_41f280
  eax = ext_41e590_thiscall1(ecx);  // @3_41f280
  ecx = edx = 0;  // @4_41f280
  ecx = esi;  // @5_41f280
  eax = ext_41f3a0_thiscall1(ecx);  // @6_41f280
  ecx = edx = 0;  // @7_41f280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7340940), &v, sizeof v); }  // @8_41f280
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 49), sizeof v); (u32)v; });  // @9_41f280
  if ((edi & edi) == 0) goto L41f2e5;  // @10_41f280
  ecx = edi;  // @11_41f280
  eax = ext_4cfae0_thiscall1(ecx);  // @12_41f280
  ecx = edx = 0;  // @13_41f280
  p0_ = edi;  // @14_41f280
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(74052));  // @15_41f280
  ecx = edx = 0;  // @16_41f280
  L41f2e5:;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760cc))((u32)(7328296));  // @18_41f280
  ecx = edx = 0;  // @19_41f280
  ecx = esi;  // @20_41f280
  eax = ext_41e1f0_thiscall1(ecx);  // @21_41f280
  ecx = edx = 0;  // @22_41f280
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L41f308;  // @23_41f280
  p1_ = esi;  // @24_41f280
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(80));  // @25_41f280
  ecx = edx = 0;  // @26_41f280
  L41f308:;
  eax = esi;  // @28_41f280
  SEH_LEAVE();  // @29_41f280
  return eax;  // @30_41f280
}
PCREG(41f280, lifted_41f280);

extern "C" u32 THISCALL lifted_41f1e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66404a);  // @h_41f1e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_41f1e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_41f1e0
  eax = ext_41e180_thiscall1(ecx);  // @2_41f1e0
  ecx = edx = 0;  // @3_41f1e0
  reg.state = (s32)((u32)(0));  // @4_41f1e0
  { u32 v = (u32)((u32)(6779760)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_41f1e0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760c0))((u32)(7328296));  // @6_41f1e0
  ecx = edx = 0;  // @7_41f1e0
  eax = ext_41e290_cdecl1((u32)(74052));  // @8_41f1e0
  ecx = edx = 0;  // @9_41f1e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_41f1e0
  reg.state = (s32)((u32)(1));  // @11_41f1e0
  if ((eax & eax) == 0) goto L41f24f;  // @12_41f1e0
  ecx = eax;  // @13_41f1e0
  eax = ext_4cf940_thiscall4(ecx, (u32)(0), (u32)(-1), (u32)(0));  // @14_41f1e0
  ecx = edx = 0;  // @15_41f1e0
  goto L41f251;  // @16_41f1e0
  L41f24f:;
  eax = 0;  // @18_41f1e0
  L41f251:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 49), &v, sizeof v); }  // @20_41f1e0
  ecx = esi;  // @21_41f1e0
  reg.state = (s32)((u32)(0));  // @22_41f1e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7340940), &v, sizeof v); }  // @23_41f1e0
  eax = ext_41e4b0_thiscall1(ecx);  // @24_41f1e0
  ecx = edx = 0;  // @25_41f1e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 79), &v, sizeof v); }  // @26_41f1e0
  eax = esi;  // @27_41f1e0
  SEH_LEAVE();  // @28_41f1e0
  return eax;  // @29_41f1e0
}
PCREG(41f1e0, lifted_41f1e0);

extern "C" u32 THISCALL lifted_41f0d0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x664012);  // @h_41f0d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_41f0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @1_41f0d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_41f0d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 61), &v, sizeof v); }  // @3_41f0d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @4_41f0d0
  if ((ecx & ecx) == 0) goto L41f116;  // @5_41f0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_41f0d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(140));  // @7_41f0d0
  ecx = edx = 0;  // @8_41f0d0
  goto L41f11f;  // @9_41f0d0
  L41f116:;
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x6762f0))();  // @11_41f0d0
  ecx = edx = 0;  // @12_41f0d0
  L41f11f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_41f0d0
  reg.state = (s32)((u32)(0));  // @15_41f0d0
  if ((eax & eax) == 0) goto L41f13f;  // @16_41f0d0
  ecx = eax;  // @17_41f0d0
  p0_ = edi;  // @18_41f0d0
  eax = ext_4d0f30_thiscall4(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @19_41f0d0
  ecx = edx = 0;  // @20_41f0d0
  ecx = eax;  // @21_41f0d0
  goto L41f141;  // @22_41f0d0
  L41f13f:;
  ecx = 0;  // @24_41f0d0
  L41f141:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @26_41f0d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + eax*4 + 53), &v, sizeof v); }  // @27_41f0d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @28_41f0d0
  SEH_LEAVE();  // @29_41f0d0
  return eax;  // @30_41f0d0
}
PCREG(41f0d0, lifted_41f0d0);

extern "C" u32 STDCALL lifted_651ce0(u32 a0) {
  SEH_ENTER(0x66428b);  // @h_651ce0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_651ce0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_651ce0
  p0_ = esi;  // @2_651ce0
  ecx = (u32)(ecx + 7825);  // @3_651ce0
  eax = ext_4cc1d0_cdecl1((u32)(p0_));  // @4_651ce0
  ecx = edx = 0;  // @5_651ce0
  p1_ = eax;  // @6_651ce0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676414))((u32)(p1_));  // @7_651ce0
  ecx = edx = 0;  // @8_651ce0
  if ((eax & eax) == 0) goto L651d89;  // @9_651ce0
  p2_ = esi;  // @10_651ce0
  ecx = (u32)(EBP - 144);  // @11_651ce0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p2_));  // @12_651ce0
  ecx = edx = 0;  // @13_651ce0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_651ce0
  eax = (u32)(EBP - 144);  // @15_651ce0
  p3_ = eax;  // @16_651ce0
  reg.state = (s32)((u32)(0));  // @17_651ce0
  ecx = (u32)(ecx + 7825);  // @18_651ce0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p3_));  // @19_651ce0
  ecx = edx = 0;  // @20_651ce0
  ecx = (u32)(EBP - 144);  // @21_651ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_651ce0
  ecx = edx = 0;  // @23_651ce0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_651ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 111), sizeof v); (u32)v; });  // @25_651ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 119), &v, sizeof v); }  // @26_651ce0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_651ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 115), sizeof v); (u32)v; });  // @28_651ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 123), &v, sizeof v); }  // @29_651ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_651ce0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 6807), &v, sizeof v); }  // @31_651ce0
  L651d89:;
  SEH_LEAVE();  // @33_651ce0
  ext_633654(G(u32, 0x6f5630));  // @34_651ce0
  return eax;  // @35_651ce0
}
PCREG(651ce0, lifted_651ce0);

extern "C" u32 THISCALL lifted_651880(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_651880
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_651880
  { u32 v = (u32)((u32)(7091948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_651880
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4583), &v, sizeof v); }  // @2_651880
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676230))((u32)(0));  // @3_651880
  ecx = edx = 0;  // @4_651880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_651880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_651880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4759), sizeof v); (u32)v; }));  // @7_651880
  ecx = edx = 0;  // @8_651880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4759), sizeof v); (u32)v; });  // @9_651880
  if ((ecx & ecx) == 0) goto L6518de;  // @10_651880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_651880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @12_651880
  ecx = edx = 0;  // @13_651880
  L6518de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_651880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_651880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4763), sizeof v); (u32)v; }));  // @17_651880
  ecx = edx = 0;  // @18_651880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4763), sizeof v); (u32)v; });  // @19_651880
  if ((ecx & ecx) == 0) goto L651902;  // @20_651880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_651880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @22_651880
  ecx = edx = 0;  // @23_651880
  L651902:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_651880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_651880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4767), sizeof v); (u32)v; }));  // @27_651880
  ecx = edx = 0;  // @28_651880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4767), sizeof v); (u32)v; });  // @29_651880
  if ((ecx & ecx) == 0) goto L651926;  // @30_651880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_651880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @32_651880
  ecx = edx = 0;  // @33_651880
  L651926:;
  ecx = esi;  // @35_651880
  eax = ext_658020_thiscall1(ecx);  // @36_651880
  ecx = edx = 0;  // @37_651880
  SEH_LEAVE();  // @38_651880
  return eax;  // @39_651880
}
PCREG(651880, lifted_651880);

extern "C" u32 THISCALL lifted_42b2e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6649d8);  // @h_42b2e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_42b2e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_42b2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_42b2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_42b2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @4_42b2e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_42b2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_42b2e0
  ebx = (ebx - ecx);  // @7_42b2e0
  reg.state = (s32)((u32)(0));  // @8_42b2e0
  esi = (u32)(ebx + 1);  // @9_42b2e0
  if (esi > (u32)(-2)) goto L42b353;  // @10_42b2e0
  if ((esi & esi) != 0) goto L42b33e;  // @11_42b2e0
  eax = 0;  // @12_42b2e0
  goto L42b349;  // @13_42b2e0
  L42b33e:;
  p0_ = esi;  // @15_42b2e0
  ecx = edi;  // @16_42b2e0
  eax = ext_6014a0_stdcall1((u32)(p0_));  // @17_42b2e0
  ecx = edx = 0;  // @18_42b2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_42b2e0
  L42b349:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @21_42b2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @22_42b2e0
  eax = (eax + esi);  // @23_42b2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @24_42b2e0
  L42b353:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_42b2e0
  p1_ = ebx;  // @27_42b2e0
  p2_ = ecx;  // @28_42b2e0
  p3_ = esi;  // @29_42b2e0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))((u32)(p3_), (u32)(p2_), (u32)(p1_));  // @30_42b2e0
  ecx = edx = 0;  // @31_42b2e0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @32_42b2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @33_42b2e0
  eax = (eax + esi);  // @34_42b2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @35_42b2e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @36_42b2e0
  if (eax == 0) goto L42b374;  // @37_42b2e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @38_42b2e0
  L42b374:;
  eax = edi;  // @40_42b2e0
  SEH_LEAVE();  // @41_42b2e0
  return eax;  // @42_42b2e0
}
PCREG(42b2e0, lifted_42b2e0);

extern "C" u32 THISCALL lifted_5f10c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cda8);  // @h_5f10c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_5f10c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_5f10c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5f10c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_5f10c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @4_5f10c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_5f10c0
  reg.state = (s32)((u32)(0));  // @6_5f10c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @7_5f10c0
  ebx = edx;  // @8_5f10c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_5f10c0
  ebx = (ebx - ecx);  // @10_5f10c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @11_5f10c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @12_5f10c0
  esi = (u32)(ebx + 1);  // @13_5f10c0
  if (esi > (u32)(-2)) goto L5f113f;  // @14_5f10c0
  if ((esi & esi) != 0) goto L5f112a;  // @15_5f10c0
  eax = 0;  // @16_5f10c0
  goto L5f1135;  // @17_5f10c0
  L5f112a:;
  p0_ = esi;  // @19_5f10c0
  ecx = edi;  // @20_5f10c0
  eax = ext_6014a0_stdcall1((u32)(p0_));  // @21_5f10c0
  ecx = edx = 0;  // @22_5f10c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @23_5f10c0
  L5f1135:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @25_5f10c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @26_5f10c0
  eax = (eax + esi);  // @27_5f10c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @28_5f10c0
  L5f113f:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_5f10c0
  p1_ = ebx;  // @31_5f10c0
  p2_ = ecx;  // @32_5f10c0
  p3_ = esi;  // @33_5f10c0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))((u32)(p3_), (u32)(p2_), (u32)(p1_));  // @34_5f10c0
  ecx = edx = 0;  // @35_5f10c0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @36_5f10c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @37_5f10c0
  eax = (eax + esi);  // @38_5f10c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @39_5f10c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @40_5f10c0
  if (eax == 0) goto L5f1160;  // @41_5f10c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @42_5f10c0
  L5f1160:;
  eax = edi;  // @44_5f10c0
  SEH_LEAVE();  // @45_5f10c0
  return eax;  // @46_5f10c0
}
PCREG(5f10c0, lifted_5f10c0);

extern "C" u32 THISCALL lifted_42ed30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_42ed30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_42ed30
  ecx = (ecx + (u32)(291));  // @1_42ed30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @2_42ed30
  eax = ext_4cc1d0_thiscall1(ecx);  // @3_42ed30
  ecx = edx = 0;  // @4_42ed30
  p0_ = eax;  // @5_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))((u32)(p0_), (u32)(58));  // @6_42ed30
  ecx = edx = 0;  // @7_42ed30
  if ((eax & eax) != 0) goto L42ed92;  // @8_42ed30
  L42ed84:;
  ecx = esi;  // @10_42ed30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @11_42ed30
  ecx = edx = 0;  // @12_42ed30
  goto L42edf9;  // @13_42ed30
  L42ed92:;
  p1_ = eax;  // @15_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p1_), (u32)(92));  // @16_42ed30
  ecx = edx = 0;  // @17_42ed30
  if ((eax & eax) == 0) goto L42ed84;  // @18_42ed30
  eax = (eax + 1);  // @19_42ed30
  ecx = (u32)(EBP - 144);  // @20_42ed30
  p2_ = eax;  // @21_42ed30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p2_));  // @22_42ed30
  ecx = edx = 0;  // @23_42ed30
  ecx = (u32)(EBP - 144);  // @24_42ed30
  reg.state = (s32)((u32)(0));  // @25_42ed30
  eax = ext_4cc1d0_thiscall1(ecx);  // @26_42ed30
  ecx = edx = 0;  // @27_42ed30
  p3_ = eax;  // @28_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p3_), (u32)(92));  // @29_42ed30
  ecx = edx = 0;  // @30_42ed30
  ecx = esi;  // @31_42ed30
  if ((eax & eax) != 0) goto L42eddf;  // @32_42ed30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @33_42ed30
  ecx = edx = 0;  // @34_42ed30
  goto L42edee;  // @35_42ed30
  L42eddf:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_42ed30
  eax = (u32)(EBP - 144);  // @38_42ed30
  p4_ = eax;  // @39_42ed30
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p4_));  // @40_42ed30
  ecx = edx = 0;  // @41_42ed30
  L42edee:;
  ecx = (u32)(EBP - 144);  // @43_42ed30
  eax = ext_4cbec0_thiscall1(ecx);  // @44_42ed30
  ecx = edx = 0;  // @45_42ed30
  L42edf9:;
  eax = esi;  // @47_42ed30
  SEH_LEAVE();  // @48_42ed30
  ext_633654(G(u32, 0x6f5630));  // @49_42ed30
  return eax;  // @50_42ed30
}
PCREG(42ed30, lifted_42ed30);

extern "C" u32 THISCALL lifted_4eec30(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664d1b);  // @h_4eec30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4eec30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4eec30
  ebx = (u32)(393232);  // @2_4eec30
  if (eax > (u32)(6)) goto L4eec9e;  // @3_4eec30
  switch (eax) { case 0: goto L4eecf0; case 1: goto L4eec74; case 2: goto L4eec7b; case 3: goto L4eec82; case 4: goto L4eec89; case 5: goto L4eec90; case 6: goto L4eec97; default: __builtin_trap(); }  // @4_4eec30
  L4eec74:;
  ebx = (u32)(393234);  // @6_4eec30
  goto L4eecf0;  // @7_4eec30
  L4eec7b:;
  ebx = (u32)(393236);  // @9_4eec30
  goto L4eecf0;  // @10_4eec30
  L4eec82:;
  ebx = (u32)(393233);  // @12_4eec30
  goto L4eecf0;  // @13_4eec30
  L4eec89:;
  ebx = (u32)(393240);  // @15_4eec30
  goto L4eecf0;  // @16_4eec30
  L4eec90:;
  ebx = (u32)(393744);  // @18_4eec30
  goto L4eecf0;  // @19_4eec30
  L4eec97:;
  ebx = (u32)(393745);  // @21_4eec30
  goto L4eecf0;  // @22_4eec30
  L4eec9e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @24_4eec30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4eec30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6912796), (u32)(678));  // @26_4eec30
  ecx = edx = 0;  // @27_4eec30
  edi = eax;  // @28_4eec30
  ecx = (u32)(EBP - 144);  // @29_4eec30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_4eec30
  p0_ = ecx;  // @31_4eec30
  ecx = esi;  // @32_4eec30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 476)))(ecx, (u32)(p0_), (u32)(1));  // @33_4eec30
  ecx = edx = 0;  // @34_4eec30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_4eec30
  ecx = eax;  // @36_4eec30
  reg.state = (s32)((u32)(0));  // @37_4eec30
  eax = ext_4cc1d0_thiscall1(ecx);  // @38_4eec30
  ecx = edx = 0;  // @39_4eec30
  p1_ = eax;  // @40_4eec30
  p2_ = edi;  // @41_4eec30
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p2_), (u32)(6915108), (u32)(p1_));  // @42_4eec30
  ecx = edx = 0;  // @43_4eec30
  ecx = (u32)(EBP - 144);  // @44_4eec30
  eax = ext_4cbec0_thiscall1(ecx);  // @45_4eec30
  ecx = edx = 0;  // @46_4eec30
  L4eecf0:;
  eax = ebx;  // @48_4eec30
  SEH_LEAVE();  // @49_4eec30
  ext_633654(G(u32, 0x6f5630));  // @50_4eec30
  return eax;  // @51_4eec30
}
PCREG(4eec30, lifted_4eec30);

extern "C" u32 THISCALL lifted_41fed0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_41fed0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_41fed0
  { u32 v = (u32)((u32)(6780996)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_41fed0
  eax = ext_423e60_thiscall1(ecx);  // @2_41fed0
  ecx = edx = 0;  // @3_41fed0
  ecx = esi;  // @4_41fed0
  eax = ext_42cc30_thiscall1(ecx);  // @5_41fed0
  ecx = edx = 0;  // @6_41fed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2523), sizeof v); (u32)v; });  // @7_41fed0
  if ((eax & eax) == 0) goto L41ff22;  // @8_41fed0
  p0_ = eax;  // @9_41fed0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676194))((u32)(p0_));  // @10_41fed0
  ecx = edx = 0;  // @11_41fed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2523), &v, sizeof v); }  // @12_41fed0
  L41ff22:;
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676184))((u32)(7225480), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2511), sizeof v); (u32)v; }));  // @14_41fed0
  ecx = edx = 0;  // @15_41fed0
  ecx = (u32)(esi + 9563);  // @16_41fed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7340956), &v, sizeof v); }  // @17_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @18_41fed0
  ecx = edx = 0;  // @19_41fed0
  ecx = (u32)(esi + 9435);  // @20_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @21_41fed0
  ecx = edx = 0;  // @22_41fed0
  ecx = (u32)(esi + 9307);  // @23_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @24_41fed0
  ecx = edx = 0;  // @25_41fed0
  ecx = (u32)(esi + 9179);  // @26_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @27_41fed0
  ecx = edx = 0;  // @28_41fed0
  ecx = (u32)(esi + 9030);  // @29_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @30_41fed0
  ecx = edx = 0;  // @31_41fed0
  ecx = (u32)(esi + 8902);  // @32_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @33_41fed0
  ecx = edx = 0;  // @34_41fed0
  ecx = (u32)(esi + 8770);  // @35_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @36_41fed0
  ecx = edx = 0;  // @37_41fed0
  ecx = (u32)(esi + 8593);  // @38_41fed0
  eax = ext_4ccf60_thiscall1(ecx);  // @39_41fed0
  ecx = edx = 0;  // @40_41fed0
  ecx = (u32)(esi + 8465);  // @41_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @42_41fed0
  ecx = edx = 0;  // @43_41fed0
  ecx = (u32)(esi + 8337);  // @44_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @45_41fed0
  ecx = edx = 0;  // @46_41fed0
  ecx = (u32)(esi + 8209);  // @47_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @48_41fed0
  ecx = edx = 0;  // @49_41fed0
  ecx = (u32)(esi + 8081);  // @50_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @51_41fed0
  ecx = edx = 0;  // @52_41fed0
  ecx = (u32)(esi + 7953);  // @53_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @54_41fed0
  ecx = edx = 0;  // @55_41fed0
  ecx = (u32)(esi + 7825);  // @56_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @57_41fed0
  ecx = edx = 0;  // @58_41fed0
  ecx = (u32)(esi + 7691);  // @59_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @60_41fed0
  ecx = edx = 0;  // @61_41fed0
  ecx = (u32)(esi + 7537);  // @62_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @63_41fed0
  ecx = edx = 0;  // @64_41fed0
  ecx = (u32)(esi + 7409);  // @65_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @66_41fed0
  ecx = edx = 0;  // @67_41fed0
  ecx = (u32)(esi + 7281);  // @68_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @69_41fed0
  ecx = edx = 0;  // @70_41fed0
  ecx = (u32)(esi + 7153);  // @71_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @72_41fed0
  ecx = edx = 0;  // @73_41fed0
  ecx = (u32)(esi + 7025);  // @74_41fed0
  eax = ext_4cbec0_thiscall1(ecx);  // @75_41fed0
  ecx = edx = 0;  // @76_41fed0
  ecx = esi;  // @77_41fed0
  eax = ext_42bae0_thiscall1(ecx);  // @78_41fed0
  ecx = edx = 0;  // @79_41fed0
  SEH_LEAVE();  // @80_41fed0
  return eax;  // @81_41fed0
}
PCREG(41fed0, lifted_41fed0);

extern "C" u32 THISCALL lifted_4f6450(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d1b);  // @h_4f6450
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f6450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 151), sizeof v); (u32)v; });  // @1_4f6450
  eax = (u32)(EBP + 8);  // @2_4f6450
  p0_ = eax;  // @3_4f6450
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)0x676448))((u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }), (u32)(20), (u32)(5215504));  // @4_4f6450
  ecx = edx = 0;  // @5_4f6450
  if ((eax & eax) != 0) goto L4f6533;  // @6_4f6450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @7_4f6450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4f6450
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6924584), (u32)(66));  // @9_4f6450
  ecx = edx = 0;  // @10_4f6450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_4f6450
  edi = eax;  // @12_4f6450
  eax = (u32)(EBP - 144);  // @13_4f6450
  ecx = ebx;  // @14_4f6450
  p1_ = eax;  // @15_4f6450
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p1_), (u32)(1));  // @16_4f6450
  ecx = edx = 0;  // @17_4f6450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_4f6450
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @19_4f6450
  p2_ = ecx;  // @20_4f6450
  p3_ = ecx;  // @21_4f6450
  ecx = eax;  // @22_4f6450
  reg.state = (s32)((u32)(0));  // @23_4f6450
  eax = ext_4cc1d0_cdecl2((u32)(p3_), (u32)(p2_));  // @24_4f6450
  ecx = edx = 0;  // @25_4f6450
  p4_ = eax;  // @26_4f6450
  p5_ = edi;  // @27_4f6450
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(p5_), (u32)(6924624), (u32)(p4_));  // @28_4f6450
  ecx = edx = 0;  // @29_4f6450
  ecx = (u32)(EBP - 144);  // @30_4f6450
  eax = ext_4cbec0_thiscall1(ecx);  // @31_4f6450
  ecx = edx = 0;  // @32_4f6450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 151), sizeof v); (u32)v; });  // @33_4f6450
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @34_4f6450
  eax = (u32)(EBP + 8);  // @35_4f6450
  p6_ = eax;  // @36_4f6450
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)0x676448))((u32)(p6_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }), (u32)(20), (u32)(5215504));  // @37_4f6450
  ecx = edx = 0;  // @38_4f6450
  if ((eax & eax) != 0) goto L4f6533;  // @39_4f6450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; });  // @40_4f6450
  L4f6533:;
  SEH_LEAVE();  // @42_4f6450
  ext_633654(G(u32, 0x6f5630));  // @43_4f6450
  return eax;  // @44_4f6450
}
PCREG(4f6450, lifted_4f6450);

extern "C" u32 THISCALL lifted_5f1180(u32 ecx_in) {
  SEH_ENTER(0x66ce12);  // @h_5f1180
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5f1180
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5f1180
  eax = ext_41e290_cdecl1((u32)(25));  // @2_5f1180
  ecx = edx = 0;  // @3_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_5f1180
  reg.state = (s32)((u32)(0));  // @5_5f1180
  if ((eax & eax) == 0) goto L5f11cc;  // @6_5f1180
  ecx = eax;  // @7_5f1180
  eax = ext_600be0_thiscall1(ecx);  // @8_5f1180
  ecx = edx = 0;  // @9_5f1180
  goto L5f11ce;  // @10_5f1180
  L5f11cc:;
  eax = 0;  // @12_5f1180
  L5f11ce:;
  reg.state = (s32)((u32)(4294967295));  // @14_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @15_5f1180
  eax = ext_41e290_cdecl1((u32)(77));  // @16_5f1180
  ecx = edx = 0;  // @17_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @18_5f1180
  reg.state = (s32)((u32)(1));  // @19_5f1180
  if ((eax & eax) == 0) goto L5f11fc;  // @20_5f1180
  ecx = eax;  // @21_5f1180
  eax = ext_5fa910_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(20));  // @22_5f1180
  ecx = edx = 0;  // @23_5f1180
  goto L5f11fe;  // @24_5f1180
  L5f11fc:;
  eax = 0;  // @26_5f1180
  L5f11fe:;
  p0_ = eax;  // @28_5f1180
  ecx = (u32)(esi + 8);  // @29_5f1180
  reg.state = (s32)((u32)(4294967295));  // @30_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @31_5f1180
  eax = ext_604170_thiscall2(ecx, (u32)(p0_));  // @32_5f1180
  ecx = edx = 0;  // @33_5f1180
  ecx = (u32)(esi + 20);  // @34_5f1180
  reg.state = (s32)((u32)(2));  // @35_5f1180
  eax = ext_4cbeb0_thiscall1(ecx);  // @36_5f1180
  ecx = edx = 0;  // @37_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 172), &v, sizeof v); }  // @38_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @39_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @40_5f1180
  reg.state = (s32)((u32)(4));  // @41_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @42_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @43_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @44_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @45_5f1180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @46_5f1180
  eax = ext_41e290_cdecl1((u32)(8));  // @47_5f1180
  ecx = edx = 0;  // @48_5f1180
  if ((eax & eax) == 0) goto L5f12a7;  // @49_5f1180
  { u32 v = (u32)((u32)(7046824)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @50_5f1180
  { u32 v = (u32)((u32)(7046784)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @51_5f1180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @52_5f1180
  eax = esi;  // @53_5f1180
  SEH_LEAVE();  // @54_5f1180
  return eax;  // @55_5f1180
  L5f12a7:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @57_5f1180
  eax = esi;  // @58_5f1180
  SEH_LEAVE();  // @59_5f1180
  return eax;  // @60_5f1180
}
PCREG(5f1180, lifted_5f1180);

extern "C" u32 THISCALL lifted_606b80(u32 ecx_in) {
  SEH_ENTER(0x66df71);  // @h_606b80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_606b80
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_606b80
  ecx = (u32)(ebx + 4);  // @2_606b80
  { u32 v = (u32)((u32)(7053004)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @3_606b80
  eax = ext_606a70_thiscall1(ecx);  // @4_606b80
  ecx = edx = 0;  // @5_606b80
  ecx = (u32)(ebx + 23);  // @6_606b80
  reg.state = (s32)((u32)(0));  // @7_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @8_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @9_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @10_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 35), &v, sizeof v); }  // @11_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 39), &v, sizeof v); }  // @12_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 43), &v, sizeof v); }  // @13_606b80
  reg.state = (s32)((u32)(2));  // @14_606b80
  eax = ext_607310_thiscall2(ecx, (u32)(200));  // @15_606b80
  ecx = edx = 0;  // @16_606b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 35), sizeof v); (u32)v; });  // @17_606b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 43), sizeof v); (u32)v; });  // @18_606b80
  eax = (eax - ecx);  // @19_606b80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @20_606b80
  eax = (u32)((s32)eax >> (u32)(1));  // @21_606b80
  if (eax >= (u32)(200)) goto L606c70;  // @22_606b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 39), sizeof v); (u32)v; });  // @23_606b80
  eax = esi;  // @24_606b80
  eax = (eax - ecx);  // @25_606b80
  ecx = (u32)(ebx + 35);  // @26_606b80
  eax = (u32)((s32)eax >> (u32)(1));  // @27_606b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @28_606b80
  eax = ext_6014a0_stdcall1((u32)(400));  // @29_606b80
  ecx = edx = 0;  // @30_606b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @31_606b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @32_606b80
  esi = (esi - eax);  // @33_606b80
  esi = (esi & (u32)(4294967294));  // @34_606b80
  p0_ = esi;  // @35_606b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @36_606b80
  p1_ = eax;  // @37_606b80
  p2_ = esi;  // @38_606b80
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @39_606b80
  ecx = edx = 0;  // @40_606b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 43), sizeof v); (u32)v; });  // @41_606b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 35), sizeof v); (u32)v; });  // @42_606b80
  eax = (eax - ecx);  // @43_606b80
  eax = (u32)((s32)eax >> (u32)(1));  // @44_606b80
  if (eax == 0) goto L606c5b;  // @45_606b80
  eax = (eax + eax);  // @46_606b80
  p3_ = eax;  // @47_606b80
  p4_ = ecx;  // @48_606b80
  ecx = (u32)(ebx + 35);  // @49_606b80
  eax = ext_54f870_stdcall2((u32)(p4_), (u32)(p3_));  // @50_606b80
  ecx = edx = 0;  // @51_606b80
  L606c5b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @53_606b80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 35), &v, sizeof v); }  // @54_606b80
  eax = (u32)(esi + eax*2);  // @55_606b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 39), &v, sizeof v); }  // @56_606b80
  eax = (u32)(esi + 400);  // @57_606b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 43), &v, sizeof v); }  // @58_606b80
  L606c70:;
  eax = ebx;  // @60_606b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 47), &v, sizeof v); }  // @61_606b80
  SEH_LEAVE();  // @62_606b80
  return eax;  // @63_606b80
}
PCREG(606b80, lifted_606b80);

extern "C" u32 THISCALL lifted_4264b0(u32 ecx_in) {
  SEH_ENTER(0x665420);  // @h_4264b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @1_4264b0
  { u32 v = (u32)((u32)(6785124)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_4264b0
  if ((ecx & ecx) == 0) goto L426573;  // @3_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4264b0
  edx = (u32)(EBP - 24);  // @5_4264b0
  p0_ = edx;  // @6_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(p0_));  // @7_4264b0
  ecx = edx = 0;  // @8_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @9_4264b0
  edx = (u32)(EBP - 24);  // @10_4264b0
  p1_ = edx;  // @11_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, (u32)(p1_));  // @13_4264b0
  ecx = edx = 0;  // @14_4264b0
  esi = eax;  // @15_4264b0
  if ((esi & esi) == 0) goto L426573;  // @16_4264b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6774960), sizeof v); (u32)v; });  // @17_4264b0
  L426512:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @19_4264b0
  if ((ecx & ecx) == 0) goto L426520;  // @20_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @22_4264b0
  ecx = edx = 0;  // @23_4264b0
  L426520:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @25_4264b0
  if ((ecx & ecx) == 0) goto L42652e;  // @26_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @28_4264b0
  ecx = edx = 0;  // @29_4264b0
  L42652e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @31_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4264b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6785452), (u32)(27));  // @33_4264b0
  ecx = edx = 0;  // @34_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_4264b0
  p2_ = eax;  // @36_4264b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p2_), (u32)(6785504), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @37_4264b0
  ecx = edx = 0;  // @38_4264b0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(1));  // @39_4264b0
  ecx = edx = 0;  // @40_4264b0
  eax = ((u32(STDCALL *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @41_4264b0
  ecx = edx = 0;  // @42_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @43_4264b0
  edx = (u32)(EBP - 24);  // @44_4264b0
  p3_ = edx;  // @45_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, (u32)(p3_));  // @47_4264b0
  ecx = edx = 0;  // @48_4264b0
  esi = eax;  // @49_4264b0
  if ((esi & esi) != 0) goto L426512;  // @50_4264b0
  L426573:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @52_4264b0
  if ((ecx & ecx) == 0) goto L426583;  // @53_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @55_4264b0
  ecx = edx = 0;  // @56_4264b0
  L426583:;
  ecx = edi;  // @58_4264b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7340948), &v, sizeof v); }  // @59_4264b0
  eax = ext_433f30_thiscall1(ecx);  // @60_4264b0
  ecx = edx = 0;  // @61_4264b0
  SEH_LEAVE();  // @62_4264b0
  return eax;  // @63_4264b0
}
PCREG(4264b0, lifted_4264b0);

extern "C" u32 THISCALL lifted_4d81f0(u32 ecx_in) {
  SEH_ENTER(0x669639);  // @h_4d81f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_4d81f0
  { u32 v = (u32)((u32)(6909020)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1_4d81f0
  eax = ext_41e290_cdecl1((u32)(28));  // @2_4d81f0
  ecx = edx = 0;  // @3_4d81f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4d81f0
  reg.state = (s32)((u32)(0));  // @5_4d81f0
  if ((eax & eax) == 0) goto L4d8242;  // @6_4d81f0
  ecx = eax;  // @7_4d81f0
  eax = ext_4ccd10_thiscall3(ecx, (u32)(8), (u32)(1));  // @8_4d81f0
  ecx = edx = 0;  // @9_4d81f0
  goto L4d8244;  // @10_4d81f0
  L4d8242:;
  eax = 0;  // @12_4d81f0
  L4d8244:;
  reg.state = (s32)((u32)(4294967295));  // @14_4d81f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @15_4d81f0
  eax = ext_41e290_cdecl1((u32)(264));  // @16_4d81f0
  ecx = edx = 0;  // @17_4d81f0
  esi = eax;  // @18_4d81f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @19_4d81f0
  reg.state = (s32)((u32)(1));  // @20_4d81f0
  if ((esi & esi) == 0) goto L4d82a0;  // @21_4d81f0
  ecx = (u32)(esi + 4);  // @22_4d81f0
  { u32 v = (u32)((u32)(6908948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @23_4d81f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6909368));  // @24_4d81f0
  ecx = edx = 0;  // @25_4d81f0
  ecx = (u32)(esi + 132);  // @26_4d81f0
  reg.state = (s32)((u32)(2));  // @27_4d81f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6909324));  // @28_4d81f0
  ecx = edx = 0;  // @29_4d81f0
  { u32 v = (u32)((u32)(6909044)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @30_4d81f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 260), &v, sizeof v); }  // @31_4d81f0
  goto L4d82a2;  // @32_4d81f0
  L4d82a0:;
  esi = 0;  // @34_4d81f0
  L4d82a2:;
  p0_ = esi;  // @36_4d81f0
  ecx = edi;  // @37_4d81f0
  reg.state = (s32)((u32)(4294967295));  // @38_4d81f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @39_4d81f0
  eax = ext_4d8600_thiscall2(ecx, (u32)(p0_));  // @40_4d81f0
  ecx = edx = 0;  // @41_4d81f0
  eax = ext_41e290_cdecl1((u32)(264));  // @42_4d81f0
  ecx = edx = 0;  // @43_4d81f0
  esi = eax;  // @44_4d81f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @45_4d81f0
  reg.state = (s32)((u32)(3));  // @46_4d81f0
  if ((esi & esi) == 0) goto L4d8306;  // @47_4d81f0
  ecx = (u32)(esi + 4);  // @48_4d81f0
  { u32 v = (u32)((u32)(6908948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @49_4d81f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6909412));  // @50_4d81f0
  ecx = edx = 0;  // @51_4d81f0
  ecx = (u32)(esi + 132);  // @52_4d81f0
  reg.state = (s32)((u32)(4));  // @53_4d81f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6909380));  // @54_4d81f0
  ecx = edx = 0;  // @55_4d81f0
  { u32 v = (u32)((u32)(6909116)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @56_4d81f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 260), &v, sizeof v); }  // @57_4d81f0
  goto L4d8308;  // @58_4d81f0
  L4d8306:;
  esi = 0;  // @60_4d81f0
  L4d8308:;
  p1_ = esi;  // @62_4d81f0
  ecx = edi;  // @63_4d81f0
  reg.state = (s32)((u32)(4294967295));  // @64_4d81f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @65_4d81f0
  eax = ext_4d8600_thiscall2(ecx, (u32)(p1_));  // @66_4d81f0
  ecx = edx = 0;  // @67_4d81f0
  eax = edi;  // @68_4d81f0
  SEH_LEAVE();  // @69_4d81f0
  return eax;  // @70_4d81f0
}
PCREG(4d81f0, lifted_4d81f0);

extern "C" u32 THISCALL lifted_6074f0(u32 ecx_in) {
  SEH_ENTER(0x66dfe1);  // @h_6074f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_6074f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6074f0
  esi = (u32)(edi + 20);  // @2_6074f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @3_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @4_6074f0
  ecx = esi;  // @5_6074f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @6_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @8_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @9_6074f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @10_6074f0
  ecx = edx = 0;  // @11_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @13_6074f0
  ecx = (u32)(eax + 8);  // @14_6074f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @15_6074f0
  if ((eax & eax) == 0) goto L60755f;  // @16_6074f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @17_6074f0
  L60755f:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @19_6074f0
  esi = (u32)(edi + 32);  // @20_6074f0
  reg.state = (s32)((u32)(0));  // @21_6074f0
  ecx = esi;  // @22_6074f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @23_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @24_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @25_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @26_6074f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @27_6074f0
  ecx = edx = 0;  // @28_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @29_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @30_6074f0
  ecx = (u32)(eax + 8);  // @31_6074f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @32_6074f0
  if ((eax & eax) == 0) goto L60759e;  // @33_6074f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @34_6074f0
  L60759e:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @36_6074f0
  esi = (u32)(edi + 44);  // @37_6074f0
  reg.state = (s32)((u32)(1));  // @38_6074f0
  ecx = esi;  // @39_6074f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @40_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @41_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @42_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @43_6074f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @44_6074f0
  ecx = edx = 0;  // @45_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @46_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @47_6074f0
  ecx = (u32)(eax + 8);  // @48_6074f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @49_6074f0
  if ((eax & eax) == 0) goto L6075da;  // @50_6074f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @51_6074f0
  L6075da:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @53_6074f0
  esi = (u32)(edi + 56);  // @54_6074f0
  reg.state = (s32)((u32)(2));  // @55_6074f0
  ecx = esi;  // @56_6074f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @57_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @58_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @59_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @60_6074f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @61_6074f0
  ecx = edx = 0;  // @62_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @63_6074f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @64_6074f0
  ecx = (u32)(eax + 8);  // @65_6074f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @66_6074f0
  if ((eax & eax) == 0) goto L607616;  // @67_6074f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @68_6074f0
  L607616:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @70_6074f0
  eax = edi;  // @71_6074f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @72_6074f0
  SEH_LEAVE();  // @73_6074f0
  return eax;  // @74_6074f0
}
PCREG(6074f0, lifted_6074f0);

extern "C" u32 THISCALL lifted_42c170(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664ce2);  // @h_42c170
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_42c170
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_42c170
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_42c170
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 788), &v, sizeof v); }  // @3_42c170
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) != (u32)(0)) goto L42c1c6;  // @4_42c170
  ecx = esi;  // @5_42c170
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @6_42c170
  ecx = edx = 0;  // @7_42c170
  goto L42c2c3;  // @8_42c170
  L42c1c6:;
  p0_ = edi;  // @10_42c170
  ecx = (u32)(EBP - 144);  // @11_42c170
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @12_42c170
  ecx = edx = 0;  // @13_42c170
  ecx = (u32)(EBP - 144);  // @14_42c170
  reg.state = (s32)((u32)(0));  // @15_42c170
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_42c170
  ecx = edx = 0;  // @17_42c170
  p1_ = eax;  // @18_42c170
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p1_), (u32)(58));  // @19_42c170
  ecx = edx = 0;  // @20_42c170
  if ((eax & eax) != 0) goto L42c2aa;  // @21_42c170
  p2_ = edi;  // @22_42c170
  ecx = (u32)(EBP - 400);  // @23_42c170
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p2_));  // @24_42c170
  ecx = edx = 0;  // @25_42c170
  ecx = (u32)(EBP - 272);  // @26_42c170
  reg.state = (s32)((u32)(1));  // @27_42c170
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @28_42c170
  ecx = edx = 0;  // @29_42c170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @30_42c170
  ecx = (u32)(EBP - 784);  // @31_42c170
  p3_ = ecx;  // @32_42c170
  ecx = ebx;  // @33_42c170
  reg.state = (s32)((u32)(2));  // @34_42c170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 296)))(ecx, (u32)(p3_));  // @35_42c170
  ecx = edx = 0;  // @36_42c170
  ecx = (u32)(EBP - 272);  // @37_42c170
  reg.state = (s32)((u32)(3));  // @38_42c170
  p4_ = ecx;  // @39_42c170
  ecx = (u32)(EBP - 656);  // @40_42c170
  p5_ = ecx;  // @41_42c170
  ecx = eax;  // @42_42c170
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p5_), (u32)(p4_));  // @43_42c170
  ecx = edx = 0;  // @44_42c170
  ecx = (u32)(EBP - 400);  // @45_42c170
  reg.state = (s32)((u32)(4));  // @46_42c170
  p6_ = ecx;  // @47_42c170
  ecx = (u32)(EBP - 528);  // @48_42c170
  p7_ = ecx;  // @49_42c170
  ecx = eax;  // @50_42c170
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p7_), (u32)(p6_));  // @51_42c170
  ecx = edx = 0;  // @52_42c170
  p8_ = eax;  // @53_42c170
  ecx = (u32)(EBP - 144);  // @54_42c170
  reg.state = (s32)((u32)(5));  // @55_42c170
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p8_));  // @56_42c170
  ecx = edx = 0;  // @57_42c170
  ecx = (u32)(EBP - 528);  // @58_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @59_42c170
  ecx = edx = 0;  // @60_42c170
  ecx = (u32)(EBP - 656);  // @61_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @62_42c170
  ecx = edx = 0;  // @63_42c170
  ecx = (u32)(EBP - 784);  // @64_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @65_42c170
  ecx = edx = 0;  // @66_42c170
  ecx = (u32)(EBP - 272);  // @67_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @68_42c170
  ecx = edx = 0;  // @69_42c170
  ecx = (u32)(EBP - 400);  // @70_42c170
  reg.state = (s32)((u32)(0));  // @71_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @72_42c170
  ecx = edx = 0;  // @73_42c170
  L42c2aa:;
  eax = (u32)(EBP - 144);  // @75_42c170
  ecx = esi;  // @76_42c170
  p9_ = eax;  // @77_42c170
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p9_));  // @78_42c170
  ecx = edx = 0;  // @79_42c170
  ecx = (u32)(EBP - 144);  // @80_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @81_42c170
  ecx = edx = 0;  // @82_42c170
  L42c2c3:;
  eax = esi;  // @84_42c170
  SEH_LEAVE();  // @85_42c170
  ext_633654(G(u32, 0x6f5630));  // @86_42c170
  return eax;  // @87_42c170
}
PCREG(42c170, lifted_42c170);

extern "C" u32 THISCALL lifted_4b8fd0(u32 ecx_in) {
  SEH_ENTER(0x668c56);  // @h_4b8fd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4b8fd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4b8fd0
  eax = ext_469870_thiscall1(ecx);  // @2_4b8fd0
  ecx = edx = 0;  // @3_4b8fd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4b8fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4b8fd0
  { u32 v = (u32)((u32)(6892080)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_4b8fd0
  reg.state = (s32)((u32)(0));  // @9_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6827544), (u32)(0), (u32)(6892212), (u32)(36));  // @11_4b8fd0
  ecx = edx = 0;  // @12_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 149), &v, sizeof v); }  // @13_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6858876), (u32)(0), (u32)(6892212), (u32)(37));  // @17_4b8fd0
  ecx = edx = 0;  // @18_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 151), &v, sizeof v); }  // @19_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892260), (u32)(0), (u32)(6892212), (u32)(38));  // @23_4b8fd0
  ecx = edx = 0;  // @24_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 153), &v, sizeof v); }  // @25_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @27_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892276), (u32)(0), (u32)(6892212), (u32)(39));  // @29_4b8fd0
  ecx = edx = 0;  // @30_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @31_4b8fd0
  eax = ext_41e290_cdecl1((u32)(109));  // @32_4b8fd0
  ecx = edx = 0;  // @33_4b8fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @34_4b8fd0
  reg.state = (s32)((u32)(1));  // @35_4b8fd0
  if ((eax & eax) == 0) goto L4b90d6;  // @36_4b8fd0
  ecx = eax;  // @37_4b8fd0
  eax = ext_4e1b60_thiscall1(ecx);  // @38_4b8fd0
  ecx = edx = 0;  // @39_4b8fd0
  goto L4b90d8;  // @40_4b8fd0
  L4b90d6:;
  eax = 0;  // @42_4b8fd0
  L4b90d8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @44_4b8fd0
  reg.state = (s32)((u32)(0));  // @45_4b8fd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 108), &v, sizeof v); }  // @46_4b8fd0
  eax = ext_41e290_cdecl1((u32)(44));  // @47_4b8fd0
  ecx = edx = 0;  // @48_4b8fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @49_4b8fd0
  reg.state = (s32)((u32)(2));  // @50_4b8fd0
  if ((eax & eax) == 0) goto L4b9104;  // @51_4b8fd0
  ecx = eax;  // @52_4b8fd0
  eax = ext_4e7160_thiscall1(ecx);  // @53_4b8fd0
  ecx = edx = 0;  // @54_4b8fd0
  goto L4b9106;  // @55_4b8fd0
  L4b9104:;
  eax = 0;  // @57_4b8fd0
  L4b9106:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @59_4b8fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 137), &v, sizeof v); }  // @60_4b8fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }  // @61_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_4b8fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_4b8fd0
  reg.state = (s32)((u32)(0));  // @64_4b8fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4b8fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892288), (u32)(0), (u32)(6892212), (u32)(49));  // @66_4b8fd0
  ecx = edx = 0;  // @67_4b8fd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 157), &v, sizeof v); }  // @68_4b8fd0
  eax = esi;  // @69_4b8fd0
  SEH_LEAVE();  // @70_4b8fd0
  return eax;  // @71_4b8fd0
}
PCREG(4b8fd0, lifted_4b8fd0);

extern "C" u32 THISCALL lifted_45e710(u32 ecx_in) {
  SEH_ENTER(0x66d436);  // @h_45e710
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45e710
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L45e825;  // @1_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_45e710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @3_45e710
  ecx = edx = 0;  // @4_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_45e710
  ecx = esi;  // @6_45e710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @7_45e710
  ecx = edx = 0;  // @8_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @9_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @10_45e710
  if ((edx & edx) == 0) goto L45e78c;  // @11_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7261), sizeof v); (u32)v; });  // @14_45e710
  if (edx < ecx) goto L45e781;  // @15_45e710
  if ((ecx & ecx) == 0) goto L45e781;  // @16_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 8), sizeof v); (u32)v; });  // @17_45e710
  eax = (eax & (u32)(536870911));  // @18_45e710
  eax = (eax + ecx);  // @19_45e710
  if (edx < eax) goto L45e78c;  // @20_45e710
  L45e781:;
  p0_ = edx;  // @22_45e710
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(24));  // @23_45e710
  ecx = edx = 0;  // @24_45e710
  L45e78c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @26_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @27_45e710
  if ((eax & eax) == 0) goto L45e7a1;  // @28_45e710
  p1_ = eax;  // @29_45e710
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(8));  // @30_45e710
  ecx = edx = 0;  // @31_45e710
  L45e7a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @33_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @34_45e710
  if ((eax & eax) == 0) goto L45e811;  // @35_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @36_45e710
  if ((eax & eax) == 0) goto L45e7c5;  // @37_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @38_45e710
  if ((edx & edx) == 0) goto L45e7c5;  // @39_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @40_45e710
  p2_ = edx;  // @41_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p2_));  // @43_45e710
  ecx = edx = 0;  // @44_45e710
  L45e7c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @46_45e710
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @47_45e710
  if ((edi & edi) == 0) goto L45e811;  // @48_45e710
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @49_45e710
  if ((ebx & ebx) == 0) goto L45e806;  // @50_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @51_45e710
  reg.state = (s32)((u32)(0));  // @52_45e710
  if ((ecx & ecx) == 0) goto L45e7f4;  // @53_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @54_45e710
  if ((edx & edx) == 0) goto L45e7f4;  // @55_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_45e710
  p3_ = edx;  // @57_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p3_));  // @58_45e710
  ecx = edx = 0;  // @59_45e710
  L45e7f4:;
  p4_ = ebx;  // @61_45e710
  eax = ext_634273_cdecl2((u32)(p4_), (u32)(16));  // @62_45e710
  ecx = edx = 0;  // @63_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @64_45e710
  L45e806:;
  p5_ = edi;  // @66_45e710
  eax = ext_634273_cdecl2((u32)(p5_), (u32)(8));  // @67_45e710
  ecx = edx = 0;  // @68_45e710
  L45e811:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }), (u32)(32));  // @70_45e710
  ecx = edx = 0;  // @71_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @72_45e710
  L45e825:;
  SEH_LEAVE();  // @74_45e710
  return eax;  // @75_45e710
}
PCREG(45e710, lifted_45e710);

extern "C" u32 THISCALL lifted_6150c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e51a);  // @h_6150c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_6150c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6150c0
  edx = 0;  // @2_6150c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @3_6150c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; });  // @4_6150c0
  if (eax > (u32)(4)) goto L6151f1;  // @5_6150c0
  switch (eax) { case 0: goto L615102; case 1: goto L61512e; case 2: goto L61518f; case 3: goto L6151b4; case 4: goto L6151ca; default: __builtin_trap(); }  // @6_6150c0
  L615102:;
  eax = ext_41e290_cdecl1((u32)(52));  // @8_6150c0
  ecx = edx = 0;  // @9_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @10_6150c0
  reg.state = (s32)((u32)(0));  // @11_6150c0
  if ((eax & eax) == 0) goto L6151ef;  // @12_6150c0
  p0_ = esi;  // @13_6150c0
  p1_ = edi;  // @14_6150c0
  ecx = eax;  // @15_6150c0
  eax = ext_6168f0_thiscall3(ecx, (u32)(p1_), (u32)(p0_));  // @16_6150c0
  ecx = edx = 0;  // @17_6150c0
  edx = eax;  // @18_6150c0
  goto L6151f1;  // @19_6150c0
  L61512e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47524), sizeof v); (u32)v; });  // @21_6150c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5101), sizeof v); (u32)v; })) & 0xff);  // @22_6150c0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L61516a;  // @23_6150c0
  eax = ext_41e290_cdecl1((u32)(48));  // @24_6150c0
  ecx = edx = 0;  // @25_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @26_6150c0
  reg.state = (s32)((u32)(1));  // @27_6150c0
  if ((eax & eax) == 0) goto L6151ef;  // @28_6150c0
  p2_ = esi;  // @29_6150c0
  p3_ = edi;  // @30_6150c0
  ecx = eax;  // @31_6150c0
  eax = ext_6162f0_thiscall3(ecx, (u32)(p3_), (u32)(p2_));  // @32_6150c0
  ecx = edx = 0;  // @33_6150c0
  edx = eax;  // @34_6150c0
  goto L6151f1;  // @35_6150c0
  L61516a:;
  eax = ext_41e290_cdecl1((u32)(16));  // @37_6150c0
  ecx = edx = 0;  // @38_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @39_6150c0
  reg.state = (s32)((u32)(2));  // @40_6150c0
  if ((eax & eax) == 0) goto L6151ef;  // @41_6150c0
  p4_ = esi;  // @42_6150c0
  p5_ = edi;  // @43_6150c0
  ecx = eax;  // @44_6150c0
  eax = ext_616150_thiscall3(ecx, (u32)(p5_), (u32)(p4_));  // @45_6150c0
  ecx = edx = 0;  // @46_6150c0
  edx = eax;  // @47_6150c0
  goto L6151f1;  // @48_6150c0
  L61518f:;
  eax = ext_41e290_cdecl1((u32)(12));  // @50_6150c0
  ecx = edx = 0;  // @51_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @52_6150c0
  reg.state = (s32)((u32)(3));  // @53_6150c0
  if ((eax & eax) == 0) goto L6151ef;  // @54_6150c0
  p6_ = esi;  // @55_6150c0
  p7_ = edi;  // @56_6150c0
  ecx = eax;  // @57_6150c0
  eax = ext_6168c0_thiscall3(ecx, (u32)(p7_), (u32)(p6_));  // @58_6150c0
  ecx = edx = 0;  // @59_6150c0
  edx = eax;  // @60_6150c0
  goto L6151f1;  // @61_6150c0
  L6151b4:;
  eax = ext_41e290_cdecl1((u32)(48));  // @63_6150c0
  ecx = edx = 0;  // @64_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @65_6150c0
  reg.state = (s32)((u32)(4));  // @66_6150c0
  goto L6151de;  // @67_6150c0
  L6151ca:;
  eax = ext_41e290_cdecl1((u32)(48));  // @69_6150c0
  ecx = edx = 0;  // @70_6150c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @71_6150c0
  reg.state = (s32)((u32)(5));  // @72_6150c0
  L6151de:;
  if ((eax & eax) == 0) goto L6151ef;  // @74_6150c0
  p8_ = esi;  // @75_6150c0
  p9_ = edi;  // @76_6150c0
  ecx = eax;  // @77_6150c0
  eax = ext_6166c0_thiscall3(ecx, (u32)(p9_), (u32)(p8_));  // @78_6150c0
  ecx = edx = 0;  // @79_6150c0
  edx = eax;  // @80_6150c0
  goto L6151f1;  // @81_6150c0
  L6151ef:;
  edx = 0;  // @83_6150c0
  L6151f1:;
  eax = edx;  // @85_6150c0
  SEH_LEAVE();  // @86_6150c0
  return eax;  // @87_6150c0
}
PCREG(6150c0, lifted_6150c0);

extern "C" u32 THISCALL lifted_5c5f30(u32 ecx_in) {
  SEH_ENTER(0x66c6b6);  // @h_5c5f30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @1_5c5f30
  { u32 v = (u32)((u32)(7029940)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f6c;  // @3_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_5c5f30
  ecx = edx = 0;  // @6_5c5f30
  L5c5f6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @8_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f79;  // @9_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_5c5f30
  ecx = edx = 0;  // @12_5c5f30
  L5c5f79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @14_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f86;  // @15_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_5c5f30
  ecx = edx = 0;  // @18_5c5f30
  L5c5f86:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @20_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f93;  // @21_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @23_5c5f30
  ecx = edx = 0;  // @24_5c5f30
  L5c5f93:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @26_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fff;  // @27_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5c5f30
  edx = (u32)(EBP - 24);  // @29_5c5f30
  p0_ = edx;  // @30_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @31_5c5f30
  ecx = edx = 0;  // @32_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @33_5c5f30
  edx = (u32)(EBP - 24);  // @34_5c5f30
  p1_ = edx;  // @35_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @37_5c5f30
  ecx = edx = 0;  // @38_5c5f30
  esi = eax;  // @39_5c5f30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L5c5fff;  // @40_5c5f30
  L5c5fb7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @42_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fc4;  // @43_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @45_5c5f30
  ecx = edx = 0;  // @46_5c5f30
  L5c5fc4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @48_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fd1;  // @49_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @51_5c5f30
  ecx = edx = 0;  // @52_5c5f30
  L5c5fd1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @54_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fde;  // @55_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @57_5c5f30
  ecx = edx = 0;  // @58_5c5f30
  L5c5fde:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @60_5c5f30
  if ((ecx & ecx) == 0) goto L5c5feb;  // @61_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @63_5c5f30
  ecx = edx = 0;  // @64_5c5f30
  L5c5feb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @66_5c5f30
  edx = (u32)(EBP - 24);  // @67_5c5f30
  p2_ = edx;  // @68_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @70_5c5f30
  ecx = edx = 0;  // @71_5c5f30
  esi = eax;  // @72_5c5f30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L5c5fb7;  // @73_5c5f30
  L5c5fff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @75_5c5f30
  if ((ecx & ecx) == 0) goto L5c600c;  // @76_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @78_5c5f30
  ecx = edx = 0;  // @79_5c5f30
  L5c600c:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @81_5c5f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @82_5c5f30
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @83_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_5c5f30
  p3_ = edi;  // @85_5c5f30
  reg.state = (s32)((u32)(0));  // @86_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @87_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p3_));  // @89_5c5f30
  ecx = edx = 0;  // @90_5c5f30
  SEH_LEAVE();  // @91_5c5f30
  return eax;  // @92_5c5f30
}
PCREG(5c5f30, lifted_5c5f30);

extern "C" u32 THISCALL lifted_5fb400(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66d471);  // @h_5fb400
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edi = ecx;  // @0_5fb400
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_5fb400
  if (ebx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) goto L5fb4ac;  // @2_5fb400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L5fb4ac;  // @3_5fb400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @4_5fb400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @5_5fb400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 13), sizeof v); (u32)v; });  // @6_5fb400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @7_5fb400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @8_5fb400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_5fb400
  eax = (eax - ecx);  // @10_5fb400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @11_5fb400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @12_5fb400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @13_5fb400
  eax = (eax - edx);  // @14_5fb400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @15_5fb400
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @16_5fb400
  ebx = (u32)(EBP - 24);  // @17_5fb400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @18_5fb400
  eax = (u32)(EBP - 20);  // @19_5fb400
  if ((s32)ebx >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; })) eax = ebx;  // @20_5fb400
  p0_ = edx;  // @21_5fb400
  p1_ = ecx;  // @22_5fb400
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676408))((u32)(p1_), (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @23_5fb400
  ecx = edx = 0;  // @24_5fb400
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @25_5fb400
  if ((eax & eax) != 0) goto L5fb491;  // @26_5fb400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @27_5fb400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @28_5fb400
  if ((s32)ecx < (s32)edx) goto L5fb4ac;  // @29_5fb400
  eax = 0;  // @30_5fb400
  eax = (eax & 0xffffff00u) | (((u32)((s32)ecx > (s32)edx)) & 0xff);  // @31_5fb400
  L5fb491:;
  if ((s32)(eax & eax) < 0) goto L5fb4ac;  // @33_5fb400
  p2_ = esi;  // @34_5fb400
  ecx = edi;  // @35_5fb400
  eax = ext_5fb2c0_stdcall1((u32)(p2_));  // @36_5fb400
  ecx = edx = 0;  // @37_5fb400
  esi = eax;  // @38_5fb400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 9), &v, sizeof v); }  // @39_5fb400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_5fb400
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; })) goto L5fb4f9;  // @41_5fb400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @42_5fb400
  goto L5fb4f9;  // @43_5fb400
  L5fb4ac:;
  ecx = edi;  // @45_5fb400
  eax = ext_6014a0_stdcall1((u32)(29));  // @46_5fb400
  ecx = edx = 0;  // @47_5fb400
  esi = eax;  // @48_5fb400
  eax = (u32)(esi + 13);  // @49_5fb400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @50_5fb400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @51_5fb400
  reg.state = (s32)((u32)(0));  // @52_5fb400
  if ((eax & eax) == 0) goto L5fb4de;  // @53_5fb400
  ecx = eax;  // @54_5fb400
  eax = ext_5f10c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @55_5fb400
  ecx = edx = 0;  // @56_5fb400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @57_5fb400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @58_5fb400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @59_5fb400
  L5fb4de:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 5), &v, sizeof v); }  // @61_5fb400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_5fb400
  if (ebx != eax) goto L5fb4f1;  // @63_5fb400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @64_5fb400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_5fb400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @66_5fb400
  goto L5fb4f9;  // @67_5fb400
  L5fb4f1:;
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5), sizeof v); (u32)v; })) goto L5fb4f9;  // @69_5fb400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @70_5fb400
  L5fb4f9:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1), &v, sizeof v); }  // @72_5fb400
  ecx = esi;  // @73_5fb400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5), &v, sizeof v); }  // @74_5fb400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @75_5fb400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @76_5fb400
  edx = (edx + 1);  // @77_5fb400
  eax = ext_430480_fastcall2(ecx, edx);  // @78_5fb400
  ecx = edx = 0;  // @79_5fb400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @80_5fb400
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @81_5fb400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @82_5fb400
  SEH_LEAVE();  // @83_5fb400
  return eax;  // @84_5fb400
}
PCREG(5fb400, lifted_5fb400);

extern "C" u32 THISCALL lifted_424fc0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x664512);  // @h_424fc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_424fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_424fc0
  eax = ecx;  // @2_424fc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_424fc0
  eax = (eax >> (u32)(8));  // @4_424fc0
  if ((eax & eax) == 0) goto L425007;  // @5_424fc0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L425119;  // @6_424fc0
  L425007:;
  eax = (ecx & 0xff);  // @8_424fc0
  eax = (eax + (u32)(-2));  // @9_424fc0
  if (eax > (u32)(5)) goto L425119;  // @10_424fc0
  switch (eax) { case 0: goto L425067; case 1: goto L425079; case 2: goto L425099; case 3: goto L4250c3; case 4: goto L42501d; case 5: goto L4250a5; default: __builtin_trap(); }  // @11_424fc0
  L42501d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L42505e;  // @13_424fc0
  eax = ext_41e290_cdecl1((u32)(40));  // @14_424fc0
  ecx = edx = 0;  // @15_424fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @16_424fc0
  reg.state = (s32)((u32)(0));  // @17_424fc0
  if ((eax & eax) == 0) goto L42504e;  // @18_424fc0
  ecx = eax;  // @19_424fc0
  eax = ext_4cca60_thiscall3(ecx, (u32)(128), (u32)(5));  // @20_424fc0
  ecx = edx = 0;  // @21_424fc0
  goto L425050;  // @22_424fc0
  L42504e:;
  eax = 0;  // @24_424fc0
  L425050:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @26_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_424fc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6980), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 6980), &v, sizeof v); }  // @28_424fc0
  L42505e:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @30_424fc0
  goto L425119;  // @31_424fc0
  L425067:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L425119;  // @33_424fc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @34_424fc0
  goto L425119;  // @35_424fc0
  L425079:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L425119;  // @37_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_424fc0
  ecx = esi;  // @39_424fc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @40_424fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(8), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }), (u32)(0));  // @41_424fc0
  ecx = edx = 0;  // @42_424fc0
  goto L425119;  // @43_424fc0
  L425099:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != edi) goto L4250a5;  // @45_424fc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @46_424fc0
  L4250a5:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L4250bd;  // @48_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_424fc0
  ecx = esi;  // @50_424fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 72)))(ecx);  // @51_424fc0
  ecx = edx = 0;  // @52_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_424fc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6980), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 6980), &v, sizeof v); }  // @54_424fc0
  L4250bd:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @56_424fc0
  goto L425119;  // @57_424fc0
  L4250c3:;
  if ((edi & edi) == 0) goto L425106;  // @59_424fc0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L4250fd;  // @60_424fc0
  eax = (u32)(EBP - 272);  // @61_424fc0
  p0_ = eax;  // @62_424fc0
  p1_ = edi;  // @63_424fc0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6760f8))((u32)(p1_), (u32)(p0_), (u32)(255));  // @64_424fc0
  ecx = edx = 0;  // @65_424fc0
  p2_ = edi;  // @66_424fc0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760f0))((u32)(p2_));  // @67_424fc0
  ecx = edx = 0;  // @68_424fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_424fc0
  edx = (u32)(EBP - 272);  // @70_424fc0
  p3_ = edx;  // @71_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_424fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(p3_), (u32)(0));  // @73_424fc0
  ecx = edx = 0;  // @74_424fc0
  goto L425119;  // @75_424fc0
  L4250fd:;
  p4_ = edi;  // @77_424fc0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760f0))((u32)(p4_));  // @78_424fc0
  ecx = edx = 0;  // @79_424fc0
  goto L425119;  // @80_424fc0
  L425106:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @82_424fc0
  p5_ = eax;  // @83_424fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @84_424fc0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 52)))((u32)(p5_), (u32)(6784928));  // @85_424fc0
  ecx = edx = 0;  // @86_424fc0
  L425119:;
  eax = 0;  // @88_424fc0
  SEH_LEAVE();  // @89_424fc0
  ext_633654(G(u32, 0x6f5630));  // @90_424fc0
  return eax;  // @91_424fc0
}
PCREG(424fc0, lifted_424fc0);

extern "C" u32 THISCALL lifted_42c9a0(u32 ecx_in) {
  SEH_ENTER(0x664dc6);  // @h_42c9a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_42c9a0
  ebx = (u32)(edi + 1187);  // @1_42c9a0
  ecx = ebx;  // @2_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @3_42c9a0
  ecx = edx = 0;  // @4_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(37)) goto L42cb07;  // @5_42c9a0
  ecx = ebx;  // @6_42c9a0
  esi = (u32)(1);  // @7_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @8_42c9a0
  ecx = edx = 0;  // @9_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }) == (u32)(37)) goto L42ca06;  // @10_42c9a0
  L42c9f8:;
  ecx = ebx;  // @12_42c9a0
  esi = (esi + 1);  // @13_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @14_42c9a0
  ecx = edx = 0;  // @15_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(37)) goto L42c9f8;  // @16_42c9a0
  L42ca06:;
  ecx = ebx;  // @18_42c9a0
  esi = (esi + 1);  // @19_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @20_42c9a0
  ecx = edx = 0;  // @21_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) == (u32)(92)) goto L42ca06;  // @22_42c9a0
  ecx = ebx;  // @23_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_42c9a0
  ecx = edx = 0;  // @25_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) == (u32)(47)) goto L42ca06;  // @26_42c9a0
  ecx = ebx;  // @27_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_42c9a0
  ecx = edx = 0;  // @29_42c9a0
  eax = (eax + 1);  // @30_42c9a0
  p0_ = eax;  // @31_42c9a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676410))((u32)(p0_), (u32)(6790792), (u32)(7));  // @32_42c9a0
  ecx = edx = 0;  // @33_42c9a0
  if ((eax & eax) != 0) goto L42cb07;  // @34_42c9a0
  eax = ext_41e290_cdecl1((u32)(260));  // @35_42c9a0
  ecx = edx = 0;  // @36_42c9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_42c9a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @38_42c9a0
  ecx = edi;  // @39_42c9a0
  eax = (u32)(EBP - 272);  // @40_42c9a0
  p1_ = eax;  // @41_42c9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 412)))(ecx, (u32)(p1_));  // @42_42c9a0
  ecx = edx = 0;  // @43_42c9a0
  ecx = eax;  // @44_42c9a0
  reg.state = (s32)((u32)(0));  // @45_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @46_42c9a0
  ecx = edx = 0;  // @47_42c9a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @48_42c9a0
  edx = edi;  // @49_42c9a0
  edx = (edx - eax);  // @50_42c9a0
  L42ca80:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @52_42c9a0
  eax = (u32)(eax + 1);  // @53_42c9a0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @54_42c9a0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L42ca80;  // @55_42c9a0
  ecx = (u32)(EBP - 272);  // @56_42c9a0
  reg.state = (s32)((u32)(4294967295));  // @57_42c9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @58_42c9a0
  ecx = edx = 0;  // @59_42c9a0
  ecx = ebx;  // @60_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @61_42c9a0
  ecx = edx = 0;  // @62_42c9a0
  edx = (u32)(esi + eax);  // @63_42c9a0
  esi = edx;  // @64_42c9a0
  L42cab0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @66_42c9a0
  edx = (edx + 1);  // @67_42c9a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42cab0;  // @68_42c9a0
  edx = (edx - esi);  // @69_42c9a0
  edi = (edi - 1);  // @70_42c9a0
  L42cac0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @72_42c9a0
  edi = (edi + 1);  // @73_42c9a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42cac0;  // @74_42c9a0
  ecx = edx;  // @75_42c9a0
  ecx = (ecx >> (u32)(2));  // @76_42c9a0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @77_42c9a0
  ecx = edx;  // @78_42c9a0
  ecx = (ecx & (u32)(3));  // @79_42c9a0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 1); esi += 1; edi += 1; ecx--; }  // @80_42c9a0
  ecx = (u32)(EBP - 144);  // @81_42c9a0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @82_42c9a0
  ecx = edx = 0;  // @83_42c9a0
  eax = (u32)(EBP - 144);  // @84_42c9a0
  reg.state = (s32)((u32)(1));  // @85_42c9a0
  p2_ = eax;  // @86_42c9a0
  ecx = ebx;  // @87_42c9a0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @88_42c9a0
  ecx = edx = 0;  // @89_42c9a0
  ecx = (u32)(EBP - 144);  // @90_42c9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @91_42c9a0
  ecx = edx = 0;  // @92_42c9a0
  L42cb07:;
  SEH_LEAVE();  // @94_42c9a0
  ext_633654(G(u32, 0x6f5630));  // @95_42c9a0
  return eax;  // @96_42c9a0
}
PCREG(42c9a0, lifted_42c9a0);

extern "C" u32 THISCALL lifted_45d5c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66676f);  // @h_45d5c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_45d5c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @2_45d5c0
  ecx = edx = 0;  // @3_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @4_45d5c0
  if ((eax & eax) == 0) goto L45d600;  // @5_45d5c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @6_45d5c0
  L45d600:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @9_45d5c0
  eax = ext_4da3a0_thiscall1(ecx);  // @10_45d5c0
  ecx = edx = 0;  // @11_45d5c0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L45d700;  // @12_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_45d5c0
  ecx = ebx;  // @14_45d5c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @15_45d5c0
  ecx = edx = 0;  // @16_45d5c0
  eax = ext_41e290_cdecl1((u32)(28));  // @17_45d5c0
  ecx = edx = 0;  // @18_45d5c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @19_45d5c0
  reg.state = (s32)((u32)(0));  // @20_45d5c0
  if ((eax & eax) == 0) goto L45d641;  // @21_45d5c0
  ecx = eax;  // @22_45d5c0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @23_45d5c0
  ecx = edx = 0;  // @24_45d5c0
  ecx = eax;  // @25_45d5c0
  goto L45d643;  // @26_45d5c0
  L45d641:;
  ecx = 0;  // @28_45d5c0
  L45d643:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @30_45d5c0
  reg.state = (s32)((u32)(4294967295));  // @31_45d5c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @32_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @33_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @34_45d5c0
  if ((ecx & ecx) == 0) goto L45d700;  // @35_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_45d5c0
  edx = (u32)(EBP - 28);  // @37_45d5c0
  p0_ = edx;  // @38_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @39_45d5c0
  ecx = edx = 0;  // @40_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @41_45d5c0
  edx = (u32)(EBP - 28);  // @42_45d5c0
  p1_ = edx;  // @43_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @44_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @46_45d5c0
  ecx = edx = 0;  // @47_45d5c0
  edx = eax;  // @48_45d5c0
  if ((edx & edx) == 0) goto L45d700;  // @49_45d5c0
  L45d680:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @51_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @53_45d5c0
  ecx = edx = 0;  // @54_45d5c0
  esi = eax;  // @55_45d5c0
  if ((esi & esi) != 0) goto L45d6a7;  // @56_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @57_45d5c0
  edx = (u32)(EBP - 28);  // @58_45d5c0
  p2_ = edx;  // @59_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @60_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p2_));  // @62_45d5c0
  ecx = edx = 0;  // @63_45d5c0
  goto L45d6eb;  // @64_45d5c0
  L45d6a7:;
  ecx = ebx;  // @66_45d5c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L45d6bf;  // @67_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_45d5c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 272)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }));  // @69_45d5c0
  ecx = edx = 0;  // @70_45d5c0
  goto L45d6eb;  // @71_45d5c0
  L45d6bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @73_45d5c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @74_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 264)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @75_45d5c0
  ecx = edx = 0;  // @76_45d5c0
  edi = eax;  // @77_45d5c0
  p3_ = esi;  // @78_45d5c0
  ecx = edi;  // @79_45d5c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @80_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(p3_));  // @81_45d5c0
  ecx = edx = 0;  // @82_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @83_45d5c0
  ecx = (ecx | ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @84_45d5c0
  ecx = (ecx & (u32)(4294967283));  // @85_45d5c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @86_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @87_45d5c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @88_45d5c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @89_45d5c0
  L45d6eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @91_45d5c0
  edx = (u32)(EBP - 28);  // @92_45d5c0
  p4_ = edx;  // @93_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @94_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @96_45d5c0
  ecx = edx = 0;  // @97_45d5c0
  edx = eax;  // @98_45d5c0
  if ((edx & edx) != 0) goto L45d680;  // @99_45d5c0
  L45d700:;
  SEH_LEAVE();  // @101_45d5c0
  return eax;  // @102_45d5c0
}
PCREG(45d5c0, lifted_45d5c0);

extern "C" u32 THISCALL lifted_431880(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665451);  // @h_431880
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_431880
  esi = (u32)(ecx + 132);  // @1_431880
  edi = 0;  // @2_431880
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @3_431880
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_431880
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @5_431880
  if ((esi & esi) == 0) goto L431971;  // @6_431880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_431880
  ecx = (u32)(EBP - 32);  // @8_431880
  p0_ = ecx;  // @9_431880
  ecx = esi;  // @10_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @11_431880
  ecx = edx = 0;  // @12_431880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_431880
  ecx = (u32)(EBP - 32);  // @14_431880
  p1_ = ecx;  // @15_431880
  ecx = esi;  // @16_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @17_431880
  ecx = edx = 0;  // @18_431880
  edi = eax;  // @19_431880
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @20_431880
  if ((edi & edi) == 0) goto L43196a;  // @21_431880
  L4318e6:;
  ecx = ebx;  // @23_431880
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_431880
  ecx = edx = 0;  // @25_431880
  p2_ = eax;  // @26_431880
  ecx = edi;  // @27_431880
  eax = ext_4cc1d0_cdecl1((u32)(p2_));  // @28_431880
  ecx = edx = 0;  // @29_431880
  p3_ = eax;  // @30_431880
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676414))((u32)(p3_));  // @31_431880
  ecx = edx = 0;  // @32_431880
  if ((eax & eax) != 0) goto L431938;  // @33_431880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @34_431880
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 165), sizeof v); (u32)v; }) == (eax & 0xff)) goto L43192d;  // @35_431880
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 167), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 167), sizeof v); (u32)v; }));  // @36_431880
  ecx = edx = 0;  // @37_431880
  if ((eax & eax) != 0) goto L43192d;  // @38_431880
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @39_431880
  goto L431938;  // @40_431880
  L43192d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_431880
  ecx = (u32)(EBP - 32);  // @43_431880
  p4_ = ecx;  // @44_431880
  ecx = esi;  // @45_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p4_));  // @46_431880
  ecx = edx = 0;  // @47_431880
  L431938:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_431880
  ecx = (u32)(EBP - 32);  // @50_431880
  p5_ = ecx;  // @51_431880
  ecx = esi;  // @52_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p5_));  // @53_431880
  ecx = edx = 0;  // @54_431880
  edi = eax;  // @55_431880
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @56_431880
  if ((edi & edi) != 0) goto L4318e6;  // @57_431880
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 13), sizeof v); (u32)v; })) & 0xff);  // @58_431880
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L43196e;  // @59_431880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @60_431880
  SEH_LEAVE();  // @61_431880
  return eax;  // @62_431880
  L43196a:;
  edi = 0;  // @64_431880
  goto L431971;  // @65_431880
  L43196e:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @67_431880
  L431971:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @69_431880
  ecx = esi;  // @70_431880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @71_431880
  ecx = edx = 0;  // @72_431880
  esi = eax;  // @73_431880
  esi = (esi - (u32)(4));  // @74_431880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @75_431880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @76_431880
  reg.state = (s32)((u32)(0));  // @77_431880
  if (esi == 0) goto L431997;  // @78_431880
  ecx = esi;  // @79_431880
  eax = ext_4cbeb0_thiscall1(ecx);  // @80_431880
  ecx = edx = 0;  // @81_431880
  goto L431999;  // @82_431880
  L431997:;
  esi = 0;  // @84_431880
  L431999:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 160), sizeof v); (u32)v; })) & 0xff);  // @86_431880
  ecx = esi;  // @87_431880
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @88_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 161), &v, sizeof v); }  // @89_431880
  { u16 v = (u16)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 165), &v, sizeof v); }  // @90_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @91_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @92_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @93_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @94_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 136), &v, sizeof v); }  // @95_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @96_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @97_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @98_431880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 167), sizeof v); (u32)v; });  // @99_431880
  p6_ = ebx;  // @100_431880
  reg.state = (s32)((u32)(4294967295));  // @101_431880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 167), &v, sizeof v); }  // @102_431880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 171), &v, sizeof v); }  // @103_431880
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p6_));  // @104_431880
  ecx = edx = 0;  // @105_431880
  eax = (u32)(edi + 1);  // @106_431880
  SEH_LEAVE();  // @107_431880
  return eax;  // @108_431880
}
PCREG(431880, lifted_431880);

extern "C" u32 THISCALL lifted_432270(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6686a6);  // @h_432270
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @0_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @1_432270
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_432270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6791032), (u32)(1089));  // @4_432270
  ecx = edx = 0;  // @5_432270
  esi = eax;  // @6_432270
  ecx = ebx;  // @7_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @9_432270
  ecx = edx = 0;  // @10_432270
  p0_ = eax;  // @11_432270
  p1_ = esi;  // @12_432270
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p1_), (u32)(6791656), (u32)(p0_));  // @13_432270
  ecx = edx = 0;  // @14_432270
  ecx = (u32)(EBP - 272);  // @15_432270
  p2_ = ebx;  // @16_432270
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p2_));  // @17_432270
  ecx = edx = 0;  // @18_432270
  ecx = (u32)(EBP - 272);  // @19_432270
  reg.state = (s32)((u32)(0));  // @20_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_432270
  ecx = edx = 0;  // @22_432270
  esi = eax;  // @23_432270
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(0)) goto L432405;  // @24_432270
  L432300:;
  edi = 0;  // @26_432270
  ebx = esi;  // @27_432270
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(59)) goto L43234b;  // @28_432270
  L432310:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @30_432270
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L432328;  // @31_432270
  if ((eax & 0xff) != (u32)(61)) goto L432320;  // @32_432270
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @33_432270
  edi = (u32)(esi + 1);  // @34_432270
  L432320:;
  esi = (esi + 1);  // @36_432270
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(59)) goto L432310;  // @37_432270
  goto L43234b;  // @38_432270
  L432328:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @40_432270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6791032), (u32)(1096));  // @42_432270
  ecx = edx = 0;  // @43_432270
  p3_ = eax;  // @44_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_432270
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6791696));  // @46_432270
  ecx = edx = 0;  // @47_432270
  L43234b:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @49_432270
  esi = (esi + 1);  // @50_432270
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(1131574387)) goto L4323fc;  // @51_432270
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @52_432270
  if ((eax & 0xff) != (u32)(67)) goto L4323dd;  // @53_432270
  if ((edi & edi) == 0) goto L4323dd;  // @54_432270
  p4_ = edi;  // @55_432270
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))((u32)(p4_));  // @56_432270
  ecx = edx = 0;  // @57_432270
  ecx = (u32)(EBP - 144);  // @58_432270
  edi = eax;  // @59_432270
  ebx = (ebx + (u32)(5));  // @60_432270
  eax = ext_4cbeb0_thiscall1(ecx);  // @61_432270
  ecx = edx = 0;  // @62_432270
  p5_ = edi;  // @63_432270
  ecx = (u32)(EBP - 144);  // @64_432270
  reg.state = (s32)((u32)(1));  // @65_432270
  eax = ext_4cbf30_thiscall2(ecx, (u32)(p5_));  // @66_432270
  ecx = edx = 0;  // @67_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @68_432270
  ecx = (u32)(EBP - 144);  // @69_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @70_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @71_432270
  ecx = edx = 0;  // @72_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @73_432270
  p6_ = eax;  // @74_432270
  p7_ = ebx;  // @75_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 104)))(ecx, (u32)(p7_), (u32)(p6_));  // @76_432270
  ecx = edx = 0;  // @77_432270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_432270
  ecx = (u32)(EBP - 144);  // @79_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @80_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @81_432270
  ecx = edx = 0;  // @82_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @83_432270
  p8_ = eax;  // @84_432270
  p9_ = ebx;  // @85_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(p9_), (u32)(p8_));  // @86_432270
  ecx = edx = 0;  // @87_432270
  ecx = (u32)(EBP - 144);  // @88_432270
  reg.state = (s32)((u32)(0));  // @89_432270
  eax = ext_4cbec0_thiscall1(ecx);  // @90_432270
  ecx = edx = 0;  // @91_432270
  goto L4323fc;  // @92_432270
  L4323dd:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(1131574387)) goto L4323fc;  // @94_432270
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @95_432270
  if ((eax & 0xff) != (u32)(114)) goto L4323fc;  // @96_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @97_432270
  eax = (u32)(ebx + 5);  // @98_432270
  p10_ = eax;  // @99_432270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_432270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p10_));  // @101_432270
  ecx = edx = 0;  // @102_432270
  L4323fc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L432300;  // @104_432270
  L432405:;
  ecx = (u32)(EBP - 272);  // @106_432270
  eax = ext_4cbec0_thiscall1(ecx);  // @107_432270
  ecx = edx = 0;  // @108_432270
  SEH_LEAVE();  // @109_432270
  ext_633654(G(u32, 0x6f5630));  // @110_432270
  return eax;  // @111_432270
}
PCREG(432270, lifted_432270);

extern "C" u32 THISCALL lifted_42db40(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664f46);  // @h_42db40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_42db40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42db40
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(0)) goto L42dcfe;  // @2_42db40
  L42db80:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @4_42db40
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42db96;  // @5_42db40
  L42db86:;
  if ((eax & 0xff) == (u32)(13)) goto L42db8e;  // @7_42db40
  if ((eax & 0xff) != (u32)(10)) goto L42db96;  // @8_42db40
  L42db8e:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @10_42db40
  esi = (esi + 1);  // @11_42db40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42db86;  // @12_42db40
  L42db96:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @14_42db40
  ecx = 0;  // @15_42db40
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42dbc6;  // @16_42db40
  edx = (u32)(EBP - 528);  // @17_42db40
  edx = (edx - esi);  // @18_42db40
  L42dba6:;
  if ((eax & 0xff) == (u32)(13)) goto L42dbba;  // @20_42db40
  if ((eax & 0xff) == (u32)(10)) goto L42dbba;  // @21_42db40
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + esi), &v, sizeof v); }  // @22_42db40
  ecx = (ecx + 1);  // @23_42db40
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @24_42db40
  esi = (esi + 1);  // @25_42db40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42dba6;  // @26_42db40
  L42dbba:;
  if (ecx >= (u32)(512)) goto L42dd1e;  // @28_42db40
  L42dbc6:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + ecx - 528), &v, sizeof v); }  // @30_42db40
  ecx = (u32)(EBP - 528);  // @31_42db40
  edx = (u32)(ecx + 1);  // @32_42db40
  L42dbd7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @34_42db40
  ecx = (ecx + 1);  // @35_42db40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42dbd7;  // @36_42db40
  ecx = (ecx - edx);  // @37_42db40
  if ((s32)(ecx & ecx) <= 0) goto L42dc19;  // @38_42db40
  eax = (u32)(EBP + ecx - 529);  // @39_42db40
  ecx = (u32)(EBP - 528);  // @40_42db40
  if (eax == ecx) goto L42dc19;  // @41_42db40
  L42dbf5:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @43_42db40
  if ((ecx & 0xff) == (u32)(32)) goto L42dc0b;  // @44_42db40
  if ((ecx & 0xff) == (u32)(9)) goto L42dc0b;  // @45_42db40
  if ((ecx & 0xff) == (u32)(13)) goto L42dc0b;  // @46_42db40
  if ((ecx & 0xff) != (u32)(10)) goto L42dc19;  // @47_42db40
  L42dc0b:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @49_42db40
  ecx = (u32)(EBP - 528);  // @50_42db40
  eax = (eax - 1);  // @51_42db40
  if (eax != ecx) goto L42dbf5;  // @52_42db40
  L42dc19:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 528), sizeof v); (u32)v; }) == (u32)(47)) goto L42dcf5;  // @54_42db40
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 527), sizeof v); (u32)v; }) == (u32)(47)) goto L42dcf5;  // @55_42db40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_42db40
  ecx = (u32)(EBP - 1040);  // @57_42db40
  p0_ = ecx;  // @58_42db40
  ecx = (u32)(EBP - 1552);  // @59_42db40
  p1_ = ecx;  // @60_42db40
  ecx = (u32)(EBP - 528);  // @61_42db40
  p2_ = ecx;  // @62_42db40
  ecx = ebx;  // @63_42db40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @64_42db40
  ecx = edx = 0;  // @65_42db40
  eax = (u32)(EBP - 1552);  // @66_42db40
  p3_ = eax;  // @67_42db40
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))((u32)(p3_), (u32)(6790780));  // @68_42db40
  ecx = edx = 0;  // @69_42db40
  if ((eax & eax) != 0) goto L42dce0;  // @70_42db40
  eax = (u32)(EBP - 1040);  // @71_42db40
  p4_ = eax;  // @72_42db40
  ecx = (u32)(EBP - 1680);  // @73_42db40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p4_));  // @74_42db40
  ecx = edx = 0;  // @75_42db40
  eax = (u32)(EBP - 1680);  // @76_42db40
  reg.state = (s32)((u32)(0));  // @77_42db40
  p5_ = eax;  // @78_42db40
  ecx = (u32)(ebx + 6839);  // @79_42db40
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p5_));  // @80_42db40
  ecx = edx = 0;  // @81_42db40
  ecx = (u32)(EBP - 1680);  // @82_42db40
  reg.state = (s32)((u32)(4294967295));  // @83_42db40
  eax = ext_4cbec0_thiscall1(ecx);  // @84_42db40
  ecx = edx = 0;  // @85_42db40
  ecx = (u32)(EBP - 1808);  // @86_42db40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6777860));  // @87_42db40
  ecx = edx = 0;  // @88_42db40
  eax = (u32)(EBP - 1808);  // @89_42db40
  reg.state = (s32)((u32)(1));  // @90_42db40
  p6_ = eax;  // @91_42db40
  ecx = (u32)(ebx + 6839);  // @92_42db40
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p6_));  // @93_42db40
  ecx = edx = 0;  // @94_42db40
  ecx = (u32)(EBP - 1808);  // @95_42db40
  reg.state = (s32)((u32)(4294967295));  // @96_42db40
  eax = ext_4cbec0_thiscall1(ecx);  // @97_42db40
  ecx = edx = 0;  // @98_42db40
  L42dce0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @100_42db40
  ecx = (u32)(EBP - 1040);  // @101_42db40
  p7_ = ecx;  // @102_42db40
  ecx = (u32)(EBP - 1552);  // @103_42db40
  p8_ = ecx;  // @104_42db40
  ecx = ebx;  // @105_42db40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(p8_), (u32)(p7_));  // @106_42db40
  ecx = edx = 0;  // @107_42db40
  L42dcf5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L42db80;  // @109_42db40
  L42dcfe:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @111_42db40
  SEH_LEAVE();  // @112_42db40
  ext_633654(G(u32, 0x6f5630));  // @113_42db40
  return eax;  // @114_42db40
  L42dd1e:;
  eax = ext_634047_cdecl0();  // @116_42db40
  ecx = edx = 0;  // @117_42db40
}
PCREG(42db40, lifted_42db40);

extern "C" u32 THISCALL lifted_48c4b0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x667a8c);  // @h_48c4b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_48c4b0
  eax = (u32)(ecx + 3021);  // @1_48c4b0
  p0_ = eax;  // @2_48c4b0
  ecx = (u32)(EBP - 144);  // @3_48c4b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @4_48c4b0
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p0_));  // @5_48c4b0
  ecx = edx = 0;  // @6_48c4b0
  ecx = (u32)(EBP - 144);  // @7_48c4b0
  reg.state = (s32)((u32)(0));  // @8_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @9_48c4b0
  ecx = edx = 0;  // @10_48c4b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @11_48c4b0
  p1_ = eax;  // @12_48c4b0
  eax = ((u32(STDCALL *)(u32, u32))(ebx))((u32)(p1_), (u32)(92));  // @13_48c4b0
  ecx = edx = 0;  // @14_48c4b0
  edi = eax;  // @15_48c4b0
  if ((edi & edi) != 0) goto L48c530;  // @16_48c4b0
  ecx = (u32)(EBP - 144);  // @17_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @18_48c4b0
  ecx = edx = 0;  // @19_48c4b0
  edi = eax;  // @20_48c4b0
  L48c530:;
  ecx = (u32)(EBP - 144);  // @22_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @23_48c4b0
  ecx = edx = 0;  // @24_48c4b0
  edx = (u32)(eax + 1);  // @25_48c4b0
  L48c540:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @27_48c4b0
  eax = (eax + 1);  // @28_48c4b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L48c540;  // @29_48c4b0
  eax = (eax - edx);  // @30_48c4b0
  if (eax == 0) goto L48c590;  // @31_48c4b0
  p2_ = edi;  // @32_48c4b0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p2_), (u32)(46));  // @33_48c4b0
  ecx = edx = 0;  // @34_48c4b0
  if ((eax & eax) != 0) goto L48c590;  // @35_48c4b0
  ecx = (u32)(EBP - 272);  // @36_48c4b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6871072));  // @37_48c4b0
  ecx = edx = 0;  // @38_48c4b0
  eax = (u32)(EBP - 272);  // @39_48c4b0
  reg.state = (s32)((u32)(1));  // @40_48c4b0
  p3_ = eax;  // @41_48c4b0
  ecx = (u32)(EBP - 144);  // @42_48c4b0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p3_));  // @43_48c4b0
  ecx = edx = 0;  // @44_48c4b0
  ecx = (u32)(EBP - 272);  // @45_48c4b0
  reg.state = (s32)((u32)(0));  // @46_48c4b0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_48c4b0
  ecx = edx = 0;  // @48_48c4b0
  L48c590:;
  ecx = (u32)(EBP - 144);  // @50_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @51_48c4b0
  ecx = edx = 0;  // @52_48c4b0
  edx = (u32)(6871072);  // @53_48c4b0
  ecx = eax;  // @54_48c4b0
  eax = ext_4cc780_fastcall2(ecx, edx);  // @55_48c4b0
  ecx = edx = 0;  // @56_48c4b0
  if ((eax & eax) == 0) goto L48c660;  // @57_48c4b0
  ecx = (u32)(EBP - 144);  // @58_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @59_48c4b0
  ecx = edx = 0;  // @60_48c4b0
  edx = (u32)(6871080);  // @61_48c4b0
  ecx = eax;  // @62_48c4b0
  eax = ext_4cc780_fastcall2(ecx, edx);  // @63_48c4b0
  ecx = edx = 0;  // @64_48c4b0
  if ((eax & eax) == 0) goto L48c5db;  // @65_48c4b0
  L48c5ca:;
  ecx = esi;  // @67_48c4b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @68_48c4b0
  ecx = edx = 0;  // @69_48c4b0
  goto L48c695;  // @70_48c4b0
  L48c5db:;
  ecx = (u32)(EBP - 144);  // @72_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @73_48c4b0
  ecx = edx = 0;  // @74_48c4b0
  p4_ = eax;  // @75_48c4b0
  eax = ((u32(STDCALL *)(u32, u32))(ebx))((u32)(p4_), (u32)(92));  // @76_48c4b0
  ecx = edx = 0;  // @77_48c4b0
  edi = eax;  // @78_48c4b0
  if ((edi & edi) == 0) goto L48c5ca;  // @79_48c4b0
  eax = (u32)(edi + 1);  // @80_48c4b0
  p5_ = eax;  // @81_48c4b0
  ecx = (u32)(EBP - 400);  // @82_48c4b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p5_));  // @83_48c4b0
  ecx = edx = 0;  // @84_48c4b0
  ecx = (u32)(EBP - 272);  // @85_48c4b0
  reg.state = (s32)((u32)(2));  // @86_48c4b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @87_48c4b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6870184));  // @88_48c4b0
  ecx = edx = 0;  // @89_48c4b0
  eax = (u32)(EBP - 272);  // @90_48c4b0
  reg.state = (s32)((u32)(3));  // @91_48c4b0
  p6_ = eax;  // @92_48c4b0
  ecx = (u32)(EBP - 144);  // @93_48c4b0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p6_));  // @94_48c4b0
  ecx = edx = 0;  // @95_48c4b0
  ecx = (u32)(EBP - 272);  // @96_48c4b0
  reg.state = (s32)((u32)(2));  // @97_48c4b0
  eax = ext_4cbec0_thiscall1(ecx);  // @98_48c4b0
  ecx = edx = 0;  // @99_48c4b0
  eax = (u32)(EBP - 400);  // @100_48c4b0
  p7_ = eax;  // @101_48c4b0
  ecx = (u32)(EBP - 144);  // @102_48c4b0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p7_));  // @103_48c4b0
  ecx = edx = 0;  // @104_48c4b0
  ecx = (u32)(EBP - 400);  // @105_48c4b0
  reg.state = (s32)((u32)(0));  // @106_48c4b0
  eax = ext_4cbec0_thiscall1(ecx);  // @107_48c4b0
  ecx = edx = 0;  // @108_48c4b0
  L48c660:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @110_48c4b0
  if ((edi & edi) == 0) goto L48c687;  // @111_48c4b0
  ecx = (u32)(EBP - 144);  // @112_48c4b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @113_48c4b0
  ecx = edx = 0;  // @114_48c4b0
  p8_ = eax;  // @115_48c4b0
  eax = ((u32(STDCALL *)(u32, u32))(ebx))((u32)(p8_), (u32)(46));  // @116_48c4b0
  ecx = edx = 0;  // @117_48c4b0
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @118_48c4b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @119_48c4b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; })) & 0xff);  // @120_48c4b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 3), &v, sizeof v); }  // @121_48c4b0
  L48c687:;
  eax = (u32)(EBP - 144);  // @123_48c4b0
  ecx = esi;  // @124_48c4b0
  p9_ = eax;  // @125_48c4b0
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p9_));  // @126_48c4b0
  ecx = edx = 0;  // @127_48c4b0
  L48c695:;
  ecx = (u32)(EBP - 144);  // @129_48c4b0
  eax = ext_4cbec0_thiscall1(ecx);  // @130_48c4b0
  ecx = edx = 0;  // @131_48c4b0
  eax = esi;  // @132_48c4b0
  SEH_LEAVE();  // @133_48c4b0
  ext_633654(G(u32, 0x6f5630));  // @134_48c4b0
  return eax;  // @135_48c4b0
}
PCREG(48c4b0, lifted_48c4b0);

extern "C" u32 THISCALL lifted_4d5150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6694c8);  // @h_4d5150
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4d5150
  eax = ext_41e290_cdecl1((u32)(4));  // @1_4d5150
  ecx = edx = 0;  // @2_4d5150
  edi = eax;  // @3_4d5150
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6763b0))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @4_4d5150
  ecx = edx = 0;  // @5_4d5150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @6_4d5150
  if ((eax & eax) != 0) goto L4d51a2;  // @7_4d5150
  p0_ = edi;  // @8_4d5150
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(4));  // @9_4d5150
  ecx = edx = 0;  // @10_4d5150
  edi = 0;  // @11_4d5150
  L4d51a2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_4d5150
  if ((esi & esi) == 0) goto L4d52e4;  // @14_4d5150
  p1_ = esi;  // @15_4d5150
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6763e8))((u32)(p1_), (u32)(0), (u32)(2));  // @16_4d5150
  ecx = edx = 0;  // @17_4d5150
  p2_ = esi;  // @18_4d5150
  reg.state = (s32)((u32)(0));  // @19_4d5150
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p2_));  // @20_4d5150
  ecx = edx = 0;  // @21_4d5150
  if ((eax & eax) == 0) goto L4d51da;  // @22_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @23_4d5150
  if ((eax & eax) == 0) goto L4d51d9;  // @24_4d5150
  eax = ((u32(STDCALL *)(void))(eax))();  // @25_4d5150
  ecx = edx = 0;  // @26_4d5150
  goto L4d51da;  // @27_4d5150
  L4d51d9:;
  __builtin_trap();  // @29_4d5150
  L4d51da:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @31_4d5150
  p3_ = esi;  // @32_4d5150
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763f4))((u32)(p3_));  // @33_4d5150
  ecx = edx = 0;  // @34_4d5150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @35_4d5150
  p4_ = esi;  // @36_4d5150
  reg.state = (s32)((u32)(1));  // @37_4d5150
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p4_));  // @38_4d5150
  ecx = edx = 0;  // @39_4d5150
  if ((eax & eax) == 0) goto L4d520a;  // @40_4d5150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @41_4d5150
  if ((ecx & ecx) == 0) goto L4d5209;  // @42_4d5150
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @43_4d5150
  ecx = edx = 0;  // @44_4d5150
  goto L4d520a;  // @45_4d5150
  L4d5209:;
  __builtin_trap();  // @47_4d5150
  L4d520a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @49_4d5150
  p5_ = esi;  // @50_4d5150
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6763e8))((u32)(p5_), (u32)(0), (u32)(0));  // @51_4d5150
  ecx = edx = 0;  // @52_4d5150
  p6_ = esi;  // @53_4d5150
  reg.state = (s32)((u32)(2));  // @54_4d5150
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p6_));  // @55_4d5150
  ecx = edx = 0;  // @56_4d5150
  if ((eax & eax) == 0) goto L4d523a;  // @57_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @58_4d5150
  if ((eax & eax) == 0) goto L4d5239;  // @59_4d5150
  eax = ((u32(STDCALL *)(void))(eax))();  // @60_4d5150
  ecx = edx = 0;  // @61_4d5150
  goto L4d523a;  // @62_4d5150
  L4d5239:;
  __builtin_trap();  // @64_4d5150
  L4d523a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @66_4d5150
  reg.state = (s32)((u32)(4294967295));  // @67_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_4d5150
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, (u32)(-1));  // @69_4d5150
  ecx = edx = 0;  // @70_4d5150
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @71_4d5150
  p7_ = esi;  // @72_4d5150
  eax = ext_41e290_cdecl1((u32)(p7_));  // @73_4d5150
  ecx = edx = 0;  // @74_4d5150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @75_4d5150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @76_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_4d5150
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, (u32)(0));  // @78_4d5150
  ecx = edx = 0;  // @79_4d5150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @80_4d5150
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @81_4d5150
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @82_4d5150
  p8_ = esi;  // @83_4d5150
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }), (u32)(1), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; }), (u32)(p8_));  // @84_4d5150
  ecx = edx = 0;  // @85_4d5150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @86_4d5150
  p9_ = esi;  // @87_4d5150
  reg.state = (s32)((u32)(3));  // @88_4d5150
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763d8))((u32)(p9_));  // @89_4d5150
  ecx = edx = 0;  // @90_4d5150
  if ((eax & eax) == 0) goto L4d52b2;  // @91_4d5150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @92_4d5150
  if ((ecx & ecx) == 0) goto L4d52b1;  // @93_4d5150
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @94_4d5150
  ecx = edx = 0;  // @95_4d5150
  goto L4d52b2;  // @96_4d5150
  L4d52b1:;
  __builtin_trap();  // @98_4d5150
  L4d52b2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @100_4d5150
  reg.state = (s32)((u32)(4294967295));  // @101_4d5150
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; })) goto L4d52cf;  // @102_4d5150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @103_4d5150
  if ((eax & eax) == 0) goto L4d52ce;  // @104_4d5150
  eax = ((u32(STDCALL *)(void))(eax))();  // @105_4d5150
  ecx = edx = 0;  // @106_4d5150
  goto L4d52cf;  // @107_4d5150
  L4d52ce:;
  __builtin_trap();  // @109_4d5150
  L4d52cf:;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763ac))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @111_4d5150
  ecx = edx = 0;  // @112_4d5150
  p10_ = edi;  // @113_4d5150
  eax = ext_634273_cdecl2((u32)(p10_), (u32)(4));  // @114_4d5150
  ecx = edx = 0;  // @115_4d5150
  goto L4d52f2;  // @116_4d5150
  L4d52e4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @118_4d5150
  if ((eax & eax) == 0) goto L4d52f1;  // @119_4d5150
  eax = ((u32(STDCALL *)(void))(eax))();  // @120_4d5150
  ecx = edx = 0;  // @121_4d5150
  goto L4d52f2;  // @122_4d5150
  L4d52f1:;
  __builtin_trap();  // @124_4d5150
  L4d52f2:;
  eax = (u32)(ebx + 4);  // @126_4d5150
  SEH_LEAVE();  // @127_4d5150
  return eax;  // @128_4d5150
}
PCREG(4d5150, lifted_4d5150);

extern "C" u32 THISCALL lifted_426d60(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66466b);  // @h_426d60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 728), &v, sizeof v); }  // @0_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_426d60
  ecx = (u32)(EBP - 724);  // @2_426d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_426d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 732), &v, sizeof v); }  // @4_426d60
  eax = ext_421080_thiscall1(ecx);  // @5_426d60
  ecx = edx = 0;  // @6_426d60
  ecx = eax;  // @7_426d60
  reg.state = (s32)((u32)(0));  // @8_426d60
  eax = ext_4cc1d0_thiscall1(ecx);  // @9_426d60
  ecx = edx = 0;  // @10_426d60
  edx = (u32)(EBP - 276);  // @11_426d60
  edx = (edx - eax);  // @12_426d60
  L426dc1:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @14_426d60
  eax = (u32)(eax + 1);  // @15_426d60
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @16_426d60
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L426dc1;  // @17_426d60
  ecx = (u32)(EBP - 724);  // @18_426d60
  reg.state = (s32)((u32)(4294967295));  // @19_426d60
  eax = ext_4cbec0_thiscall1(ecx);  // @20_426d60
  ecx = edx = 0;  // @21_426d60
  esi = ebx;  // @22_426d60
  L426de2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) & 0xff);  // @24_426d60
  ebx = (ebx + 1);  // @25_426d60
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L426de2;  // @26_426d60
  edi = (u32)(EBP - 276);  // @27_426d60
  ebx = (ebx - esi);  // @28_426d60
  edi = (edi - 1);  // @29_426d60
  L426df2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @31_426d60
  edi = (edi + 1);  // @32_426d60
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L426df2;  // @33_426d60
  ecx = ebx;  // @34_426d60
  ecx = (ecx >> (u32)(2));  // @35_426d60
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @36_426d60
  ecx = ebx;  // @37_426d60
  ecx = (ecx & (u32)(3));  // @38_426d60
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 1); esi += 1; edi += 1; ecx--; }  // @39_426d60
  edi = (u32)(EBP - 276);  // @40_426d60
  edi = (edi - 1);  // @41_426d60
  L426e10:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @43_426d60
  edi = (u32)(edi + 1);  // @44_426d60
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L426e10;  // @45_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @46_426d60
  edx = (u32)(EBP - 276);  // @47_426d60
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @48_426d60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @49_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_426d60
  p0_ = edx;  // @51_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @52_426d60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p0_), (u32)(0));  // @53_426d60
  ecx = edx = 0;  // @54_426d60
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L426e4f;  // @55_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 728), sizeof v); (u32)v; });  // @56_426d60
  edx = (u32)(EBP - 276);  // @57_426d60
  p1_ = edx;  // @58_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_426d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @60_426d60
  ecx = edx = 0;  // @61_426d60
  L426e4f:;
  edi = (u32)(EBP - 276);  // @63_426d60
  edi = (edi - 1);  // @64_426d60
  L426e56:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @66_426d60
  edi = (u32)(edi + 1);  // @67_426d60
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L426e56;  // @68_426d60
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6786308), sizeof v); (u32)v; })) & 0xffff);  // @69_426d60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @70_426d60
  eax = (u32)(EBP - 596);  // @71_426d60
  p2_ = eax;  // @72_426d60
  eax = (u32)(EBP - 276);  // @73_426d60
  p3_ = eax;  // @74_426d60
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67610c))((u32)(p3_), (u32)(p2_));  // @75_426d60
  ecx = edx = 0;  // @76_426d60
  esi = eax;  // @77_426d60
  if (esi == (u32)(-1)) goto L426f32;  // @78_426d60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775056), sizeof v); (u32)v; });  // @79_426d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @80_426d60
  L426e94:;
  eax = (u32)(EBP - 552);  // @82_426d60
  p4_ = eax;  // @83_426d60
  eax = ((u32( *)(u32, u32))(ebx))((u32)(p4_), (u32)(46));  // @84_426d60
  ecx = edx = 0;  // @85_426d60
  if ((eax & eax) == 0) goto L426edd;  // @86_426d60
  ecx = (u32)(6786312);  // @87_426d60
  L426eb0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @89_426d60
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L426ed0;  // @90_426d60
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L426ecc;  // @91_426d60
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @92_426d60
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L426ed0;  // @93_426d60
  eax = (eax + (u32)(2));  // @94_426d60
  ecx = (ecx + (u32)(2));  // @95_426d60
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L426eb0;  // @96_426d60
  L426ecc:;
  eax = 0;  // @98_426d60
  goto L426ed5;  // @99_426d60
  L426ed0:;
  eax = 0;  // @101_426d60
  eax = (eax | (u32)(1));  // @102_426d60
  L426ed5:;
  if ((eax & eax) != 0) goto L426edd;  // @104_426d60
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @105_426d60
  goto L426edf;  // @106_426d60
  L426edd:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @108_426d60
  L426edf:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 552), sizeof v); (u32)v; }) != (u32)(46)) goto L426f00;  // @110_426d60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 551), sizeof v); (u32)v; })) & 0xff);  // @111_426d60
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L426f19;  // @112_426d60
  if ((ecx & 0xff) != (u32)(46)) goto L426f00;  // @113_426d60
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 550), sizeof v); (u32)v; }) == (u32)(0)) goto L426f19;  // @114_426d60
  L426f00:;
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L426f19;  // @116_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 732), sizeof v); (u32)v; });  // @117_426d60
  edx = (u32)(EBP - 552);  // @118_426d60
  p5_ = edx;  // @119_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_426d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(p5_));  // @121_426d60
  ecx = edx = 0;  // @122_426d60
  L426f19:;
  eax = (u32)(EBP - 596);  // @124_426d60
  p6_ = eax;  // @125_426d60
  p7_ = esi;  // @126_426d60
  eax = ((u32(STDCALL *)(u32, u32))(edi))((u32)(p7_), (u32)(p6_));  // @127_426d60
  ecx = edx = 0;  // @128_426d60
  if ((eax & eax) != 0) goto L426e94;  // @129_426d60
  p8_ = esi;  // @130_426d60
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676108))((u32)(p8_));  // @131_426d60
  ecx = edx = 0;  // @132_426d60
  L426f32:;
  SEH_LEAVE();  // @134_426d60
  ext_633654(G(u32, 0x6f5630));  // @135_426d60
  return eax;  // @136_426d60
}
PCREG(426d60, lifted_426d60);

extern "C" u32 THISCALL lifted_6515d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66ecee);  // @h_6515d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_6515d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6515d0
  eax = ext_657da0_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @2_6515d0
  ecx = edx = 0;  // @3_6515d0
  { u32 v = (u32)((u32)(7091948)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @4_6515d0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4757), &v, sizeof v); }  // @5_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 311), &v, sizeof v); }  // @6_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_6515d0
  reg.state = (s32)((u32)(0));  // @8_6515d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; }) == (u32)(0)) goto L65163d;  // @9_6515d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 99), sizeof v); (u32)v; }) != (u32)(0)) goto L6516e8;  // @10_6515d0
  L65163d:;
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x676240))();  // @12_6515d0
  ecx = edx = 0;  // @13_6515d0
  p0_ = eax;  // @14_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @15_6515d0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6761f8))((u32)(p0_));  // @16_6515d0
  ecx = edx = 0;  // @17_6515d0
  ebx = eax;  // @18_6515d0
  p1_ = ebx;  // @19_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676038))((u32)(p1_), (u32)(14));  // @20_6515d0
  ecx = edx = 0;  // @21_6515d0
  p2_ = ebx;  // @22_6515d0
  edi = eax;  // @23_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676038))((u32)(p2_), (u32)(12));  // @24_6515d0
  ecx = edx = 0;  // @25_6515d0
  p3_ = ebx;  // @26_6515d0
  edi = (u32)((s32)edi * (s32)eax);  // @27_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67620c))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p3_));  // @28_6515d0
  ecx = edx = 0;  // @29_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_6515d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 127), &v, sizeof v); }  // @31_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_6515d0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; }) >= (s32)(u32)(16)) goto L6516a1;  // @33_6515d0
  eax = (u32)(EBP - 24);  // @34_6515d0
  { u32 v = (u32)((u32)(7092880)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @35_6515d0
  p4_ = eax;  // @36_6515d0
  { u32 v = (u32)((u32)(7092792)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @37_6515d0
  eax = ext_634d34_cdecl2((u32)(p4_), (u32)(7197212));  // @38_6515d0
  ecx = edx = 0;  // @39_6515d0
  L6516a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @41_6515d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 118), sizeof v); (u32)v; }) == (u32)(0)) goto L6516df;  // @42_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @43_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_6515d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7092888), (u32)(455));  // @45_6515d0
  ecx = edx = 0;  // @46_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_6515d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_6515d0
  p5_ = eax;  // @49_6515d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(p5_), (u32)(7092940), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; }));  // @50_6515d0
  ecx = edx = 0;  // @51_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_6515d0
  L6516df:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @54_6515d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 99), sizeof v); (u32)v; }) == (u32)(0)) goto L651701;  // @55_6515d0
  L6516e8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 135), &v, sizeof v); }  // @57_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 139), &v, sizeof v); }  // @59_6515d0
  L651701:;
  { u32 v = (u32)((u32)(40000)); __builtin_memcpy((void *)(u32)(ebx + 4745), &v, sizeof v); }  // @61_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4585), &v, sizeof v); }  // @62_6515d0
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx + 4583), &v, sizeof v); }  // @63_6515d0
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x676234))();  // @64_6515d0
  ecx = edx = 0;  // @65_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 303), sizeof v); (u32)v; });  // @66_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4593), &v, sizeof v); }  // @67_6515d0
  eax = ext_6528a0_thiscall1(ecx);  // @68_6515d0
  ecx = edx = 0;  // @69_6515d0
  eax = (u32)(ebx + 4613);  // @70_6515d0
  p6_ = eax;  // @71_6515d0
  eax = ext_634d10_cdecl3((u32)(p6_), (u32)(0), (u32)(128));  // @72_6515d0
  ecx = edx = 0;  // @73_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4741), &v, sizeof v); }  // @74_6515d0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ebx + 4749), &v, sizeof v); }  // @75_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @76_6515d0
  ecx = edx = 0;  // @77_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @78_6515d0
  reg.state = (s32)((u32)(1));  // @79_6515d0
  if ((eax & eax) == 0) goto L65178b;  // @80_6515d0
  ecx = eax;  // @81_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092956), (u32)(0), (u32)(7493664));  // @82_6515d0
  ecx = edx = 0;  // @83_6515d0
  edx = eax;  // @84_6515d0
  goto L65178d;  // @85_6515d0
  L65178b:;
  edx = 0;  // @87_6515d0
  L65178d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4759), &v, sizeof v); }  // @89_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_6515d0
  p7_ = edx;  // @91_6515d0
  reg.state = (s32)((u32)(0));  // @92_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p7_));  // @94_6515d0
  ecx = edx = 0;  // @95_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @96_6515d0
  ecx = edx = 0;  // @97_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @98_6515d0
  reg.state = (s32)((u32)(2));  // @99_6515d0
  if ((eax & eax) == 0) goto L6517d5;  // @100_6515d0
  ecx = eax;  // @101_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092980), (u32)(0), (u32)(7298720));  // @102_6515d0
  ecx = edx = 0;  // @103_6515d0
  edx = eax;  // @104_6515d0
  goto L6517d7;  // @105_6515d0
  L6517d5:;
  edx = 0;  // @107_6515d0
  L6517d7:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4763), &v, sizeof v); }  // @109_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_6515d0
  p8_ = edx;  // @111_6515d0
  reg.state = (s32)((u32)(0));  // @112_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p8_));  // @114_6515d0
  ecx = edx = 0;  // @115_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @116_6515d0
  ecx = edx = 0;  // @117_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @118_6515d0
  reg.state = (s32)((u32)(3));  // @119_6515d0
  if ((eax & eax) == 0) goto L65181f;  // @120_6515d0
  ecx = eax;  // @121_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092992), (u32)(0), (u32)(7298724));  // @122_6515d0
  ecx = edx = 0;  // @123_6515d0
  edx = eax;  // @124_6515d0
  goto L651821;  // @125_6515d0
  L65181f:;
  edx = 0;  // @127_6515d0
  L651821:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4767), &v, sizeof v); }  // @129_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @130_6515d0
  p9_ = edx;  // @131_6515d0
  reg.state = (s32)((u32)(0));  // @132_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p9_));  // @134_6515d0
  ecx = edx = 0;  // @135_6515d0
  eax = ebx;  // @136_6515d0
  SEH_LEAVE();  // @137_6515d0
  return eax;  // @138_6515d0
}
PCREG(6515d0, lifted_6515d0);

extern "C" u32 THISCALL lifted_434010(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6656fa);  // @h_434010
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_434010
  ecx = (u32)(EBP - 272);  // @2_434010
  p0_ = eax;  // @3_434010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @4_434010
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @5_434010
  ecx = edx = 0;  // @6_434010
  ecx = (u32)(EBP - 272);  // @7_434010
  reg.state = (s32)((u32)(0));  // @8_434010
  eax = ext_4cc5f0_thiscall1(ecx);  // @9_434010
  ecx = edx = 0;  // @10_434010
  ebx = eax;  // @11_434010
  esi = 0;  // @12_434010
  if ((ebx & ebx) == 0) goto L434095;  // @13_434010
  L434070:;
  ecx = (u32)(EBP - 272);  // @15_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_434010
  ecx = edx = 0;  // @17_434010
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L434090;  // @18_434010
  ecx = (u32)(EBP - 272);  // @19_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @20_434010
  ecx = edx = 0;  // @21_434010
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @22_434010
  L434090:;
  esi = (esi + 1);  // @24_434010
  if (esi != ebx) goto L434070;  // @25_434010
  L434095:;
  eax = (u32)(EBP - 272);  // @27_434010
  p1_ = eax;  // @28_434010
  ecx = (u32)(EBP - 144);  // @29_434010
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p1_));  // @30_434010
  ecx = edx = 0;  // @31_434010
  ecx = (u32)(EBP - 144);  // @32_434010
  reg.state = (s32)((u32)(1));  // @33_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @34_434010
  ecx = edx = 0;  // @35_434010
  p2_ = eax;  // @36_434010
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))((u32)(p2_), (u32)(46));  // @37_434010
  ecx = edx = 0;  // @38_434010
  if ((eax & eax) == 0) goto L434214;  // @39_434010
  { u32 v = (u32)((u32)(1346984494)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @40_434010
  ecx = (u32)(EBP - 144);  // @41_434010
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @43_434010
  ecx = edx = 0;  // @44_434010
  p3_ = eax;  // @45_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 160), sizeof v); (u32)v; });  // @46_434010
  ecx = edi;  // @47_434010
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p3_));  // @48_434010
  ecx = edx = 0;  // @49_434010
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L434214;  // @50_434010
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_434010
  ecx = (u32)(EBP - 144);  // @52_434010
  eax = ext_4cc1d0_cdecl1((u32)(1));  // @53_434010
  ecx = edx = 0;  // @54_434010
  p4_ = eax;  // @55_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @56_434010
  ecx = edi;  // @57_434010
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p4_));  // @58_434010
  ecx = edx = 0;  // @59_434010
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4341eb;  // @60_434010
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L434143;  // @61_434010
  eax = ext_41e290_cdecl1((u32)(40));  // @62_434010
  ecx = edx = 0;  // @63_434010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @64_434010
  reg.state = (s32)((u32)(2));  // @65_434010
  if ((eax & eax) == 0) goto L43413a;  // @66_434010
  ecx = eax;  // @67_434010
  eax = ext_4cca60_thiscall3(ecx, (u32)(4), (u32)(1));  // @68_434010
  ecx = edx = 0;  // @69_434010
  goto L43413c;  // @70_434010
  L43413a:;
  eax = 0;  // @72_434010
  L43413c:;
  reg.state = (s32)((u32)(1));  // @74_434010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @75_434010
  L434143:;
  eax = ext_41e290_cdecl1((u32)(111));  // @77_434010
  ecx = edx = 0;  // @78_434010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @79_434010
  reg.state = (s32)((u32)(3));  // @80_434010
  if ((eax & eax) == 0) goto L434166;  // @81_434010
  ecx = eax;  // @82_434010
  eax = ext_4d5440_thiscall1(ecx);  // @83_434010
  ecx = edx = 0;  // @84_434010
  ebx = eax;  // @85_434010
  goto L434168;  // @86_434010
  L434166:;
  ebx = 0;  // @88_434010
  L434168:;
  ecx = (u32)(5);  // @90_434010
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @91_434010
  eax = (u32)(2);  // @92_434010
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) eax = ecx;  // @93_434010
  reg.state = (s32)((u32)(1));  // @94_434010
  p5_ = eax;  // @95_434010
  ecx = (u32)(EBP - 144);  // @96_434010
  eax = ext_4cc1d0_cdecl1((u32)(p5_));  // @97_434010
  ecx = edx = 0;  // @98_434010
  p6_ = eax;  // @99_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @100_434010
  ecx = ebx;  // @101_434010
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p6_));  // @102_434010
  ecx = edx = 0;  // @103_434010
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4341eb;  // @104_434010
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @105_434010
  if ((ecx & ecx) == 0) goto L4341db;  // @106_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_434010
  edx = (u32)(EBP - 292);  // @108_434010
  p7_ = edx;  // @109_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p7_));  // @110_434010
  ecx = edx = 0;  // @111_434010
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @112_434010
  edx = (u32)(EBP - 292);  // @113_434010
  p8_ = edx;  // @114_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p8_));  // @116_434010
  ecx = edx = 0;  // @117_434010
  if ((eax & eax) == 0) goto L4341db;  // @118_434010
  L4341c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @120_434010
  p9_ = ebx;  // @121_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(p9_));  // @123_434010
  ecx = edx = 0;  // @124_434010
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @125_434010
  edx = (u32)(EBP - 292);  // @126_434010
  p10_ = edx;  // @127_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @128_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p10_));  // @129_434010
  ecx = edx = 0;  // @130_434010
  if ((eax & eax) != 0) goto L4341c0;  // @131_434010
  L4341db:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @133_434010
  p11_ = ebx;  // @134_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p11_));  // @136_434010
  ecx = edx = 0;  // @137_434010
  esi = eax;  // @138_434010
  goto L434216;  // @139_434010
  L4341eb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @141_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @142_434010
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6792428), (u32)(445));  // @143_434010
  ecx = edx = 0;  // @144_434010
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @145_434010
  p12_ = eax;  // @146_434010
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p12_), (u32)(6792552), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @147_434010
  ecx = edx = 0;  // @148_434010
  L434214:;
  esi = 0;  // @150_434010
  L434216:;
  ecx = (u32)(EBP - 144);  // @152_434010
  eax = ext_4cbec0_thiscall1(ecx);  // @153_434010
  ecx = edx = 0;  // @154_434010
  ecx = (u32)(EBP - 272);  // @155_434010
  eax = ext_4cbec0_thiscall1(ecx);  // @156_434010
  ecx = edx = 0;  // @157_434010
  eax = esi;  // @158_434010
  SEH_LEAVE();  // @159_434010
  ext_633654(G(u32, 0x6f5630));  // @160_434010
  return eax;  // @161_434010
}
PCREG(434010, lifted_434010);

extern "C" u32 THISCALL lifted_434800(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665786);  // @h_434800
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_434800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1176), &v, sizeof v); }  // @3_434800
  ecx = (u32)(EBP - 1168);  // @4_434800
  p0_ = eax;  // @5_434800
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @6_434800
  ecx = edx = 0;  // @7_434800
  ecx = (u32)(EBP - 1168);  // @8_434800
  reg.state = (s32)((u32)(0));  // @9_434800
  eax = ext_4cc5f0_thiscall1(ecx);  // @10_434800
  ecx = edx = 0;  // @11_434800
  edi = eax;  // @12_434800
  esi = 0;  // @13_434800
  if ((edi & edi) == 0) goto L434887;  // @14_434800
  L434862:;
  ecx = (u32)(EBP - 1168);  // @16_434800
  eax = ext_4cc1d0_thiscall1(ecx);  // @17_434800
  ecx = edx = 0;  // @18_434800
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L434882;  // @19_434800
  ecx = (u32)(EBP - 1168);  // @20_434800
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_434800
  ecx = edx = 0;  // @22_434800
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @23_434800
  L434882:;
  esi = (esi + 1);  // @25_434800
  if (esi != edi) goto L434862;  // @26_434800
  L434887:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @28_434800
  if ((ecx & ecx) == 0) goto L434a51;  // @29_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_434800
  edx = (u32)(EBP - 1216);  // @31_434800
  p1_ = edx;  // @32_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @33_434800
  ecx = edx = 0;  // @34_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @35_434800
  edx = (u32)(EBP - 1216);  // @36_434800
  p2_ = edx;  // @37_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @39_434800
  ecx = edx = 0;  // @40_434800
  if ((eax & eax) == 0) goto L434a51;  // @41_434800
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @42_434800
  L4348c0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @44_434800
  ecx = (u32)(EBP - 1168);  // @45_434800
  eax = ext_4cc1d0_thiscall1(ecx);  // @46_434800
  ecx = edx = 0;  // @47_434800
  p3_ = eax;  // @48_434800
  eax = ((u32( *)(u32, u32))(edi))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; }), (u32)(p3_));  // @49_434800
  ecx = edx = 0;  // @50_434800
  if ((eax & eax) == 0) goto L4348f2;  // @51_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @52_434800
  edx = (u32)(EBP - 1216);  // @53_434800
  p4_ = edx;  // @54_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @56_434800
  ecx = edx = 0;  // @57_434800
  if ((eax & eax) != 0) goto L4348c0;  // @58_434800
  goto L434a51;  // @59_434800
  L4348f2:;
  ecx = (u32)(EBP - 1204);  // @61_434800
  eax = ext_4ccd10_thiscall3(ecx, (u32)(256), (u32)(0));  // @62_434800
  ecx = edx = 0;  // @63_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_434800
  ecx = (u32)(EBP - 1204);  // @65_434800
  p5_ = ecx;  // @66_434800
  ecx = esi;  // @67_434800
  reg.state = (s32)((u32)(1));  // @68_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(p5_));  // @69_434800
  ecx = edx = 0;  // @70_434800
  eax = (u32)(EBP - 1228);  // @71_434800
  p6_ = eax;  // @72_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1204), sizeof v); (u32)v; });  // @73_434800
  ecx = (u32)(EBP - 1204);  // @74_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p6_));  // @75_434800
  ecx = edx = 0;  // @76_434800
  eax = (u32)(EBP - 1228);  // @77_434800
  p7_ = eax;  // @78_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1204), sizeof v); (u32)v; });  // @79_434800
  ecx = (u32)(EBP - 1204);  // @80_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p7_));  // @81_434800
  ecx = edx = 0;  // @82_434800
  ecx = eax;  // @83_434800
  if ((ecx & ecx) == 0) goto L434a46;  // @84_434800
  L434950:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6792424), sizeof v); (u32)v; })) & 0xffff);  // @86_434800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1176), sizeof v); (u32)v; });  // @87_434800
  esi = edx;  // @88_434800
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 1040), &v, sizeof v); }  // @89_434800
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6792426), sizeof v); (u32)v; })) & 0xff);  // @90_434800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1038), &v, sizeof v); }  // @91_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_434800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1172), &v, sizeof v); }  // @93_434800
  if ((edx & edx) == 0) goto L4349db;  // @94_434800
  L434980:;
  p8_ = esi;  // @96_434800
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676254))((u32)(p8_), (u32)(44));  // @97_434800
  ecx = edx = 0;  // @98_434800
  ebx = eax;  // @99_434800
  if ((ebx & ebx) == 0) goto L4349f5;  // @100_434800
  edi = ebx;  // @101_434800
  eax = (u32)(EBP - 1038);  // @102_434800
  edi = (edi - esi);  // @103_434800
  p9_ = edi;  // @104_434800
  p10_ = esi;  // @105_434800
  p11_ = eax;  // @106_434800
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67642c))((u32)(p11_), (u32)(p10_), (u32)(p9_));  // @107_434800
  ecx = edx = 0;  // @108_434800
  edi = (edi + (u32)(2));  // @109_434800
  if (edi >= (u32)(1024)) goto L434a7c;  // @110_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1172), sizeof v); (u32)v; });  // @111_434800
  edx = (u32)(EBP - 1040);  // @112_434800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + edi - 1040), &v, sizeof v); }  // @113_434800
  esi = (u32)(ebx + 1);  // @114_434800
  eax = ext_4cc850_fastcall2(ecx, edx);  // @115_434800
  ecx = edx = 0;  // @116_434800
  if ((eax & eax) == 0) goto L434a22;  // @117_434800
  if ((esi & esi) != 0) goto L434980;  // @118_434800
  L4349db:;
  ecx = (u32)(EBP - 1204);  // @120_434800
  eax = ext_4cd0e0_thiscall1(ecx);  // @121_434800
  ecx = edx = 0;  // @122_434800
  ecx = (u32)(EBP - 1168);  // @123_434800
  eax = ext_4cbec0_thiscall1(ecx);  // @124_434800
  ecx = edx = 0;  // @125_434800
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @126_434800
  goto L434a5e;  // @127_434800
  L4349f5:;
  edi = (u32)(EBP - 1038);  // @129_434800
  edx = esi;  // @130_434800
  edi = (edi - esi);  // @131_434800
  L434a00:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @133_434800
  edx = (u32)(edx + 1);  // @134_434800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + edx - 1), &v, sizeof v); }  // @135_434800
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L434a00;  // @136_434800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1172), sizeof v); (u32)v; });  // @137_434800
  edx = (u32)(EBP - 1040);  // @138_434800
  eax = ext_4cc850_fastcall2(ecx, edx);  // @139_434800
  ecx = edx = 0;  // @140_434800
  if ((eax & eax) != 0) goto L4349db;  // @141_434800
  L434a22:;
  if ((esi & esi) == 0) goto L4349db;  // @143_434800
  eax = (u32)(EBP - 1228);  // @144_434800
  p12_ = eax;  // @145_434800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1204), sizeof v); (u32)v; });  // @146_434800
  ecx = (u32)(EBP - 1204);  // @147_434800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p12_));  // @148_434800
  ecx = edx = 0;  // @149_434800
  ecx = eax;  // @150_434800
  if ((ecx & ecx) != 0) goto L434950;  // @151_434800
  L434a46:;
  ecx = (u32)(EBP - 1204);  // @153_434800
  eax = ext_4cd0e0_thiscall1(ecx);  // @154_434800
  ecx = edx = 0;  // @155_434800
  L434a51:;
  ecx = (u32)(EBP - 1168);  // @157_434800
  eax = ext_4cbec0_thiscall1(ecx);  // @158_434800
  ecx = edx = 0;  // @159_434800
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @160_434800
  L434a5e:;
  SEH_LEAVE();  // @162_434800
  ext_633654(G(u32, 0x6f5630));  // @163_434800
  return eax;  // @164_434800
  L434a7c:;
  eax = ext_634047_cdecl0();  // @166_434800
  ecx = edx = 0;  // @167_434800
}
PCREG(434800, lifted_434800);

extern "C" u32 THISCALL lifted_439c20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665bbd);  // @h_439c20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_439c20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_439c20
  if ((esi & esi) == 0) goto L439e29;  // @2_439c20
  ecx = (u32)(EBP - 144);  // @3_439c20
  eax = ext_4cbeb0_thiscall1(ecx);  // @4_439c20
  ecx = edx = 0;  // @5_439c20
  ecx = (u32)(EBP - 144);  // @6_439c20
  reg.state = (s32)((u32)(0));  // @7_439c20
  eax = ext_4cc1d0_thiscall1(ecx);  // @8_439c20
  ecx = edx = 0;  // @9_439c20
  ecx = (u32)(EBP - 144);  // @10_439c20
  ebx = eax;  // @11_439c20
  eax = ext_4cc1d0_thiscall1(ecx);  // @12_439c20
  ecx = edx = 0;  // @13_439c20
  eax = (eax - esi);  // @14_439c20
  L439c87:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @16_439c20
  esi = (u32)(esi + 1);  // @17_439c20
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + esi - 1), &v, sizeof v); }  // @18_439c20
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L439c87;  // @19_439c20
  p0_ = ebx;  // @20_439c20
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p0_), (u32)(62));  // @21_439c20
  ecx = edx = 0;  // @22_439c20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @23_439c20
  if ((eax & eax) == 0) goto L439e11;  // @24_439c20
  L439cb0:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @26_439c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @27_439c20
  if ((ecx & ecx) == 0) goto L439ce1;  // @28_439c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_439c20
  if (eax != (u32)(3)) goto L439ccc;  // @30_439c20
  eax = (u32)(ecx - 4);  // @31_439c20
  ecx = (0u - ecx);  // @32_439c20
  ecx = 0;  // @33_439c20
  ecx = (ecx & eax);  // @34_439c20
  goto L439ce3;  // @35_439c20
  L439ccc:;
  if (eax != (u32)(1)) goto L439ce1;  // @37_439c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @38_439c20
  ecx = eax;  // @39_439c20
  eax = (eax + (u32)(-4));  // @40_439c20
  ecx = (0u - ecx);  // @41_439c20
  ecx = 0;  // @42_439c20
  ecx = (ecx & eax);  // @43_439c20
  goto L439ce3;  // @44_439c20
  L439ce1:;
  ecx = 0;  // @46_439c20
  L439ce3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 17), sizeof v); (u32)v; });  // @48_439c20
  p1_ = ebx;  // @49_439c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_439c20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @51_439c20
  ecx = edx = 0;  // @52_439c20
  esi = eax;  // @53_439c20
  if (esi != (u32)(-1)) goto L439d1c;  // @54_439c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @55_439c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_439c20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(3210));  // @57_439c20
  ecx = edx = 0;  // @58_439c20
  p2_ = ebx;  // @59_439c20
  p3_ = eax;  // @60_439c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @61_439c20
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6794304), (u32)(p2_));  // @62_439c20
  ecx = edx = 0;  // @63_439c20
  goto L439df0;  // @64_439c20
  L439d1c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @66_439c20
  if ((eax & eax) == 0) goto L439d4a;  // @67_439c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @68_439c20
  if (ecx != (u32)(3)) goto L439d35;  // @69_439c20
  ecx = (u32)(eax - 4);  // @70_439c20
  eax = (0u - eax);  // @71_439c20
  eax = 0;  // @72_439c20
  eax = (eax & ecx);  // @73_439c20
  goto L439d4c;  // @74_439c20
  L439d35:;
  if (ecx != (u32)(1)) goto L439d4a;  // @76_439c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @77_439c20
  eax = ecx;  // @78_439c20
  ecx = (ecx + (u32)(-4));  // @79_439c20
  eax = (0u - eax);  // @80_439c20
  eax = 0;  // @81_439c20
  eax = (eax & ecx);  // @82_439c20
  goto L439d4c;  // @83_439c20
  L439d4a:;
  eax = 0;  // @85_439c20
  L439d4c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 17), sizeof v); (u32)v; });  // @87_439c20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4624), sizeof v); (u32)v; }) <= (s32)esi) goto L439df0;  // @88_439c20
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 13), sizeof v); (u32)v; }) != (u32)(0)) goto L439d8f;  // @89_439c20
  eax = ext_41e290_cdecl1((u32)(28));  // @90_439c20
  ecx = edx = 0;  // @91_439c20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @92_439c20
  reg.state = (s32)((u32)(1));  // @93_439c20
  if ((eax & eax) == 0) goto L439d86;  // @94_439c20
  ecx = eax;  // @95_439c20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(4));  // @96_439c20
  ecx = edx = 0;  // @97_439c20
  goto L439d88;  // @98_439c20
  L439d86:;
  eax = 0;  // @100_439c20
  L439d88:;
  reg.state = (s32)((u32)(0));  // @102_439c20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 13), &v, sizeof v); }  // @103_439c20
  L439d8f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 13), sizeof v); (u32)v; });  // @105_439c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_439c20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @107_439c20
  ecx = edx = 0;  // @108_439c20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @109_439c20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @110_439c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @111_439c20
  if ((ecx & ecx) == 0) goto L439dcd;  // @112_439c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_439c20
  if (eax != (u32)(3)) goto L439db8;  // @114_439c20
  eax = (u32)(ecx - 4);  // @115_439c20
  ecx = (0u - ecx);  // @116_439c20
  ecx = 0;  // @117_439c20
  ecx = (ecx & eax);  // @118_439c20
  goto L439dcf;  // @119_439c20
  L439db8:;
  if (eax != (u32)(1)) goto L439dcd;  // @121_439c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @122_439c20
  ecx = eax;  // @123_439c20
  eax = (eax + (u32)(-4));  // @124_439c20
  ecx = (0u - ecx);  // @125_439c20
  ecx = 0;  // @126_439c20
  ecx = (ecx & eax);  // @127_439c20
  goto L439dcf;  // @128_439c20
  L439dcd:;
  ecx = 0;  // @130_439c20
  L439dcf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 17), sizeof v); (u32)v; });  // @132_439c20
  ecx = (u32)(esi + esi*4);  // @133_439c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4932), sizeof v); (u32)v; });  // @134_439c20
  esi = (u32)(eax + ecx*2);  // @135_439c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @136_439c20
  eax = ext_4382e0_thiscall1(ecx);  // @137_439c20
  ecx = edx = 0;  // @138_439c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @139_439c20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @140_439c20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @141_439c20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @142_439c20
  L439df0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @144_439c20
  ebx = (ebx + 1);  // @145_439c20
  p4_ = ebx;  // @146_439c20
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p4_), (u32)(62));  // @147_439c20
  ecx = edx = 0;  // @148_439c20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @149_439c20
  if ((eax & eax) != 0) goto L439cb0;  // @150_439c20
  L439e11:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) == (u32)(0)) goto L439e1e;  // @152_439c20
  p5_ = ebx;  // @153_439c20
  ecx = edi;  // @154_439c20
  eax = ext_437b00_thiscall2(ecx, (u32)(p5_));  // @155_439c20
  ecx = edx = 0;  // @156_439c20
  L439e1e:;
  ecx = (u32)(EBP - 144);  // @158_439c20
  eax = ext_4cbec0_thiscall1(ecx);  // @159_439c20
  ecx = edx = 0;  // @160_439c20
  L439e29:;
  SEH_LEAVE();  // @162_439c20
  ext_633654(G(u32, 0x6f5630));  // @163_439c20
  return eax;  // @164_439c20
}
PCREG(439c20, lifted_439c20);

extern "C" u32 THISCALL lifted_5338b0(u32 ecx_in) {
  SEH_ENTER(0x66a7d2);  // @h_5338b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5338b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21614), sizeof v); (u32)v; }) == (u32)(0)) goto L533ad2;  // @1_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_5338b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 592)))(ecx);  // @3_5338b0
  ecx = edx = 0;  // @4_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_5338b0
  ecx = esi;  // @6_5338b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 396)))(ecx);  // @7_5338b0
  ecx = edx = 0;  // @8_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5338b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @11_5338b0
  ecx = edx = 0;  // @12_5338b0
  edi = eax;  // @13_5338b0
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @14_5338b0
  ebx = 0;  // @15_5338b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @16_5338b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 14), &v, sizeof v); }  // @17_5338b0
  if ((edi & edi) == 0) goto L533979;  // @18_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @19_5338b0
  ecx = edi;  // @20_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(6953324));  // @21_5338b0
  ecx = edx = 0;  // @22_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_5338b0
  ebx = eax;  // @24_5338b0
  p0_ = ebx;  // @25_5338b0
  ecx = esi;  // @26_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 580)))(ecx, (u32)(p0_));  // @27_5338b0
  ecx = edx = 0;  // @28_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_5338b0
  ecx = edi;  // @30_5338b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 262), sizeof v); (u32)v; })) & 0xff);  // @31_5338b0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @32_5338b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6792092), (u32)(16));  // @33_5338b0
  ecx = edx = 0;  // @34_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_5338b0
  ecx = edi;  // @36_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @37_5338b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6791240), (u32)(3));  // @38_5338b0
  ecx = edx = 0;  // @39_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_5338b0
  ecx = edi;  // @41_5338b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6953336), (u32)(0));  // @42_5338b0
  ecx = edx = 0;  // @43_5338b0
  if ((eax & eax) == 0) goto L533979;  // @44_5338b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 14), &v, sizeof v); }  // @45_5338b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @46_5338b0
  L533979:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_5338b0
  ecx = esi;  // @49_5338b0
  p1_ = ebx;  // @50_5338b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @51_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 580)))(ecx, (u32)(p1_));  // @52_5338b0
  ecx = edx = 0;  // @53_5338b0
  if ((eax & eax) == 0) goto L5339cf;  // @54_5338b0
  eax = ext_41e290_cdecl1((u32)(41693));  // @55_5338b0
  ecx = edx = 0;  // @56_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @57_5338b0
  reg.state = (s32)((u32)(0));  // @58_5338b0
  if ((eax & eax) == 0) goto L5339b5;  // @59_5338b0
  ecx = eax;  // @60_5338b0
  eax = ext_54abf0_thiscall1(ecx);  // @61_5338b0
  ecx = edx = 0;  // @62_5338b0
  ecx = eax;  // @63_5338b0
  goto L5339b7;  // @64_5338b0
  L5339b5:;
  ecx = 0;  // @66_5338b0
  L5339b7:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 21642), &v, sizeof v); }  // @68_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_5338b0
  reg.state = (s32)((u32)(4294967295));  // @70_5338b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @71_5338b0
  ecx = edx = 0;  // @72_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @73_5338b0
  L5339cf:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; }) == (u32)(0)) goto L533b1e;  // @75_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_5338b0
  ecx = esi;  // @77_5338b0
  p2_ = ebx;  // @78_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 580)))(ecx, (u32)(p2_));  // @79_5338b0
  ecx = edx = 0;  // @80_5338b0
  edi = eax;  // @81_5338b0
  if ((edi & edi) == 0) goto L533a26;  // @82_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @83_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_5338b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6953036), (u32)(812));  // @85_5338b0
  ecx = edx = 0;  // @86_5338b0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 200), sizeof v); (u32)v; });  // @87_5338b0
  p3_ = ecx;  // @88_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @89_5338b0
  ecx = (u32)(edi + 4);  // @90_5338b0
  p4_ = ecx;  // @91_5338b0
  ecx = (u32)(edi + 68);  // @92_5338b0
  p5_ = ecx;  // @93_5338b0
  p6_ = eax;  // @94_5338b0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 44)))((u32)(p6_), (u32)(6953356), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 196), sizeof v); (u32)v; }), (u32)(p3_));  // @95_5338b0
  ecx = edx = 0;  // @96_5338b0
  L533a26:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 196), sizeof v); (u32)v; });  // @98_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @99_5338b0
  if ((s32)ecx < (s32)eax) ecx = eax;  // @100_5338b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 13), sizeof v); (u32)v; });  // @101_5338b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @102_5338b0
  ecx = 0;  // @103_5338b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 200), sizeof v); (u32)v; }) != (ecx & 0xff)) ecx = eax;  // @104_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @105_5338b0
  ebx = (ebx & 0xffffff00u) | (((ecx & 0xff)) & 0xff);  // @106_5338b0
  eax = (eax + (u32)(-4));  // @107_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @108_5338b0
  p7_ = eax;  // @109_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 160)))(ecx, (u32)(p7_));  // @111_5338b0
  ecx = edx = 0;  // @112_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @113_5338b0
  p8_ = ebx;  // @114_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 164)))(ecx, (u32)(p8_));  // @116_5338b0
  ecx = edx = 0;  // @117_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @118_5338b0
  if ((eax & eax) == 0) goto L533a94;  // @119_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @120_5338b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 201), sizeof v); (u32)v; }) != (u32)(0)) goto L533a8b;  // @121_5338b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 41596), &v, sizeof v); }  // @122_5338b0
  goto L533a94;  // @123_5338b0
  L533a8b:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 14), sizeof v); (u32)v; })) & 0xff);  // @125_5338b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 41596), &v, sizeof v); }  // @126_5338b0
  L533a94:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @128_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21634), sizeof v); (u32)v; });  // @129_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 41582), &v, sizeof v); }  // @130_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @131_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @133_5338b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @134_5338b0
  ecx = edx = 0;  // @135_5338b0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L533ae6;  // @136_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @137_5338b0
  if ((ecx & ecx) == 0) goto L533ac8;  // @138_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(1));  // @140_5338b0
  ecx = edx = 0;  // @141_5338b0
  L533ac8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21642), &v, sizeof v); }  // @143_5338b0
  L533ad2:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @145_5338b0
  SEH_LEAVE();  // @146_5338b0
  return eax;  // @147_5338b0
  L533ae6:;
  eax = (u32)(EBP - 28);  // @149_5338b0
  p9_ = eax;  // @150_5338b0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)0x67614c))((u32)(0), (u32)(0), (u32)(5454944), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; }), (u32)(0), (u32)(p9_));  // @151_5338b0
  ecx = edx = 0;  // @152_5338b0
  p10_ = eax;  // @153_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 21638), &v, sizeof v); }  // @154_5338b0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676150))((u32)(p10_), (u32)(15));  // @155_5338b0
  ecx = edx = 0;  // @156_5338b0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676154))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21638), sizeof v); (u32)v; }), (u32)(1));  // @157_5338b0
  ecx = edx = 0;  // @158_5338b0
  L533b1e:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @160_5338b0
  SEH_LEAVE();  // @161_5338b0
  return eax;  // @162_5338b0
}
PCREG(5338b0, lifted_5338b0);

extern "C" u32 THISCALL lifted_41fad0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6641b6);  // @h_41fad0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_41fad0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_41fad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_41fad0
  p0_ = eax;  // @3_41fad0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @4_41fad0
  eax = ext_42a4a0_thiscall2(ecx, (u32)(p0_));  // @5_41fad0
  ecx = edx = 0;  // @6_41fad0
  ecx = (u32)(edi + 7825);  // @7_41fad0
  reg.state = (s32)((u32)(0));  // @8_41fad0
  { u32 v = (u32)((u32)(6780996)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @9_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @10_41fad0
  ecx = edx = 0;  // @11_41fad0
  ecx = (u32)(edi + 7953);  // @12_41fad0
  reg.state = (s32)((u32)(1));  // @13_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @14_41fad0
  ecx = edx = 0;  // @15_41fad0
  ecx = (u32)(edi + 8081);  // @16_41fad0
  reg.state = (s32)((u32)(2));  // @17_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @18_41fad0
  ecx = edx = 0;  // @19_41fad0
  ecx = (u32)(edi + 8209);  // @20_41fad0
  reg.state = (s32)((u32)(3));  // @21_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @22_41fad0
  ecx = edx = 0;  // @23_41fad0
  ecx = (u32)(edi + 8337);  // @24_41fad0
  reg.state = (s32)((u32)(4));  // @25_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @26_41fad0
  ecx = edx = 0;  // @27_41fad0
  ecx = (u32)(edi + 8465);  // @28_41fad0
  reg.state = (s32)((u32)(5));  // @29_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @30_41fad0
  ecx = edx = 0;  // @31_41fad0
  ecx = (u32)(edi + 8593);  // @32_41fad0
  reg.state = (s32)((u32)(6));  // @33_41fad0
  eax = ext_4ccba0_thiscall1(ecx);  // @34_41fad0
  ecx = edx = 0;  // @35_41fad0
  ebx = (u32)(edi + 8770);  // @36_41fad0
  reg.state = (s32)((u32)(7));  // @37_41fad0
  ecx = ebx;  // @38_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @39_41fad0
  ecx = edx = 0;  // @40_41fad0
  ecx = (u32)(edi + 8902);  // @41_41fad0
  reg.state = (s32)((u32)(8));  // @42_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @43_41fad0
  ecx = edx = 0;  // @44_41fad0
  ecx = (u32)(edi + 9030);  // @45_41fad0
  reg.state = (s32)((u32)(9));  // @46_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @47_41fad0
  ecx = edx = 0;  // @48_41fad0
  ecx = (u32)(edi + 9179);  // @49_41fad0
  reg.state = (s32)((u32)(10));  // @50_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @51_41fad0
  ecx = edx = 0;  // @52_41fad0
  ecx = (u32)(edi + 9307);  // @53_41fad0
  reg.state = (s32)((u32)(11));  // @54_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @55_41fad0
  ecx = edx = 0;  // @56_41fad0
  ecx = (u32)(edi + 9435);  // @57_41fad0
  reg.state = (s32)((u32)(12));  // @58_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @59_41fad0
  ecx = edx = 0;  // @60_41fad0
  ecx = (u32)(edi + 9563);  // @61_41fad0
  reg.state = (s32)((u32)(13));  // @62_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @63_41fad0
  ecx = edx = 0;  // @64_41fad0
  eax = (u32)(edi + 9707);  // @65_41fad0
  reg.state = (s32)((u32)(14));  // @66_41fad0
  p1_ = eax;  // @67_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 7819), &v, sizeof v); }  // @68_41fad0
  eax = ext_634d10_cdecl3((u32)(p1_), (u32)(0), (u32)(152));  // @69_41fad0
  ecx = edx = 0;  // @70_41fad0
  eax = ext_41e290_cdecl1((u32)(260));  // @71_41fad0
  ecx = edx = 0;  // @72_41fad0
  esi = eax;  // @73_41fad0
  p2_ = esi;  // @74_41fad0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67607c))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2511), sizeof v); (u32)v; }), (u32)(p2_), (u32)(260));  // @75_41fad0
  ecx = edx = 0;  // @76_41fad0
  p3_ = esi;  // @77_41fad0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))((u32)(p3_), (u32)(92));  // @78_41fad0
  ecx = edx = 0;  // @79_41fad0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @80_41fad0
  ecx = (u32)(EBP - 144);  // @81_41fad0
  p4_ = esi;  // @82_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p4_));  // @83_41fad0
  ecx = edx = 0;  // @84_41fad0
  eax = (u32)(EBP - 144);  // @85_41fad0
  reg.state = (s32)((u32)(15));  // @86_41fad0
  p5_ = eax;  // @87_41fad0
  ecx = (u32)(edi + 163);  // @88_41fad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p5_));  // @89_41fad0
  ecx = edx = 0;  // @90_41fad0
  ecx = (u32)(EBP - 144);  // @91_41fad0
  reg.state = (s32)((u32)(14));  // @92_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @93_41fad0
  ecx = edx = 0;  // @94_41fad0
  p6_ = esi;  // @95_41fad0
  eax = ext_634273_cdecl2((u32)(p6_), (u32)(1));  // @96_41fad0
  ecx = edx = 0;  // @97_41fad0
  ecx = edi;  // @98_41fad0
  eax = ext_421680_thiscall1(ecx);  // @99_41fad0
  ecx = edx = 0;  // @100_41fad0
  ecx = edi;  // @101_41fad0
  eax = ext_421940_thiscall1(ecx);  // @102_41fad0
  ecx = edx = 0;  // @103_41fad0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L41fe52;  // @104_41fad0
  ecx = (u32)(EBP - 144);  // @105_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 6823), &v, sizeof v); }  // @106_41fad0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 7824), &v, sizeof v); }  // @107_41fad0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9704), &v, sizeof v); }  // @108_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8898), &v, sizeof v); }  // @109_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9158), &v, sizeof v); }  // @110_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9162), &v, sizeof v); }  // @111_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782784));  // @112_41fad0
  ecx = edx = 0;  // @113_41fad0
  eax = (u32)(EBP - 144);  // @114_41fad0
  reg.state = (s32)((u32)(16));  // @115_41fad0
  p7_ = eax;  // @116_41fad0
  ecx = (u32)(edi + 7953);  // @117_41fad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p7_));  // @118_41fad0
  ecx = edx = 0;  // @119_41fad0
  ecx = (u32)(EBP - 144);  // @120_41fad0
  reg.state = (s32)((u32)(14));  // @121_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @122_41fad0
  ecx = edx = 0;  // @123_41fad0
  eax = (u32)(EBP - 144);  // @124_41fad0
  { u32 v = (u32)((u32)(4332832)); __builtin_memcpy((void *)(u32)(edi + 9174), &v, sizeof v); }  // @125_41fad0
  p8_ = eax;  // @126_41fad0
  { u32 v = (u32)((u32)(120)); __builtin_memcpy((void *)(u32)(edi + 2531), &v, sizeof v); }  // @127_41fad0
  eax = ext_420ea0_cdecl1((u32)(p8_));  // @128_41fad0
  ecx = edx = 0;  // @129_41fad0
  p9_ = eax;  // @130_41fad0
  ecx = ebx;  // @131_41fad0
  reg.state = (s32)((u32)(17));  // @132_41fad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p9_));  // @133_41fad0
  ecx = edx = 0;  // @134_41fad0
  ecx = (u32)(EBP - 144);  // @135_41fad0
  reg.state = (s32)((u32)(14));  // @136_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @137_41fad0
  ecx = edx = 0;  // @138_41fad0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(7328832), &v, sizeof v); }  // @139_41fad0
  eax = ((u32( *)(u32))(*(u32 *)0x676270))((u32)(4344080));  // @140_41fad0
  ecx = edx = 0;  // @141_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9692), &v, sizeof v); }  // @142_41fad0
  ecx = (u32)(EBP - 144);  // @143_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782788));  // @144_41fad0
  ecx = edx = 0;  // @145_41fad0
  eax = (u32)(EBP - 144);  // @146_41fad0
  reg.state = (s32)((u32)(18));  // @147_41fad0
  p10_ = eax;  // @148_41fad0
  ecx = (u32)(edi + 7825);  // @149_41fad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p10_));  // @150_41fad0
  ecx = edx = 0;  // @151_41fad0
  ecx = (u32)(EBP - 144);  // @152_41fad0
  reg.state = (s32)((u32)(14));  // @153_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @154_41fad0
  ecx = edx = 0;  // @155_41fad0
  ecx = (u32)(EBP - 144);  // @156_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782804));  // @157_41fad0
  ecx = edx = 0;  // @158_41fad0
  eax = (u32)(EBP - 144);  // @159_41fad0
  reg.state = (s32)((u32)(19));  // @160_41fad0
  p11_ = eax;  // @161_41fad0
  ecx = (u32)(edi + 8081);  // @162_41fad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p11_));  // @163_41fad0
  ecx = edx = 0;  // @164_41fad0
  ecx = (u32)(EBP - 144);  // @165_41fad0
  reg.state = (s32)((u32)(14));  // @166_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @167_41fad0
  ecx = edx = 0;  // @168_41fad0
  ecx = (u32)(EBP - 144);  // @169_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782820));  // @170_41fad0
  ecx = edx = 0;  // @171_41fad0
  eax = (u32)(EBP - 144);  // @172_41fad0
  reg.state = (s32)((u32)(20));  // @173_41fad0
  p12_ = eax;  // @174_41fad0
  ecx = (u32)(edi + 1059);  // @175_41fad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p12_));  // @176_41fad0
  ecx = edx = 0;  // @177_41fad0
  ecx = (u32)(EBP - 144);  // @178_41fad0
  reg.state = (s32)((u32)(14));  // @179_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @180_41fad0
  ecx = edx = 0;  // @181_41fad0
  ecx = (u32)(EBP - 144);  // @182_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782844));  // @183_41fad0
  ecx = edx = 0;  // @184_41fad0
  eax = (u32)(EBP - 144);  // @185_41fad0
  reg.state = (s32)((u32)(21));  // @186_41fad0
  p13_ = eax;  // @187_41fad0
  ecx = (u32)(edi + 8337);  // @188_41fad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p13_));  // @189_41fad0
  ecx = edx = 0;  // @190_41fad0
  ecx = (u32)(EBP - 144);  // @191_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @192_41fad0
  ecx = edx = 0;  // @193_41fad0
  { u16 v = (u16)((u32)(257)); __builtin_memcpy((void *)(u32)(edi + 109), &v, sizeof v); }  // @194_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 147), &v, sizeof v); }  // @195_41fad0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 151), &v, sizeof v); }  // @196_41fad0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 143), &v, sizeof v); }  // @197_41fad0
  L41fe52:;
  eax = edi;  // @199_41fad0
  SEH_LEAVE();  // @200_41fad0
  ext_633654(G(u32, 0x6f5630));  // @201_41fad0
  return eax;  // @202_41fad0
}
PCREG(41fad0, lifted_41fad0);

extern "C" u32 THISCALL lifted_5f9940(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d1e5);  // @h_5f9940
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  ebx = ecx;  // @0_5f9940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @1_5f9940
  edx = 0;  // @2_5f9940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_5f9940
  eax = (eax - ecx);  // @4_5f9940
  eax = (u32)((s32)eax >> (u32)(2));  // @5_5f9940
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_5f9940
  if ((eax & eax) == 0) goto L5f9a1f;  // @7_5f9940
  L5f9981:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_5f9940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4), sizeof v); (u32)v; });  // @10_5f9940
  edi = (u32)(esi + 1);  // @11_5f9940
  L5f9990:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @13_5f9940
  esi = (esi + 1);  // @14_5f9940
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5f9990;  // @15_5f9940
  esi = (esi - edi);  // @16_5f9940
  edx = (u32)(EBP - 24);  // @17_5f9940
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @18_5f9940
  eax = (u32)(EBP - 20);  // @19_5f9940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @20_5f9940
  edi = (edi - ecx);  // @21_5f9940
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @22_5f9940
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @23_5f9940
  if ((s32)esi >= (s32)edi) eax = edx;  // @24_5f9940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_5f9940
  p0_ = edx;  // @26_5f9940
  p1_ = ecx;  // @27_5f9940
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676408))((u32)(p1_), (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @28_5f9940
  ecx = edx = 0;  // @29_5f9940
  if ((eax & eax) != 0) goto L5f9a06;  // @30_5f9940
  if ((s32)edi < (s32)esi) goto L5f9a06;  // @31_5f9940
  eax = (eax & 0xffffff00u) | (((u32)((s32)edi > (s32)esi)) & 0xff);  // @32_5f9940
  if ((eax & eax) != 0) goto L5f9a06;  // @33_5f9940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @34_5f9940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_5f9940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7049376), (u32)(26));  // @36_5f9940
  ecx = edx = 0;  // @37_5f9940
  p2_ = eax;  // @38_5f9940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_5f9940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p2_), (u32)(6932144), (u32)(7049464));  // @40_5f9940
  ecx = edx = 0;  // @41_5f9940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @42_5f9940
  if ((eax & eax) == 0) goto L5f9a05;  // @43_5f9940
  eax = ((u32(STDCALL *)(void))(eax))();  // @44_5f9940
  ecx = edx = 0;  // @45_5f9940
  goto L5f9a06;  // @46_5f9940
  L5f9a05:;
  __builtin_trap();  // @48_5f9940
  L5f9a06:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @50_5f9940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @51_5f9940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @52_5f9940
  edx = (edx + 1);  // @53_5f9940
  eax = (eax - ecx);  // @54_5f9940
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @55_5f9940
  eax = (u32)((s32)eax >> (u32)(2));  // @56_5f9940
  if (edx < eax) goto L5f9981;  // @57_5f9940
  L5f9a1f:;
  eax = ext_41e290_cdecl1((u32)(72));  // @59_5f9940
  ecx = edx = 0;  // @60_5f9940
  edi = eax;  // @61_5f9940
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @62_5f9940
  reg.state = (s32)((u32)(0));  // @63_5f9940
  if ((edi & edi) == 0) goto L5f9a91;  // @64_5f9940
  esi = (u32)(edi + 4);  // @65_5f9940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @66_5f9940
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @67_5f9940
  ecx = esi;  // @68_5f9940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @69_5f9940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @70_5f9940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @71_5f9940
  eax = ext_6014a0_stdcall1((u32)(8));  // @72_5f9940
  ecx = edx = 0;  // @73_5f9940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @74_5f9940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @75_5f9940
  ecx = (u32)(eax + 8);  // @76_5f9940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @77_5f9940
  if ((eax & eax) == 0) goto L5f9a74;  // @78_5f9940
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @79_5f9940
  L5f9a74:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @81_5f9940
  ecx = (u32)(edi + 16);  // @82_5f9940
  reg.state = (s32)((u32)(1));  // @83_5f9940
  eax = ext_5f9720_thiscall1(ecx);  // @84_5f9940
  ecx = edx = 0;  // @85_5f9940
  ecx = (u32)(edi + 44);  // @86_5f9940
  reg.state = (s32)((u32)(2));  // @87_5f9940
  eax = ext_5f9720_thiscall1(ecx);  // @88_5f9940
  ecx = edx = 0;  // @89_5f9940
  goto L5f9a93;  // @90_5f9940
  L5f9a91:;
  edi = 0;  // @92_5f9940
  L5f9a93:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @94_5f9940
  ecx = edx;  // @95_5f9940
  reg.state = (s32)((u32)(4294967295));  // @96_5f9940
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @97_5f9940
  eax = (u32)(ecx + 1);  // @98_5f9940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @99_5f9940
  L5f9aa8:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @101_5f9940
  ecx = (ecx + 1);  // @102_5f9940
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5f9aa8;  // @103_5f9940
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @104_5f9940
  eax = (u32)(ecx + edx);  // @105_5f9940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @106_5f9940
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @107_5f9940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @108_5f9940
  eax = (eax - edx);  // @109_5f9940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @110_5f9940
  if (eax > ecx) goto L5f9b03;  // @111_5f9940
  p3_ = eax;  // @112_5f9940
  p4_ = edx;  // @113_5f9940
  eax = ext_634d22_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }), (u32)(p4_), (u32)(p3_));  // @114_5f9940
  ecx = edx = 0;  // @115_5f9940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @116_5f9940
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @117_5f9940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @118_5f9940
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @119_5f9940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @120_5f9940
  if (ecx == edx) goto L5f9b25;  // @121_5f9940
  eax = edx;  // @122_5f9940
  eax = (eax - edx);  // @123_5f9940
  eax = (eax + 1);  // @124_5f9940
  p5_ = eax;  // @125_5f9940
  p6_ = edx;  // @126_5f9940
  p7_ = ecx;  // @127_5f9940
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))((u32)(p7_), (u32)(p6_), (u32)(p5_));  // @128_5f9940
  ecx = edx = 0;  // @129_5f9940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @130_5f9940
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @131_5f9940
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @132_5f9940
  goto L5f9b25;  // @133_5f9940
  L5f9b03:;
  p8_ = ecx;  // @135_5f9940
  p9_ = edx;  // @136_5f9940
  eax = ext_634d22_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }), (u32)(p9_), (u32)(p8_));  // @137_5f9940
  ecx = edx = 0;  // @138_5f9940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @139_5f9940
  ecx = (u32)(edi + 4);  // @140_5f9940
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @141_5f9940
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @142_5f9940
  p10_ = eax;  // @143_5f9940
  eax = ext_5f2c60_thiscall3(ecx, (u32)(p10_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @144_5f9940
  ecx = edx = 0;  // @145_5f9940
  L5f9b25:;
  ecx = (u32)(edi + 16);  // @147_5f9940
  eax = ext_605ba0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @148_5f9940
  ecx = edx = 0;  // @149_5f9940
  ecx = (u32)(edi + 44);  // @150_5f9940
  eax = ext_605ba0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @151_5f9940
  ecx = edx = 0;  // @152_5f9940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @153_5f9940
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; })) goto L5f9b4f;  // @154_5f9940
  if ((eax & eax) == 0) goto L5f9b49;  // @155_5f9940
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @156_5f9940
  L5f9b49:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @158_5f9940
  goto L5f9b5b;  // @159_5f9940
  L5f9b4f:;
  ecx = (u32)(EBP - 16);  // @161_5f9940
  p11_ = ecx;  // @162_5f9940
  p12_ = eax;  // @163_5f9940
  ecx = ebx;  // @164_5f9940
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p12_), (u32)(p11_));  // @165_5f9940
  ecx = edx = 0;  // @166_5f9940
  L5f9b5b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @168_5f9940
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @169_5f9940
  eax = (u32)((s32)eax >> (u32)(2));  // @170_5f9940
  eax = (eax - 1);  // @171_5f9940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @172_5f9940
  SEH_LEAVE();  // @173_5f9940
  return eax;  // @174_5f9940
}
PCREG(5f9940, lifted_5f9940);

extern "C" u32 THISCALL lifted_5cce70(u32 ecx_in) {
  SEH_ENTER(0x66c86a);  // @h_5cce70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5cce70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_5cce70
  eax = ext_469870_thiscall1(ecx);  // @2_5cce70
  ecx = edx = 0;  // @3_5cce70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5cce70
  { u32 v = (u32)((u32)(7032276)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5cce70
  ebx = (u32)(esi + 2743);  // @7_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @8_5cce70
  ecx = (u32)(esi + 2907);  // @9_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2644), &v, sizeof v); }  // @10_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2648), &v, sizeof v); }  // @11_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2726), &v, sizeof v); }  // @12_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @13_5cce70
  reg.state = (s32)((u32)(0));  // @14_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2793), &v, sizeof v); }  // @15_5cce70
  eax = ext_4e1b60_thiscall1(ecx);  // @16_5cce70
  ecx = edx = 0;  // @17_5cce70
  ecx = (u32)(esi + 3029);  // @18_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3017), &v, sizeof v); }  // @19_5cce70
  eax = ext_662750_thiscall1(ecx);  // @20_5cce70
  ecx = edx = 0;  // @21_5cce70
  ecx = (u32)(esi + 3058);  // @22_5cce70
  eax = ext_662750_thiscall1(ecx);  // @23_5cce70
  ecx = edx = 0;  // @24_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3087), &v, sizeof v); }  // @25_5cce70
  ecx = (u32)(esi + 3382);  // @26_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3091), &v, sizeof v); }  // @27_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3095), &v, sizeof v); }  // @28_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3099), &v, sizeof v); }  // @29_5cce70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3103), &v, sizeof v); }  // @30_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3104), &v, sizeof v); }  // @31_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3108), &v, sizeof v); }  // @32_5cce70
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 3112), &v, sizeof v); }  // @33_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3116), &v, sizeof v); }  // @34_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3120), &v, sizeof v); }  // @35_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3124), &v, sizeof v); }  // @36_5cce70
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 3128), &v, sizeof v); }  // @37_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3132), &v, sizeof v); }  // @38_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3136), &v, sizeof v); }  // @39_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3140), &v, sizeof v); }  // @40_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3144), &v, sizeof v); }  // @41_5cce70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3148), &v, sizeof v); }  // @42_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3149), &v, sizeof v); }  // @43_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3153), &v, sizeof v); }  // @44_5cce70
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 3157), &v, sizeof v); }  // @45_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3161), &v, sizeof v); }  // @46_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3165), &v, sizeof v); }  // @47_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3169), &v, sizeof v); }  // @48_5cce70
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 3173), &v, sizeof v); }  // @49_5cce70
  eax = ext_662be0_thiscall1(ecx);  // @50_5cce70
  ecx = edx = 0;  // @51_5cce70
  ecx = (u32)(esi + 3463);  // @52_5cce70
  eax = ext_662ed0_thiscall1(ecx);  // @53_5cce70
  ecx = edx = 0;  // @54_5cce70
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3612), &v, sizeof v); }  // @55_5cce70
  edx = (u32)(EBP - 16);  // @56_5cce70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_5cce70
  p0_ = edx;  // @58_5cce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_5cce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @60_5cce70
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7032424), (u32)(p0_));  // @61_5cce70
  ecx = edx = 0;  // @62_5cce70
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5cd05f;  // @63_5cce70
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))((u32)(6795480), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @64_5cce70
  ecx = edx = 0;  // @65_5cce70
  if ((eax & eax) != 0) goto L5cd05f;  // @66_5cce70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 3612), &v, sizeof v); }  // @67_5cce70
  L5cd05f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3608), &v, sizeof v); }  // @69_5cce70
  eax = (u32)(EBP - 24);  // @70_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2644), &v, sizeof v); }  // @71_5cce70
  edi = (u32)(esi + 3573);  // @72_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2652), &v, sizeof v); }  // @73_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2656), &v, sizeof v); }  // @74_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2660), &v, sizeof v); }  // @75_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2664), &v, sizeof v); }  // @76_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2668), &v, sizeof v); }  // @77_5cce70
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2672), &v, sizeof v); }  // @78_5cce70
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3379), &v, sizeof v); }  // @79_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3599), &v, sizeof v); }  // @80_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3603), &v, sizeof v); }  // @81_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2869), &v, sizeof v); }  // @82_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2773), &v, sizeof v); }  // @83_5cce70
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 2777), &v, sizeof v); }  // @84_5cce70
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 2781), &v, sizeof v); }  // @85_5cce70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2772), &v, sizeof v); }  // @86_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2793), &v, sizeof v); }  // @87_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2797), &v, sizeof v); }  // @88_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2801), &v, sizeof v); }  // @89_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2805), &v, sizeof v); }  // @90_5cce70
  { u32 v = (u32)((u32)(1048196573)); __builtin_memcpy((void *)(u32)(esi + 2809), &v, sizeof v); }  // @91_5cce70
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 2829), &v, sizeof v); }  // @92_5cce70
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 2817), &v, sizeof v); }  // @93_5cce70
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(esi + 2825), &v, sizeof v); }  // @94_5cce70
  { u32 v = (u32)((u32)(1054828275)); __builtin_memcpy((void *)(u32)(esi + 2813), &v, sizeof v); }  // @95_5cce70
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(esi + 2841), &v, sizeof v); }  // @96_5cce70
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 2821), &v, sizeof v); }  // @97_5cce70
  { u32 v = (u32)((u32)(3214696874)); __builtin_memcpy((void *)(u32)(esi + 2710), &v, sizeof v); }  // @98_5cce70
  { u32 v = (u32)((u32)(1065749138)); __builtin_memcpy((void *)(u32)(esi + 2714), &v, sizeof v); }  // @99_5cce70
  { u32 v = (u32)((u32)(3214696874)); __builtin_memcpy((void *)(u32)(esi + 2718), &v, sizeof v); }  // @100_5cce70
  { u32 v = (u32)((u32)(1065749138)); __builtin_memcpy((void *)(u32)(esi + 2722), &v, sizeof v); }  // @101_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2843), &v, sizeof v); }  // @102_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3341), &v, sizeof v); }  // @103_5cce70
  { u32 v = (u32)((u32)(1050728828)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @104_5cce70
  { u32 v = (u32)((u32)(1050728828)); __builtin_memcpy((void *)(u32)(esi + 3577), &v, sizeof v); }  // @105_5cce70
  { u32 v = (u32)((u32)(1161527296)); __builtin_memcpy((void *)(u32)(esi + 3581), &v, sizeof v); }  // @106_5cce70
  { u32 v = (u32)((u32)(1258902592)); __builtin_memcpy((void *)(u32)(esi + 3585), &v, sizeof v); }  // @107_5cce70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3378), &v, sizeof v); }  // @108_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2847), &v, sizeof v); }  // @109_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2851), &v, sizeof v); }  // @110_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2855), &v, sizeof v); }  // @111_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2859), &v, sizeof v); }  // @112_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2863), &v, sizeof v); }  // @113_5cce70
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2867), &v, sizeof v); }  // @114_5cce70
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3597), &v, sizeof v); }  // @115_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2900), &v, sizeof v); }  // @116_5cce70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2895), &v, sizeof v); }  // @117_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2789), &v, sizeof v); }  // @118_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2885), &v, sizeof v); }  // @119_5cce70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2893), &v, sizeof v); }  // @120_5cce70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2742), &v, sizeof v); }  // @121_5cce70
  if (ebx == eax) goto L5cd258;  // @122_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @123_5cce70
  L5cd258:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3381), &v, sizeof v); }  // @125_5cce70
  ecx = (u32)(esi + 3209);  // @126_5cce70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3544), &v, sizeof v); }  // @127_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3545), &v, sizeof v); }  // @128_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3349), &v, sizeof v); }  // @129_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3353), &v, sizeof v); }  // @130_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3357), &v, sizeof v); }  // @131_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3362), &v, sizeof v); }  // @132_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3366), &v, sizeof v); }  // @133_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3370), &v, sizeof v); }  // @134_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2674), &v, sizeof v); }  // @135_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2678), &v, sizeof v); }  // @136_5cce70
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(esi + 2682), &v, sizeof v); }  // @137_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2698), &v, sizeof v); }  // @138_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2702), &v, sizeof v); }  // @139_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2706), &v, sizeof v); }  // @140_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2686), &v, sizeof v); }  // @141_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2690), &v, sizeof v); }  // @142_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2694), &v, sizeof v); }  // @143_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3197), &v, sizeof v); }  // @144_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3201), &v, sizeof v); }  // @145_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3205), &v, sizeof v); }  // @146_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3185), &v, sizeof v); }  // @147_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3189), &v, sizeof v); }  // @148_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3193), &v, sizeof v); }  // @149_5cce70
  eax = ext_4de7a0_thiscall1(ecx);  // @150_5cce70
  ecx = edx = 0;  // @151_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2869), &v, sizeof v); }  // @152_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2896), &v, sizeof v); }  // @153_5cce70
  { u32 v = (u32)((u32)(4294967291)); __builtin_memcpy((void *)(u32)(esi + 3021), &v, sizeof v); }  // @154_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3374), &v, sizeof v); }  // @155_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3345), &v, sizeof v); }  // @156_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3025), &v, sizeof v); }  // @157_5cce70
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 2833), &v, sizeof v); }  // @158_5cce70
  { u32 v = (u32)((u32)(1133903872)); __builtin_memcpy((void *)(u32)(esi + 3177), &v, sizeof v); }  // @159_5cce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @160_5cce70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @161_5cce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @162_5cce70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6999972), (u32)(0), (u32)(7032440), (u32)(228));  // @163_5cce70
  ecx = edx = 0;  // @164_5cce70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 2905), &v, sizeof v); }  // @165_5cce70
  ecx = (u32)(EBP - 28);  // @166_5cce70
  eax = (u32)(esi + 3017);  // @167_5cce70
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 3050), &v, sizeof v); }  // @168_5cce70
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 3079), &v, sizeof v); }  // @169_5cce70
  if (eax == ecx) goto L5cd3ef;  // @170_5cce70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @171_5cce70
  L5cd3ef:;
  eax = ext_41e290_cdecl1((u32)(264));  // @173_5cce70
  ecx = edx = 0;  // @174_5cce70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @175_5cce70
  reg.state = (s32)((u32)(1));  // @176_5cce70
  if ((eax & eax) == 0) goto L5cd41d;  // @177_5cce70
  p1_ = edi;  // @178_5cce70
  ecx = eax;  // @179_5cce70
  eax = ext_4d8330_thiscall4(ecx, (u32)(7032516), (u32)(7032488), (u32)(p1_));  // @180_5cce70
  ecx = edx = 0;  // @181_5cce70
  edx = eax;  // @182_5cce70
  goto L5cd41f;  // @183_5cce70
  L5cd41d:;
  edx = 0;  // @185_5cce70
  L5cd41f:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 2640), &v, sizeof v); }  // @187_5cce70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_5cce70
  p2_ = edx;  // @189_5cce70
  reg.state = (s32)((u32)(0));  // @190_5cce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @191_5cce70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(p2_));  // @192_5cce70
  ecx = edx = 0;  // @193_5cce70
  eax = esi;  // @194_5cce70
  SEH_LEAVE();  // @195_5cce70
  return eax;  // @196_5cce70
}
PCREG(5cce70, lifted_5cce70);

extern "C" u32 THISCALL lifted_4acf30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668781);  // @h_4acf30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4acf30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @1_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4acf30
  p0_ = edx;  // @4_4acf30
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @5_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p0_));  // @8_4acf30
  ecx = edx = 0;  // @9_4acf30
  ebx = eax;  // @10_4acf30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @11_4acf30
  if ((ebx & ebx) != 0) goto L4acfe8;  // @12_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @13_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(579));  // @15_4acf30
  ecx = edx = 0;  // @16_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @17_4acf30
  edx = (u32)(EBP - 144);  // @18_4acf30
  edi = eax;  // @19_4acf30
  p1_ = edx;  // @20_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @21_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, (u32)(p1_), (u32)(1));  // @23_4acf30
  ecx = edx = 0;  // @24_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_4acf30
  ecx = eax;  // @26_4acf30
  reg.state = (s32)(ebx);  // @27_4acf30
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_4acf30
  ecx = edx = 0;  // @29_4acf30
  p2_ = eax;  // @30_4acf30
  p3_ = edi;  // @31_4acf30
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p3_), (u32)(6884216), (u32)(p2_));  // @32_4acf30
  ecx = edx = 0;  // @33_4acf30
  ecx = (u32)(EBP - 144);  // @34_4acf30
  eax = ext_4cbec0_thiscall1(ecx);  // @35_4acf30
  ecx = edx = 0;  // @36_4acf30
  L4acfe1:;
  eax = 0;  // @38_4acf30
  goto L4ad375;  // @39_4acf30
  L4acfe8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @41_4acf30
  ecx = ebx;  // @42_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @43_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050577));  // @44_4acf30
  ecx = edx = 0;  // @45_4acf30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4ad0b7;  // @46_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @47_4acf30
  ecx = ebx;  // @48_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @49_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050579));  // @50_4acf30
  ecx = edx = 0;  // @51_4acf30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4ad0b7;  // @52_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @53_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(584));  // @55_4acf30
  ecx = edx = 0;  // @56_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @57_4acf30
  edx = (u32)(EBP - 272);  // @58_4acf30
  edi = eax;  // @59_4acf30
  p4_ = edx;  // @60_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @61_4acf30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @62_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, (u32)(p4_), (u32)(1));  // @64_4acf30
  ecx = edx = 0;  // @65_4acf30
  ebx = eax;  // @66_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @67_4acf30
  edx = (u32)(EBP - 144);  // @68_4acf30
  p5_ = edx;  // @69_4acf30
  reg.state = (s32)((u32)(1));  // @70_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, (u32)(p5_), (u32)(1));  // @72_4acf30
  ecx = edx = 0;  // @73_4acf30
  esi = eax;  // @74_4acf30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_4acf30
  ecx = ebx;  // @76_4acf30
  reg.state = (s32)((u32)(2));  // @77_4acf30
  eax = ext_4cc1d0_thiscall1(ecx);  // @78_4acf30
  ecx = edx = 0;  // @79_4acf30
  p6_ = eax;  // @80_4acf30
  ecx = esi;  // @81_4acf30
  eax = ext_4cc1d0_cdecl1((u32)(p6_));  // @82_4acf30
  ecx = edx = 0;  // @83_4acf30
  p7_ = eax;  // @84_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; }), (u32)(6884272), (u32)(p7_));  // @85_4acf30
  ecx = edx = 0;  // @86_4acf30
  ecx = (u32)(EBP - 144);  // @87_4acf30
  eax = ext_4cbec0_thiscall1(ecx);  // @88_4acf30
  ecx = edx = 0;  // @89_4acf30
  ecx = (u32)(EBP - 272);  // @90_4acf30
  eax = ext_4cbec0_thiscall1(ecx);  // @91_4acf30
  ecx = edx = 0;  // @92_4acf30
  eax = 0;  // @93_4acf30
  goto L4ad375;  // @94_4acf30
  L4ad0b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @96_4acf30
  ecx = ebx;  // @97_4acf30
  esi = ebx;  // @98_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @99_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050577));  // @100_4acf30
  ecx = edx = 0;  // @101_4acf30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4ad0da;  // @102_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @103_4acf30
  ecx = ebx;  // @104_4acf30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @105_4acf30
  ecx = edx = 0;  // @106_4acf30
  esi = eax;  // @107_4acf30
  L4ad0da:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @109_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @111_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2149580820));  // @112_4acf30
  ecx = edx = 0;  // @113_4acf30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4ad1d7;  // @114_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @115_4acf30
  ecx = (u32)(6801640);  // @116_4acf30
  if ((eax & eax) != 0) ecx = eax;  // @117_4acf30
  p8_ = ecx;  // @118_4acf30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))((u32)(6884340), (u32)(p8_));  // @119_4acf30
  ecx = edx = 0;  // @120_4acf30
  if ((eax & eax) != 0) goto L4ad1d7;  // @121_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @122_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @123_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @125_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @126_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6884352), (u32)(0), (u32)(6883748), (u32)(594), (u32)(50), (u32)(0));  // @127_4acf30
  ecx = edx = 0;  // @128_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @129_4acf30
  eax = (eax & 0xffff);  // @130_4acf30
  p9_ = eax;  // @131_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, (u32)(p9_));  // @132_4acf30
  ecx = edx = 0;  // @133_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @135_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_4acf30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @137_4acf30
  ecx = edx = 0;  // @138_4acf30
  ecx = eax;  // @139_4acf30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @140_4acf30
  edx = (u32)(EBP - 288);  // @141_4acf30
  p10_ = edx;  // @142_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(6884372), (u32)(p10_));  // @144_4acf30
  ecx = edx = 0;  // @145_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @146_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @147_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; }));  // @149_4acf30
  ecx = edx = 0;  // @150_4acf30
  ecx = eax;  // @151_4acf30
  if ((ecx & ecx) == 0) goto L4ad1ab;  // @152_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @154_4acf30
  ecx = edx = 0;  // @155_4acf30
  L4ad1ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @157_4acf30
  ecx = ebx;  // @158_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @159_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050577));  // @160_4acf30
  ecx = edx = 0;  // @161_4acf30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4acfe1;  // @162_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @163_4acf30
  ecx = ebx;  // @164_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @165_4acf30
  ecx = edx = 0;  // @166_4acf30
  eax = 0;  // @167_4acf30
  goto L4ad375;  // @168_4acf30
  L4ad1d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @170_4acf30
  ecx = ebx;  // @171_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @172_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050579));  // @173_4acf30
  ecx = edx = 0;  // @174_4acf30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4ad2ca;  // @175_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @176_4acf30
  ecx = ebx;  // @177_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @178_4acf30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @179_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @180_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @181_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 708)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; }), (u32)(1230259533));  // @182_4acf30
  ecx = edx = 0;  // @183_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @184_4acf30
  p11_ = eax;  // @185_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @186_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, (u32)(p11_));  // @187_4acf30
  ecx = edx = 0;  // @188_4acf30
  edx = eax;  // @189_4acf30
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @190_4acf30
  if ((edx & edx) == 0) goto L4acfe1;  // @191_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @192_4acf30
  p12_ = edx;  // @193_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @194_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @195_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p12_));  // @196_4acf30
  ecx = edx = 0;  // @197_4acf30
  ebx = eax;  // @198_4acf30
  ecx = ebx;  // @199_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @200_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @201_4acf30
  ecx = edx = 0;  // @202_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @203_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @204_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @205_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050581));  // @206_4acf30
  ecx = edx = 0;  // @207_4acf30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4ad28d;  // @208_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @209_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @210_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @211_4acf30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 796)))(ecx);  // @212_4acf30
  ecx = edx = 0;  // @213_4acf30
  p13_ = eax;  // @214_4acf30
  ecx = ebx;  // @215_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 808)))(ecx, (u32)(p13_));  // @216_4acf30
  ecx = edx = 0;  // @217_4acf30
  goto L4ad2ca;  // @218_4acf30
  L4ad28d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @220_4acf30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @221_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @222_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @223_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @224_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @225_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(0));  // @226_4acf30
  ecx = edx = 0;  // @227_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @228_4acf30
  p14_ = eax;  // @229_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @230_4acf30
  ecx = esi;  // @231_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; }), (u32)(p14_));  // @232_4acf30
  ecx = edx = 0;  // @233_4acf30
  p15_ = eax;  // @234_4acf30
  ecx = ebx;  // @235_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, (u32)(p15_));  // @236_4acf30
  ecx = edx = 0;  // @237_4acf30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @238_4acf30
  L4ad2ca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @240_4acf30
  ecx = ebx;  // @241_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @242_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050584));  // @243_4acf30
  ecx = edx = 0;  // @244_4acf30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4ad333;  // @245_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @246_4acf30
  ecx = ebx;  // @247_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @248_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 744)))(ecx, (u32)(0));  // @249_4acf30
  ecx = edx = 0;  // @250_4acf30
  p16_ = eax;  // @251_4acf30
  ecx = edi;  // @252_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 152)))(ecx, (u32)(p16_));  // @253_4acf30
  ecx = edx = 0;  // @254_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @255_4acf30
  p17_ = eax;  // @256_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @257_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @258_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p17_));  // @259_4acf30
  ecx = edx = 0;  // @260_4acf30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @261_4acf30
  if ((eax & eax) == 0) goto L4ad333;  // @262_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @263_4acf30
  ecx = ebx;  // @264_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @265_4acf30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 800)))(ecx);  // @266_4acf30
  ecx = edx = 0;  // @267_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @268_4acf30
  p18_ = eax;  // @269_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 808)))(ecx, (u32)(p18_));  // @270_4acf30
  ecx = edx = 0;  // @271_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @272_4acf30
  goto L4ad375;  // @273_4acf30
  L4ad333:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 282), sizeof v); (u32)v; });  // @275_4acf30
  ecx = (u32)(edi + 282);  // @276_4acf30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @277_4acf30
  p19_ = esi;  // @278_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p19_));  // @279_4acf30
  ecx = edx = 0;  // @280_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @281_4acf30
  if ((edx & edx) == 0) goto L4ad373;  // @282_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @283_4acf30
  p20_ = edx;  // @284_4acf30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @285_4acf30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @286_4acf30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p20_));  // @287_4acf30
  ecx = edx = 0;  // @288_4acf30
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @289_4acf30
  p21_ = esi;  // @290_4acf30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @291_4acf30
  p22_ = ecx;  // @292_4acf30
  ecx = eax;  // @293_4acf30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(p22_), (u32)(p21_), (u32)(0));  // @294_4acf30
  ecx = edx = 0;  // @295_4acf30
  L4ad373:;
  eax = ebx;  // @297_4acf30
  L4ad375:;
  SEH_LEAVE();  // @299_4acf30
  ext_633654(G(u32, 0x6f5630));  // @300_4acf30
  return eax;  // @301_4acf30
}
PCREG(4acf30, lifted_4acf30);

extern "C" u32 THISCALL lifted_434250(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665746);  // @h_434250
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_, p35_, p36_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_434250
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 1688), &v, sizeof v); }  // @1_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @2_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1712), &v, sizeof v); }  // @5_434250
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1720), &v, sizeof v); }  // @6_434250
  if ((ecx & ecx) == 0) goto L434690;  // @7_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_434250
  edx = (u32)(EBP - 1772);  // @9_434250
  p0_ = edx;  // @10_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @11_434250
  ecx = edx = 0;  // @12_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @13_434250
  edx = (u32)(EBP - 1772);  // @14_434250
  p1_ = edx;  // @15_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @17_434250
  ecx = edx = 0;  // @18_434250
  if ((eax & eax) == 0) goto L434690;  // @19_434250
  L4342c6:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_434250
  ecx = (u32)(EBP - 1748);  // @22_434250
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1716), &v, sizeof v); }  // @23_434250
  eax = ext_4ccd10_thiscall3(ecx, (u32)(256), (u32)(0));  // @24_434250
  ecx = edx = 0;  // @25_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_434250
  ecx = (u32)(EBP - 1748);  // @27_434250
  p2_ = ecx;  // @28_434250
  ecx = esi;  // @29_434250
  reg.state = (s32)((u32)(0));  // @30_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(p2_));  // @31_434250
  ecx = edx = 0;  // @32_434250
  if ((edi & edi) != 0) goto L43430f;  // @33_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @34_434250
  if ((eax & eax) == 0) goto L434309;  // @35_434250
  eax = ((u32(STDCALL *)(void))(eax))();  // @36_434250
  ecx = edx = 0;  // @37_434250
  goto L434667;  // @38_434250
  L434309:;
  __builtin_trap();  // @40_434250
  L43430f:;
  eax = (u32)(EBP - 1760);  // @42_434250
  p3_ = eax;  // @43_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1748), sizeof v); (u32)v; });  // @44_434250
  ecx = (u32)(EBP - 1748);  // @45_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p3_));  // @46_434250
  ecx = edx = 0;  // @47_434250
  eax = (u32)(EBP - 1760);  // @48_434250
  p4_ = eax;  // @49_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1748), sizeof v); (u32)v; });  // @50_434250
  ecx = (u32)(EBP - 1748);  // @51_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @52_434250
  ecx = edx = 0;  // @53_434250
  if ((eax & eax) == 0) goto L434667;  // @54_434250
  L434343:;
  esi = edi;  // @56_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_434250
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6792424), sizeof v); (u32)v; })) & 0xffff);  // @58_434250
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 1552), &v, sizeof v); }  // @59_434250
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6792426), sizeof v); (u32)v; })) & 0xff);  // @60_434250
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1704), &v, sizeof v); }  // @61_434250
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1550), &v, sizeof v); }  // @62_434250
  L434365:;
  p5_ = esi;  // @64_434250
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676254))((u32)(p5_), (u32)(44));  // @65_434250
  ecx = edx = 0;  // @66_434250
  ebx = eax;  // @67_434250
  if ((ebx & ebx) == 0) goto L4343af;  // @68_434250
  edi = ebx;  // @69_434250
  eax = (u32)(EBP - 1550);  // @70_434250
  edi = (edi - esi);  // @71_434250
  p6_ = edi;  // @72_434250
  p7_ = esi;  // @73_434250
  p8_ = eax;  // @74_434250
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67642c))((u32)(p8_), (u32)(p7_), (u32)(p6_));  // @75_434250
  ecx = edx = 0;  // @76_434250
  edi = (edi + (u32)(2));  // @77_434250
  if (edi >= (u32)(1024)) goto L4346ae;  // @78_434250
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + edi - 1552), &v, sizeof v); }  // @79_434250
  esi = (u32)(ebx + 1);  // @80_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1704), sizeof v); (u32)v; });  // @81_434250
  goto L4343c6;  // @82_434250
  L4343af:;
  ecx = (u32)(EBP - 1550);  // @84_434250
  ecx = (ecx - esi);  // @85_434250
  L4343b7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @87_434250
  esi = (u32)(esi + 1);  // @88_434250
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi - 1), &v, sizeof v); }  // @89_434250
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4343b7;  // @90_434250
  esi = 0;  // @91_434250
  L4343c6:;
  edx = (u32)(EBP - 1552);  // @93_434250
  ecx = edi;  // @94_434250
  eax = ext_4cc850_fastcall2(ecx, edx);  // @95_434250
  ecx = edx = 0;  // @96_434250
  if ((eax & eax) == 0) goto L43463d;  // @97_434250
  if ((esi & esi) != 0) goto L434365;  // @98_434250
  if ((edi & edi) == 0) goto L43463d;  // @99_434250
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1688), sizeof v); (u32)v; });  // @100_434250
  ecx = ebx;  // @101_434250
  p9_ = edi;  // @102_434250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 1681), &v, sizeof v); }  // @103_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @104_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 304)))(ecx, (u32)(p9_));  // @105_434250
  ecx = edx = 0;  // @106_434250
  if ((eax & eax) != 0) goto L434570;  // @107_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @108_434250
  ecx = (u32)(EBP - 1680);  // @109_434250
  p10_ = edi;  // @110_434250
  p11_ = ecx;  // @111_434250
  ecx = ebx;  // @112_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 300)))(ecx, (u32)(p11_), (u32)(p10_));  // @113_434250
  ecx = edx = 0;  // @114_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @115_434250
  ecx = (u32)(EBP - 1680);  // @116_434250
  reg.state = (s32)((u32)(1));  // @117_434250
  eax = ext_4cc1d0_cdecl1((u32)(1));  // @118_434250
  ecx = edx = 0;  // @119_434250
  p12_ = eax;  // @120_434250
  ecx = ebx;  // @121_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(p12_));  // @122_434250
  ecx = edx = 0;  // @123_434250
  ebx = eax;  // @124_434250
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 1696), &v, sizeof v); }  // @125_434250
  if (ebx == (u32)(-1)) goto L43453d;  // @126_434250
  p13_ = ebx;  // @127_434250
  eax = ext_41e290_cdecl1((u32)(p13_));  // @128_434250
  ecx = edx = 0;  // @129_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1688), sizeof v); (u32)v; });  // @130_434250
  ecx = (u32)(EBP - 1680);  // @131_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1708), &v, sizeof v); }  // @132_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @133_434250
  p14_ = ebx;  // @134_434250
  p15_ = eax;  // @135_434250
  eax = ext_4cc1d0_cdecl4((u32)(p15_), (u32)(p14_), (u32)(0), (u32)(1));  // @136_434250
  ecx = edx = 0;  // @137_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1688), sizeof v); (u32)v; });  // @138_434250
  p16_ = eax;  // @139_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 96)))(ecx, (u32)(p16_));  // @140_434250
  ecx = edx = 0;  // @141_434250
  if (ebx != eax) goto L43452a;  // @142_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1712), sizeof v); (u32)v; });  // @143_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(1));  // @145_434250
  ecx = edx = 0;  // @146_434250
  edx = edi;  // @147_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1700), &v, sizeof v); }  // @148_434250
  esi = (u32)(edx + 1);  // @149_434250
  L434495:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @151_434250
  edx = (edx + 1);  // @152_434250
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L434495;  // @153_434250
  edx = (edx - esi);  // @154_434250
  esi = 0;  // @155_434250
  eax = (u32)(edx + 1);  // @156_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1692), &v, sizeof v); }  // @157_434250
  if ((eax & eax) == 0) goto L4344eb;  // @158_434250
  ebx = edi;  // @159_434250
  eax = (u32)(EBP - 528);  // @160_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1692), sizeof v); (u32)v; });  // @161_434250
  ebx = (ebx - eax);  // @162_434250
  L4344c0:;
  edx = (u32)(EBP - 528);  // @164_434250
  eax = (u32)(92);  // @165_434250
  edx = (edx + esi);  // @166_434250
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx), sizeof v); (u32)v; });  // @167_434250
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx), sizeof v); (u32)v; }) == (u32)(47)) ecx = eax;  // @168_434250
  esi = (esi + 1);  // @169_434250
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @170_434250
  if (esi != edi) goto L4344c0;  // @171_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1704), sizeof v); (u32)v; });  // @172_434250
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1696), sizeof v); (u32)v; });  // @173_434250
  L4344eb:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1700), sizeof v); (u32)v; });  // @175_434250
  ecx = (u32)(EBP - 528);  // @176_434250
  p17_ = ecx;  // @177_434250
  ecx = esi;  // @178_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(p17_));  // @180_434250
  ecx = edx = 0;  // @181_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @182_434250
  ecx = esi;  // @183_434250
  p18_ = ebx;  // @184_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p18_));  // @185_434250
  ecx = edx = 0;  // @186_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1708), sizeof v); (u32)v; });  // @187_434250
  ecx = eax;  // @188_434250
  p19_ = ebx;  // @189_434250
  p20_ = esi;  // @190_434250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @191_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 28)))(ecx, (u32)(p20_), (u32)(p19_));  // @192_434250
  ecx = edx = 0;  // @193_434250
  p21_ = esi;  // @194_434250
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1681), &v, sizeof v); }  // @195_434250
  eax = ext_634273_cdecl2((u32)(p21_), (u32)(1));  // @196_434250
  ecx = edx = 0;  // @197_434250
  goto L434561;  // @198_434250
  L43452a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1708), sizeof v); (u32)v; });  // @200_434250
  p22_ = esi;  // @201_434250
  eax = ext_634273_cdecl2((u32)(p22_), (u32)(1));  // @202_434250
  ecx = edx = 0;  // @203_434250
  goto L434561;  // @204_434250
  L43453d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @206_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6792428), (u32)(273));  // @208_434250
  ecx = edx = 0;  // @209_434250
  p23_ = edi;  // @210_434250
  p24_ = eax;  // @211_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @212_434250
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p24_), (u32)(6792472), (u32)(p23_));  // @213_434250
  ecx = edx = 0;  // @214_434250
  L434561:;
  ecx = (u32)(EBP - 1680);  // @216_434250
  reg.state = (s32)((u32)(0));  // @217_434250
  eax = ext_4cbec0_thiscall1(ecx);  // @218_434250
  ecx = edx = 0;  // @219_434250
  L434570:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1681), sizeof v); (u32)v; }) == (u32)(0)) goto L43463d;  // @221_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1716), sizeof v); (u32)v; });  // @222_434250
  ecx = esi;  // @223_434250
  p25_ = edi;  // @224_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @225_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 16)))(ecx, (u32)(p25_));  // @226_434250
  ecx = edx = 0;  // @227_434250
  ebx = eax;  // @228_434250
  p26_ = ebx;  // @229_434250
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 1696), &v, sizeof v); }  // @230_434250
  eax = ext_41e290_cdecl1((u32)(p26_));  // @231_434250
  ecx = edx = 0;  // @232_434250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @233_434250
  ecx = esi;  // @234_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1692), &v, sizeof v); }  // @235_434250
  p27_ = ebx;  // @236_434250
  p28_ = eax;  // @237_434250
  p29_ = edi;  // @238_434250
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 28)))(ecx, (u32)(p29_), (u32)(p28_), (u32)(p27_), (u32)(0));  // @239_434250
  ecx = edx = 0;  // @240_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1712), sizeof v); (u32)v; });  // @241_434250
  ecx = eax;  // @242_434250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @243_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(1));  // @244_434250
  ecx = edx = 0;  // @245_434250
  edx = edi;  // @246_434250
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1700), &v, sizeof v); }  // @247_434250
  eax = (u32)(edx + 1);  // @248_434250
  L4345c8:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @250_434250
  edx = (edx + 1);  // @251_434250
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L4345c8;  // @252_434250
  edx = (edx - eax);  // @253_434250
  esi = 0;  // @254_434250
  ebx = (u32)(edx + 1);  // @255_434250
  if ((ebx & ebx) == 0) goto L434601;  // @256_434250
  eax = (u32)(EBP - 528);  // @257_434250
  edi = (edi - eax);  // @258_434250
  L4345e2:;
  edx = (u32)(EBP - 528);  // @260_434250
  eax = (u32)(92);  // @261_434250
  edx = (edx + esi);  // @262_434250
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx), sizeof v); (u32)v; });  // @263_434250
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx), sizeof v); (u32)v; }) == (u32)(47)) ecx = eax;  // @264_434250
  esi = (esi + 1);  // @265_434250
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @266_434250
  if (esi != ebx) goto L4345e2;  // @267_434250
  L434601:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1700), sizeof v); (u32)v; });  // @269_434250
  ecx = (u32)(EBP - 528);  // @270_434250
  p30_ = ecx;  // @271_434250
  ecx = ebx;  // @272_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @273_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(p30_));  // @274_434250
  ecx = edx = 0;  // @275_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @276_434250
  ecx = ebx;  // @277_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1696), sizeof v); (u32)v; });  // @278_434250
  p31_ = esi;  // @279_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p31_));  // @280_434250
  ecx = edx = 0;  // @281_434250
  p32_ = esi;  // @282_434250
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1692), sizeof v); (u32)v; });  // @283_434250
  ecx = eax;  // @284_434250
  p33_ = esi;  // @285_434250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @286_434250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 28)))(ecx, (u32)(p33_), (u32)(p32_));  // @287_434250
  ecx = edx = 0;  // @288_434250
  p34_ = esi;  // @289_434250
  eax = ext_634273_cdecl2((u32)(p34_), (u32)(1));  // @290_434250
  ecx = edx = 0;  // @291_434250
  L43463d:;
  eax = (u32)(EBP - 1760);  // @293_434250
  p35_ = eax;  // @294_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1748), sizeof v); (u32)v; });  // @295_434250
  ecx = (u32)(EBP - 1748);  // @296_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p35_));  // @297_434250
  ecx = edx = 0;  // @298_434250
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1720), sizeof v); (u32)v; });  // @299_434250
  if ((eax & eax) != 0) goto L434343;  // @300_434250
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1688), sizeof v); (u32)v; });  // @301_434250
  L434667:;
  ecx = (u32)(EBP - 1748);  // @303_434250
  reg.state = (s32)((u32)(4294967295));  // @304_434250
  eax = ext_4cd0e0_thiscall1(ecx);  // @305_434250
  ecx = edx = 0;  // @306_434250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @307_434250
  edx = (u32)(EBP - 1772);  // @308_434250
  p36_ = edx;  // @309_434250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @310_434250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p36_));  // @311_434250
  ecx = edx = 0;  // @312_434250
  if ((eax & eax) != 0) goto L4342c6;  // @313_434250
  L434690:;
  SEH_LEAVE();  // @315_434250
  ext_633654(G(u32, 0x6f5630));  // @316_434250
  return eax;  // @317_434250
  L4346ae:;
  eax = ext_634047_cdecl0();  // @319_434250
  ecx = edx = 0;  // @320_434250
}
PCREG(434250, lifted_434250);

extern "C" u32 THISCALL lifted_5a6980(u32 ecx_in) {
  SEH_ENTER(0x66c176);  // @h_5a6980
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_, p35_, p36_, p37_, p38_, p39_, p40_, p41_, p42_, p43_, p44_, p45_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5a6980
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @1_5a6980
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1624), sizeof v); (u32)v; }) != (u32)(0)) goto L5a6af7;  // @2_5a6980
  eax = ext_41e290_cdecl1((u32)(247));  // @3_5a6980
  ecx = edx = 0;  // @4_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @5_5a6980
  reg.state = (s32)((u32)(0));  // @6_5a6980
  if ((eax & eax) == 0) goto L5a69ea;  // @7_5a6980
  ecx = eax;  // @8_5a6980
  eax = ext_5ed460_thiscall1(ecx);  // @9_5a6980
  ecx = edx = 0;  // @10_5a6980
  goto L5a69ec;  // @11_5a6980
  L5a69ea:;
  eax = 0;  // @13_5a6980
  L5a69ec:;
  esi = (u32)(edi + 1625);  // @15_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1080), &v, sizeof v); }  // @16_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @17_5a6980
  reg.state = (s32)((u32)(4294967295));  // @18_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @19_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6a19;  // @20_5a6980
  if ((ecx & ecx) == 0) goto L5a6a13;  // @21_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @22_5a6980
  L5a6a13:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @24_5a6980
  goto L5a6a28;  // @25_5a6980
  L5a6a19:;
  eax = (u32)(EBP - 136);  // @27_5a6980
  p0_ = eax;  // @28_5a6980
  p1_ = ecx;  // @29_5a6980
  ecx = esi;  // @30_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p1_), (u32)(p0_));  // @31_5a6980
  ecx = edx = 0;  // @32_5a6980
  L5a6a28:;
  eax = ext_41e290_cdecl1((u32)(215));  // @34_5a6980
  ecx = edx = 0;  // @35_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @36_5a6980
  reg.state = (s32)((u32)(1));  // @37_5a6980
  if ((eax & eax) == 0) goto L5a6a51;  // @38_5a6980
  ecx = eax;  // @39_5a6980
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @40_5a6980
  ecx = edx = 0;  // @41_5a6980
  goto L5a6a53;  // @42_5a6980
  L5a6a51:;
  eax = 0;  // @44_5a6980
  L5a6a53:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1084), &v, sizeof v); }  // @46_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @47_5a6980
  reg.state = (s32)((u32)(4294967295));  // @48_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @49_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6a7a;  // @50_5a6980
  if ((ecx & ecx) == 0) goto L5a6a74;  // @51_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @52_5a6980
  L5a6a74:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @54_5a6980
  goto L5a6a89;  // @55_5a6980
  L5a6a7a:;
  eax = (u32)(EBP - 136);  // @57_5a6980
  p2_ = eax;  // @58_5a6980
  p3_ = ecx;  // @59_5a6980
  ecx = esi;  // @60_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p3_), (u32)(p2_));  // @61_5a6980
  ecx = edx = 0;  // @62_5a6980
  L5a6a89:;
  eax = ext_41e290_cdecl1((u32)(132));  // @64_5a6980
  ecx = edx = 0;  // @65_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @66_5a6980
  reg.state = (s32)((u32)(2));  // @67_5a6980
  if ((eax & eax) == 0) goto L5a6ab2;  // @68_5a6980
  ecx = eax;  // @69_5a6980
  eax = ext_5edd80_thiscall2(ecx, (u32)(3));  // @70_5a6980
  ecx = edx = 0;  // @71_5a6980
  goto L5a6ab4;  // @72_5a6980
  L5a6ab2:;
  eax = 0;  // @74_5a6980
  L5a6ab4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1592), &v, sizeof v); }  // @76_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @77_5a6980
  reg.state = (s32)((u32)(4294967295));  // @78_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @79_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6adb;  // @80_5a6980
  if ((ecx & ecx) == 0) goto L5a6ad5;  // @81_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @82_5a6980
  L5a6ad5:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @84_5a6980
  goto L5a6aea;  // @85_5a6980
  L5a6adb:;
  eax = (u32)(EBP - 136);  // @87_5a6980
  p4_ = eax;  // @88_5a6980
  p5_ = ecx;  // @89_5a6980
  ecx = esi;  // @90_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p5_), (u32)(p4_));  // @91_5a6980
  ecx = edx = 0;  // @92_5a6980
  L5a6aea:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1624), sizeof v); (u32)v; }) == (u32)(0)) goto L5a6c1c;  // @94_5a6980
  L5a6af7:;
  eax = ext_41e290_cdecl1((u32)(132));  // @96_5a6980
  ecx = edx = 0;  // @97_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @98_5a6980
  reg.state = (s32)((u32)(3));  // @99_5a6980
  if ((eax & eax) == 0) goto L5a6b20;  // @100_5a6980
  ecx = eax;  // @101_5a6980
  eax = ext_5edd80_thiscall2(ecx, (u32)(1));  // @102_5a6980
  ecx = edx = 0;  // @103_5a6980
  goto L5a6b22;  // @104_5a6980
  L5a6b20:;
  eax = 0;  // @106_5a6980
  L5a6b22:;
  esi = (u32)(edi + 1637);  // @108_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1596), &v, sizeof v); }  // @109_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @110_5a6980
  reg.state = (s32)((u32)(4294967295));  // @111_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @112_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6b4f;  // @113_5a6980
  if ((ecx & ecx) == 0) goto L5a6b49;  // @114_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @115_5a6980
  L5a6b49:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @117_5a6980
  goto L5a6b5e;  // @118_5a6980
  L5a6b4f:;
  eax = (u32)(EBP - 136);  // @120_5a6980
  p6_ = eax;  // @121_5a6980
  p7_ = ecx;  // @122_5a6980
  ecx = esi;  // @123_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p7_), (u32)(p6_));  // @124_5a6980
  ecx = edx = 0;  // @125_5a6980
  L5a6b5e:;
  eax = ext_41e290_cdecl1((u32)(219));  // @127_5a6980
  ecx = edx = 0;  // @128_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @129_5a6980
  reg.state = (s32)((u32)(4));  // @130_5a6980
  if ((eax & eax) == 0) goto L5a6b85;  // @131_5a6980
  ecx = eax;  // @132_5a6980
  eax = ext_5f0020_thiscall1(ecx);  // @133_5a6980
  ecx = edx = 0;  // @134_5a6980
  goto L5a6b87;  // @135_5a6980
  L5a6b85:;
  eax = 0;  // @137_5a6980
  L5a6b87:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2215), &v, sizeof v); }  // @139_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @140_5a6980
  reg.state = (s32)((u32)(4294967295));  // @141_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @142_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6bae;  // @143_5a6980
  if ((ecx & ecx) == 0) goto L5a6ba8;  // @144_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @145_5a6980
  L5a6ba8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @147_5a6980
  goto L5a6bbd;  // @148_5a6980
  L5a6bae:;
  eax = (u32)(EBP - 136);  // @150_5a6980
  p8_ = eax;  // @151_5a6980
  p9_ = ecx;  // @152_5a6980
  ecx = esi;  // @153_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p9_), (u32)(p8_));  // @154_5a6980
  ecx = edx = 0;  // @155_5a6980
  L5a6bbd:;
  eax = ext_41e290_cdecl1((u32)(219));  // @157_5a6980
  ecx = edx = 0;  // @158_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @159_5a6980
  reg.state = (s32)((u32)(5));  // @160_5a6980
  if ((eax & eax) == 0) goto L5a6be4;  // @161_5a6980
  ecx = eax;  // @162_5a6980
  eax = ext_5f0020_thiscall1(ecx);  // @163_5a6980
  ecx = edx = 0;  // @164_5a6980
  goto L5a6be6;  // @165_5a6980
  L5a6be4:;
  eax = 0;  // @167_5a6980
  L5a6be6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2219), &v, sizeof v); }  // @169_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @170_5a6980
  reg.state = (s32)((u32)(4294967295));  // @171_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @172_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6c0d;  // @173_5a6980
  if ((ecx & ecx) == 0) goto L5a6c07;  // @174_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @175_5a6980
  L5a6c07:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @177_5a6980
  goto L5a6c1c;  // @178_5a6980
  L5a6c0d:;
  eax = (u32)(EBP - 136);  // @180_5a6980
  p10_ = eax;  // @181_5a6980
  p11_ = ecx;  // @182_5a6980
  ecx = esi;  // @183_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p11_), (u32)(p10_));  // @184_5a6980
  ecx = edx = 0;  // @185_5a6980
  L5a6c1c:;
  eax = (u32)(edi + 1076);  // @187_5a6980
  ebx = 0;  // @188_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @189_5a6980
  esi = (u32)(edi + 1649);  // @190_5a6980
  eax = (u32)(edi + 1144);  // @191_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @192_5a6980
  eax = (u32)(edi + 1196);  // @193_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @194_5a6980
  eax = (u32)(edi + 1192);  // @195_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @196_5a6980
  eax = (u32)(edi + 1188);  // @197_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @198_5a6980
  eax = (u32)(edi + 1184);  // @199_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @200_5a6980
  eax = (u32)(edi + 1180);  // @201_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @202_5a6980
  eax = (u32)(edi + 1176);  // @203_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @204_5a6980
  eax = (u32)(edi + 1172);  // @205_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @206_5a6980
  eax = (u32)(edi + 1168);  // @207_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @208_5a6980
  eax = (u32)(edi + 1164);  // @209_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @210_5a6980
  eax = (u32)(edi + 1152);  // @211_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @212_5a6980
  eax = (u32)(edi + 1156);  // @213_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @214_5a6980
  eax = (u32)(edi + 1160);  // @215_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @216_5a6980
  eax = (u32)(edi + 1200);  // @217_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @218_5a6980
  eax = (u32)(edi + 1204);  // @219_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @220_5a6980
  eax = (u32)(edi + 1673);  // @221_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @222_5a6980
  eax = (u32)(edi + 1072);  // @223_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @224_5a6980
  eax = (u32)(edi + 1528);  // @225_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @226_5a6980
  eax = (u32)(edi + 1532);  // @227_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @228_5a6980
  eax = (u32)(edi + 1536);  // @229_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @230_5a6980
  eax = (u32)(edi + 1540);  // @231_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @232_5a6980
  eax = (u32)(edi + 1544);  // @233_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @234_5a6980
  eax = (u32)(edi + 1548);  // @235_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @236_5a6980
  eax = (u32)(edi + 1552);  // @237_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @238_5a6980
  eax = (u32)(edi + 1556);  // @239_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @240_5a6980
  eax = (u32)(edi + 1560);  // @241_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @242_5a6980
  eax = (u32)(edi + 1568);  // @243_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @244_5a6980
  eax = (u32)(edi + 1564);  // @245_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @246_5a6980
  L5a6d30:;
  eax = ext_41e290_cdecl1((u32)(215));  // @248_5a6980
  ecx = edx = 0;  // @249_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @250_5a6980
  reg.state = (s32)((u32)(6));  // @251_5a6980
  if ((eax & eax) == 0) goto L5a6d5b;  // @252_5a6980
  ecx = eax;  // @253_5a6980
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @254_5a6980
  ecx = edx = 0;  // @255_5a6980
  ecx = eax;  // @256_5a6980
  goto L5a6d5d;  // @257_5a6980
  L5a6d5b:;
  ecx = 0;  // @259_5a6980
  L5a6d5d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 132), sizeof v); (u32)v; });  // @261_5a6980
  reg.state = (s32)((u32)(4294967295));  // @262_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @263_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @264_5a6980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @265_5a6980
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6d87;  // @266_5a6980
  if ((eax & eax) == 0) goto L5a6d81;  // @267_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @268_5a6980
  L5a6d81:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @270_5a6980
  goto L5a6d96;  // @271_5a6980
  L5a6d87:;
  ecx = (u32)(EBP - 136);  // @273_5a6980
  p12_ = ecx;  // @274_5a6980
  p13_ = eax;  // @275_5a6980
  ecx = esi;  // @276_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p13_), (u32)(p12_));  // @277_5a6980
  ecx = edx = 0;  // @278_5a6980
  L5a6d96:;
  ebx = (ebx + 1);  // @280_5a6980
  if (ebx < (u32)(18)) goto L5a6d30;  // @281_5a6980
  ebx = 0;  // @282_5a6980
  L5a6da0:;
  eax = ext_41e290_cdecl1((u32)(167));  // @284_5a6980
  ecx = edx = 0;  // @285_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @286_5a6980
  reg.state = (s32)((u32)(7));  // @287_5a6980
  if ((eax & eax) == 0) goto L5a6dcb;  // @288_5a6980
  ecx = eax;  // @289_5a6980
  eax = ext_5ebae0_thiscall2(ecx, (u32)(12));  // @290_5a6980
  ecx = edx = 0;  // @291_5a6980
  ecx = eax;  // @292_5a6980
  goto L5a6dcd;  // @293_5a6980
  L5a6dcb:;
  ecx = 0;  // @295_5a6980
  L5a6dcd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 60), sizeof v); (u32)v; });  // @297_5a6980
  reg.state = (s32)((u32)(4294967295));  // @298_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @299_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @300_5a6980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @301_5a6980
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6df4;  // @302_5a6980
  if ((eax & eax) == 0) goto L5a6dee;  // @303_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @304_5a6980
  L5a6dee:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @306_5a6980
  goto L5a6e03;  // @307_5a6980
  L5a6df4:;
  ecx = (u32)(EBP - 136);  // @309_5a6980
  p14_ = ecx;  // @310_5a6980
  p15_ = eax;  // @311_5a6980
  ecx = esi;  // @312_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p15_), (u32)(p14_));  // @313_5a6980
  ecx = edx = 0;  // @314_5a6980
  L5a6e03:;
  ebx = (ebx + 1);  // @316_5a6980
  if (ebx < (u32)(11)) goto L5a6da0;  // @317_5a6980
  eax = ext_41e290_cdecl1((u32)(167));  // @318_5a6980
  ecx = edx = 0;  // @319_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @320_5a6980
  reg.state = (s32)((u32)(8));  // @321_5a6980
  if ((eax & eax) == 0) goto L5a6e35;  // @322_5a6980
  ecx = eax;  // @323_5a6980
  eax = ext_5ebae0_thiscall2(ecx, (u32)(256));  // @324_5a6980
  ecx = edx = 0;  // @325_5a6980
  goto L5a6e37;  // @326_5a6980
  L5a6e35:;
  eax = 0;  // @328_5a6980
  L5a6e37:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1572), &v, sizeof v); }  // @330_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @331_5a6980
  reg.state = (s32)((u32)(4294967295));  // @332_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @333_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6e5e;  // @334_5a6980
  if ((ecx & ecx) == 0) goto L5a6e58;  // @335_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @336_5a6980
  L5a6e58:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @338_5a6980
  goto L5a6e6d;  // @339_5a6980
  L5a6e5e:;
  eax = (u32)(EBP - 136);  // @341_5a6980
  p16_ = eax;  // @342_5a6980
  p17_ = ecx;  // @343_5a6980
  ecx = esi;  // @344_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p17_), (u32)(p16_));  // @345_5a6980
  ecx = edx = 0;  // @346_5a6980
  L5a6e6d:;
  ebx = (u32)(edi + 1088);  // @348_5a6980
  edi = (u32)(12);  // @349_5a6980
  L5a6e80:;
  eax = ext_41e290_cdecl1((u32)(215));  // @351_5a6980
  ecx = edx = 0;  // @352_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @353_5a6980
  reg.state = (s32)((u32)(9));  // @354_5a6980
  if ((eax & eax) == 0) goto L5a6ea9;  // @355_5a6980
  ecx = eax;  // @356_5a6980
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @357_5a6980
  ecx = edx = 0;  // @358_5a6980
  goto L5a6eab;  // @359_5a6980
  L5a6ea9:;
  eax = 0;  // @361_5a6980
  L5a6eab:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @363_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @364_5a6980
  reg.state = (s32)((u32)(4294967295));  // @365_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @366_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6ece;  // @367_5a6980
  if ((ecx & ecx) == 0) goto L5a6ec8;  // @368_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @369_5a6980
  L5a6ec8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @371_5a6980
  goto L5a6edd;  // @372_5a6980
  L5a6ece:;
  eax = (u32)(EBP - 136);  // @374_5a6980
  p18_ = eax;  // @375_5a6980
  p19_ = ecx;  // @376_5a6980
  ecx = esi;  // @377_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p19_), (u32)(p18_));  // @378_5a6980
  ecx = edx = 0;  // @379_5a6980
  L5a6edd:;
  ebx = (ebx + (u32)(4));  // @381_5a6980
  edi = (edi - (u32)(1));  // @382_5a6980
  if (edi != 0) goto L5a6e80;  // @383_5a6980
  eax = ext_41e290_cdecl1((u32)(247));  // @384_5a6980
  ecx = edx = 0;  // @385_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @386_5a6980
  reg.state = (s32)((u32)(10));  // @387_5a6980
  if ((eax & eax) == 0) goto L5a6f0c;  // @388_5a6980
  ecx = eax;  // @389_5a6980
  eax = ext_5ed460_thiscall1(ecx);  // @390_5a6980
  ecx = edx = 0;  // @391_5a6980
  goto L5a6f0e;  // @392_5a6980
  L5a6f0c:;
  eax = 0;  // @394_5a6980
  L5a6f0e:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @396_5a6980
  reg.state = (s32)((u32)(4294967295));  // @397_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @398_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1136), &v, sizeof v); }  // @399_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @400_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6f3b;  // @401_5a6980
  if ((ecx & ecx) == 0) goto L5a6f35;  // @402_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @403_5a6980
  L5a6f35:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @405_5a6980
  goto L5a6f4a;  // @406_5a6980
  L5a6f3b:;
  eax = (u32)(EBP - 136);  // @408_5a6980
  p20_ = eax;  // @409_5a6980
  p21_ = ecx;  // @410_5a6980
  ecx = esi;  // @411_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p21_), (u32)(p20_));  // @412_5a6980
  ecx = edx = 0;  // @413_5a6980
  L5a6f4a:;
  eax = ext_41e290_cdecl1((u32)(168));  // @415_5a6980
  ecx = edx = 0;  // @416_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @417_5a6980
  reg.state = (s32)((u32)(11));  // @418_5a6980
  if ((eax & eax) == 0) goto L5a6f73;  // @419_5a6980
  ecx = eax;  // @420_5a6980
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(1));  // @421_5a6980
  ecx = edx = 0;  // @422_5a6980
  goto L5a6f75;  // @423_5a6980
  L5a6f73:;
  eax = 0;  // @425_5a6980
  L5a6f75:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1600), &v, sizeof v); }  // @427_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @428_5a6980
  reg.state = (s32)((u32)(4294967295));  // @429_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @430_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6f9c;  // @431_5a6980
  if ((ecx & ecx) == 0) goto L5a6f96;  // @432_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @433_5a6980
  L5a6f96:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @435_5a6980
  goto L5a6fab;  // @436_5a6980
  L5a6f9c:;
  eax = (u32)(EBP - 136);  // @438_5a6980
  p22_ = eax;  // @439_5a6980
  p23_ = ecx;  // @440_5a6980
  ecx = esi;  // @441_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p23_), (u32)(p22_));  // @442_5a6980
  ecx = edx = 0;  // @443_5a6980
  L5a6fab:;
  eax = ext_41e290_cdecl1((u32)(168));  // @445_5a6980
  ecx = edx = 0;  // @446_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @447_5a6980
  reg.state = (s32)((u32)(12));  // @448_5a6980
  if ((eax & eax) == 0) goto L5a6fd4;  // @449_5a6980
  ecx = eax;  // @450_5a6980
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(6));  // @451_5a6980
  ecx = edx = 0;  // @452_5a6980
  goto L5a6fd6;  // @453_5a6980
  L5a6fd4:;
  eax = 0;  // @455_5a6980
  L5a6fd6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1604), &v, sizeof v); }  // @457_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @458_5a6980
  reg.state = (s32)((u32)(4294967295));  // @459_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @460_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a6ffd;  // @461_5a6980
  if ((ecx & ecx) == 0) goto L5a6ff7;  // @462_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @463_5a6980
  L5a6ff7:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @465_5a6980
  goto L5a700c;  // @466_5a6980
  L5a6ffd:;
  eax = (u32)(EBP - 136);  // @468_5a6980
  p24_ = eax;  // @469_5a6980
  p25_ = ecx;  // @470_5a6980
  ecx = esi;  // @471_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p25_), (u32)(p24_));  // @472_5a6980
  ecx = edx = 0;  // @473_5a6980
  L5a700c:;
  eax = ext_41e290_cdecl1((u32)(168));  // @475_5a6980
  ecx = edx = 0;  // @476_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @477_5a6980
  reg.state = (s32)((u32)(13));  // @478_5a6980
  if ((eax & eax) == 0) goto L5a7035;  // @479_5a6980
  ecx = eax;  // @480_5a6980
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(1));  // @481_5a6980
  ecx = edx = 0;  // @482_5a6980
  goto L5a7037;  // @483_5a6980
  L5a7035:;
  eax = 0;  // @485_5a6980
  L5a7037:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1608), &v, sizeof v); }  // @487_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @488_5a6980
  reg.state = (s32)((u32)(4294967295));  // @489_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @490_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a705e;  // @491_5a6980
  if ((ecx & ecx) == 0) goto L5a7058;  // @492_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @493_5a6980
  L5a7058:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @495_5a6980
  goto L5a706d;  // @496_5a6980
  L5a705e:;
  eax = (u32)(EBP - 136);  // @498_5a6980
  p26_ = eax;  // @499_5a6980
  p27_ = ecx;  // @500_5a6980
  ecx = esi;  // @501_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p27_), (u32)(p26_));  // @502_5a6980
  ecx = edx = 0;  // @503_5a6980
  L5a706d:;
  eax = ext_41e290_cdecl1((u32)(33));  // @505_5a6980
  ecx = edx = 0;  // @506_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @507_5a6980
  reg.state = (s32)((u32)(14));  // @508_5a6980
  if ((eax & eax) == 0) goto L5a7091;  // @509_5a6980
  ecx = eax;  // @510_5a6980
  eax = ext_5eec40_thiscall1(ecx);  // @511_5a6980
  ecx = edx = 0;  // @512_5a6980
  goto L5a7093;  // @513_5a6980
  L5a7091:;
  eax = 0;  // @515_5a6980
  L5a7093:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1580), &v, sizeof v); }  // @517_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @518_5a6980
  reg.state = (s32)((u32)(4294967295));  // @519_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @520_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a70ba;  // @521_5a6980
  if ((ecx & ecx) == 0) goto L5a70b4;  // @522_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @523_5a6980
  L5a70b4:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @525_5a6980
  goto L5a70c9;  // @526_5a6980
  L5a70ba:;
  eax = (u32)(EBP - 136);  // @528_5a6980
  p28_ = eax;  // @529_5a6980
  p29_ = ecx;  // @530_5a6980
  ecx = esi;  // @531_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p29_), (u32)(p28_));  // @532_5a6980
  ecx = edx = 0;  // @533_5a6980
  L5a70c9:;
  eax = ext_41e290_cdecl1((u32)(247));  // @535_5a6980
  ecx = edx = 0;  // @536_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @537_5a6980
  reg.state = (s32)((u32)(15));  // @538_5a6980
  if ((eax & eax) == 0) goto L5a70f0;  // @539_5a6980
  ecx = eax;  // @540_5a6980
  eax = ext_5ed460_thiscall1(ecx);  // @541_5a6980
  ecx = edx = 0;  // @542_5a6980
  goto L5a70f2;  // @543_5a6980
  L5a70f0:;
  eax = 0;  // @545_5a6980
  L5a70f2:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1576), &v, sizeof v); }  // @547_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @548_5a6980
  reg.state = (s32)((u32)(4294967295));  // @549_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @550_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a7119;  // @551_5a6980
  if ((ecx & ecx) == 0) goto L5a7113;  // @552_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @553_5a6980
  L5a7113:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @555_5a6980
  goto L5a7128;  // @556_5a6980
  L5a7119:;
  eax = (u32)(EBP - 136);  // @558_5a6980
  p30_ = eax;  // @559_5a6980
  p31_ = ecx;  // @560_5a6980
  ecx = esi;  // @561_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p31_), (u32)(p30_));  // @562_5a6980
  ecx = edx = 0;  // @563_5a6980
  L5a7128:;
  eax = ext_41e290_cdecl1((u32)(247));  // @565_5a6980
  ecx = edx = 0;  // @566_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @567_5a6980
  reg.state = (s32)((u32)(16));  // @568_5a6980
  if ((eax & eax) == 0) goto L5a714f;  // @569_5a6980
  ecx = eax;  // @570_5a6980
  eax = ext_5ed460_thiscall1(ecx);  // @571_5a6980
  ecx = edx = 0;  // @572_5a6980
  goto L5a7151;  // @573_5a6980
  L5a714f:;
  eax = 0;  // @575_5a6980
  L5a7151:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1140), &v, sizeof v); }  // @577_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @578_5a6980
  reg.state = (s32)((u32)(4294967295));  // @579_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @580_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a7178;  // @581_5a6980
  if ((ecx & ecx) == 0) goto L5a7172;  // @582_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @583_5a6980
  L5a7172:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @585_5a6980
  goto L5a7187;  // @586_5a6980
  L5a7178:;
  eax = (u32)(EBP - 136);  // @588_5a6980
  p32_ = eax;  // @589_5a6980
  p33_ = ecx;  // @590_5a6980
  ecx = esi;  // @591_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p33_), (u32)(p32_));  // @592_5a6980
  ecx = edx = 0;  // @593_5a6980
  L5a7187:;
  eax = ext_41e290_cdecl1((u32)(153));  // @595_5a6980
  ecx = edx = 0;  // @596_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @597_5a6980
  reg.state = (s32)((u32)(17));  // @598_5a6980
  if ((eax & eax) == 0) goto L5a71ae;  // @599_5a6980
  ecx = eax;  // @600_5a6980
  eax = ext_5efd10_thiscall1(ecx);  // @601_5a6980
  ecx = edx = 0;  // @602_5a6980
  goto L5a71b0;  // @603_5a6980
  L5a71ae:;
  eax = 0;  // @605_5a6980
  L5a71b0:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1588), &v, sizeof v); }  // @607_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @608_5a6980
  reg.state = (s32)((u32)(4294967295));  // @609_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @610_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a71d7;  // @611_5a6980
  if ((ecx & ecx) == 0) goto L5a71d1;  // @612_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @613_5a6980
  L5a71d1:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @615_5a6980
  goto L5a71e6;  // @616_5a6980
  L5a71d7:;
  eax = (u32)(EBP - 136);  // @618_5a6980
  p34_ = eax;  // @619_5a6980
  p35_ = ecx;  // @620_5a6980
  ecx = esi;  // @621_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p35_), (u32)(p34_));  // @622_5a6980
  ecx = edx = 0;  // @623_5a6980
  L5a71e6:;
  eax = ext_41e290_cdecl1((u32)(168));  // @625_5a6980
  ecx = edx = 0;  // @626_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @627_5a6980
  reg.state = (s32)((u32)(18));  // @628_5a6980
  if ((eax & eax) == 0) goto L5a720f;  // @629_5a6980
  ecx = eax;  // @630_5a6980
  eax = ext_5ab2e0_thiscall2(ecx, (u32)(3));  // @631_5a6980
  ecx = edx = 0;  // @632_5a6980
  goto L5a7211;  // @633_5a6980
  L5a720f:;
  eax = 0;  // @635_5a6980
  L5a7211:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1584), &v, sizeof v); }  // @637_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @638_5a6980
  reg.state = (s32)((u32)(4294967295));  // @639_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @640_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a7238;  // @641_5a6980
  if ((ecx & ecx) == 0) goto L5a7232;  // @642_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @643_5a6980
  L5a7232:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @645_5a6980
  goto L5a7247;  // @646_5a6980
  L5a7238:;
  eax = (u32)(EBP - 136);  // @648_5a6980
  p36_ = eax;  // @649_5a6980
  p37_ = ecx;  // @650_5a6980
  ecx = esi;  // @651_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p37_), (u32)(p36_));  // @652_5a6980
  ecx = edx = 0;  // @653_5a6980
  L5a7247:;
  eax = ext_41e290_cdecl1((u32)(199));  // @655_5a6980
  ecx = edx = 0;  // @656_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @657_5a6980
  reg.state = (s32)((u32)(19));  // @658_5a6980
  if ((eax & eax) == 0) goto L5a726e;  // @659_5a6980
  ecx = eax;  // @660_5a6980
  eax = ext_5ef080_thiscall1(ecx);  // @661_5a6980
  ecx = edx = 0;  // @662_5a6980
  goto L5a7270;  // @663_5a6980
  L5a726e:;
  eax = 0;  // @665_5a6980
  L5a7270:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @667_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @668_5a6980
  reg.state = (s32)((u32)(4294967295));  // @669_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @670_5a6980
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a7297;  // @671_5a6980
  if ((ecx & ecx) == 0) goto L5a7291;  // @672_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @673_5a6980
  L5a7291:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @675_5a6980
  goto L5a72a6;  // @676_5a6980
  L5a7297:;
  eax = (u32)(EBP - 136);  // @678_5a6980
  p38_ = eax;  // @679_5a6980
  p39_ = ecx;  // @680_5a6980
  ecx = esi;  // @681_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p39_), (u32)(p38_));  // @682_5a6980
  ecx = edx = 0;  // @683_5a6980
  L5a72a6:;
  ebx = (u32)(edi + 1228);  // @685_5a6980
  edi = (u32)(24);  // @686_5a6980
  L5a72b1:;
  eax = ext_41e290_cdecl1((u32)(215));  // @688_5a6980
  ecx = edx = 0;  // @689_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @690_5a6980
  reg.state = (s32)((u32)(20));  // @691_5a6980
  if ((eax & eax) == 0) goto L5a72dc;  // @692_5a6980
  ecx = eax;  // @693_5a6980
  eax = ext_5ec720_thiscall2(ecx, (u32)(1));  // @694_5a6980
  ecx = edx = 0;  // @695_5a6980
  ecx = eax;  // @696_5a6980
  goto L5a72de;  // @697_5a6980
  L5a72dc:;
  ecx = 0;  // @699_5a6980
  L5a72de:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @701_5a6980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @702_5a6980
  reg.state = (s32)((u32)(4294967295));  // @703_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @704_5a6980
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L5a7301;  // @705_5a6980
  if ((eax & eax) == 0) goto L5a72fb;  // @706_5a6980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @707_5a6980
  L5a72fb:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @709_5a6980
  goto L5a7310;  // @710_5a6980
  L5a7301:;
  ecx = (u32)(EBP - 136);  // @712_5a6980
  p40_ = ecx;  // @713_5a6980
  p41_ = eax;  // @714_5a6980
  ecx = esi;  // @715_5a6980
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(p41_), (u32)(p40_));  // @716_5a6980
  ecx = edx = 0;  // @717_5a6980
  L5a7310:;
  ebx = (ebx + (u32)(4));  // @719_5a6980
  edi = (edi - (u32)(1));  // @720_5a6980
  if (edi != 0) goto L5a72b1;  // @721_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }), (u32)(7012036));  // @722_5a6980
  ecx = edx = 0;  // @723_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @724_5a6980
  ebx = eax;  // @725_5a6980
  ebx = (ebx - ecx);  // @726_5a6980
  esi = 0;  // @727_5a6980
  edx = 0;  // @728_5a6980
  if (ecx > eax) ebx = edi;  // @729_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @730_5a6980
  if ((ebx & ebx) == 0) goto L5a736e;  // @731_5a6980
  edi = ecx;  // @732_5a6980
  L5a7350:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @734_5a6980
  ecx = (u32)(esi + 1);  // @735_5a6980
  edx = (edx + 1);  // @736_5a6980
  if ((eax & 0xff) != (u32)(59)) ecx = esi;  // @737_5a6980
  esi = ecx;  // @738_5a6980
  if (edx < ebx) goto L5a7350;  // @739_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @740_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @741_5a6980
  L5a736e:;
  esi = (u32)(esi + 2);  // @743_5a6980
  eax = (u32)(esi + esi*2);  // @744_5a6980
  eax = (u32)(edi + eax*4);  // @745_5a6980
  p42_ = ecx;  // @746_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1208), &v, sizeof v); }  // @747_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))((u32)(p42_), (u32)(7012048));  // @748_5a6980
  ecx = edx = 0;  // @749_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @750_5a6980
  edx = 0;  // @751_5a6980
  ebx = eax;  // @752_5a6980
  ebx = (ebx - ecx);  // @753_5a6980
  esi = 0;  // @754_5a6980
  if (ecx > eax) ebx = edx;  // @755_5a6980
  if ((ebx & ebx) == 0) goto L5a73c3;  // @756_5a6980
  edi = ecx;  // @757_5a6980
  L5a73a5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @759_5a6980
  ecx = (u32)(esi + 1);  // @760_5a6980
  edx = (edx + 1);  // @761_5a6980
  if ((eax & 0xff) != (u32)(59)) ecx = esi;  // @762_5a6980
  esi = ecx;  // @763_5a6980
  if (edx < ebx) goto L5a73a5;  // @764_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @765_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @766_5a6980
  L5a73c3:;
  esi = (u32)(esi + 2);  // @768_5a6980
  eax = (u32)(esi + esi*2);  // @769_5a6980
  eax = (u32)(edi + eax*4);  // @770_5a6980
  p43_ = ecx;  // @771_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1212), &v, sizeof v); }  // @772_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))((u32)(p43_), (u32)(7012056));  // @773_5a6980
  ecx = edx = 0;  // @774_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @775_5a6980
  edx = 0;  // @776_5a6980
  ebx = eax;  // @777_5a6980
  ebx = (ebx - ecx);  // @778_5a6980
  esi = 0;  // @779_5a6980
  if (ecx > eax) ebx = edx;  // @780_5a6980
  if ((ebx & ebx) == 0) goto L5a741e;  // @781_5a6980
  edi = ecx;  // @782_5a6980
  L5a7400:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @784_5a6980
  ecx = (u32)(esi + 1);  // @785_5a6980
  edx = (edx + 1);  // @786_5a6980
  if ((eax & 0xff) != (u32)(59)) ecx = esi;  // @787_5a6980
  esi = ecx;  // @788_5a6980
  if (edx < ebx) goto L5a7400;  // @789_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @790_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @791_5a6980
  L5a741e:;
  esi = (u32)(esi + 2);  // @793_5a6980
  eax = (u32)(esi + esi*2);  // @794_5a6980
  eax = (u32)(edi + eax*4);  // @795_5a6980
  p44_ = ecx;  // @796_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1216), &v, sizeof v); }  // @797_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))((u32)(p44_), (u32)(7012068));  // @798_5a6980
  ecx = edx = 0;  // @799_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @800_5a6980
  edx = 0;  // @801_5a6980
  ebx = eax;  // @802_5a6980
  ebx = (ebx - ecx);  // @803_5a6980
  esi = 0;  // @804_5a6980
  if (ecx > eax) ebx = edx;  // @805_5a6980
  if ((ebx & ebx) == 0) goto L5a7473;  // @806_5a6980
  edi = ecx;  // @807_5a6980
  L5a7455:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @809_5a6980
  ecx = (u32)(esi + 1);  // @810_5a6980
  edx = (edx + 1);  // @811_5a6980
  if ((eax & 0xff) != (u32)(59)) ecx = esi;  // @812_5a6980
  esi = ecx;  // @813_5a6980
  if (edx < ebx) goto L5a7455;  // @814_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @815_5a6980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @816_5a6980
  L5a7473:;
  esi = (u32)(esi + 2);  // @818_5a6980
  eax = (u32)(esi + esi*2);  // @819_5a6980
  eax = (u32)(edi + eax*4);  // @820_5a6980
  p45_ = ecx;  // @821_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1220), &v, sizeof v); }  // @822_5a6980
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67625c))((u32)(p45_), (u32)(7012076));  // @823_5a6980
  ecx = edx = 0;  // @824_5a6980
  edx = 0;  // @825_5a6980
  ebx = eax;  // @826_5a6980
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @827_5a6980
  esi = 0;  // @828_5a6980
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }) > eax) ebx = edx;  // @829_5a6980
  if ((ebx & ebx) == 0) goto L5a74c8;  // @830_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @831_5a6980
  L5a74b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @833_5a6980
  ecx = (u32)(esi + 1);  // @834_5a6980
  edx = (edx + 1);  // @835_5a6980
  if ((eax & 0xff) != (u32)(59)) ecx = esi;  // @836_5a6980
  esi = ecx;  // @837_5a6980
  if (edx < ebx) goto L5a74b0;  // @838_5a6980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @839_5a6980
  L5a74c8:;
  esi = (u32)(esi + 2);  // @841_5a6980
  eax = (u32)(esi + esi*2);  // @842_5a6980
  eax = (u32)(edi + eax*4);  // @843_5a6980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1224), &v, sizeof v); }  // @844_5a6980
  SEH_LEAVE();  // @845_5a6980
  ext_633654(G(u32, 0x6f5630));  // @846_5a6980
  return eax;  // @847_5a6980
}
PCREG(5a6980, lifted_5a6980);

extern "C" u32 lifted_6345b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760c4))((u32)(7493592));  // @0_6345b0
  ecx = edx = 0;  // @1_6345b0
  return eax;  // @2_6345b0
}
PCREG(6345b0, lifted_6345b0);

extern "C" u32 lifted_6345fd(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760c8))((u32)(7493592));  // @0_6345fd
  ecx = edx = 0;  // @1_6345fd
  return eax;  // @2_6345fd
}
PCREG(6345fd, lifted_6345fd);

extern "C" u32 lifted_634817(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676054))((u32)(7493632));  // @0_634817
  ecx = edx = 0;  // @1_634817
  return eax;  // @2_634817
}
PCREG(634817, lifted_634817);

extern "C" u32 lifted_634a0b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676160))((u32)(6507031));  // @0_634a0b
  ecx = edx = 0;  // @1_634a0b
  return eax;  // @2_634a0b
}
PCREG(634a0b, lifted_634a0b);

extern "C" u32 lifted_63450f(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760cc))((u32)(7493592));  // @0_63450f
  ecx = edx = 0;  // @1_63450f
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7493620), sizeof v); (u32)v; });  // @2_63450f
  if ((eax & eax) == 0) goto L63452a;  // @3_63450f
  p0_ = eax;  // @4_63450f
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676070))((u32)(p0_));  // @5_63450f
  ecx = edx = 0;  // @6_63450f
  L63452a:;
  return eax;  // @8_63450f
}
PCREG(63450f, lifted_63450f);

extern "C" u32 lifted_633f24(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676160))((u32)(0));  // @0_633f24
  ecx = edx = 0;  // @1_633f24
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676168))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @2_633f24
  ecx = edx = 0;  // @3_633f24
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760ac))((u32)(3221226505));  // @4_633f24
  ecx = edx = 0;  // @5_633f24
  p0_ = eax;  // @6_633f24
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x67615c))((u32)(p0_));  // @7_633f24
  ecx = edx = 0;  // @8_633f24
  return eax;  // @9_633f24
}
PCREG(633f24, lifted_633f24);

extern "C" u32 lifted_6349c7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676060))((u32)(0));  // @0_6349c7
  ecx = edx = 0;  // @1_6349c7
  ecx = eax;  // @2_6349c7
  if ((ecx & ecx) != 0) goto L6349d8;  // @3_6349c7
  L6349d5:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @5_6349c7
  return eax;  // @6_6349c7
  L6349d8:;
  eax = (u32)(23117);  // @8_6349c7
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L6349d5;  // @9_6349c7
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @10_6349c7
  eax = (eax + ecx);  // @11_6349c7
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(17744)) goto L6349d5;  // @12_6349c7
  ecx = (u32)(267);  // @13_6349c7
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }) != (ecx & 0xffff)) goto L6349d5;  // @14_6349c7
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 116), sizeof v); (u32)v; }) <= (u32)(14)) goto L6349d5;  // @15_6349c7
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 232), sizeof v); (u32)v; }) != (u32)(0))) & 0xff);  // @16_6349c7
  return eax;  // @17_6349c7
}
PCREG(6349c7, lifted_6349c7);

extern "C" u32 lifted_634771(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) & (u32)(0))); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @0_634771
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }) & (u32)(0))); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @1_634771
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @2_634771
  edi = (u32)(3141592654);  // @3_634771
  esi = (u32)(4294901760);  // @4_634771
  if (eax == edi) goto L6347a1;  // @5_634771
  if ((esi & eax) == 0) goto L6347a1;  // @6_634771
  eax = (~eax);  // @7_634771
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7296556), &v, sizeof v); }  // @8_634771
  goto L634807;  // @9_634771
  L6347a1:;
  eax = (u32)(EBP - 12);  // @11_634771
  p0_ = eax;  // @12_634771
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676124))((u32)(p0_));  // @13_634771
  ecx = edx = 0;  // @14_634771
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @15_634771
  eax = (eax ^ ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @16_634771
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @17_634771
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x676058))();  // @18_634771
  ecx = edx = 0;  // @19_634771
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) ^ eax)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @20_634771
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x67605c))();  // @21_634771
  ecx = edx = 0;  // @22_634771
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) ^ eax)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @23_634771
  eax = (u32)(EBP - 20);  // @24_634771
  p1_ = eax;  // @25_634771
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760e0))((u32)(p1_));  // @26_634771
  ecx = edx = 0;  // @27_634771
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @28_634771
  eax = (u32)(EBP - 4);  // @29_634771
  ecx = (ecx ^ ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @30_634771
  ecx = (ecx ^ ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @31_634771
  ecx = (ecx ^ eax);  // @32_634771
  if (ecx != edi) goto L6347e9;  // @33_634771
  ecx = (u32)(3141592655);  // @34_634771
  goto L6347f9;  // @35_634771
  L6347e9:;
  if ((esi & ecx) != 0) goto L6347f9;  // @37_634771
  eax = ecx;  // @38_634771
  eax = (eax | (u32)(18193));  // @39_634771
  eax = (eax << (u32)(16));  // @40_634771
  ecx = (ecx | eax);  // @41_634771
  L6347f9:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7296560), &v, sizeof v); }  // @43_634771
  ecx = (~ecx);  // @44_634771
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7296556), &v, sizeof v); }  // @45_634771
  L634807:;
  return eax;  // @47_634771
}
PCREG(634771, lifted_634771);

extern "C" u32 lifted_634432(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ext_634d46_cdecl3((u32)(7493592), (u32)(4000), (u32)(0));  // @0_634432
  ecx = edx = 0;  // @1_634432
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676060))((u32)(7083676));  // @2_634432
  ecx = edx = 0;  // @3_634432
  esi = eax;  // @4_634432
  if ((esi & esi) == 0) goto L6344ea;  // @5_634432
  p0_ = esi;  // @6_634432
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760b4))((u32)(p0_), (u32)(7083704));  // @7_634432
  ecx = edx = 0;  // @8_634432
  p1_ = esi;  // @9_634432
  ebx = eax;  // @10_634432
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760b4))((u32)(p1_), (u32)(7083732));  // @11_634432
  ecx = edx = 0;  // @12_634432
  p2_ = esi;  // @13_634432
  edi = eax;  // @14_634432
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760b4))((u32)(p2_), (u32)(7083760));  // @15_634432
  ecx = edx = 0;  // @16_634432
  esi = eax;  // @17_634432
  if ((ebx & ebx) == 0) goto L6344c3;  // @18_634432
  if ((edi & edi) == 0) goto L6344c3;  // @19_634432
  if ((esi & esi) == 0) goto L6344c3;  // @20_634432
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7493620), sizeof v); (u32)v; }) & (u32)(0))); __builtin_memcpy((void *)(u32)(7493620), &v, sizeof v); }  // @21_634432
  ecx = ebx;  // @22_634432
  eax = ext_634aae_cdecl1((u32)(7493616));  // @23_634432
  ecx = edx = 0;  // @24_634432
  eax = ((u32(STDCALL *)(void))(ebx))();  // @25_634432
  ecx = edx = 0;  // @26_634432
  p3_ = edi;  // @27_634432
  eax = ext_6344f2_cdecl1((u32)(p3_));  // @28_634432
  ecx = edx = 0;  // @29_634432
  p4_ = esi;  // @30_634432
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7493624), &v, sizeof v); }  // @31_634432
  eax = ext_6344f2_cdecl1((u32)(p4_));  // @32_634432
  ecx = edx = 0;  // @33_634432
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7493628), &v, sizeof v); }  // @34_634432
  goto L6344d9;  // @35_634432
  L6344c3:;
  eax = 0;  // @37_634432
  p5_ = eax;  // @38_634432
  p6_ = eax;  // @39_634432
  p7_ = eax;  // @40_634432
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x676064))((u32)(p7_), (u32)(1), (u32)(p6_), (u32)(p5_));  // @41_634432
  ecx = edx = 0;  // @42_634432
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7493620), &v, sizeof v); }  // @43_634432
  if ((eax & eax) == 0) goto L6344ea;  // @44_634432
  L6344d9:;
  eax = ext_633f0f_cdecl1((u32)(6505743));  // @46_634432
  ecx = edx = 0;  // @47_634432
  eax = 0;  // @48_634432
  return eax;  // @49_634432
  L6344ea:;
  eax = ext_634879_cdecl1((u32)(7));  // @51_634432
  ecx = edx = 0;  // @52_634432
}
PCREG(634432, lifted_634432);

