// batch363.cpp - area 76 (docs/20-unclaimed-76.md, label D; blocked rows resolved): five thiscall accessors with one stack argument a,
// ret 4. Each computes a value V, elem = 0x5003d0(container, index 0) (thiscall, one word, ret 4), then 0x5002f0(elem, V) (thiscall,
// one word, ret 4; stores V and sets the flag byte). The second pushed word of the caller is 0x5002f0's argument: the callee pops it.
//   0x55ace0: V = 0x59ffc0([this+0x1c]) ([ecx+0x77f]); container = [a+8].
//   0x55b0f0: V = [[[this+0x1c]+0x54]+4]; container = [a+8].
//   0x559f30: V = [this+0x1c].vtbl[0x6a8](); container = [a+8].
//   0x5595c0: V = (s16) low word of [this+0x1c].vtbl[0x6b0]() (cwde); container = [a+8].
#include "ff.h"

extern "C" u32 THISCALL ext_59ffc0(u8 *self);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 index);
extern "C" void THISCALL ext_5002f0(u8 *self, u32 value);

static u32 vtcall0(u32 obj, u32 off) {
    return ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)obj + off)))(obj);
}

static void THISCALL f55ace0(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 V = ext_59ffc0((u8 *)*(u32 *)(self + 0x1cu));
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 8u), 0u);
    ext_5002f0((u8 *)elem, V);
}
PCREG(55ace0, f55ace0);

static void THISCALL f55b0f0(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 holder = *(u32 *)(self + 0x1cu);
    u32 V = *(u32 *)(*(u32 *)(holder + 0x54u) + 4u);
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 8u), 0u);
    ext_5002f0((u8 *)elem, V);
}
PCREG(55b0f0, f55b0f0);

static void THISCALL f559f30(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 V = vtcall0(*(u32 *)(self + 0x1cu), 0x6a8u);
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 8u), 0u);
    ext_5002f0((u8 *)elem, V);
}
PCREG(559f30, f559f30);

static void THISCALL f5595c0(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    u32 r = vtcall0(*(u32 *)(self + 0x1cu), 0x6b0u);
    u32 V = (u32)(s32)(s16)(r & 0xffffu);      // cwde
    u32 elem = ext_5003d0((u8 *)*(u32 *)(a + 8u), 0u);
    ext_5002f0((u8 *)elem, V);
}
PCREG(5595c0, f5595c0);
