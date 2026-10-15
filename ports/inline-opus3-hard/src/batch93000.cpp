// batch93000.cpp - hard-function trial opus 3: an SEH function whose EH state changes around live objects.
#include "ff.h"

extern "C" {
void *ext_634d10(void *dst, int v, u32 n);   // CRT memset (thunk), cdecl
void THISCALL ext_469870(void *self);         // base constructor (objects A and C)
void THISCALL ext_4fb930(void *self);         // constructor of object B
void THISCALL ext_4ccf60(void *self);         // constructor of B's member at +0x98
void THISCALL ext_4fb9a0(void *self);         // constructor of object D
void FASTCALL ext_633654(u32 cookie);         // __security_check_cookie
}

// MSVC C++ EH registration record (fs:[0] chain): next, handler, try-level/state.
struct SehRecord {
  u32 next;
  u32 handler;
  s32 state;
};

static inline u32 teb_exception_list() {
  u32 v;
  asm volatile("movl %%fs:0, %0" : "=r"(v));
  return v;
}
static inline void set_teb_exception_list(u32 v) { asm volatile("movl %0, %%fs:0" : : "r"(v) : "memory"); }

static inline u32 rd32(const void *p) {
  u32 v;
  __builtin_memcpy(&v, p, 4);
  return v;
}
static inline void wr32(void *p, u32 v) { __builtin_memcpy(p, &v, 4); }

// The original's frame below ebp, byte for byte. The objects are dead once registered (state goes back to -1), so
// the compiler reused stack: B's member at B+0x98 lies inside C's slot.
// (2 lead bytes so that, like ebp, the record is 4-byte aligned; the packed members are only touched bytewise or via rec)
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
struct __attribute__((packed, aligned(4))) Frame4fae80 {
  u8 lead[2];
  u8 d[0x62];        // ebp-0x22e
  u8 a[0x60];        // ebp-0x1cc
  u8 b[0x6c];        // ebp-0x16c (its member at +0x98 runs into c)
  u8 c[0xec];        // ebp-0x100
  u8 pad[4];         // ebp-0x14
  u32 cookie;        // ebp-0x10: /GS cookie ^ frame
  SehRecord rec;     // ebp-0xc
};

// Final setup shared by all four objects, then hand it to the engine's object table (slot 0x34) with the EH state
// set to `state` while the call can throw (an unwinder would destroy the object), -1 afterwards.
static void register_obj(volatile SehRecord *rec, u8 *o, s32 state, bool reset_state) {
  wr32(o + 0x44, 0);
  wr32(o + 0x30, 0);
  void *table = (void *)rd32((u8 *)g_pSysInterface + 0x9b);
  wr32(o, 0x686874);   // vtable
  rec->state = state;
  vcall<void>(table, 0x34, (void *)o);
  if (reset_state)
    rec->state = -1;
}

// 0x4fae80: builds four temporary handler objects on the stack and registers each with the engine object table.
extern "C" void RegisterHandlers_4fae80() {
  Frame4fae80 f;
  volatile SehRecord *rec = &f.rec;
  rec->state = -1;
  rec->handler = 0x669b18;
  rec->next = teb_exception_list();
  f.cookie = G(u32, 0x6f5630) ^ (u32)&f.rec.next;
  set_teb_exception_list((u32)rec);

  ext_634d10(f.a, 0, 0x60);
  ext_469870(f.a);
  f.a[4] |= 0x20;
  register_obj(rec, f.a, 0, true);

  ext_4fb930(f.b);
  ext_4ccf60(f.b + 0x98);
  register_obj(rec, f.b, 1, true);

  ext_634d10(f.c, 0, 0xec);
  ext_469870(f.c);
  f.c[4] |= 0x20;
  register_obj(rec, f.c, 2, true);

  ext_4fb9a0(f.d);
  register_obj(rec, f.d, 3, false);

  set_teb_exception_list(rec->next);
  ext_633654(f.cookie ^ (u32)&f.rec.next);
}
PCREG(4fae80, RegisterHandlers_4fae80);
