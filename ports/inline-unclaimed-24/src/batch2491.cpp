// batch2491.cpp - decomp area 24, batch 2491 (residue 3 of floor(addr/16) mod 20, smallest first).
#include "ff.h"

extern "C" void THISCALL ext_573930(void *self, u32 cam, u32 id);  // ZBaseMap::DrawUpdate(ZCAMERA*, EDrawID), thiscall, ret 8 (assumed)
extern "C" void THISCALL ext_574ff0(void *self);                    // thiscall, no argument
extern "C" void THISCALL ext_562e90(void *self, u32 a, u32 b);      // CBaseWindow::OnWindowClose(unsigned int, bool), thiscall, ret 8 (assumed)
extern "C" u32 THISCALL ext_56f2d0(void *self);                     // CNewMenu::GetStartZone(), thiscall

// 0x574e30 ZBaseMap::Draw-style wrapper (GUESS name). When the byte at +0x88 is set: DrawUpdate(cam, id); then, when id == 2 and the
// byte at +0x21b is set, the thiscall helper 0x574ff0.
static void THISCALL baseMapDraw(u8 *self, u32 cam, u32 id) {
  if (*(u8 *)(self + 0x88)) {
    ext_573930(self, cam, id);
    if (id == 2 && *(u8 *)(self + 0x21b))
      ext_574ff0(self);
  }
}
PCREG(574e30, baseMapDraw);

// 0x56fa70 CNewMenu window-close handler (GUESS name for the class-level method). Calls the base OnWindowClose with (a, b); when the
// low byte of b is set, GetStartZone, then clears the byte at +0x1ed; always clears the byte at +0x196.
static void THISCALL newMenuOnWindowClose(u8 *self, u32 a, u32 b) {
  ext_562e90(self, a, b);
  if ((u8)b) {
    ext_56f2d0(self);
    *(u8 *)(self + 0x1ed) = 0;
  }
  *(u8 *)(self + 0x196) = 0;
}
PCREG(56fa70, newMenuOnWindowClose);

// 0x4b0df0 (GUESS name). Copies the dword at system object +0x40 into this+0x50 unless they alias; when the dword at system +0x1a9f
// is nonzero: this+0x60 = 0, byte +0x6c = 0, and this+0x68 = 0 - (this+0x64 * 0). The two stack arguments are not read.
static void THISCALL guessCopyAndClear(u8 *self, u32 a, u32 b) {
  (void)a;
  (void)b;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *dst = self + 0x50;
  u8 *src = sys + 0x40;
  if (dst != src)
    *(u32 *)dst = *(u32 *)src;
  if (*(u32 *)(sys + 0x1a9f) != 0) {
    float t = *(float *)(self + 0x64) * 0.0f;
    *(u32 *)(self + 0x60) = 0;
    *(u8 *)(self + 0x6c) = 0;
    *(float *)(self + 0x68) = 0.0f - t;
  }
}
PCREG(4b0df0, guessCopyAndClear);
