// batch46004.cpp - cascade t7 (Sonnet), tier G: 0x4d0100 (pool allocator: release every block owned by a key, coalesce neighbours, recycle empty nodes).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);                       // cdecl alloc
extern "C" void ext_634273(void *p, u32 n);                // cdecl free(p, n)
extern "C" void THISCALL ext_4d0c70(u8 *self, u8 *blk, u32 flag);   // ret 8
typedef u32 (*hook_t)();
typedef void (*free1_t)(u32);
typedef void (*cdecl2_t)(void *, u32);

static inline u32 &W(u8 *p, s32 off) { return *(u32 *)(p + off); }
static inline s32 &SW(u8 *p, s32 off) { return *(s32 *)(p + off); }
static inline void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
static inline void iatFree(u32 p) { (*(free1_t *)0x6762ec)(p); }

static void THISCALL fn4d0100(u8 *self, u32 key) {
  u32 *buf = (u32 *)ext_41e290(W(self, 0x8224) << 2);
  u32 cnt = 0;
  for (u8 *n = *(u8 **)(self + 0x8220); n; n = *(u8 **)(n + 4)) buf[cnt++] = (u32)n;
  if (cnt == 0) {
    ext_634273(buf, 4);
    return;
  }
  for (u32 i = 0; i != cnt; i++) {
    u8 *edi = (u8 *)buf[i] + 0x10;
    s32 sz = SW(edi, 8);
    if (sz == 0) continue;
    u8 *next;
    for (;;) {
      if (sz > 0) {
        edi = edi + 0x10 + sz;
        sz = SW(edi, 8);
        if (sz == 0) break;
        continue;
      }
      u8 *b0 = edi - sz;
      s32 nsz = SW(b0, 0x18);
      next = b0 + 0x10;
      if (nsz > 0) next = next + 0x10 + nsz;
      if (W(edi, 4) == key) {
        W(self, 0x20b)--;
        s32 L04 = -SW(edi, 8);
        u32 e0 = W(self, 0x20f);
        if (e0 != 0xffffffff) {
          u32 unit = W(self, 0x8217);
          u32 L24 = (u32)edi - e0;
          u32 L08 = (u32)edi + 0x10 + (u32)L04 - e0;
          if (L24 < (unit << 13)) {
            u32 lim = unit * 0x1fff;
            if (lim < L08) L08 = lim;
            u32 L10 = L24 / W(self, 0x8217);
            u32 L14 = L08 / W(self, 0x8217);
            s32 L28 = (s32)L10 + 1;
            s32 last = (s32)L14 - 1;
            if (L28 < last) {
              u8 *p = self + 0x217 + L28 * 4;
              s32 left = last - L28;
              do {
                W(p, 0) -= W(self, 0x8217);
                if ((u16)W(p, 0) != 0) assertHook();
                p += 4;
                left--;
              } while (left != 0);
            }
            if (L10 == L14) {
              W(self, 0x217 + L10 * 4) += L24 - L08;
            } else {
              u32 t = L24 - W(self, 0x8217) * (u32)L28;
              W(self, 0x217 + L10 * 4) += t;
              W(self, 0x217 + L14 * 4) += W(self, 0x8217) * L14 - L08;
            }
          }
        }
        if (L04 < 0) assertHook();
        if (W(edi, 0xc) == 0xffffffff) {
          iatFree(W(edi, -4));
        } else {
          W(self, 0) += (u32)(-0x10 - L04);
          s32 pv = SW(edi, 0xc);
          W(edi, 8) = (u32)L04;
          if (pv < 0) pv = -pv;
          u8 *prev = 0;
          if (pv != 0) prev = edi - pv - 0x10;
          u8 *nxt = edi + 0x10 + L04;
          if (W(nxt, 0xc) != (u32)-L04) assertHook();
          if (prev && W(prev, 8) != W(edi, 0xc)) {
            u8 *g = *(u8 **)0x700390;
            u8 *r = vcall<u8 *>(g, 0x20, (u32)0x695dc0, (u32)0x34f);
            (*(cdecl2_t **)r)[0x2c / 4](r, 0x695e78);
            assertHook();
          }
          if (SW(edi, 0xc) > 0) {
            if (!prev) assertHook();
            if (W(prev, 8) != W(edi, 0xc)) assertHook();
            ext_4d0c70(self, prev, 0);
            edi = prev;
            L04 = L04 + 0x10 + SW(prev, 8);
            W(prev, 8) = (u32)L04;
          }
          W(nxt, 0xc) = (u32)L04;
          u8 *after = nxt;
          if (SW(nxt, 8) > 0) {
            ext_4d0c70(self, nxt, 0);
            L04 = L04 + 0x10 + SW(nxt, 8);
            after = edi + 0x10 + L04;
            W(after, 0xc) = (u32)L04;
          }
          u8 *node = edi - 0x10;
          W(edi, 8) = (u32)L04;
          if (node == *(u8 **)(self + 0x20f) || W(edi, 0xc) != 0 || W(after, 8) != 0) {
            // keep the node: record the merged free block on the size-class list
            u8 *cls = self + 0x1cc;
            u8 *bk = vcall<u8 *>(cls, 8, (u32)L04, (u32)0);
            if (!bk) {
              u32 c = W(self, 0x1c4);
              if (c) {
                c--;
                W(self, 0x1c4) = c;
                bk = *(u8 **)(self + 0x34 + c * 4);
              } else {
                u32 a = W(self, 0x12130);
                bk = *(u8 **)(self + 0x11530 + a * 4);
                W(self, 0x12130) = a + 1;
                u32 b = W(self, 0xd628);
                u8 *ed = *(u8 **)(self + 0xc628 + b * 4);
                W(self, 0xd628) = b + 1;
                W(ed, 0xc) = (u32)bk;
                vcall<void>(self + 0x1ea, 0, (u32)ed);
              }
              W(bk, 0xc) = (u32)L04;
              W(bk, 0x11) = 0;
              vcall<void>(cls, 0, (u32)bk);
            }
            W(edi, 0x10) = 0;
            W(edi, 0x14) = W(bk, 0x11);
            W(bk, 0x11) = (u32)edi;
            u8 *q = *(u8 **)(edi + 0x14);
            if (q) W(q, 0x10) = (u32)edi;
          } else {
            // the node is now completely free: unlink it and recycle it
            u8 *pn = *(u8 **)node, *nn = *(u8 **)(node + 4);
            if (pn) W(pn, 4) = (u32)nn;
            else W(self, 0x8220) = (u32)nn;
            if (*(u8 **)(node + 4)) W(*(u8 **)(node + 4), 0) = W(node, 0);
            W(self, 0x8224)--;
            W(self, 4) += (u32)(-0x30 - SW(edi, 8));
            u32 c = W(self, 0x1c8);
            if (c == 0xb) {
              iatFree(W(node, -4));
              u8 *o = self + 0x1ea;
              u8 *rb = vcall<u8 *>(o, 8, (u32)node, (u32)0);
              if (!rb) assertHook();
              W(self, 0xd628)--;
              u32 d = W(self, 0xd628);
              u32 rv = vcall<u32>(self + 0x1ea, 4, (u32)rb);
              W(self, 0xc628 + d * 4) = rv;
              W(self, 0x207)--;
            } else {
              W(self, 8 + c * 4) = (u32)node;
              W(self, 0x1c8)++;
            }
          }
        }
      }
      edi = next;
      sz = SW(edi, 8);
      if (sz == 0) break;
    }
  }
  ext_634273(buf, 4);
}
PCREG(4d0100, fn4d0100);
