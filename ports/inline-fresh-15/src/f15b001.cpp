// f15b001.cpp - fresh slice 15, batch 1 (2026-10-12): the 16 smallest open functions of residue 15.
// 0x638cb0 REFTAB::Size: this+0x18.          0x635330 ZEventBase::Remove: this+4 |= 1.
// 0x6053b0 OpaqueString_t::getTypeName: 0x67a14c (string address).
// 0x607cf0 / 0x614ef0 / 0x64b130: constant getters 0x3c / 0x1d / 0x78.
// 0x60d830 (named ZRenderGC::EnableFog, folded body): returns this+0x118a, plain ret (no args popped).
// 0x659c30: push ebp/mov/pop then jmp 0x63fea0 (ZDrawBase::RoomCreate): naked forwarder.
// 0x60ed70 ZRender::LOD: [[0x70039c]+0x97].  0x651030 / 0x651170: byte arg -> this+0x83 / +0x81, ret 4.
// 0x658d30 ZGeomDrawEntry::Bones: byte this+0x3f ? [this+0x48]+0x90 : 0.
// 0x604370 ScriptEvent_t::getEventData: p = this+0x18; p[1] = 0; p[2] = [[p]+8]; return p.
// 0x638670: thiscall 0x638610(this) + [this+0x32]*4 + 4.
// 0x550c30 CFFScriptInterfaceDll::PushScene(const char*): byte this+0xc -> 0x557930(ecx 0) then 0x555550(result). ret 4.
// 0x64f9b0 ZRender::CreateView(u32): [this+0xbd] slot 0x28 (this, a) thiscall; returns its eax. ret 4.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL f15_638cb0(void *self) { return AT(u32, self, 0x18); }
extern "C" void THISCALL f15_635330(void *self) { AT(u32, self, 4) |= 1; }
extern "C" u32 f15_6053b0() { return 0x67a14cu; }
extern "C" u32 THISCALL f15_607cf0(void *) { return 0x3c; }
extern "C" u32 THISCALL f15_614ef0(void *) { return 0x1d; }
extern "C" u32 THISCALL f15_64b130(void *) { return 0x78; }
extern "C" u32 THISCALL f15_60d830(void *self) { return AT(u32, self, 0x118a); }

extern "C" __attribute__((naked)) void f15_659c30() { asm volatile("jmp ext_63fea0"); }

extern "C" u32 f15_60ed70() { return AT(u32, G(u8 *, 0x70039c), 0x97); }
extern "C" void THISCALL f15_651030(void *self, u8 on) { AT(u8, self, 0x83) = on; }
extern "C" void THISCALL f15_651170(void *self, u8 on) { AT(u8, self, 0x81) = on; }

extern "C" u32 THISCALL f15_658d30(void *self) {
  if (AT(u8, self, 0x3f) == 0) return 0;
  return AT(u32, self, 0x48) + 0x90;
}

extern "C" u32 *THISCALL f15_604370(void *self) {
  u32 *p = (u32 *)((u8 *)self + 0x18);
  p[1] = 0;
  p[2] = AT(u32, (void *)p[0], 8);
  return p;
}

extern "C" char ext_638610[];
typedef u32(THISCALL *Get0)(void *);
extern "C" u32 THISCALL f15_638670(void *self) {
  u32 n = ((Get0)(void *)ext_638610)(self);
  return n + AT(u32, self, 0x32) * 4 + 4;
}

extern "C" char ext_557930[], ext_555550[];
extern "C" void THISCALL f15_550c30(void *self, const char *) {
  if (AT(u8, self, 0xc) == 0) return;
  void *t = ((void *(THISCALL *)(void *))(void *)ext_557930)(nullptr);
  ((void(THISCALL *)(void *))(void *)ext_555550)(t);
}

extern "C" u32 THISCALL f15_64f9b0(void *self, u32 a) {
  return vcall<u32>(AT(void *, self, 0xbd), 0x28, self, a);
}

PCREG(638cb0, f15_638cb0);
PCREG(635330, f15_635330);
PCREG(6053b0, f15_6053b0);
PCREG(607cf0, f15_607cf0);
PCREG(614ef0, f15_614ef0);
PCREG(64b130, f15_64b130);
PCREG(60d830, f15_60d830);
PCREG(659c30, f15_659c30);
PCREG(60ed70, f15_60ed70);
PCREG(651030, f15_651030);
PCREG(651170, f15_651170);
PCREG(658d30, f15_658d30);
PCREG(604370, f15_604370);
PCREG(638670, f15_638670);
PCREG(550c30, f15_550c30);
PCREG(64f9b0, f15_64f9b0);
