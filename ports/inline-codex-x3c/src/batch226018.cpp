// batch226018.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_42b390_thiscall3(u32, u32, u32) __asm__("ext_42b390");
extern "C" u32 THISCALL ext_5fe980_thiscall4(u32, u32, u32, u32) __asm__("ext_5fe980");
extern "C" u32 THISCALL ext_5ffb00_thiscall2(u32, u32) __asm__("ext_5ffb00");
extern "C" u32 THISCALL ext_6000b0_thiscall2(u32, u32) __asm__("ext_6000b0");
extern "C" u32 THISCALL ext_600ba0_thiscall2(u32, u32) __asm__("ext_600ba0");
extern "C" u32 ext_5fa630_cdecl0(void) __asm__("ext_5fa630");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5fe980(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d761);  // @h_5fe980
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_5fe980
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @1_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 156), sizeof v); (u32)v; });  // @2_5fe980
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_5fe980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_5fe980
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @6_5fe980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @7_5fe980
  if ((ecx & ecx) == 0) goto L5fe9da;  // @8_5fe980
  PS[0] = eax;  // @9_5fe980
  PS[1] = edi;  // @10_5fe980
  PS[2] = ebx;  // @11_5fe980
  eax = ext_5fe980_thiscall4(ecx, (u32)(PS[2]), (u32)(PS[1]), (u32)(PS[0]));  // @12_5fe980
  ecx = edx = 0;  // @13_5fe980
  L5fe9da:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; });  // @15_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_5fe980
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }));  // @17_5fe980
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; }));  // @18_5fe980
  eax = (u32)(ecx + edx);  // @19_5fe980
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 162), sizeof v); (u32)v; })) goto L5fea02;  // @20_5fe980
  PS[0] = edx;  // @21_5fe980
  PS[2] = ecx;  // @22_5fe980
  eax = ext_634d22_cdecl3((u32)(PS[2]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }), (u32)(PS[0]));  // @23_5fe980
  ecx = edx = 0;  // @24_5fe980
  goto L5fea10;  // @25_5fe980
  L5fea02:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @27_5fe980
  if ((eax & eax) == 0) goto L5fea0f;  // @28_5fe980
  eax = ((u32(STDCALL *)(void))(eax))();  // @29_5fe980
  ecx = edx = 0;  // @30_5fe980
  goto L5fea10;  // @31_5fe980
  L5fea0f:;
  __builtin_trap();  // @33_5fe980
  L5fea10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; });  // @35_5fe980
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }));  // @36_5fe980
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @37_5fe980
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; }) == (u32)(0)) goto L5fecfb;  // @38_5fe980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @39_5fe980
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; }));  // @40_5fe980
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @41_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_5fe980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @43_5fe980
  if ((eax & eax) == 0) goto L5feb21;  // @44_5fe980
  ebx = 0;  // @45_5fe980
  L5fea46:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edi + 4), sizeof v); (u32)v; });  // @47_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @48_5fe980
  if (ecx > edx) goto L5fea5d;  // @49_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; });  // @50_5fe980
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }));  // @51_5fe980
  eax = (eax + ecx);  // @52_5fe980
  if (eax > edx) goto L5fea71;  // @53_5fe980
  L5fea5d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 156), sizeof v); (u32)v; });  // @55_5fe980
  if ((ecx & ecx) == 0) goto L5feade;  // @56_5fe980
  PS[0] = edx;  // @57_5fe980
  eax = ext_600ba0_thiscall2(ecx, (u32)(PS[0]));  // @58_5fe980
  ecx = edx = 0;  // @59_5fe980
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5feade;  // @60_5fe980
  L5fea71:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edi + 8), sizeof v); (u32)v; });  // @62_5fe980
  ecx = esi;  // @63_5fe980
  PS[0] = eax;  // @64_5fe980
  eax = ext_5ffb00_thiscall2(ecx, (u32)(PS[0]));  // @65_5fe980
  ecx = edx = 0;  // @66_5fe980
  edi = eax;  // @67_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @68_5fe980
  PS[0] = edi;  // @69_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 150), sizeof v); (u32)v; });  // @70_5fe980
  eax = ext_6000b0_thiscall2(ecx, (u32)(PS[0]));  // @71_5fe980
  ecx = edx = 0;  // @72_5fe980
  if ((eax & eax) != 0) goto L5feabd;  // @73_5fe980
  eax = ext_5fa630_cdecl0();  // @74_5fe980
  ecx = edx = 0;  // @75_5fe980
  PS[0] = edi;  // @76_5fe980
  edx = (u32)(EBP - 116);  // @77_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @78_5fe980
  PS[2] = edx;  // @79_5fe980
  PS[3] = eax;  // @80_5fe980
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 20)))((u32)(PS[3]), (u32)(PS[2]), (u32)(7050472), (u32)(PS[0]));  // @81_5fe980
  ecx = edx = 0;  // @82_5fe980
  eax = ext_5fa630_cdecl0();  // @83_5fe980
  ecx = edx = 0;  // @84_5fe980
  edx = (u32)(EBP - 116);  // @85_5fe980
  PS[0] = edx;  // @86_5fe980
  PS[1] = eax;  // @87_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_5fe980
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 12)))((u32)(PS[1]), (u32)(PS[0]));  // @89_5fe980
  ecx = edx = 0;  // @90_5fe980
  L5feabd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @92_5fe980
  PS[0] = edi;  // @93_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_5fe980
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(PS[0]));  // @95_5fe980
  ecx = edx = 0;  // @96_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @97_5fe980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @98_5fe980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 158), sizeof v); (u32)v; });  // @99_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edi + 4), sizeof v); (u32)v; });  // @100_5fe980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @101_5fe980
  goto L5feb14;  // @102_5fe980
  L5feade:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @104_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_5fe980
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7050400), (u32)(585));  // @106_5fe980
  ecx = edx = 0;  // @107_5fe980
  PS[2] = eax;  // @108_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @109_5fe980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(PS[2]), (u32)(6932144), (u32)(6781786));  // @110_5fe980
  ecx = edx = 0;  // @111_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @112_5fe980
  if ((eax & eax) == 0) goto L5feb13;  // @113_5fe980
  eax = ((u32(STDCALL *)(void))(eax))();  // @114_5fe980
  ecx = edx = 0;  // @115_5fe980
  goto L5feb14;  // @116_5fe980
  L5feb13:;
  __builtin_trap();  // @118_5fe980
  L5feb14:;
  ebx = (ebx + (u32)(6));  // @120_5fe980
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @121_5fe980
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; }) != 0) goto L5fea46;  // @122_5fe980
  L5feb21:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; });  // @124_5fe980
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; }));  // @125_5fe980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @126_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_5fe980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @128_5fe980
  if ((eax & eax) == 0) goto L5fecfb;  // @129_5fe980
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @130_5fe980
  eax = 0;  // @131_5fe980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @132_5fe980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @133_5fe980
  L5feb51:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 4), sizeof v); (u32)v; });  // @135_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @136_5fe980
  if (ecx > edx) goto L5feb68;  // @137_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; });  // @138_5fe980
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }));  // @139_5fe980
  eax = (eax + ecx);  // @140_5fe980
  if (eax > edx) goto L5feb84;  // @141_5fe980
  L5feb68:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 156), sizeof v); (u32)v; });  // @143_5fe980
  if ((ecx & ecx) == 0) goto L5fecac;  // @144_5fe980
  PS[0] = edx;  // @145_5fe980
  eax = ext_600ba0_thiscall2(ecx, (u32)(PS[0]));  // @146_5fe980
  ecx = edx = 0;  // @147_5fe980
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5fecac;  // @148_5fe980
  L5feb84:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @150_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @151_5fe980
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 8), sizeof v); (u32)v; });  // @152_5fe980
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; }) == (u32)(0)) goto L5fec03;  // @153_5fe980
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 160), sizeof v); (u32)v; }) > ecx) goto L5fec03;  // @154_5fe980
  ecx = (ecx & 0xffff0000u) | ((((ecx & 0xffff) - ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 160), sizeof v); (u32)v; }))) & 0xffff);  // @155_5fe980
  ecx = (ecx & 0xffff);  // @156_5fe980
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; })) goto L5febc5;  // @157_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 172), sizeof v); (u32)v; });  // @158_5fe980
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @159_5fe980
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 176), sizeof v); (u32)v; }));  // @160_5fe980
  ebx = edi;  // @161_5fe980
  goto L5fec27;  // @162_5fe980
  L5febc5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @164_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_5fe980
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7050272), (u32)(311));  // @166_5fe980
  ecx = edx = 0;  // @167_5fe980
  PS[2] = eax;  // @168_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @169_5fe980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(PS[2]), (u32)(6932144), (u32)(7050356));  // @170_5fe980
  ecx = edx = 0;  // @171_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @172_5fe980
  if ((eax & eax) == 0) goto L5febfc;  // @173_5fe980
  eax = ((u32(STDCALL *)(void))(eax))();  // @174_5fe980
  ecx = edx = 0;  // @175_5fe980
  ebx = edi;  // @176_5fe980
  goto L5fec27;  // @177_5fe980
  L5febfc:;
  __builtin_trap();  // @179_5fe980
  L5fec03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 156), sizeof v); (u32)v; });  // @181_5fe980
  if ((eax & eax) == 0) goto L5fec17;  // @182_5fe980
  PS[0] = ecx;  // @183_5fe980
  ecx = eax;  // @184_5fe980
  eax = ext_5ffb00_thiscall2(ecx, (u32)(PS[0]));  // @185_5fe980
  ecx = edx = 0;  // @186_5fe980
  goto L5fec25;  // @187_5fe980
  L5fec17:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @189_5fe980
  if ((eax & eax) == 0) goto L5fec24;  // @190_5fe980
  eax = ((u32(STDCALL *)(void))(eax))();  // @191_5fe980
  ecx = edx = 0;  // @192_5fe980
  goto L5fec27;  // @193_5fe980
  L5fec24:;
  __builtin_trap();  // @195_5fe980
  L5fec25:;
  ebx = eax;  // @197_5fe980
  L5fec27:;
  eax = (u32)(EBP - 133);  // @199_5fe980
  PS[0] = eax;  // @200_5fe980
  PS[1] = ebx;  // @201_5fe980
  ecx = (u32)(EBP - 156);  // @202_5fe980
  eax = ext_42b390_thiscall3(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @203_5fe980
  ecx = edx = 0;  // @204_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @205_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @206_5fe980
  eax = (eax + (u32)(2762));  // @207_5fe980
  reg.state = (s32)((u32)(0));  // @208_5fe980
  PS[0] = eax;  // @209_5fe980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @210_5fe980
  eax = (u32)(EBP - 156);  // @211_5fe980
  PS[1] = eax;  // @212_5fe980
  PS[2] = ebx;  // @213_5fe980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[2]), (u32)(PS[1]), (u32)(PS[0]));  // @214_5fe980
  ecx = edx = 0;  // @215_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @216_5fe980
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @217_5fe980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 158), sizeof v); (u32)v; });  // @218_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @219_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi + 4), sizeof v); (u32)v; });  // @220_5fe980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @221_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @222_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @223_5fe980
  eax = (eax - ecx);  // @224_5fe980
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @225_5fe980
  reg.state = (s32)((u32)(1));  // @226_5fe980
  if ((ecx & ecx) == 0) goto L5feca3;  // @227_5fe980
  if ((eax & eax) == 0) goto L5feca3;  // @228_5fe980
  PS[0] = eax;  // @229_5fe980
  PS[1] = ecx;  // @230_5fe980
  ecx = (u32)(EBP - 156);  // @231_5fe980
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @232_5fe980
  ecx = edx = 0;  // @233_5fe980
  L5feca3:;
  reg.state = (s32)((u32)(4294967295));  // @235_5fe980
  goto L5fece2;  // @236_5fe980
  L5fecac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @238_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @239_5fe980
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7050400), (u32)(627));  // @240_5fe980
  ecx = edx = 0;  // @241_5fe980
  PS[2] = eax;  // @242_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @243_5fe980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(PS[2]), (u32)(6932144), (u32)(6781786));  // @244_5fe980
  ecx = edx = 0;  // @245_5fe980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @246_5fe980
  if ((eax & eax) == 0) goto L5fece1;  // @247_5fe980
  eax = ((u32(STDCALL *)(void))(eax))();  // @248_5fe980
  ecx = edx = 0;  // @249_5fe980
  goto L5fece2;  // @250_5fe980
  L5fece1:;
  __builtin_trap();  // @252_5fe980
  L5fece2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @254_5fe980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @255_5fe980
  eax = (eax + (u32)(6));  // @256_5fe980
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @257_5fe980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @258_5fe980
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; }) != 0) goto L5feb51;  // @259_5fe980
  L5fecfb:;
  SEH_LEAVE();  // @261_5fe980
  ext_633654(G(u32, 0x6f5630));  // @262_5fe980
  return eax;  // @263_5fe980
}
PCREG(5fe980, lifted_5fe980);

