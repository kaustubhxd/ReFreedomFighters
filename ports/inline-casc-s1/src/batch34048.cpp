// batch34048.cpp - cascade tier E, batch 34048: 0x547670 (write an array of 0x34-byte records through slot 0x68), 0x559d40 (register an id and a table value),
// 0x5612c0 (append a separator and a path component to a string).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);    // thiscall ret 4: entry lookup
extern "C" void THISCALL ext_5002f0(void *self, u32 v);   // thiscall ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x547670, thiscall(s) ret 4, returns true: like 0x546040 but through s slot 0x68: for each of the [this+0x28] (signed) records of 0x34 bytes at the unaligned pointer [this+0xf] sends the
// fields at +0xc, +0, +0x18 and +0x24.
static bool THISCALL fn547670(u8 *self, u8 *s) {
  s32 n = *(s32 *)(self + 0x28);
  u8 *rec = (u8 *)rd32u(self + 0xf);
  s32 i = 0;
  if (n > 0) {
    do {
      vcall<void>(s, 0x68, (u32)(rec + 0xc));
      vcall<void>(s, 0x68, (u32)rec);
      vcall<void>(s, 0x68, (u32)(rec + 0x18));
      vcall<void>(s, 0x68, (u32)(rec + 0x24));
      rec += 0x34;
      i++;
    } while (i < n);
  }
  return true;
}
PCREG(547670, fn547670);

// 0x559d40, thiscall(a) ret 4: 0x5002f0(0x5003d0([a+8], 0), 0); m = [this+0x1c]; r = m->slot0x20(); r2 = r->slot0x20() (each step stops when null); when r2->slot0x1e0(0x100001): v =
// engine table slot 0x4c(r2); 0x5002f0(0x5003d0([a+8], 0), v).
static void THISCALL fn559d40(u8 *self, u8 *a) {
  u32 e = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0((void *)e, 0);
  u8 *m = *(u8 **)(self + 0x1c);
  u8 *r = vcall<u8 *>(m, 0x20);
  if (!r) return;
  u8 *r2 = vcall<u8 *>(r, 0x20);
  if (!r2) return;
  if (!vcall<bool>(r2, 0x1e0, 0x100001u)) return;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(tbl, 0x4c, (u32)r2);
  u32 e2 = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0((void *)e2, v);
}
PCREG(559d40, fn559d40);

// 0x5612c0, stdcall(buf) ret 4 (ECX unused): appends the two-byte constant at 0x679e6c to the string in buf (writing both bytes at its terminator), then s = [[engine table]+0xae4]->slot0(0x6a67e8,
// 0x6a683c) and appends s (with its terminator) at the new end of buf.
static void STDCALL fn5612c0(u8 *buf) {
  u8 *e = buf;
  while (*e) e++;
  e[0] = *(u8 *)0x679e6c;
  e[1] = *(u8 *)0x679e6d;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *c = *(u8 **)(tbl + 0xae4);
  u8 *s = vcall<u8 *>(c, 0, 0x6a67e8u, 0x6a683cu);
  u32 len = 0;
  while (s[len]) len++;
  len += 1;
  e = buf;
  while (*e) e++;
  for (u32 i = 0; i < len; i++) e[i] = s[i];
}
PCREG(5612c0, fn5612c0);
