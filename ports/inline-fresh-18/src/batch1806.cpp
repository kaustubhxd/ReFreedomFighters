// batch1806.cpp - fresh-18 batch 6 (slice 18): zip compare, constructors and allocating factories, file size,
// UTF-16 class scanner, bone copy.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*cdeclLog2)(void *, u32);

extern "C" u8 THISCALL ext_4d6520(void *self, u32 name, void *hdr, void *pos);   // FsZip_t::findFile
extern "C" void THISCALL ext_51a960(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_51b530(void *self);
extern "C" u32 ext_62c640(u32 hi, u32 lo);                                      // cdecl
extern "C" void *ext_45c4f0(u32 size, u32 a);                                   // cdecl allocator
extern "C" void *ext_45c4b0(u32 size);                                          // cdecl allocator
extern "C" void THISCALL ext_43de40(void *self, u32 a, u32 b, u32 c);            // ZSTDOBJ::ZSTDOBJ
extern "C" void THISCALL ext_45c3a0(void *self, u32 a, u32 b, u32 c);            // ZGEOM::ZGEOM
extern "C" void THISCALL ext_4609b0(void *self);
extern "C" void *ext_41e290(u32 size);                                          // operator new, cdecl
extern "C" void THISCALL ext_603500(void *self, u32 n);                          // OpaqueUserType_t ctor
extern "C" void THISCALL ext_4cbe80(void *self, u32 s);                          // MYSTR::MYSTR(const char*)
extern "C" void THISCALL ext_4cbee0(void *self, void *o);                        // MYSTR::operator=
extern "C" void THISCALL ext_4cbec0(void *self);                                 // MYSTR::~MYSTR
extern "C" u32 FASTCALL ext_4ee0e0(u32 a, u32 b, u32 c, u32 d);
extern "C" u32 THISCALL ext_4ee1b0(void *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_469870(void *self);
extern "C" void THISCALL ext_4ccba0(void *self);                                 // REFTAB32::REFTAB32
extern "C" void THISCALL ext_659330(void *self, u32 n, u32 p);
extern "C" void *ext_634d22(void *d, const void *s, u32 n);                      // memcpy

// 0x4d5ba0 FsZip_t::Compare(const char*, const char*) [high]: both files found and their local headers agree on the
// dwords at +0xe and +0xa (GUESS CRC-32 and compressed size; the header buffers are 0x1c bytes apart in the frame).
static u8 THISCALL f4d5ba0(void *self, u32 a, u32 b) {
  u8 h1[0x1c], h2[0x1c];
  if (!ext_4d6520(self, a, h1, 0)) return 0;
  if (!ext_4d6520(self, b, h2, 0)) return 0;
  if (*(u32 *)(h1 + 0xe) != *(u32 *)(h2 + 0xe)) return 0;
  return *(u32 *)(h1 + 0xa) == *(u32 *)(h2 + 0xa);
}
PCREG(4d5ba0, f4d5ba0);

// 0x51af20 GUESS constructor (vtable 0x69f43c, base 0x51a960): resolves b through a(+0x15) slot 0x40 (in place) and
// stores its engine handle (slot 0x58) at +0x1c; registers through 0x51b530 while [0x701800] is 0.
static void *THISCALL f51af20(u8 *self, u8 *a, u32 b) {
  ext_51a960(self, (u32)a, b);
  *(u32 *)self = 0x69f43c;
  if (!G(u32, 0x701800)) ext_51b530(self);
  vcall<void>(*(void **)(a + 0x15), 0x40, &b);
  *(u32 *)(self + 0x1c) = vcall<u32>(engineObj9b(), 0x58, b);
  return self;
}
PCREG(51af20, f51af20);

// 0x427320 GUESS file size (map: ZSysFileGC::FileTimeToSysTime [medium], the body is a size query): unless flag is
// set, asks the archive (slots 0x130, 0x70, 0x10) first; else opens (slot 8), GetFileSize, logs a failure, closes
// (slot 0x1c).
typedef u32(STDCALL *getFileSizeFn)(u32, u32);
static u32 THISCALL f427320(void *self, u32 name, u32 flag) {
  if (!(u8)flag) {
    u32 h = vcall<u32>(self, 0x130, name);
    void *f = vcall<void *>(self, 0x70, h);
    if (f) {
      u32 r = vcall<u32>(f, 0x10, h);
      if (r != 0xffffffffu) return r;
    }
  }
  u32 fh = vcall<u32>(self, 8, name);
  if (!fh) return 0xffffffffu;
  u32 sz = (*(getFileSizeFn *)0x67608c)(fh, 0);
  if (sz == 0xffffffffu) {
    void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x6789ac, 0xb5);
    (*(cdeclLog2 *)(*(u8 **)lg + 0x2c))(lg, 0x678af8);
  }
  vcall<void>(self, 0x1c, fh);
  return sz;
}
PCREG(427320, f427320);

// 0x6279e0 GUESS UTF-16 (big-endian) scanner, cdecl: the first char must be class 0x18/0x19, then it runs over
// 0x18/0x19 chars until class 0x12 (returns 10, *out past it) or another class (returns 0, *out at it); -1 at end.
// Classes come from the table at enc+0x4c for chars < 0x100, else from 0x62c640(hi, lo).
static inline u32 cls6279e0(u8 *enc, const u8 *p) {
  return p[0] ? ext_62c640(p[0], p[1]) : enc[0x4c + p[1]];
}
static s32 f6279e0(u8 *enc, const u8 *p, const u8 *end, const u8 **out) {
  if (p == end) return -1;
  if (cls6279e0(enc, p) - 0x18 > 1) { *out = p; return 0; }
  for (p += 2; p != end; p += 2) {
    u32 c = cls6279e0(enc, p);
    if (c == 0x12) { *out = p + 2; return 10; }
    if (c - 0x18 > 1) { *out = p; return 0; }
  }
  return -1;
}
PCREG(6279e0, f6279e0);

// 0x5d87a0 GUESS factory (fastcall): 0x48-byte ZSTDOBJ subclass (vtable 0x6b5fc8), +0x20 and +0x44 cleared.
static void *FASTCALL f5d87a0(u32 a, u32 b, u32 c, u32 d) {
  u8 *o = (u8 *)ext_45c4f0(0x48, a);
  if (!o) return 0;
  ext_43de40(o, b, c, d);
  *(u32 *)o = 0x6b5fc8;
  *(u32 *)(o + 0x20) = 0;
  *(u32 *)(o + 0x44) = 0;
  return o;
}
PCREG(5d87a0, f5d87a0);

// 0x44a820 GUESS factory (fastcall): 0x30-byte ZGEOM subclass (vtable 0x67f874), member at +0x1c (0x4609b0), +0x18 = 0.
static void *FASTCALL f44a820(u32 a, u32 b, u32 c, u32 d) {
  u8 *o = (u8 *)ext_45c4f0(0x30, a);
  if (!o) return 0;
  ext_45c3a0(o, b, c, d);
  *(u32 *)o = 0x67f874;
  ext_4609b0(o + 0x1c);
  *(u32 *)(o + 0x18) = 0;
  return o;
}
PCREG(44a820, f44a820);

// 0x5f95e0 GUESS pool constructor: n pointers at +0 (count +4, used +8) and 1000 at +0xc (cap +0x10, used +0x14);
// new[] sizes saturate to 0xffffffff on overflow as MSVC emits.
static inline u32 newSize4(u32 n) {
  u64 m = (u64)n * 4;
  return (m >> 32) ? 0xffffffffu : (u32)m;
}
static void *THISCALL f5f95e0(u32 *self, u32 n) {
  self[1] = n;
  self[2] = 0;
  self[0] = (u32)ext_41e290(newSize4(n));
  self[4] = 1000;
  self[5] = 0;
  self[3] = (u32)ext_41e290(newSize4(1000));
  return self;
}
PCREG(5f95e0, f5f95e0);

// 0x601e20 CHostInterface::produceScriptEvent(ScriptEventFactory_t*, const char*, int) [high]: new 0x2a-byte event
// (vtable 0x6b97b4), named through its slot 0x50. A failed new crashes in the exe (null vtable read) as here.
static void *THISCALL f601e20(void *, u32 factory, u32 name, u32 n) {
  u8 *o = (u8 *)ext_41e290(0x2a);
  if (o) {
    ext_603500(o, n);
    *(u32 *)o = 0x6b97b4;
    *(u8 **)(o + 0x18) = o + 0xc;
    *(u32 *)(o + 0x1c) = 0;
    *(u32 *)(o + 0x20) = 0;
    *(u16 *)(o + 0x24) = 0;
    *(u32 *)(o + 0x26) = factory;
  }
  vcall<void>(o, 0x50, name);
  return o;
}
PCREG(601e20, f601e20);

// 0x421560 ZSysInterfaceGC::~ZSysInterfaceGC() [medium] (body: resets state and the name string at +0x2346).
static void THISCALL f421560(u8 *self) {
  self[0x2241] = 0;
  vcall<void>(self, 0x100, 0);
  u8 tmp[0x80];
  self[0x25ea] = 0;
  ext_4cbe80(tmp, 0x677f8c);
  ext_4cbee0(self + 0x2346, tmp);
  ext_4cbec0(tmp);
  self[0x25ea] = 1;
}
PCREG(421560, f421560);

// 0x4ee6a0 GUESS (fastcall): forwards to 0x4ee0e0(d, c, a, b) when d is set, else builds a 0xac-byte object
// (0x45c4b0, ctor 0x4ee1b0(c, a, b)).
static u32 FASTCALL f4ee6a0(u32 a, u32 b, u32 c, u32 d) {
  if (d) return ext_4ee0e0(d, c, a, b);
  void *o = ext_45c4b0(0xac);
  if (!o) return 0;
  return ext_4ee1b0(o, c, a, b);
}
PCREG(4ee6a0, f4ee6a0);

// 0x4acde0 GUESS constructor (vtable 0x68f1a0, geom base 0x469870) with three REFTAB32 at +0x6e, +0x11a, +0x1c6;
// a null this returns 0 (the exe tests it).
static void *THISCALL f4acde0(u8 *self) {
  if (!self) return 0;
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x68f1a0;
  ext_4ccba0(self + 0x6e);
  ext_4ccba0(self + 0x11a);
  ext_4ccba0(self + 0x1c6);
  return self;
}
PCREG(4acde0, f4acde0);

// 0x617360 GUESS lock (count +0x30): on the first lock sets up the bone block (0x659330 on +0x24) and copies n
// 36-byte entries from the engine's bone table into the target's buffer (created through its slot 4 when missing).
static void THISCALL f617360(u8 *self) {
  if ((*(u32 *)(self + 0x30))++ != 0) return;
  u8 *a = *(u8 **)(*(u8 **)(self + 4) + 8);
  u8 *s = *(u8 **)(self + 8);
  u32 n = *(u16 *)(a + 0xe);
  ext_659330(self + 0x24, n, *(u32 *)(s + 0xb9a8));
  u8 *t = *(u8 **)(*(u8 **)(s + 0xb9a4) + 0x13fa);
  u32 base = *(u32 *)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x20);
  if (!*(u32 *)(self + 0x28)) return;
  if (!*(u32 *)(t + 0x30)) *(u32 *)(t + 0x30) = vcall<u32>(t, 4, 0, 0);
  ext_634d22((void *)(*(u32 *)(t + 0x30) + *(u32 *)(self + 0x28) * 36), (void *)(*(u32 *)(a + 0x14) + base), n * 36);
}
PCREG(617360, f617360);
