// batch753.cpp - area 72, gap rows: tail-jump forwarders to known exe targets with known arity (2026-10-12).
#include "ff.h"

extern "C" void THISCALL ext_4efdd0(void *self, u32 a, u32 b, u32 c, u32 d);   // ZWINOBJ::Draw (ret 0x10: 4 args)
extern "C" void THISCALL ext_43ff00(void *self, u32 a, u32 b, u32 c, u32 d, u32 e); // ZGROUP::Duplicate (ret 0x14: 5 args)
extern "C" void THISCALL ext_4fd510(void *self, u32 a);                      // ZSortCameraList::ReadInput (ret 4)
extern "C" void THISCALL ext_5fa590(void *self, u32 a, u32 b);               // OpaqueType_t::toSerial (ret 8)
extern "C" void THISCALL ext_5355a0(void *self, u32 a, u32 b, u32 c);        // ZDllSound::BuildFrame (ret 0xc)

// 0x4f5840 - jmp 0x4efdd0
static void THISCALL fwd_4f5840(u8 *self, u32 a, u32 b, u32 c, u32 d) { ext_4efdd0(self, a, b, c, d); }
PCREG(4f5840, fwd_4f5840);
// 0x4f9e00 - jmp 0x43ff00
static void THISCALL fwd_4f9e00(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) { ext_43ff00(self, a, b, c, d, e); }
PCREG(4f9e00, fwd_4f9e00);
// 0x4fc130 - jmp 0x4fd510
static void THISCALL fwd_4fc130(u8 *self, u32 a) { ext_4fd510(self, a); }
PCREG(4fc130, fwd_4fc130);
// 0x50b7e0 - jmp 0x5fa590
static void THISCALL fwd_50b7e0(u8 *self, u32 a, u32 b) { ext_5fa590(self, a, b); }
PCREG(50b7e0, fwd_50b7e0);
// 0x533100 - jmp 0x5355a0
static void THISCALL fwd_533100(u8 *self, u32 a, u32 b, u32 c) { ext_5355a0(self, a, b, c); }
PCREG(533100, fwd_533100);
