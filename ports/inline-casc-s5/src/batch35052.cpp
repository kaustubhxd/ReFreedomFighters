// batch35052.cpp - cascade s5 batch 35052: 0x4d5e80 (GUESS parse a path, remember its id and notify the listener with the normalised path).
#include "ff.h"

extern "C" u8 THISCALL ext_4d6520(u8 *self, const u8 *a, u32 *p20, u32 *p24);   // ret 0xc, bool in AL
extern "C" void THISCALL ext_4d61e0(u8 *vec);                                      // grow the vector at +0x5e, plain ret
extern "C" void FASTCALL ext_4d7130(const u8 *src, u8 *dst);                       // fastcall (ecx = src, edx = dst): copy with backslashes turned into slashes
typedef void(THISCALL *v1_t)(void *, void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4d5e80, thiscall(a) ret 4, returns bool (AL). ok = 0x4d6520(this, a, &x, &v). When ok: the vector header at this+0x5e (capacity dword at +0, size at +4 = this+0x62, data pointer at +8 = this+0x66, all
// unaligned): size >= capacity calls 0x4d61e0(vec); size++; data[size - 1] = v. When [this+0x6a] is set: a 0x10004-byte stack buffer receives the normalised copy of the C string a
// (0x4d7130) and [this+0x6a] slot 0xc(buffer) is called. Returns ok.
static u8 THISCALL fn4d5e80(u8 *self, const u8 *a) {
  u32 x, v;
  u8 ok = ext_4d6520(self, a, &x, &v);
  if (ok) {
    u8 *vec = self + 0x5e;
    if (rd32u(self + 0x62) >= rd32u(vec)) ext_4d61e0(vec);
    u32 size = rd32u(vec + 4) + 1;
    wr32u(vec + 4, size);
    u8 *data = (u8 *)rd32u(vec + 8);
    wr32u(data + size * 4 - 4, v);
    if (rd32u(self + 0x6a)) {
      u8 buf[0x10004];
      ext_4d7130(a, buf);
      u8 *o = (u8 *)rd32u(self + 0x6a);
      (*(v1_t **)o)[0xc / 4](o, buf);
    }
  }
  return ok;
}
PCREG(4d5e80, fn4d5e80);
