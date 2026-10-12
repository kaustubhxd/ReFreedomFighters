#include "ff.h"
// batch952.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): sixteen trivial thiscall leaves (no calls, no writes except 0x42ace0).
// Offsets and constants are from the PC bytes. Byte getters return only AL in the exe (the harness compares AL, ret='al').
// Stub rows 0x43e140 (ret 0x1c) and 0x42adb0 (ret 0x14, xor al,al) pop their stack arguments (callee-cleaned).

static void THISCALL zg43e140(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {}                  // ret 0x1c
static u32 THISCALL zg443020(u8 *self) { return *(u32 *)(self + 0x77); }                                             // mov eax,[ecx+0x77]
static u32 THISCALL zg443060(u8 *self) { return *(u32 *)(self + 0x71); }                                             // mov eax,[ecx+0x71]
static u32 THISCALL zg443540(u8 *self) { return *(u8 *)(self + 0x76); }                                              // mov al,[ecx+0x76]
static u32 THISCALL zg443550(u8 *self) { return *(u8 *)(self + 0x5c); }                                              // mov al,[ecx+0x5c]
static u32 THISCALL zg443560(u8 *self) { return *(u8 *)(self + 0x75); }                                              // mov al,[ecx+0x75]
static u32 THISCALL zg452e10(u8 *self) { return *(u32 *)(self + 0x1c); }                                             // mov eax,[ecx+0x1c]
static u32 THISCALL zg453b10(u8 *self) { return (u32)(self + 0x22); }                                                // lea eax,[ecx+0x22]
static u32 THISCALL zg453b30(u8 *self) { return *(u8 *)(self + 0x60); }                                              // mov al,[ecx+0x60]
static u32 THISCALL zg453b40(u8 *self) { return *(u8 *)(self + 0x61); }                                              // mov al,[ecx+0x61]
static u32 THISCALL zg42adb0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) { return 0; }                         // xor al,al; ret 0x14
static u32 THISCALL zg4364c0(u8 *self) { return G(u32, 0x6e4190); }                                                  // mov eax,[0x6e4190]
static u32 THISCALL zg453a30(u8 *self) { return 2; }                                                                 // mov eax,2
static void THISCALL zg42ace0(u8 *self) { *(u32 *)self = 0x679754; }                                                 // mov [ecx],0x679754
static u32 THISCALL zg432430(u8 *self) { return *(u8 *)(self + 0x101); }                                             // mov al,[ecx+0x101]
static u32 THISCALL zg432530(u8 *self) { return *(u32 *)(self + 0xf4); }                                             // mov eax,[ecx+0xf4]

PCREG(43e140, zg43e140);
PCREG(443020, zg443020);
PCREG(443060, zg443060);
PCREG(443540, zg443540);
PCREG(443550, zg443550);
PCREG(443560, zg443560);
PCREG(452e10, zg452e10);
PCREG(453b10, zg453b10);
PCREG(453b30, zg453b30);
PCREG(453b40, zg453b40);
PCREG(42adb0, zg42adb0);
PCREG(4364c0, zg4364c0);
PCREG(453a30, zg453a30);
PCREG(42ace0, zg42ace0);
PCREG(432430, zg432430);
PCREG(432530, zg432530);
