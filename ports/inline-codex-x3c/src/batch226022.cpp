// batch226022.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_5eaaf0_thiscall1(u32) __asm__("ext_5eaaf0");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_598a50(u32 ecx_in) {
  SEH_ENTER(0x66bb8c);  // @h_598a50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_598a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8919), sizeof v); (u32)v; });  // @1_598a50
  { u32 v = (u32)((u32)(7001516)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_598a50
  if ((edi & edi) == 0) goto L598a9a;  // @3_598a50
  ecx = edi;  // @4_598a50
  eax = ext_5eaaf0_thiscall1(ecx);  // @5_598a50
  ecx = edx = 0;  // @6_598a50
  PS[1] = edi;  // @7_598a50
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(76));  // @8_598a50
  ecx = edx = 0;  // @9_598a50
  L598a9a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 117), sizeof v); (u32)v; }));  // @13_598a50
  ecx = edx = 0;  // @14_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 117), sizeof v); (u32)v; });  // @15_598a50
  if ((ecx & ecx) == 0) goto L598ab8;  // @16_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @18_598a50
  ecx = edx = 0;  // @19_598a50
  L598ab8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }));  // @23_598a50
  ecx = edx = 0;  // @24_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @25_598a50
  if ((ecx & ecx) == 0) goto L598ad6;  // @26_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @28_598a50
  ecx = edx = 0;  // @29_598a50
  L598ad6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }));  // @33_598a50
  ecx = edx = 0;  // @34_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @35_598a50
  if ((ecx & ecx) == 0) goto L598af4;  // @36_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @38_598a50
  ecx = edx = 0;  // @39_598a50
  L598af4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }));  // @43_598a50
  ecx = edx = 0;  // @44_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @45_598a50
  if ((ecx & ecx) == 0) goto L598b12;  // @46_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @48_598a50
  ecx = edx = 0;  // @49_598a50
  L598b12:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; }));  // @53_598a50
  ecx = edx = 0;  // @54_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; });  // @55_598a50
  if ((ecx & ecx) == 0) goto L598b30;  // @56_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @58_598a50
  ecx = edx = 0;  // @59_598a50
  L598b30:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 121), sizeof v); (u32)v; }));  // @63_598a50
  ecx = edx = 0;  // @64_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 121), sizeof v); (u32)v; });  // @65_598a50
  if ((ecx & ecx) == 0) goto L598b4e;  // @66_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @68_598a50
  ecx = edx = 0;  // @69_598a50
  L598b4e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 125), sizeof v); (u32)v; }));  // @73_598a50
  ecx = edx = 0;  // @74_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 125), sizeof v); (u32)v; });  // @75_598a50
  if ((ecx & ecx) == 0) goto L598b6c;  // @76_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @78_598a50
  ecx = edx = 0;  // @79_598a50
  L598b6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 129), sizeof v); (u32)v; }));  // @83_598a50
  ecx = edx = 0;  // @84_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 129), sizeof v); (u32)v; });  // @85_598a50
  if ((ecx & ecx) == 0) goto L598b90;  // @86_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @88_598a50
  ecx = edx = 0;  // @89_598a50
  L598b90:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7586), sizeof v); (u32)v; });  // @91_598a50
  ebx = (u32)(esi + 7586);  // @92_598a50
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; })) goto L598c3e;  // @93_598a50
  L598ba8:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @95_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @96_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @97_598a50
  if ((eax & eax) == 0) goto L598bc8;  // @98_598a50
  ecx = eax;  // @99_598a50
  eax = ext_4690b0_cdecl0();  // @100_598a50
  ecx = edx = 0;  // @101_598a50
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }), (u32)(16));  // @102_598a50
  ecx = edx = 0;  // @103_598a50
  L598bc8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @105_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @106_598a50
  if ((eax & eax) == 0) goto L598be6;  // @107_598a50
  ecx = eax;  // @108_598a50
  eax = ext_4690b0_cdecl0();  // @109_598a50
  ecx = edx = 0;  // @110_598a50
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }), (u32)(41));  // @111_598a50
  ecx = edx = 0;  // @112_598a50
  L598be6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @114_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @115_598a50
  if ((eax & eax) == 0) goto L598c04;  // @116_598a50
  ecx = eax;  // @117_598a50
  eax = ext_4690b0_cdecl0();  // @118_598a50
  ecx = edx = 0;  // @119_598a50
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }), (u32)(41));  // @120_598a50
  ecx = edx = 0;  // @121_598a50
  L598c04:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @123_598a50
  if ((ebx & ebx) == 0) goto L598c1d;  // @124_598a50
  ecx = ebx;  // @125_598a50
  eax = ext_4690b0_cdecl0();  // @126_598a50
  ecx = edx = 0;  // @127_598a50
  PS[1] = ebx;  // @128_598a50
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(41));  // @129_598a50
  ecx = edx = 0;  // @130_598a50
  L598c1d:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }), (u32)(28));  // @132_598a50
  ecx = edx = 0;  // @133_598a50
  edi = (edi + (u32)(4));  // @134_598a50
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; })) goto L598ba8;  // @135_598a50
  ebx = (u32)(esi + 7586);  // @136_598a50
  L598c3e:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @138_598a50
  edx = edi;  // @139_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @140_598a50
  edx = (edx - edi);  // @141_598a50
  edx = (u32)((s32)edx >> (u32)(2));  // @142_598a50
  ecx = eax;  // @143_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @144_598a50
  if ((s32)(edx & edx) <= 0) goto L598c6e;  // @145_598a50
  ebx = edi;  // @146_598a50
  ebx = (ebx - eax);  // @147_598a50
  L598c57:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx), sizeof v); (u32)v; });  // @149_598a50
  ecx = (u32)(ecx + 4);  // @150_598a50
  edx = (edx - 1);  // @151_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @152_598a50
  if ((s32)(edx & edx) > 0) goto L598c57;  // @153_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @154_598a50
  ebx = (u32)(esi + 7586);  // @155_598a50
  L598c6e:;
  edi = (edi - eax);  // @157_598a50
  edi = (u32)((s32)edi >> (u32)(2));  // @158_598a50
  CF = (edi != 0); edi = (u32)(0 - edi);  // @159_598a50
  edi = (edi << (u32)(2));  // @160_598a50
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + edi)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @161_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @162_598a50
  if ((ecx & ecx) == 0) goto L598c88;  // @163_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @165_598a50
  ecx = edx = 0;  // @166_598a50
  L598c88:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @168_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @169_598a50
  eax = (eax - ecx);  // @170_598a50
  eax = (u32)((s32)eax >> (u32)(2));  // @171_598a50
  reg.state = (s32)((u32)(0));  // @172_598a50
  if ((eax & eax) == 0) goto L598ca9;  // @173_598a50
  eax = (eax << (u32)(2));  // @174_598a50
  PS[0] = eax;  // @175_598a50
  PS[1] = ecx;  // @176_598a50
  ecx = ebx;  // @177_598a50
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @178_598a50
  ecx = edx = 0;  // @179_598a50
  L598ca9:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @181_598a50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @182_598a50
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @183_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @184_598a50
  PS[0] = esi;  // @185_598a50
  reg.state = (s32)((u32)(1));  // @186_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @187_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @188_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(PS[0]));  // @189_598a50
  ecx = edx = 0;  // @190_598a50
  SEH_LEAVE();  // @191_598a50
  return eax;  // @192_598a50
}
PCREG(598a50, lifted_598a50);

