// f16b005.cpp - fresh slice 16, batch 5 (2026-10-12).
// 0x562bc0 CBaseWindow::LoadLevel: +0x84 = 1; +0x85 == 0 and +0xdc == 2 -> +0x85 = 1, +0xdc = 4,
//           +0x64 = (float)(int)[0x70039c]+0x30 * [0x6785e4] (1/1024), ZWINDOWS::EnableFade 0x4f21f0(this slot 0x84(), false).
//           The pushed 0 before slot 0x84 is EnableFade's argument: slot 0x84 is CWinEvent::GetSystem 0x562380 (no args).
// 0x4f8040 ZSlider::OnKeyPress(key): 0x102 -> this slot 0x370(-step), 0x103 -> slot 0x370(step) (step = float +0x9b; the
//           minus is a sign-bit xor with [0x67af40]); both return true; else tail ZCONTROL::OnKeyPress 0x4fa390. Ret 4.
// 0x50b780 (stdcall p): e = 0x5003d0([p+4]; 0) (ret 4); byte e+4 <= 1 -> e[0] = 0, e+4 = 1, returns e; else error report
//           (0x69c8e0, 0xc4; 0x69c6b0, 0x69c938) then the handler at 0x7003b0 (int3 if null; not run).
// 0x496700 ZGeomBuffer::DetachAllGeoms(g): for child c = [s+0x54] along s = [g+0x50], s = [s+0x60] while c's flags
//           ([[c+0xc]+0x23], or 0x200002 with no c) have bit 0x100000: recurse on c. Then while [g+0x50]: g slot 0x290([g+0x50], 0).
// 0x4e4900 (this = block, pool): index n = u16 +8 non-zero, +0xc == 0, +0 | +4 == 0 -> in the pool's row n (base [pool],
//           stride [pool+0xc]) clear the first of 4 u16 slots that maps back to this, then CMemPool::DeAlloc 0x4e6bf0(pool; this).
// 0x53aa80 CEVENTCONTROLLER::GetOldestNotifyTime(out): *out = [0x70039c]+0x40; list +4: slot 0x4c(&it), then for each
//           e = slot 0x64(&it): e+8 < *out (signed) and out != e+8 -> *out = [e+8]. Returns out. Ret 4.
#include "ff.h"
#include "f16log.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4f21f0[], ext_4fa390[], ext_5003d0[], ext_4e6bf0[];

extern "C" void THISCALL f16_562bc0(u8 *self) {
  AT(u8, self, 0x84) = 1;
  if (AT(u8, self, 0x85) != 0 || AT(u32, self, 0xdc) != 2) return;
  AT(u8, self, 0x85) = 1;
  AT(u32, self, 0xdc) = 4;
  AT(float, self, 0x64) = (float)AT(s32, G(u8 *, 0x70039c), 0x30) * G(float, 0x6785e4);
  void *w = vcall<void *>(self, 0x84);
  ((void(THISCALL *)(void *, bool))(void *)ext_4f21f0)(w, false);
}

extern "C" bool THISCALL f16_4f8040(u8 *self, u32 key) {
  if (key == 0x102) {
    vcall<void>(self, 0x370, AT(u32, self, 0x9b) ^ G(u32, 0x67af40));
    return true;
  }
  if (key == 0x103) {
    vcall<void>(self, 0x370, AT(u32, self, 0x9b));
    return true;
  }
  return ((bool(THISCALL *)(void *, u32))(void *)ext_4fa390)(self, key);
}

extern "C" u32 STDCALL f16_50b780(u8 *p) {
  u8 *e = ((u8 * (THISCALL *)(void *, u32))(void *)ext_5003d0)(AT(void *, p, 4), 0);
  if (AT(u8, e, 4) <= 1) {
    AT(u32, e, 0) = 0;
    AT(u8, e, 4) = 1;
    return (u32)e;
  }
  f16_report2(0x69c8e0u, 0xc4, 0x69c6b0u, 0x69c938u);
  typedef u32 (*Hfn)();
  Hfn h = G(Hfn, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}

extern "C" void THISCALL f16_496700(void *self, u8 *g) {
  for (u8 *s = AT(u8 *, g, 0x50); s; s = AT(u8 *, s, 0x60)) {
    u8 *c = AT(u8 *, s, 0x54);
    u32 fl = c ? AT(u32, AT(u8 *, c, 0xc), 0x23) : 0x200002u;
    if (!(fl & 0x100000)) break;
    f16_496700(self, c);
  }
  while (AT(u32, g, 0x50)) vcall<void>(g, 0x290, AT(u32, g, 0x50), 0u);
}

extern "C" void THISCALL f16_4e4900(u8 *self, u8 *pool) {
  u32 n = AT(u16, self, 8);
  if (!n || AT(u32, self, 0xc) != 0 || (AT(u32, self, 0) | AT(u32, self, 4)) != 0) return;
  u32 base = AT(u32, pool, 0), sz = AT(u32, pool, 0xc);
  u16 *row = (u16 *)(n * sz + base);
  for (u32 i = 0; i < 4; ++i) {
    if (row[i] * sz + base == (u32)self) {
      row[i] = 0;
      ((void(THISCALL *)(void *, void *))(void *)ext_4e6bf0)(pool, self);
      return;
    }
  }
}

extern "C" s32 *THISCALL f16_53aa80(u8 *self, s32 *out) {
  *out = AT(s32, G(u8 *, 0x70039c), 0x40);
  void *l = AT(void *, self, 4);
  if (l) {
    u32 it[3];
    vcall<void>(l, 0x4c, (void *)it);
    for (u8 *e = vcall<u8 *>(AT(void *, self, 4), 0x64, (void *)it); e; e = vcall<u8 *>(AT(void *, self, 4), 0x64, (void *)it)) {
      s32 *p = (s32 *)(e + 8);
      if (*p < *out && out != p) *out = *p;
    }
  }
  return out;
}

PCREG(562bc0, f16_562bc0);
PCREG(4f8040, f16_4f8040);
PCREG(50b780, f16_50b780);
PCREG(496700, f16_496700);
PCREG(4e4900, f16_4e4900);
PCREG(53aa80, f16_53aa80);
