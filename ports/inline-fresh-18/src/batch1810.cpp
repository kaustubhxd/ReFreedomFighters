// batch1810.cpp - fresh-18 batch 10 (slice 18): data block reads, menu open, light overlay, script message,
// picture draw, file name, constructors with message ids, sound init.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*voidfn)();
static inline void ffAssert() {
  voidfn h = G(voidfn, 0x7003b0);
  if (h) h(); else __builtin_debugtrap();
}
typedef void (*cdeclLog2)(void *, u32);
typedef void (*cdeclLog3)(void *, u32, u32);

extern "C" float THISCALL ext_4e5e80(void *db);                                  // DBREAD::operator float (st0)
extern "C" u32 THISCALL ext_4e5e60(void *db);                                    // DBREAD::operator unsigned int
extern "C" void THISCALL ext_565020(void *self, u32 id, u32 open);               // CFileWindow::OnWindowOpen
extern "C" void THISCALL ext_564600(void *self, u32 cmd);                        // CFileWindow::AsynchronCommand
extern "C" void THISCALL ext_565100(void *self, u32 st);                         // CFileWindow::SetStatus
extern "C" void THISCALL ext_56c6a0(void *self);                                 // CLoadMenu::SetupProfiles
extern "C" void THISCALL ext_56b460(void *self, u32 i);                          // CLoadMenu::DisplayIndex
extern "C" float FASTCALL ext_4dfda0(const float *v);                            // v2len (st0)
extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);
extern "C" void FASTCALL ext_4e0d40(float *d, const float *s, float k);          // vscalar
extern "C" void THISCALL ext_4cbe50(void *self, const void *o);                  // MYSTR::MYSTR(const MYSTR&)
extern "C" void THISCALL ext_4cbe80(void *self, u32 s);                          // MYSTR::MYSTR(const char*)
extern "C" void THISCALL ext_4cc2c0(void *self, const void *o);                  // MYSTR::operator+=
extern "C" void THISCALL ext_4cbec0(void *self);                                 // MYSTR::~MYSTR
extern "C" void THISCALL ext_469870(void *self);

// 0x633910: CRT float -> unsigned conversion taking its value in xmm0 (called, not reimplemented).
static inline u32 crtFtoui(float t) {
  u32 r;
  asm volatile("call *%[f]"
               : "=a"(r), "+Yz"(t)
               : [f] "S"(0x633910u)
               : "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return r;
}

// 0x4ca160 ZDiscoMove::CopyEventDataBlock(DBREAD&) [high]: six positions scaled by 0x67da04 (x87 product, stored as
// float), three plain floats, a flag (nonzero word) and a word.
static inline float scaled(void *db) { return (float)((double)ext_4e5e80(db) * (double)G(float, 0x67da04)); }
static void THISCALL f4ca160(u8 *self, void *db) {
  *(float *)(self + 0x6c) = scaled(db);
  float y = scaled(db);
  *(u32 *)(self + 0x74) = 0;
  *(float *)(self + 0x70) = y;
  *(float *)(self + 0x78) = scaled(db);
  y = scaled(db);
  *(u32 *)(self + 0x80) = 0;
  *(float *)(self + 0x7c) = y;
  *(float *)(self + 0x84) = scaled(db);
  y = scaled(db);
  *(u32 *)(self + 0x8c) = 0;
  *(float *)(self + 0x88) = y;
  *(float *)(self + 0x90) = ext_4e5e80(db);
  *(float *)(self + 0x94) = ext_4e5e80(db);
  *(float *)(self + 0x98) = ext_4e5e80(db);
  u32 f = ext_4e5e60(db);
  *(u32 *)(self + 0x9d) = ext_4e5e60(db);
  self[0x9c] = f != 0;
}
PCREG(4ca160, f4ca160);

// 0x56c5a0 CLoadMenu::OnWindowOpen(unsigned int, bool) [high]: on open, keeps the list's slot 0x34 value (+0xcea)
// and runs the pending action of mode +0xcee (jump table 0x56c680); on close in mode 1 rebuilds the profile list.
static u8 THISCALL f56c5a0(u8 *self, u32 id, u32 open) {
  ext_565020(self, id, open);
  if ((u8)open) {
    *(u32 *)(self + 0xcea) = vcall<u32>(*(void **)(self + 0xc5e), 0x34);
    switch (*(u32 *)(self + 0xcee)) {
    case 0: ext_564600(self, 8); break;
    case 1:
    case 2: ext_564600(self, 1); break;
    case 3:
      if ((u8)vcall<u32>(*(void **)(self + 0xc5e), 0x3c)) ext_564600(self, 8);
      else ext_564600(self, 0);
      break;
    case 4: ext_565100(self, 0x15); break;
    case 5: ext_565100(self, 0x18); break;
    }
    return 0;
  }
  if (*(u32 *)(self + 0xcee) == 1) {
    ext_56c6a0(self);
    ext_56b460(self, *(u32 *)(self + 0xce2));
  }
  vcall<void>(self, 0x104);
  return 0;
}
PCREG(56c5a0, f56c5a0);

// 0x47ff20 ZLightOverlay::CalcTrans(ZCAMERA*, const float*) const [medium]: alpha from the 2D distance over the
// camera's projected half-size (slot 0x274 of {0.5, -0.5, 0}) plus +0x1c: 0 beyond far (+0x20), 255 inside near
// (+0x24), else (1 - (r - near) / (far - near)) * 255 through the CRT conversion.
static u32 THISCALL f47ff20(u8 *self, void *cam, const float *pos) {
  float out[3], in[3];
  in[0] = 0.5f;
  in[1] = -0.5f;
  in[2] = 0.0f;
  out[2] = pos[2];
  vcall<void>(cam, 0x274, out, in);
  float m = out[0] < out[1] ? out[0] : out[1];
  float d = m + *(float *)(self + 0x1c);
  float r = (float)((double)ext_4dfda0(pos) / (double)d);
  float far = *(float *)(self + 0x20);
  if (r > far) return 0;
  float nr = *(float *)(self + 0x24);
  if (nr > r) return 0xff;
  float t = (G(float, 0x678858) - (r - nr) / (far - nr)) * G(float, 0x68af18);
  return crtFtoui(t);
}
PCREG(47ff20, f47ff20);

// 0x509c20 GUESS script call: sends a registered message (engine db slot 0x114(name, 0, 0x69d214, 0xb1); name from
// parameter 0 as type 3 char* or type 4 string object slot 0x34) to every geom of the group (+0xc)->+0x18 through
// the group's SendCommand slot 0x12c(handle, msg, 0).
static void THISCALL f509c20(u8 *self, u8 *prm) {
  u8 *p = (u8 *)ext_5003d0(*(void **)(prm + 4), 0);
  u32 name;
  if (p[4] == 3) name = *(u32 *)p;
  else if (p[4] == 4) name = vcall<u32>(*(void **)p, 0x34);
  else {
    void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x69c8e0, 0x111);
    (*(cdeclLog3 *)(*(u8 **)lg + 0x2c))(lg, 0x69c6b0, 0x69c9b0);
    ffAssert();
    name = 0;
  }
  u32 msg = (u16)vcall<u32>(engineObj9b(), 0x114, name, 0, 0x69d214, 0xb1);
  void *t = *(void **)(*(u8 **)(self + 0xc) + 0x18);
  if (!t) return;
  u32 it[3];
  vcall<void>(t, 0x4c, it);
  u32 x = vcall<u32>(*(void **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, it);
  while (it[0]) {
    vcall<void>(*(void **)(self + 0xc), 0x12c, x, msg, 0);
    x = vcall<u32>(*(void **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, it);
  }
}
PCREG(509c20, f509c20);

// 0x45a720 ZPICOBJ::Draw(ZDrawBuffer*, ZCAMERA*, const float*, const float*) [high]: draws the picture with a 4x3
// matrix {m.x * sx, m.y * sy, m.z * sz, pos * |s|} (s = +0x18..+0x20, pos = [+8]+0x30) via buffer slot 0x30([+8], mat, col, 0xff).
static void THISCALL f45a720(u8 *self, void *buf, void *, const float *m, u32 col) {
  float sx = *(float *)(self + 0x18), sy = *(float *)(self + 0x1c), sz = *(float *)(self + 0x20);
  float len = (float)crt::sqrt((double)(sx * sx + sy * sy + sz * sz));
  float mat[12];
  ext_4e0d40(mat + 9, (float *)(*(u8 **)(self + 8) + 0x30), len);
  ext_4e0d40(mat + 6, m + 6, *(float *)(self + 0x18));
  ext_4e0d40(mat + 3, m + 3, *(float *)(self + 0x1c));
  ext_4e0d40(mat, m, *(float *)(self + 0x20));
  vcall<void>(buf, 0x30, *(u32 *)(self + 8), mat, col, 0xff);
}
PCREG(45a720, f45a720);

// 0x4266a0 ZSysFileGC::ConvertFileNameFromZipToHD(const char*) [high] (stdcall, MYSTR returned through out):
// out = engine root (+0x123) + "\x67856c" + name.
static void *STDCALL f4266a0(u8 *out, u32 name) {
  ext_4cbe50(out, G(u8 *, 0x70039c) + 0x123);
  u8 tmp[0x80];
  ext_4cbe80(tmp, 0x67856c);
  ext_4cc2c0(out, tmp);
  ext_4cbec0(tmp);
  ext_4cbe80(tmp, name);
  ext_4cc2c0(out, tmp);
  ext_4cbec0(tmp);
  return out;
}
PCREG(4266a0, f4266a0);

// 0x572360 CSubtitle::CSubtitle() [high]: four message ids (0x10..0x13 of 0x6a8a10) in the words +0x48..+0x4e.
static void *THISCALL f572360(u8 *self) {
  static const u32 names[4] = {0x692668, 0x6a8a38, 0x6a8a48, 0x6a8a5c};
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6a898c;
  for (u32 i = 0; i < 4; i++)
    *(u16 *)(self + 0x48 + 2 * i) = (u16)vcall<u32>(engineObj9b(), 0x114, names[i], 0, 0x6a8a10, 0x10 + i);
  return self;
}
PCREG(572360, f572360);

// 0x5378a0 ZDllSound::Initialize() [high]: message id 0x100 (+0x50a7), the three volume levels from the engine's
// options object (engine slot 0xbc; slots 0x7c/0x84/0x8c into own slot 0x104(i, v)), the speaker setting (slot 0x5c,
// as float at +0x87), then own slot 0x1f8 decides +0x50ba or logs a failure.
static void THISCALL f5378a0(u8 *self) {
  G(u8, 0x711b70) = 0;
  self[0xc] = 0;
  *(u16 *)(self + 0x50a7) = (u16)vcall<u32>(engineObj9b(), 0x114, 0x69f024, 0, 0x6a1e2c, 0x100);
  void *o = vcall<void *>(G(void *, 0x70039c), 0xbc);
  if (o) {
    vcall<void>(self, 0x104, 0, vcall<u32>(o, 0x7c, 0));
    vcall<void>(self, 0x104, 1, vcall<u32>(o, 0x84, 0));
    vcall<void>(self, 0x104, 2, vcall<u32>(o, 0x8c, 0));
    *(float *)(self + 0x87) = (float)(s32)vcall<u32>(o, 0x5c, 0x67a048, 3);
  }
  if ((u8)vcall<u32>(self, 0x1f8)) {
    self[0x50ba] = 1;
    return;
  }
  void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x6a1e2c, 0x117);
  (*(cdeclLog2 *)(*(u8 **)lg + 0x2c))(lg, 0x6a1e5c);
}
PCREG(5378a0, f5378a0);
