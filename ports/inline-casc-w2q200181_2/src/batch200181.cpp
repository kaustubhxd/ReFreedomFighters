// batch200181.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_47ac90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_47ac90
  eax = ecx;  // @1_47ac90
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EBX, 4);  // @2_47ac90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_47ac90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4 + 1178), sizeof v); (u32)v; });  // @5_47ac90
  __builtin_memcpy((void *)(u32)(EBP - 12), &SENT_ESI, 4);  // @6_47ac90
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_EDI, 4);  // @7_47ac90
  if ((eax & eax) == 0) goto L47acd2;  // @8_47ac90
  eax = (u32)(eax + ebx*8);  // @9_47ac90
  ecx = 0;  // @10_47ac90
  eax = (eax + (u32)(4));  // @11_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != ecx) ecx = eax;  // @12_47ac90
  if ((ecx & ecx) == 0) goto L47acd2;  // @13_47ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @14_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != esi) goto L47acd5;  // @15_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @16_47ac90
  edi = 0;  // @17_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) == eax) esi = edi;  // @18_47ac90
  goto L47acd5;  // @19_47ac90
  L47acd2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @21_47ac90
  L47acd5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @23_47ac90
  edi = 0;  // @24_47ac90
  ecx = 0;  // @25_47ac90
  eax = (eax + (u32)(1206));  // @26_47ac90
  L47ace1:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 4), sizeof v); (u32)v; }) != edx) goto L47acea;  // @28_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == ebx) goto L47acf5;  // @29_47ac90
  L47acea:;
  ecx = (ecx + 1);  // @31_47ac90
  eax = (eax + (u32)(16));  // @32_47ac90
  if (ecx < (u32)(16)) goto L47ace1;  // @33_47ac90
  goto L47acfc;  // @34_47ac90
  L47acf5:;
  edi = (u32)(eax - 4);  // @36_47ac90
  if ((edi & edi) != 0) goto L47ad33;  // @37_47ac90
  L47acfc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @39_47ac90
  ecx = 0;  // @40_47ac90
  L47ad01:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1210), sizeof v); (u32)v; }) == (u32)(0)) goto L47ad15;  // @42_47ac90
  ecx = (ecx + 1);  // @43_47ac90
  eax = (eax + (u32)(16));  // @44_47ac90
  if (ecx < (u32)(16)) goto L47ad01;  // @45_47ac90
  goto L47ad20;  // @46_47ac90
  L47ad15:;
  edi = (u32)(eax + 1202);  // @48_47ac90
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @49_47ac90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @50_47ac90
  L47ad20:;
  if (ecx != (u32)(16)) goto L47ad33;  // @52_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @53_47ac90
  if ((eax & eax) == 0) goto L47ad32;  // @54_47ac90
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @55_47ac90
  eax = ((u32(STDCALL *)(void))(eax))();  // @56_47ac90
  *(volatile u32 *)0x8140f4 = 0;  // @57_47ac90
  ecx = edx = 0;  // @58_47ac90
  goto L47ad33;  // @59_47ac90
  L47ad32:;
  __builtin_trap();  // @61_47ac90
  L47ad33:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @63_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @64_47ac90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @65_47ac90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @66_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_47ac90
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @68_47ac90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1452)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1198), sizeof v); (u32)v; }), (u32)(1));  // @69_47ac90
  *(volatile u32 *)0x8140f4 = 0;  // @70_47ac90
  ecx = edx = 0;  // @71_47ac90
  return eax;  // @72_47ac90
}
PCREG(47ac90, lifted_47ac90);

