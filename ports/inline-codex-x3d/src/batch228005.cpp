// batch228005.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_475820_stdcall2(u32, u32) __asm__("ext_475820");
extern "C" u32 THISCALL ext_476f50_thiscall4(u32, u32, u32, u32) __asm__("ext_476f50");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_5eade0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5eade0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_59d580(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66bcde);  // @h_59d580
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_59d580
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_59d580
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_59d580
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_59d580
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_59d580
  eax = ext_476f50_thiscall4(ecx, PV[2], PV[1], PV[0]);  // @5_59d580
  ecx = edx = 0;  // @6_59d580
  reg.state = (s32)((u32)(0));  // @7_59d580
  edi = (u32)(esi + 2002);  // @8_59d580
  { u32 v = (u32)((u32)(7004016)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_59d580
  ebx = (u32)(16);  // @10_59d580
  L59d5d1:;
  ecx = edi;  // @12_59d580
  eax = ext_5eade0_thiscall6(ecx, (u32)(0), (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @13_59d580
  ecx = edx = 0;  // @14_59d580
  edi = (edi + (u32)(16));  // @15_59d580
  ebx = (ebx - (u32)(1));  // @16_59d580
  if (ebx != 0) goto L59d5d1;  // @17_59d580
  PV[3] = (u32)(ebx);  // @18_59d580
  PV[4] = (u32)(ebx);  // @19_59d580
  PV[5] = (u32)(ebx);  // @20_59d580
  PV[6] = (u32)(ebx);  // @21_59d580
  PV[7] = (u32)(ebx);  // @22_59d580
  ecx = (u32)(esi + 2258);  // @23_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1998), &v, sizeof v); }  // @24_59d580
  eax = ext_5eade0_thiscall6(ecx, PV[7], PV[6], PV[5], PV[4], PV[3]);  // @25_59d580
  ecx = edx = 0;  // @26_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_59d580
  PV[8] = (u32)(ebx);  // @28_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_59d580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968132), PV[8], (u32)(7005856), (u32)(77));  // @31_59d580
  ecx = edx = 0;  // @32_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1919), &v, sizeof v); }  // @33_59d580
  eax = (u32)(35);  // @34_59d580
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 1923), &v, sizeof v); }  // @35_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1924), &v, sizeof v); }  // @36_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1938), &v, sizeof v); }  // @37_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1942), &v, sizeof v); }  // @38_59d580
  { u32 v = (u32)((u32)(6553700)); __builtin_memcpy((void *)(u32)(esi + 1952), &v, sizeof v); }  // @39_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1930), &v, sizeof v); }  // @40_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1934), &v, sizeof v); }  // @41_59d580
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 1956), &v, sizeof v); }  // @42_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 1958), &v, sizeof v); }  // @43_59d580
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 2294), &v, sizeof v); }  // @44_59d580
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 2298), &v, sizeof v); }  // @45_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 2323), &v, sizeof v); }  // @46_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 2319), &v, sizeof v); }  // @47_59d580
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2327), &v, sizeof v); }  // @48_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 2299), &v, sizeof v); }  // @49_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 2303), &v, sizeof v); }  // @50_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 2307), &v, sizeof v); }  // @51_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 2311), &v, sizeof v); }  // @52_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 2315), &v, sizeof v); }  // @53_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_59d580
  PV[9] = (u32)(ebx);  // @55_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @56_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_59d580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6851624), PV[9], (u32)(7005856), (u32)(105));  // @58_59d580
  ecx = edx = 0;  // @59_59d580
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422672), &v, sizeof v); }  // @60_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_59d580
  PV[10] = (u32)(ebx);  // @62_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_59d580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6941356), PV[10], (u32)(7005856), (u32)(106));  // @65_59d580
  ecx = edx = 0;  // @66_59d580
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422676), &v, sizeof v); }  // @67_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_59d580
  PV[11] = (u32)(ebx);  // @69_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @70_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_59d580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892260), PV[11], (u32)(7005856), (u32)(107));  // @72_59d580
  ecx = edx = 0;  // @73_59d580
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422680), &v, sizeof v); }  // @74_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_59d580
  PV[12] = (u32)(ebx);  // @76_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @77_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_59d580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7005904), PV[12], (u32)(7005856), (u32)(108));  // @79_59d580
  ecx = edx = 0;  // @80_59d580
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422684), &v, sizeof v); }  // @81_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_59d580
  PV[13] = (u32)(ebx);  // @83_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @84_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_59d580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892276), PV[13], (u32)(7005856), (u32)(109));  // @86_59d580
  ecx = edx = 0;  // @87_59d580
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422688), &v, sizeof v); }  // @88_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_59d580
  PV[14] = (u32)(ebx);  // @90_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @91_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_59d580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6882880), PV[14], (u32)(7005856), (u32)(110));  // @93_59d580
  ecx = edx = 0;  // @94_59d580
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422692), &v, sizeof v); }  // @95_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_59d580
  PV[15] = (u32)(ebx);  // @97_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @98_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_59d580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6882896), PV[15], (u32)(7005856), (u32)(111));  // @100_59d580
  ecx = edx = 0;  // @101_59d580
  PV[16] = (u32)(ecx);  // @102_59d580
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422696), &v, sizeof v); }  // @103_59d580
  ecx = esi;  // @104_59d580
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 1951), &v, sizeof v); }  // @105_59d580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 2332), &v, sizeof v); }  // @106_59d580
  eax = ext_475820_stdcall2((u32)(1), (u32)((u32)(1065353216)));  // @107_59d580
  ecx = edx = 0;  // @108_59d580
  PV[17] = (u32)(ecx);  // @109_59d580
  ecx = esi;  // @110_59d580
  eax = ext_475820_stdcall2((u32)(2), (u32)((u32)(1084227584)));  // @111_59d580
  ecx = edx = 0;  // @112_59d580
  PV[18] = (u32)(ecx);  // @113_59d580
  ecx = esi;  // @114_59d580
  eax = ext_475820_stdcall2((u32)(3), (u32)((u32)(1084227584)));  // @115_59d580
  ecx = edx = 0;  // @116_59d580
  eax = ext_41e290_cdecl1((u32)(264));  // @117_59d580
  ecx = edx = 0;  // @118_59d580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @119_59d580
  reg.state = (s32)((u32)(1));  // @120_59d580
  if ((eax & eax) == 0) goto L59d824;  // @121_59d580
  ecx = (u32)(esi + 2381);  // @122_59d580
  PV[19] = (u32)(ecx);  // @123_59d580
  ecx = eax;  // @124_59d580
  eax = ext_4d8330_thiscall4(ecx, (u32)(7005952), (u32)(7005924), PV[19]);  // @125_59d580
  ecx = edx = 0;  // @126_59d580
  edx = eax;  // @127_59d580
  goto L59d826;  // @128_59d580
  L59d824:;
  edx = 0;  // @130_59d580
  L59d826:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 2282), &v, sizeof v); }  // @132_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @133_59d580
  PV[20] = (u32)(edx);  // @134_59d580
  reg.state = (s32)((u32)(0));  // @135_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_59d580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[20]);  // @137_59d580
  ecx = edx = 0;  // @138_59d580
  eax = ext_41e290_cdecl1((u32)(264));  // @139_59d580
  ecx = edx = 0;  // @140_59d580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @141_59d580
  reg.state = (s32)((u32)(2));  // @142_59d580
  if ((eax & eax) == 0) goto L59d871;  // @143_59d580
  ecx = eax;  // @144_59d580
  eax = ext_4d8330_thiscall4(ecx, (u32)(7005996), (u32)(7005964), (u32)(7422700));  // @145_59d580
  ecx = edx = 0;  // @146_59d580
  edx = eax;  // @147_59d580
  goto L59d873;  // @148_59d580
  L59d871:;
  edx = 0;  // @150_59d580
  L59d873:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 2274), &v, sizeof v); }  // @152_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @153_59d580
  PV[21] = (u32)(edx);  // @154_59d580
  reg.state = (s32)((u32)(0));  // @155_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @156_59d580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[21]);  // @157_59d580
  ecx = edx = 0;  // @158_59d580
  eax = ext_41e290_cdecl1((u32)(264));  // @159_59d580
  ecx = edx = 0;  // @160_59d580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @161_59d580
  reg.state = (s32)((u32)(3));  // @162_59d580
  if ((eax & eax) == 0) goto L59d8be;  // @163_59d580
  ecx = eax;  // @164_59d580
  eax = ext_4d8330_thiscall4(ecx, (u32)(7006052), (u32)(7006008), (u32)(7422704));  // @165_59d580
  ecx = edx = 0;  // @166_59d580
  edx = eax;  // @167_59d580
  goto L59d8c0;  // @168_59d580
  L59d8be:;
  edx = 0;  // @170_59d580
  L59d8c0:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 2278), &v, sizeof v); }  // @172_59d580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @173_59d580
  PV[22] = (u32)(edx);  // @174_59d580
  reg.state = (s32)((u32)(0));  // @175_59d580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @176_59d580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[22]);  // @177_59d580
  ecx = edx = 0;  // @178_59d580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2381), &v, sizeof v); }  // @179_59d580
  eax = esi;  // @180_59d580
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2336), &v, sizeof v); }  // @181_59d580
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2345), &v, sizeof v); }  // @182_59d580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2337), &v, sizeof v); }  // @183_59d580
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 2341), &v, sizeof v); }  // @184_59d580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2346), &v, sizeof v); }  // @185_59d580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2350), &v, sizeof v); }  // @186_59d580
  SEH_LEAVE();  // @187_59d580
  return eax;  // @188_59d580
}
PCREG(59d580, lifted_59d580);

