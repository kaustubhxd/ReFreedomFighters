// batch1034.cpp - ZCamHelper::ZCamHelper() (0x5cce70): the helper's field defaults and the calls the original makes
// (base ctor, COLI ctor, ease ctors, FFControlMode option, script reference, auto-aim option). The stores come
// from the disassembly in order (imm stores only); the calls are placed where the original makes them.
// Exception-frame setup (fs:[0]) is not reproduced. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_469870(void *self);            // base class ctor (original)
extern "C" THISCALL void *ext_4e1b60(void *coli);           // COLI::COLI (original)
extern "C" THISCALL void ext_662750(void *ease);            // ease ctor (original)
extern "C" THISCALL void ext_662be0(void *ease);            // ease ctor (original)
extern "C" THISCALL void ext_662ed0(void *ease);            // ease ctor (original)
extern "C" FASTCALL void ext_4de7a0(float *m);              // mreset
extern "C" void *ext_41e290(u32 size);                      // operator new (cdecl)
extern "C" THISCALL u32 ext_4d8330(void *obj, const char *name, const char *desc, float *out);  // option object ctor

// _stricmp through the import slot (the exe calls it via the IAT at 0x676414).
static inline int ext_stricmp(u32 a, const char *b) {
  typedef int (*strfn)(const char *, const char *);
  strfn f = *(strfn *)0x676414;
  return f((const char *)a, b);
}

// 0x5cce70 ZCamHelper::ZCamHelper()
static THISCALL u8 *ZCamHelper_Ctor(u8 *self) {
  ext_469870(self);
  at<u32>(self, 4) |= 0x20;
  at<u32>(self, 0x44) = 0;
  at<u32>(self, 0) = 0x6b4dd4;  // vtable (ZCamHelper)
  at<u32>(self, 0x48) = 0;
  at<u32>(self, 0xa54) = 0;
  at<u32>(self, 0xa58) = 0;
  at<u32>(self, 0xaa6) = 0;
  at<u32>(self, 0xab7) = 0;
  at<u32>(self, 0xae9) = 0;
  ext_4e1b60(self + 0xb5b);
  at<u32>(self, 0xbc9) = 0;
  ext_662750(self + 0xbd5);
  ext_662750(self + 0xbf2);
  at<u32>(self, 0xc0f) = 0;
  at<u32>(self, 0xc13) = 0;
  at<u32>(self, 0xc17) = 0;
  at<u32>(self, 0xc1b) = 0;
  at<u8>(self, 0xc1f) = 1;
  at<u32>(self, 0xc20) = 0;
  at<u32>(self, 0xc24) = 0;
  at<u32>(self, 0xc28) = 0x3f800000;
  at<u32>(self, 0xc2c) = 0;
  at<u32>(self, 0xc30) = 0;
  at<u32>(self, 0xc34) = 0;
  at<u32>(self, 0xc38) = 0x3ba3d70a;
  at<u32>(self, 0xc3c) = 0;
  at<u32>(self, 0xc40) = 0;
  at<u32>(self, 0xc44) = 0;
  at<u32>(self, 0xc48) = 0;
  at<u8>(self, 0xc4c) = 1;
  at<u32>(self, 0xc4d) = 0;
  at<u32>(self, 0xc51) = 0;
  at<u32>(self, 0xc55) = 0x3f800000;
  at<u32>(self, 0xc59) = 0;
  at<u32>(self, 0xc5d) = 0;
  at<u32>(self, 0xc61) = 0;
  at<u32>(self, 0xc65) = 0x3ba3d70a;
  ext_662be0(self + 0xd36);
  ext_662ed0(self + 0xd87);
  at<u32>(self, 0xe1c) = 1;
  { u32 val = 0;
    if (vcall<bool>(G(u8 *, 0x70039c), 0x5c, (const char *)0x6b4e68, &val)) {  // "FFControlMode"
      if (ext_stricmp(val, (const char *)0x67b0d8) == 0) at<u32>(self, 0xe1c) = 0;  // "A"
    } }
  at<u32>(self, 0xe18) = 0;
  at<u32>(self, 0xa54) = 0;
  at<u32>(self, 0xa5c) = 0;
  at<u32>(self, 0xa60) = 0;
  at<u32>(self, 0xa64) = 0;
  at<u32>(self, 0xa68) = 0;
  at<u32>(self, 0xa6c) = 0;
  at<u16>(self, 0xa70) = 0;
  at<u16>(self, 0xd33) = 0;
  at<u32>(self, 0xe0f) = 0;
  at<u32>(self, 0xe13) = 0;
  at<u32>(self, 0xb35) = 0;
  at<u32>(self, 0xad5) = 0;
  at<u32>(self, 0xad9) = 0x3f800000;
  at<u32>(self, 0xadd) = 0x3f800000;
  at<u8>(self, 0xad4) = 1;
  at<u32>(self, 0xae9) = 0;
  at<u32>(self, 0xaed) = 0;
  at<u32>(self, 0xaf1) = 0;
  at<u32>(self, 0xaf5) = 0;
  at<u32>(self, 0xaf9) = 0x3e7a35dd;
  at<u32>(self, 0xb0d) = 0x40a00000;
  at<u32>(self, 0xb01) = 0x3f800000;
  at<u32>(self, 0xb09) = 0x3f000000;
  at<u32>(self, 0xafd) = 0x3edf66f3;
  at<u16>(self, 0xb19) = 0x100;
  at<u32>(self, 0xb05) = 0x3f800000;
  at<u32>(self, 0xa96) = 0xbf9c61aa;
  at<u32>(self, 0xa9a) = 0x3f860a92;
  at<u32>(self, 0xa9e) = 0xbf9c61aa;
  at<u32>(self, 0xaa2) = 0x3f860a92;
  at<u32>(self, 0xb1b) = 0;
  at<u32>(self, 0xd0d) = 0;
  at<u32>(self, 0xdf5) = 0x3ea0d97c;  // [edi], edi = self+0xdf5
  at<u32>(self, 0xdf9) = 0x3ea0d97c;
  at<u32>(self, 0xdfd) = 0x453b8000;
  at<u32>(self, 0xe01) = 0x4b095440;
  at<u8>(self, 0xd32) = 1;
  at<u32>(self, 0xb1f) = 0;
  at<u32>(self, 0xb23) = 0;
  at<u32>(self, 0xb27) = 0;
  at<u32>(self, 0xb2b) = 0;
  at<u32>(self, 0xb2f) = 0;
  at<u16>(self, 0xb33) = 0;
  at<u16>(self, 0xe0d) = 0;
  at<u32>(self, 0xb54) = 0;
  at<u8>(self, 0xb4f) = 0;
  at<u32>(self, 0xae5) = 0;
  at<u32>(self, 0xb45) = 0;
  at<u8>(self, 0xb4d) = 0;
  at<u8>(self, 0xab6) = 0;
  at<u32>(self, 0xab7) = 0;
  at<u8>(self, 0xd35) = 0;
  at<u8>(self, 0xdd8) = 0;
  at<u32>(self, 0xdd9) = 0;
  at<u32>(self, 0xd15) = 0;
  at<u32>(self, 0xd19) = 0;
  at<u32>(self, 0xd1d) = 0;
  at<u32>(self, 0xd22) = 0;
  at<u32>(self, 0xd26) = 0;
  at<u32>(self, 0xd2a) = 0;
  at<u32>(self, 0xa72) = 0;
  at<u32>(self, 0xa76) = 0;
  at<u32>(self, 0xa7a) = 0x42c80000;
  at<u32>(self, 0xa8a) = 0;
  at<u32>(self, 0xa8e) = 0;
  at<u32>(self, 0xa92) = 0;
  at<u32>(self, 0xa7e) = 0;
  at<u32>(self, 0xa82) = 0;
  at<u32>(self, 0xa86) = 0;
  at<u32>(self, 0xc7d) = 0;
  at<u32>(self, 0xc81) = 0;
  at<u32>(self, 0xc85) = 0;
  at<u32>(self, 0xc71) = 0;
  at<u32>(self, 0xc75) = 0;
  at<u32>(self, 0xc79) = 0;
  ext_4de7a0((float *)(self + 0xc89));
  at<u32>(self, 0xb35) = 0;
  at<u32>(self, 0xb50) = 0;
  at<u32>(self, 0xbcd) = 0xfffffffb;
  at<u32>(self, 0xd2e) = 0;
  at<u32>(self, 0xd11) = 0;
  at<u32>(self, 0xbd1) = 0;
  at<u32>(self, 0xb11) = 0x43fa0000;
  at<u32>(self, 0xc69) = 0x43960000;
  at<u16>(self, 0xb59) = (u16)vcall<u32>(SYS9B, 0x114, (const char *)0x6acfa4, 0u, (const char *)0x6b4e78, 0xe4u);  // GetRefObjectCamHelper
  at<u32>(self, 0xbea) = 4;
  at<u32>(self, 0xc07) = 4;
  at<u32>(self, 0xbc9) = 0;
  u8 *aa = (u8 *)ext_41e290(0x108);
  u32 edx = aa ? ext_4d8330(aa, (const char *)0x6b4ec4, (const char *)0x6b4ea8, (float *)(self + 0xdf5)) : 0;
  at<u32>(self, 0xa50) = edx;
  vcall<void>(G(u8 *, 0x70039c), 0x1a4, edx);
  return self;
}
PCREG(5cce70, ZCamHelper_Ctor);
