// batch36027.cpp - cascade s4 batch 36027: 0x57def0, 0x589710, 0x41eca0, 0x44d250, 0x428370 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_57ece0(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_562c20(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_57d000(void *self);          // plain ret
extern "C" void THISCALL ext_57e930(void *self);          // plain ret
extern "C" void *ext_634d22(void *dst, const void *src, u32 n);  // cdecl (memcpy thunk)

// 0x57def0, thiscall(code) ret 4, returns bool (this = E): E[0xdc] != 2 -> 0. code 0x1388 or 0x2b67: 0x562c20(E, code); 0x1770: 0x57e930(E); 0x3ea: 0x57ece0(E, -1); 0x3eb: 0x57ece0(E, 1); all return 1.
// Otherwise memcpy(E[0x32c], [[0x70039c]+0x1907][0x131c], E[0x338]), E[0x34a] = 0, E[0x33c] = code, 0x57d000(E); returns 1.
static u8 THISCALL fn57def0(u8 *E, u32 code) {
  if (rd(E + 0xdc) != 2) return 0;
  if (code > 0x1388) {
    if (code == 0x1770) {
      ext_57e930(E);
      return 1;
    }
    if (code == 0x2b67) {
      ext_562c20(E, code);
      return 1;
    }
  } else {
    if (code == 0x1388) {
      ext_562c20(E, code);
      return 1;
    }
    if (code == 0x3ea) {
      ext_57ece0(E, 0xffffffffu);
      return 1;
    }
    if (code == 0x3eb) {
      ext_57ece0(E, 1);
      return 1;
    }
  }
  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x1907);
  ext_634d22(*(void **)(E + 0x32c), (const void *)rd(o + 0x131c), rd(E + 0x338));
  E[0x34a] = 0;
  wr(E + 0x33c, code);
  ext_57d000(E);
  return 1;
}
PCREG(57def0, fn57def0);

typedef void *(*memmove_t)(void *, const void *, u32);

// 0x589710, thiscall(src) ret 4, returns this (this = E): E[0] = src[0] and src[0] dwords from +4; E[0x34] = src[0x34]; E[0x38] = src[0x38] and that many dwords from +0x3c;
// E[0x7c] = src[0x7c] and memmove(E+0x80, src+0x80, src[0x7c] * 4); E[0xb0] = src[0xb0] and memmove(E+0xb4, src+0xb4, src[0xb0] * 4).
static u8 *THISCALL fn589710(u8 *E, u8 *src) {
  wr(E, rd(src));
  for (s32 i = 0, n = (s32)rd(src); i < n; i++) wr(E + 4 + 4 * i, rd(src + 4 + 4 * i));
  wr(E + 0x34, rd(src + 0x34));
  wr(E + 0x38, rd(src + 0x38));
  for (s32 i = 0, n = (s32)rd(src + 0x38); i < n; i++) wr(E + 0x3c + 4 * i, rd(src + 0x3c + 4 * i));
  wr(E + 0x7c, rd(src + 0x7c));
  G(memmove_t, 0x676278)(E + 0x80, src + 0x80, rd(src + 0x7c) << 2);
  wr(E + 0xb0, rd(src + 0xb0));
  G(memmove_t, 0x676278)(E + 0xb4, src + 0xb4, rd(src + 0xb0) << 2);
  return E;
}
PCREG(589710, fn589710);

typedef int(*stricmp_t)(const char *, const char *);
extern "C" void ext_634273(void *p, u32 n);  // cdecl

// 0x41eca0, thiscall(name) ret 4 (this = E): c = E[0x20] (null returns); c->slot 0x4c(&loc); for each r from c->slot 0x64(&loc): _stricmp(r[0], name) != 0 -> next;
// match: r[0xc] non-null: free(r[0xc], 4); r[0] non-null: free(r[0], 1); c->slot 0x44(&loc); returns.
static void THISCALL fn41eca0(u8 *E, const char *name) {
  u32 loc[3];
  u8 *c = *(u8 **)(E + 0x20);
  if (!c) return;
  (*(v1_t **)c)[0x4c / 4](c, (u32)loc);
  c = *(u8 **)(E + 0x20);
  u8 *r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
  if (!r) return;
  do {
    if (G(stricmp_t, 0x676414)((const char *)rd(r), name) == 0) {
      if (rd(r + 0xc)) ext_634273((void *)rd(r + 0xc), 4);
      if (rd(r)) ext_634273((void *)rd(r), 1);
      c = *(u8 **)(E + 0x20);
      (*(v1_t **)c)[0x44 / 4](c, (u32)loc);
      return;
    }
    c = *(u8 **)(E + 0x20);
    r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
  } while (r);
}
PCREG(41eca0, fn41eca0);

// 0x44d250, thiscall(a, b) ret 8, returns the node or 0 (this = E): t = [0x70039c][0x44]; scan the first E[0x46c] node pointers at E+0x1c: node[0] == a and node[4] == b -> found;
// t - node[0x3c] > 0x100 (signed): evict (E[0x46c]--, swap with the last slot, retest the same index); else next. Not found: count == 0x10 -> 0; else take the node at the next slot,
// count++, node[0] = a, node[4] = b, node[0x40] = 1. Found or new: node[0x3c] = [0x70039c][0x40]; returns the node.
static u8 *THISCALL fn44d250(u8 *E, u32 a, u32 b) {
  u32 t = rd(G(u8 *, 0x70039c) + 0x44);
  u32 i = 0;
  u8 *node = 0;
  bool found = false;
  if (rd(E + 0x46c) > 0) {
    do {
      node = *(u8 **)(E + 0x1c + 4 * i);
      if (rd(node) == a && rd(node + 4) == b) {
        found = true;
        break;
      }
      if ((s32)(t - rd(node + 0x3c)) > 0x100) {
        wr(E + 0x46c, rd(E + 0x46c) - 1);
        u32 j = rd(E + 0x46c);
        if (i != j) {
          u32 x = rd(E + 0x1c + 4 * i), y = rd(E + 0x1c + 4 * j);
          wr(E + 0x1c + 4 * i, y);
          wr(E + 0x1c + 4 * j, x);
        }
      } else {
        i++;
      }
    } while (i < rd(E + 0x46c));
  }
  if (!found) {
    u32 n = rd(E + 0x46c);
    if (n == 0x10) return 0;
    node = *(u8 **)(E + 0x1c + 4 * n);
    wr(E + 0x46c, n + 1);
    wr(node, a);
    wr(node + 4, b);
    node[0x40] = 1;
  }
  wr(node + 0x3c, rd(G(u8 *, 0x70039c) + 0x40));
  return node;
}
PCREG(44d250, fn44d250);

typedef u32(STDCALL *writefile_t)(u32, u8 *, u32, u32 *, u32);
typedef u32(STDCALL *getlasterror_t)();
typedef u32(STDCALL *formatmessage_t)(u32, u32, u32, u32, u32 *, u32, u32);
typedef u32(STDCALL *localfree_t)(u32);

// 0x428370, stdcall(h, buf, n) ret 0xc, returns bool: writes n bytes in chunks of at most 0x3c00000 with WriteFile; a failed write fetches GetLastError twice, formats the message with FormatMessageA(0x1300, 0, err, 0x400, &msg),
// logs (0x6789ac, 0x113, 0x678b88, chunk, msg) through the engine log and frees the message with LocalFree; returns 0.
static u32 STDCALL fn428370(u32 h, u8 *buf, u32 n) {
  u32 off = 0;
  u32 chunk;
  u32 written;
  do {
    chunk = n - off;
    if ((s32)chunk > 0x3c00000) chunk = 0x3c00000;
    if (!G(writefile_t, 0x676120)(h, buf + off, chunk, &written, 0)) {
      G(getlasterror_t, 0x67609c)();
      u32 err = G(getlasterror_t, 0x67609c)();
      u32 msg = n;
      G(formatmessage_t, 0x6760ec)(0x1300, 0, err, 0x400, &msg, 0, 0);
      u8 *db = G(u8 *, 0x700390);
      u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x6789acu, 0x113u);
      void **vt2 = *(void ***)o;
      void *fn = *(void **)((u8 *)vt2 + 0x2c);
      ((void (*)(u8 *, u32, u32, u32))fn)(o, 0x678b88u, chunk, msg);  // cdecl printf-style (ecx = vtable in the exe is not read)
      (void)vt2;
      G(localfree_t, 0x676128)(msg);
      return 0;
    }
    off += chunk;
  } while (n != off);
  return 1;
}
PCREG(428370, fn428370);
