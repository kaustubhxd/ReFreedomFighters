// batch1909.cpp - fresh slice 19, batch 1909 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
// SEH frames and stack cookies of the exe are not ported (the state they leave is the same).
#include "ff.h"

extern "C" u8 *THISCALL ext_48c4b0(u8 *self, u8 *ret, u32 name);  // ZEngineDataBase::CalcCacheFileName (MYSTR by value; hooked)
extern "C" u32 THISCALL ext_4cc1d0(u8 *s);                         // MYSTR text pointer: mov eax, [ecx]; ret (runs as exe code)
extern "C" void THISCALL ext_4cbec0(u8 *s);                        // MYSTR::~MYSTR (hooked)
extern "C" u32 VECTORCALL ext_633910(float x);                     // CRT float -> unsigned helper, runs as exe code
extern "C" void THISCALL ext_5ed170(u8 *self, u8 *s);              // CSprite2D::Save (hooked)
extern "C" u32 *THISCALL ext_5003d0(u8 *arr, u32 i);               // parameter array element (hooked)
extern "C" u32 THISCALL ext_506040(u32 *p);                        // parameter as string (hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x490470 ZEngineDataBase::GetGeomFilesSize() and its two siblings 0x4906f0 / 0x490830 (no GC names): the file system
// [0x700394] slot 0x30(text, 0) on the text of CalcCacheFileName(name) (names 0x68d864 / 0x68d83c / 0x68d840); the
// temporary MYSTR is destroyed after the call. The `push 0` before 0x4cc1d0 is slot 0x30's second argument: 0x4cc1d0 is
// `mov eax, [ecx]; ret` and pops nothing (first spec run stubbed it with ret 4: wrong, corrected before counting).
static inline u32 cacheFileSize(u8 *self, u32 name) {
  alignas(4) u8 tmp[0x80];
  ext_48c4b0(self, tmp, name);
  u8 *fs = G(u8 *, 0x700394);
  u8 *vt = *(u8 **)fs;
  u32 s = ext_4cc1d0(tmp);
  u32 r = (*(u32(THISCALL **)(u8 *, u32, u32))(vt + 0x30))(G(u8 *, 0x700394), s, 0);
  ext_4cbec0(tmp);
  return r;
}
static u32 THISCALL getGeomFilesSize_490470(u8 *self) { return cacheFileSize(self, 0x68d864); }
PCREG(490470, getGeomFilesSize_490470);
static u32 THISCALL fileSize_4906f0(u8 *self) { return cacheFileSize(self, 0x68d83c); }
PCREG(4906f0, fileSize_4906f0);
static u32 THISCALL fileSize_490830(u8 *self) { return cacheFileSize(self, 0x68d840); }
PCREG(490830, fileSize_490830);

// 0x610070 (no GC name) (float v) ret 4: stores v at +0x14f2; render state 0x2f on the device at +0x1377 (COM slot 0xc8):
// 0 for v == 0 or v == 1, 0x10 for v == 0.99 [0x680140], otherwise min(15, ftou((1 - v) * 255 / 0.04 + 0.5)).
typedef void(STDCALL *rs_t)(u8 *, u32, u32);
static void THISCALL setFog_610070(u8 *self, float v) {
  u32 lvl = 0;
  *(float *)(self + 0x14f2) = v;
  if (v != G(float, 0x6785d0) && v != G(float, 0x678858)) {
    if (v == G(float, 0x680140)) lvl = 0x10;
    else {
      float x = G(float, 0x678858) - v;
      x = x * G(float, 0x68af18);
      x = x / G(float, 0x686080);
      x = x + G(float, 0x67a6ac);
      lvl = ext_633910(x);
      if (lvl > 0xf) lvl = 0xf;
    }
  }
  u8 *dev = *(u8 **)(self + 0x1377);
  (*(rs_t *)(*(u8 **)dev + 0xc8))(dev, 0x2f, lvl);
}
PCREG(610070, setFog_610070);

// 0x5eda70 CSpriteBorder2D::Save(ZSaveGame *s) ret 4: CSprite2D::Save, floats +0xd7 / +0xdb (slot 0x4c), words +0xdf .. +0xeb
// (slot 0x3c), words +0xef / +0xf3 (slot 0x44).
static void THISCALL save_5eda70(u8 *self, u8 *s) {
  ext_5ed170(self, s);
  vcall<void>(s, 0x4c, *(float *)(self + 0xd7));
  vcall<void>(s, 0x4c, *(float *)(self + 0xdb));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0xdf));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0xe3));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0xe7));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0xeb));
  vcall<void>(s, 0x44, *(u32 *)(self + 0xef));
  vcall<void>(s, 0x44, *(u32 *)(self + 0xf3));
}
PCREG(5eda70, save_5eda70);

// 0x50f9f0 ZScriptSceneInterface_t::SendCommandToObject(OpaqueCallParameters_t &p) ret 4: g = db vt[0x58](param 0); with g:
// msg = db vt[0x114] RegisterZMsg(text of param 1, 0, file 0x69db34, line 0x289) (4 words), then g->vt[0x138](msg & 0xffff,
// param 2, 0) (3 words; MSVC pushes these before the RegisterZMsg words: stack-word sharing). Vtables read before the calls.
static void THISCALL sendCommandToObject_50f9f0(u8 *self, u8 *p) {
  u8 *g = vcall<u8 *>(DB, 0x58, *ext_5003d0(*(u8 **)(p + 4), 0));
  if (!g) return;
  u32 v2 = *ext_5003d0(*(u8 **)(p + 4), 2);
  u8 *gvt = *(u8 **)g;
  u8 *dvt = *(u8 **)DB;
  u32 name = ext_506040(ext_5003d0(*(u8 **)(p + 4), 1));
  u32 msg = (*(u32(THISCALL **)(u8 *, u32, u32, u32, u32))(dvt + 0x114))(DB, name, 0, 0x69db34u, 0x289u);
  (*(void(THISCALL **)(u8 *, u32, u32, u32))(gvt + 0x138))(g, msg & 0xffff, v2, 0);
}
PCREG(50f9f0, sendCommandToObject_50f9f0);
