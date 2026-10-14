// batch35011.cpp - cascade s5 batch 35011: 0x424d90 (GUESS network object constructor: window message id, WinSock start-up, host lookup).
#include "ff.h"

extern "C" void THISCALL ext_42acc0(u8 *self);   // base constructor, plain ret
typedef u32(STDCALL *imp1_t)(u32);
typedef u32(STDCALL *imp2_t)(u32, void *);
typedef u32(STDCALL *imp3_t)(void *, u32, u32);

// 0x424d90, thiscall, no arguments, returns this. Base constructor 0x42acc0, vtable 0x67864c, fields cleared (+0x28, +0x12, +0x18, +0x1c, +0x10, +0x13, +0x24), +0x14 = 10,
// [+4] = RegisterWindowMessageA(0x67869c), global 0x700390 = this. WSAStartup(0x202, &data) must return 0 with version 2.2 (int3 otherwise; WSACleanup first for a bad version).
// Then the global 0x6fd930 = gethostbyname(0x6786ac); when null, a = inet_addr(0x6786b8) and the global = gethostbyaddr(&buf (16 bytes, buf[1] = a), 0x10, 0).
static u8 *THISCALL fn424d90(u8 *self) {
  u8 wsa[0x1a0];
  u32 buf[4];
  ext_42acc0(self);
  *(u32 *)self = 0x67864c;
  *(u32 *)(self + 0x28) = 0;
  self[0x12] = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  self[0x10] = 0;
  self[0x13] = 0;
  *(u32 *)(self + 0x14) = 0xa;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 4) = (*(imp1_t *)0x6761d0)(0x67869c);
  G(u8 *, 0x700390) = self;
  if ((*(imp2_t *)0x6762a8)(0x202, wsa)) __asm__ volatile("int3");
  u32 ver = *(u32 *)wsa;
  if ((u8)ver != 2 || (u8)(ver >> 8) != 2) {
    (*(u32(STDCALL **)())0x6762ac)();
    __asm__ volatile("int3");
  }
  u32 h = (*(imp1_t *)0x6762a0)(0x6786ac);
  G(u32, 0x6fd930) = h;
  if (!h) {
    buf[1] = (*(imp1_t *)0x6762b8)(0x6786b8);
    G(u32, 0x6fd930) = (*(imp3_t *)0x676298)(buf, 0x10, 0);
  }
  return self;
}
PCREG(424d90, fn424d90);
