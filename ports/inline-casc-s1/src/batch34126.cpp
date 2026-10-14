// batch34126.cpp - cascade tier E, batch 34126: 0x561180 (append a suffix and a name), 0x57f130 (refresh every listed object), 0x59dae0 (resolve a request and record it).
#include "ff.h"

extern "C" u32 THISCALL ext_57d500(void *self, void *a, u32 b);                          // thiscall ret 8
extern "C" u32 THISCALL ext_57ee90(void *self);                                          // thiscall, plain ret
extern "C" u32 THISCALL ext_5eade0(void *self, u32 a, u32 b, u32 c, u32 d, u32 e);       // ecx = out block; stack (a, b, c, d, e), ret 0x14
extern "C" u32 THISCALL ext_5a2460(void *self, void *a);                                 // thiscall ret 4 (al)
extern "C" u32 THISCALL ext_5a2bd0(void *self, void *a);                                 // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x561180, thiscall(s) ret 4: nothing when byte [this+0x87] is zero. Else the word at 0x679e6c (a space) is appended at the terminator of s; t = [[[0x70039c]+0x9b]+0xae4]->slot0(0x6a67e8, 0x6a6828); the string t (with its
// terminator) is appended after the end of the new s.
static void THISCALL fn561180(u8 *self, u8 *s) {
  if (self[0x87] == 0) return;
  u8 *e = s;
  while (*e) e++;
  e[0] = G(u8, 0x679e6c);
  e[1] = G(u8, 0x679e6d);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = *(u8 **)(tbl + 0xae4);
  u8 *t = vcall<u8 *>(o, 0, 0x6a67e8u, 0x6a6828u);
  u32 n = 0;
  while (t[n]) n++;
  n++;
  e = s;
  while (*e) e++;
  for (u32 i = 0; i < n; i++) e[i] = t[i];
}
PCREG(561180, fn561180);

// 0x57f130, thiscall(flag) ret 4: embedded list at this+0x23c (slots 0x14 count, 0x30 item i): for every i < count (count re-read, signed): o = [0x70038c]->slot0xcc(item); when o: if byte flag: byte [o+0xe0] = low byte of ext_57d500(o, o+0x2c, 0),
// byte [o+0xdf] = 0, ext_57ee90(o); then ext_57ee90(o).
static void THISCALL fn57f130(u8 *self, u32 flag) {
  u8 *lst = self + 0x23c;
  s32 n = (s32)vcall<u32>(lst, 0x14);
  if (n <= 0) return;
  s32 i = 0;
  do {
    u32 item = vcall<u32>(lst, 0x30, (u32)i);
    u8 *o = vcall<u8 *>(G(u8 *, 0x70038c), 0xcc, item);
    if (o) {
      if ((u8)flag) {
        o[0xe0] = (u8)ext_57d500(o, o + 0x2c, 0);
        o[0xdf] = 0;
        ext_57ee90(o);
      }
      ext_57ee90(o);
    }
    i++;
  } while (i < (s32)vcall<u32>(lst, 0x14));
}
PCREG(57f130, fn57f130);

// 0x59dae0, thiscall(a, b, c, d, e) ret 0x14, bool: false for a null a. Else ext_5eade0(&blk, a, b, c, 0, e); when ext_5a2460(this+0x7ce, &blk) has a non-zero low byte and (u8) d is set:
// ext_5a2bd0(this, this+0x7ce + 16 * unaligned [this+0x7ce] - 12), true; otherwise false.
static u32 THISCALL fn59dae0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u8 blk[0x10];
  if (!a) return 0;
  ext_5eade0(blk, a, b, c, 0, e);
  u8 *p = self + 0x7ce;
  if ((u8)ext_5a2460(p, blk) && (u8)d) {
    ext_5a2bd0(self, p + rd32(p) * 16 - 0xc);
    return 1;
  }
  return 0;
}
PCREG(59dae0, fn59dae0);
