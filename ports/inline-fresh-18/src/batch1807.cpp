// batch1807.cpp - fresh-18 batch 7 (slice 18): factories, list append, light notify, loaders, small constructors.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*voidfn)();
static inline void ffAssert() {
  voidfn h = G(voidfn, 0x7003b0);
  if (h) h(); else __builtin_debugtrap();
}
typedef void (*cdeclLog3)(void *, u32, u32);

extern "C" void *ext_45c4b0(u32 size);                                          // cdecl allocator
extern "C" void *ext_45c4f0(u32 size, u32 a);                                   // cdecl allocator
extern "C" u32 FASTCALL ext_4528f0(u32 a, u32 b, u32 c, u32 d);
extern "C" void THISCALL ext_447640(void *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_5ec5a0(void *self, u32 n);                          // CSprite3D::SetDrawCount
extern "C" void *ext_41e290(u32 size);                                          // operator new, cdecl
extern "C" void *ext_634d22(void *d, const void *s, u32 n);                      // memcpy
extern "C" void THISCALL ext_562440(void *self);                                 // CBaseWindow::Init
extern "C" void THISCALL ext_57dd10(void *self);
extern "C" void THISCALL ext_4db500(void *self, void *pos);                      // ZBaseGeom::GetPos
extern "C" void FASTCALL ext_43e8e0(void *out, const void *a, const void *b);
extern "C" void THISCALL ext_63ef90(void *self, void *e);                        // ZDrawBase::LightEnter
extern "C" void THISCALL ext_4db6c0(void *self, void *a, void *b);               // ZBaseGeom::GetRootTM
extern "C" u32 THISCALL ext_4ce7b0(void *self);                                  // ZAllocIndex::New
extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);
extern "C" void THISCALL ext_5002f0(void *self, u32 v);
extern "C" void THISCALL ext_43de40(void *self, u32 a, u32 b, u32 c);            // ZSTDOBJ::ZSTDOBJ
extern "C" void THISCALL ext_45c3a0(void *self, u32 a, u32 b, u32 c);            // ZGEOM::ZGEOM
extern "C" void ext_4690b0(void *p, u32 v);                                     // cdecl
extern "C" u32 FASTCALL ext_4f42f0(u32 a, u32 b, u32 c, u32 d);
extern "C" u32 THISCALL ext_4ee1b0(void *self, u32 a, u32 b, u32 c);
extern "C" u32 THISCALL ext_4cca60(void *self, u32 a, u32 b);                    // LINKREFTAB::LINKREFTAB
extern "C" u32 THISCALL ext_4d4c90(void *self, u32 a, u32 b);
extern "C" void *THISCALL ext_48c4b0(void *self, void *out, u32 name);           // CalcCacheFileName (MYSTR out)
extern "C" u32 THISCALL ext_4cc1d0(void *self);                                  // MYSTR::c_str (returns [this], pops 0)
extern "C" void THISCALL ext_4cbec0(void *self);                                 // MYSTR::~MYSTR
extern "C" void *THISCALL ext_6014a0(void *self, u32 size);                      // CHostInterface::alloc

// 0x452a20 GUESS (fastcall): forwards to 0x4528f0(d, c, a, b) when d is set, else builds a 0x24-byte object
// (ctor 0x447640(c, a, b), vtable 0x681860, +0x18 = 0x3000, +0x1c/+0x20 = self as an empty list).
static u32 FASTCALL f452a20(u32 a, u32 b, u32 c, u32 d) {
  if (d) return ext_4528f0(d, c, a, b);
  u8 *o = (u8 *)ext_45c4b0(0x24);
  if (!o) return 0;
  ext_447640(o, c, a, b);
  *(u32 *)o = 0x681860;
  *(u32 *)(o + 0x18) = 0x3000;
  *(u8 **)(o + 0x1c) = o;
  *(u8 **)(o + 0x20) = o;
  return (u32)o;
}
PCREG(452a20, f452a20);

// 0x5a58a0 GUESS: SetDrawCount(0) on the twelve sprites at +0x5f8..+0x624.
static void THISCALL f5a58a0(u8 *self) {
  for (u32 o = 0x5f8; o <= 0x624; o += 4) ext_5ec5a0(*(void **)(self + o), 0);
}
PCREG(5a58a0, f5a58a0);

// 0x4d16e0 GUESS: appends a 0x14-byte node {owner, prev, next, copy of name, size} to the list at +0x18/+0x1c.
static void THISCALL f4d16e0(u8 *self, const char *name) {
  u32 *n = (u32 *)ext_41e290(0x14);
  if (!n) return;
  u32 len = 0;
  while (name[len]) len++;
  u32 size = len + 1;
  void *b = ext_41e290(size);
  n[3] = (u32)b;
  ext_634d22(b, name, size);
  n[4] = size;
  n[0] = (u32)self;
  n[1] = *(u32 *)(self + 0x1c);
  n[2] = 0;
  u32 *last = *(u32 **)(self + 0x1c);
  if (last) last[2] = (u32)n;
  else *(u32 **)(self + 0x18) = n;
  *(u32 **)(self + 0x1c) = n;
}
PCREG(4d16e0, f4d16e0);

// 0x57d8a0 GUESS window Init: aims the two child geoms (slot 0x70 of +0x310 and +0x314) along the offset between
// the window anchor (+0x34b) and the geom of +0x54 (0x43e8e0), the second with x and y negated (sign mask 0x67af40).
static void THISCALL f57d8a0(u8 *self) {
  ext_562440(self);
  ext_57dd10(self);
  u8 *p = self + 0x34b;
  ext_4db500(*(void **)(*(u8 **)(self + 0x310) + 8), p);
  u32 v[3], m[3];
  ext_4db500(*(void **)(*(u8 **)(self + 0x54) + 8), v);
  ext_43e8e0(m, p, v);
  vcall<void>(*(void **)(self + 0x310), 0x70, m);
  v[0] ^= G(u32, 0x67af40);
  v[1] ^= G(u32, 0x67af40);
  vcall<void>(*(void **)(self + 0x314), 0x70, v);
}
PCREG(57d8a0, f57d8a0);

// 0x63f220 ZDrawBase::OnLightNotify(ZBaseGeom*) [high]: finds or creates the light's draw entry (index in the
// geom's word +0x5a, table +0x68) and enters it unless flag 1 of byte +5 is set.
static void *THISCALL f63f220(u8 *self, u8 *geom) {
  u16 idx = *(u16 *)(geom + 0x5a);
  if (idx) {
    u8 *e = (*(u8 ***)(self + 0x68))[idx & 0xfff];
    if (!(e[5] & 1)) ext_63ef90(self, e);
    return e;
  }
  u8 *e = vcall<u8 *>(*(void **)(self + 0x230), 8);
  if (!e) return 0;
  *(u8 **)(e + 0x38) = geom;
  ext_4db6c0(geom, e + 8, e + 0x2c);
  u32 k = (ext_4ce7b0(self + 0xb990) + 1) & 0xfff;
  if (!k) ffAssert();
  (*(u8 ***)(self + 0x68))[k] = e;
  *(u16 *)(geom + 0x5a) = (u16)k;
  ext_63ef90(self, e);
  return e;
}
PCREG(63f220, f63f220);

// 0x555c60 GUESS script call (OpaqueCallParameters_t&): result = flag 0x1000 of the geom's (+8)->+0x3c for the handle
// parameter 0 (type byte 0 or 1, else logged and asserted), or 0 when the handle resolves to nothing.
static void THISCALL f555c60(void *, u8 *prm) {
  u8 *p = (u8 *)ext_5003d0(*(void **)(prm + 4), 0);
  u8 t = p[4];
  if (t != 0 && t != 1) {
    void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x69c8e0, 0x104);
    (*(cdeclLog3 *)(*(u8 **)lg + 0x2c))(lg, 0x69c6b0, 0x69c938);
    ffAssert();
  }
  u8 *h = vcall<u8 *>(engineObj9b(), 0x58, *(u32 *)p);
  u32 v = h ? *(u32 *)(*(u8 **)(h + 8) + 0x3c) & 0x1000 : 0;
  ext_5002f0(ext_5003d0(*(void **)(prm + 8), 0), v);
}
PCREG(555c60, f555c60);

// 0x5734e0 GUESS ZSTDOBJ factory (fastcall): 0x2c bytes, vtable 0x6a8d30, +0x18..+0x28 cleared.
static void *FASTCALL f5734e0(u32 a, u32 b, u32 c, u32 d) {
  u8 *o = (u8 *)ext_45c4f0(0x2c, a);
  if (!o) return 0;
  ext_43de40(o, b, c, d);
  *(u32 *)o = 0x6a8d30;
  *(u32 *)(o + 0x28) = 0;
  *(u32 *)(o + 0x18) = 0;
  *(u32 *)(o + 0x1c) = 0;
  *(u32 *)(o + 0x20) = 0;
  *(u32 *)(o + 0x24) = 0;
  return o;
}
PCREG(5734e0, f5734e0);

// 0x5d60e0 CLensFlareControl::~CLensFlareControl() [medium] (scalar-deleting form): unregisters (engine slot 0x34);
// with flag 1 it asserts unless flag 4 is set, which calls 0x4690b0(this, 0x7f) instead. Nothing is freed.
static void *THISCALL f5d60e0(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(engineObj9b(), 0x34, self);
  if (flags & 1) {
    if (!(flags & 4)) {
      ffAssert();
      return self;
    }
    ext_4690b0(self, 0x7f);
  }
  return self;
}
PCREG(5d60e0, f5d60e0);

// 0x446fe0 GUESS ZGEOM factory (fastcall): 0x24 bytes, +0x18 = 0, flag 1 of +0x14 when engine db byte +0xbad is
// set; final vtable 0x67e9e0 (0x67dc30 before).
static void *FASTCALL f446fe0(u32 a, u32 b, u32 c, u32 d) {
  u8 *o = (u8 *)ext_45c4f0(0x24, a);
  if (!o) return 0;
  ext_45c3a0(o, b, c, d);
  *(u32 *)o = 0x67dc30;
  *(u32 *)(o + 0x18) = 0;
  if (engineObj9b()[0xbad]) *(u32 *)(o + 0x14) |= 1;
  *(u32 *)o = 0x67e9e0;
  return o;
}
PCREG(446fe0, f446fe0);

// 0x4f4460 GUESS (fastcall): forwards to 0x4f42f0(d, c, a, b) when d is set, else builds a 0xb4-byte object
// (ctor 0x4ee1b0(c, a, b), vtable 0x699664, +0xac/+0xb0 cleared).
static u32 FASTCALL f4f4460(u32 a, u32 b, u32 c, u32 d) {
  if (d) return ext_4f42f0(d, c, a, b);
  u8 *o = (u8 *)ext_45c4b0(0xb4);
  if (!o) return 0;
  ext_4ee1b0(o, c, a, b);
  *(u32 *)o = 0x699664;
  *(u32 *)(o + 0xac) = 0;
  *(u32 *)(o + 0xb0) = 0;
  return (u32)o;
}
PCREG(4f4460, f4f4460);

// 0x435920 ZSysFile::UseBig(CHUNKFILE*, const char*) [low]: creates the table at +4 on first use (LINKREFTAB(4, 1))
// and adds a new 0x15-byte entry (0x4d4c90(a, b)) through its slot 0x84.
static u8 THISCALL f435920(u8 *self, u32 a, u32 b) {
  if (!*(u32 *)(self + 4)) {
    void *t = ext_41e290(0x28);
    *(u32 *)(self + 4) = t ? ext_4cca60(t, 4, 1) : 0;
  }
  void *n = ext_41e290(0x15);
  u32 e = n ? ext_4d4c90(n, a, b) : 0;
  vcall<void>(*(void **)(self + 4), 0x84, e);
  return 1;
}
PCREG(435920, f435920);

// 0x490d20 ZEngineDataBase::GetSoundData(void*, unsigned int) [medium]: writes the data to the cache file
// (0x700394 slot 0x60(name, p, n, 0, 0); the four words are pushed before the c_str call 0x4cc1d0, which pops none),
// then calls own slot 0x90(2, 0, 0.57f) and drops its float.
static void THISCALL f490d20(void *self, u32 p, u32 n) {
  u8 tmp[0x80];
  ext_48c4b0(self, tmp, 0x68d854);
  void *db = G(void *, 0x700394);
  u32 r = ext_4cc1d0(tmp);
  vcall<void>(db, 0x60, r, p, n, 0u, 0u);
  (void)vcall<float>(self, 0x90, 2u, 0u, 0x3f11eb85u);
  ext_4cbec0(tmp);
}
PCREG(490d20, f490d20);

// 0x5bc0a0 ZFFCareTaker_C03A::Load(ZLoadGame*) [high]
static u8 THISCALL f5bc0a0(u8 *self, void *lg) {
  void *arg = lg;
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(lg, 0x40, &arg);
  *(u32 *)(self + 0x48) = vcall<u32>(engineObj9b(), 0x58, arg);
  vcall<void>(lg, 0x68, self + 0x4c);
  vcall<void>(lg, 0x50, self + 0x4d);
  vcall<void>(lg, 0x40, self + 0x51);
  vcall<void>(lg, 0x40, self + 0x55);
  vcall<void>(lg, 0x40, self + 0x5d);
  vcall<void>(lg, 0x40, self + 0x59);
  void *x = vcall<void *>(engineObj9b(), 0x138);
  // engine db slot 0x4c takes one word (as at 0x4fa720); the 0x10 pushed before it is slot 0x60's third word
  // (name, value, size), the shape 0x49f5a0 pushes directly.
  u32 y = vcall<u32>(engineObj9b(), 0x4c, *(u32 *)(self + 0x44));
  vcall<void>(x, 0x60, 0x6b2cd8, y, 0x10);
  return 1;
}
PCREG(5bc0a0, f5bc0a0);

// 0x5f9720 GUESS constructor: 10 pointers at +0 (count +4, used +8), an 8-byte CHostInterface buffer at +0xc..+0x14
// (first byte cleared; the exe writes it again without the null test), +0x18 = 0.
static void *THISCALL f5f9720(u32 *self) {
  self[1] = 10;
  self[2] = 0;
  self[0] = (u32)ext_41e290(40);
  u32 *v = self + 3;
  v[0] = v[1] = v[2] = 0;
  u8 *a = (u8 *)ext_6014a0(v, 8);
  v[0] = (u32)a;
  v[1] = (u32)a;
  v[2] = (u32)a + 8;
  *a = 0;
  self[6] = 0;
  return self;
}
PCREG(5f9720, f5f9720);
