// batch1204.cpp - fresh slice 12, batch 4. Names are FUN_ in the exe list (no map entry) except the CRT callees.
// Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);   // sized operator delete
extern "C" void __attribute__((cdecl)) ext_45c510(void *p);             // delete wrapper
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 size);   // sized delete
extern "C" void *__attribute__((cdecl)) ext_634d10(void *p, s32 v, u32 n);   // memset (CRT)
extern "C" double __attribute__((cdecl)) ext_634da6(double x);          // ceil (CRT, result in ST0)
extern "C" void THISCALL ext_4ee440(u8 *self);                          // base destructor, ret 0
extern "C" void THISCALL ext_54f870(u8 *self, u8 *node, u32 tag);       // ret 8

typedef u32(__attribute__((cdecl)) * failfn)();
static inline u32 fail_7003b0() {
  failfn f = G(failfn, 0x7003b0);
  if (!f) asm volatile("int3");
  return f();
}

// 0x5bc680: m = engine(+0x9b)->slot 0x138(); id = 0; m->slot 0x88(0x6ac89c, &id); +0x48 = engine->slot 0x58(id);
// word +0x4c = 0. EAX = the slot 0x58 result.
static u32 THISCALL f5bc680(u8 *self) {
  u8 *m = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x138);
  u32 id = 0;
  vcall<u32>(m, 0x88, 0x6ac89c, &id);
  u32 h = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, id);
  *(u32 *)(self + 0x48) = h;
  *(u16 *)(self + 0x4c) = 0;
  return h;
}
PCREG(5bc680, f5bc680);

// 0x655c40: allocates n*8 bytes from engine(+0x190f)->slot 0x20()->slot 0x14(size) and zeroes them; n*8 == 0 gives 0
// (memset(0, 0, 0) still runs). stdcall-like thiscall, ret 4.
static void *THISCALL alloc8(u8 *, u32 n) {
  u32 sz = n * 8;
  void *p;
  if (!sz) {
    p = 0;
  } else {
    u8 *a = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x190f), 0x20);
    p = vcall<void *>(a, 0x14, sz);
  }
  ext_634d10(p, 0, sz);
  return p;
}
PCREG(655c40, alloc8);

// 0x560380: dispatch on word +0x10 of the message through the handler table 0x7141a0 (count at 0x714198); handlers
// get ECX unchanged and the same stack argument (tail jmp). An id out of range logs message 0x83 through the log object
// at 0x700390 and returns the failure handler's result. ret 4.
typedef u32(THISCALL *handler_t)(void *self, u8 *msg);
static u32 THISCALL dispatchMsg(void *self, u8 *msg) {
  u32 id = *(u16 *)(msg + 0x10);
  if (id < G(u32, 0x714198)) return (*(handler_t *)(0x7141a0 + id * 4))(self, msg);
  typedef void(__attribute__((cdecl)) * printfn)(u8 *, u32, u32);
  u8 *pr = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6a622c, 0x83);
  (*(printfn *)(*(u8 **)pr + 0x2c))(pr, 0x69c6b0, 0x69ca40);
  return fail_7003b0();
}
PCREG(560380, dispatchMsg);

// 0x4f4400: deleting destructor: vtable 0x699664, delete +0xac (size 1) if set, base 0x4ee440; flags bit 0 -> delete
// this (bit 2: sized 0xb4 via 0x4690b0, else 0x45c510). Returns this. ret 4.
static u8 *THISCALL sdd4f4400(u8 *self, u32 flags) {
  void *b = *(void **)(self + 0xac);
  *(u32 *)self = 0x699664;
  if (b) ext_634273(b, 1);
  ext_4ee440(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0xb4);
    else ext_45c510(self);
  }
  return self;
}
PCREG(4f4400, sdd4f4400);

// 0x4f74c0: v = (float)ceil(x); when v differs from +0xa3 (unordered counts as different): +0xa3 = v and
// vslot 0x358(arg). ret 8.
static void THISCALL setCeil(u8 *self, float x, u32 arg) {
  float v = (float)ext_634da6((double)x);
  if (!(v == *(float *)(self + 0xa3))) {
    *(float *)(self + 0xa3) = v;
    vcall<u32>(self, 0x358, arg);
  }
}
PCREG(4f74c0, setCeil);

// 0x4ee640: when the alignment byte +0x20 has a low-nibble bit but not bit 0: subtracts (float)(bit 2 ? x >> 1 : x)
// from the first float of the n 40-byte records just before p. ret 0xc.
static void THISCALL shiftRecords(u8 *self, s32 x, s32 n, u8 *p) {
  u8 f = self[0x20];
  if (!(f & 0xf) || (f & 1)) return;
  s32 v = (f & 4) ? (x >> 1) : x;
  if (!n) return;
  float fv = (float)v;
  float *q = (float *)(p - 40 * n);
  for (s32 i = n; i; i--) {
    *q = *q - fv;
    q = (float *)((u8 *)q + 0x28);
  }
}
PCREG(4ee640, shiftRecords);

// 0x5fb600: clears the bucket array [+3, +7): every chain node (next at +0) goes to 0x54f870(node, 0xa), the bucket is
// zeroed; then +0xf = 0.
static void THISCALL clearBuckets(u8 *self) {
  u32 i = 0;
  if ((s32)(*(u32 *)(self + 7) - *(u32 *)(self + 3)) >> 2) {
    do {
      u8 *n = ((u8 **)*(u32 *)(self + 3))[i];
      while (n) {
        u8 *nx = *(u8 **)n;
        ext_54f870(self, n, 0xa);
        n = nx;
      }
      ((u32 *)*(u32 *)(self + 3))[i] = 0;
      i++;
    } while (i < (u32)((s32)(*(u32 *)(self + 7) - *(u32 *)(self + 3)) >> 2));
  }
  *(u32 *)(self + 0xf) = 0;
}
PCREG(5fb600, clearBuckets);

// 0x499c80: writes a string to the stream (slot 0x10(data, size)): length incl. the NUL as a dword, then the bytes;
// a null string writes the dword 0 only. Returns this. ret 4.
static u8 *THISCALL writeStr(u8 *self, const char *s) {
  if (!s) {
    u32 z = 0;
    vcall<u32>(self, 0x10, &z, 4);
    return self;
  }
  const char *e = s;
  while (*e++) {
  }
  u32 len = (u32)(e - s);
  vcall<u32>(self, 0x10, &len, 4);
  vcall<u32>(self, 0x10, s, len);
  return self;
}
PCREG(499c80, writeStr);

// 0x64c780: r = mgr(+0x1aa3)->slot 0x80(x); y = x < 0x800 ? x : x - 0x800; when y != 0 and the u16 at r != y the
// failure handler runs; returns mgr->slot 0x80(y). ret 4.
static u32 THISCALL f64c780(u8 *, u32 x) {
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  u16 *r = vcall<u16 *>(mgr, 0x80, x);
  u32 y = x < 0x800 ? x : x - 0x800;
  if (y && *r != y) fail_7003b0();
  mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  return vcall<u32>(mgr, 0x80, y);
}
PCREG(64c780, f64c780);
