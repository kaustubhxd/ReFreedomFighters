// batch90003.cpp - hard-function trial (fable), batch 90003: 0x5fc590 script manager LoadScript(path, ctx, flag) (436 insns, recursive).
#include "ff.h"

struct Str { char *b, *e, *cap; };   // the engine's begin/end/capacity string (no inline buffer)

extern "C" void THISCALL ext_42b390(Str *s, const char *path, u8 *flag);                                   // ret 8: construct from a path (real)
extern "C" u32 *FASTCALL ext_5f1050(u32 *out, const char *chars, const char *end, const char *begin, const char *charsEnd, u32 unused);  // ret 0x10: find last of (case-insensitive), real
extern "C" Str *THISCALL ext_4312f0(Str *s, Str *out, u32 pos, u32 n);                                      // ret 0xc: substr (real)
extern "C" void THISCALL ext_5f2d60(Str *s, const char *b, const char *e);                                  // ret 8: assign range (real)
extern "C" void THISCALL ext_54f870(Str *s, void *p, u32 n);                                                // ret 8: free buffer (real -> allocator slot 0x10)
extern "C" void THISCALL ext_5f2c60(Str *s, const char *b, const char *e);                                  // ret 8: append range (real)
extern "C" const char *FASTCALL ext_5fa640(const char *hb, const char *he, const char *nb, const char *ne, u32 u1, u32 u2, u32 u3);  // ret 0x14: find (case-insensitive), real
extern "C" void THISCALL ext_5fb980(void *map, u32 *iter, Str *key);                                        // ret 8: map find (hooked)
extern "C" u32 THISCALL ext_5fba50(Str *s, const char *chars, u32 pos);                                     // ret 8: rfind (real)
extern "C" u8 *ext_5fa630();                                                                                // the script loader global [0x724270]
extern "C" u8 *ext_41e290(u32 n);                                                                           // cdecl: allocate (real -> allocator slot 8)
extern "C" u8 *THISCALL ext_5fa740(u8 *node);                                                               // ret 0: node ctor (hooked, returns node)
extern "C" u32 *THISCALL ext_5fb110(void *map, Str *key);                                                   // ret 4: map insert -> value slot (hooked)
extern "C" void THISCALL ext_607640(u8 *node, void *stream);                                                // ret 4: parse (hooked)
extern "C" void ext_634273(void *p, u32 n);                                                                 // cdecl: free (real -> allocator slot 0x10)
extern "C" void THISCALL ext_5fd630(Str *s, u32 pos, u32 n, Str *src);                                      // ret 0xc: replace (real)
extern "C" void THISCALL ext_5fd0a0(void *ctx, Str *s);                                                     // ret 4 (hooked)
extern "C" u8 *THISCALL ext_5fc590(void *self, const char *path, u32 ctx, u32 flag);                        // ret 0xc: this function (recursion, hooked)
extern "C" void THISCALL ext_5ff2b0(void *p, u32 a, void *self, u32 flag);                                  // ret 0xc (hooked)
extern "C" void THISCALL ext_602240(void *stream);                                                          // ret 0: stream dtor (real)
extern "C" void FASTCALL ext_633654(u32 cookie);

typedef void (*c4_t)(void *, void *, u32, u32);
typedef void (*c2_t)(void *, void *);
#define STR(a) ((const char *)(a))

static inline void sfree(Str *s) {   // the inlined "if (b && cap - b) deallocate(b, cap - b)"
  if (s->b && s->cap - s->b) ext_54f870(s, s->b, (u32)(s->cap - s->b));
}
static inline void substr_assign(Str *s, Str *tmp, u32 pos, u32 n) {   // s = s.substr(pos, n) through a temporary
  Str *r = ext_4312f0(s, tmp, pos, n);
  if (r != s) ext_5f2d60(s, r->b, r->e);
  sfree(tmp);
}

// 0x5fc590, thiscall(path, ctx, flag byte) ret 0xc, SEH frame. S = Str(path); S = S.substr(0, last '.'); S += ".ppo"; S = S after the last '\'.
// If self[0] != 0 -> 0. Look S up in the map at self+1 (counter 0x724688++): found -> node[0x19]. Else (0x724684++) T = Str(path) cut at
// rfind('.') + ".ppo"; data = loader->slot 8(T.b, &size). data: node = alloc(0x17e) ctor; node.name(0x172) = T; map[S] = node; parse(node,
// stream{0x6b8508, data, data, data+size, size, 1}); free(data, 1); if node has a parent name (0xc..0x10): T = path, replace the part after
// the last '\' with it (or T = parent name), ctx ? 0x5fd0a0(ctx, &T); node[0xd8] = LoadScript(T.b, ctx, flag) + 0x3c. Then 0x5ff2b0(node+0x3c,
// node[0x38], self, flag); delete node[0x38]; 0x72468c += node[0x2c] * 0x50; return node. No data: loader slots 0x14/0xc log the error, assert hook, 0.
static u8 *THISCALL fn5fc590(u8 *self, const char *path, u32 ctx, u32 flagw) {
  Str S, T, tmp;
  u32 local78, m90, c0;
  u8 flag8;
  u32 stream[6];
  char local74[0x64];
  u8 *res;
  u8 flag = (u8)flagw;
  ext_42b390(&S, path, &flag8);
  m90 = 0xffffffff;
  u32 len = (u32)(S.e - S.b);
  u32 pos;
  if (len >= 1) {
    local78 = len - 1;
    ext_5f1050(&local78, STR(0x67b1b0), S.b + local78 + 1, S.b, STR(0x67b1b1), ctx);
    pos = (local78 == (u32)S.b) ? 0xffffffff : local78 - (u32)S.b - 1;
  } else {
    pos = 0xffffffff;
  }
  substr_assign(&S, &tmp, 0, pos);
  ext_5f2c60(&S, STR(0x6b880c), STR(0x6b8810));
  len = (u32)(S.e - S.b);
  local78 = 0xffffffff;
  u32 pos2;
  if (len < 1) {
    pos2 = 0xffffffff;
  } else {
    m90 = len - 1;
    const char *end = S.b + 1 + m90;
    const char *r = ext_5fa640(S.b, end, STR(0x67856c), STR(0x67856d), ctx, ctx, ctx);
    pos2 = (r == end) ? 0xffffffff : (u32)(r - S.b);
    local78 = pos2;
  }
  u32 from = (pos2 == 0xffffffff) ? 0 : pos2 + 1;
  u32 cnt = (u32)(S.e - S.b) - from;
  substr_assign(&S, &tmp, from, cnt);
  if (self[0] != 0) {
    res = 0;
  } else {
    u8 *map = self + 1;
    ext_5fb980(map, &local78, &S);
    G(u32, 0x724688)++;
    if (local78 != *(u32 *)map) {
      res = *(u8 **)(local78 + 0x19);
    } else {
      G(u32, 0x724684)++;
      ext_42b390(&T, path, &flag8);
      u32 p3 = ext_5fba50(&T, STR(0x67b1b0), 0xffffffff);
      substr_assign(&T, &tmp, 0, p3);
      ext_5f2c60(&T, STR(0x6b880c), STR(0x6b8810));
      m90 = 0;
      u8 *g = ext_5fa630();
      u8 *data = vcall<u8 *>(g, 8, (u32)T.b, (u32)&m90);
      if (data) {
        u8 *blk = ext_41e290(0x17e);
        u8 *node = blk ? ext_5fa740(blk) : 0;
        if ((Str *)(node + 0x172) != &T) ext_5f2d60((Str *)(node + 0x172), T.b, T.e);
        u32 *slot = ext_5fb110(map, &S);
        *slot = (u32)node;
        stream[0] = 0x6b8508;
        stream[1] = (u32)data;
        stream[2] = (u32)data;
        stream[3] = (u32)data + m90;
        stream[4] = m90;
        ((u8 *)stream)[0x14] = 1;
        ext_607640(node, stream);
        ext_634273(data, 1);
        Str *pname = (Str *)(node + 0xc);
        if (pname->e - pname->b != 0) {
          u32 n = 0;
          while (path[n]) n++;
          ext_5f2d60(&T, path, path + n);
          len = (u32)(T.e - T.b);
          local78 = 0xffffffff;
          bool replaced = false;
          if (len >= 1) {
            c0 = len - 1;
            const char *end = T.b + 1 + c0;
            const char *r = ext_5fa640(T.b, end, STR(0x67856c), STR(0x67856d), ctx, ctx, ctx);
            if (r != end && (u32)(r - T.b) != 0xffffffff) {
              u32 c1 = (u32)(r - T.b) + 1;
              ext_5fd630(&T, c1, (u32)(T.e - T.b) - c1, pname);
              replaced = true;
            }
          }
          if (!replaced && pname != &T) ext_5f2d60(&T, pname->b, pname->e);
          if (ctx) ext_5fd0a0((void *)ctx, &T);
          u8 *r2 = ext_5fc590(self, T.b, ctx, flag);
          *(u32 *)(node + 0xd8) = (u32)r2 + 0x3c;
        }
        ext_5ff2b0(node + 0x3c, *(u32 *)(node + 0x38), self, flag);
        u8 *o = *(u8 **)(node + 0x38);
        if (o) vcall<void>(o, 0, 1u);
        *(u32 *)(node + 0x38) = 0;
        G(u32, 0x72468c) += *(u32 *)(node + 0x2c) * 0x50;
        ext_602240(stream);
        sfree(&T);
        res = node;
      } else {
        g = ext_5fa630();
        (*(c4_t **)g)[0x14 / 4](g, local74, 0x6b92b0, (u32)path);
        g = ext_5fa630();
        (*(c2_t **)g)[0xc / 4](g, local74);
        u32 h = G(u32, 0x7003b0);
        if (h) ((void (*)())h)();
        else __builtin_trap();
        sfree(&T);
        res = 0;
      }
    }
  }
  sfree(&S);
  ext_633654(0);
  return res;
}
PCREG(5fc590, fn5fc590);
