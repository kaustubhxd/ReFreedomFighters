// batch35191.cpp - cascade s5 batch 35191 (tier H): 0x50e920 (GUESS read an entity's orientation vector into the global scratch and store its negation in three record slots).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4: returns a record pointer
extern "C" void THISCALL ext_4e09b0(float *v);           // negates three floats, plain ret
typedef u32 (*hook_t)();
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *l2_t)(void *, u32, u32);

// Log through the logger at 0x700390: r = slot 0x20(a, b); slot 0x2c(r, ...) with ECX = the vtable, caller-popped.
#define LOG_OPEN(a, b)                    \
  u8 *lg = G(u8 *, 0x700390);             \
  u8 *r = (*(l2_t **)lg)[0x20 / 4](lg, a, b); \
  u32 vt = *(u32 *)r;                     \
  u32 slot = ((u32 *)vt)[0x2c / 4];

// A record slot check: when byte [rec+4] is neither 0 nor 2 a log line (0x104) goes out and the assert hook 0x7003b0 is called (int3 when null); then [rec+4] = 2 and float [rec] = x.
static void setSlot(u8 *rec, u32 xbits) {
  u8 k = rec[4];
  if (k != 0 && k != 2) {
    LOG_OPEN(0x69c8e0u, 0x104u)
    asm volatile("push $0x69c938\n\tpush $0x69c6b0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  rec[4] = 2;
  *(u32 *)rec = xbits;
}

// 0x50e920, stdcall(a) ret 4, no return value. e = engine[+0x9b] slot 0x58([0x5003d0(a[4], 0)]); e: e slot 0x80(0x70148c, 0x701480), otherwise the logger slot 0x20(0x69db34, 0x2e3) and slot 0x2c(r, 0x69dff0, [0x5003d0(a[4], 0)]).
// Then floats 0x701480..0x701488 = 0x70148c..0x701494; 0x4e09b0(0x701480) negates them; slots 0x5003d0(a[8], 0/1/2) get the three values through setSlot.
static void STDCALL fn50e920(u8 *a) {
  u32 id = *(u32 *)ext_5003d0(*(u32 *)(a + 4), 0);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *e = (*(e1_t **)tab)[0x58 / 4](tab, id);
  if (e) {
    (*(v2_t **)e)[0x80 / 4](e, 0x70148c, 0x701480);
  } else {
    LOG_OPEN(0x69db34u, 0x2e3u)
    u32 id2 = *(u32 *)ext_5003d0(*(u32 *)(a + 4), 0);
    asm volatile("push %[id]\n\tpush $0x69dff0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [id] "r"(id2), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  }
  *(u32 *)0x701480 = *(u32 *)0x70148c;
  *(u32 *)0x701484 = *(u32 *)0x701490;
  *(u32 *)0x701488 = *(u32 *)0x701494;
  ext_4e09b0((float *)0x701480);
  u32 x = *(u32 *)0x701480;
  setSlot(ext_5003d0(*(u32 *)(a + 8), 0), x);
  u32 y = *(u32 *)0x701484;
  setSlot(ext_5003d0(*(u32 *)(a + 8), 1), y);
  u32 z = *(u32 *)0x701488;
  setSlot(ext_5003d0(*(u32 *)(a + 8), 2), z);
}
PCREG(50e920, fn50e920);
