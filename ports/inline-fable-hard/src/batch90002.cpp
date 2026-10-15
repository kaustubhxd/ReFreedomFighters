// batch90002.cpp - hard-function trial (fable), batch 90002: 0x43bc80 (action-map config parser: end-element handler, 13-state switch).
#include "ff.h"

extern "C" void THISCALL ext_43b9a0(void *, const char *);    // ret 4 (verified): parse error with message
extern "C" void *THISCALL ext_4cbe80(void *, const char *);   // ret 4 (verified): ZString ctor from char*
extern "C" void *THISCALL ext_4cbee0(void *, void *);         // ret 4 (verified): ZString assign from ZString*
extern "C" void THISCALL ext_4cbec0(void *);                  // ret 0 (verified): ZString dtor
extern "C" u8 *ext_41e290(u32 n);                             // cdecl (verified): engine allocation
extern "C" void THISCALL ext_43bbe0(void *, void *);          // ret 4: commit the mapping named by the string at this+0x10 (hooked)
extern "C" void FASTCALL ext_633654(u32 cookie);              // /GS check

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline bool streq(const char *a, const char *b) {   // the exe inlines strcmp and only tests the result for zero
  while (*a && *a == *b) { a++; b++; }
  return *a == *b;
}
static inline u32 slen(u8 *zs) {   // 0x4cc5f0: strlen of a ZString's char pointer (at +0)
  const char *p = *(const char **)zs;
  u32 n = 0;
  while (p[n]) n++;
  return n;
}
#define STR(a) ((const char *)(a))

// 0x43bc80, thiscall(name) ret 4, SEH frame (handler 0x664d1b) around a ZString temp. State E[0xc] (jump table 0x43c1dc, 13 entries):
//  0: name != "Settings" -> error 0x67c07c.
//  1: name == "ActionMap" -> E[0xc3] = ZString(""); E[0xbf] = 0; state 1. else name != "Controls" -> error 0x67c0a8 (misplaced end token); else state 0.
//  2: name != "Mapping" -> error; else if len(E[0x10]) E[8]->slot 0x34(E+0x10); zero E[0xb0..0xb6], E[0x90..0xaf] = -1, E[0x247]=E[0x243]=E[0xb7]=E[0xbb]=0; state 1.
//  3: name != "Group" -> error; else if len(E[0x10]) && len(E[0x1c3]) && E[0xb5] == 1: E[0xb7] = alloc(len+1), strcpy, E[8]->slot 0x38(E+0x10); 0x43bbe0(E+0x10); state 1.
//  4: name != "Mouse" -> error; else state 1.   5: name == "Action" -> state 3.   6: name in Key/NotKey/Action/NotAction -> state 2, else error.
//  7, 8: state 0.   9: state 1.   0xa, > 0xc: nothing.   0xb: like 3 with "Sequence", E[0xb6] == 1 and slot 0x34.   0xc: name != "Keys" -> error; else state 0xb.
static void THISCALL fn43bc80(u8 *E, const char *name) {
  u8 tmp[0x80];
  u8 *s10 = E + 0x10;
  switch (rd(E + 0xc)) {
    case 0:
      if (!streq(name, STR(0x67a0e8))) ext_43b9a0(E, STR(0x67c07c));
      break;
    case 1:
      if (streq(name, STR(0x67be1c))) {
        ext_4cbe80(tmp, STR(0x677b5a));
        ext_4cbee0(E + 0xc3, tmp);
        ext_4cbec0(tmp);
        wr(E + 0xbf, 0);
        wr(E + 0xc, 1);
      } else if (!streq(name, STR(0x67a0fc))) {
        ext_43b9a0(E, STR(0x67c0a8));
      } else {
        wr(E + 0xc, 0);
      }
      break;
    case 2:
      if (!streq(name, STR(0x67a108))) { ext_43b9a0(E, STR(0x67c0a8)); break; }
      if (slen(s10)) vcall<void>(*(u8 **)(E + 8), 0x34, (u32)s10);
      E[0xb0] = 0;
      wr(E + 0xb1, 0);
      *(u16 *)(E + 0xb5) = 0;
      wr(E + 0x90, 0xffffffff); wr(E + 0xa0, 0xffffffff); wr(E + 0x94, 0xffffffff); wr(E + 0xa4, 0xffffffff);
      wr(E + 0x98, 0xffffffff); wr(E + 0xa8, 0xffffffff); wr(E + 0x9c, 0xffffffff); wr(E + 0xac, 0xffffffff);
      wr(E + 0x247, 0);
      wr(E + 0x243, 0);
      wr(E + 0xb7, 0);
      wr(E + 0xbb, 0);
      wr(E + 0xc, 1);
      break;
    case 3:
    case 0xb: {
      bool grp = rd(E + 0xc) == 3;
      if (!streq(name, STR(grp ? 0x67bdec : 0x67bdfc))) { ext_43b9a0(E, STR(0x67c0a8)); break; }
      if (slen(s10) && slen(E + 0x1c3) && E[grp ? 0xb5 : 0xb6] == 1) {
        u32 n = slen(E + 0x1c3) + 1;
        u8 *p = ext_41e290(n);
        wr(E + 0xb7, (u32)p);
        const char *src = *(const char **)(E + 0x1c3);
        u8 *d = *(u8 **)(E + 0xb7);
        char ch;
        do { ch = *src++; *d++ = (u8)ch; } while (ch);
        vcall<void>(*(u8 **)(E + 8), grp ? 0x38 : 0x34, (u32)s10);
      }
      ext_43bbe0(E, s10);
      wr(E + 0xc, 1);
      break;
    }
    case 4:
      if (!streq(name, STR(0x67a1b0))) ext_43b9a0(E, STR(0x67c0a8));
      else wr(E + 0xc, 1);
      break;
    case 5:
      if (streq(name, STR(0x67a110))) wr(E + 0xc, 3);
      break;
    case 6:
      if (streq(name, STR(0x67beac)) || streq(name, STR(0x67bf18)) || streq(name, STR(0x67a110)) || streq(name, STR(0x67a154))) wr(E + 0xc, 2);
      else ext_43b9a0(E, STR(0x67c0a8));
      break;
    case 7:
    case 8:
      wr(E + 0xc, 0);
      break;
    case 9:
      wr(E + 0xc, 1);
      break;
    case 0xc:
      if (!streq(name, STR(0x67bfb8))) ext_43b9a0(E, STR(0x67c0a8));
      else wr(E + 0xc, 0xb);
      break;
    default:
      break;
  }
  ext_633654(0);
}
PCREG(43bc80, fn43bc80);
