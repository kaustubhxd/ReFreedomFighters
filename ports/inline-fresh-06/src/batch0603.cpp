// batch0603.cpp - fresh-06 batch 3 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);       // __builtin_delete (cdecl)
extern "C" void *ext_41e290(u32 n);                  // __builtin_new (cdecl)
extern "C" void ext_45c510(void *p);                 // ZGEOM::operator delete (cdecl)
extern "C" void ext_4690b0(void *p, u32 sz);         // sized pool free (cdecl, GUESS)

// The error logger at 0x700390: slot 0x20(file, line) (thiscall) returns a sink whose slot 0x2c is cdecl with the sink
// as first argument (variadic).
typedef void (*sink2)(void *, u32);
typedef void (*sink3)(void *, u32, u32);
static inline void *logAt(u32 line, u32 file) {
  return vcall<void *>(G(void *, 0x700390), 0x20, file, line);   // pushed line first: slot args are (file, line)
}

// 0x452fa0, ZGATE deleting destructor: vtable 0x681b24, the object at +0x52 deleted (slot 0 with 1) when set, base
// destructor 0x43de70, then flags bit 0: bit 2 -> 0x4690b0(this, 0x62), else ZGEOM::operator delete. Returns this.
extern "C" void THISCALL ext_43de70(void *self);
static void *THISCALL zgateDelDtor(u8 *self, u32 flags) {
  void *o = *(void **)(self + 0x52);
  *(u32 *)self = 0x681b24;
  if (o) vcall<void>(o, 0, 1u);
  ext_43de70(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x62);
    else ext_45c510(self);
  }
  return self;
}
PCREG(452fa0, zgateDelDtor);

// 0x63ade0, ZDrawArray<ZGeomDrawEntry,...>::Add(): walks the block list from +8 for a block with a free slot (word +2
// != 0xffff), stopping when it comes back to the first block or reaches null; a block found (or a new one made by
// ConstructorCall 0x63b440) gets +0xc incremented and its slot taken by 0x63b050 (tail call). No block: 0.
extern "C" u8 THISCALL ext_63b440(void *self);
extern "C" void *THISCALL ext_63b050(void *blk);
static void *THISCALL drawArrayAdd(u8 *self) {
  u8 *first = *(u8 **)(self + 8);
  if (first) {
    for (;;) {
      u8 *b = *(u8 **)(self + 8);
      if (*(u16 *)(b + 2) != 0xffff) {
        ++*(u32 *)(self + 0xc);
        return ext_63b050(b);
      }
      u8 *n = *(u8 **)(b + 8);
      *(u8 **)(self + 8) = n;
      if (first == n || !n) break;
    }
  }
  if (!ext_63b440(self)) return 0;
  ++*(u32 *)(self + 0xc);
  return ext_63b050(*(void **)(self + 8));
}
PCREG(63ade0, drawArrayAdd);

// 0x44bca0, ZSNDOBJ::CopyData(const ZGEOM*): ZGEOM::CopyData (0x45d5b0); when the source's slot 0x1e0(0x200012) is
// true: byte +0x20 copied, and with a sound system (engine +0x1a9f) and a sound object at +0x18,
// ZSoundObject::CopyData(src+0x18 object).
extern "C" void THISCALL ext_45d5b0(void *self, const void *src);
extern "C" void THISCALL ext_44bcf0(void *so, void *src);
static void THISCALL sndobjCopyData(u8 *self, u8 *src) {
  ext_45d5b0(self, src);
  if (!vcall<u8>(src, 0x1e0, 0x200012u)) return;
  self[0x20] = src[0x20];
  if (*(u32 *)(G(u8 *, 0x70039c) + 0x1a9f) == 0) return;
  void *so = *(void **)(self + 0x18);
  if (so) ext_44bcf0(so, *(void **)(src + 0x18));
}
PCREG(44bca0, sndobjCopyData);

// 0x65f460, ZDrawBuffer::DrawBaseGeomLocal(ZBaseGeom*, const float*, const float*, unsigned char): OnGeomNotify on
// [this+0xc] with ([this+4], geom, 1, 1); the entry's matrix (+0xc) gets the position (3 dwords to +0x24) and mcpy
// (fastcall: dst, src) of the matrix argument; byte +0x16 = b unless b is 0xff.
extern "C" u8 *THISCALL ext_64d030(void *view, u32 room, void *geom, u32 a, u32 b);
extern "C" void FASTCALL ext_4de420(void *dst, const void *src);
static void THISCALL drawBaseGeomLocal(u8 *self, void *geom, const void *m, const u32 *pos, u32 b) {
  u8 *e = ext_64d030(*(void **)(self + 0xc), *(u32 *)(self + 4), geom, 1, 1);
  u8 *d = *(u8 **)(e + 0xc);
  if (d) {
    *(u32 *)(d + 0x24) = pos[0];
    *(u32 *)(d + 0x28) = pos[1];
    *(u32 *)(d + 0x2c) = pos[2];
    ext_4de420(*(void **)(e + 0xc), m);
  }
  if ((u8)b != 0xff) e[0x16] = (u8)b;
}
PCREG(65f460, drawBaseGeomLocal);

// 0x620120 (no map name; GUESS: collapse whitespace in place, cdecl): '\n', '\r' and ' ' runs become one space,
// leading whitespace is dropped, one trailing space is removed. Returns the pointer to the new terminator.
static char *collapseSpaces(char *s) {
  char *d = s;
  if (*s) {
    char *p = s;
    do {
      char ch = *p;
      if (ch == '\n' || ch == '\r' || ch == ' ') {
        if (d != s && d[-1] != ' ') *d++ = ' ';
      } else {
        *d++ = ch;
      }
      ++p;
    } while (*p);
    if (d != s && d[-1] == ' ') --d;
  }
  *d = 0;
  return d;
}
PCREG(620120, collapseSpaces);

// 0x54c320 (no map name; GUESS: start a COM sound/input buffer): +0x7a = 1, +0x7b = 1 when [+0x75] is 2 or 3; the
// COM object at +0x63ec gets slot 0x34(0) then slot 0x30(0, 0, +0x7b ? 1 : 0) (stdcall, object first). A nonzero
// result goes to 0x54f2b0 (fastcall: result, 0x6a3c20) as a tail call; else 0.
extern "C" u32 FASTCALL ext_54f2b0(u32 hr, u32 s);
static u32 THISCALL comStart(u8 *self) {
  self[0x7a] = 1;
  if (*(u32 *)(self + 0x75) - 2 <= 1) self[0x7b] = 1;
  typedef u32(STDCALL * f34)(void *, u32);
  typedef u32(STDCALL * f30)(void *, u32, u32, u32);
  void *o = *(void **)(self + 0x63ec);
  (*(f34 *)(*(u8 **)o + 0x34))(o, 0);
  o = *(void **)(self + 0x63ec);
  u32 r = (*(f30 *)(*(u8 **)o + 0x30))(o, 0, 0, self[0x7b] ? 1 : 0);
  if (!r) return 0;
  return ext_54f2b0(r, 0x6a3c20);
}
PCREG(54c320, comStart);

// 0x5ffe20 (no map name; GUESS: address to 28-byte record lookup over a chain): for each node (next at +0x9c) with a
// nonzero size (+0x12e) and base (+0x12a) <= a < base + size (unsigned, wrapping as the original): returns
// [+0x132] + (a - base) * 28. None: 0.
static u32 THISCALL chainLookup28(u8 *n, u32 a) {
  do {
    u32 sz = *(u32 *)(n + 0x12e);
    if (sz) {
      u32 base = *(u32 *)(n + 0x12a);
      if (a >= base && a < sz + base) return *(u32 *)(n + 0x132) + (a - base) * 28;
    }
    n = *(u8 **)(n + 0x9c);
  } while (n);
  return 0;
}
PCREG(5ffe20, chainLookup28);

// 0x49e0e0 (no map name; GUESS: load a whole file into a new buffer): the file system (0x700394) slot 0x30(name, 0)
// gives the size; when > 0 the old buffer at +4 is freed, a new one allocated, and slot 0x60(name, buf, size, 0, 0)
// reads it. Returns the last call's EAX (the size when <= 0).
static u32 THISCALL loadWholeFile(u8 *self, u32 name) {
  s32 n = vcall<s32>(G(void *, 0x700394), 0x30, name, 0u);
  if (n <= 0) return (u32)n;
  void *old = *(void **)(self + 4);
  if (old) ext_634273(old, 1);
  void *p = ext_41e290((u32)n);
  *(void **)(self + 4) = p;
  return vcall<u32>(G(void *, 0x700394), 0x60, name, p, (u32)n, 0u, 0u);
}
PCREG(49e0e0, loadWholeFile);

// 0x4b8da0, ZAttachGeomToBone::FrameUpdate(): once (+0x58 flag): the render manager's slot 0x58([+0x4c]) gives the
// geom entry; with +0x54 == 1 its base geom (+8) gets SetOwnerDraw(true); the actor at +0x59 gets slot 0x290(geom,
// [+0x50], 0, 0); own slot 0x68(0x10, 0).
extern "C" void THISCALL ext_4dcbb0(void *g, u32 b);
static void THISCALL attachGeomFrameUpdate(u8 *self) {
  if (self[0x58]) return;
  self[0x58] = 1;
  u8 *e = vcall<u8 *>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x58, *(u32 *)(self + 0x4c));
  if (*(u32 *)(self + 0x54) == 1) ext_4dcbb0(*(void **)(e + 8), 1);
  vcall<void>(*(void **)(self + 0x59), 0x290, *(u32 *)(e + 8), *(u32 *)(self + 0x50), 0u, 0u);
  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(4b8da0, attachGeomFrameUpdate);

// 0x63b7e0, ZDrawBase::AllocSprites(int): size rounded up to 16; +8 counts calls, +0xc adds the size; AllocHi on
// +0x60. -1: error logged (line 0xc7) and 0 returned; else [+0x64] + offset.
extern "C" u32 THISCALL ext_63b710(void *a, u32 n);
static u32 THISCALL drawAllocSprites(u8 *self, s32 n) {
  u32 sz = (u32)(n + 0xf) & 0xfffffff0u;
  ++*(u32 *)(self + 8);
  *(u32 *)(self + 0xc) += sz;
  u32 r = ext_63b710(*(void **)(self + 0x60), sz);
  if (r == 0xffffffffu) {
    void *s = logAt(0xc7, 0x6c265c);
    (*(sink2 *)(*(u8 **)s + 0x2c))(s, 0x6c2684);
    return 0;
  }
  return *(u32 *)(self + 0x64) + r;
}
PCREG(63b7e0, drawAllocSprites);

// 0x6001e0, VMImageInfo_t::initNewStateContext(Process_t*, int, StateContext_t&, DynamicStackData_t&):
// MasterStateRecord_t::initStateContext on this+0xcc with (a, b, c, this, d). False: error logged (line 0x1f2) and the
// handler at 0x7003b0 called (int3 when none; not exercised), returning its EAX; true: initStateContext's EAX.
extern "C" u32 THISCALL ext_600280(void *rec, u32 a, u32 b, u32 c, void *img, u32 d);
static u32 THISCALL vmInitNewStateContext(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u32 r = ext_600280(self + 0xcc, a, b, c, self, d);
  if ((u8)r) return r;
  void *s = logAt(0x1f2, 0x6b94a0);
  (*(sink3 *)(*(u8 **)s + 0x2c))(s, 0x69c6b0, 0x6b94d0);
  typedef u32 (*hfn)();
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  return h();
}
PCREG(6001e0, vmInitNewStateContext);

// 0x455020, ZMaterialDescGroup::Load(ZLoadGame*): ZGROUP::Load, then a count (slot 0x48, written into the argument's
// own stack slot) and that many ids (slot 0x40); each id goes through the render manager's slot 0x58 and the result is
// added to the list at +0x5c (slot 4). Returns true.
extern "C" void THISCALL ext_440e10(void *self, void *lg);
static u8 THISCALL matDescGroupLoad(u8 *self, void *lg) {
  ext_440e10(self, lg);
  s32 n;
  vcall<void>(lg, 0x48, &n);
  for (s32 i = 0; i < n; ++i) {
    u32 id;
    vcall<void>(lg, 0x40, &id);
    void *m = vcall<void *>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x58, id);
    vcall<void>(*(void **)(self + 0x5c), 4, m);
  }
  return 1;
}
PCREG(455020, matDescGroupLoad);

// 0x656fe0, ZPrimControlGC::GetNumEntries(unsigned, unsigned): own slot 0xc(a) gives the entry. Entry word +2 == 0:
// kind 1, 2, 4, 8 -> word +0xe * dword +0x50; kind 16 -> dword +0x40; other kinds call the handler at 0x7003b0 twice
// (once for the bad kind, once on the shared error path). Word +2 != 0: the handler once. Returns the handler's EAX
// on the error paths (int3 when there is no handler; not exercised).
static u32 THISCALL primGetNumEntries(void *self, u32 a, u32 kind) {
  u8 *e = vcall<u8 *>(self, 0xc, a);
  typedef u32 (*hfn)();
  if (*(u16 *)(e + 2) == 0) {
    u32 k = kind - 1;
    if (k <= 0xf) {
      if (k == 0xf) return *(u32 *)(e + 0x40);
      if (k == 0 || k == 1 || k == 3 || k == 7) return (u32)*(u16 *)(e + 0xe) * *(u32 *)(e + 0x50);
    }
    hfn h = G(hfn, 0x7003b0);
    if (!h) asm volatile("int3");
    h();
  }
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  return h();
}
PCREG(656fe0, primGetNumEntries);

// 0x4b0ba0, CCutSequenceSoundEnvironment::Run(REFTAB*, REFTAB*): the engine dword at +0x40 is copied to +0x50 (skipped
// when they are the same address); the sound system (engine +0x1a9f) gets slot 0xcc([+0x64]); without one an error is
// logged (line 0xcc2).
static void THISCALL cutSoundEnvRun(u8 *self, void *, void *) {
  u8 *eng = G(u8 *, 0x70039c);
  if (self + 0x50 != eng + 0x40) {
    *(u32 *)(self + 0x50) = *(u32 *)(eng + 0x40);
    eng = G(u8 *, 0x70039c);
  }
  void *s = *(void **)(eng + 0x1a9f);
  if (s) {
    vcall<void>(s, 0xcc, *(u32 *)(self + 0x64));
    return;
  }
  void *k = logAt(0xcc2, 0x691edc);
  (*(sink2 *)(*(u8 **)k + 0x2c))(k, 0x69269c);
}
PCREG(4b0ba0, cutSoundEnvRun);
