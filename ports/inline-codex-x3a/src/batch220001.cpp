// batch220001.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_503770(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @0_503770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_503770
  esi = ecx;  // @2_503770
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @3_503770
  if (eax >= (u32)(60)) goto L5037a1;  // @4_503770
  { u32 v = (u32)((u32)(5256976)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @5_503770
  eax = (eax + 1);  // @6_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @7_503770
  goto L5037be;  // @8_503770
  L5037a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @11_503770
  ecx = edx = 0;  // @12_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @13_503770
  if ((eax & eax) == 0) goto L5037b8;  // @14_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @15_503770
  ecx = edx = 0;  // @16_503770
  goto L5037b9;  // @17_503770
  L5037b8:;
  __builtin_trap();  // @19_503770
  L5037b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @21_503770
  L5037be:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @23_503770
  if (eax >= (u32)(60)) goto L5037e0;  // @24_503770
  { u32 v = (u32)((u32)(5248336)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @25_503770
  eax = (eax + 1);  // @26_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @27_503770
  goto L5037ff;  // @28_503770
  L5037e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_503770
  ecx = esi;  // @31_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @32_503770
  ecx = edx = 0;  // @33_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @34_503770
  if ((eax & eax) == 0) goto L5037f9;  // @35_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @36_503770
  ecx = edx = 0;  // @37_503770
  goto L5037fa;  // @38_503770
  L5037f9:;
  __builtin_trap();  // @40_503770
  L5037fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @42_503770
  L5037ff:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @44_503770
  if (eax >= (u32)(60)) goto L503821;  // @45_503770
  { u32 v = (u32)((u32)(5249120)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @46_503770
  eax = (eax + 1);  // @47_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @48_503770
  goto L503840;  // @49_503770
  L503821:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_503770
  ecx = esi;  // @52_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @53_503770
  ecx = edx = 0;  // @54_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @55_503770
  if ((eax & eax) == 0) goto L50383a;  // @56_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @57_503770
  ecx = edx = 0;  // @58_503770
  goto L50383b;  // @59_503770
  L50383a:;
  __builtin_trap();  // @61_503770
  L50383b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @63_503770
  L503840:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @65_503770
  if (eax >= (u32)(60)) goto L503862;  // @66_503770
  { u32 v = (u32)((u32)(5256816)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @67_503770
  eax = (eax + 1);  // @68_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @69_503770
  goto L503881;  // @70_503770
  L503862:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_503770
  ecx = esi;  // @73_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @74_503770
  ecx = edx = 0;  // @75_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @76_503770
  if ((eax & eax) == 0) goto L50387b;  // @77_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @78_503770
  ecx = edx = 0;  // @79_503770
  goto L50387c;  // @80_503770
  L50387b:;
  __builtin_trap();  // @82_503770
  L50387c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @84_503770
  L503881:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @86_503770
  if (eax >= (u32)(60)) goto L5038a3;  // @87_503770
  { u32 v = (u32)((u32)(5256432)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @88_503770
  eax = (eax + 1);  // @89_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @90_503770
  goto L5038c2;  // @91_503770
  L5038a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_503770
  ecx = esi;  // @94_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @95_503770
  ecx = edx = 0;  // @96_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @97_503770
  if ((eax & eax) == 0) goto L5038bc;  // @98_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @99_503770
  ecx = edx = 0;  // @100_503770
  goto L5038bd;  // @101_503770
  L5038bc:;
  __builtin_trap();  // @103_503770
  L5038bd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @105_503770
  L5038c2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @107_503770
  if (eax >= (u32)(60)) goto L5038e4;  // @108_503770
  { u32 v = (u32)((u32)(5256608)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @109_503770
  eax = (eax + 1);  // @110_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @111_503770
  goto L503903;  // @112_503770
  L5038e4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_503770
  ecx = esi;  // @115_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @116_503770
  ecx = edx = 0;  // @117_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @118_503770
  if ((eax & eax) == 0) goto L5038fd;  // @119_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @120_503770
  ecx = edx = 0;  // @121_503770
  goto L5038fe;  // @122_503770
  L5038fd:;
  __builtin_trap();  // @124_503770
  L5038fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @126_503770
  L503903:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @128_503770
  if (eax >= (u32)(60)) goto L503925;  // @129_503770
  { u32 v = (u32)((u32)(5248800)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @130_503770
  eax = (eax + 1);  // @131_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @132_503770
  goto L503944;  // @133_503770
  L503925:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @135_503770
  ecx = esi;  // @136_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @137_503770
  ecx = edx = 0;  // @138_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @139_503770
  if ((eax & eax) == 0) goto L50393e;  // @140_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @141_503770
  ecx = edx = 0;  // @142_503770
  goto L50393f;  // @143_503770
  L50393e:;
  __builtin_trap();  // @145_503770
  L50393f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @147_503770
  L503944:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @149_503770
  if (eax >= (u32)(60)) goto L503966;  // @150_503770
  { u32 v = (u32)((u32)(5249504)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @151_503770
  eax = (eax + 1);  // @152_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @153_503770
  goto L503985;  // @154_503770
  L503966:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_503770
  ecx = esi;  // @157_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @158_503770
  ecx = edx = 0;  // @159_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @160_503770
  if ((eax & eax) == 0) goto L50397f;  // @161_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @162_503770
  ecx = edx = 0;  // @163_503770
  goto L503980;  // @164_503770
  L50397f:;
  __builtin_trap();  // @166_503770
  L503980:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @168_503770
  L503985:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @170_503770
  if (eax >= (u32)(60)) goto L5039a7;  // @171_503770
  { u32 v = (u32)((u32)(5246128)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @172_503770
  eax = (eax + 1);  // @173_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @174_503770
  goto L5039c6;  // @175_503770
  L5039a7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_503770
  ecx = esi;  // @178_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @179_503770
  ecx = edx = 0;  // @180_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @181_503770
  if ((eax & eax) == 0) goto L5039c0;  // @182_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @183_503770
  ecx = edx = 0;  // @184_503770
  goto L5039c1;  // @185_503770
  L5039c0:;
  __builtin_trap();  // @187_503770
  L5039c1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @189_503770
  L5039c6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @191_503770
  if (eax >= (u32)(60)) goto L5039e8;  // @192_503770
  { u32 v = (u32)((u32)(5245520)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @193_503770
  eax = (eax + 1);  // @194_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @195_503770
  goto L503a07;  // @196_503770
  L5039e8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_503770
  ecx = esi;  // @199_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @200_503770
  ecx = edx = 0;  // @201_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @202_503770
  if ((eax & eax) == 0) goto L503a01;  // @203_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @204_503770
  ecx = edx = 0;  // @205_503770
  goto L503a02;  // @206_503770
  L503a01:;
  __builtin_trap();  // @208_503770
  L503a02:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @210_503770
  L503a07:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @212_503770
  if (eax >= (u32)(60)) goto L503a29;  // @213_503770
  { u32 v = (u32)((u32)(5247632)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @214_503770
  eax = (eax + 1);  // @215_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @216_503770
  goto L503a48;  // @217_503770
  L503a29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @219_503770
  ecx = esi;  // @220_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @221_503770
  ecx = edx = 0;  // @222_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @223_503770
  if ((eax & eax) == 0) goto L503a42;  // @224_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @225_503770
  ecx = edx = 0;  // @226_503770
  goto L503a43;  // @227_503770
  L503a42:;
  __builtin_trap();  // @229_503770
  L503a43:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @231_503770
  L503a48:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @233_503770
  if (eax >= (u32)(60)) goto L503a6a;  // @234_503770
  { u32 v = (u32)((u32)(5248048)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @235_503770
  eax = (eax + 1);  // @236_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @237_503770
  goto L503a89;  // @238_503770
  L503a6a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @240_503770
  ecx = esi;  // @241_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @242_503770
  ecx = edx = 0;  // @243_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @244_503770
  if ((eax & eax) == 0) goto L503a83;  // @245_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @246_503770
  ecx = edx = 0;  // @247_503770
  goto L503a84;  // @248_503770
  L503a83:;
  __builtin_trap();  // @250_503770
  L503a84:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @252_503770
  L503a89:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @254_503770
  if (eax >= (u32)(60)) goto L503aab;  // @255_503770
  { u32 v = (u32)((u32)(5247056)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @256_503770
  eax = (eax + 1);  // @257_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @258_503770
  goto L503aca;  // @259_503770
  L503aab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @261_503770
  ecx = esi;  // @262_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @263_503770
  ecx = edx = 0;  // @264_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @265_503770
  if ((eax & eax) == 0) goto L503ac4;  // @266_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @267_503770
  ecx = edx = 0;  // @268_503770
  goto L503ac5;  // @269_503770
  L503ac4:;
  __builtin_trap();  // @271_503770
  L503ac5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @273_503770
  L503aca:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @275_503770
  if (eax >= (u32)(60)) goto L503aec;  // @276_503770
  { u32 v = (u32)((u32)(5247216)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @277_503770
  eax = (eax + 1);  // @278_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @279_503770
  goto L503b0b;  // @280_503770
  L503aec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @282_503770
  ecx = esi;  // @283_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @284_503770
  ecx = edx = 0;  // @285_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @286_503770
  if ((eax & eax) == 0) goto L503b05;  // @287_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @288_503770
  ecx = edx = 0;  // @289_503770
  goto L503b06;  // @290_503770
  L503b05:;
  __builtin_trap();  // @292_503770
  L503b06:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @294_503770
  L503b0b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @296_503770
  if (eax >= (u32)(60)) goto L503b2d;  // @297_503770
  { u32 v = (u32)((u32)(5250784)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @298_503770
  eax = (eax + 1);  // @299_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @300_503770
  goto L503b4c;  // @301_503770
  L503b2d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @303_503770
  ecx = esi;  // @304_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @305_503770
  ecx = edx = 0;  // @306_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @307_503770
  if ((eax & eax) == 0) goto L503b46;  // @308_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @309_503770
  ecx = edx = 0;  // @310_503770
  goto L503b47;  // @311_503770
  L503b46:;
  __builtin_trap();  // @313_503770
  L503b47:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @315_503770
  L503b4c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @317_503770
  if (eax >= (u32)(60)) goto L503b6e;  // @318_503770
  { u32 v = (u32)((u32)(5250624)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @319_503770
  eax = (eax + 1);  // @320_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @321_503770
  goto L503b8d;  // @322_503770
  L503b6e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @324_503770
  ecx = esi;  // @325_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @326_503770
  ecx = edx = 0;  // @327_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @328_503770
  if ((eax & eax) == 0) goto L503b87;  // @329_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @330_503770
  ecx = edx = 0;  // @331_503770
  goto L503b88;  // @332_503770
  L503b87:;
  __builtin_trap();  // @334_503770
  L503b88:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @336_503770
  L503b8d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @338_503770
  if (eax >= (u32)(60)) goto L503baf;  // @339_503770
  { u32 v = (u32)((u32)(5250464)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @340_503770
  eax = (eax + 1);  // @341_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @342_503770
  goto L503bce;  // @343_503770
  L503baf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @345_503770
  ecx = esi;  // @346_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @347_503770
  ecx = edx = 0;  // @348_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @349_503770
  if ((eax & eax) == 0) goto L503bc8;  // @350_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @351_503770
  ecx = edx = 0;  // @352_503770
  goto L503bc9;  // @353_503770
  L503bc8:;
  __builtin_trap();  // @355_503770
  L503bc9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @357_503770
  L503bce:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @359_503770
  if (eax >= (u32)(60)) goto L503bf0;  // @360_503770
  { u32 v = (u32)((u32)(5250256)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @361_503770
  eax = (eax + 1);  // @362_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @363_503770
  goto L503c0f;  // @364_503770
  L503bf0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @366_503770
  ecx = esi;  // @367_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @368_503770
  ecx = edx = 0;  // @369_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @370_503770
  if ((eax & eax) == 0) goto L503c09;  // @371_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @372_503770
  ecx = edx = 0;  // @373_503770
  goto L503c0a;  // @374_503770
  L503c09:;
  __builtin_trap();  // @376_503770
  L503c0a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @378_503770
  L503c0f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @380_503770
  if (eax >= (u32)(60)) goto L503c31;  // @381_503770
  { u32 v = (u32)((u32)(5249072)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @382_503770
  eax = (eax + 1);  // @383_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @384_503770
  goto L503c50;  // @385_503770
  L503c31:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @387_503770
  ecx = esi;  // @388_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @389_503770
  ecx = edx = 0;  // @390_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @391_503770
  if ((eax & eax) == 0) goto L503c4a;  // @392_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @393_503770
  ecx = edx = 0;  // @394_503770
  goto L503c4b;  // @395_503770
  L503c4a:;
  __builtin_trap();  // @397_503770
  L503c4b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @399_503770
  L503c50:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @401_503770
  if (eax >= (u32)(60)) goto L503c72;  // @402_503770
  { u32 v = (u32)((u32)(5248784)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @403_503770
  eax = (eax + 1);  // @404_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @405_503770
  goto L503c91;  // @406_503770
  L503c72:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @408_503770
  ecx = esi;  // @409_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @410_503770
  ecx = edx = 0;  // @411_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @412_503770
  if ((eax & eax) == 0) goto L503c8b;  // @413_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @414_503770
  ecx = edx = 0;  // @415_503770
  goto L503c8c;  // @416_503770
  L503c8b:;
  __builtin_trap();  // @418_503770
  L503c8c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @420_503770
  L503c91:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @422_503770
  if (eax >= (u32)(60)) goto L503cb3;  // @423_503770
  { u32 v = (u32)((u32)(5248768)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @424_503770
  eax = (eax + 1);  // @425_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @426_503770
  goto L503cd2;  // @427_503770
  L503cb3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @429_503770
  ecx = esi;  // @430_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @431_503770
  ecx = edx = 0;  // @432_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @433_503770
  if ((eax & eax) == 0) goto L503ccc;  // @434_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @435_503770
  ecx = edx = 0;  // @436_503770
  goto L503ccd;  // @437_503770
  L503ccc:;
  __builtin_trap();  // @439_503770
  L503ccd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @441_503770
  L503cd2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @443_503770
  if (eax >= (u32)(60)) goto L503cf4;  // @444_503770
  { u32 v = (u32)((u32)(5246656)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @445_503770
  eax = (eax + 1);  // @446_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @447_503770
  goto L503d13;  // @448_503770
  L503cf4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @450_503770
  ecx = esi;  // @451_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @452_503770
  ecx = edx = 0;  // @453_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @454_503770
  if ((eax & eax) == 0) goto L503d0d;  // @455_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @456_503770
  ecx = edx = 0;  // @457_503770
  goto L503d0e;  // @458_503770
  L503d0d:;
  __builtin_trap();  // @460_503770
  L503d0e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @462_503770
  L503d13:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @464_503770
  if (eax >= (u32)(60)) goto L503d35;  // @465_503770
  { u32 v = (u32)((u32)(5246640)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @466_503770
  eax = (eax + 1);  // @467_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @468_503770
  goto L503d54;  // @469_503770
  L503d35:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @471_503770
  ecx = esi;  // @472_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @473_503770
  ecx = edx = 0;  // @474_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @475_503770
  if ((eax & eax) == 0) goto L503d4e;  // @476_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @477_503770
  ecx = edx = 0;  // @478_503770
  goto L503d4f;  // @479_503770
  L503d4e:;
  __builtin_trap();  // @481_503770
  L503d4f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @483_503770
  L503d54:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @485_503770
  if (eax >= (u32)(60)) goto L503d76;  // @486_503770
  { u32 v = (u32)((u32)(5250944)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @487_503770
  eax = (eax + 1);  // @488_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @489_503770
  goto L503d95;  // @490_503770
  L503d76:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @492_503770
  ecx = esi;  // @493_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @494_503770
  ecx = edx = 0;  // @495_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @496_503770
  if ((eax & eax) == 0) goto L503d8f;  // @497_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @498_503770
  ecx = edx = 0;  // @499_503770
  goto L503d90;  // @500_503770
  L503d8f:;
  __builtin_trap();  // @502_503770
  L503d90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @504_503770
  L503d95:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @506_503770
  if (eax >= (u32)(60)) goto L503db7;  // @507_503770
  { u32 v = (u32)((u32)(5251808)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @508_503770
  eax = (eax + 1);  // @509_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @510_503770
  goto L503dd6;  // @511_503770
  L503db7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @513_503770
  ecx = esi;  // @514_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @515_503770
  ecx = edx = 0;  // @516_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @517_503770
  if ((eax & eax) == 0) goto L503dd0;  // @518_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @519_503770
  ecx = edx = 0;  // @520_503770
  goto L503dd1;  // @521_503770
  L503dd0:;
  __builtin_trap();  // @523_503770
  L503dd1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @525_503770
  L503dd6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @527_503770
  if (eax >= (u32)(60)) goto L503df8;  // @528_503770
  { u32 v = (u32)((u32)(5251808)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @529_503770
  eax = (eax + 1);  // @530_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @531_503770
  goto L503e17;  // @532_503770
  L503df8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @534_503770
  ecx = esi;  // @535_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @536_503770
  ecx = edx = 0;  // @537_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @538_503770
  if ((eax & eax) == 0) goto L503e11;  // @539_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @540_503770
  ecx = edx = 0;  // @541_503770
  goto L503e12;  // @542_503770
  L503e11:;
  __builtin_trap();  // @544_503770
  L503e12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @546_503770
  L503e17:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @548_503770
  if (eax >= (u32)(60)) goto L503e39;  // @549_503770
  { u32 v = (u32)((u32)(5252496)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @550_503770
  eax = (eax + 1);  // @551_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @552_503770
  goto L503e58;  // @553_503770
  L503e39:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @555_503770
  ecx = esi;  // @556_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @557_503770
  ecx = edx = 0;  // @558_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @559_503770
  if ((eax & eax) == 0) goto L503e52;  // @560_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @561_503770
  ecx = edx = 0;  // @562_503770
  goto L503e53;  // @563_503770
  L503e52:;
  __builtin_trap();  // @565_503770
  L503e53:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @567_503770
  L503e58:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @569_503770
  if (eax >= (u32)(60)) goto L503e7a;  // @570_503770
  { u32 v = (u32)((u32)(5252496)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @571_503770
  eax = (eax + 1);  // @572_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @573_503770
  goto L503e99;  // @574_503770
  L503e7a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @576_503770
  ecx = esi;  // @577_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @578_503770
  ecx = edx = 0;  // @579_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @580_503770
  if ((eax & eax) == 0) goto L503e93;  // @581_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @582_503770
  ecx = edx = 0;  // @583_503770
  goto L503e94;  // @584_503770
  L503e93:;
  __builtin_trap();  // @586_503770
  L503e94:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @588_503770
  L503e99:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @590_503770
  if (eax >= (u32)(60)) goto L503ebb;  // @591_503770
  { u32 v = (u32)((u32)(5252496)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @592_503770
  eax = (eax + 1);  // @593_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @594_503770
  goto L503eda;  // @595_503770
  L503ebb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @597_503770
  ecx = esi;  // @598_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @599_503770
  ecx = edx = 0;  // @600_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @601_503770
  if ((eax & eax) == 0) goto L503ed4;  // @602_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @603_503770
  ecx = edx = 0;  // @604_503770
  goto L503ed5;  // @605_503770
  L503ed4:;
  __builtin_trap();  // @607_503770
  L503ed5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @609_503770
  L503eda:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @611_503770
  if (eax >= (u32)(60)) goto L503efc;  // @612_503770
  { u32 v = (u32)((u32)(5252016)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @613_503770
  eax = (eax + 1);  // @614_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @615_503770
  goto L503f1b;  // @616_503770
  L503efc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @618_503770
  ecx = esi;  // @619_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @620_503770
  ecx = edx = 0;  // @621_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @622_503770
  if ((eax & eax) == 0) goto L503f15;  // @623_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @624_503770
  ecx = edx = 0;  // @625_503770
  goto L503f16;  // @626_503770
  L503f15:;
  __builtin_trap();  // @628_503770
  L503f16:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @630_503770
  L503f1b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @632_503770
  if (eax >= (u32)(60)) goto L503f3d;  // @633_503770
  { u32 v = (u32)((u32)(5252240)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @634_503770
  eax = (eax + 1);  // @635_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @636_503770
  goto L503f5c;  // @637_503770
  L503f3d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @639_503770
  ecx = esi;  // @640_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @641_503770
  ecx = edx = 0;  // @642_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @643_503770
  if ((eax & eax) == 0) goto L503f56;  // @644_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @645_503770
  ecx = edx = 0;  // @646_503770
  goto L503f57;  // @647_503770
  L503f56:;
  __builtin_trap();  // @649_503770
  L503f57:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @651_503770
  L503f5c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @653_503770
  if (eax >= (u32)(60)) goto L503f7e;  // @654_503770
  { u32 v = (u32)((u32)(5251328)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @655_503770
  eax = (eax + 1);  // @656_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @657_503770
  goto L503f9d;  // @658_503770
  L503f7e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @660_503770
  ecx = esi;  // @661_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @662_503770
  ecx = edx = 0;  // @663_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @664_503770
  if ((eax & eax) == 0) goto L503f97;  // @665_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @666_503770
  ecx = edx = 0;  // @667_503770
  goto L503f98;  // @668_503770
  L503f97:;
  __builtin_trap();  // @670_503770
  L503f98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @672_503770
  L503f9d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @674_503770
  if (eax >= (u32)(60)) goto L503fbf;  // @675_503770
  { u32 v = (u32)((u32)(5251536)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @676_503770
  eax = (eax + 1);  // @677_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @678_503770
  goto L503fde;  // @679_503770
  L503fbf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @681_503770
  ecx = esi;  // @682_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @683_503770
  ecx = edx = 0;  // @684_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @685_503770
  if ((eax & eax) == 0) goto L503fd8;  // @686_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @687_503770
  ecx = edx = 0;  // @688_503770
  goto L503fd9;  // @689_503770
  L503fd8:;
  __builtin_trap();  // @691_503770
  L503fd9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @693_503770
  L503fde:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @695_503770
  if (eax >= (u32)(60)) goto L504000;  // @696_503770
  { u32 v = (u32)((u32)(5253344)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @697_503770
  eax = (eax + 1);  // @698_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @699_503770
  goto L50401f;  // @700_503770
  L504000:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @702_503770
  ecx = esi;  // @703_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @704_503770
  ecx = edx = 0;  // @705_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @706_503770
  if ((eax & eax) == 0) goto L504019;  // @707_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @708_503770
  ecx = edx = 0;  // @709_503770
  goto L50401a;  // @710_503770
  L504019:;
  __builtin_trap();  // @712_503770
  L50401a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @714_503770
  L50401f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @716_503770
  if (eax >= (u32)(60)) goto L504041;  // @717_503770
  { u32 v = (u32)((u32)(5253040)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @718_503770
  eax = (eax + 1);  // @719_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @720_503770
  goto L504060;  // @721_503770
  L504041:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @723_503770
  ecx = esi;  // @724_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @725_503770
  ecx = edx = 0;  // @726_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @727_503770
  if ((eax & eax) == 0) goto L50405a;  // @728_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @729_503770
  ecx = edx = 0;  // @730_503770
  goto L50405b;  // @731_503770
  L50405a:;
  __builtin_trap();  // @733_503770
  L50405b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @735_503770
  L504060:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @737_503770
  if (eax >= (u32)(60)) goto L504082;  // @738_503770
  { u32 v = (u32)((u32)(5252720)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @739_503770
  eax = (eax + 1);  // @740_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @741_503770
  goto L5040a1;  // @742_503770
  L504082:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @744_503770
  ecx = esi;  // @745_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @746_503770
  ecx = edx = 0;  // @747_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @748_503770
  if ((eax & eax) == 0) goto L50409b;  // @749_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @750_503770
  ecx = edx = 0;  // @751_503770
  goto L50409c;  // @752_503770
  L50409b:;
  __builtin_trap();  // @754_503770
  L50409c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @756_503770
  L5040a1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @758_503770
  if (eax >= (u32)(60)) goto L5040c3;  // @759_503770
  { u32 v = (u32)((u32)(5251120)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @760_503770
  eax = (eax + 1);  // @761_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @762_503770
  goto L5040e2;  // @763_503770
  L5040c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @765_503770
  ecx = esi;  // @766_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @767_503770
  ecx = edx = 0;  // @768_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @769_503770
  if ((eax & eax) == 0) goto L5040dc;  // @770_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @771_503770
  ecx = edx = 0;  // @772_503770
  goto L5040dd;  // @773_503770
  L5040dc:;
  __builtin_trap();  // @775_503770
  L5040dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @777_503770
  L5040e2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @779_503770
  if (eax >= (u32)(60)) goto L504104;  // @780_503770
  { u32 v = (u32)((u32)(5253632)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @781_503770
  eax = (eax + 1);  // @782_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @783_503770
  goto L504123;  // @784_503770
  L504104:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @786_503770
  ecx = esi;  // @787_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @788_503770
  ecx = edx = 0;  // @789_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @790_503770
  if ((eax & eax) == 0) goto L50411d;  // @791_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @792_503770
  ecx = edx = 0;  // @793_503770
  goto L50411e;  // @794_503770
  L50411d:;
  __builtin_trap();  // @796_503770
  L50411e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @798_503770
  L504123:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @800_503770
  if (eax >= (u32)(60)) goto L504145;  // @801_503770
  { u32 v = (u32)((u32)(5254704)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @802_503770
  eax = (eax + 1);  // @803_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @804_503770
  goto L504164;  // @805_503770
  L504145:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @807_503770
  ecx = esi;  // @808_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @809_503770
  ecx = edx = 0;  // @810_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @811_503770
  if ((eax & eax) == 0) goto L50415e;  // @812_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @813_503770
  ecx = edx = 0;  // @814_503770
  goto L50415f;  // @815_503770
  L50415e:;
  __builtin_trap();  // @817_503770
  L50415f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @819_503770
  L504164:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @821_503770
  if (eax >= (u32)(60)) goto L504186;  // @822_503770
  { u32 v = (u32)((u32)(5254704)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @823_503770
  eax = (eax + 1);  // @824_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @825_503770
  goto L5041a5;  // @826_503770
  L504186:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @828_503770
  ecx = esi;  // @829_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @830_503770
  ecx = edx = 0;  // @831_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @832_503770
  if ((eax & eax) == 0) goto L50419f;  // @833_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @834_503770
  ecx = edx = 0;  // @835_503770
  goto L5041a0;  // @836_503770
  L50419f:;
  __builtin_trap();  // @838_503770
  L5041a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @840_503770
  L5041a5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @842_503770
  if (eax >= (u32)(60)) goto L5041c7;  // @843_503770
  { u32 v = (u32)((u32)(5256272)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @844_503770
  eax = (eax + 1);  // @845_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @846_503770
  goto L5041e6;  // @847_503770
  L5041c7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @849_503770
  ecx = esi;  // @850_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @851_503770
  ecx = edx = 0;  // @852_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @853_503770
  if ((eax & eax) == 0) goto L5041e0;  // @854_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @855_503770
  ecx = edx = 0;  // @856_503770
  goto L5041e1;  // @857_503770
  L5041e0:;
  __builtin_trap();  // @859_503770
  L5041e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @861_503770
  L5041e6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @863_503770
  if (eax >= (u32)(60)) goto L504208;  // @864_503770
  { u32 v = (u32)((u32)(5254912)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @865_503770
  eax = (eax + 1);  // @866_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @867_503770
  goto L504227;  // @868_503770
  L504208:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @870_503770
  ecx = esi;  // @871_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @872_503770
  ecx = edx = 0;  // @873_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @874_503770
  if ((eax & eax) == 0) goto L504221;  // @875_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @876_503770
  ecx = edx = 0;  // @877_503770
  goto L504222;  // @878_503770
  L504221:;
  __builtin_trap();  // @880_503770
  L504222:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @882_503770
  L504227:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @884_503770
  if (eax >= (u32)(60)) goto L504249;  // @885_503770
  { u32 v = (u32)((u32)(5254912)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @886_503770
  eax = (eax + 1);  // @887_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @888_503770
  goto L504268;  // @889_503770
  L504249:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @891_503770
  ecx = esi;  // @892_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @893_503770
  ecx = edx = 0;  // @894_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @895_503770
  if ((eax & eax) == 0) goto L504262;  // @896_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @897_503770
  ecx = edx = 0;  // @898_503770
  goto L504263;  // @899_503770
  L504262:;
  __builtin_trap();  // @901_503770
  L504263:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @903_503770
  L504268:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @905_503770
  if (eax >= (u32)(60)) goto L50428a;  // @906_503770
  { u32 v = (u32)((u32)(5254912)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @907_503770
  eax = (eax + 1);  // @908_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @909_503770
  goto L5042a9;  // @910_503770
  L50428a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @912_503770
  ecx = esi;  // @913_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @914_503770
  ecx = edx = 0;  // @915_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @916_503770
  if ((eax & eax) == 0) goto L5042a3;  // @917_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @918_503770
  ecx = edx = 0;  // @919_503770
  goto L5042a4;  // @920_503770
  L5042a3:;
  __builtin_trap();  // @922_503770
  L5042a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @924_503770
  L5042a9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @926_503770
  if (eax >= (u32)(60)) goto L5042cb;  // @927_503770
  { u32 v = (u32)((u32)(5255136)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @928_503770
  eax = (eax + 1);  // @929_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @930_503770
  goto L5042ea;  // @931_503770
  L5042cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @933_503770
  ecx = esi;  // @934_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @935_503770
  ecx = edx = 0;  // @936_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @937_503770
  if ((eax & eax) == 0) goto L5042e4;  // @938_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @939_503770
  ecx = edx = 0;  // @940_503770
  goto L5042e5;  // @941_503770
  L5042e4:;
  __builtin_trap();  // @943_503770
  L5042e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @945_503770
  L5042ea:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @947_503770
  if (eax >= (u32)(60)) goto L50430c;  // @948_503770
  { u32 v = (u32)((u32)(5255408)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @949_503770
  eax = (eax + 1);  // @950_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @951_503770
  goto L50432b;  // @952_503770
  L50430c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @954_503770
  ecx = esi;  // @955_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @956_503770
  ecx = edx = 0;  // @957_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @958_503770
  if ((eax & eax) == 0) goto L504325;  // @959_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @960_503770
  ecx = edx = 0;  // @961_503770
  goto L504326;  // @962_503770
  L504325:;
  __builtin_trap();  // @964_503770
  L504326:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @966_503770
  L50432b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @968_503770
  if (eax >= (u32)(60)) goto L50434d;  // @969_503770
  { u32 v = (u32)((u32)(5255680)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @970_503770
  eax = (eax + 1);  // @971_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @972_503770
  goto L50436c;  // @973_503770
  L50434d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @975_503770
  ecx = esi;  // @976_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @977_503770
  ecx = edx = 0;  // @978_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @979_503770
  if ((eax & eax) == 0) goto L504366;  // @980_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @981_503770
  ecx = edx = 0;  // @982_503770
  goto L504367;  // @983_503770
  L504366:;
  __builtin_trap();  // @985_503770
  L504367:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @987_503770
  L50436c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @989_503770
  if (eax >= (u32)(60)) goto L50438e;  // @990_503770
  { u32 v = (u32)((u32)(5255984)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @991_503770
  eax = (eax + 1);  // @992_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @993_503770
  goto L5043ad;  // @994_503770
  L50438e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @996_503770
  ecx = esi;  // @997_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @998_503770
  ecx = edx = 0;  // @999_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1000_503770
  if ((eax & eax) == 0) goto L5043a7;  // @1001_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1002_503770
  ecx = edx = 0;  // @1003_503770
  goto L5043a8;  // @1004_503770
  L5043a7:;
  __builtin_trap();  // @1006_503770
  L5043a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @1008_503770
  L5043ad:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @1010_503770
  if (eax >= (u32)(60)) goto L5043cf;  // @1011_503770
  { u32 v = (u32)((u32)(5254048)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @1012_503770
  eax = (eax + 1);  // @1013_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @1014_503770
  goto L5043ee;  // @1015_503770
  L5043cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1017_503770
  ecx = esi;  // @1018_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1019_503770
  ecx = edx = 0;  // @1020_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1021_503770
  if ((eax & eax) == 0) goto L5043e8;  // @1022_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1023_503770
  ecx = edx = 0;  // @1024_503770
  goto L5043e9;  // @1025_503770
  L5043e8:;
  __builtin_trap();  // @1027_503770
  L5043e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @1029_503770
  L5043ee:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @1031_503770
  if (eax >= (u32)(60)) goto L504410;  // @1032_503770
  { u32 v = (u32)((u32)(5254336)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @1033_503770
  eax = (eax + 1);  // @1034_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @1035_503770
  goto L50442f;  // @1036_503770
  L504410:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1038_503770
  ecx = esi;  // @1039_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1040_503770
  ecx = edx = 0;  // @1041_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1042_503770
  if ((eax & eax) == 0) goto L504429;  // @1043_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1044_503770
  ecx = edx = 0;  // @1045_503770
  goto L50442a;  // @1046_503770
  L504429:;
  __builtin_trap();  // @1048_503770
  L50442a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @1050_503770
  L50442f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @1052_503770
  if (eax >= (u32)(60)) goto L50444d;  // @1053_503770
  { u32 v = (u32)((u32)(5253840)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @1054_503770
  eax = (eax + 1);  // @1055_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @1056_503770
  goto L50446c;  // @1057_503770
  L50444d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1059_503770
  ecx = esi;  // @1060_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1061_503770
  ecx = edx = 0;  // @1062_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1063_503770
  if ((eax & eax) == 0) goto L504466;  // @1064_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1065_503770
  ecx = edx = 0;  // @1066_503770
  goto L504467;  // @1067_503770
  L504466:;
  __builtin_trap();  // @1069_503770
  L504467:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @1071_503770
  L50446c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @1073_503770
  if (eax >= (u32)(60)) goto L50448e;  // @1074_503770
  { u32 v = (u32)((u32)(5246688)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @1075_503770
  eax = (eax + 1);  // @1076_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @1077_503770
  return eax;  // @1078_503770
  L50448e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1080_503770
  ecx = esi;  // @1081_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1082_503770
  ecx = edx = 0;  // @1083_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1084_503770
  if ((eax & eax) == 0) goto L5044ab;  // @1085_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1086_503770
  ecx = edx = 0;  // @1087_503770
  return eax;  // @1088_503770
  L5044ab:;
  __builtin_trap();  // @1090_503770
  L5044ac:;
  return eax;  // @1092_503770
}
PCREG(503770, lifted_503770);

