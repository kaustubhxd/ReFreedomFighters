// batch0109.cpp - fresh-01 batch 9 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" u8 THISCALL ext_648dd0(u8 *self);                          // ZDrawArray grow (new block)
extern "C" void THISCALL ext_647f70(u8 *entry);                       // ZGeomViewEntry init
extern "C" void THISCALL ext_573590(u8 *p);                           // base constructor
extern "C" void THISCALL ext_4e6680(u8 *self);                        // ZSoundDllBase::ZSoundDllBase
extern "C" u32 THISCALL ext_5f1180(u8 *p);                            // sound manager constructor
extern "C" void *ext_41e290(u32 size);                                // operator new
extern "C" void FASTCALL ext_633654(u32 cookie);                      // __security_check_cookie

// 0x630c50, zlib init_block(deflate_state*) (cdecl): zeroes the Freq words of dyn_ltree (0x11e entries at +0x8c),
// dyn_dtree (0x1e at +0x980) and bl_tree (0x13 at +0xa74); opt_len (+0x16a4), static_len (+0x16a0), matches (+0x16a8)
// and last_lit (+0x1698) = 0; dyn_ltree[END_BLOCK].Freq (+0x48c) = 1.
static void zInitBlock(u8 *s) {
  for (u32 i = 0; i < 0x11e; i++) *(u16 *)(s + 0x8c + 4 * i) = 0;
  for (u32 i = 0; i < 0x1e; i++) *(u16 *)(s + 0x980 + 4 * i) = 0;
  for (u32 i = 0; i < 0x13; i++) *(u16 *)(s + 0xa74 + 4 * i) = 0;
  *(u32 *)(s + 0x16a4) = 0;
  *(u32 *)(s + 0x16a0) = 0;
  *(u32 *)(s + 0x16a8) = 0;
  *(u32 *)(s + 0x1698) = 0;
  *(u16 *)(s + 0x48c) = 1;
}
PCREG(630c50, zInitBlock);

// 0x648350, ZDrawArray<ZGeomViewEntry, ...>::Add(): finds a block with a free entry along the ring from this+8 (as
// 0x63aed0) or grows (0x648dd0; 0 when that fails); count (+0xc)++; takes the free entry idx (+2 word; 0 when it is
// 0xffff): entry = block + 0x10 + idx*36, the block's free index = the entry's first word, init 0x647f70(entry),
// block byte 0 ++. Returns the entry.
static u8 *THISCALL drawArrayGeomViewAdd(u8 *self) {
  u8 *start = *(u8 **)(self + 8);
  u8 *b;
  if (start) {
    do {
      b = *(u8 **)(self + 8);
      if (*(u16 *)(b + 2) != 0xffff) goto found;
      b = *(u8 **)(b + 8);
      *(u8 **)(self + 8) = b;
    } while (start != b && b);
  }
  if (!ext_648dd0(self)) return 0;
  b = *(u8 **)(self + 8);
found:
  ++*(u32 *)(self + 0xc);
  {
    u32 idx = *(u16 *)(b + 2);
    if (idx == 0xffff) return 0;
    u8 *e = b + (idx * 9 + 4) * 4;
    *(u16 *)(b + 2) = *(u16 *)e;
    ext_647f70(e);
    b[0]++;
    return e;
  }
}
PCREG(648350, drawArrayGeomViewAdd);

// 0x575e50 (unnamed factory): p = allocator slot 0x44 (ECX pushed, GUESS as in batch 6); when set: constructor 0x573590,
// vtable 0x6a9348, byte +0x20b = 1, dword +0x20d = 0x1000100, +0x21d = 0. Returns p.
static u8 *THISCALL factory575e50(u32 ecxIn) {
  u8 *a = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  u8 *p = vcall<u8 *>(a, 0x44, ecxIn);
  if (p) {
    ext_573590(p);
    *(u32 *)p = 0x6a9348;
    p[0x20b] = 1;
    *(u32 *)(p + 0x20d) = 0x1000100;
    *(u32 *)(p + 0x21d) = 0;
  }
  return p;
}
PCREG(575e50, factory575e50);

// 0x626ed0 (unnamed, cdecl (parser, begin, end, int* tok)): checks whether [begin, end) is the UTF-16BE name "xml"
// (6 bytes, high bytes 0), case-insensitively. *tok = 0xb first. Returns 0 for a mixed or upper case "xml" (last letter
// 'L', or 'l' after an uppercase letter); for "xml" exactly *tok = 0xc and returns 1; anything else returns 1.
static u32 xmlCheck626ed0(u32 parser, const s8 *s, const s8 *end, u32 *tok) {
  u32 up = 0;
  *tok = 0xb;
  if (end - s != 6 || s[0] != 0) return 1;
  if (s[1] == 'X') up = 1;
  else if (s[1] != 'x') return 1;
  if (s[2] != 0) return 1;
  if (s[3] == 'M') up = 1;
  else if (s[3] != 'm') return 1;
  if (s[4] != 0) return 1;
  if (s[5] == 'L') return 0;
  if (s[5] != 'l') return 1;
  if (up) return 0;
  *tok = 0xc;
  return 1;
}
PCREG(626ed0, xmlCheck626ed0);

// 0x424650, ZSysInterfaceGC::UPlotF(int, int, const char*, ...) (cdecl, this first): unless engine float +0x9c7 is 0.0
// (0x6785d0), for each plotter in the list at this+0x190f (next at +8): formats with [0x700390] slot 0x4c(buf, fmt,
// va) into a 0x400-byte local and calls the plotter's cdecl slot 0x124(plotter, x, y, buf).
typedef void (*plotFn)(void *, u32, u32, char *);
static void sysPlotF(u8 *self, u32 x, u32 y, u32 fmt, ...) {
  char buf[0x400];
  __builtin_va_list ap;
  __builtin_va_start(ap, fmt);
  if (!(*(float *)(G(u8 *, 0x70039c) + 0x9c7) == G(float, 0x6785d0))) {
    u8 *p = *(u8 **)(self + 0x190f);
    while (p) {
      vcall<void>(G(u8 *, 0x700390), 0x4c, (char *)buf, fmt, (char *)ap);
      (*(plotFn *)(*(u8 **)p + 0x124))(p, x, y, buf);
      p = *(u8 **)(p + 8);
    }
  }
  __builtin_va_end(ap);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(424650, sysPlotF);

// 0x5f12d0 (unnamed ZSoundDllBase subclass constructor): base constructor, vtable 0x6b83bc, [0x724694] = 0, +0xc = the
// new 0xb8-byte object built by 0x5f1180 (0 when new fails), +0x1010 = 0. Returns this.
static u8 *THISCALL soundDllCtor(u8 *self) {
  ext_4e6680(self);
  *(u32 *)self = 0x6b83bc;
  G(u32, 0x724694) = 0;
  u8 *p = (u8 *)ext_41e290(0xb8);
  u32 r = p ? ext_5f1180(p) : 0;
  *(u32 *)(self + 0xc) = r;
  *(u32 *)(self + 0x1010) = 0;
  return self;
}
PCREG(5f12d0, soundDllCtor);

// 0x56f190, CNewMenu::CopyData(ZEventBase*): copies dwords +0x19d, +0x1a1, +0x1a9, +0x199, +0x1a5, +0x1ad, +0x1b1,
// +0x1b5, +0x1b9, +0x1bd, +0x1c5 from src, in that order.
static void THISCALL newMenuCopyData(u8 *self, const u8 *src) {
  static const u16 offs[] = {0x19d, 0x1a1, 0x1a9, 0x199, 0x1a5, 0x1ad, 0x1b1, 0x1b5, 0x1b9, 0x1bd, 0x1c5};
  for (u32 i = 0; i < 11; i++) *(u32 *)(self + offs[i]) = *(const u32 *)(src + offs[i]);
}
PCREG(56f190, newMenuCopyData);
