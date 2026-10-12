// batch240.cpp - parked item from the loop, now ported. 0x5ebf10 (name GUESS): thiscall(B) (ret 4). The mirror of 0x5ec190:
// vtable calls on B that write into this (0x74 +4, 0x6c +0x28, 0x68 +0x34, 0x68 +0x35, 0x48 +0x36, 0x40 +0x3e, 0x40 +0x42, 0x6c +0x46,
// 0x40 +0x52, +0x56, +0x5a, +0x5e, +0x6e, +0x72, 0x74 +0x76, 0x6c +0x9a, 0x68 +0xa6). S = [this+0x3a]: n = [this+0x3e]; [S+4] = alloc(n*40)
// (overflow saturates to 0xffffffff); [S] = B->vt[0x40](&tmp); B->vt[0x18]([S+4], n*40). count = B->vt[0x40](&count); for i < count:
// blk = alloc(0x2c); B->vt[0x18](blk, 0x2c); list = this+0x62: if [list+4] == [list+8]: 0x5fe3b0(list, [list+4], &blk) else
// { if [list+4]: *[list+4] = blk; [list+4] += 4 }. The allocator 0x41e290 is cdecl (the caller pops). Name GUESS.
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);                            // original allocator, cdecl (hooked by the harness)
extern "C" void THISCALL ext_5fe3b0(u8 *self, u32 p1, u32 *p2);   // original list push, thiscall two words, ret 8 (stubbed)

typedef void(THISCALL *SlotWord)(u8 *, u32);
typedef void(THISCALL *SlotTwo)(u8 *, u32, u32);
typedef void(THISCALL *SlotOut)(u8 *, u32 *);

static u32 vslot21(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static void THISCALL vecSerialize_5ebf10(u8 *self, u8 *B) {
  ((SlotWord)vslot21(B, 0x74))(B, (u32)(self + 4));
  ((SlotWord)vslot21(B, 0x6c))(B, (u32)(self + 0x28));
  ((SlotWord)vslot21(B, 0x68))(B, (u32)(self + 0x34));
  ((SlotWord)vslot21(B, 0x68))(B, (u32)(self + 0x35));
  ((SlotWord)vslot21(B, 0x48))(B, (u32)(self + 0x36));
  ((SlotOut)vslot21(B, 0x40))(B, (u32 *)(self + 0x3e));
  ((SlotOut)vslot21(B, 0x40))(B, (u32 *)(self + 0x42));
  ((SlotWord)vslot21(B, 0x6c))(B, (u32)(self + 0x46));
  ((SlotOut)vslot21(B, 0x40))(B, (u32 *)(self + 0x52));
  ((SlotOut)vslot21(B, 0x40))(B, (u32 *)(self + 0x56));
  ((SlotOut)vslot21(B, 0x40))(B, (u32 *)(self + 0x5a));
  ((SlotOut)vslot21(B, 0x40))(B, (u32 *)(self + 0x5e));
  ((SlotOut)vslot21(B, 0x40))(B, (u32 *)(self + 0x6e));
  ((SlotOut)vslot21(B, 0x40))(B, (u32 *)(self + 0x72));
  ((SlotWord)vslot21(B, 0x74))(B, (u32)(self + 0x76));
  ((SlotWord)vslot21(B, 0x6c))(B, (u32)(self + 0x9a));
  ((SlotWord)vslot21(B, 0x68))(B, (u32)(self + 0xa6));
  u32 n = *(u32 *)(self + 0x3e);
  u64 prod = (u64)n * 0x28u;
  u32 size = (prod >> 32) ? 0xffffffffu : (u32)prod;
  u8 *S = *(u8 **)(self + 0x3a);
  *(u8 **)(S + 4) = ext_41e290(size);
  u32 tmp = 0;
  ((SlotOut)vslot21(B, 0x40))(B, &tmp);
  *(u32 *)S = tmp;
  ((SlotTwo)vslot21(B, 0x18))(B, *(u32 *)(S + 4), n * 40u);
  u32 count = 0;
  ((SlotOut)vslot21(B, 0x40))(B, &count);
  u8 *list = self + 0x62;
  for (u32 i = 0; i < count; ++i) {
    u32 blk = (u32)ext_41e290(0x2c);
    ((SlotTwo)vslot21(B, 0x18))(B, blk, 0x2c);
    u32 cur = *(u32 *)(list + 4);
    if (cur == *(u32 *)(list + 8)) {
      ext_5fe3b0(list, cur, &blk);
    } else {
      if (cur) *(u32 *)cur = blk;
      *(u32 *)(list + 4) = cur + 4;
    }
  }
}
PCREG(5ebf10, vecSerialize_5ebf10);
