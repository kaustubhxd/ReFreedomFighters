// batch220015.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_62c860(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  volatile u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 STK[2];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_62c860
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_62c860
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) == eax) goto L62c9a3;  // @2_62c860
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @3_62c860
  L62c877:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_62c860
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_62c860
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_62c860
  esi = (u32)(edx + eax*4);  // @8_62c860
  edx = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 888), sizeof v); (u32)v; }));  // @9_62c860
  esi = (esi + (u32)(889));  // @10_62c860
  if ((edx & edx) != 0) goto L62c977;  // @11_62c860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_62c860
  STK[0] = ecx;  // @13_62c860
  STK[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 372), sizeof v); (u32)v; });  // @14_62c860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 368), sizeof v); (u32)v; });  // @15_62c860
  eax = ((u32( *)(u32, u32))(eax))(STK[1], STK[0]);  // @16_62c860
  ecx = edx = 0;  // @17_62c860
  if ((s32)(eax & eax) < 0) goto L62c952;  // @18_62c860
  if ((s32)eax >= (s32)(u32)(128)) goto L62c8c8;  // @19_62c860
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @20_62c860
  edx = (u32)(1);  // @21_62c860
  goto L62c954;  // @22_62c860
  L62c8c8:;
  if ((s32)eax >= (s32)(u32)(2048)) goto L62c8e8;  // @24_62c860
  ecx = eax;  // @25_62c860
  edx = (u32)(2);  // @26_62c860
  ecx = (u32)((s32)ecx >> (u32)(6));  // @27_62c860
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @28_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) | (u32)(192))) & 0xff);  // @29_62c860
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(128))) & 0xff);  // @30_62c860
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @31_62c860
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 13), &v, sizeof v); }  // @32_62c860
  goto L62c954;  // @33_62c860
  L62c8e8:;
  if ((s32)eax >= (s32)(u32)(65536)) goto L62c916;  // @35_62c860
  ecx = eax;  // @36_62c860
  edx = (u32)(3);  // @37_62c860
  ecx = (u32)((s32)ecx >> (u32)(12));  // @38_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) | (u32)(224))) & 0xff);  // @39_62c860
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @40_62c860
  ecx = eax;  // @41_62c860
  ecx = (u32)((s32)ecx >> (u32)(6));  // @42_62c860
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @43_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @44_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) | (u32)(128))) & 0xff);  // @45_62c860
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(128))) & 0xff);  // @46_62c860
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 13), &v, sizeof v); }  // @47_62c860
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 14), &v, sizeof v); }  // @48_62c860
  goto L62c954;  // @49_62c860
  L62c916:;
  if ((s32)eax >= (s32)(u32)(1114112)) goto L62c952;  // @51_62c860
  ecx = eax;  // @52_62c860
  edx = (u32)(4);  // @53_62c860
  ecx = (u32)((s32)ecx >> (u32)(18));  // @54_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) | (u32)(240))) & 0xff);  // @55_62c860
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @56_62c860
  ecx = eax;  // @57_62c860
  ecx = (u32)((s32)ecx >> (u32)(12));  // @58_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @59_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) | (u32)(128))) & 0xff);  // @60_62c860
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 13), &v, sizeof v); }  // @61_62c860
  ecx = eax;  // @62_62c860
  ecx = (u32)((s32)ecx >> (u32)(6));  // @63_62c860
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @64_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @65_62c860
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) | (u32)(128))) & 0xff);  // @66_62c860
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(128))) & 0xff);  // @67_62c860
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 14), &v, sizeof v); }  // @68_62c860
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @69_62c860
  goto L62c954;  // @70_62c860
  L62c952:;
  edx = 0;  // @72_62c860
  L62c954:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @74_62c860
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @75_62c860
  if ((s32)edx > (s32)eax) goto L62c9a1;  // @76_62c860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @77_62c860
  esi = (u32)(EBP + 12);  // @78_62c860
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @79_62c860
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_62c860
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @81_62c860
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @82_62c860
  eax = (eax + (u32)(-3));  // @83_62c860
  eax = (eax + ecx);  // @84_62c860
  goto L62c983;  // @85_62c860
  L62c977:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @87_62c860
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @88_62c860
  if ((s32)edx > (s32)eax) goto L62c9a1;  // @89_62c860
  eax = (u32)(ecx + 1);  // @90_62c860
  L62c983:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @92_62c860
  L62c985:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @94_62c860
  esi = (u32)(esi + 1);  // @95_62c860
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi - 1), sizeof v); (u32)v; })) & 0xff);  // @96_62c860
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @97_62c860
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @98_62c860
  edx = (edx - (u32)(1));  // @99_62c860
  if (edx != 0) goto L62c985;  // @100_62c860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @101_62c860
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != eax) goto L62c877;  // @102_62c860
  L62c9a1:;
  L62c9a3:;
  return eax;  // @105_62c860
}
PCREG(62c860, lifted_62c860);

