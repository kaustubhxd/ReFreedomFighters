// u18_04.cpp - area 18, group 4 (unclaimed-18 thread): three named functions that call other functions.
#include "ff.h"

extern "C" void THISCALL ext_45f8c0(void *self);                    // ZGEOM::RequestCustomDraw (original code; 9 bytes)
extern "C" void THISCALL ext_562440(void *self);                    // CBaseWindow::Init (original code)
extern "C" void THISCALL ext_563510(void *self, const char *name);  // CBaseWindow::SetBackGroundPicture (ret 4)
extern "C" void THISCALL ext_563610(void *self, const char *name);  // unnamed window call (ret 4)
extern "C" void THISCALL ext_4cbe50(void *self, const char *text);  // MYSTR::MYSTR(const char*) (ret 4)

// 0x43e150, ZSTDOBJ::RequestCustomDraw() (GC map medium). thiscall, void. When the sub-object at +0xc is not of class
// 0x200002, the flag 0x20 is set in the flags at +0x14; then the exe tail-jumps to ZGEOM::RequestCustomDraw.
static void THISCALL stdobjRequestCustomDraw(u8 *self) {
  u8 *sub = *(u8 **)(self + 0xc);
  if (*(u32 *)(sub + 0x23) != 0x200002u)
    *(u32 *)(self + 0x14) |= 0x20u;
  ext_45f8c0(self);
}
PCREG(43e150, stdobjRequestCustomDraw);

// 0x57c210, ZFFAutoSave::Init() (GC map high). thiscall, void: init the base window, then the "Options" background and
// the "HelpGroup11" group (strings from the exe).
static void THISCALL autoSaveInit(u8 *self) {
  ext_562440(self);
  ext_563510(self, (const char *)0x6a6f98);   // "Options"
  ext_563610(self, (const char *)0x6a6fa0);   // "HelpGroup11"
}
PCREG(57c210, autoSaveInit);

// 0x42fc90, ZSysInterface::StreamIdxPath() const (GC map high). thiscall with a hidden return buffer (one stack arg,
// ret 4). Builds a MYSTR in the buffer from this+0x823; returns the buffer.
static u8 *THISCALL sysStreamIdxPath(u8 *self, u8 *retBuf) {
  ext_4cbe50(retBuf, (const char *)(self + 0x823));
  return retBuf;
}
PCREG(42fc90, sysStreamIdxPath);
