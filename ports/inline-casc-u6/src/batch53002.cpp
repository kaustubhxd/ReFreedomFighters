// batch53002.cpp - u6 batch 53002: tier H function with engine vcalls.
#include "ff.h"

extern "C" u32 THISCALL ext_591ae0(u8 *self);                 // thiscall, plain ret
extern "C" void THISCALL ext_5922c0(u8 *self, u8 *out);       // thiscall ret 4
extern "C" void THISCALL ext_4de7a0(u8 *self);                // thiscall, plain ret (initialises the 0x24-byte local at ebp-0x34)
typedef void(__attribute__((cdecl)) * logfn_t)(void *, u32);

static inline void wr32b(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline u32 rd32c(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x5d00e0, thiscall no args, /GS frame (cookie omitted), GUESS: fills fields of a 0xe20+ byte object from its owner edi = [this+0x44] and the engine tables.
static void THISCALL fn5d00e0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *edi = *(u8 **)(self + 0x44);
  void *mgr = *(void **)(eng + 0x9b);
  void *a = (void *)vcall<u32>(mgr, 0x134);
  u8 flag = 0;
  vcall<u32>(a, 0x90, 0x68a9d4u, (u32)&flag);
  self[0xe17] = flag != 0;
  *(u32 *)(self + 0xc6d) = *(u32 *)(edi + 0x676);
  *(u32 *)(self + 0xb54) = ext_591ae0(edi);
  ext_5922c0(edi, self + 0xd22);
  u8 local[0x24];
  ext_4de7a0(local);
  wr32b(self + 0xb15, 0x43fa0000);
  u32 mode = *(u32 *)(edi + 0x684);
  u32 str;
  if (mode == 2) str = 0x6b4ed4;
  else if (mode == 3) str = 0x6b4ee0;
  else if (mode == 4) str = 0x6b4eec;
  else str = 0x690418;
  void *b = (void *)vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x138);
  u32 loc = 0;
  vcall<u32>(b, 0x88, str, (u32)&loc);
  *(u32 *)(self + 0xae1) = loc;
  eng = G(u8 *, 0x70039c);
  if (eng[0x6c] == 0) {
    *(u32 *)(self + 0xe1c) = 3;
    eng = G(u8 *, 0x70039c);
  }
  void *r = (void *)vcall<u32>(*(void **)(eng + 0x9b), 0x58, *(u32 *)(self + 0xc6d));
  if (!r) {
    void *lg = G(void *, 0x700390);
    void *o = (void *)vcall<u32>(lg, 0x20, 0x6b4e78u, 0x136u);
    (*(logfn_t **)o)[0x2c / 4](o, 0x6b4ef8);
    return;
  }
  vcall<u32>(r, 0x80, (u32)(self + 0xcb9), (u32)(self + 0xcad));
  float v[3];
  vcall<u32>(edi, 0x378, (u32)v);
  vcall<u32>(edi, 0x84, (u32)v);
  __builtin_memcpy(self + 0xc71, &v[0], 4);
  __builtin_memcpy(self + 0xc75, &v[1], 4);
  __builtin_memcpy(self + 0xc79, &v[2], 4);
}
PCREG(5d00e0, fn5d00e0);
