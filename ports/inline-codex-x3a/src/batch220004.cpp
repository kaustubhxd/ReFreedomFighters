// batch220004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_503770_thiscall2(u32, u32) __asm__("ext_503770");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_519ea0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @0_519ea0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_519ea0
  esi = ecx;  // @2_519ea0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @3_519ea0
  if (eax >= (u32)(50)) goto L519ed1;  // @4_519ea0
  { u32 v = (u32)((u32)(5348336)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @5_519ea0
  eax = (eax + 1);  // @6_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @7_519ea0
  goto L519eee;  // @8_519ea0
  L519ed1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @11_519ea0
  ecx = edx = 0;  // @12_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @13_519ea0
  if ((eax & eax) == 0) goto L519ee8;  // @14_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @15_519ea0
  ecx = edx = 0;  // @16_519ea0
  goto L519ee9;  // @17_519ea0
  L519ee8:;
  __builtin_trap();  // @19_519ea0
  L519ee9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @21_519ea0
  L519eee:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @23_519ea0
  if (eax >= (u32)(50)) goto L519f10;  // @24_519ea0
  { u32 v = (u32)((u32)(5347168)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @25_519ea0
  eax = (eax + 1);  // @26_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @27_519ea0
  goto L519f2f;  // @28_519ea0
  L519f10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_519ea0
  ecx = esi;  // @31_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @32_519ea0
  ecx = edx = 0;  // @33_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @34_519ea0
  if ((eax & eax) == 0) goto L519f29;  // @35_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @36_519ea0
  ecx = edx = 0;  // @37_519ea0
  goto L519f2a;  // @38_519ea0
  L519f29:;
  __builtin_trap();  // @40_519ea0
  L519f2a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @42_519ea0
  L519f2f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @44_519ea0
  if (eax >= (u32)(50)) goto L519f51;  // @45_519ea0
  { u32 v = (u32)((u32)(5346496)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @46_519ea0
  eax = (eax + 1);  // @47_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @48_519ea0
  goto L519f70;  // @49_519ea0
  L519f51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_519ea0
  ecx = esi;  // @52_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @53_519ea0
  ecx = edx = 0;  // @54_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @55_519ea0
  if ((eax & eax) == 0) goto L519f6a;  // @56_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @57_519ea0
  ecx = edx = 0;  // @58_519ea0
  goto L519f6b;  // @59_519ea0
  L519f6a:;
  __builtin_trap();  // @61_519ea0
  L519f6b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @63_519ea0
  L519f70:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @65_519ea0
  if (eax >= (u32)(50)) goto L519f92;  // @66_519ea0
  { u32 v = (u32)((u32)(5347296)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @67_519ea0
  eax = (eax + 1);  // @68_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @69_519ea0
  goto L519fb1;  // @70_519ea0
  L519f92:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_519ea0
  ecx = esi;  // @73_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @74_519ea0
  ecx = edx = 0;  // @75_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @76_519ea0
  if ((eax & eax) == 0) goto L519fab;  // @77_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @78_519ea0
  ecx = edx = 0;  // @79_519ea0
  goto L519fac;  // @80_519ea0
  L519fab:;
  __builtin_trap();  // @82_519ea0
  L519fac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @84_519ea0
  L519fb1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @86_519ea0
  if (eax >= (u32)(50)) goto L519fd3;  // @87_519ea0
  { u32 v = (u32)((u32)(5346976)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @88_519ea0
  eax = (eax + 1);  // @89_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @90_519ea0
  goto L519ff2;  // @91_519ea0
  L519fd3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_519ea0
  ecx = esi;  // @94_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @95_519ea0
  ecx = edx = 0;  // @96_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @97_519ea0
  if ((eax & eax) == 0) goto L519fec;  // @98_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @99_519ea0
  ecx = edx = 0;  // @100_519ea0
  goto L519fed;  // @101_519ea0
  L519fec:;
  __builtin_trap();  // @103_519ea0
  L519fed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @105_519ea0
  L519ff2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @107_519ea0
  if (eax >= (u32)(50)) goto L51a014;  // @108_519ea0
  { u32 v = (u32)((u32)(5346928)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @109_519ea0
  eax = (eax + 1);  // @110_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @111_519ea0
  goto L51a033;  // @112_519ea0
  L51a014:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_519ea0
  ecx = esi;  // @115_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @116_519ea0
  ecx = edx = 0;  // @117_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @118_519ea0
  if ((eax & eax) == 0) goto L51a02d;  // @119_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @120_519ea0
  ecx = edx = 0;  // @121_519ea0
  goto L51a02e;  // @122_519ea0
  L51a02d:;
  __builtin_trap();  // @124_519ea0
  L51a02e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @126_519ea0
  L51a033:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @128_519ea0
  if (eax >= (u32)(50)) goto L51a055;  // @129_519ea0
  { u32 v = (u32)((u32)(5347504)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @130_519ea0
  eax = (eax + 1);  // @131_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @132_519ea0
  goto L51a074;  // @133_519ea0
  L51a055:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @135_519ea0
  ecx = esi;  // @136_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @137_519ea0
  ecx = edx = 0;  // @138_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @139_519ea0
  if ((eax & eax) == 0) goto L51a06e;  // @140_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @141_519ea0
  ecx = edx = 0;  // @142_519ea0
  goto L51a06f;  // @143_519ea0
  L51a06e:;
  __builtin_trap();  // @145_519ea0
  L51a06f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @147_519ea0
  L51a074:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @149_519ea0
  if (eax >= (u32)(50)) goto L51a096;  // @150_519ea0
  { u32 v = (u32)((u32)(5348864)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @151_519ea0
  eax = (eax + 1);  // @152_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @153_519ea0
  goto L51a0b5;  // @154_519ea0
  L51a096:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_519ea0
  ecx = esi;  // @157_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @158_519ea0
  ecx = edx = 0;  // @159_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @160_519ea0
  if ((eax & eax) == 0) goto L51a0af;  // @161_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @162_519ea0
  ecx = edx = 0;  // @163_519ea0
  goto L51a0b0;  // @164_519ea0
  L51a0af:;
  __builtin_trap();  // @166_519ea0
  L51a0b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @168_519ea0
  L51a0b5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @170_519ea0
  if (eax >= (u32)(50)) goto L51a0d7;  // @171_519ea0
  { u32 v = (u32)((u32)(5347424)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @172_519ea0
  eax = (eax + 1);  // @173_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @174_519ea0
  goto L51a0f6;  // @175_519ea0
  L51a0d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_519ea0
  ecx = esi;  // @178_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @179_519ea0
  ecx = edx = 0;  // @180_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @181_519ea0
  if ((eax & eax) == 0) goto L51a0f0;  // @182_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @183_519ea0
  ecx = edx = 0;  // @184_519ea0
  goto L51a0f1;  // @185_519ea0
  L51a0f0:;
  __builtin_trap();  // @187_519ea0
  L51a0f1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @189_519ea0
  L51a0f6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @191_519ea0
  if (eax >= (u32)(50)) goto L51a118;  // @192_519ea0
  { u32 v = (u32)((u32)(5348592)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @193_519ea0
  eax = (eax + 1);  // @194_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @195_519ea0
  goto L51a137;  // @196_519ea0
  L51a118:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_519ea0
  ecx = esi;  // @199_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @200_519ea0
  ecx = edx = 0;  // @201_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @202_519ea0
  if ((eax & eax) == 0) goto L51a131;  // @203_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @204_519ea0
  ecx = edx = 0;  // @205_519ea0
  goto L51a132;  // @206_519ea0
  L51a131:;
  __builtin_trap();  // @208_519ea0
  L51a132:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @210_519ea0
  L51a137:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @212_519ea0
  if (eax >= (u32)(50)) goto L51a159;  // @213_519ea0
  { u32 v = (u32)((u32)(5348528)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @214_519ea0
  eax = (eax + 1);  // @215_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @216_519ea0
  goto L51a178;  // @217_519ea0
  L51a159:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @219_519ea0
  ecx = esi;  // @220_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @221_519ea0
  ecx = edx = 0;  // @222_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @223_519ea0
  if ((eax & eax) == 0) goto L51a172;  // @224_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @225_519ea0
  ecx = edx = 0;  // @226_519ea0
  goto L51a173;  // @227_519ea0
  L51a172:;
  __builtin_trap();  // @229_519ea0
  L51a173:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @231_519ea0
  L51a178:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @233_519ea0
  if (eax >= (u32)(50)) goto L51a19a;  // @234_519ea0
  { u32 v = (u32)((u32)(5347120)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @235_519ea0
  eax = (eax + 1);  // @236_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @237_519ea0
  goto L51a1b9;  // @238_519ea0
  L51a19a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @240_519ea0
  ecx = esi;  // @241_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @242_519ea0
  ecx = edx = 0;  // @243_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @244_519ea0
  if ((eax & eax) == 0) goto L51a1b3;  // @245_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @246_519ea0
  ecx = edx = 0;  // @247_519ea0
  goto L51a1b4;  // @248_519ea0
  L51a1b3:;
  __builtin_trap();  // @250_519ea0
  L51a1b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @252_519ea0
  L51a1b9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @254_519ea0
  if (eax >= (u32)(50)) goto L51a1db;  // @255_519ea0
  { u32 v = (u32)((u32)(5347664)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @256_519ea0
  eax = (eax + 1);  // @257_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @258_519ea0
  goto L51a1fa;  // @259_519ea0
  L51a1db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @261_519ea0
  ecx = esi;  // @262_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @263_519ea0
  ecx = edx = 0;  // @264_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @265_519ea0
  if ((eax & eax) == 0) goto L51a1f4;  // @266_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @267_519ea0
  ecx = edx = 0;  // @268_519ea0
  goto L51a1f5;  // @269_519ea0
  L51a1f4:;
  __builtin_trap();  // @271_519ea0
  L51a1f5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @273_519ea0
  L51a1fa:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @275_519ea0
  if (eax >= (u32)(50)) goto L51a21c;  // @276_519ea0
  { u32 v = (u32)((u32)(5346480)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @277_519ea0
  eax = (eax + 1);  // @278_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @279_519ea0
  goto L51a23b;  // @280_519ea0
  L51a21c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @282_519ea0
  ecx = esi;  // @283_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @284_519ea0
  ecx = edx = 0;  // @285_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @286_519ea0
  if ((eax & eax) == 0) goto L51a235;  // @287_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @288_519ea0
  ecx = edx = 0;  // @289_519ea0
  goto L51a236;  // @290_519ea0
  L51a235:;
  __builtin_trap();  // @292_519ea0
  L51a236:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @294_519ea0
  L51a23b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @296_519ea0
  if (eax >= (u32)(50)) goto L51a25d;  // @297_519ea0
  { u32 v = (u32)((u32)(5348160)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @298_519ea0
  eax = (eax + 1);  // @299_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @300_519ea0
  goto L51a27c;  // @301_519ea0
  L51a25d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @303_519ea0
  ecx = esi;  // @304_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @305_519ea0
  ecx = edx = 0;  // @306_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @307_519ea0
  if ((eax & eax) == 0) goto L51a276;  // @308_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @309_519ea0
  ecx = edx = 0;  // @310_519ea0
  goto L51a277;  // @311_519ea0
  L51a276:;
  __builtin_trap();  // @313_519ea0
  L51a277:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @315_519ea0
  L51a27c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @317_519ea0
  if (eax >= (u32)(50)) goto L51a29e;  // @318_519ea0
  { u32 v = (u32)((u32)(5346832)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @319_519ea0
  eax = (eax + 1);  // @320_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @321_519ea0
  goto L51a2bd;  // @322_519ea0
  L51a29e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @324_519ea0
  ecx = esi;  // @325_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @326_519ea0
  ecx = edx = 0;  // @327_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @328_519ea0
  if ((eax & eax) == 0) goto L51a2b7;  // @329_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @330_519ea0
  ecx = edx = 0;  // @331_519ea0
  goto L51a2b8;  // @332_519ea0
  L51a2b7:;
  __builtin_trap();  // @334_519ea0
  L51a2b8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @336_519ea0
  L51a2bd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @338_519ea0
  if (eax >= (u32)(50)) goto L51a2df;  // @339_519ea0
  { u32 v = (u32)((u32)(5346784)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @340_519ea0
  eax = (eax + 1);  // @341_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @342_519ea0
  goto L51a2fe;  // @343_519ea0
  L51a2df:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @345_519ea0
  ecx = esi;  // @346_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @347_519ea0
  ecx = edx = 0;  // @348_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @349_519ea0
  if ((eax & eax) == 0) goto L51a2f8;  // @350_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @351_519ea0
  ecx = edx = 0;  // @352_519ea0
  goto L51a2f9;  // @353_519ea0
  L51a2f8:;
  __builtin_trap();  // @355_519ea0
  L51a2f9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @357_519ea0
  L51a2fe:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @359_519ea0
  if (eax >= (u32)(50)) goto L51a320;  // @360_519ea0
  { u32 v = (u32)((u32)(5346736)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @361_519ea0
  eax = (eax + 1);  // @362_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @363_519ea0
  goto L51a33f;  // @364_519ea0
  L51a320:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @366_519ea0
  ecx = esi;  // @367_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @368_519ea0
  ecx = edx = 0;  // @369_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @370_519ea0
  if ((eax & eax) == 0) goto L51a339;  // @371_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @372_519ea0
  ecx = edx = 0;  // @373_519ea0
  goto L51a33a;  // @374_519ea0
  L51a339:;
  __builtin_trap();  // @376_519ea0
  L51a33a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @378_519ea0
  L51a33f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @380_519ea0
  if (eax >= (u32)(50)) goto L51a361;  // @381_519ea0
  { u32 v = (u32)((u32)(5348464)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @382_519ea0
  eax = (eax + 1);  // @383_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @384_519ea0
  goto L51a380;  // @385_519ea0
  L51a361:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @387_519ea0
  ecx = esi;  // @388_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @389_519ea0
  ecx = edx = 0;  // @390_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @391_519ea0
  if ((eax & eax) == 0) goto L51a37a;  // @392_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @393_519ea0
  ecx = edx = 0;  // @394_519ea0
  goto L51a37b;  // @395_519ea0
  L51a37a:;
  __builtin_trap();  // @397_519ea0
  L51a37b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @399_519ea0
  L51a380:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @401_519ea0
  if (eax >= (u32)(50)) goto L51a3a2;  // @402_519ea0
  { u32 v = (u32)((u32)(5348656)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @403_519ea0
  eax = (eax + 1);  // @404_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @405_519ea0
  goto L51a3c1;  // @406_519ea0
  L51a3a2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @408_519ea0
  ecx = esi;  // @409_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @410_519ea0
  ecx = edx = 0;  // @411_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @412_519ea0
  if ((eax & eax) == 0) goto L51a3bb;  // @413_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @414_519ea0
  ecx = edx = 0;  // @415_519ea0
  goto L51a3bc;  // @416_519ea0
  L51a3bb:;
  __builtin_trap();  // @418_519ea0
  L51a3bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @420_519ea0
  L51a3c1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @422_519ea0
  if (eax >= (u32)(50)) goto L51a3e3;  // @423_519ea0
  { u32 v = (u32)((u32)(5348768)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @424_519ea0
  eax = (eax + 1);  // @425_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @426_519ea0
  goto L51a402;  // @427_519ea0
  L51a3e3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @429_519ea0
  ecx = esi;  // @430_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @431_519ea0
  ecx = edx = 0;  // @432_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @433_519ea0
  if ((eax & eax) == 0) goto L51a3fc;  // @434_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @435_519ea0
  ecx = edx = 0;  // @436_519ea0
  goto L51a3fd;  // @437_519ea0
  L51a3fc:;
  __builtin_trap();  // @439_519ea0
  L51a3fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @441_519ea0
  L51a402:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @443_519ea0
  if (eax >= (u32)(50)) goto L51a424;  // @444_519ea0
  { u32 v = (u32)((u32)(5348816)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @445_519ea0
  eax = (eax + 1);  // @446_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @447_519ea0
  goto L51a443;  // @448_519ea0
  L51a424:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @450_519ea0
  ecx = esi;  // @451_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @452_519ea0
  ecx = edx = 0;  // @453_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @454_519ea0
  if ((eax & eax) == 0) goto L51a43d;  // @455_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @456_519ea0
  ecx = edx = 0;  // @457_519ea0
  goto L51a43e;  // @458_519ea0
  L51a43d:;
  __builtin_trap();  // @460_519ea0
  L51a43e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @462_519ea0
  L51a443:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @464_519ea0
  if (eax >= (u32)(50)) goto L51a465;  // @465_519ea0
  { u32 v = (u32)((u32)(5348976)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @466_519ea0
  eax = (eax + 1);  // @467_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @468_519ea0
  goto L51a484;  // @469_519ea0
  L51a465:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @471_519ea0
  ecx = esi;  // @472_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @473_519ea0
  ecx = edx = 0;  // @474_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @475_519ea0
  if ((eax & eax) == 0) goto L51a47e;  // @476_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @477_519ea0
  ecx = edx = 0;  // @478_519ea0
  goto L51a47f;  // @479_519ea0
  L51a47e:;
  __builtin_trap();  // @481_519ea0
  L51a47f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @483_519ea0
  L51a484:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @485_519ea0
  if (eax >= (u32)(50)) goto L51a4a6;  // @486_519ea0
  { u32 v = (u32)((u32)(5348992)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @487_519ea0
  eax = (eax + 1);  // @488_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @489_519ea0
  goto L51a4c5;  // @490_519ea0
  L51a4a6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @492_519ea0
  ecx = esi;  // @493_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @494_519ea0
  ecx = edx = 0;  // @495_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @496_519ea0
  if ((eax & eax) == 0) goto L51a4bf;  // @497_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @498_519ea0
  ecx = edx = 0;  // @499_519ea0
  goto L51a4c0;  // @500_519ea0
  L51a4bf:;
  __builtin_trap();  // @502_519ea0
  L51a4c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @504_519ea0
  L51a4c5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @506_519ea0
  if (eax >= (u32)(50)) goto L51a4e7;  // @507_519ea0
  { u32 v = (u32)((u32)(5347808)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @508_519ea0
  eax = (eax + 1);  // @509_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @510_519ea0
  goto L51a506;  // @511_519ea0
  L51a4e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @513_519ea0
  ecx = esi;  // @514_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @515_519ea0
  ecx = edx = 0;  // @516_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @517_519ea0
  if ((eax & eax) == 0) goto L51a500;  // @518_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @519_519ea0
  ecx = edx = 0;  // @520_519ea0
  goto L51a501;  // @521_519ea0
  L51a500:;
  __builtin_trap();  // @523_519ea0
  L51a501:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @525_519ea0
  L51a506:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @527_519ea0
  if (eax >= (u32)(50)) goto L51a528;  // @528_519ea0
  { u32 v = (u32)((u32)(5348016)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @529_519ea0
  eax = (eax + 1);  // @530_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @531_519ea0
  goto L51a547;  // @532_519ea0
  L51a528:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @534_519ea0
  ecx = esi;  // @535_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @536_519ea0
  ecx = edx = 0;  // @537_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @538_519ea0
  if ((eax & eax) == 0) goto L51a541;  // @539_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @540_519ea0
  ecx = edx = 0;  // @541_519ea0
  goto L51a542;  // @542_519ea0
  L51a541:;
  __builtin_trap();  // @544_519ea0
  L51a542:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @546_519ea0
  L51a547:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @548_519ea0
  if (eax >= (u32)(50)) goto L51a569;  // @549_519ea0
  { u32 v = (u32)((u32)(5348272)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @550_519ea0
  eax = (eax + 1);  // @551_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @552_519ea0
  goto L51a588;  // @553_519ea0
  L51a569:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @555_519ea0
  ecx = esi;  // @556_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @557_519ea0
  ecx = edx = 0;  // @558_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @559_519ea0
  if ((eax & eax) == 0) goto L51a582;  // @560_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @561_519ea0
  ecx = edx = 0;  // @562_519ea0
  goto L51a583;  // @563_519ea0
  L51a582:;
  __builtin_trap();  // @565_519ea0
  L51a583:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @567_519ea0
  L51a588:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @569_519ea0
  if (eax >= (u32)(50)) goto L51a5aa;  // @570_519ea0
  { u32 v = (u32)((u32)(5348208)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @571_519ea0
  eax = (eax + 1);  // @572_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @573_519ea0
  goto L51a5c9;  // @574_519ea0
  L51a5aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @576_519ea0
  ecx = esi;  // @577_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @578_519ea0
  ecx = edx = 0;  // @579_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @580_519ea0
  if ((eax & eax) == 0) goto L51a5c3;  // @581_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @582_519ea0
  ecx = edx = 0;  // @583_519ea0
  goto L51a5c4;  // @584_519ea0
  L51a5c3:;
  __builtin_trap();  // @586_519ea0
  L51a5c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @588_519ea0
  L51a5c9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @590_519ea0
  if (eax >= (u32)(50)) goto L51a5eb;  // @591_519ea0
  { u32 v = (u32)((u32)(5346880)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @592_519ea0
  eax = (eax + 1);  // @593_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @594_519ea0
  goto L51a60a;  // @595_519ea0
  L51a5eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @597_519ea0
  ecx = esi;  // @598_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @599_519ea0
  ecx = edx = 0;  // @600_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @601_519ea0
  if ((eax & eax) == 0) goto L51a604;  // @602_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @603_519ea0
  ecx = edx = 0;  // @604_519ea0
  goto L51a605;  // @605_519ea0
  L51a604:;
  __builtin_trap();  // @607_519ea0
  L51a605:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @609_519ea0
  L51a60a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @611_519ea0
  if (eax >= (u32)(50)) goto L51a62c;  // @612_519ea0
  { u32 v = (u32)((u32)(5346416)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @613_519ea0
  eax = (eax + 1);  // @614_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @615_519ea0
  goto L51a64b;  // @616_519ea0
  L51a62c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @618_519ea0
  ecx = esi;  // @619_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @620_519ea0
  ecx = edx = 0;  // @621_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @622_519ea0
  if ((eax & eax) == 0) goto L51a645;  // @623_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @624_519ea0
  ecx = edx = 0;  // @625_519ea0
  goto L51a646;  // @626_519ea0
  L51a645:;
  __builtin_trap();  // @628_519ea0
  L51a646:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @630_519ea0
  L51a64b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @632_519ea0
  if (eax >= (u32)(50)) goto L51a66d;  // @633_519ea0
  { u32 v = (u32)((u32)(5347216)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @634_519ea0
  eax = (eax + 1);  // @635_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @636_519ea0
  goto L51a68c;  // @637_519ea0
  L51a66d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @639_519ea0
  ecx = esi;  // @640_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @641_519ea0
  ecx = edx = 0;  // @642_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @643_519ea0
  if ((eax & eax) == 0) goto L51a686;  // @644_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @645_519ea0
  ecx = edx = 0;  // @646_519ea0
  goto L51a687;  // @647_519ea0
  L51a686:;
  __builtin_trap();  // @649_519ea0
  L51a687:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @651_519ea0
  L51a68c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @653_519ea0
  if (eax >= (u32)(50)) goto L51a6ba;  // @654_519ea0
  { u32 v = (u32)((u32)(5348720)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @655_519ea0
  ecx = esi;  // @656_519ea0
  eax = (eax + 1);  // @657_519ea0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @658_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @659_519ea0
  eax = ext_503770_thiscall2(ecx, (u32)(edi));  // @660_519ea0
  ecx = edx = 0;  // @661_519ea0
  return eax;  // @662_519ea0
  L51a6ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @664_519ea0
  ecx = esi;  // @665_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @666_519ea0
  ecx = edx = 0;  // @667_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @668_519ea0
  if ((eax & eax) == 0) goto L51a6e3;  // @669_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @670_519ea0
  ecx = edx = 0;  // @671_519ea0
  ecx = esi;  // @672_519ea0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @673_519ea0
  eax = ext_503770_thiscall2(ecx, (u32)(edi));  // @674_519ea0
  ecx = edx = 0;  // @675_519ea0
  return eax;  // @676_519ea0
  L51a6e3:;
  __builtin_trap();  // @678_519ea0
  L51a6e4:;
  ecx = esi;  // @680_519ea0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @681_519ea0
  eax = ext_503770_thiscall2(ecx, (u32)(edi));  // @682_519ea0
  ecx = edx = 0;  // @683_519ea0
  return eax;  // @684_519ea0
}
PCREG(519ea0, lifted_519ea0);

