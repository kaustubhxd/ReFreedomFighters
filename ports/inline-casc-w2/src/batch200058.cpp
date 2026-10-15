// batch200058.cpp - Sonnet-w2, mechanically lifted ports (lift.py): ctor + base + engine slot 0x114 registrations.
#include "ff.h"
extern "C" u32 THISCALL ext_469870(u32);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4a4700(u32 ecx_in) {
  SEH_ENTER(0x66c468);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4a4700
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4a4700
  eax = ext_469870(ecx);  // @2_4a4700
  ecx = edx = 0;  // @3_4a4700
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4a4700
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4a4700
  { u32 v = (u32)((u32)(6880548)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4a4700
  eax = 0;  // @7_4a4700
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 86), &v, sizeof v); }  // @8_4a4700
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @9_4a4700
  { u16 v = (u16)((u32)(257)); __builtin_memcpy((void *)(u32)(esi + 99), &v, sizeof v); }  // @10_4a4700
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @11_4a4700
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @12_4a4700
  { u32 v = (u32)((u32)(1103626240)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @13_4a4700
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @14_4a4700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4a4700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_4a4700
  reg.state = (s32)((u32)(0));  // @17_4a4700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4a4700
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6880724), (u32)(0), (u32)(6880680), (u32)(36));  // @19_4a4700
  ecx = edx = 0;  // @20_4a4700
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7340792), &v, sizeof v); }  // @21_4a4700
  eax = esi;  // @22_4a4700
  SEH_LEAVE();  // @23_4a4700
  return eax;  // @24_4a4700
}
PCREG(4a4700, lifted_4a4700);

extern "C" u32 THISCALL lifted_5d9360(u32 ecx_in) {
  SEH_ENTER(0x66c468);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5d9360
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5d9360
  eax = ext_469870(ecx);  // @2_5d9360
  ecx = edx = 0;  // @3_5d9360
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5d9360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5d9360
  { u32 v = (u32)((u32)(7037912)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272460), sizeof v); (u32)v; });  // @7_5d9360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @8_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_5d9360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_5d9360
  reg.state = (s32)((u32)(0));  // @11_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_5d9360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6827544), (u32)(0), (u32)(7038044), (u32)(33));  // @13_5d9360
  ecx = edx = 0;  // @14_5d9360
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @15_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_5d9360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @17_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5d9360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7038100), (u32)(0), (u32)(7038044), (u32)(34));  // @19_5d9360
  ecx = edx = 0;  // @20_5d9360
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 130), &v, sizeof v); }  // @21_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_5d9360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_5d9360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7038120), (u32)(0), (u32)(7038044), (u32)(35));  // @25_5d9360
  ecx = edx = 0;  // @26_5d9360
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @27_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_5d9360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_5d9360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5d9360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7038132), (u32)(0), (u32)(7038044), (u32)(36));  // @31_5d9360
  ecx = edx = 0;  // @32_5d9360
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 134), &v, sizeof v); }  // @33_5d9360
  eax = esi;  // @34_5d9360
  SEH_LEAVE();  // @35_5d9360
  return eax;  // @36_5d9360
}
PCREG(5d9360, lifted_5d9360);
