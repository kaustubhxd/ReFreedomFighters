// batch746.cpp - area 72, whole-exe gap list (2026-10-12): trivial accessors and constants (see docs/20-unclaimed-72.md).
#include "ff.h"

// 0x51ad70 stub_ret8
static void THISCALL f_51ad70(u8 *self, u32 a, u32 b) { (void)self; (void)a; (void)b; }
PCREG(51ad70, f_51ad70);

// 0x51f230 zero0
static u32 THISCALL f_51f230(u8 *self) { (void)self; return 0; }
PCREG(51f230, f_51f230);

// 0x4b00c0 u32_48
static u32 THISCALL f_4b00c0(u8 *self) { return *(u32 *)(self + 0x48); }
PCREG(4b00c0, f_4b00c0);

// 0x4d4520 f32_7
static float THISCALL f_4d4520(u8 *self) { return *(float *)(self + 0x7); }
PCREG(4d4520, f_4d4520);

// 0x4d4530 u8_6
static u8 THISCALL f_4d4530(u8 *self) { return *(u8 *)(self + 0x6); }
PCREG(4d4530, f_4d4530);

// 0x4d6970 u8_6e
static u8 THISCALL f_4d6970(u8 *self) { return *(u8 *)(self + 0x6e); }
PCREG(4d6970, f_4d6970);

// 0x4f0030 ptr_3e
static u8 *THISCALL f_4f0030(u8 *self) { return self + 0x3e; }
PCREG(4f0030, f_4f0030);

// 0x4f22d0 u32_73
static u32 THISCALL f_4f22d0(u8 *self) { return *(u32 *)(self + 0x73); }
PCREG(4f22d0, f_4f22d0);

// 0x54bbb0 ptr_14
static u8 *THISCALL f_54bbb0(u8 *self) { return self + 0x14; }
PCREG(54bbb0, f_54bbb0);

// 0x54bc00 ptr_38
static u8 *THISCALL f_54bc00(u8 *self) { return self + 0x38; }
PCREG(54bc00, f_54bc00);

// 0x54bc10 ptr_20
static u8 *THISCALL f_54bc10(u8 *self) { return self + 0x20; }
PCREG(54bc10, f_54bc10);

// 0x54e1e0 u8_59
static u8 THISCALL f_54e1e0(u8 *self) { return *(u8 *)(self + 0x59); }
PCREG(54e1e0, f_54e1e0);

// 0x5acff0 ptr_48
static u8 *THISCALL f_5acff0(u8 *self) { return self + 0x48; }
PCREG(5acff0, f_5acff0);

// 0x4d76f0 clr_21
static void THISCALL f_4d76f0(u8 *self) { *(u8 *)(self + 0x21) = 0; }
PCREG(4d76f0, f_4d76f0);

// 0x53cca0 true6
static bool THISCALL f_53cca0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) { (void)self; (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; return true; }
PCREG(53cca0, f_53cca0);

