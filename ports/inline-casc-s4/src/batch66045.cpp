// batch66045.cpp - cascade s4 batch 66045: 0x4273d0 (tier F row).
#include "ff.h"

typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *v3r_t)(void *, u32, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(*fopen_t)(const char *, const char *);
typedef s32(*fseek_t)(u32, u32, u32);
typedef u32(*fread_t)(void *, u32, u32, u32);
typedef s32(*fclose_t)(u32);

// 0x4273d0, thiscall(name, buf, size, off, skip) ret 0x14, returns the byte count or -1 (this = t): skip == 0: k = t->slot 0x4c (0x130)(name); o = t->slot 0x1c (0x70)(k); o set: r = o->slot 7 (0x1c)(k, buf, size, off); r != -1 -> return r.
// off != 0: f = fopen(name, "rb") (0x678ccc); none -> -1; fseek(f, off, 0); n = fread(buf, 1, size, f); fclose(f); return n.
// off == 0: x = t->slot 2 (8)(name); none -> -1; n = t->slot 0x10 (0x40)(x, buf, size); t->slot 7 (0x1c)(x); return n.
static u32 THISCALL fn4273d0(u8 *t, u32 name, u32 buf, u32 size, u32 off, u8 skip) {
  if (!skip) {
    u32 k = (*(v1r_t **)t)[0x130 / 4](t, name);
    u8 *o = (*(v1o_t **)t)[0x70 / 4](t, k);
    if (o) {
      u32 r = (*(v4r_t **)o)[0x1c / 4](o, k, buf, size, off);
      if (r != 0xffffffffu) return r;
    }
  }
  if (off) {
    u32 f = G(fopen_t, 0x6763b0)((const char *)name, (const char *)0x678ccc);
    if (!f) return 0xffffffffu;
    G(fseek_t, 0x6763e8)(f, off, 0);
    u32 n = G(fread_t, 0x6763f8)((void *)buf, 1, size, f);
    G(fclose_t, 0x6763ac)(f);
    return n;
  }
  u32 x = (*(v1r_t **)t)[8 / 4](t, name);
  if (!x) return 0xffffffffu;
  u32 n = (*(v3r_t **)t)[0x40 / 4](t, x, buf, size);
  (*(v1_t **)t)[0x1c / 4](t, x);
  return n;
}
PCREG(4273d0, fn4273d0);
