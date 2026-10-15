// batch46003.cpp - cascade t7 (Sonnet), tier G: 0x53b8d0 (builds the list of unique 0x89-byte "slot records" for a list of items, copies them into this+0xc9).
#include "ff.h"

extern "C" u32 THISCALL ext_53bfd0(u8 *self, u8 *a1, u32 *l10, u8 *p14, u8 *pc);                              // ret 0x10, returns al
extern "C" u32 THISCALL ext_53c5b0(u8 *self, u32 a, u32 b, u32 *cnt, u8 *rec, u32 *l11f4, u32 *l10);           // ret 0x18, returns al
extern "C" u32 THISCALL ext_53b860(u8 *self, u8 *list, s32 count, u8 *probe);                                  // ret 0xc
extern "C" void THISCALL ext_53b7f0(u8 *self, u8 *dst, u8 *src);                                               // ret 8
extern "C" u8 *THISCALL ext_53c1f0(u8 *self, u32 key);                                                         // ret 4
extern "C" u8 *THISCALL ext_4db3b0(u8 *obj);                                                                   // plain ret

static inline u8 *eng() { return *(u8 **)0x70039c; }
static inline u8 *table() { return *(u8 **)(eng() + 0x9b); }
static inline u32 &W(u8 *p, u32 off) { return *(u32 *)(p + off); }
static inline void push_idx(u8 *s, u32 v) {
  u32 n = W(s, 0x8c);
  W(s, 0x90 + 4 * n) = v;
  W(s, 0x8c) = n + 1;
}

static void THISCALL fn53b8d0(u8 *self, u8 *a1, u8 *it, u8 *sink) {
  u8 E[0x89 * 40];
  u8 rec[0x89];
  for (u32 i = 0; i < sizeof(E); i++) E[i] = 0xcc;
  for (u32 i = 0; i < sizeof(rec); i++) rec[i] = 0xcc;
  u32 L10[3] = {0, 0, 0};
  u32 L11e8 = 0, L11f0 = 0, L11f4 = 0;
  u8 *lq = *(u8 **)(eng() + 0x1a9f);
  u8 *lbase = lq + 0x109f;
  u8 *o = vcall<u8 *>(lq, 0xc0);
  vcall<void>(o, 0x84, (u32)L10);
  W(self, 0x10) = W(a1, 0x94);
  lq = *(u8 **)(eng() + 0x1a9f);
  if (lq[0x86]) self[0x18] = (u8)ext_53bfd0(self, a1, L10, self + 0x14, self + 0xc);
  else self[0x18] = 0;
  u32 r = vcall<u32>(a1, 0x350);
  W(E, 0x25) = 1;
  if (r) {
    u32 r2 = vcall<u32>(a1, 0x350);
    W(E, 0x29) = r2;
    W(E, 5) = r2;
    W(E, 0x2d) = self[0x18] ? 5 : 2;
  } else {
    W(E, 0x29) = 0x12345678;
    W(E, 0x2d) = 3;
    W(E, 5) = 0x12345678;
  }
  s32 cnt = 1;
  u8 *nextEntry = E + 0x89;
  if (it) {
    vcall<void>(it, 0x4c, (u32)&L11e8);
    u32 item = vcall<u32>(it, 0x5c, (u32)&L11e8);
    while (L11e8 != 0) {
      u8 *s = vcall<u8 *>(table(), 0x60, item);
      bool sinkOnly = false;   // true: sink->slot4(item), then advance
      if (!s) {
        vcall<void>(it, 0x44, (u32)&L11e8);
        item = vcall<u32>(it, 0x5c, (u32)&L11e8);
        continue;
      }
      u32 k = W(s, 0x3c);
      W(s, 0x8c) = 0;
      bool fetchOnly = false;   // jump to the "fetch next" step without advancing
      if (k == 0) {
        sinkOnly = true;
      } else {
        u8 *pp = vcall<u8 *>(table(), 0x58, k);
        u8 *esi5 = ext_4db3b0(*(u8 **)(pp + 8));
        if (W(self, 0x11f5) == 0) {
          sinkOnly = true;
        } else {
          u32 fl = W(s, 0x40);
          u8 *e = eng();
          if ((fl & 0x20) && (u32)a1 == W(*(u8 **)(e + 0x9b), 0xadc)) {
            sinkOnly = true;
          } else if (self[0x1209] != 0) {
            sinkOnly = true;
          } else if (!(fl & 4) && (u32)a1 != W(*(u8 **)(e + 0x9b), 0xadc)) {
            sinkOnly = true;
          } else if ((u32)esi5 == (u32)a1) {
            push_idx(s, 0);
            sinkOnly = true;
          } else {
            bool done = false;
            if (fl & 1) {
              u8 *ent = ext_53c1f0(lbase, W(s, 0x30));
              while (ent) {
                u8 *tb = *(u8 **)(*(u8 **)0x70039c + 0x9b);
                u32 z = (u32)vcall<u8 *>(tb, 0x58, W(ent, 0));
                if (z != 0 && z == (u32)a1) {
                  push_idx(s, 0);
                  done = true;
                  break;
                }
                u32 nx = W(ent, 4);
                if (nx == 0 || nx == 0x80000000) break;
                ent = lbase + 8 + nx * 8;
              }
            }
            if (done) {
              sinkOnly = true;
            } else {
              u8 *e2 = esi5;
              L11f4 = 0;
              L11f0 = 0;
              u32 ok = ext_53c5b0(self, W(e2, 0x94), W(a1, 0x94), &L11f0, rec, &L11f4, L10) & 0xff;
              if (!ok) {
                fetchOnly = true;
              } else {
                u32 have = vcall<u32>(e2, 0x350);
                u32 n = L11f0;
                if (have) {
                  u32 r3 = vcall<u32>(e2, 0x350);
                  W(rec, 0x29 + 12 * n) = r3;
                  W(rec, 0x2d + 12 * n) = 2;
                  W(rec, 5 + 4 * n) = 0;
                  n++;
                }
                W(rec, 0x25) = n;
                u32 idx = cnt;
                u32 rr = ext_53b860(self, E, cnt, rec);
                if (rr == 0xffffffff) {
                  u32 rr2 = ext_53b860(self, self + 0xc9, (s32)W(self, 0xc5), rec);
                  if (rr2 == 0xffffffff) rec[0] = 1;
                  else {
                    W(rec, 1) = rr2;
                    rec[0] = 0;
                  }
                  ext_53b7f0(self, nextEntry, rec);
                  cnt++;
                  nextEntry += 0x89;
                } else {
                  idx = rr;
                }
                push_idx(s, idx);
                sinkOnly = true;
              }
            }
          }
        }
      }
      if (sinkOnly) {
        vcall<void>(sink, 4, item);
        vcall<void>(it, 0x44, (u32)&L11e8);
      }
      (void)fetchOnly;
      item = vcall<u32>(it, 0x5c, (u32)&L11e8);
    }
  }
  vcall<void>(self + 0x19, 0xc);
  for (s32 i = 0; i < (s32)W(self, 0xc5); i++) {
    u32 rr = ext_53b860(self, E, cnt, self + 0xc9 + 0x89 * i);
    if (rr == 0xffffffff) vcall<void>(self + 0x19, 4, (u32)i);
  }
  if (cnt <= 0) {
    W(self, 0xc5) = cnt;
    return;
  }
  for (s32 j = 0; j < cnt; j++) {
    u8 *src = E + 0x89 * j;
    u8 *dst = self + 0xc9 + 0x89 * j;
    dst[0] = src[0];
    u32 n = W(src, 0x25);
    W(dst, 0x25) = n;
    W(dst, 1) = W(src, 1);
    for (s32 i = 0; i < (s32)n; i++) {
      W(dst, 0x29 + 12 * i) = W(src, 0x29 + 12 * i);
      W(dst, 0x2d + 12 * i) = W(src, 0x2d + 12 * i);
      W(dst, 0x31 + 12 * i) = W(src, 0x31 + 12 * i);
      W(dst, 5 + 4 * i) = W(src, 5 + 4 * i);
    }
  }
  W(self, 0xc5) = cnt;
}
PCREG(53b8d0, fn53b8d0);
