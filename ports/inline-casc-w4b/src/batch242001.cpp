// batch242001.cpp - Sonnet-w4b, hand ports of tier-3 (unreachable-but-probably-used) helpers: tail-jump thunks, vtable-slot siblings.
#include "ff.h"

#define R32(a) (*(u32 *)(u32)(a))
#define W32(a, v) (*(u32 *)(u32)(a) = (u32)(v))
#define R8(a) (*(u8 *)(u32)(a))

extern "C" u32 THISCALL ext_46b800_thiscall2(u32, u32, u32) __asm__("ext_46b800");
extern "C" u32 THISCALL ext_4c1a00_thiscall1(u32, u32) __asm__("ext_4c1a00");
extern "C" u32 THISCALL ext_4f9af0_thiscall0(u32) __asm__("ext_4f9af0");

// 0x46ba90: `push ebp; mov ebp,esp; pop ebp; jmp 0x46b800` - tail jump to a thiscall(2 args)
extern "C" u32 THISCALL port_46ba90(u32 self, u32 a0, u32 a1) { return ext_46b800_thiscall2(self, a0, a1); }
PCREG(46ba90, port_46ba90);

// 0x4bcd60: same shape, tail jump to 0x4c1a00 (thiscall, 1 arg)
extern "C" u32 THISCALL port_4bcd60(u32 self, u32 a0) { return ext_4c1a00_thiscall1(self, a0); }
PCREG(4bcd60, port_4bcd60);

// 0x41e010: `mov eax,[0x6fcd78]; jmp eax` - tail jump through a global function pointer, arguments and ecx pass through untouched
extern "C" __attribute__((naked)) void port_41e010() { __asm__ volatile("movl 0x6fcd78, %eax\n\tjmp *%eax"); }
PCREG(41e010, port_41e010);

// 0x4f9b90: this->init_4f9af0(); this->vslot_0x36c(this->field_0x9b); tail call this->vslot_0x358()
extern "C" u32 THISCALL port_4f9b90(u32 self) {
  ext_4f9af0_thiscall0(self);
  ((u32(THISCALL *)(u32, u32))R32(R32(self) + 0x36c))(self, R32(self + 0x9b));
  return ((u32(THISCALL *)(u32))R32(R32(self) + 0x358))(self);
}
PCREG(4f9b90, port_4f9b90);

// 0x4afed0: A = engine.table->slot138(); A->slot4c(0x69206c, engine.table->slot4c(this->field_0x44))
extern "C" u32 THISCALL port_4afed0(u32 self) {
  u32 T = R32(R32(0x70039c) + 0x9b);
  u32 A = ((u32(THISCALL *)(u32))R32(R32(T) + 0x138))(T);
  u32 G2 = R32(0x70039c);
  u32 a = R32(self + 0x44);
  u32 T2 = R32(G2 + 0x9b);
  u32 vtA = R32(A);
  u32 vT2 = R32(T2);
  u32 r = ((u32(THISCALL *)(u32, u32))R32(vT2 + 0x4c))(T2, a);
  return ((u32(THISCALL *)(u32, u32, u32))R32(vtA + 0x4c))(A, 0x69206c, r);
}
PCREG(4afed0, port_4afed0);

// 0x4d29d0: compact a list of [size][live byte]...[payload] records in place (this+8 = buffer, this+0xc = used bytes);
// live records are memmove'd down (IAT 0x676278), the used size becomes the compacted size
extern "C" u32 THISCALL port_4d29d0(u32 self) {
  u32 ebx = 0, esi = 0;
  if (R32(self + 0xc) > ebx) {
    do {
      u32 edx = R32(self + 8);
      u32 eax = R32(edx + esi);
      u32 ecx = edx + esi;
      esi += eax;
      if (R8(ecx + 4) != 0) {
        edx += ebx;
        ebx += eax;
        if (esi != ebx) ((u32(__attribute__((cdecl)) *)(u32, u32, u32))R32(0x676278))(edx, ecx, eax);
      }
    } while (esi < R32(self + 0xc));
  }
  W32(self + 0xc, ebx);
  return 0;
}
PCREG(4d29d0, port_4d29d0);
