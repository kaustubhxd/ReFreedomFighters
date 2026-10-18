// batch814.cpp - animation layer thread, batch 814: starting clips by name (with the "unable to locate" warning).
#include "ff.h"

#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" const char *THISCALL ext_4cc1d0(void *s);   // MYSTR::c_str (mov eax, [ecx])
extern "C" void THISCALL ext_4cbec0(void *s);          // MYSTR::~MYSTR

// Logs 'WARNING: unable to locate animation "%s" for character "%s"' (zlnkobj.cpp, given line) with the object's
// name from vt 0x1d8(MYSTR* out, 1).
static void warnNoAnim(void *self, const char *name, u32 line) {
  void *sink = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x685834, line);
  u8 str[0x84];
  void *s = vcall<void *>(self, 0x1d8, str, 1);
  const char *who = ext_4cc1d0(s);
  typedef void(__attribute__((cdecl)) * pf)(void *, const char *, const char *, const char *);
  (*(pf *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x685984, name, who);
  ext_4cbec0(str);
}

// ZLNKOBJ::ActivateAnim(const char* name, int n) [medium, GC 80184bf8; string group]: GetAnim (vt 0x21c), warn when
// missing (line 0x5a0), then vt 0x230(hdr, n) (the AnimHeader overload) even with a null header.
static u32 THISCALL ActivateAnimByName(void *self, const char *name, u32 n) {
  void *hdr = vcall<void *>(self, 0x21c, name);
  if (!hdr) warnNoAnim(self, name, 0x5a0);
  return vcall<u32>(self, 0x230, hdr, n);
}
PCREG(461120, ActivateAnimByName);

// ZLNKOBJ::ActivateAnimSegment(const char* name, int n, float a, float b) [medium, GC 80184920]: same lookup and
// warning (line 0x575), then vt 0x228(hdr, n, a, b, 1.0).
static u32 THISCALL ActivateAnimSegmentByName(void *self, const char *name, u32 n, float a, float b) {
  void *hdr = vcall<void *>(self, 0x21c, name);
  if (!hdr) warnNoAnim(self, name, 0x575);
  return vcall<u32>(self, 0x228, hdr, n, a, b, 1.0f);
}
PCREG(4613a0, ActivateAnimSegmentByName);
