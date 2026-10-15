// batch46000.cpp - cascade t7 (Sonnet), tier G: 0x56a220 (UI widget command dispatcher, 393 insns).
#include "ff.h"

extern "C" void THISCALL ext_562b50(u8 *self, const void *name);     // ret 4
extern "C" void THISCALL ext_562bc0(u8 *self);                       // plain ret
extern "C" void THISCALL ext_562c20(u8 *self, u32 id);               // ret 4
extern "C" void THISCALL ext_563500(u8 *self);                       // plain ret
extern "C" void THISCALL ext_561f10(u8 *self, u32 flag);             // ret 4
extern "C" void THISCALL ext_59c420(u8 *self);                       // plain ret
extern "C" void THISCALL ext_5ae270(u8 *self, u32 flag);             // ret 4
extern "C" void THISCALL ext_5ae710(u8 *self, u32 flag);             // ret 4
extern "C" void THISCALL ext_610100(u8 *self, u32 flag);             // ret 4
extern "C" u32 THISCALL ext_48aad0(void *pair);                      // plain ret, this = {obj, key}

static inline u8 *rd(u8 *p, u32 off) { return *(u8 **)(p + off); }
static inline u8 *table() { return *(u8 **)(*(u8 **)0x70039c + 0x9b); }
// object-table slot 0x114: (a, b, file, line, c) -> u16 (thiscall, callee pops 20)
static inline u32 log114(u32 a, u32 b, u32 line, u32 c) {
  u8 *t = table();
  return (u16)vcall<u32>(t, 0x114, a, b, (u32)0x6a771c, line, c);
}
static inline void emit12c(u8 *self, u32 a, u32 b) { vcall<void>(rd(self, 0x44), 0x12c, a, b); }
static inline void cmd(u8 *self, u32 v) { vcall<void>(self, 0xd0, v); }

static u32 THISCALL fn56a220(u8 *self, u32 id) {
  u32 idv = id;
  if (*(u32 *)(self + 0xdc) != 2) return 0;
  if (idv < 6) {
    if (*(u32 *)(self + 0x198) != 0) {
      u8 *w = rd(self, 0x44);
      u32 ax = (u16)vcall<u32>(table(), 0x114, (u32)0x6a6ffc, (u32)0, (u32)0x6a771c, (u32)0xe1, (u32)&idv);
      vcall<void>(w, 0x12c, *(u32 *)(self + 0x198), ax);
    }
    if (*(u32 *)(self + 0x1c5) == 4) {
      cmd(self, 0);
    } else {
      u32 s = *(u32 *)(self + idv * 4 + 0x180);
      if (s) cmd(self, s);
    }
    return 0;
  }
  if (id == 0x64) {
    u8 *o = rd(self, 0x94);
    if (*(u32 *)(o + 0x1044) == 3) ext_59c420(o);
    else ext_562b50(self, (void *)0x6a7744);
    return 0;
  }
  if (id == 0xc8) {
    ext_5ae270(rd(self, 0x94) + 0x57, 1);
    ext_5ae710(rd(self, 0x94) + 0x57, 0);
    u8 *o = rd(self, 0x94);
    if (o[0x1040]) ext_562b50(self, (void *)0x6a774c);
    else ext_562b50(self, o + 0x48);
    return 0;
  }
  if (id == 0x2b67) {
    if (self[0x87] == 0) return 0;
    cmd(self, 0);
    return 0;
  }
  if (id == 0x309) {
    u32 pair[2];
    pair[0] = vcall<u32>(table(), 0x138);
    pair[1] = 0x6a7754;
    cmd(self, ext_48aad0(pair));
    return 0;
  }
  if (id == 0x378) {
    ext_5ae270(rd(self, 0x94) + 0x57, 1);
    u8 *o = rd(self, 0x94);
    u8 b[8];
    const u8 *p = o + 0x48;
    u32 i = 0;
    u8 c;
    do {
      c = p[i];
      b[i] = c;
      i++;
    } while (c);
    b[4] = c;
    if (b[2] == 0x38) {
      if (b[3] != 0x41 || *(s32 *)(o + 0x1048) != -3) b[2] = 0x39;
    }
    b[3] = 0x52;
    ext_562b50(self, b);
    return 0;
  }
  if (id == 0x384) {
    u8 *o = rd(self, 0x94);
    if (*(u32 *)(o + 0x1044) == 3 && o[0x1042] == 0) ext_59c420(o);
    else vcall<void>(table(), 0xa8);
    return 0;
  }
  if (id == 0x3e8 || id == 0x3f2) {
    u8 *p = vcall<u8 *>(table(), 0x134);
    vcall<void>(p, 0x68, (u32)(id == 0x3e8 ? 0x6a757c : 0x6a776c), (u32)1, (u32)0);
    p = vcall<u8 *>(table(), 0x134);
    vcall<void>(p, 0x68, (u32)0x6a75b0, (u32)0, (u32)0);
    ext_563500(self);
    ext_561f10(self, 0);
    ext_562b50(self, (void *)(id == 0x3e8 ? 0x6a7764 : 0x6a7774));
    return 0;
  }
  if (id == 0xbb8) {
    u32 pair[2];
    pair[0] = vcall<u32>(table(), 0x138);
    u8 *w = rd(self, 0x44);
    pair[1] = 0x6a5c48;
    u32 ax = (u16)vcall<u32>(table(), 0x114, (u32)0x6a4fb0, (u32)0, (u32)0x6a771c, (u32)0x149, (u32)0);
    u32 r = ext_48aad0(pair);
    vcall<void>(rd(self, 0x44), 0x12c, r, ax);
    (void)w;
    u8 *o = rd(self, 0x90);
    if (o) vcall<void>(o, 0x658);
    ext_610100(self, 0);
    return 0;
  }
  if (id == 0xfa0) return 0;
  if (id == 0x1b58) {
    ext_563500(self);
    u8 *p = vcall<u8 *>(table(), 0x134);
    vcall<void>(p, 0x5c, (u32)0x6a777c, (u32)1, (u32)2);
    ext_562bc0(self);
    return 0;
  }
  if ((id & 0xffff0000) == 0xff0000) {
    cmd(self, *(u32 *)(self + (id & 0xffff) * 4 + 0x180));
    return 0;
  }
  if (id - 0x12c < 0x64) {
    u8 *o = rd(self, 0x94);
    u32 line2;
    u32 ebx;
    if (o[0x103e]) {
      const u8 *a = o + 0x48, *b = (const u8 *)0x6a6e5c;
      u32 d = 0;
      for (;; a++, b++) {
        if (*a != *b) { d = 1; break; }
        if (!*a) break;
      }
      if (d) {
        u32 s = *(u32 *)(self + id * 4 - 0x330);
        if (s) cmd(self, s);
        return 0;
      }
      u32 pair[2];
      pair[0] = vcall<u32>(table(), 0x138);
      pair[1] = 0x6a778c;
      ebx = ext_48aad0(pair);
      u8 *w = rd(self, 0x44);
      u32 ax = (u16)vcall<u32>(table(), 0x114, (u32)0x6a77a0, (u32)0, (u32)0x6a771c, (u32)0x166, (u32)0x6a7798);
      (void)w;
      emit12c(self, ebx, ax);
      line2 = 0x167;
    } else {
      u32 pair[2];
      pair[0] = vcall<u32>(table(), 0x138);
      pair[1] = 0x6a778c;
      ebx = ext_48aad0(pair);
      u32 ax = (u16)vcall<u32>(table(), 0x114, (u32)0x6a77a0, (u32)0, (u32)0x6a771c, (u32)0x177, (u32)(rd(self, 0x94) + 0x48));
      emit12c(self, ebx, ax);
      line2 = 0x178;
    }
    u32 ax2 = (u16)vcall<u32>(table(), 0x114, (u32)0x6a77ac, (u32)0, (u32)0x6a771c, line2, (u32)0);
    emit12c(self, ebx, ax2);
    cmd(self, ebx);
    return 0;
  }
  ext_562c20(self, id);
  return 0;
}
PCREG(56a220, fn56a220);
