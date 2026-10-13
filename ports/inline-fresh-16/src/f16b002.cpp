// f16b002.cpp - fresh slice 16, batch 2 (2026-10-12).
// 0x634a83: CRT initializer walk over the table 0x6d453c..0x6d453c; the table is empty in this exe, so it does nothing.
// 0x659380: thiscall(geom, x): ZDrawBase::RemoveBaseGeom 0x63ce50(this; geom, x) (ret 8), e = geom->DirectLights() 0x658db0,
//           memset(e, 0, 0x70), e+0xc = -1; returns e (memset's return). Ret 8.
// 0x635340 ZEventBase::SetTimerInterval(float): +0x30 == 0 and handle +0x1c != 0 -> [0x70039c]+0x9b slot 0x58(handle);
//           then +0xc = the float. Ret 4.
// 0x5fe200: recursive list free: for node = arg; node; node = next: self(node+9 child list), next = node+5,
//           0x54f870(this; node, 0x13) (ret 8). Ret 4.
// 0x61ba80 expatpp::~expatpp (deleting): vtable 0x6be264, parser +4 -> XML_ParserFree 0x61c3d0 (cdecl), flag bit 0 ->
//           __builtin_delete(this, 8). Returns this. Ret 4.
// 0x63b4c0: forwards its seven arguments to ZGeometryDecal::Add 0x65e210 on this+0x8270. Ret 0x1c.
// 0x5f3440: span init (buf, off, len): +8 = len, +0 = buf, +4 = off; off+len > buf+8 (unsigned) -> call the handler at
//           0x7003b0 (no args) or int3 if it is null. Returns this. Ret 0xc.
// 0x620bc0 (expat, cdecl p, s, end, next): enc = p+0x8c; tok = enc[0](enc, s, end, &p_slot) (cdecl, may move the
//           first-argument slot); then doProlog 0x61dcd0(p, enc, s, end, tok, p_slot, next) (cdecl). Returns doProlog's result.
// 0x4fe080 CNewDialogCamera::CopyEventDataBlock: four DBREAD u16 reads 0x4e5e40 into +0x49, +0x4b, +0x4d, +0x4f. Ret 4.
// 0x62c600 toAscii (expat, cdecl enc, ptr, end): one-byte buffer c; enc+0x3c(enc, &ptr, end, &p, &c + 1);
//           p unchanged -> -1, else (signed char)c.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_63ce50[], ext_658db0[], ext_634d10[], ext_54f870[], ext_61c3d0[], ext_634273[], ext_65e210[],
    ext_61dcd0[], ext_4e5e40[];

extern "C" void f16_634a83() {
  for (u32 *p = (u32 *)0x6d453c; p < (u32 *)0x6d453c; ++p)
    if (*p) ((void (*)())(void *)*p)();
}

extern "C" void *THISCALL f16_659380(void *self, void *geom, u32 x) {
  ((void(THISCALL *)(void *, void *, u32))(void *)ext_63ce50)(self, geom, x);
  void *e = ((void *(THISCALL *)(void *))(void *)ext_658db0)(geom);
  void *r = ((void *(*)(void *, int, u32))(void *)ext_634d10)(e, 0, 0x70);
  AT(u32, e, 0xc) = 0xffffffffu;
  return r;
}

extern "C" void THISCALL f16_635340(void *self, u32 fbits_) {
  if (AT(u32, self, 0x30) == 0) {
    u32 h = AT(u32, self, 0x1c);
    if (h) vcall<void>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x58, h);
  }
  AT(u32, self, 0xc) = fbits_;
}

extern "C" void THISCALL f16_5fe200(void *self, u8 *node) {
  while (node) {
    f16_5fe200(self, AT(u8 *, node, 9));
    u8 *next = AT(u8 *, node, 5);
    ((void(THISCALL *)(void *, void *, u32))(void *)ext_54f870)(self, node, 0x13);
    node = next;
  }
}

extern "C" void *THISCALL f16_61ba80(void *self, u32 flags) {
  void *p = AT(void *, self, 4);
  AT(u32, self, 0) = 0x6be264u;
  if (p) ((void (*)(void *))(void *)ext_61c3d0)(p);
  if (flags & 1) ((void (*)(void *, u32))(void *)ext_634273)(self, 8);
  return self;
}

extern "C" void THISCALL f16_63b4c0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
  ((void(THISCALL *)(void *, u32, u32, u32, u32, u32, u32, u32))(void *)ext_65e210)(self + 0x8270, a, b, c, d, e, f, g);
}

extern "C" void *THISCALL f16_5f3440(u32 *self, u8 *buf, u32 off, u32 len) {
  self[2] = len;
  self[0] = (u32)buf;
  self[1] = off;
  if (len + off > AT(u32, buf, 8)) {
    typedef void (*Hfn)();
    Hfn h = G(Hfn, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  return self;
}

extern "C" u32 f16_620bc0(u8 *p, u32 s, u32 end, u32 next) {
  void *enc = AT(void *, p, 0x8c);
  u32 slot = (u32)p;
  u32 tok = (*(u32(**)(void *, u32, u32, u32 *))enc)(enc, s, end, &slot);
  return ((u32(*)(void *, void *, u32, u32, u32, u32, u32))(void *)ext_61dcd0)(p, enc, s, end, tok, slot, next);
}

extern "C" void THISCALL f16_4fe080(u8 *self, void *rd) {
  typedef u16(THISCALL * Rd)(void *);
  AT(u16, self, 0x49) = ((Rd)(void *)ext_4e5e40)(rd);
  AT(u16, self, 0x4b) = ((Rd)(void *)ext_4e5e40)(rd);
  AT(u16, self, 0x4d) = ((Rd)(void *)ext_4e5e40)(rd);
  AT(u16, self, 0x4f) = ((Rd)(void *)ext_4e5e40)(rd);
}

extern "C" s32 f16_62c600(u8 *enc, u32 ptr, u32 end) {
  struct { char c; char lim; } buf;
  char *p = &buf.c;
  (*(void (**)(void *, u32 *, u32, char **, char *))(enc + 0x3c))(enc, &ptr, end, &p, &buf.c + 1);
  if (p == &buf.c) return -1;
  return (s32)(s8)buf.c;
}

PCREG(634a83, f16_634a83);
PCREG(659380, f16_659380);
PCREG(635340, f16_635340);
PCREG(5fe200, f16_5fe200);
PCREG(61ba80, f16_61ba80);
PCREG(63b4c0, f16_63b4c0);
PCREG(5f3440, f16_5f3440);
PCREG(620bc0, f16_620bc0);
PCREG(4fe080, f16_4fe080);
PCREG(62c600, f16_62c600);
