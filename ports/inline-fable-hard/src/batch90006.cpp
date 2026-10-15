// batch90006.cpp - hard-function trial (fable), batch 90006: 0x5a3710 multiplayer manager constructor (455 insns, 70 calls).
#include "ff.h"

extern "C" void THISCALL ext_469870(void *);                 // base ctor (257 bytes, hooked)
extern "C" u8 *ext_41e290(u32 n);                             // cdecl (verified, hooked): allocation
extern "C" u8 *THISCALL ext_4ccbe0(void *, u32 n, u32 m);     // ret 8 (verified, real): small array object ctor

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *table() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *settings() { u8 *t = table(); return vcall<u8 *>(t, 0x134); }
static inline void reg68(u32 name, u32 a, u32 b) { u8 *z = settings(); vcall<void>(z, 0x68, name, a, b); }
static inline void reg5c(u32 name, u32 a, u32 b) { u8 *z = settings(); vcall<void>(z, 0x5c, name, a, b); }
static inline void reg40(u32 name, u32 a, u32 b) { u8 *z = settings(); vcall<void>(z, 0x40, name, a, b); }
static inline u16 txt(u32 name, u32 file, u32 line) { u8 *t = table(); return (u16)vcall<u32>(t, 0x114, name, 0u, file, line); }
typedef u32 (THISCALL *id_t)(void *);

// 0x5a3710, thiscall() returns this, SEH frame. Base ctor 0x469870; E[4] |= 0x20; E[0x44] = 0; vtable 0x6af018; [0x7003b8][0x2c21] = E; E[0xe9..0xf8] = 0.
// settings = [[0x70039c]+0x9b]->slot 0x134. If settings->slot 0x90(0x68a9d4, &b) leaves b == 0: register the 26 default settings (slots 0x68/0x5c/0x40/0x58).
// [0x70039c][0x1b5d] = 1 always. E[0x48] = settings->slot 0x88(0x6a80fc). E[0xf9..0x108] = 8 words from table->slot 0x114(name, 0, 0x6af0cc, line).
// reg = table->slot 0x138(); id = type id of E through the allocator object [0x70038c] (slot 0x20(E) nonzero -> 0; else the range function
// at +8 when E is in [+0xc, +0x10); else E[-4], filled by slot 0xac(E) when zero); reg->slot 0x60(0x6a8324, id, 4). Four alloc(0x1c) + 0x4ccbe0(4, 0)
// into E[0xe9..]; E[0x10b], 0x10f, 0x11b, 0x123, 0x127, 0x12b, 0x12f, 0x133 = 0; E[0x113] = 10.0f.
static u8 *THISCALL fn5a3710(u8 *E) {
  u8 b;
  u32 v14;
  ext_469870(E);
  wr(E + 4, rd(E + 4) | 0x20);
  wr(E + 0x44, 0);
  wr(E, 0x6af018);
  wr(G(u8 *, 0x7003b8) + 0x2c21, (u32)E);
  wr(E + 0xe9, 0);
  wr(E + 0xed, 0);
  wr(E + 0xf1, 0);
  wr(E + 0xf5, 0);
  u8 *z = settings();
  b = 0;
  vcall<void>(z, 0x90, 0x68a9d4u, (u32)&b);
  bool have = b != 0;
  wr(G(u8 *, 0x70039c) + 0x1b5d, 1);
  if (!have) {
    reg68(0x68a9d4, 1, 0);
    reg5c(0x68fcec, 2, 2);
    reg68(0x6a7cf0, 1, 0);
    reg5c(0x6a7d04, 0, 2);
    reg5c(0x6a7d14, 3, 2);
    reg40(0x6a7d24, 0x6a812c, 0xc);
    reg5c(0x6a7d34, 8, 2);
    reg68(0x6a7d48, 1, 0);
    reg5c(0x6a7d5c, 1, 2);
    reg5c(0x6a7d6c, 4, 2);
    reg40(0x6a7d7c, 0x6af09c, 0xc);
    reg5c(0x6a7d8c, 4, 2);
    reg68(0x6a7da0, 0, 0);
    reg5c(0x6a7db4, 2, 2);
    reg5c(0x6a7dc4, 4, 2);
    reg40(0x6a7dd4, 0x6af0ac, 0xc);
    reg5c(0x6a7de4, 4, 2);
    reg68(0x6a7df8, 0, 0);
    reg5c(0x6a7e0c, 3, 2);
    reg5c(0x6a7e1c, 4, 2);
    reg40(0x6a7e2c, 0x6af0bc, 0xc);
    reg5c(0x6a7e3c, 0, 2);
    reg5c(0x6a813c, 0, 2);
    reg5c(0x6a80fc, 1, 2);
    z = settings();
    vcall<void>(z, 0x58, 0x6a810cu, 0x40400000u, 3u);
  }
  z = settings();
  v14 = 0;
  vcall<void>(z, 0x88, 0x6a80fcu, (u32)&v14);
  wr(E + 0x48, v14);
  *(u16 *)(E + 0xf9) = txt(0x6af104, 0x6af0cc, 0x75);
  *(u16 *)(E + 0xfb) = txt(0x6af118, 0x6af0cc, 0x77);
  *(u16 *)(E + 0xfd) = txt(0x6af12c, 0x6af0cc, 0x78);
  *(u16 *)(E + 0xff) = txt(0x6af13c, 0x6af0cc, 0x7a);
  *(u16 *)(E + 0x101) = txt(0x6ace1c, 0x6af0cc, 0x7b);
  *(u16 *)(E + 0x103) = txt(0x6af14c, 0x6af0cc, 0x7d);
  *(u16 *)(E + 0x105) = txt(0x6af164, 0x6af0cc, 0x7f);
  *(u16 *)(E + 0x107) = txt(0x6af174, 0x6af0cc, 0x80);
  u8 *t = table();
  u8 *reg = vcall<u8 *>(t, 0x138);
  u8 *al = G(u8 *, 0x70038c);
  u32 id;
  if (vcall<u32>(al, 0x20, (u32)E)) {
    id = 0;
  } else {
    al = G(u8 *, 0x70038c);
    u32 f = rd(al + 8);
    if (f && rd(al + 0xc) <= (u32)E && (u32)E < rd(al + 0x10)) {
      id = ((id_t)f)(E);
    } else {
      if (rd(E - 4) == 0) vcall<void>(al, 0xac, (u32)E);
      id = rd(E - 4);
    }
  }
  vcall<void>(reg, 0x60, 0x6a8324u, id, 4u);
  for (u32 i = 0; i < 4; i++) {
    u8 *p = ext_41e290(0x1c);
    u8 *o = p ? ext_4ccbe0(p, 4, 0) : 0;
    wr(E + 0xe9 + 4 * i, (u32)o);
  }
  wr(E + 0x10b, 0);
  wr(E + 0x10f, 0);
  wr(E + 0x11b, 0);
  wr(E + 0x123, 0);
  wr(E + 0x113, 0x41200000);
  wr(E + 0x127, 0);
  wr(E + 0x12b, 0);
  wr(E + 0x12f, 0);
  wr(E + 0x133, 0);
  return E;
}
PCREG(5a3710, fn5a3710);
