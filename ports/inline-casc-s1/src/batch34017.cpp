// batch34017.cpp - cascade tier E, batch 34017: 0x54ab90 (dispatch on a record kind), 0x54c3f0 (build a 12-dword descriptor and ask a factory object
// to accept it), 0x5219c0 (look up an object by id and push its transformed vector to this).
#include "ff.h"

extern "C" void THISCALL ext_54dff0(void *self, void *p);                       // thiscall ret 4
extern "C" void FASTCALL ext_43e920(void *ecx, void *edx, void *arg);          // fastcall, 1 stack arg
extern "C" void FASTCALL ext_633654(u32 cookie);                               // /GS check, fastcall(ecx)
typedef u32 (*hook_t)();

// 0x54ab90, thiscall(p) ret 4: 0x54dff0(this, p); by kind = [p]: 1 -> slot 0x68(p), 2 -> slot 0x64(p), otherwise the assert hook at 0x7003b0
// (int3 when it is null) and carry on; then [this+0x63d7] = [p+0x4c] (unaligned), slot 0x70(), slot 0x6c(p).
static void THISCALL fn54ab90(u8 *self, u8 *p) {
  ext_54dff0(self, p);
  u32 kind = *(u32 *)p;
  if (kind == 1) {
    vcall<void>(self, 0x68, (u32)p);
  } else if (kind == 2) {
    vcall<void>(self, 0x64, (u32)p);
  } else {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 v = *(u32 *)(p + 0x4c);
  u8 *d = self + 0x63d7;
  d[0] = v; d[1] = v >> 8; d[2] = v >> 16; d[3] = v >> 24;
  vcall<void>(self, 0x70);
  vcall<void>(self, 0x6c, (u32)p);
}
PCREG(54ab90, fn54ab90);

// 0x54c3f0, thiscall, no args: f = this->slot0x40(); build the descriptor {6, 0, 1, 0x5622, 0x10, 0x20, (unset), 1, 0, 0x10, 2, 1} on the stack;
// when f->slot8(&desc, 1) (thiscall, bool) fails: f->slot4(1) and return 0; else return f.
static u8 *THISCALL fn54c3f0(u8 *self) {
  u32 d[12];
  d[0] = 6; d[1] = 0; d[2] = 1; d[3] = 0x5622; d[4] = 0x10; d[5] = 0x20;
  d[7] = 1; d[8] = 0; d[9] = 0x10; d[10] = 2; d[11] = 1;
  u8 *f = vcall<u8 *>(self, 0x40);
  if (!vcall<bool>(f, 8, (u32)d, 1u)) {
    vcall<void>(f, 4, 1u);
    return 0;
  }
  return f;
}
PCREG(54c3f0, fn54c3f0);

// 0x5219c0, thiscall(id) ret 4: when id != 0: obj = engine->table->slot0x58(id); v = {0,0,0}; obj->slot0x84(&v); 0x43e920(&out, &v, this+0x60);
// this->slot0x378(&out). Then the /GS check.
static void THISCALL fn5219c0(u8 *self, u32 id) {
  if (id) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tbl = *(u8 **)(eng + 0x9b);
    u8 *obj = vcall<u8 *>(tbl, 0x58, id);
    u32 v[3] = {0, 0, 0};
    u32 out[3];
    vcall<void>(obj, 0x84, (u32)v);
    ext_43e920(out, v, self + 0x60);
    vcall<void>(self, 0x378, (u32)out);
  }
  ext_633654(0);
}
PCREG(5219c0, fn5219c0);
