// batch220002.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_50ffe0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @0_50ffe0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_50ffe0
  esi = ecx;  // @2_50ffe0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @3_50ffe0
  if (eax >= (u32)(50)) goto L510011;  // @4_50ffe0
  { u32 v = (u32)((u32)(5298656)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @5_50ffe0
  eax = (eax + 1);  // @6_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @7_50ffe0
  goto L51002e;  // @8_50ffe0
  L510011:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @11_50ffe0
  ecx = edx = 0;  // @12_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @13_50ffe0
  if ((eax & eax) == 0) goto L510028;  // @14_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @15_50ffe0
  ecx = edx = 0;  // @16_50ffe0
  goto L510029;  // @17_50ffe0
  L510028:;
  __builtin_trap();  // @19_50ffe0
  L510029:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @21_50ffe0
  L51002e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @23_50ffe0
  if (eax >= (u32)(50)) goto L510050;  // @24_50ffe0
  { u32 v = (u32)((u32)(5305312)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @25_50ffe0
  eax = (eax + 1);  // @26_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @27_50ffe0
  goto L51006f;  // @28_50ffe0
  L510050:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_50ffe0
  ecx = esi;  // @31_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @32_50ffe0
  ecx = edx = 0;  // @33_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @34_50ffe0
  if ((eax & eax) == 0) goto L510069;  // @35_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @36_50ffe0
  ecx = edx = 0;  // @37_50ffe0
  goto L51006a;  // @38_50ffe0
  L510069:;
  __builtin_trap();  // @40_50ffe0
  L51006a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @42_50ffe0
  L51006f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @44_50ffe0
  if (eax >= (u32)(50)) goto L510091;  // @45_50ffe0
  { u32 v = (u32)((u32)(5305312)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @46_50ffe0
  eax = (eax + 1);  // @47_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @48_50ffe0
  goto L5100b0;  // @49_50ffe0
  L510091:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_50ffe0
  ecx = esi;  // @52_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @53_50ffe0
  ecx = edx = 0;  // @54_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @55_50ffe0
  if ((eax & eax) == 0) goto L5100aa;  // @56_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @57_50ffe0
  ecx = edx = 0;  // @58_50ffe0
  goto L5100ab;  // @59_50ffe0
  L5100aa:;
  __builtin_trap();  // @61_50ffe0
  L5100ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @63_50ffe0
  L5100b0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @65_50ffe0
  if (eax >= (u32)(50)) goto L5100d2;  // @66_50ffe0
  { u32 v = (u32)((u32)(5305552)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @67_50ffe0
  eax = (eax + 1);  // @68_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @69_50ffe0
  goto L5100f1;  // @70_50ffe0
  L5100d2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_50ffe0
  ecx = esi;  // @73_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @74_50ffe0
  ecx = edx = 0;  // @75_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @76_50ffe0
  if ((eax & eax) == 0) goto L5100eb;  // @77_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @78_50ffe0
  ecx = edx = 0;  // @79_50ffe0
  goto L5100ec;  // @80_50ffe0
  L5100eb:;
  __builtin_trap();  // @82_50ffe0
  L5100ec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @84_50ffe0
  L5100f1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @86_50ffe0
  if (eax >= (u32)(50)) goto L510113;  // @87_50ffe0
  { u32 v = (u32)((u32)(5305056)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @88_50ffe0
  eax = (eax + 1);  // @89_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @90_50ffe0
  goto L510132;  // @91_50ffe0
  L510113:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_50ffe0
  ecx = esi;  // @94_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @95_50ffe0
  ecx = edx = 0;  // @96_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @97_50ffe0
  if ((eax & eax) == 0) goto L51012c;  // @98_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @99_50ffe0
  ecx = edx = 0;  // @100_50ffe0
  goto L51012d;  // @101_50ffe0
  L51012c:;
  __builtin_trap();  // @103_50ffe0
  L51012d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @105_50ffe0
  L510132:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @107_50ffe0
  if (eax >= (u32)(50)) goto L510154;  // @108_50ffe0
  { u32 v = (u32)((u32)(5304816)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @109_50ffe0
  eax = (eax + 1);  // @110_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @111_50ffe0
  goto L510173;  // @112_50ffe0
  L510154:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_50ffe0
  ecx = esi;  // @115_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @116_50ffe0
  ecx = edx = 0;  // @117_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @118_50ffe0
  if ((eax & eax) == 0) goto L51016d;  // @119_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @120_50ffe0
  ecx = edx = 0;  // @121_50ffe0
  goto L51016e;  // @122_50ffe0
  L51016d:;
  __builtin_trap();  // @124_50ffe0
  L51016e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @126_50ffe0
  L510173:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @128_50ffe0
  if (eax >= (u32)(50)) goto L510195;  // @129_50ffe0
  { u32 v = (u32)((u32)(5307424)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @130_50ffe0
  eax = (eax + 1);  // @131_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @132_50ffe0
  goto L5101b4;  // @133_50ffe0
  L510195:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @135_50ffe0
  ecx = esi;  // @136_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @137_50ffe0
  ecx = edx = 0;  // @138_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @139_50ffe0
  if ((eax & eax) == 0) goto L5101ae;  // @140_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @141_50ffe0
  ecx = edx = 0;  // @142_50ffe0
  goto L5101af;  // @143_50ffe0
  L5101ae:;
  __builtin_trap();  // @145_50ffe0
  L5101af:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @147_50ffe0
  L5101b4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @149_50ffe0
  if (eax >= (u32)(50)) goto L5101d6;  // @150_50ffe0
  { u32 v = (u32)((u32)(5307424)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @151_50ffe0
  eax = (eax + 1);  // @152_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @153_50ffe0
  goto L5101f5;  // @154_50ffe0
  L5101d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_50ffe0
  ecx = esi;  // @157_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @158_50ffe0
  ecx = edx = 0;  // @159_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @160_50ffe0
  if ((eax & eax) == 0) goto L5101ef;  // @161_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @162_50ffe0
  ecx = edx = 0;  // @163_50ffe0
  goto L5101f0;  // @164_50ffe0
  L5101ef:;
  __builtin_trap();  // @166_50ffe0
  L5101f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @168_50ffe0
  L5101f5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @170_50ffe0
  if (eax >= (u32)(50)) goto L510217;  // @171_50ffe0
  { u32 v = (u32)((u32)(5307648)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @172_50ffe0
  eax = (eax + 1);  // @173_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @174_50ffe0
  goto L510236;  // @175_50ffe0
  L510217:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_50ffe0
  ecx = esi;  // @178_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @179_50ffe0
  ecx = edx = 0;  // @180_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @181_50ffe0
  if ((eax & eax) == 0) goto L510230;  // @182_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @183_50ffe0
  ecx = edx = 0;  // @184_50ffe0
  goto L510231;  // @185_50ffe0
  L510230:;
  __builtin_trap();  // @187_50ffe0
  L510231:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @189_50ffe0
  L510236:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @191_50ffe0
  if (eax >= (u32)(50)) goto L510258;  // @192_50ffe0
  { u32 v = (u32)((u32)(5307248)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @193_50ffe0
  eax = (eax + 1);  // @194_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @195_50ffe0
  goto L510277;  // @196_50ffe0
  L510258:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_50ffe0
  ecx = esi;  // @199_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @200_50ffe0
  ecx = edx = 0;  // @201_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @202_50ffe0
  if ((eax & eax) == 0) goto L510271;  // @203_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @204_50ffe0
  ecx = edx = 0;  // @205_50ffe0
  goto L510272;  // @206_50ffe0
  L510271:;
  __builtin_trap();  // @208_50ffe0
  L510272:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @210_50ffe0
  L510277:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @212_50ffe0
  if (eax >= (u32)(50)) goto L510299;  // @213_50ffe0
  { u32 v = (u32)((u32)(5307024)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @214_50ffe0
  eax = (eax + 1);  // @215_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @216_50ffe0
  goto L5102b8;  // @217_50ffe0
  L510299:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @219_50ffe0
  ecx = esi;  // @220_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @221_50ffe0
  ecx = edx = 0;  // @222_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @223_50ffe0
  if ((eax & eax) == 0) goto L5102b2;  // @224_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @225_50ffe0
  ecx = edx = 0;  // @226_50ffe0
  goto L5102b3;  // @227_50ffe0
  L5102b2:;
  __builtin_trap();  // @229_50ffe0
  L5102b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @231_50ffe0
  L5102b8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @233_50ffe0
  if (eax >= (u32)(50)) goto L5102da;  // @234_50ffe0
  { u32 v = (u32)((u32)(5307952)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @235_50ffe0
  eax = (eax + 1);  // @236_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @237_50ffe0
  goto L5102f9;  // @238_50ffe0
  L5102da:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @240_50ffe0
  ecx = esi;  // @241_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @242_50ffe0
  ecx = edx = 0;  // @243_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @244_50ffe0
  if ((eax & eax) == 0) goto L5102f3;  // @245_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @246_50ffe0
  ecx = edx = 0;  // @247_50ffe0
  goto L5102f4;  // @248_50ffe0
  L5102f3:;
  __builtin_trap();  // @250_50ffe0
  L5102f4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @252_50ffe0
  L5102f9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @254_50ffe0
  if (eax >= (u32)(50)) goto L51031b;  // @255_50ffe0
  { u32 v = (u32)((u32)(5306320)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @256_50ffe0
  eax = (eax + 1);  // @257_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @258_50ffe0
  goto L51033a;  // @259_50ffe0
  L51031b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @261_50ffe0
  ecx = esi;  // @262_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @263_50ffe0
  ecx = edx = 0;  // @264_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @265_50ffe0
  if ((eax & eax) == 0) goto L510334;  // @266_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @267_50ffe0
  ecx = edx = 0;  // @268_50ffe0
  goto L510335;  // @269_50ffe0
  L510334:;
  __builtin_trap();  // @271_50ffe0
  L510335:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @273_50ffe0
  L51033a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @275_50ffe0
  if (eax >= (u32)(50)) goto L51035c;  // @276_50ffe0
  { u32 v = (u32)((u32)(5306288)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @277_50ffe0
  eax = (eax + 1);  // @278_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @279_50ffe0
  goto L51037b;  // @280_50ffe0
  L51035c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @282_50ffe0
  ecx = esi;  // @283_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @284_50ffe0
  ecx = edx = 0;  // @285_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @286_50ffe0
  if ((eax & eax) == 0) goto L510375;  // @287_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @288_50ffe0
  ecx = edx = 0;  // @289_50ffe0
  goto L510376;  // @290_50ffe0
  L510375:;
  __builtin_trap();  // @292_50ffe0
  L510376:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @294_50ffe0
  L51037b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @296_50ffe0
  if (eax >= (u32)(50)) goto L51039d;  // @297_50ffe0
  { u32 v = (u32)((u32)(5300128)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @298_50ffe0
  eax = (eax + 1);  // @299_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @300_50ffe0
  goto L5103bc;  // @301_50ffe0
  L51039d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @303_50ffe0
  ecx = esi;  // @304_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @305_50ffe0
  ecx = edx = 0;  // @306_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @307_50ffe0
  if ((eax & eax) == 0) goto L5103b6;  // @308_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @309_50ffe0
  ecx = edx = 0;  // @310_50ffe0
  goto L5103b7;  // @311_50ffe0
  L5103b6:;
  __builtin_trap();  // @313_50ffe0
  L5103b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @315_50ffe0
  L5103bc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @317_50ffe0
  if (eax >= (u32)(50)) goto L5103de;  // @318_50ffe0
  { u32 v = (u32)((u32)(5304608)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @319_50ffe0
  eax = (eax + 1);  // @320_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @321_50ffe0
  goto L5103fd;  // @322_50ffe0
  L5103de:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @324_50ffe0
  ecx = esi;  // @325_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @326_50ffe0
  ecx = edx = 0;  // @327_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @328_50ffe0
  if ((eax & eax) == 0) goto L5103f7;  // @329_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @330_50ffe0
  ecx = edx = 0;  // @331_50ffe0
  goto L5103f8;  // @332_50ffe0
  L5103f7:;
  __builtin_trap();  // @334_50ffe0
  L5103f8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @336_50ffe0
  L5103fd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @338_50ffe0
  if (eax >= (u32)(50)) goto L51041f;  // @339_50ffe0
  { u32 v = (u32)((u32)(5304416)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @340_50ffe0
  eax = (eax + 1);  // @341_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @342_50ffe0
  goto L51043e;  // @343_50ffe0
  L51041f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @345_50ffe0
  ecx = esi;  // @346_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @347_50ffe0
  ecx = edx = 0;  // @348_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @349_50ffe0
  if ((eax & eax) == 0) goto L510438;  // @350_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @351_50ffe0
  ecx = edx = 0;  // @352_50ffe0
  goto L510439;  // @353_50ffe0
  L510438:;
  __builtin_trap();  // @355_50ffe0
  L510439:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @357_50ffe0
  L51043e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @359_50ffe0
  if (eax >= (u32)(50)) goto L510460;  // @360_50ffe0
  { u32 v = (u32)((u32)(5302112)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @361_50ffe0
  eax = (eax + 1);  // @362_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @363_50ffe0
  goto L51047f;  // @364_50ffe0
  L510460:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @366_50ffe0
  ecx = esi;  // @367_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @368_50ffe0
  ecx = edx = 0;  // @369_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @370_50ffe0
  if ((eax & eax) == 0) goto L510479;  // @371_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @372_50ffe0
  ecx = edx = 0;  // @373_50ffe0
  goto L51047a;  // @374_50ffe0
  L510479:;
  __builtin_trap();  // @376_50ffe0
  L51047a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @378_50ffe0
  L51047f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @380_50ffe0
  if (eax >= (u32)(50)) goto L5104a1;  // @381_50ffe0
  { u32 v = (u32)((u32)(5302256)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @382_50ffe0
  eax = (eax + 1);  // @383_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @384_50ffe0
  goto L5104c0;  // @385_50ffe0
  L5104a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @387_50ffe0
  ecx = esi;  // @388_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @389_50ffe0
  ecx = edx = 0;  // @390_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @391_50ffe0
  if ((eax & eax) == 0) goto L5104ba;  // @392_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @393_50ffe0
  ecx = edx = 0;  // @394_50ffe0
  goto L5104bb;  // @395_50ffe0
  L5104ba:;
  __builtin_trap();  // @397_50ffe0
  L5104bb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @399_50ffe0
  L5104c0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @401_50ffe0
  if (eax >= (u32)(50)) goto L5104e2;  // @402_50ffe0
  { u32 v = (u32)((u32)(5300560)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @403_50ffe0
  eax = (eax + 1);  // @404_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @405_50ffe0
  goto L510501;  // @406_50ffe0
  L5104e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @408_50ffe0
  ecx = esi;  // @409_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @410_50ffe0
  ecx = edx = 0;  // @411_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @412_50ffe0
  if ((eax & eax) == 0) goto L5104fb;  // @413_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @414_50ffe0
  ecx = edx = 0;  // @415_50ffe0
  goto L5104fc;  // @416_50ffe0
  L5104fb:;
  __builtin_trap();  // @418_50ffe0
  L5104fc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @420_50ffe0
  L510501:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @422_50ffe0
  if (eax >= (u32)(50)) goto L510523;  // @423_50ffe0
  { u32 v = (u32)((u32)(5299536)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @424_50ffe0
  eax = (eax + 1);  // @425_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @426_50ffe0
  goto L510542;  // @427_50ffe0
  L510523:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @429_50ffe0
  ecx = esi;  // @430_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @431_50ffe0
  ecx = edx = 0;  // @432_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @433_50ffe0
  if ((eax & eax) == 0) goto L51053c;  // @434_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @435_50ffe0
  ecx = edx = 0;  // @436_50ffe0
  goto L51053d;  // @437_50ffe0
  L51053c:;
  __builtin_trap();  // @439_50ffe0
  L51053d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @441_50ffe0
  L510542:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @443_50ffe0
  if (eax >= (u32)(50)) goto L510564;  // @444_50ffe0
  { u32 v = (u32)((u32)(5299792)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @445_50ffe0
  eax = (eax + 1);  // @446_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @447_50ffe0
  goto L510583;  // @448_50ffe0
  L510564:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @450_50ffe0
  ecx = esi;  // @451_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @452_50ffe0
  ecx = edx = 0;  // @453_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @454_50ffe0
  if ((eax & eax) == 0) goto L51057d;  // @455_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @456_50ffe0
  ecx = edx = 0;  // @457_50ffe0
  goto L51057e;  // @458_50ffe0
  L51057d:;
  __builtin_trap();  // @460_50ffe0
  L51057e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @462_50ffe0
  L510583:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @464_50ffe0
  if (eax >= (u32)(50)) goto L5105a5;  // @465_50ffe0
  { u32 v = (u32)((u32)(5311808)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @466_50ffe0
  eax = (eax + 1);  // @467_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @468_50ffe0
  goto L5105c4;  // @469_50ffe0
  L5105a5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @471_50ffe0
  ecx = esi;  // @472_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @473_50ffe0
  ecx = edx = 0;  // @474_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @475_50ffe0
  if ((eax & eax) == 0) goto L5105be;  // @476_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @477_50ffe0
  ecx = edx = 0;  // @478_50ffe0
  goto L5105bf;  // @479_50ffe0
  L5105be:;
  __builtin_trap();  // @481_50ffe0
  L5105bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @483_50ffe0
  L5105c4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @485_50ffe0
  if (eax >= (u32)(50)) goto L5105e6;  // @486_50ffe0
  { u32 v = (u32)((u32)(5311472)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @487_50ffe0
  eax = (eax + 1);  // @488_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @489_50ffe0
  goto L510605;  // @490_50ffe0
  L5105e6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @492_50ffe0
  ecx = esi;  // @493_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @494_50ffe0
  ecx = edx = 0;  // @495_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @496_50ffe0
  if ((eax & eax) == 0) goto L5105ff;  // @497_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @498_50ffe0
  ecx = edx = 0;  // @499_50ffe0
  goto L510600;  // @500_50ffe0
  L5105ff:;
  __builtin_trap();  // @502_50ffe0
  L510600:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @504_50ffe0
  L510605:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @506_50ffe0
  if (eax >= (u32)(50)) goto L510627;  // @507_50ffe0
  { u32 v = (u32)((u32)(5299296)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @508_50ffe0
  eax = (eax + 1);  // @509_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @510_50ffe0
  goto L510646;  // @511_50ffe0
  L510627:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @513_50ffe0
  ecx = esi;  // @514_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @515_50ffe0
  ecx = edx = 0;  // @516_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @517_50ffe0
  if ((eax & eax) == 0) goto L510640;  // @518_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @519_50ffe0
  ecx = edx = 0;  // @520_50ffe0
  goto L510641;  // @521_50ffe0
  L510640:;
  __builtin_trap();  // @523_50ffe0
  L510641:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @525_50ffe0
  L510646:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @527_50ffe0
  if (eax >= (u32)(50)) goto L510668;  // @528_50ffe0
  { u32 v = (u32)((u32)(5306448)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @529_50ffe0
  eax = (eax + 1);  // @530_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @531_50ffe0
  goto L510687;  // @532_50ffe0
  L510668:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @534_50ffe0
  ecx = esi;  // @535_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @536_50ffe0
  ecx = edx = 0;  // @537_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @538_50ffe0
  if ((eax & eax) == 0) goto L510681;  // @539_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @540_50ffe0
  ecx = edx = 0;  // @541_50ffe0
  goto L510682;  // @542_50ffe0
  L510681:;
  __builtin_trap();  // @544_50ffe0
  L510682:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @546_50ffe0
  L510687:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @548_50ffe0
  if (eax >= (u32)(50)) goto L5106a9;  // @549_50ffe0
  { u32 v = (u32)((u32)(5303072)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @550_50ffe0
  eax = (eax + 1);  // @551_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @552_50ffe0
  goto L5106c8;  // @553_50ffe0
  L5106a9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @555_50ffe0
  ecx = esi;  // @556_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @557_50ffe0
  ecx = edx = 0;  // @558_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @559_50ffe0
  if ((eax & eax) == 0) goto L5106c2;  // @560_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @561_50ffe0
  ecx = edx = 0;  // @562_50ffe0
  goto L5106c3;  // @563_50ffe0
  L5106c2:;
  __builtin_trap();  // @565_50ffe0
  L5106c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @567_50ffe0
  L5106c8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @569_50ffe0
  if (eax >= (u32)(50)) goto L5106ea;  // @570_50ffe0
  { u32 v = (u32)((u32)(5303552)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @571_50ffe0
  eax = (eax + 1);  // @572_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @573_50ffe0
  goto L510709;  // @574_50ffe0
  L5106ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @576_50ffe0
  ecx = esi;  // @577_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @578_50ffe0
  ecx = edx = 0;  // @579_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @580_50ffe0
  if ((eax & eax) == 0) goto L510703;  // @581_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @582_50ffe0
  ecx = edx = 0;  // @583_50ffe0
  goto L510704;  // @584_50ffe0
  L510703:;
  __builtin_trap();  // @586_50ffe0
  L510704:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @588_50ffe0
  L510709:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @590_50ffe0
  if (eax >= (u32)(50)) goto L51072b;  // @591_50ffe0
  { u32 v = (u32)((u32)(5301008)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @592_50ffe0
  eax = (eax + 1);  // @593_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @594_50ffe0
  goto L51074a;  // @595_50ffe0
  L51072b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @597_50ffe0
  ecx = esi;  // @598_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @599_50ffe0
  ecx = edx = 0;  // @600_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @601_50ffe0
  if ((eax & eax) == 0) goto L510744;  // @602_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @603_50ffe0
  ecx = edx = 0;  // @604_50ffe0
  goto L510745;  // @605_50ffe0
  L510744:;
  __builtin_trap();  // @607_50ffe0
  L510745:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @609_50ffe0
  L51074a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @611_50ffe0
  if (eax >= (u32)(50)) goto L51076c;  // @612_50ffe0
  { u32 v = (u32)((u32)(5302560)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @613_50ffe0
  eax = (eax + 1);  // @614_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @615_50ffe0
  goto L51078b;  // @616_50ffe0
  L51076c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @618_50ffe0
  ecx = esi;  // @619_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @620_50ffe0
  ecx = edx = 0;  // @621_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @622_50ffe0
  if ((eax & eax) == 0) goto L510785;  // @623_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @624_50ffe0
  ecx = edx = 0;  // @625_50ffe0
  goto L510786;  // @626_50ffe0
  L510785:;
  __builtin_trap();  // @628_50ffe0
  L510786:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @630_50ffe0
  L51078b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @632_50ffe0
  if (eax >= (u32)(50)) goto L5107ad;  // @633_50ffe0
  { u32 v = (u32)((u32)(5305776)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @634_50ffe0
  eax = (eax + 1);  // @635_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @636_50ffe0
  goto L5107cc;  // @637_50ffe0
  L5107ad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @639_50ffe0
  ecx = esi;  // @640_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @641_50ffe0
  ecx = edx = 0;  // @642_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @643_50ffe0
  if ((eax & eax) == 0) goto L5107c6;  // @644_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @645_50ffe0
  ecx = edx = 0;  // @646_50ffe0
  goto L5107c7;  // @647_50ffe0
  L5107c6:;
  __builtin_trap();  // @649_50ffe0
  L5107c7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @651_50ffe0
  L5107cc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @653_50ffe0
  if (eax >= (u32)(50)) goto L5107ee;  // @654_50ffe0
  { u32 v = (u32)((u32)(5305872)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @655_50ffe0
  eax = (eax + 1);  // @656_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @657_50ffe0
  goto L51080d;  // @658_50ffe0
  L5107ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @660_50ffe0
  ecx = esi;  // @661_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @662_50ffe0
  ecx = edx = 0;  // @663_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @664_50ffe0
  if ((eax & eax) == 0) goto L510807;  // @665_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @666_50ffe0
  ecx = edx = 0;  // @667_50ffe0
  goto L510808;  // @668_50ffe0
  L510807:;
  __builtin_trap();  // @670_50ffe0
  L510808:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @672_50ffe0
  L51080d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @674_50ffe0
  if (eax >= (u32)(50)) goto L51082f;  // @675_50ffe0
  { u32 v = (u32)((u32)(5308192)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @676_50ffe0
  eax = (eax + 1);  // @677_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @678_50ffe0
  goto L51084e;  // @679_50ffe0
  L51082f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @681_50ffe0
  ecx = esi;  // @682_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @683_50ffe0
  ecx = edx = 0;  // @684_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @685_50ffe0
  if ((eax & eax) == 0) goto L510848;  // @686_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @687_50ffe0
  ecx = edx = 0;  // @688_50ffe0
  goto L510849;  // @689_50ffe0
  L510848:;
  __builtin_trap();  // @691_50ffe0
  L510849:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @693_50ffe0
  L51084e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @695_50ffe0
  if (eax >= (u32)(50)) goto L510870;  // @696_50ffe0
  { u32 v = (u32)((u32)(5308288)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @697_50ffe0
  eax = (eax + 1);  // @698_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @699_50ffe0
  goto L51088f;  // @700_50ffe0
  L510870:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @702_50ffe0
  ecx = esi;  // @703_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @704_50ffe0
  ecx = edx = 0;  // @705_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @706_50ffe0
  if ((eax & eax) == 0) goto L510889;  // @707_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @708_50ffe0
  ecx = edx = 0;  // @709_50ffe0
  goto L51088a;  // @710_50ffe0
  L510889:;
  __builtin_trap();  // @712_50ffe0
  L51088a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @714_50ffe0
  L51088f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @716_50ffe0
  if (eax >= (u32)(50)) goto L5108b1;  // @717_50ffe0
  { u32 v = (u32)((u32)(5306032)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @718_50ffe0
  eax = (eax + 1);  // @719_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @720_50ffe0
  goto L5108d0;  // @721_50ffe0
  L5108b1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @723_50ffe0
  ecx = esi;  // @724_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @725_50ffe0
  ecx = edx = 0;  // @726_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @727_50ffe0
  if ((eax & eax) == 0) goto L5108ca;  // @728_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @729_50ffe0
  ecx = edx = 0;  // @730_50ffe0
  goto L5108cb;  // @731_50ffe0
  L5108ca:;
  __builtin_trap();  // @733_50ffe0
  L5108cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @735_50ffe0
  L5108d0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @737_50ffe0
  if (eax >= (u32)(50)) goto L5108f2;  // @738_50ffe0
  { u32 v = (u32)((u32)(5306128)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @739_50ffe0
  eax = (eax + 1);  // @740_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @741_50ffe0
  goto L510911;  // @742_50ffe0
  L5108f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @744_50ffe0
  ecx = esi;  // @745_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @746_50ffe0
  ecx = edx = 0;  // @747_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @748_50ffe0
  if ((eax & eax) == 0) goto L51090b;  // @749_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @750_50ffe0
  ecx = edx = 0;  // @751_50ffe0
  goto L51090c;  // @752_50ffe0
  L51090b:;
  __builtin_trap();  // @754_50ffe0
  L51090c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @756_50ffe0
  L510911:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @758_50ffe0
  if (eax >= (u32)(50)) goto L510933;  // @759_50ffe0
  { u32 v = (u32)((u32)(5302432)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @760_50ffe0
  eax = (eax + 1);  // @761_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @762_50ffe0
  goto L510952;  // @763_50ffe0
  L510933:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @765_50ffe0
  ecx = esi;  // @766_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @767_50ffe0
  ecx = edx = 0;  // @768_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @769_50ffe0
  if ((eax & eax) == 0) goto L51094c;  // @770_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @771_50ffe0
  ecx = edx = 0;  // @772_50ffe0
  goto L51094d;  // @773_50ffe0
  L51094c:;
  __builtin_trap();  // @775_50ffe0
  L51094d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @777_50ffe0
  L510952:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @779_50ffe0
  if (eax >= (u32)(50)) goto L510974;  // @780_50ffe0
  { u32 v = (u32)((u32)(5306864)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @781_50ffe0
  eax = (eax + 1);  // @782_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @783_50ffe0
  goto L510993;  // @784_50ffe0
  L510974:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @786_50ffe0
  ecx = esi;  // @787_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @788_50ffe0
  ecx = edx = 0;  // @789_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @790_50ffe0
  if ((eax & eax) == 0) goto L51098d;  // @791_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @792_50ffe0
  ecx = edx = 0;  // @793_50ffe0
  goto L51098e;  // @794_50ffe0
  L51098d:;
  __builtin_trap();  // @796_50ffe0
  L51098e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @798_50ffe0
  L510993:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @800_50ffe0
  if (eax >= (u32)(50)) goto L5109b5;  // @801_50ffe0
  { u32 v = (u32)((u32)(5299024)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @802_50ffe0
  eax = (eax + 1);  // @803_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @804_50ffe0
  goto L5109d4;  // @805_50ffe0
  L5109b5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @807_50ffe0
  ecx = esi;  // @808_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @809_50ffe0
  ecx = edx = 0;  // @810_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @811_50ffe0
  if ((eax & eax) == 0) goto L5109ce;  // @812_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @813_50ffe0
  ecx = edx = 0;  // @814_50ffe0
  goto L5109cf;  // @815_50ffe0
  L5109ce:;
  __builtin_trap();  // @817_50ffe0
  L5109cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @819_50ffe0
  L5109d4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @821_50ffe0
  if (eax >= (u32)(50)) goto L5109f6;  // @822_50ffe0
  { u32 v = (u32)((u32)(5298896)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @823_50ffe0
  eax = (eax + 1);  // @824_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @825_50ffe0
  goto L510a15;  // @826_50ffe0
  L5109f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @828_50ffe0
  ecx = esi;  // @829_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @830_50ffe0
  ecx = edx = 0;  // @831_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @832_50ffe0
  if ((eax & eax) == 0) goto L510a0f;  // @833_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @834_50ffe0
  ecx = edx = 0;  // @835_50ffe0
  goto L510a10;  // @836_50ffe0
  L510a0f:;
  __builtin_trap();  // @838_50ffe0
  L510a10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @840_50ffe0
  L510a15:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @842_50ffe0
  if (eax >= (u32)(50)) goto L510a37;  // @843_50ffe0
  { u32 v = (u32)((u32)(5305968)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @844_50ffe0
  eax = (eax + 1);  // @845_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @846_50ffe0
  goto L510a56;  // @847_50ffe0
  L510a37:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @849_50ffe0
  ecx = esi;  // @850_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @851_50ffe0
  ecx = edx = 0;  // @852_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @853_50ffe0
  if ((eax & eax) == 0) goto L510a50;  // @854_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @855_50ffe0
  ecx = edx = 0;  // @856_50ffe0
  goto L510a51;  // @857_50ffe0
  L510a50:;
  __builtin_trap();  // @859_50ffe0
  L510a51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @861_50ffe0
  L510a56:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @863_50ffe0
  if (eax >= (u32)(50)) goto L510a74;  // @864_50ffe0
  { u32 v = (u32)((u32)(5306224)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @865_50ffe0
  eax = (eax + 1);  // @866_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @867_50ffe0
  goto L510a93;  // @868_50ffe0
  L510a74:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @870_50ffe0
  ecx = esi;  // @871_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @872_50ffe0
  ecx = edx = 0;  // @873_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @874_50ffe0
  if ((eax & eax) == 0) goto L510a8d;  // @875_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @876_50ffe0
  ecx = edx = 0;  // @877_50ffe0
  goto L510a8e;  // @878_50ffe0
  L510a8d:;
  __builtin_trap();  // @880_50ffe0
  L510a8e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @882_50ffe0
  L510a93:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @884_50ffe0
  if (eax >= (u32)(50)) goto L510ab5;  // @885_50ffe0
  { u32 v = (u32)((u32)(5289232)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @886_50ffe0
  eax = (eax + 1);  // @887_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @888_50ffe0
  return eax;  // @889_50ffe0
  L510ab5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @891_50ffe0
  ecx = esi;  // @892_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @893_50ffe0
  ecx = edx = 0;  // @894_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @895_50ffe0
  if ((eax & eax) == 0) goto L510ad2;  // @896_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @897_50ffe0
  ecx = edx = 0;  // @898_50ffe0
  return eax;  // @899_50ffe0
  L510ad2:;
  __builtin_trap();  // @901_50ffe0
  L510ad3:;
  return eax;  // @903_50ffe0
}
PCREG(50ffe0, lifted_50ffe0);

