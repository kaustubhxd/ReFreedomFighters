// batch38016.cpp - cascade s8 batch 38016: 0x50bd00 (resolve an object from one of two named ids and register its handle).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);  // ret 4
extern "C" u32 THISCALL ext_506040(u8 *self);
extern "C" void THISCALL ext_50d7b0(u8 *self, u32 *a); // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log2_t)(void *, u32);
typedef u32(*log3_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))

static void *log_stream(u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  return (void *)SLOT(lg, 0x20, v2_t)(lg, 0x69d420, line);
}
// logs line `line` with the text of the request's name (req[4] through 0x5003d0 / 0x506040).
static void log_name(u8 *req, u32 line, u32 fmt) {
  void *st = log_stream(line);
  u8 *r = ext_5003d0(*(u8 **)(req + 4), 0);
  u32 txt = ext_506040(r);
  (*(log3_t **)st)[0x2c / 4](st, fmt, txt);
}

// 0x50bd00, stdcall(req) ret 4: two ids are fetched by name (0x690ad0 / 0x690adc, helper slot 0x88 through the table object's slot 0x138) and resolved with the table's slot 0x58.
// When both fail the error line 0xd9 is logged. Otherwise the resolved object's slot 0x25c is asked for the object named by req[4] (0x5003d0 + 0x506040; the first
// resolved one wins), error 0xe5 if none; that object's slot 0x2c4 (table field +0xadc, tag 'MEIT') goes through the table's slot 0x4c to a handle (error 0xeb if null) which is
// registered with req[8] through 0x50d7b0 (by pointer).
extern "C" __attribute__((used, noinline)) u32 ff_inner_50bd00(u8 *req) {
  u8 *t = TABLE;
  u8 *x = (u8 *)SLOT(t, 0x138, v0_t)(t);
  u32 l4 = 0;
  SLOT(x, 0x88, v2_t)(x, 0x690ad0, (u32)&l4);
  t = TABLE;
  u8 *esi = (u8 *)SLOT(t, 0x58, v1_t)(t, l4);
  t = TABLE;
  x = (u8 *)SLOT(t, 0x138, v0_t)(t);
  u32 l8 = 0;
  SLOT(x, 0x88, v2_t)(x, 0x690adc, (u32)&l8);
  t = TABLE;
  u8 *edi = (u8 *)SLOT(t, 0x58, v1_t)(t, l8);
  u8 *o = ext_5003d0(*(u8 **)(req + 8), 0);
  ext_5002f0(o, 0);
  u8 *obj;
  u32 r2;
  if (esi == 0) {
    if (edi == 0) {
      void *st = log_stream(0xd9);
      (*(log2_t **)st)[0x2c / 4](st, 0x69d53c);
      return 0;
    }
    u8 *r = ext_5003d0(*(u8 **)(req + 4), 0);
    r2 = ext_506040(r);
    obj = (u8 *)SLOT(edi, 0x25c, v1_t)(edi, r2);
  } else {
    u8 *r = ext_5003d0(*(u8 **)(req + 4), 0);
    r2 = ext_506040(r);
    obj = (u8 *)SLOT(esi, 0x25c, v1_t)(esi, r2);
  }
  if (!obj) {
    void *st = log_stream(0xe5);
    u8 *r = ext_5003d0(*(u8 **)(req + 4), 0);
    u32 txt = ext_506040(r);
    (*(log3_t **)st)[0x2c / 4](st, 0x69d578, txt);
    return 1;
  }
  u8 *e = ENG;
  t = *(u8 **)(e + 0x9b);
  u32 tag = SLOT(obj, 0x2c4, v2_t)(obj, *(u32 *)(t + 0xadc), 0x4954454d);
  t = TABLE;
  u32 h = SLOT(t, 0x4c, v1_t)(t, tag);
  if (h == 0) {
    void *st = log_stream(0xeb);
    u8 *r = ext_5003d0(*(u8 **)(req + 4), 0);
    u32 txt = ext_506040(r);
    (*(log3_t **)st)[0x2c / 4](st, 0x69d5b8, txt);
    h = 0;
  }
  u32 loc = h;
  u8 *r = ext_5003d0(*(u8 **)(req + 8), 0);
  ext_50d7b0(r, &loc);
  return 1;
}
// The original leaves one dword of 'push 0' on the stack on every path except the both-ids-missing one (0x5003d0 pops only one of the two pushed zeros), so its epilogue
// pops are shifted by one slot: it returns with EBX = entry ESI, ESI = entry EDI, EDI = 0 (the leaked zero). The wrapper reproduces that on the leaking paths.
__attribute__((naked)) static void STDCALL fn50bd00(u8 *req) {
  asm volatile(
      "push %esi\n"
      "push %edi\n"
      "pushl 12(%esp)\n"
      "call ff_inner_50bd00\n"
      "add $4, %esp\n"
      "pop %edi\n"
      "pop %esi\n"
      "test %eax, %eax\n"
      "jz 1f\n"
      "mov %esi, %ebx\n"
      "mov %edi, %esi\n"
      "xor %edi, %edi\n"
      "1: ret $4\n");
}
PCREG(50bd00, fn50bd00);
