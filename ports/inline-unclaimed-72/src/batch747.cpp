// batch747.cpp - area 72, whole-exe gap list (2026-10-12): trivial accessors and constants (see docs/20-unclaimed-72.md).
#include "ff.h"

// 0x4f1840 glob_6e7ca8
static u32 THISCALL f_4f1840(u8 *self) { (void)self; return *(u32 *)0x6e7ca8; }
PCREG(4f1840, f_4f1840);

// 0x4f1850 glob_6e7cac
static u32 THISCALL f_4f1850(u8 *self) { (void)self; return *(u32 *)0x6e7cac; }
PCREG(4f1850, f_4f1850);

// 0x4f1870 glob_6e7f8c
static u32 THISCALL f_4f1870(u8 *self) { (void)self; return *(u32 *)0x6e7f8c; }
PCREG(4f1870, f_4f1870);

// 0x504550 cstr_685230
static const char *THISCALL f_504550(u8 *self) { (void)self; return (const char *)0x685230; }
PCREG(504550, f_504550);

// 0x50a430 cstr_69c768
static const char *THISCALL f_50a430(u8 *self) { (void)self; return (const char *)0x69c768; }
PCREG(50a430, f_50a430);

// 0x50b5b0 cstr_69c770
static const char *THISCALL f_50b5b0(u8 *self) { (void)self; return (const char *)0x69c770; }
PCREG(50b5b0, f_50b5b0);

// 0x510ec0 cstr_69c784
static const char *THISCALL f_510ec0(u8 *self) { (void)self; return (const char *)0x69c784; }
PCREG(510ec0, f_510ec0);

// 0x51ff30 cstr_6a003c
static const char *THISCALL f_51ff30(u8 *self) { (void)self; return (const char *)0x6a003c; }
PCREG(51ff30, f_51ff30);

// 0x54bb80 cstr_713d30
static const char *THISCALL f_54bb80(u8 *self) { (void)self; return (const char *)0x713d30; }
PCREG(54bb80, f_54bb80);

// 0x5578c0 cstr_6a4b68
static const char *THISCALL f_5578c0(u8 *self) { (void)self; return (const char *)0x6a4b68; }
PCREG(5578c0, f_5578c0);

// 0x560370 cstr_6a4b8c
static const char *THISCALL f_560370(u8 *self) { (void)self; return (const char *)0x6a4b8c; }
PCREG(560370, f_560370);

// 0x5b2510 glob_6ed354
static u32 THISCALL f_5b2510(u8 *self) { (void)self; return *(u32 *)0x6ed354; }
PCREG(5b2510, f_5b2510);

// 0x5b2530 glob_6edacc
static u32 THISCALL f_5b2530(u8 *self) { (void)self; return *(u32 *)0x6edacc; }
PCREG(5b2530, f_5b2530);

// 0x5b2540 glob_6ee240
static u32 THISCALL f_5b2540(u8 *self) { (void)self; return *(u32 *)0x6ee240; }
PCREG(5b2540, f_5b2540);

// 0x4d0580 u32_213
static u32 THISCALL f_4d0580(u8 *self) { return *(u32 *)(self + 0x213); }
PCREG(4d0580, f_4d0580);

