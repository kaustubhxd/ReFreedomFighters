#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_4de7a0(void *obj);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// appends one 0x15-byte element at this + 0xd4e + count * 0x15 from the staging bytes `el` (16 zero bytes, a 4-byte 1.0f stored at el + 17, so el[16] stays uninitialised stack:
// the original copies the dword el[16..19] = (stack garbage, 0, 0, 0x80) and the byte el[20] = 0x3f) and bumps the count at this[0xd4a]
static inline void push_elem(u8 *self, const u8 *el) {
  u32 n = rd32u(self + 0xd4a);
  u8 *dst = self + 0xd4e + n * 0x15;
  __builtin_memcpy(dst, el, 16);
  __builtin_memcpy(dst + 0x10, el + 0x10, 4);
  dst[0x14] = el[0x14];
  wr32u(self + 0xd4a, n + 1);
}

// 0x592850: thiscall(), void, /GS protected. Initialises the element list at this+0xd4e (21-byte entries, count at this[0xd4a]) by appending 17 identical entries (the original
// unrolls them as 2 x 8 + 1): each is 16 zero bytes, the dword (pad, 0, 0, 0x80) and the byte 0x3f, where pad is an uninitialised stack byte of the original ([ebp-0x30], below a
// 4-byte 1.0f stored at an odd offset). The port keeps it uninitialised in a local staging array el (the harness poisons untouched stack with 0xcc, so both read 0xcc). Then the vector
// this+0xeb3 = (0, 0, 0) goes to this slot 0x84, this[0xebf], [0xec3], [0xec7] = 0, config C = [[0x70039c]+0x9b] slot 0x138(), C slot 0x88(0x68a9e0, &v) (v preset 0) and
// this[0xecb] = table slot 0x58(v); finally this[0xed3] = 170.0f, [0xed7] = 1.0f, [0xedb] = 550.0f, [0xedf] = 0.
extern "C" void THISCALL fn_592850(u8 *self) {
  u8 tmpobj[0x40];
  ext_4de7a0(tmpobj + 0x18);
  u8 el[0x15];
  __builtin_memset(el, 0, 16);
  wr32u(el + 17, 0x3f800000);
  for (int i = 0; i < 17; i++) push_elem(self, el);
  u8 *v3 = self + 0xeb3;
  wr32u(v3 + 8, 0);
  wr32u(v3 + 4, 0);
  wr32u(v3, 0);
  (*(V1 *)(vt(self) + 0x84))(self, (u32)v3);
  wr32u(self + 0xec7, 0);
  wr32u(self + 0xec3, 0);
  wr32u(self + 0xebf, 0);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *T = (u8 *)rd32u(eng + 0x9b);
  u8 *C = (u8 *)(*(V0 *)(vt(T) + 0x138))(T);
  u32 local44 = 0;
  (*(V2 *)(vt(C) + 0x88))(C, 0x68a9e0, (u32)&local44);
  eng = G(u8 *, 0x70039c);
  T = (u8 *)rd32u(eng + 0x9b);
  u32 r = (*(V1 *)(vt(T) + 0x58))(T, local44);
  wr32u(self + 0xecb, r);
  wr32u(self + 0xed3, 0x432a0000);
  wr32u(self + 0xed7, 0x3f800000);
  wr32u(self + 0xedb, 0x44098000);
  wr32u(self + 0xedf, 0);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(592850, fn_592850);
