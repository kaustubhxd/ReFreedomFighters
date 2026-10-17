// batch5848.cpp - 0x5c6770 (ZFFSearchLightGroup::FrameUpdate), thiscall, no args, ret void.
// Simplified version to test hooked callees
#include "ff.h"

typedef unsigned long uintptr_t;

extern "C" {
    void THISCALL ext_5c6640(void *o);
    u8 THISCALL ext_5c74a0(void *o, void *edi);
    void THISCALL ext_5c7a40(void *o, void *edi);
    void THISCALL ext_5c7980(void *o, void *edi);
    void THISCALL ext_5c7a00(void *o, void *edi);
    void ext_443ef0();
    void THISCALL ext_5c7160(void *o, void *esi);
}

static void THISCALL unnamed_5c6770(u8 *self) {
    ext_5c6640(self);

    // Get obj60 pointer (at self+0x60)
    void **obj60 = *(void ***)((char*)self + 0x60);

    // Call slot 0x30 on obj60 with arg from self+0x64
    void *X = vcall<void *>(obj60, 0x30, *(void **)((char*)self + 0x64));

    if (!X) return;

    u32 bit_field = *(u32 *)(*(u8 **)((char*)X + 0x1c) + 0x3c);
    if ((bit_field >> 10) & 1) return;

    (*(u32 *)((char*)self + 0x64))++;
    unsigned int result = vcall<unsigned int>(obj60, 0x14, 0);
    if (*(u32 *)((char*)self + 0x64) == result) {
        *(u32 *)((char*)self + 0x64) = 0;
    }

    u8 skip_flag = ext_5c74a0(self, X);

    if (skip_flag == 0) {
        ext_5c7a40(self, X);

        u8 *engine = G(u8 *, 0x70039c);
        u8 *engine_sub = engine + 0x9b;
        u8 *Y = vcall<u8 *>(engine_sub, 0x58, *(void **)((char*)X + 0x20));

        if (Y) {
            vcall<void>(Y, 0x210, 1);
        }
        *(void **)((char*)X + 0x20) = 0;
        return;
    }

    u32 res = vcall<u32>(*(void **)((char*)X + 4), 0x14);

    if (res) {
        ext_5c7a40(self, X);

        float val_6d = *(float *)((char*)self + 0x6d);
        float mult = *(float *)0x67862c;
        int scaled = (int)(val_6d * mult);

        u8 *engine = G(u8 *, 0x70039c);
        int eng_40 = *(int *)((char*)engine + 0x40);
        int diff = eng_40 - scaled;

        float scale = *(float *)0x6785e4;
        *(float *)((char*)X + 0x24) = diff * scale;
    } else {
        ext_5c7980(self, X);

        float X_24 = *(float *)((char*)X + 0x24);
        float mult = *(float *)0x678620;
        int val = (int)(X_24 * mult);

        u8 *engine = G(u8 *, 0x70039c);
        int eng_40 = *(int *)((char*)engine + 0x40);

        if (eng_40 > val) {
            ext_5c7a00(self, X);
        }
    }

    vcall<void>(*(void **)((char*)X + 0x1c), 0x80, (void*)((char*)self + 0x100), (void*)((char*)self + 0x104));

    ext_443ef0();

    u8 *list_head = *(u8 **)(self + 0x48);
    u8 *list_current = *(u8 **)(list_head + 0x18);

    if (!list_current) return;

    u32 temp;
    u8 *esi = 0;

    while (1) {
        vcall<void>(list_current, 0x4c, &temp);

        esi = vcall<u8 *>(list_current, 0x5c, &temp);

        if (!temp) return;

        u8 *engine = G(u8 *, 0x70039c);
        u8 *engine_sub = engine + 0x9b;
        u8 res_1e0 = vcall<u8>(engine_sub, 0x1e0, 0x200074);

        if (!res_1e0) return;

        u8 res_438 = vcall<u8>(engine_sub, 0x438);

        if (!res_438) return;

        ext_5c7160(self, esi);

        vcall<void>(*(void **)(esi + 4), 0x3c, 0);

        list_current = esi;
    }
}

typedef unsigned long uintptr_t;

PCREG(5c6770, unnamed_5c6770);
