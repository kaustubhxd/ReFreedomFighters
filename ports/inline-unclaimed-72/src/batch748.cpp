// batch748.cpp - area 72, gap list round 2 (2026-10-12): vtable stores, field getters and simple virtual calls (docs/20-unclaimed-72.md).
#include "ff.h"

// 0x4d23c0 vt_696168
static void THISCALL f_4d23c0(u8 *self) { *(u32 *)self = 0x696168; }
PCREG(4d23c0, f_4d23c0);

// 0x4d5570 vt_6967bc
static void THISCALL f_4d5570(u8 *self) { *(u32 *)self = 0x6967bc; }
PCREG(4d5570, f_4d5570);

// 0x5422a0 vt_6a2e08
static void THISCALL f_5422a0(u8 *self) { *(u32 *)self = 0x6a2e08; }
PCREG(5422a0, f_5422a0);

// 0x54cd00 vt_6a3e14
static void THISCALL f_54cd00(u8 *self) { *(u32 *)self = 0x6a3e14; }
PCREG(54cd00, f_54cd00);

// 0x5ab4b0 vt_6b01dc
static void THISCALL f_5ab4b0(u8 *self) { *(u32 *)self = 0x6b01dc; }
PCREG(5ab4b0, f_5ab4b0);

// 0x4f22b0 u32_1db
static u32 THISCALL f_4f22b0(u8 *self) { return *(u32 *)(self + 0x1db); }
PCREG(4f22b0, f_4f22b0);

// 0x4f4cb0 u32_8b
static u32 THISCALL f_4f4cb0(u8 *self) { return *(u32 *)(self + 0x8b); }
PCREG(4f4cb0, f_4f4cb0);

// 0x4f4d20 u8_88
static u8 THISCALL f_4f4d20(u8 *self) { return *(u8 *)(self + 0x88); }
PCREG(4f4d20, f_4f4d20);

// 0x4f9f40 u32_8f
static u32 THISCALL f_4f9f40(u8 *self) { return *(u32 *)(self + 0x8f); }
PCREG(4f9f40, f_4f9f40);

// 0x5333e0 u32_546e
static u32 THISCALL f_5333e0(u8 *self) { return *(u32 *)(self + 0x546e); }
PCREG(5333e0, f_5333e0);

// 0x5334f0 u32_548a
static u32 THISCALL f_5334f0(u8 *self) { return *(u32 *)(self + 0x548a); }
PCREG(5334f0, f_5334f0);

