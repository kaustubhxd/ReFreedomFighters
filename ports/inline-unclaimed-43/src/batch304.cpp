// batch304.cpp - input-action probe, 0x43ad20 (area 43, 2026-10-12). Caller: 0x43ae00 (ZInputActions vtable slot 44).
// thiscall (this = ECX), one stack argument (an object whose slot 0x10 takes (buffer, 0x100)), ret 4, returns bool in al.
// Body: edi = dword at +0x46; if edi == 0 return false. If the byte at +0x34 is set, clear it and return false.
// Otherwise: X from +0xc (type word 3 -> X = p - 4; type word 1 -> X = (v - 4) when v != 0; else 0), a NUL-terminated
// string at [X + 8] is copied to frame buf[0..], then the NUL-terminated string at [this + 8] to buf[0x7c..]
// (the original's second copy starts at ebp-0x84, which is buf[0x7c]); buf[0xf8] = edi; then obj->slot 0x10(&hdr, 0x100)
// where hdr = 1 is the dword before buf. Return true.
// Frame: hdr at ebp-0x104, buf at ebp-0x100 (256 bytes). The callee's buffer is the header plus buf.
// X = 0 reads the dword at address 8 (the mapped low page in the harness; the same read in the original).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static bool THISCALL probeInputAction(u8 *self, u8 *obj) {
  u32 edi = U32(self, 0x46);
  if (edi == 0)
    return false;
  if (self[0x34] != 0) {
    self[0x34] = 0;
    return false;
  }
  u32 p = U32(self, 0xc);
  u32 X = 0;
  if (p != 0) {
    u32 t = U32(p, 0);
    if (t == 3) {
      X = p - 4;
    } else if (t == 1) {
      u32 v = U32(p, 8);
      X = (v != 0) ? v - 4 : 0;
    }
  }
  struct {
    u32 hdr;
    u8 buf[0x100];
  } f;
  f.hdr = 1;
  {
    const u8 *s = (const u8 *)U32(X, 8);
    u8 *d = f.buf;
    u8 c;
    do {
      c = *s++;
      *d++ = c;
    } while (c != 0);
  }
  {
    const u8 *s = (const u8 *)U32(self, 8);
    u8 *d = f.buf + 0x7c;
    u8 c;
    do {
      c = *s++;
      *d++ = c;
    } while (c != 0);
  }
  *(u32 *)(f.buf + 0xf8) = edi;
  vcall<void>((void *)obj, 0x10, (void *)&f.hdr, 0x100u);
  return true;
}
PCREG(43ad20, probeInputAction);
