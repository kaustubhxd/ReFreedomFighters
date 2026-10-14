// batch372.cpp - area 76, residue 18 (out/functions.jsonl). Two small accessors.
// 0x64c7e0 (thiscall, one stack argument, ret 4; GUESS): return [[this+0x10071] + (arg & 0xfff) * 4].
// 0x658c20 (stdcall, one float argument, ret 4; GUESS): [[[0x70039c] + 0x1aa3] + 0x91] = value (float).
#include "ff.h"

static u32 THISCALL f64c7e0(u8 *selfp, u32 idx) {
    u32 table = *(u32 *)((u32)selfp + 0x10071u);
    return *(u32 *)(table + (idx & 0xfffu) * 4u);
}
PCREG(64c7e0, f64c7e0);

static void __attribute__((stdcall)) f658c20(float value) {
    u32 q = *(u32 *)(G(u32, 0x70039cu) + 0x1aa3u);
    *(float *)(q + 0x91u) = value;
}
PCREG(658c20, f658c20);
