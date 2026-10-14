// batch1002.cpp - fresh-10 batch 2: wrappers, destructors and small accessors (slice 10).
// Names from the name map; GUESS where it has none or the body does not show the name's meaning.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl)

// Debug log through [0x700390]: slot 0x20(file, line) returns a printer whose slot 0x2c is cdecl (printer, fmt...).
typedef void *(THISCALL *logpos_t)(void *, u32, u32);
static inline void *LogAt(u32 file, u32 line) {
  void *l = G(void *, 0x700390);
  return (*(logpos_t *)(*(u8 **)l + 0x20))(l, file, line);
}
typedef void (*logp1_t)(void *, u32);
typedef void (*logp2_t)(void *, u32, u32);

// 0x64f820 ZRender::BeginScene(): if inner.slot74() then inner.slot64(); returns true.
static bool THISCALL BeginScene(u8 *self) {
  if (vcall<bool>(*(void **)(self + 0xbd), 0x74)) vcall<void>(*(void **)(self + 0xbd), 0x64);
  return true;
}
PCREG(64f820, BeginScene);

// 0x6590a0 GUESS constructor: [this] = a; ZOffsetAlloc(1, a, 0x400) at this+4; returns this.
extern "C" void THISCALL ext_4ccdd0(void *self, u32, u32, u32);
static u8 *THISCALL Ctor6590a0(u8 *self, u32 a) {
  *(u32 *)self = a;
  ext_4ccdd0(self + 4, 1, a, 0x400);
  return self;
}
PCREG(6590a0, Ctor6590a0);

// 0x602ca0 RunTimeTypeLibrary_t::consume() (low): destroy and free the global library at 0x724694.
extern "C" void THISCALL ext_6025f0(void *self);
static void RttlConsume() {
  void *p = G(void *, 0x724694);
  if (p) {
    ext_6025f0(p);
    ext_634273(p, 0x1a);
    G(void *, 0x724694) = 0;
  }
}
PCREG(602ca0, RttlConsume);

// 0x6078e0 GUESS scalar deleting destructor: vtable 0x6b9f00, base dtor 0x64f530, delete size 0xa5 when flag & 1.
extern "C" void THISCALL ext_64f530(void *self);
static u8 *THISCALL SDtor6078e0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b9f00;
  ext_64f530(self);
  if (flags & 1) ext_634273(self, 0xa5);
  return self;
}
PCREG(6078e0, SDtor6078e0);

// 0x4cb120 ZScrollTexture::Load(ZLoadGame*): the argument is not read; flags &= ~0x40; GetInput then GetValues.
extern "C" void THISCALL ext_6352f0(void *self, u32 *db);
extern "C" void THISCALL ext_4cb030(void *self, u32 *db);
static bool THISCALL ScrollTextureLoad(u8 *self, void *) {
  u32 db = 0;
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_6352f0(self, &db);
  ext_4cb030(self, &db);
  return true;
}
PCREG(4cb120, ScrollTextureLoad);

// 0x5fa1e0 GUESS checked array read: hdr = [this+4]; idx >= hdr->count calls the assert hook [0x7003b0] (int3 if none).
typedef void (*hook_t)();
static u32 THISCALL ArrayGet(u8 *self, u32 idx) {
  u8 *hdr = *(u8 **)(self + 4);
  if (idx >= *(u32 *)(hdr + 8)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) asm volatile("int3");
    h();
  }
  return (*(u32 **)hdr)[idx];
}
PCREG(5fa1e0, ArrayGet);

// 0x655220 GUESS: sys.slotcc(); SetFocus(hwnd at this+0x133); this.slot88(1); SetCursor(0).
typedef u32(STDCALL *api1_t)(u32);
static u32 THISCALL Focus655220(u8 *self) {
  vcall<void>(G(void *, 0x70039c), 0xcc);
  G(api1_t, 0x676204)(*(u32 *)(self + 0x133));
  vcall<void>(self, 0x88, 1u);
  return G(api1_t, 0x67622c)(0);
}
PCREG(655220, Focus655220);

// Draw object: [[0x70039c]+0x190f].slot20().
static inline void *DrawObj() { return vcall<void *>(*(void **)(G(u8 *, 0x70039c) + 0x190f), 0x20); }

// 0x6563a0 GUESS: bytes = count * 68; if non-zero, draw.slot18(p, bytes).
static void THISCALL Free6563a0(u8 *, u32 p, u32 count) {
  u32 n = count * 68;
  if (n) vcall<void>(DrawObj(), 0x18, p, n);
}
PCREG(6563a0, Free6563a0);

// 0x656da0 ZPrimControlBase::SetPrimFrameNr(const ZBaseGeom*, float): entry(geom->id at +0x5a)->frame (+0x48) = f.
extern "C" u8 *THISCALL ext_63eab0(void *self, u32 id);
static void THISCALL SetPrimFrameNr(u8 *, u8 *geom, u32 fbits) {
  u16 id = *(u16 *)(geom + 0x5a);
  if (id) *(u32 *)(ext_63eab0(DrawObj(), id) + 0x48) = fbits;
}
PCREG(656da0, SetPrimFrameNr);

// 0x426620 GUESS (map: ZSysFileGC::ReadFrom, medium; the body takes one argument): SetCurrentDirectoryA(path);
// on failure logs at 0x6789ac line 0x15c with 0x678c34.
static u32 THISCALL SetDir426620(u8 *, u32 path) {
  u32 r = G(api1_t, 0x6760fc)(path);
  if (!r) {
    void *p = LogAt(0x6789ac, 0x15c);
    typedef u32 (*logp1r_t)(void *, u32);
    r = (*(logp1r_t *)(*(u8 **)p + 0x2c))(p, 0x678c34);   // EAX is what the printer returns
  }
  return r;
}
PCREG(426620, SetDir426620);

// 0x54baa0 GUESS: 0x54a0c0(this); this.slotb4(); log at 0x6a38e0 line 0x2b4 with 0x6a3a54.
extern "C" void THISCALL ext_54a0c0(void *self);
static void THISCALL F54baa0(u8 *self) {
  ext_54a0c0(self);
  vcall<void>(self, 0xb4);
  void *p = LogAt(0x6a38e0, 0x2b4);
  (*(logp1_t *)(*(u8 **)p + 0x2c))(p, 0x6a3a54);
}
PCREG(54baa0, F54baa0);

// 0x6014e0 CHostInterface::consumeOpaque(OpaqueType_t*): log at 0x6b9834 line 0x108 (0x69c6b0, 0x6b88c8), then the
// assert hook [0x7003b0] (int3 if none).
static u32 THISCALL ConsumeOpaque(u8 *, u32) {
  void *p = LogAt(0x6b9834, 0x108);
  (*(logp2_t *)(*(u8 **)p + 0x2c))(p, 0x69c6b0, 0x6b88c8);
  typedef u32 (*hookr_t)();
  hookr_t h = G(hookr_t, 0x7003b0);
  if (!h) asm volatile("int3");
  return h();
}
PCREG(6014e0, ConsumeOpaque);

// 0x4958e0 GUESS destructor body (the exe sets up an SEH frame around it): vtable 0x68e2e4, then 0x496db0(this).
extern "C" u32 THISCALL ext_496db0(void *self);
static u32 THISCALL Dtor4958e0(u8 *self) {
  *(u32 *)self = 0x68e2e4;
  return ext_496db0(self);
}
PCREG(4958e0, Dtor4958e0);

// 0x57f620 CSoundMenu::OnWindowClose(unsigned, bool): base OnWindowClose, then snd = slot84(),
// snd.slot350(0x10000, 0, [this+0x44]); returns false.
extern "C" void THISCALL ext_562e90(void *self, u32, u32);
static bool THISCALL SoundMenuOnWindowClose(u8 *self, u32 id, u32 b) {
  ext_562e90(self, id, b);
  void *snd = vcall<void *>(self, 0x84);
  vcall<void>(snd, 0x350, 0x10000u, 0u, *(u32 *)(self + 0x44));
  return false;
}
PCREG(57f620, SoundMenuOnWindowClose);

// 0x4cd1a0 ALLOCREF::~ALLOCREF() (scalar deleting): vtable 0x695b48; delete([this+4], 4); [this+8] deleted through its
// own slot 0 (flag 1); delete(this, 0x19) when flag & 1.
static u8 *THISCALL AllocRefDtor(u8 *self, u32 flags) {
  void *buf = *(void **)(self + 4);
  *(u32 *)self = 0x695b48;
  ext_634273(buf, 4);
  void *r = *(void **)(self + 8);
  if (r) vcall<void>(r, 0, 1u);
  if (flags & 1) ext_634273(self, 0x19);
  return self;
}
PCREG(4cd1a0, AllocRefDtor);
