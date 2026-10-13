// batch411.cpp - small ZBaseGeom and string accessors used by DebugControl (0x482b80) and the frame update.
#include "ff.h"

// ---------------------------------------------------------------- 0x4db550 ZBaseGeom::GetRoomList() const [high]
// thiscall, plain ret, eax. A room index at +0x5c (16-bit, 1-based) asks the room manager (render manager +8)
// slot 0x5c for the room list of that index; index 0 gives null.
static u8 *THISCALL baseGeomGetRoomList(u8 *self) {
  u16 w = *(u16 *)(self + 0x5c);
  if (!w)
    return 0;
  u8 *rmo = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  return vcall<u8 *>(rmo, 0x5c, (u32)w);
}
PCREG(4db550, baseGeomGetRoomList);

// ---------------------------------------------------------------- 0x4daf90 ZBaseGeom::GetCen(float* out) const [high]
// thiscall, ret 4: copies the three floats at +0x30 (the centre) to out.
static void THISCALL baseGeomGetCen(u8 *self, float *out) {
  out[0] = *(float *)(self + 0x30);
  out[1] = *(float *)(self + 0x34);
  out[2] = *(float *)(self + 0x38);
}
PCREG(4daf90, baseGeomGetCen);

// ---------------------------------------------------------------- 0x4cc1d0 MYSTR::c_str() [inference]
// thiscall, returns the first dword of the object: the String pointer of the MYSTR (the name's char*).
// GC: no name-map entry. The shape matches the MYSTR accessors used with the debug strings (batch 401, HealWounded).
static u32 THISCALL mystrCStr(u8 *self) { return *(u32 *)self; }
PCREG(4cc1d0, mystrCStr);
