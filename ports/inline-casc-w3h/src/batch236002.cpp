// batch236002.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_5af130_fastcall3(u32, u32, u32) __asm__("ext_5af130");
extern "C" u32 THISCALL ext_5678e0_thiscall3(u32, u32, u32) __asm__("ext_5678e0");
extern "C" u32 THISCALL ext_589c20_thiscall2(u32, u32) __asm__("ext_589c20");
extern "C" u32 THISCALL ext_59a5e0_thiscall2(u32, u32) __asm__("ext_59a5e0");
extern "C" u32 THISCALL ext_5a4590_thiscall2(u32, u32) __asm__("ext_5a4590");
extern "C" u32 THISCALL ext_5a46f0_thiscall2(u32, u32) __asm__("ext_5a46f0");
extern "C" u32 THISCALL ext_5acfa0_thiscall1(u32) __asm__("ext_5acfa0");
extern "C" u32 THISCALL ext_5adec0_thiscall2(u32, u32) __asm__("ext_5adec0");
extern "C" u32 THISCALL ext_5aedf0_thiscall2(u32, u32) __asm__("ext_5aedf0");
extern "C" u32 ext_42ac56_cdecl3(...) __asm__("ext_42ac56");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_567930(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_567930
  edi = ecx;  // @1_567930
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @2_567930
  eax = (u32)(EBP - 28);  // @3_567930
  PV[0] = (u32)(eax);  // @4_567930
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @5_567930
  ecx = (u32)(esi + 87);  // @6_567930
  eax = ext_5adec0_thiscall2(ecx, PV[0]);  // @7_567930
  ecx = edx = 0;  // @8_567930
  ecx = (u32)(esi + 945);  // @9_567930
  eax = ext_5acfa0_thiscall1(ecx);  // @10_567930
    // @11_567930
  esi = 0;  // @12_567930
  FL[3] = esi;  // @13_567930
  FL[2] = (eax & eax);  // @14_567930
  if (FL[2] == 0) goto L56797e;  // @15_567930
  ecx = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @16_567930
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }));  // @17_567930
  esi = (u32)(ecx - 8);  // @18_567930
  esi = (u32)(ecx + esi*4);  // @19_567930
  esi = (u32)(eax + esi*2);  // @20_567930
  L56797e:;
  ebx = 0;  // @22_567930
  FL[3] = ebx;  // @23_567930
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); FL[1] = ebx;  // @24_567930
  if ((s32)FL[0] <= (s32)FL[1]) goto L567e80;  // @25_567930
  L567990:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @27_567930
  eax = (eax + (u32)(-21));  // @28_567930
  FL[3] = eax;  // @29_567930
  FL[0] = eax; FL[1] = (u32)(61);  // @30_567930
  if (FL[0] > FL[1]) goto L567e76;  // @31_567930
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5668544), sizeof v); (u32)v; });  // @32_567930
  switch (eax) {  // @33_567930
  case 0: goto L5679ae;  // @34_567930
  case 1: goto L5679ee;  // @35_567930
  case 2: goto L567a76;  // @36_567930
  case 3: goto L567ab6;  // @37_567930
  case 4: goto L567af6;  // @38_567930
  case 5: goto L567b7e;  // @39_567930
  case 6: goto L567bbe;  // @40_567930
  case 7: goto L567bfe;  // @41_567930
  case 8: goto L567c3e;  // @42_567930
  case 9: goto L567c7e;  // @43_567930
  case 10: goto L567e76;  // @44_567930
  default: __builtin_trap(); }  // @45_567930
  L5679ae:;
  ecx = (u32)(edi + 468);  // @47_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(16));  // @48_567930
  edx = 0;  // @49_567930
  FL[2] = (eax & eax);  // @50_567930
  if (FL[2] != 0) goto L567e63;  // @51_567930
  ecx = (u32)(edi + 384);  // @52_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(16));  // @53_567930
  edx = 0;  // @54_567930
  FL[2] = (eax & eax);  // @55_567930
  if (FL[2] == 0) goto L567e63;  // @56_567930
  PV[1] = (u32)(eax);  // @57_567930
  ecx = (u32)(edi + 468);  // @58_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[1]);  // @59_567930
  edx = 0;  // @60_567930
  eax = (u32)(16);  // @61_567930
  goto L567e65;  // @62_567930
  L5679ee:;
  ecx = (u32)(edi + 468);  // @64_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(3));  // @65_567930
  edx = 0;  // @66_567930
  FL[2] = (eax & eax);  // @67_567930
  if (FL[2] != 0) goto L567a23;  // @68_567930
  ecx = (u32)(edi + 384);  // @69_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(3));  // @70_567930
  edx = 0;  // @71_567930
  FL[2] = (eax & eax);  // @72_567930
  if (FL[2] == 0) goto L567a23;  // @73_567930
  PV[2] = (u32)(eax);  // @74_567930
  ecx = (u32)(edi + 468);  // @75_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[2]);  // @76_567930
  edx = 0;  // @77_567930
  eax = (u32)(3);  // @78_567930
  goto L567a25;  // @79_567930
  L567a23:;
  eax = 0;  // @81_567930
  FL[3] = eax;  // @82_567930
  L567a25:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @84_567930
  if (FL[0] != FL[1]) goto L567a36;  // @85_567930
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @86_567930
  ecx = edi;  // @87_567930
  PV[4] = (u32)(eax);  // @88_567930
  eax = ext_5678e0_thiscall3(ecx, PV[4], PV[3]);  // @89_567930
  ecx = edx = 0;  // @90_567930
  L567a36:;
  ecx = (u32)(edi + 468);  // @92_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(5));  // @93_567930
  edx = 0;  // @94_567930
  FL[2] = (eax & eax);  // @95_567930
  if (FL[2] != 0) goto L567e63;  // @96_567930
  ecx = (u32)(edi + 384);  // @97_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(5));  // @98_567930
  edx = 0;  // @99_567930
  FL[2] = (eax & eax);  // @100_567930
  if (FL[2] == 0) goto L567e63;  // @101_567930
  PV[5] = (u32)(eax);  // @102_567930
  ecx = (u32)(edi + 468);  // @103_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[5]);  // @104_567930
  edx = 0;  // @105_567930
  eax = (u32)(5);  // @106_567930
  goto L567e65;  // @107_567930
  L567a76:;
  ecx = (u32)(edi + 468);  // @109_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(6));  // @110_567930
  edx = 0;  // @111_567930
  FL[2] = (eax & eax);  // @112_567930
  if (FL[2] != 0) goto L567e63;  // @113_567930
  ecx = (u32)(edi + 384);  // @114_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(6));  // @115_567930
  edx = 0;  // @116_567930
  FL[2] = (eax & eax);  // @117_567930
  if (FL[2] == 0) goto L567e63;  // @118_567930
  PV[6] = (u32)(eax);  // @119_567930
  ecx = (u32)(edi + 468);  // @120_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[6]);  // @121_567930
  edx = 0;  // @122_567930
  eax = (u32)(6);  // @123_567930
  goto L567e65;  // @124_567930
  L567ab6:;
  ecx = (u32)(edi + 468);  // @126_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(7));  // @127_567930
  edx = 0;  // @128_567930
  FL[2] = (eax & eax);  // @129_567930
  if (FL[2] != 0) goto L567e63;  // @130_567930
  ecx = (u32)(edi + 384);  // @131_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(7));  // @132_567930
  edx = 0;  // @133_567930
  FL[2] = (eax & eax);  // @134_567930
  if (FL[2] == 0) goto L567e63;  // @135_567930
  PV[7] = (u32)(eax);  // @136_567930
  ecx = (u32)(edi + 468);  // @137_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[7]);  // @138_567930
  edx = 0;  // @139_567930
  eax = (u32)(7);  // @140_567930
  goto L567e65;  // @141_567930
  L567af6:;
  ecx = (u32)(edi + 468);  // @143_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(14));  // @144_567930
  edx = 0;  // @145_567930
  FL[2] = (eax & eax);  // @146_567930
  if (FL[2] != 0) goto L567b2b;  // @147_567930
  ecx = (u32)(edi + 384);  // @148_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(14));  // @149_567930
  edx = 0;  // @150_567930
  FL[2] = (eax & eax);  // @151_567930
  if (FL[2] == 0) goto L567b2b;  // @152_567930
  PV[8] = (u32)(eax);  // @153_567930
  ecx = (u32)(edi + 468);  // @154_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[8]);  // @155_567930
  edx = 0;  // @156_567930
  eax = (u32)(14);  // @157_567930
  goto L567b2d;  // @158_567930
  L567b2b:;
  eax = 0;  // @160_567930
  FL[3] = eax;  // @161_567930
  L567b2d:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @163_567930
  if (FL[0] != FL[1]) goto L567b3e;  // @164_567930
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @165_567930
  ecx = edi;  // @166_567930
  PV[10] = (u32)(eax);  // @167_567930
  eax = ext_5678e0_thiscall3(ecx, PV[10], PV[9]);  // @168_567930
  ecx = edx = 0;  // @169_567930
  L567b3e:;
  ecx = (u32)(edi + 468);  // @171_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(13));  // @172_567930
  edx = 0;  // @173_567930
  FL[2] = (eax & eax);  // @174_567930
  if (FL[2] != 0) goto L567e63;  // @175_567930
  ecx = (u32)(edi + 384);  // @176_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(13));  // @177_567930
  edx = 0;  // @178_567930
  FL[2] = (eax & eax);  // @179_567930
  if (FL[2] == 0) goto L567e63;  // @180_567930
  PV[11] = (u32)(eax);  // @181_567930
  ecx = (u32)(edi + 468);  // @182_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[11]);  // @183_567930
  edx = 0;  // @184_567930
  eax = (u32)(13);  // @185_567930
  goto L567e65;  // @186_567930
  L567b7e:;
  ecx = (u32)(edi + 468);  // @188_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(8));  // @189_567930
  edx = 0;  // @190_567930
  FL[2] = (eax & eax);  // @191_567930
  if (FL[2] != 0) goto L567e63;  // @192_567930
  ecx = (u32)(edi + 384);  // @193_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(8));  // @194_567930
  edx = 0;  // @195_567930
  FL[2] = (eax & eax);  // @196_567930
  if (FL[2] == 0) goto L567e63;  // @197_567930
  PV[12] = (u32)(eax);  // @198_567930
  ecx = (u32)(edi + 468);  // @199_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[12]);  // @200_567930
  edx = 0;  // @201_567930
  eax = (u32)(8);  // @202_567930
  goto L567e65;  // @203_567930
  L567bbe:;
  ecx = (u32)(edi + 468);  // @205_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(4));  // @206_567930
  edx = 0;  // @207_567930
  FL[2] = (eax & eax);  // @208_567930
  if (FL[2] != 0) goto L567e63;  // @209_567930
  ecx = (u32)(edi + 384);  // @210_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(4));  // @211_567930
  edx = 0;  // @212_567930
  FL[2] = (eax & eax);  // @213_567930
  if (FL[2] == 0) goto L567e63;  // @214_567930
  PV[13] = (u32)(eax);  // @215_567930
  ecx = (u32)(edi + 468);  // @216_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[13]);  // @217_567930
  edx = 0;  // @218_567930
  eax = (u32)(4);  // @219_567930
  goto L567e65;  // @220_567930
  L567bfe:;
  ecx = (u32)(edi + 468);  // @222_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(15));  // @223_567930
  edx = 0;  // @224_567930
  FL[2] = (eax & eax);  // @225_567930
  if (FL[2] != 0) goto L567e63;  // @226_567930
  ecx = (u32)(edi + 384);  // @227_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(15));  // @228_567930
  edx = 0;  // @229_567930
  FL[2] = (eax & eax);  // @230_567930
  if (FL[2] == 0) goto L567e63;  // @231_567930
  PV[14] = (u32)(eax);  // @232_567930
  ecx = (u32)(edi + 468);  // @233_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[14]);  // @234_567930
  edx = 0;  // @235_567930
  eax = (u32)(15);  // @236_567930
  goto L567e65;  // @237_567930
  L567c3e:;
  ecx = (u32)(edi + 468);  // @239_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(11));  // @240_567930
  edx = 0;  // @241_567930
  FL[2] = (eax & eax);  // @242_567930
  if (FL[2] != 0) goto L567e63;  // @243_567930
  ecx = (u32)(edi + 384);  // @244_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(11));  // @245_567930
  edx = 0;  // @246_567930
  FL[2] = (eax & eax);  // @247_567930
  if (FL[2] == 0) goto L567e63;  // @248_567930
  PV[15] = (u32)(eax);  // @249_567930
  ecx = (u32)(edi + 468);  // @250_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[15]);  // @251_567930
  edx = 0;  // @252_567930
  eax = (u32)(11);  // @253_567930
  goto L567e65;  // @254_567930
  L567c7e:;
  ecx = (u32)(edi + 468);  // @256_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(13));  // @257_567930
  edx = 0;  // @258_567930
  FL[2] = (eax & eax);  // @259_567930
  if (FL[2] != 0) goto L567cb3;  // @260_567930
  ecx = (u32)(edi + 384);  // @261_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(13));  // @262_567930
  edx = 0;  // @263_567930
  FL[2] = (eax & eax);  // @264_567930
  if (FL[2] == 0) goto L567cb3;  // @265_567930
  PV[16] = (u32)(eax);  // @266_567930
  ecx = (u32)(edi + 468);  // @267_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[16]);  // @268_567930
  edx = 0;  // @269_567930
  eax = (u32)(13);  // @270_567930
  goto L567cb5;  // @271_567930
  L567cb3:;
  eax = 0;  // @273_567930
  FL[3] = eax;  // @274_567930
  L567cb5:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @276_567930
  if (FL[0] != FL[1]) goto L567cc6;  // @277_567930
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @278_567930
  ecx = edi;  // @279_567930
  PV[18] = (u32)(eax);  // @280_567930
  eax = ext_5678e0_thiscall3(ecx, PV[18], PV[17]);  // @281_567930
  ecx = edx = 0;  // @282_567930
  L567cc6:;
  ecx = (u32)(edi + 468);  // @284_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(16));  // @285_567930
  edx = 0;  // @286_567930
  FL[2] = (eax & eax);  // @287_567930
  if (FL[2] != 0) goto L567cfb;  // @288_567930
  ecx = (u32)(edi + 384);  // @289_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(16));  // @290_567930
  edx = 0;  // @291_567930
  FL[2] = (eax & eax);  // @292_567930
  if (FL[2] == 0) goto L567cfb;  // @293_567930
  PV[19] = (u32)(eax);  // @294_567930
  ecx = (u32)(edi + 468);  // @295_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[19]);  // @296_567930
  edx = 0;  // @297_567930
  eax = (u32)(16);  // @298_567930
  goto L567cfd;  // @299_567930
  L567cfb:;
  eax = 0;  // @301_567930
  FL[3] = eax;  // @302_567930
  L567cfd:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @304_567930
  if (FL[0] != FL[1]) goto L567d0e;  // @305_567930
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @306_567930
  ecx = edi;  // @307_567930
  PV[21] = (u32)(eax);  // @308_567930
  eax = ext_5678e0_thiscall3(ecx, PV[21], PV[20]);  // @309_567930
  ecx = edx = 0;  // @310_567930
  L567d0e:;
  ecx = (u32)(edi + 468);  // @312_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(6));  // @313_567930
  edx = 0;  // @314_567930
  FL[2] = (eax & eax);  // @315_567930
  if (FL[2] != 0) goto L567d43;  // @316_567930
  ecx = (u32)(edi + 384);  // @317_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(6));  // @318_567930
  edx = 0;  // @319_567930
  FL[2] = (eax & eax);  // @320_567930
  if (FL[2] == 0) goto L567d43;  // @321_567930
  PV[22] = (u32)(eax);  // @322_567930
  ecx = (u32)(edi + 468);  // @323_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[22]);  // @324_567930
  edx = 0;  // @325_567930
  eax = (u32)(6);  // @326_567930
  goto L567d45;  // @327_567930
  L567d43:;
  eax = 0;  // @329_567930
  FL[3] = eax;  // @330_567930
  L567d45:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @332_567930
  if (FL[0] != FL[1]) goto L567d56;  // @333_567930
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @334_567930
  ecx = edi;  // @335_567930
  PV[24] = (u32)(eax);  // @336_567930
  eax = ext_5678e0_thiscall3(ecx, PV[24], PV[23]);  // @337_567930
  ecx = edx = 0;  // @338_567930
  L567d56:;
  ecx = (u32)(edi + 468);  // @340_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(7));  // @341_567930
  edx = 0;  // @342_567930
  FL[2] = (eax & eax);  // @343_567930
  if (FL[2] != 0) goto L567d8b;  // @344_567930
  ecx = (u32)(edi + 384);  // @345_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(7));  // @346_567930
  edx = 0;  // @347_567930
  FL[2] = (eax & eax);  // @348_567930
  if (FL[2] == 0) goto L567d8b;  // @349_567930
  PV[25] = (u32)(eax);  // @350_567930
  ecx = (u32)(edi + 468);  // @351_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[25]);  // @352_567930
  edx = 0;  // @353_567930
  eax = (u32)(7);  // @354_567930
  goto L567d8d;  // @355_567930
  L567d8b:;
  eax = 0;  // @357_567930
  FL[3] = eax;  // @358_567930
  L567d8d:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @360_567930
  if (FL[0] != FL[1]) goto L567d9e;  // @361_567930
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @362_567930
  ecx = edi;  // @363_567930
  PV[27] = (u32)(eax);  // @364_567930
  eax = ext_5678e0_thiscall3(ecx, PV[27], PV[26]);  // @365_567930
  ecx = edx = 0;  // @366_567930
  L567d9e:;
  ecx = (u32)(edi + 468);  // @368_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(11));  // @369_567930
  edx = 0;  // @370_567930
  FL[2] = (eax & eax);  // @371_567930
  if (FL[2] != 0) goto L567dd3;  // @372_567930
  ecx = (u32)(edi + 384);  // @373_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(11));  // @374_567930
  edx = 0;  // @375_567930
  FL[2] = (eax & eax);  // @376_567930
  if (FL[2] == 0) goto L567dd3;  // @377_567930
  PV[28] = (u32)(eax);  // @378_567930
  ecx = (u32)(edi + 468);  // @379_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[28]);  // @380_567930
  edx = 0;  // @381_567930
  eax = (u32)(11);  // @382_567930
  goto L567dd5;  // @383_567930
  L567dd3:;
  eax = 0;  // @385_567930
  FL[3] = eax;  // @386_567930
  L567dd5:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @388_567930
  if (FL[0] != FL[1]) goto L567de6;  // @389_567930
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @390_567930
  ecx = edi;  // @391_567930
  PV[30] = (u32)(eax);  // @392_567930
  eax = ext_5678e0_thiscall3(ecx, PV[30], PV[29]);  // @393_567930
  ecx = edx = 0;  // @394_567930
  L567de6:;
  ecx = (u32)(edi + 468);  // @396_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(4));  // @397_567930
  edx = 0;  // @398_567930
  FL[2] = (eax & eax);  // @399_567930
  if (FL[2] != 0) goto L567e1b;  // @400_567930
  ecx = (u32)(edi + 384);  // @401_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(4));  // @402_567930
  edx = 0;  // @403_567930
  FL[2] = (eax & eax);  // @404_567930
  if (FL[2] == 0) goto L567e1b;  // @405_567930
  PV[31] = (u32)(eax);  // @406_567930
  ecx = (u32)(edi + 468);  // @407_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[31]);  // @408_567930
  edx = 0;  // @409_567930
  eax = (u32)(4);  // @410_567930
  goto L567e1d;  // @411_567930
  L567e1b:;
  eax = 0;  // @413_567930
  FL[3] = eax;  // @414_567930
  L567e1d:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @416_567930
  if (FL[0] != FL[1]) goto L567e2e;  // @417_567930
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @418_567930
  ecx = edi;  // @419_567930
  PV[33] = (u32)(eax);  // @420_567930
  eax = ext_5678e0_thiscall3(ecx, PV[33], PV[32]);  // @421_567930
  ecx = edx = 0;  // @422_567930
  L567e2e:;
  ecx = (u32)(edi + 468);  // @424_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(14));  // @425_567930
  edx = 0;  // @426_567930
  FL[2] = (eax & eax);  // @427_567930
  if (FL[2] != 0) goto L567e63;  // @428_567930
  ecx = (u32)(edi + 384);  // @429_567930
  eax = ext_5af130_fastcall3(ecx, edx, (u32)(14));  // @430_567930
  edx = 0;  // @431_567930
  FL[2] = (eax & eax);  // @432_567930
  if (FL[2] == 0) goto L567e63;  // @433_567930
  PV[34] = (u32)(eax);  // @434_567930
  ecx = (u32)(edi + 468);  // @435_567930
  eax = ext_5aedf0_thiscall2(ecx, PV[34]);  // @436_567930
  edx = 0;  // @437_567930
  eax = (u32)(14);  // @438_567930
  goto L567e65;  // @439_567930
  L567e63:;
  eax = 0;  // @441_567930
  FL[3] = eax;  // @442_567930
  L567e65:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 28), sizeof v); (u32)v; });  // @444_567930
  if (FL[0] != FL[1]) goto L567e76;  // @445_567930
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @446_567930
  ecx = edi;  // @447_567930
  PV[36] = (u32)(eax);  // @448_567930
  eax = ext_5678e0_thiscall3(ecx, PV[36], PV[35]);  // @449_567930
  ecx = edx = 0;  // @450_567930
  L567e76:;
  ebx = (ebx + 1);  // @452_567930
  FL[3] = ebx;  // @453_567930
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @454_567930
  if ((s32)FL[0] < (s32)FL[1]) goto L567990;  // @455_567930
  L567e80:;
  ext_633654(G(u32, 0x6f5630));  // @457_567930
  return eax;  // @458_567930
}
PCREG(567930, lifted_567930);

extern "C" u32 THISCALL lifted_56e050(u32 ecx_in) {
  u8 F[0x810] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x710);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_56e050
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1608), &v, sizeof v); }  // @1_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @4_56e050
  ecx = edx = 0;  // @5_56e050
  ecx = (u32)(EBP - 1600);  // @6_56e050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1600), &v, sizeof v); }  // @7_56e050
  PV[0] = (u32)(ecx);  // @8_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_56e050
  ecx = eax;  // @10_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6880492), PV[0]);  // @11_56e050
  ecx = edx = 0;  // @12_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @14_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @16_56e050
  ecx = edx = 0;  // @17_56e050
  ecx = (u32)(EBP - 1600);  // @18_56e050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1600), &v, sizeof v); }  // @19_56e050
  PV[1] = (u32)(ecx);  // @20_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_56e050
  ecx = eax;  // @22_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6979836), PV[1]);  // @23_56e050
  ecx = edx = 0;  // @24_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @26_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @28_56e050
  ecx = edx = 0;  // @29_56e050
  ecx = (u32)(EBP - 1596);  // @30_56e050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1596), &v, sizeof v); }  // @31_56e050
  PV[2] = (u32)(ecx);  // @32_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_56e050
  ecx = eax;  // @34_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6980388), PV[2]);  // @35_56e050
  ecx = edx = 0;  // @36_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @37_56e050
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1596), sizeof v); (u32)v; });  // @38_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[3]);  // @40_56e050
  ecx = edx = 0;  // @41_56e050
  ecx = eax;  // @42_56e050
  { u32 v = (u32)((u32)(6980408)); __builtin_memcpy((void *)(u32)(EBP - 1556), &v, sizeof v); }  // @43_56e050
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1604), &v, sizeof v); }  // @44_56e050
  edi = (u32)(EBP - 1588);  // @45_56e050
  { u32 v = (u32)((u32)(6980416)); __builtin_memcpy((void *)(u32)(EBP - 1552), &v, sizeof v); }  // @46_56e050
  ebx = (u32)(EBP - 1556);  // @47_56e050
  { u32 v = (u32)((u32)(6980424)); __builtin_memcpy((void *)(u32)(EBP - 1548), &v, sizeof v); }  // @48_56e050
  esi = (u32)(1);  // @49_56e050
  { u32 v = (u32)((u32)(6980432)); __builtin_memcpy((void *)(u32)(EBP - 1544), &v, sizeof v); }  // @50_56e050
  L56e160:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @52_56e050
  PV[4] = (u32)(esi);  // @53_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @54_56e050
  eax = ext_5a4590_thiscall2(ecx, PV[4]);  // @55_56e050
  edx = 0;  // @56_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1604), sizeof v); (u32)v; });  // @57_56e050
  ebx = (u32)(ebx + 4);  // @58_56e050
  esi = (esi + 1);  // @59_56e050
  FL[3] = esi;  // @60_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @61_56e050
  edi = (u32)(edi + 8);  // @62_56e050
  FL[0] = esi; FL[1] = (u32)(4);  // @63_56e050
  if (FL[0] <= FL[1]) goto L56e160;  // @64_56e050
  esi = 0;  // @65_56e050
  FL[3] = esi;  // @66_56e050
  { u32 v = (u32)((u32)(6980456)); __builtin_memcpy((void *)(u32)(EBP - 1644), &v, sizeof v); }  // @67_56e050
  edi = 0;  // @68_56e050
  FL[3] = edi;  // @69_56e050
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1616), &v, sizeof v); }  // @70_56e050
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1628), &v, sizeof v); }  // @71_56e050
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1624), &v, sizeof v); }  // @72_56e050
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1620), &v, sizeof v); }  // @73_56e050
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1652), &v, sizeof v); }  // @74_56e050
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1664), &v, sizeof v); }  // @75_56e050
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1660), &v, sizeof v); }  // @76_56e050
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1656), &v, sizeof v); }  // @77_56e050
  eax = ext_5a46f0_thiscall2(ecx, (u32)(3));  // @78_56e050
  edx = 0;  // @79_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1604), sizeof v); (u32)v; });  // @80_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1632), &v, sizeof v); }  // @81_56e050
  { u32 v = (u32)((u32)(6980440)); __builtin_memcpy((void *)(u32)(EBP - 1640), &v, sizeof v); }  // @82_56e050
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(EBP - 1636), &v, sizeof v); }  // @83_56e050
  { u32 v = (u32)((u32)(6967236)); __builtin_memcpy((void *)(u32)(EBP - 1612), &v, sizeof v); }  // @84_56e050
  { u32 v = (u32)((u32)(6980492)); __builtin_memcpy((void *)(u32)(EBP - 1680), &v, sizeof v); }  // @85_56e050
  eax = ext_5a46f0_thiscall2(ecx, (u32)(4));  // @86_56e050
  edx = 0;  // @87_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1668), &v, sizeof v); }  // @88_56e050
  ebx = 0;  // @89_56e050
  FL[3] = ebx;  // @90_56e050
  eax = (u32)(EBP - 1588);  // @91_56e050
  { u32 v = (u32)((u32)(6980472)); __builtin_memcpy((void *)(u32)(EBP - 1676), &v, sizeof v); }  // @92_56e050
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 1672), &v, sizeof v); }  // @93_56e050
  { u32 v = (u32)((u32)(6967260)); __builtin_memcpy((void *)(u32)(EBP - 1648), &v, sizeof v); }  // @94_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1596), &v, sizeof v); }  // @95_56e050
  L56e231:;
  PV[5] = (u32)(ebx);  // @97_56e050
  eax = (u32)(EBP - 1540);  // @98_56e050
  PV[6] = (u32)(eax);  // @99_56e050
  eax = ext_42ac56_cdecl3(PV[6], (u32)(6980512), PV[5]);  // @100_56e050
  ecx = edx = 0;  // @101_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @103_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @105_56e050
  ecx = edx = 0;  // @106_56e050
  ecx = (u32)(EBP - 1589);  // @107_56e050
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1589), &v, sizeof v); }  // @108_56e050
  PV[7] = (u32)(ecx);  // @109_56e050
  ecx = (u32)(EBP - 1540);  // @110_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @111_56e050
  PV[8] = (u32)(ecx);  // @112_56e050
  ecx = eax;  // @113_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, PV[8], PV[7]);  // @114_56e050
  ecx = edx = 0;  // @115_56e050
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1589), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @116_56e050
  if (FL[0] == FL[1]) goto L56e30a;  // @117_56e050
  PV[9] = (u32)(ebx);  // @118_56e050
  eax = (u32)(EBP - 1540);  // @119_56e050
  PV[10] = (u32)(eax);  // @120_56e050
  eax = ext_42ac56_cdecl3(PV[10], (u32)(6980532), PV[9]);  // @121_56e050
  ecx = edx = 0;  // @122_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @123_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @124_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @126_56e050
  ecx = edx = 0;  // @127_56e050
  ecx = (u32)(EBP - 1604);  // @128_56e050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1604), &v, sizeof v); }  // @129_56e050
  PV[11] = (u32)(ecx);  // @130_56e050
  ecx = (u32)(EBP - 1540);  // @131_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @132_56e050
  PV[12] = (u32)(ecx);  // @133_56e050
  ecx = eax;  // @134_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[12], PV[11]);  // @135_56e050
  ecx = edx = 0;  // @136_56e050
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1604), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @137_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1596), sizeof v); (u32)v; });  // @138_56e050
  if (FL[0] != FL[1]) goto L56e2f4;  // @139_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + esi*4 - 1628), &v, sizeof v); }  // @140_56e050
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1616), sizeof v); (u32)v; });  // @141_56e050
  esi = (esi + 1);  // @142_56e050
  FL[3] = esi;  // @143_56e050
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1616), &v, sizeof v); }  // @144_56e050
  goto L56e310;  // @145_56e050
  L56e2f4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + edi*4 - 1664), &v, sizeof v); }  // @147_56e050
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1652), sizeof v); (u32)v; });  // @148_56e050
  edi = (edi + 1);  // @149_56e050
  FL[3] = edi;  // @150_56e050
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1652), &v, sizeof v); }  // @151_56e050
  goto L56e310;  // @152_56e050
  L56e30a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1596), sizeof v); (u32)v; });  // @154_56e050
  L56e310:;
  ebx = (ebx + 1);  // @156_56e050
  FL[3] = ebx;  // @157_56e050
  eax = (eax + (u32)(8));  // @158_56e050
  FL[3] = eax;  // @159_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1596), &v, sizeof v); }  // @160_56e050
  FL[0] = ebx; FL[1] = (u32)(4);  // @161_56e050
  if (FL[0] < FL[1]) goto L56e231;  // @162_56e050
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1600), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @163_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1632), sizeof v); (u32)v; });  // @164_56e050
  if (FL[0] == FL[1]) goto L56e352;  // @165_56e050
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @166_56e050
  ecx = (u32)(EBP - 1644);  // @167_56e050
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @168_56e050
  edi = (u32)(EBP - 1680);  // @169_56e050
  ebx = ecx;  // @170_56e050
  if (FL[2] != 0) edi = ecx;  // @171_56e050
  ecx = (u32)(EBP - 1680);  // @172_56e050
  if (FL[2] != 0) ebx = ecx;  // @173_56e050
  goto L56e392;  // @174_56e050
  L56e352:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1668), sizeof v); (u32)v; });  // @176_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; });  // @177_56e050
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @178_56e050
  FL[0] = edx; FL[1] = esi;  // @179_56e050
  if ((s32)FL[0] < (s32)FL[1]) goto L56e386;  // @180_56e050
  if (FL[0] != FL[1]) goto L56e378;  // @181_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6), sizeof v); (u32)v; });  // @182_56e050
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @183_56e050
  FL[0] = edx; FL[1] = esi;  // @184_56e050
  if ((s32)FL[0] < (s32)FL[1]) goto L56e386;  // @185_56e050
  if (FL[0] != FL[1]) goto L56e378;  // @186_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 10), sizeof v); (u32)v; });  // @187_56e050
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 10), sizeof v); (u32)v; });  // @188_56e050
  if ((s32)FL[0] < (s32)FL[1]) goto L56e386;  // @189_56e050
  L56e378:;
  edi = (u32)(EBP - 1644);  // @191_56e050
  ebx = (u32)(EBP - 1680);  // @192_56e050
  goto L56e392;  // @193_56e050
  L56e386:;
  edi = (u32)(EBP - 1680);  // @195_56e050
  ebx = (u32)(EBP - 1644);  // @196_56e050
  L56e392:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1608), sizeof v); (u32)v; });  // @198_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; });  // @199_56e050
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @200_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @201_56e050
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @202_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @203_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @204_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @205_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, PV[13], (u32)(0), (u32)(6980340), (u32)(298), (u32)(0), (u32)(0));  // @206_56e050
  ecx = edx = 0;  // @207_56e050
  eax = (eax & 0xffff);  // @208_56e050
  PV[14] = (u32)(eax);  // @209_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1608), sizeof v); (u32)v; });  // @210_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; });  // @211_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @212_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[14]);  // @213_56e050
  ecx = edx = 0;  // @214_56e050
  eax = 0;  // @215_56e050
  FL[3] = eax;  // @216_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1596), &v, sizeof v); }  // @217_56e050
  L56e3f0:;
  FL[0] = eax; FL[1] = (u32)(32);  // @219_56e050
  if (FL[0] > FL[1]) goto L56e88e;  // @220_56e050
  switch (eax) {  // @221_56e050
  case 0: goto L56e400;  // @222_56e050
  case 1: goto L56e46c;  // @223_56e050
  case 2: goto L56e4b2;  // @224_56e050
  case 3: goto L56e4d4;  // @225_56e050
  case 4: goto L56e500;  // @226_56e050
  case 5: goto L56e52f;  // @227_56e050
  case 6: goto L56e548;  // @228_56e050
  case 7: goto L56e562;  // @229_56e050
  case 8: goto L56e586;  // @230_56e050
  case 9: goto L56e5aa;  // @231_56e050
  case 10: goto L56e5c3;  // @232_56e050
  case 11: goto L56e5de;  // @233_56e050
  case 12: goto L56e603;  // @234_56e050
  case 13: goto L56e628;  // @235_56e050
  case 14: goto L56e641;  // @236_56e050
  case 15: goto L56e657;  // @237_56e050
  case 16: goto L56e677;  // @238_56e050
  case 17: goto L56e697;  // @239_56e050
  case 18: goto L56e69f;  // @240_56e050
  case 19: goto L56e6c4;  // @241_56e050
  case 20: goto L56e6f3;  // @242_56e050
  case 21: goto L56e722;  // @243_56e050
  case 22: goto L56e73b;  // @244_56e050
  case 23: goto L56e755;  // @245_56e050
  case 24: goto L56e779;  // @246_56e050
  case 25: goto L56e79d;  // @247_56e050
  case 26: goto L56e7b6;  // @248_56e050
  case 27: goto L56e7d1;  // @249_56e050
  case 28: goto L56e7f6;  // @250_56e050
  case 29: goto L56e818;  // @251_56e050
  case 30: goto L56e82e;  // @252_56e050
  case 31: goto L56e841;  // @253_56e050
  case 32: goto L56e85a;  // @254_56e050
  default: __builtin_trap(); }  // @255_56e050
  L56e400:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @257_56e050
  eax = ext_589c20_thiscall2(ecx, (u32)(0));  // @258_56e050
    // @259_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @260_56e050
  esi = eax;  // @261_56e050
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @262_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @263_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @264_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @265_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6980548), PV[15]);  // @266_56e050
  ecx = edx = 0;  // @267_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1600), &v, sizeof v); }  // @268_56e050
  FL[2] = (esi & esi);  // @269_56e050
  if (FL[2] == 0) goto L56e440;  // @270_56e050
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @271_56e050
  ecx = esi;  // @272_56e050
  eax = ext_59a5e0_thiscall2(ecx, PV[16]);  // @273_56e050
  ecx = edx = 0;  // @274_56e050
  L56e440:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @276_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @277_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @278_56e050
  ecx = edx = 0;  // @279_56e050
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1600), sizeof v); (u32)v; });  // @280_56e050
  edx = (u32)(EBP - 1028);  // @281_56e050
  PV[18] = (u32)(edx);  // @282_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @283_56e050
  PV[19] = (u32)(eax);  // @284_56e050
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[19], PV[18], PV[17]);  // @285_56e050
  ecx = edx = 0;  // @286_56e050
  goto L56e88e;  // @287_56e050
  L56e46c:;
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @289_56e050
  L56e46f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @291_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @292_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @293_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @294_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6980548), PV[20]);  // @295_56e050
  ecx = edx = 0;  // @296_56e050
  L56e489:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @298_56e050
  esi = eax;  // @299_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @300_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 400)))(ecx);  // @301_56e050
  ecx = edx = 0;  // @302_56e050
  PV[21] = (u32)(esi);  // @303_56e050
  edx = (u32)(EBP - 1028);  // @304_56e050
  PV[22] = (u32)(edx);  // @305_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @306_56e050
  PV[23] = (u32)(eax);  // @307_56e050
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[23], PV[22], PV[21]);  // @308_56e050
  ecx = edx = 0;  // @309_56e050
  goto L56e88e;  // @310_56e050
  L56e4b2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @312_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @313_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @314_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @315_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @316_56e050
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @317_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6980548), PV[24]);  // @318_56e050
  ecx = edx = 0;  // @319_56e050
  goto L56e489;  // @320_56e050
  L56e4d4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @322_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @323_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @324_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @325_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @326_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @327_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @328_56e050
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @329_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6980548), PV[25]);  // @330_56e050
  ecx = edx = 0;  // @331_56e050
  goto L56e489;  // @332_56e050
  L56e500:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @334_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @335_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @336_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @337_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @338_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @339_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @340_56e050
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @341_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6980548), PV[26]);  // @342_56e050
  ecx = edx = 0;  // @343_56e050
  goto L56e489;  // @344_56e050
  L56e52f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @346_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @347_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @348_56e050
  ecx = edx = 0;  // @349_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @350_56e050
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @351_56e050
  goto L56e876;  // @352_56e050
  L56e548:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @354_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @355_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[27]);  // @356_56e050
  ecx = edx = 0;  // @357_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @358_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @359_56e050
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @360_56e050
  goto L56e876;  // @361_56e050
  L56e562:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @363_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @364_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @365_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @366_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[28]);  // @367_56e050
  ecx = edx = 0;  // @368_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @369_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @370_56e050
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @371_56e050
  goto L56e876;  // @372_56e050
  L56e586:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @374_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @375_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @376_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @377_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[29]);  // @378_56e050
  ecx = edx = 0;  // @379_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @380_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @381_56e050
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @382_56e050
  goto L56e876;  // @383_56e050
  L56e5aa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @385_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @386_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[30]);  // @387_56e050
  ecx = edx = 0;  // @388_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @389_56e050
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @390_56e050
  goto L56e876;  // @391_56e050
  L56e5c3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @393_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @394_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[31]);  // @395_56e050
  ecx = edx = 0;  // @396_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @397_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @398_56e050
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @399_56e050
  goto L56e876;  // @400_56e050
  L56e5de:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @402_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @403_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @404_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @405_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[32]);  // @406_56e050
  ecx = edx = 0;  // @407_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @408_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @409_56e050
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @410_56e050
  goto L56e876;  // @411_56e050
  L56e603:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @413_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @414_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @415_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @416_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[33]);  // @417_56e050
  ecx = edx = 0;  // @418_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @419_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @420_56e050
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @421_56e050
  goto L56e876;  // @422_56e050
  L56e628:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @424_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @425_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[34]);  // @426_56e050
  ecx = edx = 0;  // @427_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @428_56e050
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 10), sizeof v); (u32)v; });  // @429_56e050
  goto L56e876;  // @430_56e050
  L56e641:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @432_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @433_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[35]);  // @434_56e050
  ecx = edx = 0;  // @435_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @436_56e050
  goto L56e871;  // @437_56e050
  L56e657:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @439_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @440_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @441_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @442_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @443_56e050
  ecx = edx = 0;  // @444_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @445_56e050
  goto L56e871;  // @446_56e050
  L56e677:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @448_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @449_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @450_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @451_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @452_56e050
  ecx = edx = 0;  // @453_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @454_56e050
  goto L56e871;  // @455_56e050
  L56e697:;
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @457_56e050
  goto L56e46f;  // @458_56e050
  L56e69f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @460_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @461_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @462_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @463_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @464_56e050
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @465_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6980548), PV[37], PV[36]);  // @466_56e050
  ecx = edx = 0;  // @467_56e050
  goto L56e489;  // @468_56e050
  L56e6c4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @470_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @471_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @472_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @473_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @474_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @475_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @476_56e050
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @477_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6980548), PV[38]);  // @478_56e050
  ecx = edx = 0;  // @479_56e050
  goto L56e489;  // @480_56e050
  L56e6f3:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @482_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @483_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @484_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @485_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @486_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @487_56e050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @488_56e050
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @489_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6980548), PV[39]);  // @490_56e050
  ecx = edx = 0;  // @491_56e050
  goto L56e489;  // @492_56e050
  L56e722:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @494_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @495_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @496_56e050
  ecx = edx = 0;  // @497_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @498_56e050
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @499_56e050
  goto L56e876;  // @500_56e050
  L56e73b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @502_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @503_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[40]);  // @504_56e050
  ecx = edx = 0;  // @505_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @506_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @507_56e050
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @508_56e050
  goto L56e876;  // @509_56e050
  L56e755:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @511_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @512_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @513_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @514_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[41]);  // @515_56e050
  ecx = edx = 0;  // @516_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @517_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @518_56e050
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @519_56e050
  goto L56e876;  // @520_56e050
  L56e779:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @522_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @523_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @524_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @525_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[42]);  // @526_56e050
  ecx = edx = 0;  // @527_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @528_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @529_56e050
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @530_56e050
  goto L56e876;  // @531_56e050
  L56e79d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @533_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @534_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[43]);  // @535_56e050
  ecx = edx = 0;  // @536_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @537_56e050
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @538_56e050
  goto L56e876;  // @539_56e050
  L56e7b6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @541_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @542_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[44]);  // @543_56e050
  ecx = edx = 0;  // @544_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @545_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @546_56e050
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @547_56e050
  goto L56e876;  // @548_56e050
  L56e7d1:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @550_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @551_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @552_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @553_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[45]);  // @554_56e050
  ecx = edx = 0;  // @555_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @556_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @557_56e050
  PV[46] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @558_56e050
  goto L56e876;  // @559_56e050
  L56e7f6:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @561_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @562_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @563_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @564_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[46]);  // @565_56e050
  ecx = edx = 0;  // @566_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @567_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @568_56e050
  PV[47] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @569_56e050
  goto L56e876;  // @570_56e050
  L56e818:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @572_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @573_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[47]);  // @574_56e050
  ecx = edx = 0;  // @575_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @576_56e050
  PV[48] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 10), sizeof v); (u32)v; });  // @577_56e050
  goto L56e876;  // @578_56e050
  L56e82e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @580_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @581_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 400)))(ecx, PV[48]);  // @582_56e050
  ecx = edx = 0;  // @583_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @584_56e050
  goto L56e871;  // @585_56e050
  L56e841:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @587_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @588_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @589_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @590_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @591_56e050
  ecx = edx = 0;  // @592_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @593_56e050
  goto L56e871;  // @594_56e050
  L56e85a:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @596_56e050
  if (FL[0] <= FL[1]) goto L56e88e;  // @597_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @598_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @599_56e050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @600_56e050
  ecx = edx = 0;  // @601_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @602_56e050
  L56e871:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @604_56e050
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @605_56e050
  L56e876:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @607_56e050
  ecx = (u32)(EBP - 1028);  // @608_56e050
  PV[50] = (u32)(ecx);  // @609_56e050
  PV[51] = (u32)(eax);  // @610_56e050
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 408)))(PV[51], PV[50], (u32)(6784244), PV[49]);  // @611_56e050
  ecx = edx = 0;  // @612_56e050
  L56e88e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @614_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @615_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6980340), (u32)(516));  // @616_56e050
  ecx = edx = 0;  // @617_56e050
  edx = (u32)(EBP - 1028);  // @618_56e050
  PV[52] = (u32)(edx);  // @619_56e050
  PV[53] = (u32)(eax);  // @620_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @621_56e050
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, PV[53], PV[52]);  // @622_56e050
  ecx = edx = 0;  // @623_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1608), sizeof v); (u32)v; });  // @624_56e050
  edx = (u32)(EBP - 1028);  // @625_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1596), sizeof v); (u32)v; });  // @626_56e050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 + 384), sizeof v); (u32)v; });  // @627_56e050
  PV[54] = (u32)(edx);  // @628_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @629_56e050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, PV[54]);  // @630_56e050
  ecx = edx = 0;  // @631_56e050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1596), sizeof v); (u32)v; });  // @632_56e050
  eax = (eax + 1);  // @633_56e050
  FL[3] = eax;  // @634_56e050
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1028), &v, sizeof v); }  // @635_56e050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1596), &v, sizeof v); }  // @636_56e050
  FL[0] = eax; FL[1] = (u32)(33);  // @637_56e050
  if ((s32)FL[0] < (s32)FL[1]) goto L56e3f0;  // @638_56e050
  ext_633654(G(u32, 0x6f5630));  // @639_56e050
  return eax;  // @640_56e050
}
PCREG(56e050, lifted_56e050);

