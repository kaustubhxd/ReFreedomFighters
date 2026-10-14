// batch38022.cpp - cascade s8 batch 38022: 0x620e70 (parse a "name=value<FF>" definition string into the lookup tables).
#include "ff.h"

extern "C" u32 ext_6206e0(u8 *grow);                           // cdecl: grow the scratch buffer (S+0x22c)
extern "C" u8 *ext_61fd60(u8 *table, u8 *key, u32 n);          // cdecl
extern "C" u32 ext_6204f0(u8 *table, u8 *key);                 // cdecl (intern)
extern "C" u32 ext_61c660(u8 *s, u8 *node, u32 z, u8 *key, u8 *tab);   // cdecl

#define W (*(u8 **)(S + 0x238))
#define BUF (*(u8 **)(S + 0x23c))
#define END_ (*(u8 **)(S + 0x234))
#define GROW() ext_6206e0(S + 0x22c)

// 0x620e70, cdecl(S, str) -> bool. Splits str (bytes up to NUL; 0x0c ends a segment, '=' separates name from value) and uses the scratch buffer at S+0x23c (write pointer S+0x238,
// end S+0x234, grown through 0x6206e0 when full). A segment without '=' is entered with 0x61fd60(S+0x158, name, 0) and flagged (+0x1c = 1); with '=' the name goes through
// 0x61fd60(S+0x194, name, 8) (interned with 0x6204f0(S+0x1a8) when the node still points into the scratch buffer; an empty name uses the default node S+0x1dc) and the value is passed with the
// node to 0x61c660(S, node, 0, value, S+0x20c). Any helper failure returns 0, a full parse returns 1.
static u32 fn620e70(u8 *S, u8 *str) {
  u8 *ebx = str;
  u8 *edi = str;
  if (*ebx == 0) return 1;
  do {
    u8 al = *edi;
    if (al == 0x0c || al == 0) {
      if (W == END_) {
        if (!GROW()) return 0;
      }
      *W = 0;
      u8 *key = BUF;
      W++;
      u8 *r = ext_61fd60(S + 0x158, key, 0);
      if (r) r[0x1c] = 1;
      W = BUF;
      ebx = (*edi == 0) ? edi : edi + 1;
      edi = ebx;
    } else if (al == 0x3d) {
      u8 *node;
      u8 *w = W;
      if (w == BUF) {
        node = S + 0x1dc;
      } else {
        if (w == END_) {
          if (!GROW()) return 0;
        }
        *W = 0;
        u8 *key = BUF;
        W++;
        node = ext_61fd60(S + 0x194, key, 8);
        if (!node) return 0;
        if (*(u8 **)node == BUF) {
          u32 r = ext_6204f0(S + 0x1a8, *(u8 **)node);
          *(u32 *)node = r;
          if (!r) return 0;
        }
        W = BUF;
      }
      edi++;
      al = *edi;
      while (al != 0x0c && al != 0) {
        if (W == END_) {
          if (!GROW()) return 0;
        }
        u8 ch = *edi;
        edi++;
        *W = ch;
        W++;
        al = *edi;
      }
      if (W == END_) {
        if (!GROW()) return 0;
      }
      *W = 0;
      W++;
      if (!ext_61c660(S, node, 0, BUF, S + 0x20c)) return 0;
      W = BUF;
      ebx = (*edi == 0) ? edi : edi + 1;
      edi = ebx;
    } else {
      if (W == END_) {
        if (!GROW()) return 0;
      }
      *W = *edi;
      W++;
      edi++;
    }
  } while (*ebx != 0);
  return 1;
}
PCREG(620e70, fn620e70);
