// batch38082.cpp - cascade s8 batch 38082: 0x43db70 (static-initialisation style routine: constructs and tears down ~30 stack-allocated helper objects in sequence).
#include "ff.h"

extern "C" void THISCALL ext_43de40(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_43de70(u8 *);
extern "C" void THISCALL ext_43e190(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_43e990(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_43ea20(u8 *);
extern "C" void THISCALL ext_441b90(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_441c00(u8 *);
extern "C" void THISCALL ext_443f40(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_444020(u8 *);
extern "C" void THISCALL ext_4451d0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_445330(u8 *);
extern "C" void THISCALL ext_447640(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_4478d0(u8 *);
extern "C" void THISCALL ext_449d40(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_449d80(u8 *);
extern "C" void THISCALL ext_44a8c0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_44a930(u8 *);
extern "C" void THISCALL ext_44b310(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_44b5c0(u8 *);
extern "C" void THISCALL ext_44c3d0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_44c400(u8 *);
extern "C" void THISCALL ext_44c930(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_44ca70(u8 *);
extern "C" void THISCALL ext_44e6d0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_44e700(u8 *);
extern "C" void THISCALL ext_44e900(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_44e970(u8 *);
extern "C" void THISCALL ext_44edf0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_44ee20(u8 *);
extern "C" void THISCALL ext_4519a0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_451a00(u8 *);
extern "C" void THISCALL ext_452790(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_4527c0(u8 *);
extern "C" void THISCALL ext_452990(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_4529d0(u8 *);
extern "C" void THISCALL ext_452ed0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_452f80(u8 *);
extern "C" void THISCALL ext_4545f0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_454620(u8 *);
extern "C" void THISCALL ext_454980(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_454ab0(u8 *);
extern "C" void THISCALL ext_455330(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_4553d0(u8 *);
extern "C" void THISCALL ext_4571f0(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_457290(u8 *);
extern "C" void THISCALL ext_45a040(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_45a0e0(u8 *);
extern "C" void THISCALL ext_45a530(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_45a5a0(u8 *);
extern "C" void THISCALL ext_45ad90(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_45ae10(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_45b460(u8 *, u32, u32, u32);
extern "C" void THISCALL ext_45b4d0(u8 *);

// 0x43db70, cdecl(void). The original keeps all objects in one 0x16a0-byte frame (object at ebp-offset); the port keeps the same layout so the objects' relative addresses match.
static void fn43db70() {
  static_assert(sizeof(u8) == 1, "");
  u8 frame[0x16a0 + 8];
  u8 *fp = frame + 0x16a0;
  ext_44c3d0(fp - 0x1d, 0, 0, 0);  // call 0
  ext_44c400(fp - 0x1d);  // call 1
  ext_44c930(fp - 0x16a0, 0, 0, 0);  // call 2
  ext_44ca70(fp - 0x16a0);  // call 3
  ext_44e6d0(fp - 0x1c, 0, 0, 0);  // call 4
  ext_44e700(fp - 0x1c);  // call 5
  ext_44e900(fp - 0x84, 0, 0, 0);  // call 6
  ext_44e970(fp - 0x84);  // call 7
  ext_4451d0(fp - 0x19c, 0, 0, 0);  // call 8
  ext_445330(fp - 0x19c);  // call 9
  ext_44edf0(fp - 0xd8, 0, 0, 0);  // call 10
  ext_44ee20(fp - 0xd8);  // call 11
  ext_4519a0(fp - 0x48, 0, 0, 0);  // call 12
  ext_451a00(fp - 0x48);  // call 13
  ext_452790(fp - 0x20, 0, 0, 0);  // call 14
  ext_4527c0(fp - 0x20);  // call 15
  ext_452990(fp - 0x28, 0, 0, 0);  // call 16
  ext_4529d0(fp - 0x28);  // call 17
  ext_452ed0(fp - 0x68, 0, 0, 0);  // call 18
  ext_452f80(fp - 0x68);  // call 19
  ext_43e990(fp - 0x60, 0, 0, 0);  // call 20
  ext_43ea20(fp - 0x60);  // call 21
  ext_43e190(fp - 0x4c, 0, 0, 0);  // call 22
  ext_43de70(fp - 0x4c);  // call 23
  ext_4545f0(fp - 0x64, 0, 0, 0);  // call 24
  ext_454620(fp - 0x64);  // call 25
  ext_447640(fp - 0x20, 0, 0, 0);  // call 26
  ext_4478d0(fp - 0x20);  // call 27
  ext_449d40(fp - 0x24, 0, 0, 0);  // call 28
  ext_449d80(fp - 0x24);  // call 29
  ext_454980(fp - 0x50, 0, 0, 0);  // call 30
  ext_454ab0(fp - 0x50);  // call 31
  ext_455330(fp - 0xf8, 0, 0, 0);  // call 32
  ext_4553d0(fp - 0xf8);  // call 33
  ext_4571f0(fp - 0x358, 0, 0, 0);  // call 34
  ext_457290(fp - 0x358);  // call 35
  ext_45a040(fp - 0x64, 0, 0, 0);  // call 36
  ext_45a0e0(fp - 0x64);  // call 37
  ext_45a530(fp - 0x3c, 0, 0, 0);  // call 38
  ext_45a5a0(fp - 0x3c);  // call 39
  ext_45ad90(fp - 0x28, 0, 0, 0);  // call 40
  ext_43de70(fp - 0x28);  // call 41
  ext_45ae10(fp - 0x28, 0, 0, 0);  // call 42
  ext_43de70(fp - 0x28);  // call 43
  ext_45b460(fp - 0x25c, 0, 0, 0);  // call 44
  ext_45b4d0(fp - 0x25c);  // call 45
  ext_443f40(fp - 0xc8, 0, 0, 0);  // call 46
  ext_444020(fp - 0xc8);  // call 47
  ext_44a8c0(fp - 0x34, 0, 0, 0);  // call 48
  ext_44a930(fp - 0x34);  // call 49
  ext_44b310(fp - 0x25, 0, 0, 0);  // call 50
  ext_44b5c0(fp - 0x25);  // call 51
  ext_43de40(fp - 0x1c, 0, 0, 0);  // call 52
  ext_43de70(fp - 0x1c);  // call 53
  ext_441b90(fp - 0x88, 0, 0, 0);  // call 54
  ext_441c00(fp - 0x88);  // call 55
}
PCREG(43db70, fn43db70);
