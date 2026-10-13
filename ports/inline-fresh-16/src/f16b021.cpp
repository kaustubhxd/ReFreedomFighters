// f16b021.cpp - fresh slice 16, batch 21 (2026-10-12).
// 0x5fcb80 PPOLibrary_t::loadProcess(name, host, flag, deps, flag2): byte [this] set -> 0. ppo = loadDependencies(this;
//           name, deps, flag2); p = new(0xad2); proc = p ? Process_t::Process_t(p; ppo+0x3c, host, flag) (its eax) : 0;
//           host -> patchPrecompiledBinary(this; ppo, proc, host). Returns proc. Ret 0x14. SEH not reproduced.
// 0x45ae80 (fastcall a, b; c, d): d -> 0x45ace0(fastcall d, c; a, b); else p = 0x45c4b0(0x24): ZSTDOBJ(p; c, a, b), vtable
//           0x683e50, +0x18/+0x1c/+0x20 = 10.0f, SetPrim([p+8]; 0). Returns p or 0. SEH not reproduced.
// 0x5b8340 ZFFSimpleTrain2::ZFFSimpleTrain2(): 0x469870(this); +4 |= 0x20; +0x44 = 0; vtable 0x6b260c; clears +0xe6, +0x4c,
//           b+0xb2, +0xb3, b+0xdd, +0xe2, b+0x60; word +0xdb = RegisterZMsg(0x6b26c8, 0, 0x6b2690, 0x26). SEH not reproduced.
// 0x43e640 ZHELPER::Draw(buf, cam, a, b): flags = +0x18: &1 buf slot 0x80(a, b, cam); &8 buf slot 0xdc(a, b, [+8]+0x40);
//           &2 buf slot 0x88(a, b, [+8]+0x40); &4 buf slot 0xdc(a, b, {0.1f, 0.1f, +0x34 * 0.5f}). Cookie not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_5fc590[], ext_41e290[], ext_5f3480[], ext_5fcd70[], ext_45ace0[], ext_45c4b0[], ext_43de40[],
    ext_4dcdf0[], ext_469870[];

extern "C" void *THISCALL f16_5fcb80(u8 *self, u32 name, void *host, u32 flag, u32 deps, u32 flag2) {
  if (*self) return 0;
  u8 *ppo = ((u8 * (THISCALL *)(void *, u32, u32, u32))(void *)ext_5fc590)(self, name, deps, flag2);
  void *p = ((void *(*)(u32))(void *)ext_41e290)(0xad2);
  void *proc = p ? ((void *(THISCALL *)(void *, void *, void *, u32))(void *)ext_5f3480)(p, ppo + 0x3c, host, flag) : 0;
  if (host) ((void(THISCALL *)(void *, void *, void *, void *))(void *)ext_5fcd70)(self, ppo, proc, host);
  return proc;
}

extern "C" void *FASTCALL f16_45ae80(u32 a, u32 b, u32 c, u32 d) {
  if (d) return ((void *(FASTCALL *)(u32, u32, u32, u32))(void *)ext_45ace0)(d, c, a, b);
  u8 *p = (u8 *)((void *(*)(u32))(void *)ext_45c4b0)(0x24);
  if (!p) return 0;
  ((void(THISCALL *)(void *, u32, u32, u32))(void *)ext_43de40)(p, c, a, b);
  AT(u32, p, 0) = 0x683e50u;
  AT(u32, p, 0x18) = 0x41200000u;
  AT(u32, p, 0x1c) = 0x41200000u;
  AT(u32, p, 0x20) = 0x41200000u;
  ((void(THISCALL *)(void *, u32))(void *)ext_4dcdf0)(AT(void *, p, 8), 0);
  return p;
}

extern "C" void *THISCALL f16_5b8340(u8 *self) {
  ((void(THISCALL *)(void *))(void *)ext_469870)(self);
  AT(u32, self, 4) |= 0x20;
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0) = 0x6b260cu;
  AT(u32, self, 0xe6) = 0;
  AT(u32, self, 0x4c) = 0;
  AT(u8, self, 0xb2) = 0;
  AT(u32, self, 0xb3) = 0;
  AT(u8, self, 0xdd) = 0;
  AT(u32, self, 0xe2) = 0;
  AT(u8, self, 0x60) = 0;
  AT(u16, self, 0xdb) = (u16)vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x114, 0x6b26c8u, 0u, 0x6b2690u, 0x26u);
  return self;
}

extern "C" void THISCALL f16_43e640(u8 *self, void *buf, u32 cam, u32 a, u32 b) {
  if (AT(u8, self, 0x18) & 1) vcall<void>(buf, 0x80, a, b, cam);
  if (AT(u8, self, 0x18) & 8) vcall<void>(buf, 0xdc, a, b, AT(u8 *, self, 8) + 0x40);
  if (AT(u8, self, 0x18) & 2) vcall<void>(buf, 0x88, a, b, AT(u8 *, self, 8) + 0x40);
  if (AT(u8, self, 0x18) & 4) {
    volatile float v[3];
    v[0] = 0.1f;
    v[1] = 0.1f;
    v[2] = AT(float, self, 0x34) * 0.5f;
    vcall<void>(buf, 0xdc, a, b, (float *)v);
  }
}

PCREG(5fcb80, f16_5fcb80);
PCREG(45ae80, f16_45ae80);
PCREG(5b8340, f16_5b8340);
PCREG(43e640, f16_43e640);
