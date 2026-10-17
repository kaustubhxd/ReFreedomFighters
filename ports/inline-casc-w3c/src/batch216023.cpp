// batch216023.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_437670_thiscall2(u32, u32) __asm__("ext_437670");
extern "C" u32 THISCALL ext_4388a0_thiscall1(u32) __asm__("ext_4388a0");
extern "C" u32 THISCALL ext_438910_thiscall1(u32) __asm__("ext_438910");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4d9230_thiscall2(u32, u32) __asm__("ext_4d9230");
extern "C" u32 THISCALL ext_4ff920_thiscall1(u32) __asm__("ext_4ff920");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_436ec0_cdecl1(...) __asm__("ext_436ec0");
extern "C" u32 ext_438a60_cdecl1(...) __asm__("ext_438a60");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL ext_436ec0_thiscall1(u32) __asm__("ext_436ec0");
extern "C" u32 THISCALL ext_438a60_thiscall1(u32) __asm__("ext_438a60");
#ifndef VSLOT
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
#endif
extern "C" u32 THISCALL lifted_43a900(u32 ecx_in) {
  SEH_ENTER(0x665cbc);  // @h_43a900
  volatile u32 it = 0;
  u32 edi = ecx_in, eax = (u32)(u8 *)&reg;
  u32 m = *(u32 *)(edi + 0x19);
  if (m != 0) {  // @h1_43a900
    ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x4c))(m, (u32)(u32 *)&it);  // @h2_43a900
    m = *(u32 *)(edi + 0x19);
    u32 esi = eax = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x5c))(m, (u32)(u32 *)&it);  // @h3_43a900
    if (it != 0) {  // @h4_43a900
      do {
        u32 mm = *(u32 *)(edi + 0x11);
        ext_4d9230_thiscall2(*(u32 *)(mm + 0x1330), *(u32 *)(esi + 4));  // @h5_43a900
        u32 kind = *(u32 *)esi;
        if (kind == 0) {  // @h6_43a900
          u32 o = esi ? esi - 4 : 0;
          if (o) {
            reg.state = 0;
            *(u32 *)o = 0x67a7dc;
            ext_4388a0_thiscall1(o);
            ext_438910_thiscall1(o);
            if (*(u8 *)(o + 0x32) & 2) {  // @h7_43a900
              u32 pp = *(u32 *)(o + 8);
              if (pp) ext_634273_cdecl2(pp, 1);  // @h8_43a900
            }
            reg.state = -1;
            ext_634273_cdecl2(o, 0x4a);  // @h9_43a900
          }
        } else if (kind == 1) {  // @h10_43a900
          ext_436ec0_thiscall1(esi);
          ext_634273_cdecl2(esi, 0x12);  // @h11_43a900
        } else if (kind == 2) {  // @h12_43a900
          reg.state = 1;
          ext_438a60_thiscall1(esi);
          u32 pp = *(u32 *)(esi + 4);
          if (pp) ext_634273_cdecl2(pp, 1);  // @h13_43a900
          reg.state = -1;
          ext_634273_cdecl2(esi, 0x1a);  // @h14_43a900
        }
        m = *(u32 *)(edi + 0x19);
        esi = eax = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x5c))(m, (u32)(u32 *)&it);  // @h15_43a900
      } while (it != 0);  // @h16_43a900
    }
  }
  SEH_LEAVE();
  return eax;
}
PCREG(43a900, lifted_43a900);

extern "C" u32 THISCALL lifted_4368b0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66592f);  // @h_4368b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4368b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4368b0
  ecx = edi;  // @2_4368b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_4368b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4368b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @5_4368b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @6_4368b0
  ecx = edx = 0;  // @7_4368b0
  if ((eax & eax) == 0) goto L436930;  // @8_4368b0
  ecx = edi;  // @9_4368b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @10_4368b0
  ecx = edx = 0;  // @11_4368b0
  edx = (u32)(eax + 1);  // @12_4368b0
  L436902:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @14_4368b0
  eax = (eax + 1);  // @15_4368b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L436902;  // @16_4368b0
  eax = (eax - edx);  // @17_4368b0
  eax = (eax + 1);  // @18_4368b0
  PS[0] = eax;  // @19_4368b0
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @20_4368b0
  ecx = edx = 0;  // @21_4368b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @22_4368b0
  ecx = edi;  // @23_4368b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_4368b0
  ecx = edx = 0;  // @25_4368b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @26_4368b0
  L436922:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @28_4368b0
  eax = (u32)(eax + 1);  // @29_4368b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @30_4368b0
  edx = (u32)(edx + 1);  // @31_4368b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L436922;  // @32_4368b0
  L436930:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @34_4368b0
  eax = (u32)(ecx + 4);  // @35_4368b0
  CF = (ecx != 0); ecx = (u32)(0 - ecx);  // @36_4368b0
  ecx = (u32)(0 - CF);  // @37_4368b0
  ecx = (ecx & eax);  // @38_4368b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @39_4368b0
  eax = ext_41e290_cdecl1((u32)(28));  // @40_4368b0
  ecx = edx = 0;  // @41_4368b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @42_4368b0
  reg.state = (s32)((u32)(0));  // @43_4368b0
  if ((eax & eax) == 0) goto L436964;  // @44_4368b0
  ecx = eax;  // @45_4368b0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @46_4368b0
  ecx = edx = 0;  // @47_4368b0
  goto L436966;  // @48_4368b0
  L436964:;
  eax = 0;  // @50_4368b0
  L436966:;
  PS[0] = edi;  // @52_4368b0
  ecx = esi;  // @53_4368b0
  reg.state = (s32)((u32)(4294967295));  // @54_4368b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @55_4368b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @56_4368b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @57_4368b0
  eax = ext_437670_thiscall2(ecx, (u32)(PS[0]));  // @58_4368b0
  ecx = edx = 0;  // @59_4368b0
  eax = esi;  // @60_4368b0
  SEH_LEAVE();  // @61_4368b0
  return eax;  // @62_4368b0
}
PCREG(4368b0, lifted_4368b0);

extern "C" u32 THISCALL lifted_4ff9d0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_4ff9d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  ebx = ecx;  // @0_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @1_4ff9d0
  edi = 0;  // @2_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_4ff9d0
  eax = (eax - ecx);  // @4_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @5_4ff9d0
  if ((eax & eax) == 0) goto L4ffa30;  // @6_4ff9d0
  L4ffa08:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*4), sizeof v); (u32)v; });  // @8_4ff9d0
  if ((esi & esi) == 0) goto L4ffa21;  // @9_4ff9d0
  ecx = esi;  // @10_4ff9d0
  eax = ext_4ff920_thiscall1(ecx);  // @11_4ff9d0
  ecx = edx = 0;  // @12_4ff9d0
  PS[1] = esi;  // @13_4ff9d0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(72));  // @14_4ff9d0
  ecx = edx = 0;  // @15_4ff9d0
  L4ffa21:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @17_4ff9d0
  edi = (edi + 1);  // @18_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @19_4ff9d0
  eax = (eax - ecx);  // @20_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @21_4ff9d0
  if (edi < eax) goto L4ffa08;  // @22_4ff9d0
  L4ffa30:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @24_4ff9d0
  edx = esi;  // @25_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_4ff9d0
  edx = (edx - esi);  // @27_4ff9d0
  edx = (u32)((s32)edx >> (u32)(2));  // @28_4ff9d0
  ecx = eax;  // @29_4ff9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @30_4ff9d0
  if ((s32)(edx & edx) <= 0) goto L4ffa61;  // @31_4ff9d0
  edi = esi;  // @32_4ff9d0
  edi = (edi - eax);  // @33_4ff9d0
  L4ffa50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx), sizeof v); (u32)v; });  // @35_4ff9d0
  ecx = (u32)(ecx + 4);  // @36_4ff9d0
  edx = (edx - 1);  // @37_4ff9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @38_4ff9d0
  if ((s32)(edx & edx) > 0) goto L4ffa50;  // @39_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @40_4ff9d0
  L4ffa61:;
  esi = (esi - eax);  // @42_4ff9d0
  esi = (u32)((s32)esi >> (u32)(2));  // @43_4ff9d0
  CF = (esi != 0); esi = (u32)(0 - esi);  // @44_4ff9d0
  esi = (esi << (u32)(2));  // @45_4ff9d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @46_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @47_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @48_4ff9d0
  eax = (eax - ecx);  // @49_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @50_4ff9d0
  reg.state = (s32)((u32)(0));  // @51_4ff9d0
  if ((eax & eax) == 0) goto L4ffa8f;  // @52_4ff9d0
  eax = (eax << (u32)(2));  // @53_4ff9d0
  PS[0] = eax;  // @54_4ff9d0
  PS[1] = ecx;  // @55_4ff9d0
  ecx = ebx;  // @56_4ff9d0
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @57_4ff9d0
  ecx = edx = 0;  // @58_4ff9d0
  L4ffa8f:;
  SEH_LEAVE();  // @60_4ff9d0
  return eax;  // @61_4ff9d0
}
// retired: PCREG(4ff9d0, lifted_4ff9d0); (hand port in batch216060)

extern "C" u32 THISCALL lifted_5bfac0(u32 ecx_in) {
  SEH_ENTER(0x66c558);  // @h_5bfac0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_5bfac0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_5bfac0
  eax = ext_469870_thiscall1(ecx);  // @2_5bfac0
  ecx = edx = 0;  // @3_5bfac0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5bfac0
  { u32 v = (u32)((u32)(7026868)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @7_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @8_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @9_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @10_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_5bfac0
  reg.state = (s32)((u32)(0));  // @13_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968700), (u32)(0), (u32)(7027024), (u32)(63));  // @15_5bfac0
  ecx = edx = 0;  // @16_5bfac0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @17_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968716), (u32)(0), (u32)(7027024), (u32)(64));  // @21_5bfac0
  ecx = edx = 0;  // @22_5bfac0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @23_5bfac0
  edx = (u32)(EBP - 16);  // @24_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @25_5bfac0
  PS[0] = edx;  // @26_5bfac0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 11281), &v, sizeof v); }  // @27_5bfac0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @28_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @31_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7027076), (u32)(PS[0]));  // @32_5bfac0
  ecx = edx = 0;  // @33_5bfac0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5bfbdf;  // @34_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @35_5bfac0
  eax = (u32)(6792920);  // @36_5bfac0
  L5bfba0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @38_5bfac0
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L5bfbc0;  // @39_5bfac0
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L5bfbbc;  // @40_5bfac0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @41_5bfac0
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L5bfbc0;  // @42_5bfac0
  ecx = (ecx + (u32)(2));  // @43_5bfac0
  eax = (eax + (u32)(2));  // @44_5bfac0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L5bfba0;  // @45_5bfac0
  L5bfbbc:;
  eax = 0;  // @47_5bfac0
  goto L5bfbc5;  // @48_5bfac0
  L5bfbc0:;
  eax = (u32)(0 - CF);  // @50_5bfac0
  eax = (eax | (u32)(1));  // @51_5bfac0
  L5bfbc5:;
  eax = esi;  // @53_5bfac0
  if ((eax & eax) != 0) goto L5bfbe1;  // @54_5bfac0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @55_5bfac0
  SEH_LEAVE();  // @56_5bfac0
  return eax;  // @57_5bfac0
  L5bfbdf:;
  eax = esi;  // @59_5bfac0
  L5bfbe1:;
  SEH_LEAVE();  // @61_5bfac0
  return eax;  // @62_5bfac0
}
// retired: PCREG(5bfac0, lifted_5bfac0); (hand port in batch216060)

