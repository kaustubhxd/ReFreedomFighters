// batch254024.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_61bac0_thiscall3(u32, u32, u32) __asm__("ext_61bac0");
extern "C" u32 THISCALL ext_4321c0_thiscall2(u32, u32) __asm__("ext_4321c0");
extern "C" u32 THISCALL ext_43b820_thiscall2(u32, u32) __asm__("ext_43b820");
extern "C" u32 THISCALL ext_43b9a0_thiscall2(u32, u32) __asm__("ext_43b9a0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_43c210(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665d9e);  // @h_43c210
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 PVX = 0;   // hand fix: the shared tail pushes a different message per path
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_43c210
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @1_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @2_43c210
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_43c210
  FL[0] = eax; FL[1] = (u32)(12);  // @4_43c210
  if (FL[0] > FL[1]) goto L43ceaa;  // @5_43c210
  switch (eax) {  // @6_43c210
  case 0: goto L43c25c;  // @7_43c210
  case 1: goto L43c359;  // @8_43c210
  case 2: goto L43c90c;  // @9_43c210
  case 3: goto L43ccee;  // @10_43c210
  case 4: goto L43ceaa;  // @11_43c210
  case 5: goto L43ceaa;  // @12_43c210
  case 6: goto L43ce92;  // @13_43c210
  case 7: goto L43cea0;  // @14_43c210
  case 8: goto L43cea0;  // @15_43c210
  case 9: goto L43ceaa;  // @16_43c210
  case 10: goto L43ceaa;  // @17_43c210
  case 11: goto L43cdeb;  // @18_43c210
  case 12: goto L43ce99;  // @19_43c210
  default: __builtin_trap(); }  // @20_43c210
  L43c25c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_43c210
  edx = (u32)(6791420);  // @23_43c210
  eax = ecx;  // @24_43c210
  L43c266:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @26_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @27_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @28_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @29_43c210
  if (FL[0] != FL[1]) goto L43c2a8;  // @30_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @31_43c210
  if (FL[0] == FL[1]) goto L43c2a4;  // @32_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @33_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @34_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @35_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @36_43c210
  if (FL[0] != FL[1]) goto L43c2a8;  // @37_43c210
  eax = (eax + (u32)(2));  // @38_43c210
  FL[3] = eax;  // @39_43c210
  edx = (edx + (u32)(2));  // @40_43c210
  FL[3] = edx;  // @41_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @42_43c210
  if (FL[0] != FL[1]) goto L43c266;  // @43_43c210
  L43c2a4:;
  eax = 0;  // @45_43c210
  FL[3] = eax;  // @46_43c210
  goto L43c2ad;  // @47_43c210
  L43c2a8:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @49_43c210
  eax = (eax | (u32)(1));  // @50_43c210
  FL[3] = eax;  // @51_43c210
  L43c2ad:;
  FL[2] = (eax & eax);  // @53_43c210
  if (FL[2] == 0) goto L43c8f6;  // @54_43c210
  edx = (u32)(6798800);  // @55_43c210
  eax = ecx;  // @56_43c210
  L43c2c0:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @58_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @59_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @60_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @61_43c210
  if (FL[0] != FL[1]) goto L43c302;  // @62_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @63_43c210
  if (FL[0] == FL[1]) goto L43c2fe;  // @64_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @65_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @66_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @67_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @68_43c210
  if (FL[0] != FL[1]) goto L43c302;  // @69_43c210
  eax = (eax + (u32)(2));  // @70_43c210
  FL[3] = eax;  // @71_43c210
  edx = (edx + (u32)(2));  // @72_43c210
  FL[3] = edx;  // @73_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @74_43c210
  if (FL[0] != FL[1]) goto L43c2c0;  // @75_43c210
  L43c2fe:;
  eax = 0;  // @77_43c210
  FL[3] = eax;  // @78_43c210
  goto L43c307;  // @79_43c210
  L43c302:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @81_43c210
  eax = (eax | (u32)(1));  // @82_43c210
  FL[3] = eax;  // @83_43c210
  L43c307:;
  FL[2] = (eax & eax);  // @85_43c210
  if (FL[2] != 0) goto L43c317;  // @86_43c210
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @87_43c210
  goto L43ceaa;  // @88_43c210
  L43c317:;
  eax = (u32)(6791400);  // @90_43c210
  L43c320:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @92_43c210
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @93_43c210
  if (FL[0] != FL[1]) goto L43c340;  // @94_43c210
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @95_43c210
  if (FL[2] == 0) goto L43c33c;  // @96_43c210
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @97_43c210
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @98_43c210
  if (FL[0] != FL[1]) goto L43c340;  // @99_43c210
  ecx = (ecx + (u32)(2));  // @100_43c210
  FL[3] = ecx;  // @101_43c210
  eax = (eax + (u32)(2));  // @102_43c210
  FL[3] = eax;  // @103_43c210
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @104_43c210
  if (FL[2] != 0) goto L43c320;  // @105_43c210
  L43c33c:;
  eax = 0;  // @107_43c210
  FL[3] = eax;  // @108_43c210
  goto L43c345;  // @109_43c210
  L43c340:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @111_43c210
  eax = (eax | (u32)(1));  // @112_43c210
  FL[3] = eax;  // @113_43c210
  L43c345:;
  FL[2] = (eax & eax);  // @115_43c210
  if (FL[2] == 0) goto L43ceaa;  // @116_43c210
  ecx = ebx;  // @117_43c210
  PVX = 6798808u;
  goto L43cea5;  // @118_43c210
  L43c359:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @120_43c210
  ecx = (u32)(6791432);  // @121_43c210
  eax = edx;  // @122_43c210
  L43c363:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @124_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @126_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @127_43c210
  if (FL[0] != FL[1]) goto L43c3a5;  // @128_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @129_43c210
  if (FL[0] == FL[1]) goto L43c3a1;  // @130_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @131_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @132_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @133_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @134_43c210
  if (FL[0] != FL[1]) goto L43c3a5;  // @135_43c210
  eax = (eax + (u32)(2));  // @136_43c210
  FL[3] = eax;  // @137_43c210
  ecx = (ecx + (u32)(2));  // @138_43c210
  FL[3] = ecx;  // @139_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @140_43c210
  if (FL[0] != FL[1]) goto L43c363;  // @141_43c210
  L43c3a1:;
  eax = 0;  // @143_43c210
  FL[3] = eax;  // @144_43c210
  goto L43c3aa;  // @145_43c210
  L43c3a5:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @147_43c210
  eax = (eax | (u32)(1));  // @148_43c210
  FL[3] = eax;  // @149_43c210
  L43c3aa:;
  FL[2] = (eax & eax);  // @151_43c210
  if (FL[2] != 0) goto L43c48b;  // @152_43c210
  PV[0] = (u32)(esi);  // @153_43c210
  ecx = ebx;  // @154_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 144), &v, sizeof v); }  // @155_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @156_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 148), &v, sizeof v); }  // @157_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 164), &v, sizeof v); }  // @158_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @159_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 168), &v, sizeof v); }  // @160_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @161_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 172), &v, sizeof v); }  // @162_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[0], (u32)(6791440));  // @163_43c210
  ecx = edx = 0;  // @164_43c210
  PV[1] = (u32)(eax);  // @165_43c210
  ecx = (u32)(EBP - 144);  // @166_43c210
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @167_43c210
  ecx = edx = 0;  // @168_43c210
  eax = (u32)(EBP - 144);  // @169_43c210
  reg.state = (s32)((u32)(0));  // @170_43c210
  PV[2] = (u32)(eax);  // @171_43c210
  ecx = (u32)(ebx + 16);  // @172_43c210
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @173_43c210
  ecx = edx = 0;  // @174_43c210
  ecx = (u32)(EBP - 144);  // @175_43c210
  reg.state = (s32)((u32)(4294967295));  // @176_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @177_43c210
  ecx = edx = 0;  // @178_43c210
  PV[3] = (u32)(esi);  // @179_43c210
  ecx = ebx;  // @180_43c210
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 181), &v, sizeof v); }  // @181_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[3], (u32)(6791460));  // @182_43c210
  ecx = edx = 0;  // @183_43c210
  FL[2] = (eax & eax);  // @184_43c210
  if (FL[2] == 0) goto L43c478;  // @185_43c210
  PV[4] = (u32)(eax);  // @186_43c210
  ecx = ebx;  // @187_43c210
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 176), &v, sizeof v); }  // @188_43c210
  eax = ext_43b820_thiscall2(ecx, PV[4]);  // @189_43c210
  ecx = edx = 0;  // @190_43c210
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @191_43c210
  goto L43ceaa;  // @192_43c210
  L43c478:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 176), &v, sizeof v); }  // @194_43c210
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @195_43c210
  goto L43ceaa;  // @196_43c210
  L43c48b:;
  ecx = (u32)(6798828);  // @198_43c210
  eax = edx;  // @199_43c210
  L43c492:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @201_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @203_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @204_43c210
  if (FL[0] != FL[1]) goto L43c4d4;  // @205_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @206_43c210
  if (FL[0] == FL[1]) goto L43c4d0;  // @207_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @208_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @209_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @210_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @211_43c210
  if (FL[0] != FL[1]) goto L43c4d4;  // @212_43c210
  eax = (eax + (u32)(2));  // @213_43c210
  FL[3] = eax;  // @214_43c210
  ecx = (ecx + (u32)(2));  // @215_43c210
  FL[3] = ecx;  // @216_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @217_43c210
  if (FL[0] != FL[1]) goto L43c492;  // @218_43c210
  L43c4d0:;
  eax = 0;  // @220_43c210
  FL[3] = eax;  // @221_43c210
  goto L43c4d9;  // @222_43c210
  L43c4d4:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @224_43c210
  eax = (eax | (u32)(1));  // @225_43c210
  FL[3] = eax;  // @226_43c210
  L43c4d9:;
  FL[2] = (eax & eax);  // @228_43c210
  if (FL[2] != 0) goto L43c59e;  // @229_43c210
  PV[5] = (u32)(esi);  // @230_43c210
  ecx = ebx;  // @231_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 144), &v, sizeof v); }  // @232_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @233_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 148), &v, sizeof v); }  // @234_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 164), &v, sizeof v); }  // @235_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @236_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 168), &v, sizeof v); }  // @237_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @238_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 172), &v, sizeof v); }  // @239_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[5], (u32)(6798836));  // @240_43c210
  ecx = edx = 0;  // @241_43c210
  PV[6] = (u32)(eax);  // @242_43c210
  ecx = (u32)(EBP - 144);  // @243_43c210
  eax = ext_4cbe80_thiscall2(ecx, PV[6]);  // @244_43c210
  ecx = edx = 0;  // @245_43c210
  eax = (u32)(EBP - 144);  // @246_43c210
  reg.state = (s32)((u32)(1));  // @247_43c210
  PV[7] = (u32)(eax);  // @248_43c210
  ecx = (u32)(ebx + 16);  // @249_43c210
  eax = ext_4cbee0_thiscall2(ecx, PV[7]);  // @250_43c210
  ecx = edx = 0;  // @251_43c210
  ecx = (u32)(EBP - 144);  // @252_43c210
  reg.state = (s32)((u32)(4294967295));  // @253_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @254_43c210
  ecx = edx = 0;  // @255_43c210
  ecx = (u32)(EBP - 144);  // @256_43c210
  { u16 v = (u16)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 181), &v, sizeof v); }  // @257_43c210
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @258_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @259_43c210
  ecx = edx = 0;  // @260_43c210
  reg.state = (s32)((u32)(2));  // @261_43c210
  goto L43c6ac;  // @262_43c210
  L43c59e:;
  ecx = (u32)(6798844);  // @264_43c210
  eax = edx;  // @265_43c210
  L43c5a5:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @267_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @268_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @269_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @270_43c210
  if (FL[0] != FL[1]) goto L43c5e7;  // @271_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @272_43c210
  if (FL[0] == FL[1]) goto L43c5e3;  // @273_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @274_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @275_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @276_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @277_43c210
  if (FL[0] != FL[1]) goto L43c5e7;  // @278_43c210
  eax = (eax + (u32)(2));  // @279_43c210
  FL[3] = eax;  // @280_43c210
  ecx = (ecx + (u32)(2));  // @281_43c210
  FL[3] = ecx;  // @282_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @283_43c210
  if (FL[0] != FL[1]) goto L43c5a5;  // @284_43c210
  L43c5e3:;
  eax = 0;  // @286_43c210
  FL[3] = eax;  // @287_43c210
  goto L43c5ec;  // @288_43c210
  L43c5e7:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @290_43c210
  eax = (eax | (u32)(1));  // @291_43c210
  FL[3] = eax;  // @292_43c210
  L43c5ec:;
  FL[2] = (eax & eax);  // @294_43c210
  if (FL[2] != 0) goto L43c6ce;  // @295_43c210
  PV[8] = (u32)(esi);  // @296_43c210
  ecx = ebx;  // @297_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 144), &v, sizeof v); }  // @298_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @299_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 148), &v, sizeof v); }  // @300_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 164), &v, sizeof v); }  // @301_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @302_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 168), &v, sizeof v); }  // @303_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @304_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 172), &v, sizeof v); }  // @305_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[8], (u32)(6798836));  // @306_43c210
  ecx = edx = 0;  // @307_43c210
  PV[9] = (u32)(eax);  // @308_43c210
  ecx = (u32)(EBP - 144);  // @309_43c210
  eax = ext_4cbe80_thiscall2(ecx, PV[9]);  // @310_43c210
  ecx = edx = 0;  // @311_43c210
  eax = (u32)(EBP - 144);  // @312_43c210
  reg.state = (s32)((u32)(3));  // @313_43c210
  PV[10] = (u32)(eax);  // @314_43c210
  ecx = (u32)(ebx + 16);  // @315_43c210
  eax = ext_4cbee0_thiscall2(ecx, PV[10]);  // @316_43c210
  ecx = edx = 0;  // @317_43c210
  ecx = (u32)(EBP - 144);  // @318_43c210
  reg.state = (s32)((u32)(4294967295));  // @319_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @320_43c210
  ecx = edx = 0;  // @321_43c210
  ecx = (u32)(EBP - 144);  // @322_43c210
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx + 181), &v, sizeof v); }  // @323_43c210
  { u32 v = (u32)((u32)(11)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @324_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @325_43c210
  ecx = edx = 0;  // @326_43c210
  reg.state = (s32)((u32)(4));  // @327_43c210
  L43c6ac:;
  eax = (u32)(EBP - 144);  // @329_43c210
  PV[11] = (u32)(eax);  // @330_43c210
  ecx = (u32)(ebx + 451);  // @331_43c210
  eax = ext_4cbee0_thiscall2(ecx, PV[11]);  // @332_43c210
  ecx = edx = 0;  // @333_43c210
  ecx = (u32)(EBP - 144);  // @334_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @335_43c210
  ecx = edx = 0;  // @336_43c210
  goto L43ceaa;  // @337_43c210
  L43c6ce:;
  ecx = (u32)(6791488);  // @339_43c210
  eax = edx;  // @340_43c210
  L43c6d5:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @342_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @343_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @344_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @345_43c210
  if (FL[0] != FL[1]) goto L43c717;  // @346_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @347_43c210
  if (FL[0] == FL[1]) goto L43c713;  // @348_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @349_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @350_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @351_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @352_43c210
  if (FL[0] != FL[1]) goto L43c717;  // @353_43c210
  eax = (eax + (u32)(2));  // @354_43c210
  FL[3] = eax;  // @355_43c210
  ecx = (ecx + (u32)(2));  // @356_43c210
  FL[3] = ecx;  // @357_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @358_43c210
  if (FL[0] != FL[1]) goto L43c6d5;  // @359_43c210
  L43c713:;
  eax = 0;  // @361_43c210
  FL[3] = eax;  // @362_43c210
  goto L43c71c;  // @363_43c210
  L43c717:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @365_43c210
  eax = (eax | (u32)(1));  // @366_43c210
  FL[3] = eax;  // @367_43c210
  L43c71c:;
  FL[2] = (eax & eax);  // @369_43c210
  if (FL[2] != 0) goto L43c82f;  // @370_43c210
  PV[12] = (u32)(esi);  // @371_43c210
  ecx = ebx;  // @372_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[12], (u32)(6798836));  // @373_43c210
  ecx = edx = 0;  // @374_43c210
  PV[13] = (u32)(esi);  // @375_43c210
  ecx = ebx;  // @376_43c210
  edi = eax;  // @377_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[13], (u32)(6798856));  // @378_43c210
  ecx = edx = 0;  // @379_43c210
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @380_43c210
  PV[14] = (u32)(eax);  // @381_43c210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @382_43c210
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @383_43c210
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @384_43c210
  eax = ((u32( *)(u32, u32))(esi))(PV[14], (u32)(6793420));  // @385_43c210
  ecx = edx = 0;  // @386_43c210
  FL[2] = (eax & eax);  // @387_43c210
  if (FL[2] != 0) goto L43c779;  // @388_43c210
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @389_43c210
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @390_43c210
  goto L43c7a0;  // @391_43c210
  L43c779:;
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @393_43c210
  eax = ((u32( *)(u32, u32))(esi))(PV[15], (u32)(6793428));  // @394_43c210
  ecx = edx = 0;  // @395_43c210
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; });  // @396_43c210
  FL[2] = (eax & eax);  // @397_43c210
  edx = (u32)(1);  // @398_43c210
  if (FL[2] == 0) ecx = edx;  // @399_43c210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @400_43c210
  L43c7a0:;
  PV[16] = (u32)(edi);  // @402_43c210
  eax = ((u32( *)(u32, u32))(esi))(PV[16], (u32)(6798864));  // @403_43c210
  ecx = edx = 0;  // @404_43c210
  FL[2] = (eax & eax);  // @405_43c210
  if (FL[2] != 0) goto L43c7c5;  // @406_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @407_43c210
  if (FL[0] == FL[1]) goto L43c7c5;  // @408_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @409_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; })) & 0xff);  // @410_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 108), &v, sizeof v); }  // @411_43c210
  L43c7c5:;
  PV[17] = (u32)(edi);  // @413_43c210
  eax = ((u32( *)(u32, u32))(esi))(PV[17], (u32)(6791600));  // @414_43c210
  ecx = edx = 0;  // @415_43c210
  FL[2] = (eax & eax);  // @416_43c210
  if (FL[2] != 0) goto L43c7ea;  // @417_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @418_43c210
  if (FL[0] == FL[1]) goto L43c7ea;  // @419_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @420_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; })) & 0xff);  // @421_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 109), &v, sizeof v); }  // @422_43c210
  L43c7ea:;
  PV[18] = (u32)(edi);  // @424_43c210
  eax = ((u32( *)(u32, u32))(esi))(PV[18], (u32)(6791588));  // @425_43c210
  ecx = edx = 0;  // @426_43c210
  FL[2] = (eax & eax);  // @427_43c210
  if (FL[2] != 0) goto L43c80f;  // @428_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @429_43c210
  if (FL[0] == FL[1]) goto L43c823;  // @430_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @431_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; })) & 0xff);  // @432_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 110), &v, sizeof v); }  // @433_43c210
  L43c80f:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @435_43c210
  if (FL[0] == FL[1]) goto L43c823;  // @436_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340960), sizeof v); (u32)v; });  // @437_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @438_43c210
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @439_43c210
  ecx = edx = 0;  // @440_43c210
  L43c823:;
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @442_43c210
  goto L43ceaa;  // @443_43c210
  L43c82f:;
  eax = (u32)(6798876);  // @445_43c210
  L43c834:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @447_43c210
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @448_43c210
  if (FL[0] != FL[1]) goto L43c854;  // @449_43c210
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @450_43c210
  if (FL[2] == 0) goto L43c850;  // @451_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @452_43c210
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @453_43c210
  if (FL[0] != FL[1]) goto L43c854;  // @454_43c210
  edx = (edx + (u32)(2));  // @455_43c210
  FL[3] = edx;  // @456_43c210
  eax = (eax + (u32)(2));  // @457_43c210
  FL[3] = eax;  // @458_43c210
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @459_43c210
  if (FL[2] != 0) goto L43c834;  // @460_43c210
  L43c850:;
  eax = 0;  // @462_43c210
  FL[3] = eax;  // @463_43c210
  goto L43c859;  // @464_43c210
  L43c854:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @466_43c210
  eax = (eax | (u32)(1));  // @467_43c210
  FL[3] = eax;  // @468_43c210
  L43c859:;
  ecx = ebx;  // @470_43c210
  FL[2] = (eax & eax);  // @471_43c210
  if (FL[2] != 0) goto L43c902;  // @472_43c210
  PV[19] = (u32)(esi);  // @473_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[19], (u32)(6798836));  // @474_43c210
  ecx = edx = 0;  // @475_43c210
  FL[2] = (eax & eax);  // @476_43c210
  if (FL[2] == 0) goto L43c887;  // @477_43c210
  PV[20] = (u32)(eax);  // @478_43c210
  ecx = (u32)(EBP - 144);  // @479_43c210
  eax = ext_4cbe80_thiscall2(ecx, PV[20]);  // @480_43c210
  ecx = edx = 0;  // @481_43c210
  reg.state = (s32)((u32)(5));  // @482_43c210
  goto L43c8c3;  // @483_43c210
  L43c887:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @485_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @486_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(231));  // @487_43c210
  ecx = edx = 0;  // @488_43c210
  PV[21] = (u32)(eax);  // @489_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @490_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[21], (u32)(6798888), (u32)(0));  // @491_43c210
  ecx = edx = 0;  // @492_43c210
  ecx = (u32)(EBP - 144);  // @493_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @494_43c210
  ecx = edx = 0;  // @495_43c210
  reg.state = (s32)((u32)(6));  // @496_43c210
  L43c8c3:;
  eax = (u32)(EBP - 144);  // @498_43c210
  esi = (u32)(ebx + 195);  // @499_43c210
  PV[22] = (u32)(eax);  // @500_43c210
  ecx = esi;  // @501_43c210
  eax = ext_4cbee0_thiscall2(ecx, PV[22]);  // @502_43c210
  ecx = edx = 0;  // @503_43c210
  ecx = (u32)(EBP - 144);  // @504_43c210
  reg.state = (s32)((u32)(4294967295));  // @505_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @506_43c210
  ecx = edx = 0;  // @507_43c210
  ecx = esi;  // @508_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @509_43c210
    // @510_43c210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 191), &v, sizeof v); }  // @511_43c210
  L43c8f6:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @513_43c210
  goto L43ceaa;  // @514_43c210
  L43c902:;
  PVX = 6798976u;
  goto L43cea5;  // @516_43c210
  L43c90c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @518_43c210
  ecx = (u32)(6799020);  // @519_43c210
  eax = edx;  // @520_43c210
  L43c916:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @522_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @523_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @524_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @525_43c210
  if (FL[0] != FL[1]) goto L43c958;  // @526_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @527_43c210
  if (FL[0] == FL[1]) goto L43c954;  // @528_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @529_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @530_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @531_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @532_43c210
  if (FL[0] != FL[1]) goto L43c958;  // @533_43c210
  eax = (eax + (u32)(2));  // @534_43c210
  FL[3] = eax;  // @535_43c210
  ecx = (ecx + (u32)(2));  // @536_43c210
  FL[3] = ecx;  // @537_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @538_43c210
  if (FL[0] != FL[1]) goto L43c916;  // @539_43c210
  L43c954:;
  eax = 0;  // @541_43c210
  FL[3] = eax;  // @542_43c210
  goto L43c95d;  // @543_43c210
  L43c958:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @545_43c210
  eax = (eax | (u32)(1));  // @546_43c210
  FL[3] = eax;  // @547_43c210
  L43c95d:;
  FL[2] = (eax & eax);  // @549_43c210
  if (FL[2] != 0) goto L43ca34;  // @550_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; });  // @551_43c210
  ecx = ebx;  // @552_43c210
  PV[23] = (u32)(esi);  // @553_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 144), &v, sizeof v); }  // @554_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; });  // @555_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 160), &v, sizeof v); }  // @556_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[23], (u32)(6791480));  // @557_43c210
  ecx = edx = 0;  // @558_43c210
  esi = eax;  // @559_43c210
  FL[2] = (esi & esi);  // @560_43c210
  if (FL[2] == 0) goto L43ccd8;  // @561_43c210
  PV[24] = (u32)(esi);  // @562_43c210
  ecx = ebx;  // @563_43c210
  eax = ext_4321c0_thiscall2(ecx, PV[24]);  // @564_43c210
  ecx = edx = 0;  // @565_43c210
  ecx = eax;  // @566_43c210
  FL[0] = ecx; FL[1] = (u32)(-1);  // @567_43c210
  if (FL[0] != FL[1]) goto L43c9d6;  // @568_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @569_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @570_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(266));  // @571_43c210
  ecx = edx = 0;  // @572_43c210
  PV[25] = (u32)(esi);  // @573_43c210
  PV[26] = (u32)(eax);  // @574_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @575_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[26], (u32)(6799024), PV[25]);  // @576_43c210
  ecx = edx = 0;  // @577_43c210
  goto L43ceaa;  // @578_43c210
  L43c9d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; });  // @580_43c210
  FL[0] = eax; FL[1] = (u32)(4);  // @581_43c210
  if ((s32)FL[0] >= (s32)FL[1]) goto L43c9fa;  // @582_43c210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 144), &v, sizeof v); }  // @583_43c210
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 579), &v, sizeof v); }  // @584_43c210
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; });  // @585_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @586_43c210
  goto L43ceaa;  // @587_43c210
  L43c9fa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @589_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @590_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(277));  // @591_43c210
  ecx = edx = 0;  // @592_43c210
  esi = eax;  // @593_43c210
  ecx = (u32)(ebx + 16);  // @594_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @595_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @596_43c210
    // @597_43c210
  PV[27] = (u32)(eax);  // @598_43c210
  PV[28] = (u32)(esi);  // @599_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[28], (u32)(6799084), PV[27]);  // @600_43c210
  ecx = edx = 0;  // @601_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @602_43c210
  goto L43ceaa;  // @603_43c210
  L43ca34:;
  ecx = (u32)(6799128);  // @605_43c210
  eax = edx;  // @606_43c210
  L43ca40:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @608_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @609_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @610_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @611_43c210
  if (FL[0] != FL[1]) goto L43ca82;  // @612_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @613_43c210
  if (FL[0] == FL[1]) goto L43ca7e;  // @614_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @615_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @616_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @617_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @618_43c210
  if (FL[0] != FL[1]) goto L43ca82;  // @619_43c210
  eax = (eax + (u32)(2));  // @620_43c210
  FL[3] = eax;  // @621_43c210
  ecx = (ecx + (u32)(2));  // @622_43c210
  FL[3] = ecx;  // @623_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @624_43c210
  if (FL[0] != FL[1]) goto L43ca40;  // @625_43c210
  L43ca7e:;
  eax = 0;  // @627_43c210
  FL[3] = eax;  // @628_43c210
  goto L43ca87;  // @629_43c210
  L43ca82:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @631_43c210
  eax = (eax | (u32)(1));  // @632_43c210
  FL[3] = eax;  // @633_43c210
  L43ca87:;
  FL[2] = (eax & eax);  // @635_43c210
  if (FL[2] != 0) goto L43cb46;  // @636_43c210
  PV[29] = (u32)(esi);  // @637_43c210
  ecx = ebx;  // @638_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[29], (u32)(6791480));  // @639_43c210
  ecx = edx = 0;  // @640_43c210
  esi = eax;  // @641_43c210
  FL[2] = (esi & esi);  // @642_43c210
  if (FL[2] == 0) goto L43ccd8;  // @643_43c210
  PV[30] = (u32)(esi);  // @644_43c210
  ecx = ebx;  // @645_43c210
  eax = ext_4321c0_thiscall2(ecx, PV[30]);  // @646_43c210
  ecx = edx = 0;  // @647_43c210
  ecx = eax;  // @648_43c210
  FL[0] = ecx; FL[1] = (u32)(-1);  // @649_43c210
  if (FL[0] != FL[1]) goto L43cae8;  // @650_43c210
  PV[31] = (u32)(esi);  // @651_43c210
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))(PV[31]);  // @652_43c210
  ecx = edx = 0;  // @653_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @654_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @655_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(296));  // @656_43c210
  ecx = edx = 0;  // @657_43c210
  PV[32] = (u32)(esi);  // @658_43c210
  PV[33] = (u32)(eax);  // @659_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @660_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[33], (u32)(6799024), PV[32]);  // @661_43c210
  ecx = edx = 0;  // @662_43c210
  goto L43ceaa;  // @663_43c210
  L43cae8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 583), sizeof v); (u32)v; });  // @665_43c210
  FL[0] = eax; FL[1] = (u32)(4);  // @666_43c210
  if ((s32)FL[0] >= (s32)FL[1]) goto L43cb0c;  // @667_43c210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 160), &v, sizeof v); }  // @668_43c210
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 583), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 583), &v, sizeof v); }  // @669_43c210
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 583), sizeof v); (u32)v; });  // @670_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @671_43c210
  goto L43ceaa;  // @672_43c210
  L43cb0c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @674_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @675_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(307));  // @676_43c210
  ecx = edx = 0;  // @677_43c210
  esi = eax;  // @678_43c210
  ecx = (u32)(ebx + 16);  // @679_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @680_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @681_43c210
    // @682_43c210
  PV[34] = (u32)(eax);  // @683_43c210
  PV[35] = (u32)(esi);  // @684_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[35], (u32)(6799084), PV[34]);  // @685_43c210
  ecx = edx = 0;  // @686_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @687_43c210
  goto L43ceaa;  // @688_43c210
  L43cb46:;
  ecx = (u32)(6791440);  // @690_43c210
  eax = edx;  // @691_43c210
  L43cb50:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @693_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @694_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @695_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @696_43c210
  if (FL[0] != FL[1]) goto L43cb92;  // @697_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @698_43c210
  if (FL[0] == FL[1]) goto L43cb8e;  // @699_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @700_43c210
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @701_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @702_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @703_43c210
  if (FL[0] != FL[1]) goto L43cb92;  // @704_43c210
  eax = (eax + (u32)(2));  // @705_43c210
  FL[3] = eax;  // @706_43c210
  ecx = (ecx + (u32)(2));  // @707_43c210
  FL[3] = ecx;  // @708_43c210
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @709_43c210
  if (FL[0] != FL[1]) goto L43cb50;  // @710_43c210
  L43cb8e:;
  eax = 0;  // @712_43c210
  FL[3] = eax;  // @713_43c210
  goto L43cb97;  // @714_43c210
  L43cb92:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @716_43c210
  eax = (eax | (u32)(1));  // @717_43c210
  FL[3] = eax;  // @718_43c210
  L43cb97:;
  FL[2] = (eax & eax);  // @720_43c210
  if (FL[2] != 0) goto L43cc26;  // @721_43c210
  PV[36] = (u32)(esi);  // @722_43c210
  ecx = ebx;  // @723_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[36], (u32)(6791500));  // @724_43c210
  ecx = edx = 0;  // @725_43c210
  esi = eax;  // @726_43c210
  FL[2] = (esi & esi);  // @727_43c210
  if (FL[2] == 0) goto L43cbec;  // @728_43c210
  ecx = esi;  // @729_43c210
  edx = (u32)(ecx + 1);  // @730_43c210
  L43cbb7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @732_43c210
  ecx = (ecx + 1);  // @733_43c210
  FL[3] = ecx;  // @734_43c210
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @735_43c210
  if (FL[2] != 0) goto L43cbb7;  // @736_43c210
  ecx = (ecx - edx);  // @737_43c210
  FL[3] = ecx;  // @738_43c210
  eax = (u32)(ecx + 1);  // @739_43c210
  PV[37] = (u32)(eax);  // @740_43c210
  eax = ext_41e290_cdecl1(PV[37]);  // @741_43c210
  ecx = edx = 0;  // @742_43c210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 183), &v, sizeof v); }  // @743_43c210
  L43cbd2:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @745_43c210
  esi = (u32)(esi + 1);  // @746_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @747_43c210
  eax = (u32)(eax + 1);  // @748_43c210
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @749_43c210
  if (FL[2] != 0) goto L43cbd2;  // @750_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @751_43c210
  goto L43ceaa;  // @752_43c210
  L43cbec:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @754_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @755_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(326));  // @756_43c210
  ecx = edx = 0;  // @757_43c210
  esi = eax;  // @758_43c210
  ecx = (u32)(ebx + 16);  // @759_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @760_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @761_43c210
    // @762_43c210
  PV[38] = (u32)(eax);  // @763_43c210
  PV[39] = (u32)(esi);  // @764_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[39], (u32)(6799136), PV[38]);  // @765_43c210
  ecx = edx = 0;  // @766_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @767_43c210
  goto L43ceaa;  // @768_43c210
  L43cc26:;
  eax = (u32)(6791508);  // @770_43c210
  L43cc30:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @772_43c210
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @773_43c210
  if (FL[0] != FL[1]) goto L43cc50;  // @774_43c210
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @775_43c210
  if (FL[2] == 0) goto L43cc4c;  // @776_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @777_43c210
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @778_43c210
  if (FL[0] != FL[1]) goto L43cc50;  // @779_43c210
  edx = (edx + (u32)(2));  // @780_43c210
  FL[3] = edx;  // @781_43c210
  eax = (eax + (u32)(2));  // @782_43c210
  FL[3] = eax;  // @783_43c210
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @784_43c210
  if (FL[2] != 0) goto L43cc30;  // @785_43c210
  L43cc4c:;
  eax = 0;  // @787_43c210
  FL[3] = eax;  // @788_43c210
  goto L43cc55;  // @789_43c210
  L43cc50:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @791_43c210
  eax = (eax | (u32)(1));  // @792_43c210
  FL[3] = eax;  // @793_43c210
  L43cc55:;
  ecx = ebx;  // @795_43c210
  FL[2] = (eax & eax);  // @796_43c210
  if (FL[2] != 0) goto L43cce4;  // @797_43c210
  PV[40] = (u32)(esi);  // @798_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[40], (u32)(6791500));  // @799_43c210
  ecx = edx = 0;  // @800_43c210
  esi = eax;  // @801_43c210
  FL[2] = (esi & esi);  // @802_43c210
  if (FL[2] == 0) goto L43ccaa;  // @803_43c210
  ecx = esi;  // @804_43c210
  edx = (u32)(ecx + 1);  // @805_43c210
  L43cc75:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @807_43c210
  ecx = (ecx + 1);  // @808_43c210
  FL[3] = ecx;  // @809_43c210
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @810_43c210
  if (FL[2] != 0) goto L43cc75;  // @811_43c210
  ecx = (ecx - edx);  // @812_43c210
  FL[3] = ecx;  // @813_43c210
  eax = (u32)(ecx + 1);  // @814_43c210
  PV[41] = (u32)(eax);  // @815_43c210
  eax = ext_41e290_cdecl1(PV[41]);  // @816_43c210
  ecx = edx = 0;  // @817_43c210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 187), &v, sizeof v); }  // @818_43c210
  L43cc90:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @820_43c210
  esi = (u32)(esi + 1);  // @821_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @822_43c210
  eax = (u32)(eax + 1);  // @823_43c210
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @824_43c210
  if (FL[2] != 0) goto L43cc90;  // @825_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @826_43c210
  goto L43ceaa;  // @827_43c210
  L43ccaa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @829_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @830_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(343));  // @831_43c210
  ecx = edx = 0;  // @832_43c210
  esi = eax;  // @833_43c210
  ecx = (u32)(ebx + 16);  // @834_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @835_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @836_43c210
    // @837_43c210
  PV[42] = (u32)(eax);  // @838_43c210
  PV[43] = (u32)(esi);  // @839_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[43], (u32)(6799136), PV[42]);  // @840_43c210
  ecx = edx = 0;  // @841_43c210
  L43ccd8:;
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @843_43c210
  goto L43ceaa;  // @844_43c210
  L43cce4:;
  PVX = 6799176u;
  goto L43cea5;  // @846_43c210
  L43ccee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @848_43c210
  ecx = (u32)(6791440);  // @849_43c210
  L43ccf6:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @851_43c210
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @852_43c210
  if (FL[0] != FL[1]) goto L43cd16;  // @853_43c210
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @854_43c210
  if (FL[2] == 0) goto L43cd12;  // @855_43c210
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @856_43c210
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @857_43c210
  if (FL[0] != FL[1]) goto L43cd16;  // @858_43c210
  eax = (eax + (u32)(2));  // @859_43c210
  FL[3] = eax;  // @860_43c210
  ecx = (ecx + (u32)(2));  // @861_43c210
  FL[3] = ecx;  // @862_43c210
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @863_43c210
  if (FL[2] != 0) goto L43ccf6;  // @864_43c210
  L43cd12:;
  eax = 0;  // @866_43c210
  FL[3] = eax;  // @867_43c210
  goto L43cd1b;  // @868_43c210
  L43cd16:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @870_43c210
  eax = (eax | (u32)(1));  // @871_43c210
  FL[3] = eax;  // @872_43c210
  L43cd1b:;
  FL[2] = (eax & eax);  // @874_43c210
  if (FL[2] != 0) goto L43cdb8;  // @875_43c210
  PV[44] = (u32)(esi);  // @876_43c210
  ecx = ebx;  // @877_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[44], (u32)(6798836));  // @878_43c210
  ecx = edx = 0;  // @879_43c210
  ecx = (u32)(ebx + 451);  // @880_43c210
  edi = eax;  // @881_43c210
  eax = ext_4cc5f0_thiscall1(ecx);  // @882_43c210
  ecx = edx = 0;  // @883_43c210
  FL[2] = (eax & eax);  // @884_43c210
  if (FL[2] == 0) goto L43cd7c;  // @885_43c210
  ecx = (u32)(EBP - 144);  // @886_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6799224));  // @887_43c210
  ecx = edx = 0;  // @888_43c210
  eax = (u32)(EBP - 144);  // @889_43c210
  reg.state = (s32)((u32)(7));  // @890_43c210
  PV[45] = (u32)(eax);  // @891_43c210
  ecx = (u32)(ebx + 451);  // @892_43c210
  eax = ext_4cc2c0_thiscall2(ecx, PV[45]);  // @893_43c210
  ecx = edx = 0;  // @894_43c210
  ecx = (u32)(EBP - 144);  // @895_43c210
  reg.state = (s32)((u32)(4294967295));  // @896_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @897_43c210
  ecx = edx = 0;  // @898_43c210
  L43cd7c:;
  PV[46] = (u32)(edi);  // @900_43c210
  ecx = (u32)(EBP - 144);  // @901_43c210
  eax = ext_4cbe80_thiscall2(ecx, PV[46]);  // @902_43c210
  ecx = edx = 0;  // @903_43c210
  eax = (u32)(EBP - 144);  // @904_43c210
  reg.state = (s32)((u32)(8));  // @905_43c210
  PV[47] = (u32)(eax);  // @906_43c210
  ecx = (u32)(ebx + 451);  // @907_43c210
  eax = ext_4cc2c0_thiscall2(ecx, PV[47]);  // @908_43c210
  ecx = edx = 0;  // @909_43c210
  ecx = (u32)(EBP - 144);  // @910_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @911_43c210
  ecx = edx = 0;  // @912_43c210
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @913_43c210
  goto L43ceaa;  // @914_43c210
  L43cdb8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @916_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @917_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(370));  // @918_43c210
  ecx = edx = 0;  // @919_43c210
  esi = eax;  // @920_43c210
  ecx = (u32)(ebx + 16);  // @921_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @922_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @923_43c210
    // @924_43c210
  PV[48] = (u32)(eax);  // @925_43c210
  PV[49] = (u32)(esi);  // @926_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[49], (u32)(6799228), PV[48]);  // @927_43c210
  ecx = edx = 0;  // @928_43c210
  goto L43ceaa;  // @929_43c210
  L43cdeb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @931_43c210
  ecx = (u32)(6799288);  // @932_43c210
  L43cdf3:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @934_43c210
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @935_43c210
  if (FL[0] != FL[1]) goto L43ce13;  // @936_43c210
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @937_43c210
  if (FL[2] == 0) goto L43ce0f;  // @938_43c210
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @939_43c210
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @940_43c210
  if (FL[0] != FL[1]) goto L43ce13;  // @941_43c210
  eax = (eax + (u32)(2));  // @942_43c210
  FL[3] = eax;  // @943_43c210
  ecx = (ecx + (u32)(2));  // @944_43c210
  FL[3] = ecx;  // @945_43c210
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @946_43c210
  if (FL[2] != 0) goto L43cdf3;  // @947_43c210
  L43ce0f:;
  eax = 0;  // @949_43c210
  FL[3] = eax;  // @950_43c210
  goto L43ce18;  // @951_43c210
  L43ce13:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @953_43c210
  eax = (eax | (u32)(1));  // @954_43c210
  FL[3] = eax;  // @955_43c210
  L43ce18:;
  FL[2] = (eax & eax);  // @957_43c210
  if (FL[2] != 0) goto L43ce62;  // @958_43c210
  PV[50] = (u32)(esi);  // @959_43c210
  ecx = ebx;  // @960_43c210
  eax = ext_61bac0_thiscall3(ecx, PV[50], (u32)(6791480));  // @961_43c210
  ecx = edx = 0;  // @962_43c210
  PV[51] = (u32)(eax);  // @963_43c210
  ecx = (u32)(EBP - 272);  // @964_43c210
  eax = ext_4cbe80_thiscall2(ecx, PV[51]);  // @965_43c210
  ecx = edx = 0;  // @966_43c210
  eax = (u32)(EBP - 272);  // @967_43c210
  reg.state = (s32)((u32)(9));  // @968_43c210
  PV[52] = (u32)(eax);  // @969_43c210
  ecx = (u32)(ebx + 451);  // @970_43c210
  eax = ext_4cbee0_thiscall2(ecx, PV[52]);  // @971_43c210
  ecx = edx = 0;  // @972_43c210
  ecx = (u32)(EBP - 272);  // @973_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @974_43c210
  ecx = edx = 0;  // @975_43c210
  { u32 v = (u32)((u32)(12)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @976_43c210
  goto L43ceaa;  // @977_43c210
  L43ce62:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @979_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @980_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(387));  // @981_43c210
  ecx = edx = 0;  // @982_43c210
  esi = eax;  // @983_43c210
  ecx = (u32)(ebx + 16);  // @984_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @985_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @986_43c210
    // @987_43c210
  PV[53] = (u32)(eax);  // @988_43c210
  PV[54] = (u32)(esi);  // @989_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[54], (u32)(6799296), PV[53]);  // @990_43c210
  ecx = edx = 0;  // @991_43c210
  goto L43ceaa;  // @992_43c210
  L43ce92:;
  PVX = 6799360u;
  goto L43cea5;  // @994_43c210
  L43ce99:;
  PVX = 6799400u;
  goto L43cea5;  // @996_43c210
  L43cea0:;
  PVX = 0x67c050u;
  L43cea5:;
  eax = ext_43b9a0_thiscall2(ecx, PVX);  // @999_43c210
  ecx = edx = 0;  // @1000_43c210
  L43ceaa:;
  SEH_LEAVE();  // @1002_43c210
  ext_633654(G(u32, 0x6f5630));  // @1003_43c210
  return eax;  // @1004_43c210
}
PCREG(43c210, lifted_43c210);

