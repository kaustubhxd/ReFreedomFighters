// batch0114.cpp - fresh-01 batch 14 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" double ext_634dca(double x);                              // floor (CRT, st0 return)
extern "C" void THISCALL ext_4ccf60(u8 *tab);                        // REFTAB32::~REFTAB32
extern "C" void ext_4690b0(void *p, u32 size);                       // empty cdecl body (sized delete)
extern "C" u8 *THISCALL ext_605400(u8 *self);                        // OpaqueString_t copy (returns the new string)
extern "C" void ext_634273(void *p, u32 n);                          // operator delete
extern "C" void *ext_41e290(u32 size);                               // operator new
extern "C" u32 *THISCALL ext_5003d0(u32 arr, u32 i);                 // array element pointer (checked)
extern "C" u8 THISCALL ext_561c40(void *self);                       // autosave flag (engine slot 0xbc -> slot 0xe0)
extern "C" void THISCALL ext_5636c0(u8 *self, u32 id, const char *text);  // CBaseWindow::SetTextOnButton
extern "C" void FASTCALL ext_633654(u32 cookie);                     // __security_check_cookie

typedef void (*handlerFn)();
typedef int (*toupperFn)(int);
typedef void (*fmtFn)(void *, char *, u32, u32, u32);

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x404fd0 (unnamed cdecl, x87): L = |(a*c, b*d)|; when g is 0 (or NaN): *o1 = *o2 = 0. Else *o1 = (float)(a when
// |b| < |a| or unordered, else b); M = |(c*g, d*g)|; *o1 = (float)(floor(L / M * *o1 * f + 0.5) * e); *o2 = 0.
// x87 at 53-bit precision on float inputs = double math (sums, products and sqrt round the same way).
static void cdeclScale404fd0(float a, float b, float c, float d, float e, float f, float g, float *o1, u32 *o2) {
  double ac = (double)a * c, bd = (double)b * d;
  double L = crt::sqrt(bd * bd + ac * ac);
  if (g == 0.0f || g != g) {
    *(u32 *)o1 = 0;
    *o2 = 0;
    return;
  }
  float fa = __builtin_fabsf(a), fb = __builtin_fabsf(b);
  *o1 = (fb < fa || fb != fb || fa != fa) ? a : b;
  double cg = (double)c * g, dg = (double)d * g;
  double M = crt::sqrt(dg * dg + cg * cg);
  double x = L / M * (double)*o1 * (double)f + 0.5;
  *o1 = (float)(ext_634dca(x) * (double)e);
  *o2 = 0;
}
PCREG(404fd0, cdeclScale404fd0);

// 0x4a3bd0, ZSoundAmbient scalar deleting destructor: REFTAB32 dtors on +0x108 and +0x5c, then as 0x57f1d0 with
// size 0x1dd (+0x44 = +0x30 = 0, vtable 0x686874, render slot 0x34(this); flag 1: flag 4 -> 0x4690b0, else handler).
static u8 *THISCALL soundAmbientScalarDelete(u8 *self, u32 flags) {
  ext_4ccf60(self + 0x108);
  ext_4ccf60(self + 0x5c);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(render(), 0x34, self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x1dd);
    } else {
      handlerFn h = G(handlerFn, 0x7003b0);
      if (!h) __builtin_debugtrap();
      h();
    }
  }
  return self;
}
PCREG(4a3bd0, soundAmbientScalarDelete);

// 0x6057d0, OpaqueString_t::toUpper(OpaqueCallParameters_t&): r = 0x605400(this); when r's capacity-1 (u16 +0x10)
// is below strlen(this+0xc) (unsigned compare), r's buffer is replaced (delete(buf, 1), new(this cap), cap copied,
// this text copied); r's text is upper-cased in place with the CRT toupper; result element 0 of +8: when its type
// is 0, or 4 (old object released with slot 0x28), it becomes type 4 = r slot 0x24(); finally r slot 0x28().
static void THISCALL opaqueStringToUpper(u8 *self, u8 *p) {
  u8 *r = ext_605400(self);
  const char *s = *(const char **)(self + 0xc);
  u32 n = 0;
  while (s[n]) n++;
  if ((u32)*(u16 *)(r + 0x10) - 1 < n) {
    ext_634273(*(void **)(r + 0xc), 1);
    char *d = (char *)ext_41e290(*(u16 *)(self + 0x10));
    *(char **)(r + 0xc) = d;
    *(u16 *)(r + 0x10) = *(u16 *)(self + 0x10);
    const char *q = *(const char **)(self + 0xc);
    char ch;
    do {
      ch = *q++;
      *(volatile char *)d = ch;
      d++;
    } while (ch);
  }
  char *t = *(char **)(r + 0xc);
  for (; *t; t++) *t = (char)G(toupperFn, 0x67641c)((int)(signed char)*t);
  u32 *e = ext_5003d0(*(u32 *)(p + 8), 0);
  u8 ty = *((u8 *)e + 4);
  if (ty == 0 || ty == 4) {
    if (ty == 4) vcall<void>(*(u8 **)e, 0x28);
    *e = vcall<u32>(r, 0x24);
    *((u8 *)e + 4) = 4;
  }
  vcall<void>(r, 0x28);
}
PCREG(6057d0, opaqueStringToUpper);

// 0x57c390, ZFFAutoSave::UpdateButton(): s1 = text(0x6a67e8, autosave on ? 0x6aa76c : 0x6aa774) and s2 =
// text(0x6a6a34, 0x6aa64c) from the localiser [[render]+0xae4] slot 0; fmt = engine slot 0x190(); fmt slot 0x198
// (cdecl: fmt, buf, 0x68dcfc, s2, s1) fills a 0x100 stack buffer; SetTextOnButton(+0x180, buf). /GS cookie.
static void THISCALL autoSaveUpdateButton(u8 *self) {
  char buf[0x100];
  u8 on = ext_561c40(self);
  u8 *loc = *(u8 **)(render() + 0xae4);
  u32 s1 = vcall<u32>(loc, 0, 0x6a67e8u, on ? 0x6aa76cu : 0x6aa774u);
  u8 *fmt = vcall<u8 *>(G(u8 *, 0x70039c), 0x190);
  u8 *loc2 = *(u8 **)(render() + 0xae4);
  u32 s2 = vcall<u32>(loc2, 0, 0x6a6a34u, 0x6aa64cu);
  (*(fmtFn *)(*(u8 **)fmt + 0x198))(fmt, buf, 0x68dcfc, s2, s1);
  ext_5636c0(self, *(u32 *)(self + 0x180), buf);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(57c390, autoSaveUpdateButton);
