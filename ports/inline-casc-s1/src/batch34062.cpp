// batch34062.cpp - cascade tier E, batch 34062: 0x601a80 (name of an object or of its parent when it is the ground), 0x620890 (run a loader under a guard frame), 0x6322e0 (finish a handle: release, reset, rebuild).
#include "ff.h"

typedef int(*stricmp_t)(const char *, const char *);          // cdecl, api-ms-win-crt-string _stricmp
typedef u32 (*cb2_t)(u32, u32);                                // cdecl
typedef u32 (*cb4_t)(u32, u32, u32, u32);                      // cdecl
typedef u32(STDCALL *std3_t)(u32, u32, u32);
extern "C" u32 ext_61dcd0(u32 st, u32 h, u32 edi, u32 esi, u32 r, u32 a8, u32 z);   // cdecl, seven args
extern "C" void ext_633170(u32 p, u32 ctx);                    // cdecl

// 0x601a80, stdcall(a) (ECX unused), returns a string pointer: o = engine table slot 0x58(a); 0x6b98a0 when none. name = [o+4] or "<NONAME>" (0x67c8e8); when _stricmp(name, "Ground") != 0 returns name;
// otherwise q = o->slot0x20() and returns [q+4] when set, else "<NONAME>".
static u32 STDCALL fn601a80(u32 a) {
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x58, a);
  if (!o) return 0x6b98a0;
  u32 nm = *(u32 *)(o + 4);
  u32 pick = nm ? nm : 0x67c8e8;
  if (G(stricmp_t, 0x676414)((const char *)pick, (const char *)0x6b9898) != 0) {
    u32 nm2 = *(u32 *)(o + 4);
    return nm2 ? nm2 : 0x67c8e8;
  }
  u8 *q = vcall<u8 *>(o, 0x20);
  u32 x = *(u32 *)(q + 4);
  return x ? x : 0x67c8e8;
}
PCREG(601a80, fn601a80);

// 0x620890, cdecl(st, obj), returns EAX: byte [obj+0x1c] = 1; old = [st+0x124]; [st+0x124] = the address of a 16-byte local {0, 0, old, obj}; edi = [obj+4], esi = edi + [obj+8]; r = the function pointer in the
// first dword of the object h = [st+0xe0] called with (h, edi, esi, &a8) (cdecl, a8 = the incoming st slot); then 0x61dcd0(st, [st+0xe0], edi, esi, r, a8, 0); byte [obj+0x1c] = 0; [st+0x124] = old.
static u32 fn620890(u8 *st, u8 *obj) {
  u32 frame[4];
  u32 a8 = (u32)st;
  obj[0x1c] = 1;
  u32 old = *(u32 *)(st + 0x124);
  *(u32 *)(st + 0x124) = (u32)frame;
  u32 edi = *(u32 *)(obj + 4);
  u32 esi = *(u32 *)(obj + 8) + edi;
  u8 *h = *(u8 **)(st + 0xe0);
  frame[0] = 0;
  frame[1] = 0;
  frame[2] = old;
  frame[3] = (u32)obj;
  u32 r = (*(cb4_t *)h)((u32)h, edi, esi, (u32)&a8);
  u32 res = ext_61dcd0((u32)st, *(u32 *)(st + 0xe0), edi, esi, r, a8, 0);
  obj[0x1c] = 0;
  *(u32 *)(st + 0x124) = old;
  return res;
}
PCREG(620890, fn620890);

// 0x6322e0, cdecl(S, ctx, out): when out: [out] = [S+0x3c]. kinds 4 and 5: ctx function pointer at +0x24 called with ([ctx+0x28], [S+0xc]) (cdecl). Kind 6: 0x633170([S+4], ctx). Then [S+0x30] = [S+0x34] = [S+0x28];
// kind, [S+0x1c], [S+0x20] = 0; when the stdcall hook pointer at [S+0x38] exists: r = it(0, 0, 0), [S+0x3c] = [ctx+0x30] = r.
static void fn6322e0(u8 *S, u8 *ctx, u32 *out) {
  if (out) *out = *(u32 *)(S + 0x3c);
  u32 kind = *(u32 *)S;
  if (kind == 4 || kind == 5) (*(cb2_t *)(ctx + 0x24))(*(u32 *)(ctx + 0x28), *(u32 *)(S + 0xc));
  if (*(u32 *)S == 6) ext_633170(*(u32 *)(S + 4), (u32)ctx);
  u32 v = *(u32 *)(S + 0x28);
  *(u32 *)(S + 0x34) = v;
  *(u32 *)(S + 0x30) = v;
  u32 fp = *(u32 *)(S + 0x38);
  *(u32 *)S = 0;
  *(u32 *)(S + 0x1c) = 0;
  *(u32 *)(S + 0x20) = 0;
  if (fp) {
    u32 r = ((std3_t)fp)(0, 0, 0);
    *(u32 *)(S + 0x3c) = r;
    *(u32 *)(ctx + 0x30) = r;
  }
}
PCREG(6322e0, fn6322e0);
