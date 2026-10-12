// batch314.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x6070b0, a vector<unsigned short>::insert(pos, value) (thiscall,
// ret 8, GUESS). Vector words: [0] begin, [4] end, [8] capacity end. Read the value word (via pval) after the end-slot copy and before
// the tail shift. A full vector grows: capw = 2n words, or 1 when empty; buffer 2*capw bytes from 0x6014a0 (exe allocator, stdcall);
// head copied, value written, tail copied; the old begin is freed through 0x54f870 (thiscall, two args) when capacity != begin.
#include "ff.h"

extern "C" u32 STDCALL ext_6014a0(u32 bytes);
extern "C" void THISCALL ext_54f870(u8 *self, u32 a, u32 b);

static void THISCALL insertWord_6070b0(u8 *self, u32 pos, u32 pval) {
    u32 *vec = (u32 *)self;
    if (vec[1] != vec[2]) {
        u32 end = vec[1];
        if (end != 0u) *(u16 *)end = *(u16 *)(end - 2u);
        vec[1] = end + 2u;
        u32 newend = vec[1];
        u32 last = newend - 4u;
        u32 cursor = newend - 2u;
        u16 val = *(u16 *)pval;
        s32 cnt = (s32)(last - pos) >> 1;
        for (; cnt > 0; cnt--) {
            u16 w = *(u16 *)(last - 2u);
            last -= 2u;
            *(u16 *)(cursor - 2u) = w;
            cursor -= 2u;
        }
        *(u16 *)pos = val;
        return;
    }
    s32 n = (s32)(vec[1] - vec[0]) >> 1;
    u32 capw = (n == 0) ? 1u : (u32)(2 * n);
    u32 newbuf = ext_6014a0(capw * 2u);
    u32 cur = newbuf;
    s32 head = (s32)(pos - vec[0]) >> 1;
    u32 src = vec[0];
    for (s32 k = 0; k < head; k++) {
        *(u16 *)cur = *(u16 *)src;
        src += 2u;
        cur += 2u;
    }
    if (cur != 0u) *(u16 *)cur = *(u16 *)pval;
    cur += 2u;
    s32 tail = (s32)(vec[1] - pos) >> 1;
    for (s32 k = 0; k < tail; k++) {
        *(u16 *)cur = *(u16 *)(pos + 2u * (u32)k);
        cur += 2u;
    }
    s32 d = (s32)(vec[2] - vec[0]) >> 1;
    if (d != 0) ext_54f870(self, vec[0], (u32)d * 2u);
    vec[1] = cur;
    vec[0] = newbuf;
    vec[2] = newbuf + capw * 2u;
}
PCREG(6070b0, insertWord_6070b0);
