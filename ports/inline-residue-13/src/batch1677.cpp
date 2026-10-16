// batch1677.cpp - 0x46a290 (GUESS, residue 13 gap band, 2026-10-12). A 607-byte constructor (ZItem family), thiscall, three
// stack arguments, ret 0xc, returns this. Body: ZItem::ZItem(this, a1, a2, a3) (0x469980, hooked, ret 0xc); the vtable
// 0x6872ac; zeroed and set fields; four 16-bit message ids from the manager's slot 0x114 (name, 0, "zitem.cpp", line) into
// +0xa2 ("Activate", line 0x8eb), +0xa4 ("FrameStart", 0x8ec), +0xa6 ("FrameEnd", 0x8ed), +0xa8 ("WeaponFired", 0x8ee);
// new(0x1c) (0x41e290, hooked, cdecl) then REFTAB(obj, 8, 0) (0x4ccbe0, hooked, ret 8) with the result (the constructor's
// eax, which is the value stored) at +0xd9 (0 when the allocation is null); new(0x108) then 0x4d83b0(obj, "BlockFire",
// "Blocks fire...", 0x6ff988) (hooked, ret 0xc) with the result stored at +0x9e; then the system object's slot 0x1a4(value).
// SEH frame not reproduced. Its epilogue leaves ecx = [0x6f5630] ^ (entry esp - 4) and esi = the caller's (restored).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469980[], ext_41e290[], ext_4ccbe0[], ext_4d83b0[];
typedef void(THISCALL *ZItemCtor)(void *self, u32 a, u32 b, u32 c);
typedef u32(*NewFn)(u32 size);
typedef u32(THISCALL *Ctor2)(void *self, u32 a, u32 b);
typedef u32(THISCALL *Ctor3r)(void *self, u32 a, u32 b, u32 c);

static u32 MsgId(u32 name, u32 line) {
  u8 *R = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  return vcall<u16>(R, 0x114, name, (u32)0, (u32)0x6887c4u, line);
}

extern "C" u32 ctorCore8(void *self, u32 a1, u32 a2, u32 a3) {
  u8 *esi = (u8 *)self;
  ((ZItemCtor)(void *)ext_469980)(self, a1, a2, a3);
  AT(u32, esi, 0) = 0x6872acu;
  AT(u32, esi, 0xba) = 0;
  AT(u32, esi, 0xc8) = 0;
  AT(u32, esi, 0xcd) = 0x3f800000u;
  AT(u8, esi, 0xcc) = 0;
  AT(u8, esi, 0xbe) = 0;
  AT(u32, esi, 0xc0) = 0;
  AT(u32, esi, 0xc4) = 0;
  AT(u32, esi, 0xaa) = 0;
  AT(u32, esi, 0xae) = 0;
  AT(u32, esi, 0xb2) = 0;
  AT(u32, esi, 0xd1) = 0;
  AT(u32, esi, 0x105) = 0xffffffffu;
  AT(u32, esi, 0xf1) = 0;
  AT(u32, esi, 0xf5) = 0;
  AT(u32, esi, 0xf9) = 0;
  AT(u32, esi, 0x109) = 0;
  AT(u32, esi, 0x10d) = 0;
  AT(u32, esi, 0x111) = 0;
  AT(u32, esi, 0xdd) = 0;
  AT(u32, esi, 0xe5) = 0;
  AT(u32, esi, 0xe9) = 0;
  AT(u32, esi, 0xfd) = 0;
  AT(u32, esi, 0x101) = 0;
  AT(u16, esi, 0xa2) = (u16)MsgId(0x682e18u, 0x8ebu);
  AT(u16, esi, 0xa4) = (u16)MsgId(0x688c10u, 0x8ecu);
  AT(u16, esi, 0xa6) = (u16)MsgId(0x688c1cu, 0x8edu);
  AT(u16, esi, 0xa8) = (u16)MsgId(0x688c28u, 0x8eeu);
  u32 obj = ((NewFn)(void *)ext_41e290)(0x1cu);
  u32 r = 0;
  if (obj) r = ((Ctor2)(void *)ext_4ccbe0)((void *)obj, 8u, 0u);
  AT(u32, esi, 0xd9) = r;
  u32 obj2 = ((NewFn)(void *)ext_41e290)(0x108u);
  u32 e = 0;
  if (obj2) e = ((Ctor3r)(void *)ext_4d83b0)((void *)obj2, 0x688c54u, 0x688c34u, 0x6ff988u);
  AT(u32, esi, 0x9e) = e;
  u8 *sys = AT(u8 *, 0x70039c, 0);
  vcall<void>(sys, 0x1a4, e);
  return (u32)esi;
}

__asm__(
    ".globl ctorWrapper8\n"
    "ctorWrapper8:\n"
    "  movl %ecx, factorySelf8\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin8\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf8\n"
    "  call ctorCore8\n"
    "  addl $16, %esp\n"
    "  movl factoryFin8, %ecx\n"
    "  ret $12\n");
extern "C" u32 factorySelf8 = 0;
extern "C" u32 factoryFin8 = 0;
extern "C" void ctorWrapper8();
PCREG(46a290, ctorWrapper8);
