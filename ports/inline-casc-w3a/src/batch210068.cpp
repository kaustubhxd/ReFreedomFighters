// batch210068.cpp - Sonnet-w3a: 0x5edf70 (split a text on literal backslash-n sequences into line objects, then add the head)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_5ee920(u8 *self);
extern "C" u32 THISCALL ext_5aca30(u8 *self, u8 *p, u32 n);
extern "C" u32 THISCALL ext_5ac5d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5ab9d0(u8 *self);
extern "C" u32 THISCALL ext_5ee110(u8 *self, u8 *s, u32 n, u32 a);

static void THISCALL fn5edf70(u8 *self, u8 *str, u32 arg) {
  u32 saved = ld32(self + 0x11);
  st32(self + 0x11, 0);
  u32 len = 0;
  while (str[len]) len++;
  u32 edi = len;
  u32 ebx = 0;
  if (len > 1) ebx = len - 2;
  if (len > 1 && ebx != 0) {  // @5edf70_a
    for (;;) {
      if (str[ebx] == 0x5c && str[ebx + 1] == 0x6e) {  // @5edf70_b
        edi = edi - ebx - 2;
        if (edi != 0) {  // @5edf70_c
          u8 *obj;
          if (ld32(self + 0x11) == 1) {  // @5edf70_d
            u32 n = (u32)((int)(ld32(self + 9) - ld32(self + 5)) >> 2);
            if (ld32(self + 0x19) == n) {  // @5edf70_e
              ext_5ee920(self);
              st32(self + 0x19, ld32(self + 0x19) - 1);
              self[0x77] = 1;
            }
            u8 *el = (u8 *)ld32((u8 *)ld32(self + 5) + ld32(self + 0x19) * 4);
            obj = (u8 *)ld32(el);
            st32(el + 4, arg);  // @5edf70_f
            st32(self + 0x19, ld32(self + 0x19) + 1);
          } else {
            ext_5ee920(self);  // @5edf70_g
            u32 idx = ld32(self + 0x19);
            u8 *el = (u8 *)ld32((u8 *)ld32(self + 5));
            obj = (u8 *)ld32(el);
            u32 n = (u32)((int)(ld32(self + 9) - ld32(self + 5)) >> 2);
            if (idx != n) {  // @5edf70_h
              self[0x77] = 1;
              st32(self + 0x19, idx + 1);
            }
            el = (u8 *)ld32((u8 *)ld32(self + 5));
            st32(el + 4, arg);
          }
          ext_5aca30(obj, str + 2 + ebx, edi);  // @5edf70_i
          ext_5ac5d0(obj, arg);  // @5edf70_j
          st32(self + 0x41, 0);
          self[4] = 1;
          if (self[0x6a] != 0) {  // @5edf70_k
            u8 *p = (u8 *)ld32(self + 5);
            u32 mx = 0, cnt = 0;
            if (p != (u8 *)ld32(self + 9)) {
              for (;;) {
                u32 w = ext_5ab9d0((u8 *)ld32((u8 *)ld32(p)));  // @5edf70_l
                if (w > mx) mx = w;  // @5edf70_m
                cnt++;
                if (cnt == ld32(self + 0x19)) break;  // @5edf70_n
                p += 4;
                if (p == (u8 *)ld32(self + 9)) break;
              }
            }
            mx += 0xa;  // @5edf70_o
            if (ld32(self + 0x45) != mx) {
              st32(self + 0x45, mx);
              self[0x77] = 1;
            }
          }
          self[0x77] = 1;
        }
        edi = ebx;  // @5edf70_p
      }
      ebx--;
      if (ebx == 0) break;
    }
    if (edi != len) {  // @5edf70_q
      ext_5ee110(self, str, edi, arg);
      st32(self + 0x11, saved);
      return;
    }
  }
  st32(self + 0x11, saved);
  ext_5ee110(self, str, edi, arg);  // @5edf70_r
}
PCREG(5edf70, fn5edf70);
