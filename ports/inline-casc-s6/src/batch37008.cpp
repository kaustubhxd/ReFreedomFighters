// batch37008.cpp - cascade s6 batch 37008: 0x430480.
#include "ff.h"

#define PAR(n) (*(u8 **)((n) + 1))
#define LFT(n) (*(u8 **)((n) + 5))
#define RGT(n) (*(u8 **)((n) + 9))

// 0x430480, fastcall(x, root) returns *root: red-black tree insert fix-up on packed nodes {u8 colour (0 red, 1 black), parent +1, left +5, right +9};
// x is coloured red first, the loop recolours or rotates until the parent is black or x is the root, then the root is made black.
static u8 *FASTCALL fn430480(u8 *x, u8 **root) {
  x[0] = 0;
  if (x == *root) { (*root)[0] = 1; return *root; }
  for (;;) {
    u8 *p = PAR(x);
    if (p[0] != 0) break;
    u8 *g = PAR(p);
    u8 *u, *a, *b;
    if (p == LFT(g)) {
      u = RGT(g);
      if (u && u[0] == 0) goto recolor;
      if (x == RGT(p)) {
        x = p;
        a = RGT(x);
        RGT(x) = LFT(a);
        if (LFT(a)) PAR(LFT(a)) = x;
        PAR(a) = PAR(x);
        if (x == *root) *root = a;
        else if (x == LFT(PAR(x))) LFT(PAR(x)) = a;
        else RGT(PAR(x)) = a;
        LFT(a) = x;
        PAR(x) = a;
      }
      PAR(x)[0] = 1;
      PAR(PAR(x))[0] = 0;
      a = PAR(PAR(x));
      b = LFT(a);
      LFT(a) = RGT(b);
      if (RGT(b)) PAR(RGT(b)) = a;
      PAR(b) = PAR(a);
      if (a == *root) *root = b;
      else if (a == RGT(PAR(a))) RGT(PAR(a)) = b;
      else LFT(PAR(a)) = b;
      RGT(b) = a;
      PAR(a) = b;
    } else {
      u = LFT(g);
      if (u && u[0] == 0) goto recolor;
      if (x == LFT(p)) {
        x = p;
        a = LFT(x);
        LFT(x) = RGT(a);
        if (RGT(a)) PAR(RGT(a)) = x;
        PAR(a) = PAR(x);
        if (x == *root) *root = a;
        else if (x == RGT(PAR(x))) RGT(PAR(x)) = a;
        else LFT(PAR(x)) = a;
        RGT(a) = x;
        PAR(x) = a;
      }
      PAR(x)[0] = 1;
      PAR(PAR(x))[0] = 0;
      a = PAR(PAR(x));
      b = RGT(a);
      RGT(a) = LFT(b);
      if (LFT(b)) PAR(LFT(b)) = a;
      PAR(b) = PAR(a);
      if (a == *root) *root = b;
      else if (a == LFT(PAR(a))) LFT(PAR(a)) = b;
      else RGT(PAR(a)) = b;
      LFT(b) = a;
      PAR(a) = b;
    }
    if (x == *root) break;
    continue;
  recolor:
    p[0] = 1;
    u[0] = 1;
    PAR(p)[0] = 0;
    x = PAR(p);
    if (x == *root) break;
  }
  (*root)[0] = 1;
  return *root;
}
PCREG(430480, fn430480);
