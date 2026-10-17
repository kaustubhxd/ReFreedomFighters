#include "ff.h"

typedef void(THISCALL *V1)(void *, u32);

extern "C" u32 THISCALL ext_4db9a0(void *node, u32 mask);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(u32 addr) { return *(const float *)addr; }

// 0x57b6d0: thiscall(), no stack args. Walks the list this[0x54] (head [[0x54]+8], next through slot 0x50(&node)); for each node passing 0x4db9a0(node, 0x100034) the item
// node[0x54] is configured by its kind (slot 0x310, 1..12) through slot 0x36c(value, 1) (and 0x360 / 0x2d8 / 0x2dc / 0x378 for the flag-driven kinds), the values coming from
// the engine fields, the info record filled by [engine+0x190f] slot 0x1cc and the float lookups of X = engine slot 0xbc; afterwards (for every node, also for kinds outside 1..12) this[0xb4] receives the table lookup
// (slot 0x4c) of (item, item slot 0x368).
extern "C" void THISCALL fn_57b6d0(u8 *self);
extern "C" void THISCALL fn_57b6d0(u8 *self) {
  u8 *E = G(u8 *, 0x70039c);
  u8 *X = vcall<u8 *>(E, 0xbc);
  u8 *Y = (u8 *)rd32u(E + 0x190f);
  u32 info[9];
  vcall<void>(Y, 0x1cc, (u32)info);
  u32 flags = (u8)info[0];
  u8 *node = (u8 *)rd32u((u8 *)rd32u(self + 0x54) + 8);
  if (!node) return;
  do {
    if ((u8)ext_4db9a0(node, 0x100034) != 0) {
      u8 *item = (u8 *)rd32u(node + 0x54);
      u32 loc4;
      u32 k = vcall<u32>(item, 0x310) - 1;
      if (k <= 11) {
        switch (k) {
          case 0:
            vcall<void>(item, 0x36c, 3 - rd32u(G(u8 *, 0x70039c) + 0x93), 1);
            break;
          case 1:
            if (flags & 0x10) {
              vcall<void>(item, 0x360, 0, 1);
            } else {
              vcall<void>(item, 0x2dc);
              vcall<void>(item, 0x378, 0x677b5a);
            }
            vcall<void>(Y, 0x1d4, 8, (u32)&loc4);
            vcall<void>(item, 0x36c, loc4 != 0 ? 1 : 0, 1);
            break;
          case 2: {
            float v = vcall<float>(X, 0x58, 0x6922d4, 1.2f);
            float eps = rdf(0x679540);
            u32 i = 0;
            do {
              if (rdf(0x6aa1cc + i * 4) + eps >= v) break;
              i++;
            } while (i < 4);
            vcall<void>(item, 0x36c, i, 1);
            break;
          }
          case 3:
            vcall<void>(item, 0x36c, rd32u(G(u8 *, 0x70039c) + 0x97), 1);
            break;
          case 4:
            vcall<void>(item, 0x36c, rd32u(G(u8 *, 0x70039c) + 0x8f), 1);
            break;
          case 5: {
            float v = vcall<float>(X, 0x58, 0x683724, 1.0f);
            float r = (float)((double)v * (double)rdf(0x67cd40));
            vcall<void>(item, 0x36c, (u32)(int)r, 1);
            break;
          }
          case 6: {
            int cnt = 0;
            u32 sel = 0;
            if (flags & 2) {
              u32 loc18;
              vcall<void>(Y, 0x1d4, 2, (u32)&loc18);
              u32 m = loc18 ? 1u << ((loc18 - 1) & 31) : 0;
              u32 bits = info[1];
              u32 b = 2;
              do {
                if (b & bits) {
                  cnt++;
                  if (m & b) sel = (u32)cnt;
                }
                b += b;
              } while (b != 0);
              if (cnt > 0) {
                vcall<void>(item, 0x2d8);
                vcall<void>(item, 0x360, 0, (u32)cnt);
                vcall<void>(item, 0x36c, sel, 1);
                break;
              }
            }
            vcall<void>(item, 0x2dc);
            vcall<void>(item, 0x378, 0x677b5a);
            vcall<void>(item, 0x36c, sel, 1);
            break;
          }
          case 7:
            if (flags & 8) {
              vcall<void>(item, 0x2d8);
            } else {
              vcall<void>(item, 0x2dc);
              vcall<void>(item, 0x378, 0x677b5a);
            }
            vcall<void>(Y, 0x1d4, 3, (u32)&loc4);
            vcall<void>(item, 0x36c, loc4, 1);
            break;
          case 8: {
            u32 r = vcall<u32>(X, 0x5c, 0x6aa1dc, 1);
            vcall<void>(item, 0x36c, r, 1);
            break;
          }
          case 9:
            vcall<void>(item, 0x36c, (u32)*(u8 *)(G(u8 *, 0x70039c) + 0x68), 1);
            break;
          case 10:
            if (flags & 4) {
              vcall<void>(item, 0x2d8);
            } else {
              vcall<void>(item, 0x2dc);
              vcall<void>(item, 0x378, 0x677b5a);
            }
            vcall<void>(Y, 0x1d4, 7, (u32)&loc4);
            vcall<void>(item, 0x36c, loc4, 1);
            break;
          default: {
            float v = vcall<float>(X, 0x58, 0x6aa1e8, 1.25f);
            float r = (float)((1.0 / (double)v) * (double)rdf(0x67cd40));
            vcall<void>(item, 0x36c, (u32)(int)r, 1);
            break;
          }
        }
      }
      u8 *T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
      u32 vt = *(u32 *)self;
      u32 r368 = vcall<u32>(item, 0x368);
      u32 a = vcall<u32>(T, 0x4c, (u32)item, r368);
      (*(V1 *)(vt + 0xb4))(self, a);
    }
    vcall<void>((void *)rd32u(self + 0x54), 0x50, (u32)&node);
  } while (node);
}
PCREG(57b6d0, fn_57b6d0);
