// batch1910.cpp - fresh slice 19, batch 1910 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
// SEH frames and stack cookies of the exe are not ported (the state they leave is the same).
#include "ff.h"

extern "C" void THISCALL ext_4cbe50(u8 *s, u8 *o);                      // MYSTR::MYSTR(const MYSTR&) (hooked)
extern "C" u8 *ext_45c4f0(u32 n, u32 a);                                 // pool operator new (cdecl; hooked)
extern "C" void THISCALL ext_447640(u8 *self, u32 b, u32 c, u32 d);      // base constructor (hooked, ret 0xc)
extern "C" void THISCALL ext_469870(u8 *self);                           // base event constructor (hooked)
extern "C" void THISCALL ext_4e7160(u8 *p);                              // ZParamParticle::ZParamParticle (hooked)
extern "C" bool THISCALL ext_5626d0(u8 *self, u8 *l);                    // CBaseWindow::Load (hooked)
extern "C" void THISCALL ext_4f9680(u8 *snd, u32 set);                   // ZGui_Sound::PlaySound (hooked)
extern "C" void THISCALL ext_563750(u8 *self, u32 st, bool b);           // CBaseWindow::SetWindowStatus (hooked)
extern "C" u8 *THISCALL ext_48c4b0(u8 *self, u8 *ret, u32 name);         // ZEngineDataBase::CalcCacheFileName (hooked)
extern "C" u32 THISCALL ext_4cc1d0(u8 *s);                               // MYSTR text: mov eax, [ecx]; ret (exe code)
extern "C" void THISCALL ext_4cbec0(u8 *s);                              // MYSTR::~MYSTR (hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x57c870 (no GC name) copy constructor (const T &o) ret 4: MYSTR at +0 copied, then +0x80 .. +0xb2 (bytes +0xa0,
// +0xa5, +0xa6; words +0xa1, +0xa7, +0xab, +0xaf). Returns this.
static u8 *THISCALL copyCtor_57c870(u8 *self, u8 *o) {
  ext_4cbe50(self, o);
  for (u32 k = 0x80; k < 0xa0; k += 4) *(u32 *)(self + k) = *(u32 *)(o + k);
  self[0xa0] = o[0xa0];
  *(u32 *)(self + 0xa1) = *(u32 *)(o + 0xa1);
  self[0xa5] = o[0xa5];
  self[0xa6] = o[0xa6];
  *(u32 *)(self + 0xa7) = *(u32 *)(o + 0xa7);
  *(u32 *)(self + 0xab) = *(u32 *)(o + 0xab);
  *(u32 *)(self + 0xaf) = *(u32 *)(o + 0xaf);
  return self;
}
PCREG(57c870, copyCtor_57c870);

// 0x57f6b0 (no GC name) (no args): v = (int)(engine vt[0xbc]()->vt[0xa8]() * 20.0f [0x67da20]) (x87 multiply, stored as
// float, truncated); s = engine vt[0x190](); s slot 0x198 (cdecl: s, buf, fmt 0x6a8948, v) formats a 128-byte stack text
// that goes to (+0x180)->vt[0x378](buf).
typedef void (*fmt_t)(void *, char *, u32, s32);
static void THISCALL fn_57f6b0(u8 *self) {
  char buf[0x80];
  u8 *o = vcall<u8 *>(*(u8 **)0x70039cu, 0xbc);
  float f = vcall<float>(o, 0xa8);
  float m = (float)((long double)f * (long double)G(float, 0x67da20));
  s32 v = _mm_cvttss_si32(_mm_set_ss(m));
  u8 *s = vcall<u8 *>(*(u8 **)0x70039cu, 0x190);
  (*(fmt_t *)(*(u8 **)s + 0x198))(s, buf, 0x6a8948u, v);
  vcall<void>(*(u8 **)(self + 0x180), 0x378, (u32)buf);
}
PCREG(57f6b0, fn_57f6b0);

// 0x4528f0 (no GC name) fastcall (a, b; c, d) ret 8: o = pool new(0x24, a); with o: base 0x447640(b, c, d), vptr 0x681860,
// +0x18 = 0x3000, +0x1c = +0x20 = o (empty list). Returns o or 0.
static u8 *FASTCALL make_4528f0(u32 a, u32 b, u32 c, u32 d) {
  u8 *o = ext_45c4f0(0x24, a);
  if (!o) return 0;
  ext_447640(o, b, c, d);
  *(u32 *)o = 0x681860;
  *(u32 *)(o + 0x18) = 0x3000;
  *(u8 **)(o + 0x1c) = o;
  *(u8 **)(o + 0x20) = o;
  return o;
}
PCREG(4528f0, make_4528f0);

// 0x4a6270 (Ghidra: __static_initialization_and_destruction_0; an event constructor): base 0x469870, flag 0x20 at +4,
// +0x44 = 0, vptr 0x690040, ZParamParticle at +0x48, +0xf6 = 0, word +0x115 = RegisterZMsg(0x682e18, 0, 0x6900c4, 0x51).
static u8 *THISCALL ctor_4a6270(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x690040;
  ext_4e7160(self + 0x48);
  *(u32 *)(self + 0xf6) = 0;
  *(u16 *)(self + 0x115) = (u16)vcall<u32>(DB, 0x114, 0x682e18u, 0u, 0x6900c4u, 0x51u);
  return self;
}
PCREG(4a6270, ctor_4a6270);

// 0x570930 CSewerMenu::Load(ZLoadGame *l) ret 4: CBaseWindow::Load first (false returns false); bytes +0x1a0/+0x1a1/+0x1a2
// (slot 0x68), words +0x1b0/+0x1b4/+0x1b8/+0x1bc/+0x190 (slot 0x40); returns 1.
static bool THISCALL load_570930(u8 *self, u8 *l) {
  if (!ext_5626d0(self, l)) return false;
  vcall<void>(l, 0x68, (u32)(self + 0x1a0));
  vcall<void>(l, 0x68, (u32)(self + 0x1a1));
  vcall<void>(l, 0x68, (u32)(self + 0x1a2));
  vcall<void>(l, 0x40, (u32)(self + 0x1b0));
  vcall<void>(l, 0x40, (u32)(self + 0x1b4));
  vcall<void>(l, 0x40, (u32)(self + 0x1b8));
  vcall<void>(l, 0x40, (u32)(self + 0x1bc));
  vcall<void>(l, 0x40, (u32)(self + 0x190));
  return true;
}
PCREG(570930, load_570930);

// 0x561f70 CBaseWindow::Enter(): GUI sound 2; in status 3 or 5 (+0xdc): +0x64 = (float)engine->+0x30 / 1024,
// SetWindowStatus(status, false), byte +0x85 = 1, the two child windows (+0x4c, +0x50) get vt[0xbc](0), vt[0xd4](0), and
// the status becomes 6 (from 5) or 0.
static void THISCALL enter_561f70(u8 *self) {
  ext_4f9680((u8 *)0x700e24, 2);
  u32 st = *(u32 *)(self + 0xdc);
  if (st != 3 && st != 5) return;
  *(float *)(self + 0x64) = (float)*(s32 *)(*(u8 **)0x70039cu + 0x30) * G(float, 0x6785e4);
  ext_563750(self, st, false);
  self[0x85] = 1;
  if (*(u8 **)(self + 0x4c)) vcall<void>(*(u8 **)(self + 0x4c), 0xbc, 0u);
  if (*(u8 **)(self + 0x50)) vcall<void>(*(u8 **)(self + 0x50), 0xbc, 0u);
  vcall<void>(self, 0xd4, 0u);
  *(u32 *)(self + 0xdc) = *(u32 *)(self + 0xdc) == 5 ? 6 : 0;
}
PCREG(561f70, enter_561f70);

// 0x5fa4f0 OpaqueObjectSerialBuffer_t::toSerial(SerialInfo_t &si) ret 4: b = +4 (re-read after every call): si slot
// 0x2c(b->+0x14) and slot 0x3c for each of the b->+0x14 words at b->+0xc; si slot 0x2c(b->+8) and, for each of the b->+8
// objects at b->+0, obj->vt[0xc](si, this). (The exe's bounds assert inside the loops cannot fire.)
static void THISCALL toSerial_5fa4f0(u8 *self, u8 *si) {
  vcall<void>(si, 0x2c, *(u32 *)(*(u8 **)(self + 4) + 0x14));
  for (u32 i = 0; i < *(u32 *)(*(u8 **)(self + 4) + 0x14); i++)
    vcall<void>(si, 0x3c, (*(u32 **)(*(u8 **)(self + 4) + 0xc))[i]);
  vcall<void>(si, 0x2c, *(u32 *)(*(u8 **)(self + 4) + 8));
  for (u32 i = 0; i < *(u32 *)(*(u8 **)(self + 4) + 8); i++)
    vcall<void>((*(u8 ***)*(u8 **)(self + 4))[i], 0xc, (u32)si, (u32)self);
}
PCREG(5fa4f0, toSerial_5fa4f0);

// 0x490e70 ZEngineDataBase::GetSoundGraphData(void *buf, unsigned n) ret 8: file system [0x700394] slot 0x60(text of
// CalcCacheFileName(0x68d868), buf, n, 0, 0) (5 words; pushed before the text call); returns nothing.
static void THISCALL getSoundGraphData_490e70(u8 *self, u32 buf, u32 n) {
  alignas(4) u8 tmp[0x80];
  ext_48c4b0(self, tmp, 0x68d868);
  u8 *vt = *(u8 **)G(u8 *, 0x700394);
  u32 s = ext_4cc1d0(tmp);
  (*(void(THISCALL **)(u8 *, u32, u32, u32, u32, u32))(vt + 0x60))(G(u8 *, 0x700394), s, buf, n, 0, 0);
  ext_4cbec0(tmp);
}
PCREG(490e70, getSoundGraphData_490e70);
