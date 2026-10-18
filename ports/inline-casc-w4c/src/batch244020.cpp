// batch244020.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_54f2b0_fastcall2(u32, u32) __asm__("ext_54f2b0");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_549280_thiscall2(u32, u32) __asm__("ext_549280");
extern "C" u32 THISCALL ext_54e9d0_thiscall1(u32) __asm__("ext_54e9d0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e290_cdecl2(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_63364e_cdecl4(...) __asm__("ext_63364e");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_421080(u32 ecx_in) {
  SEH_ENTER(0x664256);  // @h_421080
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_421080
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @1_421080
  eax = (u32)(EBP - 276);  // @2_421080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @3_421080
  PV[0] = (u32)(eax);  // @4_421080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @5_421080
  eax = ext_63364e_cdecl4((u32)(7083500), (u32)(0), (u32)(0), PV[0]);  // @6_421080
    // @7_421080
  FL[2] = (eax & eax);  // @8_421080
  if (FL[2] == 0) goto L421123;  // @9_421080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_421080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_421080
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6782900), (u32)(3185));  // @12_421080
  ecx = edx = 0;  // @13_421080
  L4210fd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_421080
  PV[1] = (u32)(eax);  // @16_421080
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6784320));  // @17_421080
  ecx = edx = 0;  // @18_421080
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @19_421080
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676494))(PV[2]);  // @20_421080
  ecx = edx = 0;  // @21_421080
  ecx = ebx;  // @22_421080
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @23_421080
  ecx = edx = 0;  // @24_421080
  goto L421219;  // @25_421080
  L421123:;
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @27_421080
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6760dc))(PV[3], (u32)(0), (u32)(0));  // @28_421080
  ecx = edx = 0;  // @29_421080
  esi = eax;  // @30_421080
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @31_421080
  FL[2] = (esi & esi);  // @32_421080
  if (FL[2] != 0) goto L42115b;  // @33_421080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @34_421080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_421080
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6782900), (u32)(3196));  // @36_421080
  ecx = edx = 0;  // @37_421080
  goto L4210fd;  // @38_421080
  L42115b:;
  ecx = 0;  // @40_421080
  FL[3] = ecx;  // @41_421080
  edx = (u32)(2);  // @42_421080
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @43_421080
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @44_421080
  FL[1] = ecx;  // @45_421080
  ecx = (0u - ecx);  // @46_421080
  ecx = (ecx | eax);  // @47_421080
  FL[3] = ecx;  // @48_421080
  PV[4] = (u32)(ecx);  // @49_421080
  eax = ext_41e290_cdecl2(PV[4], (u32)(6784368));  // @50_421080
  ecx = edx = 0;  // @51_421080
  edi = eax;  // @52_421080
  PV[5] = (u32)(esi);  // @53_421080
  PV[6] = (u32)(edi);  // @54_421080
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @55_421080
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6760dc))(PV[7], PV[6], PV[5]);  // @56_421080
  ecx = edx = 0;  // @57_421080
  PV[8] = (u32)(esi);  // @58_421080
  eax = ext_41e290_cdecl1(PV[8]);  // @59_421080
  ecx = edx = 0;  // @60_421080
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @61_421080
  esi = eax;  // @62_421080
  PV[10] = (u32)(edi);  // @63_421080
  PV[11] = (u32)(esi);  // @64_421080
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6762dc))(PV[11], PV[10], PV[9]);  // @65_421080
  ecx = edx = 0;  // @66_421080
  ecx = (u32)(EBP - 144);  // @67_421080
  PV[12] = (u32)(esi);  // @68_421080
  eax = ext_4cbe80_thiscall2(ecx, PV[12]);  // @69_421080
  ecx = edx = 0;  // @70_421080
  ecx = (u32)(EBP - 272);  // @71_421080
  reg.state = (s32)((u32)(0));  // @72_421080
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784428));  // @73_421080
  ecx = edx = 0;  // @74_421080
  eax = (u32)(EBP - 272);  // @75_421080
  reg.state = (s32)((u32)(1));  // @76_421080
  PV[13] = (u32)(eax);  // @77_421080
  ecx = (u32)(EBP - 144);  // @78_421080
  eax = ext_4cc2c0_thiscall2(ecx, PV[13]);  // @79_421080
  ecx = edx = 0;  // @80_421080
  ecx = (u32)(EBP - 272);  // @81_421080
  reg.state = (s32)((u32)(0));  // @82_421080
  eax = ext_4cbec0_thiscall1(ecx);  // @83_421080
  ecx = edx = 0;  // @84_421080
  PV[14] = (u32)(edi);  // @85_421080
  eax = ext_41e2c0_cdecl1(PV[14]);  // @86_421080
  ecx = edx = 0;  // @87_421080
  PV[15] = (u32)(esi);  // @88_421080
  eax = ext_41e2c0_cdecl1(PV[15]);  // @89_421080
  ecx = edx = 0;  // @90_421080
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @91_421080
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676494))(PV[16]);  // @92_421080
  ecx = edx = 0;  // @93_421080
  eax = (u32)(EBP - 144);  // @94_421080
  ecx = ebx;  // @95_421080
  PV[17] = (u32)(eax);  // @96_421080
  eax = ext_4cbe50_thiscall2(ecx, PV[17]);  // @97_421080
  ecx = edx = 0;  // @98_421080
  ecx = (u32)(EBP - 144);  // @99_421080
  eax = ext_4cbec0_thiscall1(ecx);  // @100_421080
  ecx = edx = 0;  // @101_421080
  L421219:;
  eax = ebx;  // @103_421080
  SEH_LEAVE();  // @104_421080
  ext_633654(G(u32, 0x6f5630));  // @105_421080
  return eax;  // @106_421080
}
PCREG(421080, lifted_421080);

extern "C" u32 THISCALL lifted_647fd0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66eaa5);  // @h_647fd0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_647fd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_647fd0
  edi = (u32)(65535);  // @2_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @3_647fd0
  { u8 v = (u8)((u32)(18)); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @4_647fd0
  { u16 v = (u16)((edi & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 10), &v, sizeof v); }  // @5_647fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_647fd0
  edx = 0;  // @7_647fd0
  FL[3] = edx;  // @8_647fd0
  { u32 v = (u32)((u32)(7089184)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @10_647fd0
  { u32 v = (u32)((u32)(7089088)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @11_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @12_647fd0
  eax = (u32)(ecx + 568);  // @13_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @14_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @15_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @16_647fd0
  reg.state = (s32)((u32)(0));  // @17_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65581), &v, sizeof v); }  // @18_647fd0
  { u32 v = (u32)((u32)(4294906370)); __builtin_memcpy((void *)(u32)(esi + 65585), &v, sizeof v); }  // @19_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65589), &v, sizeof v); }  // @20_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65593), &v, sizeof v); }  // @21_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65597), &v, sizeof v); }  // @22_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65601), &v, sizeof v); }  // @23_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65605), &v, sizeof v); }  // @24_647fd0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 65611), &v, sizeof v); }  // @25_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65613), &v, sizeof v); }  // @26_647fd0
  { u32 v = (u32)((u32)(7088848)); __builtin_memcpy((void *)(u32)(esi + 65653), &v, sizeof v); }  // @27_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65673), &v, sizeof v); }  // @28_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65805), &v, sizeof v); }  // @29_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65905), &v, sizeof v); }  // @30_647fd0
  { u32 v = (u32)((u32)(7089112)); __builtin_memcpy((void *)(u32)(esi + 65905), &v, sizeof v); }  // @31_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65913), &v, sizeof v); }  // @32_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65909), &v, sizeof v); }  // @33_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65917), &v, sizeof v); }  // @34_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65921), &v, sizeof v); }  // @35_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65925), &v, sizeof v); }  // @36_647fd0
  { u32 v = (u32)((u32)(7089136)); __builtin_memcpy((void *)(u32)(esi + 65925), &v, sizeof v); }  // @37_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65933), &v, sizeof v); }  // @38_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65929), &v, sizeof v); }  // @39_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65937), &v, sizeof v); }  // @40_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65941), &v, sizeof v); }  // @41_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65945), &v, sizeof v); }  // @42_647fd0
  { u32 v = (u32)((u32)(7089112)); __builtin_memcpy((void *)(u32)(esi + 65945), &v, sizeof v); }  // @43_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65953), &v, sizeof v); }  // @44_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65949), &v, sizeof v); }  // @45_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65957), &v, sizeof v); }  // @46_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65961), &v, sizeof v); }  // @47_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65965), &v, sizeof v); }  // @48_647fd0
  { u32 v = (u32)((u32)(7089160)); __builtin_memcpy((void *)(u32)(esi + 65965), &v, sizeof v); }  // @49_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65973), &v, sizeof v); }  // @50_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65969), &v, sizeof v); }  // @51_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65977), &v, sizeof v); }  // @52_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65981), &v, sizeof v); }  // @53_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65985), &v, sizeof v); }  // @54_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98905), &v, sizeof v); }  // @55_647fd0
  { u32 v = (u32)((u32)(4294906371)); __builtin_memcpy((void *)(u32)(esi + 98909), &v, sizeof v); }  // @56_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98913), &v, sizeof v); }  // @57_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98917), &v, sizeof v); }  // @58_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98921), &v, sizeof v); }  // @59_647fd0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 98925), &v, sizeof v); }  // @60_647fd0
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 98927), &v, sizeof v); }  // @61_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98929), &v, sizeof v); }  // @62_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98933), &v, sizeof v); }  // @63_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98937), &v, sizeof v); }  // @64_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98941), &v, sizeof v); }  // @65_647fd0
  { u32 v = (u32)((u32)(4294906374)); __builtin_memcpy((void *)(u32)(esi + 98945), &v, sizeof v); }  // @66_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98949), &v, sizeof v); }  // @67_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98953), &v, sizeof v); }  // @68_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98961), &v, sizeof v); }  // @69_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98969), &v, sizeof v); }  // @70_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98965), &v, sizeof v); }  // @71_647fd0
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 98957), &v, sizeof v); }  // @72_647fd0
  { u16 v = (u16)((edi & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 98959), &v, sizeof v); }  // @73_647fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @74_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65577), &v, sizeof v); }  // @75_647fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @76_647fd0
  reg.state = (s32)((u32)(3));  // @77_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 98973), &v, sizeof v); }  // @78_647fd0
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 65576), &v, sizeof v); }  // @79_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65617), &v, sizeof v); }  // @80_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65669), &v, sizeof v); }  // @81_647fd0
  eax = (u32)(1);  // @82_647fd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 65629), &v, sizeof v); }  // @83_647fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @84_647fd0
  eax = (eax << (ecx & 0xff));  // @85_647fd0
  FL[3] = eax;  // @86_647fd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 65621), &v, sizeof v); }  // @87_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65649), &v, sizeof v); }  // @88_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65625), &v, sizeof v); }  // @89_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65633), &v, sizeof v); }  // @90_647fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 65637), &v, sizeof v); }  // @91_647fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65617), sizeof v); (u32)v; });  // @92_647fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_647fd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 216)))(ecx);  // @94_647fd0
  ecx = edx = 0;  // @95_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65641), &v, sizeof v); }  // @96_647fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65617), sizeof v); (u32)v; });  // @97_647fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_647fd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @99_647fd0
  ecx = edx = 0;  // @100_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65645), &v, sizeof v); }  // @101_647fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @102_647fd0
  eax = (eax + (u32)(20));  // @103_647fd0
  FL[3] = eax;  // @104_647fd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @105_647fd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65589), &v, sizeof v); }  // @106_647fd0
  eax = esi;  // @107_647fd0
  SEH_LEAVE();  // @108_647fd0
  return eax;  // @109_647fd0
}
PCREG(647fd0, lifted_647fd0);

extern "C" u32 THISCALL lifted_54b860(u32 ecx_in) {
  SEH_ENTER(0x66ad61);  // @h_54b860
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_54b860
  eax = ext_41e290_cdecl1((u32)(25592));  // @1_54b860
  ecx = edx = 0;  // @2_54b860
  esi = eax;  // @3_54b860
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_54b860
  reg.state = (s32)((u32)(0));  // @5_54b860
  FL[2] = (esi & esi);  // @6_54b860
  if (FL[2] == 0) goto L54b8df;  // @7_54b860
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @8_54b860
  ecx = esi;  // @9_54b860
  eax = ext_549280_thiscall2(ecx, PV[0]);  // @10_54b860
  ecx = edx = 0;  // @11_54b860
  { u32 v = (u32)((u32)(6961080)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_54b860
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25580), &v, sizeof v); }  // @13_54b860
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25584), &v, sizeof v); }  // @14_54b860
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25588), &v, sizeof v); }  // @15_54b860
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25576), &v, sizeof v); }  // @16_54b860
  goto L54b8e1;  // @17_54b860
  L54b8df:;
  esi = 0;  // @19_54b860
  FL[3] = esi;  // @20_54b860
  L54b8e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 93), sizeof v); (u32)v; });  // @22_54b860
  ebx = (u32)(esi + 25580);  // @23_54b860
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @24_54b860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 57), sizeof v); (u32)v; });  // @25_54b860
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 57), &v, sizeof v); }  // @26_54b860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421460), sizeof v); (u32)v; });  // @27_54b860
  PV[1] = (u32)(ebx);  // @28_54b860
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25580), sizeof v); (u32)v; });  // @29_54b860
  reg.state = (s32)((u32)(4294967295));  // @30_54b860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_54b860
  PV[3] = (u32)(eax);  // @32_54b860
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 20)))(ecx, PV[3], PV[2], PV[1]);  // @33_54b860
  ecx = edx = 0;  // @34_54b860
  FL[2] = (eax & eax);  // @35_54b860
  if (FL[2] == 0) goto L54b939;  // @36_54b860
  edx = (u32)(6961556);  // @37_54b860
  L54b915:;
  ecx = eax;  // @39_54b860
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @40_54b860
  ecx = edx = 0;  // @41_54b860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_54b860
  ecx = esi;  // @43_54b860
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @44_54b860
  ecx = edx = 0;  // @45_54b860
  eax = 0;  // @46_54b860
  FL[3] = eax;  // @47_54b860
  SEH_LEAVE();  // @48_54b860
  return eax;  // @49_54b860
  L54b939:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @51_54b860
  PV[4] = (u32)(eax);  // @52_54b860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @53_54b860
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 60)))(ecx, PV[4], (u32)(4294957296));  // @54_54b860
  ecx = edx = 0;  // @55_54b860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 57), sizeof v); (u32)v; });  // @56_54b860
  FL[0] = eax; FL[1] = (u32)(3);  // @57_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @58_54b860
  FL[0] = eax; FL[1] = (u32)(2);  // @59_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @60_54b860
  FL[0] = eax; FL[1] = (u32)(4);  // @61_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @62_54b860
  FL[0] = eax; FL[1] = (u32)(5);  // @63_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @64_54b860
  FL[0] = eax; FL[1] = (u32)(6);  // @65_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @66_54b860
  FL[0] = eax; FL[1] = (u32)(7);  // @67_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @68_54b860
  FL[0] = eax; FL[1] = (u32)(8);  // @69_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @70_54b860
  FL[0] = eax; FL[1] = (u32)(9);  // @71_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @72_54b860
  FL[0] = eax; FL[1] = (u32)(10);  // @73_54b860
  if (FL[0] == FL[1]) goto L54b9f7;  // @74_54b860
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @75_54b860
  eax = (u32)(esi + 25584);  // @76_54b860
  PV[5] = (u32)(eax);  // @77_54b860
  PV[6] = (u32)(ecx);  // @78_54b860
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_54b860
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, PV[6], (u32)(7070112), PV[5]);  // @80_54b860
  ecx = edx = 0;  // @81_54b860
  FL[2] = (eax & eax);  // @82_54b860
  if (FL[2] == 0) goto L54b9ab;  // @83_54b860
  edx = (u32)(6961584);  // @84_54b860
  goto L54b915;  // @85_54b860
  L54b9ab:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @87_54b860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_54b860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 204), sizeof v); (u32)v; });  // @89_54b860
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @90_54b860
  ecx = edx = 0;  // @91_54b860
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @92_54b860
  if (FL[2] == 0) goto L54b9f7;  // @93_54b860
  eax = ext_41e290_cdecl1((u32)(80));  // @94_54b860
  ecx = edx = 0;  // @95_54b860
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @96_54b860
  reg.state = (s32)((u32)(1));  // @97_54b860
  FL[2] = (eax & eax);  // @98_54b860
  if (FL[2] == 0) goto L54b9df;  // @99_54b860
  ecx = eax;  // @100_54b860
  eax = ext_54e9d0_thiscall1(ecx);  // @101_54b860
  ecx = edx = 0;  // @102_54b860
  ecx = eax;  // @103_54b860
  goto L54b9e1;  // @104_54b860
  L54b9df:;
  ecx = 0;  // @106_54b860
  FL[3] = ecx;  // @107_54b860
  L54b9e1:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 25588), &v, sizeof v); }  // @109_54b860
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_54b860
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @111_54b860
  reg.state = (s32)((u32)(4294967295));  // @112_54b860
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[7], (u32)(1));  // @113_54b860
  ecx = edx = 0;  // @114_54b860
  L54b9f7:;
  eax = esi;  // @116_54b860
  SEH_LEAVE();  // @117_54b860
  return eax;  // @118_54b860
}
PCREG(54b860, lifted_54b860);

extern "C" u32 THISCALL lifted_54b6a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66ad21);  // @h_54b6a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_54b6a0
  eax = ext_41e290_cdecl1((u32)(25592));  // @1_54b6a0
  ecx = edx = 0;  // @2_54b6a0
  esi = eax;  // @3_54b6a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_54b6a0
  reg.state = (s32)((u32)(0));  // @5_54b6a0
  FL[2] = (esi & esi);  // @6_54b6a0
  if (FL[2] == 0) goto L54b71d;  // @7_54b6a0
  PV[0] = (u32)(edi);  // @8_54b6a0
  ecx = esi;  // @9_54b6a0
  eax = ext_549280_thiscall2(ecx, PV[0]);  // @10_54b6a0
  ecx = edx = 0;  // @11_54b6a0
  { u32 v = (u32)((u32)(6961080)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_54b6a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25580), &v, sizeof v); }  // @13_54b6a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25584), &v, sizeof v); }  // @14_54b6a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25588), &v, sizeof v); }  // @15_54b6a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25576), &v, sizeof v); }  // @16_54b6a0
  goto L54b71f;  // @17_54b6a0
  L54b71d:;
  esi = 0;  // @19_54b6a0
  FL[3] = esi;  // @20_54b6a0
  L54b71f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_54b6a0
  ebx = (u32)(esi + 25580);  // @23_54b6a0
  PV[1] = (u32)(ebx);  // @24_54b6a0
  reg.state = (s32)((u32)(4294967295));  // @25_54b6a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 93), sizeof v); (u32)v; });  // @26_54b6a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @27_54b6a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 57), sizeof v); (u32)v; });  // @28_54b6a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 57), &v, sizeof v); }  // @29_54b6a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 41588), sizeof v); (u32)v; });  // @30_54b6a0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 25580), sizeof v); (u32)v; });  // @31_54b6a0
  PV[3] = (u32)(ecx);  // @32_54b6a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_54b6a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[3], PV[2], PV[1]);  // @34_54b6a0
  ecx = edx = 0;  // @35_54b6a0
  FL[2] = (eax & eax);  // @36_54b6a0
  if (FL[2] == 0) goto L54b77d;  // @37_54b6a0
  edx = (u32)(6961556);  // @38_54b6a0
  L54b757:;
  ecx = eax;  // @40_54b6a0
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @41_54b6a0
  ecx = edx = 0;  // @42_54b6a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_54b6a0
  ecx = esi;  // @44_54b6a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @45_54b6a0
  ecx = edx = 0;  // @46_54b6a0
  eax = 0;  // @47_54b6a0
  FL[3] = eax;  // @48_54b6a0
  SEH_LEAVE();  // @49_54b6a0
  return eax;  // @50_54b6a0
  L54b77d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @52_54b6a0
  PV[4] = (u32)(eax);  // @53_54b6a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_54b6a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 60)))(ecx, PV[4], (u32)(4294957296));  // @55_54b6a0
  ecx = edx = 0;  // @56_54b6a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @57_54b6a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 57), sizeof v); (u32)v; });  // @58_54b6a0
  FL[0] = eax; FL[1] = (u32)(3);  // @59_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @60_54b6a0
  FL[0] = eax; FL[1] = (u32)(2);  // @61_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @62_54b6a0
  FL[0] = eax; FL[1] = (u32)(4);  // @63_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @64_54b6a0
  FL[0] = eax; FL[1] = (u32)(5);  // @65_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @66_54b6a0
  FL[0] = eax; FL[1] = (u32)(6);  // @67_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @68_54b6a0
  FL[0] = eax; FL[1] = (u32)(7);  // @69_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @70_54b6a0
  FL[0] = eax; FL[1] = (u32)(8);  // @71_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @72_54b6a0
  FL[0] = eax; FL[1] = (u32)(9);  // @73_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @74_54b6a0
  FL[0] = eax; FL[1] = (u32)(10);  // @75_54b6a0
  if (FL[0] == FL[1]) goto L54b83d;  // @76_54b6a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @77_54b6a0
  eax = (u32)(esi + 25584);  // @78_54b6a0
  PV[5] = (u32)(eax);  // @79_54b6a0
  PV[6] = (u32)(ecx);  // @80_54b6a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_54b6a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, PV[6], (u32)(7070112), PV[5]);  // @82_54b6a0
  ecx = edx = 0;  // @83_54b6a0
  FL[2] = (eax & eax);  // @84_54b6a0
  if (FL[2] == 0) goto L54b7f2;  // @85_54b6a0
  edx = (u32)(6961584);  // @86_54b6a0
  goto L54b757;  // @87_54b6a0
  L54b7f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @89_54b6a0
  ecx = edi;  // @90_54b6a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 204), sizeof v); (u32)v; });  // @91_54b6a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @92_54b6a0
  ecx = edx = 0;  // @93_54b6a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @94_54b6a0
  if (FL[2] == 0) goto L54b83d;  // @95_54b6a0
  eax = ext_41e290_cdecl1((u32)(80));  // @96_54b6a0
  ecx = edx = 0;  // @97_54b6a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @98_54b6a0
  reg.state = (s32)((u32)(1));  // @99_54b6a0
  FL[2] = (eax & eax);  // @100_54b6a0
  if (FL[2] == 0) goto L54b825;  // @101_54b6a0
  ecx = eax;  // @102_54b6a0
  eax = ext_54e9d0_thiscall1(ecx);  // @103_54b6a0
  ecx = edx = 0;  // @104_54b6a0
  ecx = eax;  // @105_54b6a0
  goto L54b827;  // @106_54b6a0
  L54b825:;
  ecx = 0;  // @108_54b6a0
  FL[3] = ecx;  // @109_54b6a0
  L54b827:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 25588), &v, sizeof v); }  // @111_54b6a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_54b6a0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @113_54b6a0
  reg.state = (s32)((u32)(4294967295));  // @114_54b6a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[7], (u32)(1));  // @115_54b6a0
  ecx = edx = 0;  // @116_54b6a0
  L54b83d:;
  eax = esi;  // @118_54b6a0
  SEH_LEAVE();  // @119_54b6a0
  return eax;  // @120_54b6a0
}
PCREG(54b6a0, lifted_54b6a0);

