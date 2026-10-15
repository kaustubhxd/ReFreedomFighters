// batch90004.cpp - hard-function trial (fable), batch 90004: 0x605ba0 type-list parser: append the registry objects named in a text (438 insns).
#include "ff.h"

struct Str { char *b, *e, *cap; };

extern "C" void THISCALL ext_42b390(Str *s, const char *text, u8 *flag);                                   // ret 8: construct from text (real)
extern "C" u8 *THISCALL ext_6014a0(Str *s, u32 n);                                                          // ret 4: allocate n bytes (real -> allocator)
extern "C" Str *THISCALL ext_4312f0(Str *s, Str *out, u32 pos, u32 n);                                      // ret 0xc: substr (real)
extern "C" void THISCALL ext_5f2d60(Str *s, const char *b, const char *e);                                  // ret 8: assign range (real)
extern "C" void THISCALL ext_54f870(Str *s, void *p, u32 n);                                                // ret 8: free buffer (real)
extern "C" const char *FASTCALL ext_605b20(const char *b, const char *e, const char *sb, const char *se, u32 unused);   // ret 0xc: find first of set (ci), real
extern "C" const char *FASTCALL ext_605ac0(const char *b, const char *e, const char *sb, const char *se, u32 unused);   // ret 0xc: find first not of set (ci), real
extern "C" u8 *ext_602d30();                                                                                // cdecl, no args: the type registry [0x724694] (asserts when null), real
extern "C" u8 *THISCALL ext_602ff0(u8 *reg, const char *name);                                              // ret 4: registry lookup by name (hooked)
extern "C" void THISCALL ext_5f4630(u8 *vec);                                                               // ret 0: grow the pointer vector (real)
extern "C" u8 FASTCALL ext_4cc4b0(u8 a, u8 b);                                                              // ci char equality: ecx, edx (real)

#define STR(a) ((const char *)(a))

static inline void sfree(Str *s) {
  if (s->b && s->cap - s->b) ext_54f870(s, s->b, (u32)(s->cap - s->b));
}
static inline void substr_assign(Str *s, Str *dst, Str *tmp, u32 pos, u32 n) {   // dst = s.substr(pos, n) through a temporary
  Str *r = ext_4312f0(s, tmp, pos, n);
  if (r != dst) ext_5f2d60(dst, r->b, r->e);
  sfree(tmp);
}
static inline void empty8(Str *s) {   // Str with an 8-byte buffer holding ""
  s->b = s->e = s->cap = 0;
  u8 *p = ext_6014a0(s, 8);
  s->b = s->e = (char *)p;
  s->cap = (char *)p + 8;
  if (p) *p = 0;
  *p = 0;
}

// 0x605ba0, thiscall(text) ret 4, SEH frame. this = pointer vector {arr, cap, count, .., +0x18 sum}. L = Str(text); A = " \t\n"; B = " \t\n,".
// pos = first A char in L. While pos != -1 and pos < len: key end kb = first B char at or after pos (inline ci search), stop when none;
// if kb > pos + 1: K = L[pos .. kb) (one less when L[kb] == '\n'); vs = first B char from kb (always kb); if vs < len: ve = first non-B
// char from vs, V = L[vs .. ve) (one less when L[ve] == '\n') or V = L[vs ..) when none; obj = registry->find(K) or registry->find("int");
// push obj (grow when full), sum += obj[0x18]. Next pos = first B char from kb (or ve). Frees V, K, B, A, L. No return value.
static void THISCALL fn605ba0(u8 *self, const char *text) {
  Str L, A, B, K, V, tmp;
  u8 flag8;
  ext_42b390(&L, text, &flag8);
  ext_42b390(&A, STR(0x6b9d60), (u8 *)&text + 3);   // the exe hands the top byte of its own argument slot as the flag byte
  ext_42b390(&B, STR(0x6b9d64), (u8 *)&text + 3);
  empty8(&K);
  empty8(&V);
  const char *r = ext_605b20(L.b, L.e, A.b, A.b + (A.e - A.b), (u32)text);
  u32 pos = (r == L.e) ? 0xffffffff : (u32)(r - L.b);
  s32 kb;
  if (pos == 0xffffffff) goto done;
  for (;;) {
    u32 llen = (u32)(L.e - L.b);
    if (pos >= llen) goto done;
    const char *p = L.b + pos;
    const char *found = L.e;
    if (p != L.e) {
      for (; p != L.e; p++) {
        for (const char *q = B.b; q != B.e; q++)
          if (ext_4cc4b0((u8)*p, (u8)*q)) { found = p; goto out; }
      }
    }
  out:
    kb = (found == L.e) ? -1 : (s32)(found - L.b);
    if (kb == -1) goto done;
    if (kb <= (s32)pos + 1) goto next;
    {
      u32 n = (u32)kb - pos;
      if (L.b[kb] == '\n') substr_assign(&L, &K, &tmp, pos, n - 1);
      else substr_assign(&L, &K, &tmp, pos, n);
      llen = (u32)(L.e - L.b);
      if ((u32)kb > llen) goto assert_;
      r = ext_605b20(L.b + kb, L.e, B.b, B.b + (B.e - B.b), pos);
      if (r == L.e) goto assert_;
      u32 vs = (u32)(r - L.b);
      if (vs == 0xffffffff) goto assert_;
      if (vs < llen) {
        const char *r2 = ext_605ac0(L.b + vs, L.e, B.b, B.b + (B.e - B.b), pos);
        kb = (r2 == L.e) ? -1 : (s32)(r2 - L.b);
        if (kb == -1) goto rest;
        u32 vn = (u32)kb - vs;
        if (L.b[kb] == '\n') substr_assign(&L, &V, &tmp, vs, vn - 1);
        else substr_assign(&L, &V, &tmp, vs, vn);
      } else {
        kb = -1;
      rest:
        substr_assign(&L, &V, &tmp, vs, 0xffffffff);
      }
      u8 *reg = ext_602d30();
      u8 *obj = ext_602ff0(reg, K.b);
      if (!obj) {
        reg = ext_602d30();
        obj = ext_602ff0(reg, STR(0x6b8788));
      }
      if (*(u32 *)(self + 8) >= *(u32 *)(self + 4)) ext_5f4630(self);
      (*(u32 **)self)[*(u32 *)(self + 8)] = (u32)obj;
      (*(u32 *)(self + 8))++;
      *(u32 *)(self + 0x18) += *(u32 *)(obj + 0x18);
      goto next;
    }
  assert_: {
      u32 h = G(u32, 0x7003b0);
      if (h) ((void (*)())h)();
      else __builtin_trap();
    }
  next:
    llen = (u32)(L.e - L.b);
    if ((u32)kb > llen) goto done;
    r = ext_605b20(L.b + kb, L.e, B.b, B.b + (B.e - B.b), pos);
    pos = (r == L.e) ? 0xffffffff : (u32)(r - L.b);
    if (pos == 0xffffffff) goto done;
  }
done:
  sfree(&V);
  sfree(&K);
  sfree(&B);
  sfree(&A);
  sfree(&L);
}
PCREG(605ba0, fn605ba0);
