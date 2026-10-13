// batch6535.cpp - unclaimed-65: batch 35 (docs/20-unclaimed-65.md, claim 21): ZInputActions::GetButtonName (0x439020), the whole
// function lifted (stdcall, ret 8). Branch groups are verified one by one (see the doc); the SEH prolog and the cookie are not reproduced.
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }

// a call with `self` in ecx and four stack arguments that the CALLER removes (add esp, 0x10 follows the original call)
static void callCallerCleans4(u8 *self, u32 fn, u32 a, u32 b, u32 c, u32 d) {
  asm volatile(
      "pushl %[d]\n\t"
      "pushl %[c]\n\t"
      "pushl %[b]\n\t"
      "pushl %[a]\n\t"
      "call *%[fn]\n\t"
      "addl $16, %%esp\n\t"
      :
      : "c"(self), [fn] "r"(fn), [a] "r"(a), [b] "r"(b), [c] "r"(c), [d] "r"(d)
      : "eax", "edx", "memory", "cc");
}

extern "C" u32 THISCALL ext_4cc5f0(u8 *s);                 // plain, returns the strlen of [s]
extern "C" u32 THISCALL ext_4cc1d0(u8 *s);                 // plain, returns [s]
extern "C" void FASTCALL ext_4cc6e0(u8 *buf, u32 ch);      // fastcall, appends the UTF-8 form of ch (ret 0)
extern "C" u8 *THISCALL ext_4cbe80(u8 *self, u32 str);     // thiscall, one argument (literal if NULL), ret 4
extern "C" u8 *THISCALL ext_4cbe50(u8 *self, u8 *arg);     // thiscall, one argument (its first dword is the char pointer), ret 4
extern "C" u8 *THISCALL ext_4cbee0(u8 *self, u32 other);   // thiscall, one argument (other string object), ret 4
extern "C" void THISCALL ext_4cbec0(u8 *s);                // plain release

// 0x439020, ZInputActions::GetButtonName(out, code). See docs/20-unclaimed-65.md (claim 21) for the map of the tables.
static u8 *STDCALL getButtonName(u8 *out, u32 code) {
  u8 Lb8[0x80];   // ebp-0xb8
  u8 L138[0x80];  // ebp-0x138
  u8 L18[0x8];    // ebp-0x18
  u8 L38[0x20];   // ebp-0x38

  // default: code -1 (the literal name 0x677b5a)
  if (code == 0xffffffff) {
    ext_4cbe80(out, 0x677b5a);
    return out;
  }

  u32 esi = code & 0xffff;
  const u32 hi = code >> 16;
  u32 edx = hi <= 3 ? hi : 0;
  if (edx == 0 && G(u32, 0x6e48bc) != 0) {
    // search the bank records (16 bytes each): id at 0x6e48bc + 16k (0 ends the list), count at 0x6e48c4 + 16k, base at 0x6e48c0 + 16k
    u32 ecx = 0;
    u32 eax = G(u32, 0x6e48c4);
    for (;;) {
      if (esi < eax) {
        edx = ecx;
        break;
      }
      esi -= eax;
      ecx++;
      const u32 off = ecx << 4;
      if (G(u32, 0x6e48bc + off) == 0) {
        edx = 0;
        break;
      }
      eax = G(u32, 0x6e48c4 + off);
    }
  }

  // the entry: bank base + 12 * esi (entry + 4 is a key, entry + 8 a string pointer)
  u8 *bank = (u8 *)G(u32, 0x6e48c0 + edx * 16);
  u8 *entry = bank + 4 * (3 * esi);

  if (edx > 5) {
    ext_4cbe80(out, 0x677b5a);
    return out;
  }
  switch (edx) {
    case 0: {
      u32 key = *(const u32 *)(entry + 4);
      if (G(u32, 0x6e4928) != 0) {
        const u8 *q = (const u8 *)0x6e4928;
        for (;;) {
          if (key == *(const u32 *)(q + 4)) {
            key = *(const u32 *)q;
            break;
          }
          q += 8;
          if (*(const u32 *)q == 0) break;
        }
      }
      u8 *rend = G(u8 *, 0x70039c);
      if (*(const u8 *)(rend + 0x6e) != 0 && key == 0xb8) key = 0x138;
      vc2(rend, 0xdc, (u32)Lb8, key);
      const u32 len = ext_4cc5f0(Lb8);
      if (len == 1) {
        const u8 ch = *(const u8 *)ext_4cc1d0(Lb8);
        ext_4cc6e0(L18, ch);
        ext_4cbe80(L138, (u32)L18);
        ext_4cbee0(Lb8, (u32)L138);
        ext_4cbec0(L138);
      }
      ext_4cbe50(out, Lb8);
      ext_4cbec0(Lb8);
      return out;
    }
    case 1: {
      u8 *rend = G(u8 *, 0x70039c);
      u8 *p = (u8 *)vc0(rend, 0x190);
      callCallerCleans4(L38, *(const u32 *)(*(const u32 *)p + 0x198), (u32)p, (u32)L38, 0x67a9b8, esi + 1);
      u8 *rend9b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *o = *(u8 **)(rend9b + 0xae4);
      const u32 str = vc2(o, 0, 0x67a9c4, (u32)L38);
      ext_4cbe80(out, str);
      return out;
    }
    default:  // 2 to 5
      ext_4cbe80(out, *(const u32 *)(entry + 8));
      return out;
  }
}

PCREG(439020, getButtonName);
