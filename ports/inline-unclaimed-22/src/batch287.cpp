// batch287.cpp - area 22, residue-1 slice (docs/20-unclaimed-22.md, "Residue 1, batch287"): ten small functions from the
// coordinator's size-sorted floor(addr/16) mod 20 == 1 list. Names from the GameCube/Ghidra name map; behaviour from the
// PC bytes.
#include "ff.h"

extern "C" u8 *THISCALL ext_5fa630(u8 *self);                 // returns the global at 0x724270 (hooked)
extern "C" u32 FASTCALL ext_6054b0(u32 a, u32 b);              // builds a 0x12-byte object (GUESS: hooked)
extern "C" void THISCALL ext_5630f0(u8 *self);                 // CBaseWindow::OnWindowOpen2 (hooked)
extern "C" void THISCALL ext_565100(u8 *self, u32 status);     // CFileWindow::SetStatus (GUESS: hooked)

// 0x60db10 ZRenderGC::GetRenderName: returns the string at 0x6bcb70.
u32 THISCALL renderGetName_60db10(u8 *) { return 0x6bcb70u; }
PCREG(60db10, renderGetName_60db10);

// 0x500a10: sets the object's vtable pointer to 0x69c968 (base destructor body).
void THISCALL setVtable_500a10(u8 *self) { *(u32 *)self = 0x69c968u; }
PCREG(500a10, setVtable_500a10);

// 0x563610: this+0x58 = arg (thiscall, ret 4).
void THISCALL set58_563610(u8 *self, u32 v) { *(u32 *)(self + 0x58) = v; }
PCREG(563610, set58_563610);

// 0x5f5510 Process_t::recycle(arg): o = 0x5fa630(this) (ecx passed through), then a tail jump to o->vt 0x50(arg).
u32 THISCALL processRecycle_5f5510(u8 *self, u32 arg) {
  u8 *o = ext_5fa630(self);
  return vcall<u32>(o, 0x50, arg);
}
PCREG(5f5510, processRecycle_5f5510);

// 0x605b90: returns [+0x10] + [+8] * 4 - [+0xc] + 9.
u32 THISCALL size_605b90(u8 *self) {
  return *(u32 *)(self + 0x10) + *(u32 *)(self + 8) * 4 - *(u32 *)(self + 0xc) + 9;
}
PCREG(605b90, size_605b90);

// 0x605550 (a, b, c) stdcall, ret 0xc: the first argument is unused; returns fastcall 0x6054b0(b, c).
u32 STDCALL create_605550(u32, u32 b, u32 c) { return ext_6054b0(b, c); }
PCREG(605550, create_605550);

// 0x4dc110: c = [this+0x54]; returns c's word +4 when c and that word are not 0, else the empty string 0x67c8e8.
u32 THISCALL name_4dc110(u8 *self) {
  u8 *c = *(u8 **)(self + 0x54);
  if (c && *(u32 *)(c + 4)) return *(u32 *)(c + 4);
  return 0x67c8e8u;
}
PCREG(4dc110, name_4dc110);

// 0x57bd50 ZFFLoadError::OnWindowOpen2: the base OnWindowOpen2, then SetStatus([this+0xcb2]).
void THISCALL loadErrorOnWindowOpen2_57bd50(u8 *self) {
  ext_5630f0(self);
  ext_565100(self, *(u32 *)(self + 0xcb2));
}
PCREG(57bd50, loadErrorOnWindowOpen2_57bd50);

// 0x656950 (dst, src) stdcall, ret 8: copies words +0x10 and +0x14; returns the +0x14 word (left in eax).
u32 STDCALL copy1014_656950(u8 *dst, const u8 *src) {
  *(u32 *)(dst + 0x10) = *(const u32 *)(src + 0x10);
  u32 v = *(const u32 *)(src + 0x14);
  *(u32 *)(dst + 0x14) = v;
  return v;
}
PCREG(656950, copy1014_656950);

// 0x5f3210 savefloat(float f) (thiscall, ret 4): returns ([this+0x15])->vt 0x4c(f).
u32 THISCALL saveFloat_5f3210(u8 *self, float f) { return vcall<u32>(*(u8 **)(self + 0x15), 0x4c, f); }
PCREG(5f3210, saveFloat_5f3210);
