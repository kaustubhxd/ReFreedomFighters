// batch0604.cpp - fresh-06 batch 4 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
// SEH-framed functions (fs:[0] chain, /GS cookie): the frame only matters while an exception unwinds; nothing in these
// bodies throws in the port (-fno-exceptions), and fs:[0] is back to its old value on return in both.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);       // __builtin_delete (cdecl)
extern "C" void *ext_41e290(u32 n);                  // __builtin_new (cdecl)
extern "C" void *ext_634d10(void *p, int c, u32 n);  // memset (cdecl)
extern "C" void *ext_634d22(void *d, const void *s, u32 n);  // memcpy (cdecl)

// 0x633eac (___scrt_uninitialize_crt per Ghidra; cdecl (a, b)): unless byte 0x7254b0 is set and b is nonzero,
// 0x549de0(a) runs twice (cdecl). Returns true.
extern "C" void ext_549de0(u32 a);
static u8 scrtUninitialize(u32 a, u8 b) {
  if (!G(u8, 0x7254b0) || !b) {
    ext_549de0(a);
    ext_549de0(a);
  }
  return 1;
}
PCREG(633eac, scrtUninitialize);

// 0x5fd120, ScriptEngine_t::recycle(Process_t*): when the list at this+0x18 lets it go (0x5fd240), the global script
// host (0x5fa630, [0x724270]) gets slot 0x24(p), [this+4] gets 0x5fd2a0(p); then a non-null p is destroyed (0x5f3b00)
// and freed (__builtin_delete(p, 0xad2)).
extern "C" u8 THISCALL ext_5fd240(void *lst, void *p);
extern "C" void *ext_5fa630();
extern "C" void THISCALL ext_5fd2a0(void *o, void *p);
extern "C" void THISCALL ext_5f3b00(void *p);
static void THISCALL scriptRecycle(u8 *self, void *p) {
  if (!ext_5fd240(self + 0x18, p)) return;
  vcall<void>(ext_5fa630(), 0x24, p);
  ext_5fd2a0(*(void **)(self + 4), p);
  if (p) {
    ext_5f3b00(p);
    ext_634273(p, 0xad2);
  }
}
PCREG(5fd120, scriptRecycle);

// 0x658ca0 (no map name; GUESS: CopyDataBlock of a geom-attached prim): base (0x610100); with +0x137 set, the block's
// geom (+8) gives a 0x24-byte matrix and a position (ZBaseGeom::GetMatPos) that go to own slot 0x12c with block+0x3c.
extern "C" void THISCALL ext_610100(void *self, void *db);
extern "C" void THISCALL ext_4db2c0(void *g, float *m, float *p);
static void THISCALL primCopyMatPos(u8 *self, u8 *b) {
  ext_610100(self, b);
  if (*(u32 *)(self + 0x137) == 0) return;
  float m[9], p[3];
  ext_4db2c0(*(void **)(b + 8), m, p);
  vcall<void>(self, 0x12c, m, p, b + 0x3c);
}
PCREG(658ca0, primCopyMatPos);

// 0x4247e0 (no map name; GUESS: RLE decode, stdcall (dst, end, src, unused)): each run starts with a signed word n;
// n > 0: memset(dst, next signed byte, n) and the source moves on by 1; else memcpy(dst, src, (s16)-n) and the source
// moves on by that much. Stops when dst reaches end. Returns the bytes written.
static u32 STDCALL rleDecode(u8 *dst, u8 *end, u8 *src, u32) {
  u8 *d = dst;
  if (d != end) {
    do {
      s16 w = *(s16 *)src;
      src += 2;
      s32 n, adv;
      if (w > 0) {
        n = w;
        ext_634d10(d, (s8)*src, (u32)n);
        adv = 1;
      } else {
        n = (s16)(u16)(-(s32)(u16)w);
        ext_634d22(d, src, (u32)n);
        adv = n;
      }
      d += n;
      src += adv;
    } while (d != end);
  }
  return (u32)(d - dst);
}
PCREG(4247e0, rleDecode);

// 0x63b6a0, ZDrawArrayBlocks<ZArrayBlock>::AllocBlock(): ([+0x1c] << 12) + 0x1010 bytes from the allocator at +0x14
// (slot 0); null: 0. Else the block header sits 0x10 below the first 4 KB boundary past the start (+0xfff): count
// +0x18 incremented (its low byte to +0x10), header +4 = raw pointer, +1 = 0, and each of the [+0x1c] pages gets the
// header pointer at page+4. Returns the header.
static u8 *THISCALL drawAllocBlock(u8 *self) {
  u32 sz = (*(u32 *)(self + 0x1c) << 12) + 0x1010;
  u8 *raw = vcall<u8 *>(*(void **)(self + 0x14), 0, sz);
  if (!raw) return 0;
  ++*(u32 *)(self + 0x18);
  u32 pg = ((u32)raw + 0x100f) & 0xfffff000u;
  u8 *hdr = (u8 *)(pg - 0x10);
  self[0x10] = self[0x18];
  *(u8 **)(hdr + 4) = raw;
  hdr[1] = 0;
  u32 q = pg + 4;
  for (u32 i = 0; i != *(u32 *)(self + 0x1c); ++i, q += 0x1000) *(u8 **)q = hdr;
  return hdr;
}
PCREG(63b6a0, drawAllocBlock);

// 0x4be8e0, 0x4c4ba0, 0x4c5460 (no map names; GUESS: factories): the render manager's +8 allocator slot 0x44 is called
// with the incoming ECX as its one argument; a non-null result is constructed (0x4bdaf0 ZMusicControl::ZMusicControl,
// 0x4c4930, 0x4c52f0). Returns the object (or null).
extern "C" void THISCALL ext_4bdaf0(void *p);
extern "C" void THISCALL ext_4c4930(void *p);
extern "C" void THISCALL ext_4c52f0(void *p);
static inline void *rmAlloc(u32 arg) {
  void *a = *(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  return vcall<void *>(a, 0x44, arg);
}
static void *THISCALL newMusicControl(u32 ecx) {
  void *p = rmAlloc(ecx);
  if (p) ext_4bdaf0(p);
  return p;
}
PCREG(4be8e0, newMusicControl);
static void *THISCALL new4c4930(u32 ecx) {
  void *p = rmAlloc(ecx);
  if (p) ext_4c4930(p);
  return p;
}
PCREG(4c4ba0, new4c4930);
static void *THISCALL new4c52f0(u32 ecx) {
  void *p = rmAlloc(ecx);
  if (p) ext_4c52f0(p);
  return p;
}
PCREG(4c5460, new4c52f0);

// 0x4d8ce0 (no map name; GUESS: holder ctor): a new 0x21-byte object built by 0x4e7dd0(arg) (null when the allocation
// fails) goes to +0, word +4 = 0. Returns this.
extern "C" void *THISCALL ext_4e7dd0(void *p, u32 a);
static void *THISCALL holderCtor(u8 *self, u32 a) {
  void *p = ext_41e290(0x21);
  void *o = p ? ext_4e7dd0(p, a) : 0;
  *(void **)self = o;
  *(u16 *)(self + 4) = 0;
  return self;
}
PCREG(4d8ce0, holderCtor);

// 0x48f9a0 (no map name; GUESS: lay out a 3-column grid): for i below [this+4], the engine's slot 0x190 gives a drawer
// whose slot 0x184 (cdecl: drawer, x, y, text) gets ((i % 3) * 45, i / 3 + 5, 0x679e6c).
static void THISCALL grid3Layout(u8 *self) {
  for (u32 i = 0; i != *(u32 *)(self + 4); ++i) {
    u8 *d = vcall<u8 *>(G(void *, 0x70039c), 0x190);
    typedef void (*f184)(void *, u32, u32, u32);
    f184 f = *(f184 *)(*(u8 **)d + 0x184);
    u32 q = i / 3;
    f(d, (i - q * 3) * 0x2d, q + 5, 0x679e6c);
  }
}
PCREG(48f9a0, grid3Layout);

// 0x4d2a20, CGlobalCom::EnumKeys(char*, int, unsigned): records start at [this+8] (size dword +0, flag byte +4, name
// length +5, name +0x11) up to [this+0xc] bytes; the idx-th flagged record's name is copied out with a terminator.
// A name that does not fit (length + 1 > cap) calls the handler at 0x7003b0 and is copied anyway (int3 when there is
// no handler; not exercised). Returns true when found.
static u8 THISCALL globalComEnumKeys(u8 *self, char *out, s32 cap, u32 idx) {
  u32 end = *(u32 *)(self + 0xc);
  u32 off = 0;
  if (!end) return 0;
  u8 *base = *(u8 **)(self + 8);
  do {
    u8 *e = base + off;
    off += *(u32 *)e;
    if (e[4]) {
      if (!idx) {
        if ((s32)(*(u32 *)(e + 5) + 1) > cap) {
          typedef void (*hfn)();
          hfn h = G(hfn, 0x7003b0);
          if (!h) asm volatile("int3");
          h();
        }
        ext_634d22(out, e + 0x11, *(u32 *)(e + 5));
        out[*(u32 *)(e + 5)] = 0;
        return 1;
      }
      --idx;
    }
  } while (off < end);
  return 0;
}
PCREG(4d2a20, globalComEnumKeys);

// 0x449ae0, ZOMNILIGHT::SetMultiplier(float) and 0x452e60, ZENVIRONMENT::SetMultiplier(float): own slot 0x238, then
// the light system ([[engine+0x1aa3]+0x18]) reads the light's record ([[this+8]+0x6c]) into a local (0x24 / 0x1c
// bytes; slot 0x80 / 0x8c), the multiplier goes to record +0x14, it is written back (slot 0x98 / 0xac), and own slot
// 0x220(1) runs.
static inline void *lightSys() { return *(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18); }
static void THISCALL omniSetMultiplier(u8 *self, u32 m) {
  vcall<void>(self, 0x238);
  u32 rec[9];
  vcall<void>(lightSys(), 0x80, *(u32 *)(*(u8 **)(self + 8) + 0x6c), rec);
  rec[5] = m;
  vcall<void>(lightSys(), 0x98, *(u32 *)(*(u8 **)(self + 8) + 0x6c), rec);
  vcall<void>(self, 0x220, 1u);
}
PCREG(449ae0, omniSetMultiplier);
static void THISCALL envSetMultiplier(u8 *self, u32 m) {
  vcall<void>(self, 0x238);
  u32 rec[7];
  vcall<void>(lightSys(), 0x8c, *(u32 *)(*(u8 **)(self + 8) + 0x6c), rec);
  rec[5] = m;
  vcall<void>(lightSys(), 0xac, *(u32 *)(*(u8 **)(self + 8) + 0x6c), rec);
  vcall<void>(self, 0x220, 1u);
}
PCREG(452e60, envSetMultiplier);

// 0x454da0, ZMaterialDescGroup::CopyData(const ZGEOM*): the list at +0x5c is cleared (slot 0xc); when the source's
// type (+0xc -> +0x23) is 0x1000f0 and it has a list, each item of the source list (iterator: slot 0x4c begin, slot
// 0x5c next, ends when the iterator's first dword is 0) is added (slot 4). Then ZGROUP::CopyData.
extern "C" void THISCALL ext_43f8c0(void *self, const void *src);
static void THISCALL matDescCopyData(u8 *self, u8 *src) {
  vcall<void>(*(void **)(self + 0x5c), 0xc);
  if (*(u32 *)(*(u8 **)(src + 0xc) + 0x23) == 0x1000f0 && *(void **)(src + 0x5c)) {
    u32 it[3];
    vcall<void>(*(void **)(src + 0x5c), 0x4c, it);
    u32 r = vcall<u32>(*(void **)(src + 0x5c), 0x5c, it);
    while (it[0]) {
      vcall<void>(*(void **)(self + 0x5c), 4, r);
      r = vcall<u32>(*(void **)(src + 0x5c), 0x5c, it);
    }
  }
  ext_43f8c0(self, src);
}
PCREG(454da0, matDescCopyData);

// 0x4a3360 (no map name; GUESS: destructor body, vtables 0x68fadc then 0x686874): the buffer at +0x48 is freed
// (__builtin_delete(p, 0xa)), +0x44 and +0x30 cleared, and the render manager's slot 0x34(this) unregisters it.
static void THISCALL dtor68fadc(u8 *self) {
  void *p = *(void **)(self + 0x48);
  *(u32 *)self = 0x68fadc;
  ext_634273(p, 0xa);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x34, self);
}
PCREG(4a3360, dtor68fadc);
