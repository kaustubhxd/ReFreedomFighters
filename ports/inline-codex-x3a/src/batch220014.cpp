// batch220014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_59e050_thiscall2(u32, u32) __asm__("ext_59e050");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_559380(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 STK[13];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_559380
  eax = (eax ^ EBP);  // @1_559380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_559380
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_559380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @5_559380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_559380
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @7_559380
  edi = ecx;  // @8_559380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_559380
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @10_559380
  if ((ebx & ebx) == 0) goto L5593e2;  // @11_559380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @12_559380
  STK[0] = ebx;  // @13_559380
  eax = ext_59e050_thiscall2(ecx, STK[0]);  // @14_559380
  ecx = edx = 0;  // @15_559380
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5593e2;  // @16_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_559380
  STK[1] = ebx;  // @18_559380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_559380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, STK[1]);  // @21_559380
  ecx = edx = 0;  // @22_559380
  if ((eax & eax) == 0) goto L5593e2;  // @23_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @24_559380
  if ((eax & eax) == 0) goto L5593e2;  // @25_559380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @27_559380
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @28_559380
  L5593e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @30_559380
  edx = (u32)(EBP - 16);  // @31_559380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @32_559380
  STK[2] = edx;  // @33_559380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11281), sizeof v); (u32)v; });  // @34_559380
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @35_559380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @36_559380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @37_559380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @38_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_559380
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @40_559380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, STK[2]);  // @41_559380
  ecx = edx = 0;  // @42_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @43_559380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @44_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @45_559380
  STK[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @46_559380
  eax = (u32)(EBP - 20);  // @47_559380
  STK[4] = eax;  // @48_559380
  STK[5] = ecx;  // @49_559380
  eax = (u32)(EBP - 16);  // @50_559380
  STK[5] = (u32)(1161527296);  // @51_559380
  STK[6] = eax;  // @52_559380
  ecx = esi;  // @53_559380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, STK[6], STK[5], STK[4], STK[3]);  // @54_559380
  ecx = edx = 0;  // @55_559380
  esi = eax;  // @56_559380
  if ((esi & esi) == 0) goto L5594b7;  // @57_559380
  L559444:;
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; })) goto L55946c;  // @59_559380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_559380
  STK[7] = esi;  // @61_559380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @62_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_559380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, STK[7]);  // @64_559380
  ecx = edx = 0;  // @65_559380
  if (eax == ebx) goto L55946c;  // @66_559380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @67_559380
  STK[8] = eax;  // @68_559380
  eax = ext_59e050_thiscall2(ecx, STK[8]);  // @69_559380
  ecx = edx = 0;  // @70_559380
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5594a9;  // @71_559380
  L55946c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @73_559380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @74_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @75_559380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_559380
  STK[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @77_559380
  eax = (u32)(EBP - 20);  // @78_559380
  STK[10] = eax;  // @79_559380
  STK[11] = ecx;  // @80_559380
  eax = (u32)(EBP - 16);  // @81_559380
  STK[11] = (u32)(1161527296);  // @82_559380
  STK[12] = eax;  // @83_559380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, STK[12], STK[11], STK[10], STK[9]);  // @84_559380
  ecx = edx = 0;  // @85_559380
  esi = eax;  // @86_559380
  if ((esi & esi) != 0) goto L559444;  // @87_559380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @88_559380
  ecx = (ecx ^ EBP);  // @89_559380
  ext_633654(ecx);  // @90_559380
  return eax;  // @91_559380
  L5594a9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @93_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @94_559380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @95_559380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @96_559380
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @97_559380
  L5594b7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @99_559380
  ecx = (ecx ^ EBP);  // @100_559380
  ext_633654(ecx);  // @101_559380
  return eax;  // @102_559380
}
PCREG(559380, lifted_559380);

