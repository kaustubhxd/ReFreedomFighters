// fb0404.cpp - fresh slice 17, batch 4.
#include "ff.h"

extern "C" u32 THISCALL ext_63b1c0(u8 *self);
extern "C" int ext_42ab62(const char *fmt, ...);     // printf
extern "C" void *ext_41e290(u32 size);                // __builtin_new (cdecl)

typedef u32 (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)

// 0x63ac10 ZDrawArray<ZArrayBlock, ZArrayBlock, ZArrayBlock>::Add(): finds a block with a free entry like 0x6139d0 (circular
// list from this+8, next at +8; 0x63b1c0 grows), counts this+0xc, then pops the block's free list inline: entries are
// 0x1000 bytes from block+0x10, head word at +2 (0xffff = none, returns 0 after counting), next index in the entry's
// first word, used count byte at +0.
static u8 *THISCALL arrayBlockAdd63ac10(u8 *self) {
  u8 *start = *(u8 **)(self + 8);
  u8 *b;
  if (start) {
    b = start;
    for (;;) {
      if (*(u16 *)(b + 2) != 0xffff)
        goto found;
      b = *(u8 **)(b + 8);
      *(u8 **)(self + 8) = b;
      if (start == b || !b)
        break;
    }
  }
  if (!(u8)ext_63b1c0(self))
    return 0;
  b = *(u8 **)(self + 8);
found:
  *(u32 *)(self + 0xc) += 1;
  u16 idx = *(u16 *)(b + 2);
  if (idx == 0xffff)
    return 0;
  u8 *e = b + ((u32)idx << 12) + 0x10;
  b[0]++;
  *(u16 *)(b + 2) = *(u16 *)e;
  return e;
}
PCREG(63ac10, arrayBlockAdd63ac10);

// 0x5f5390 (GUESS FUN_5f5390, slot pool get): asserts index this+8 < count this+4 (printf 0x6b89b4 + assert hook), takes
// the 8-byte slot this[0][index] and advances the index. A slot of kind 0 or 4 is (re)filled: kind 4 first releases
// its object (slot +0x28), then object = factory->slot +0x24(), kind = 4. Returns the slot.
static u8 *THISCALL slotGet5f5390(u8 *self, void *factory) {
  if (*(u32 *)(self + 8) >= *(u32 *)(self + 4)) {
    ext_42ab62((const char *)0x6b89b4);
    if (!g_pAssertHook)
      __builtin_debugtrap();
    g_pAssertHook();
  }
  u32 i = *(u32 *)(self + 8);
  u8 *s = *(u8 **)self + i * 8;
  *(u32 *)(self + 8) = i + 1;
  u8 kind = s[4];
  if (kind == 0 || kind == 4) {
    if (kind == 4)
      vcall<u32>(*(void **)s, 0x28);
    *(u32 *)s = vcall<u32>(factory, 0x24);
    s[4] = 4;
  }
  return s;
}
PCREG(5f5390, slotGet5f5390);

// 0x4e6c10 CMemPool::Init(int first, int count, int align): n = ((align - first) & (align - 1)) + first entries of
// `count` bytes (sic, as the code reads), byte size rounded up to even; one allocation holds the data and a word free
// list of `count` entries (initialised 0, 1, 2, ...). Fields: +0 data, +4 list, +8 count, +0xc n, +0x10 0, +0x14 owned.
static void THISCALL memPoolInit4e6c10(u8 *self, s32 first, s32 count, s32 align) {
  s32 n = ((align - first) & (align - 1)) + first;
  *(s32 *)(self + 0xc) = n;
  u32 size = (u32)(n * count);
  *(s32 *)(self + 8) = count;
  *(u32 *)(self + 0x10) = 0;
  size += size & 1;
  u8 *p = (u8 *)ext_41e290(size + (u32)count * 2);
  *(u8 **)self = p;
  self[0x14] = 1;
  u16 *list = (u16 *)(p + size);
  *(u16 **)(self + 4) = list;
  for (s32 i = 0; i < *(s32 *)(self + 8); i++)
    list[i] = (u16)i;
}
PCREG(4e6c10, memPoolInit4e6c10);

// 0x656190 ZPrimControlBase::CopyPrim(unsigned first, unsigned arg): walks the prim list from `first` (slot +0xc maps a
// handle to its record, next handle at record+8), copies each with slot +0x64(handle, arg) and links the copies the same
// way (previous copy's record+8 = new copy). Returns the first copy (0 for an empty list).
static u32 THISCALL copyPrim656190(u8 *self, u32 cur, u32 arg) {
  u32 head = 0, prev = 0;
  while (cur) {
    u8 *rec = (u8 *)vcall<u32>(self, 0x0c, cur);
    u32 n = vcall<u32>(self, 0x64, cur, arg);
    if (!head)
      head = n;
    if (prev)
      *(u32 *)((u8 *)vcall<u32>(self, 0x0c, prev) + 8) = n;
    prev = n;
    cur = *(u32 *)(rec + 8);
  }
  return head;
}
PCREG(656190, copyPrim656190);

// 0x4fa990 ZScrollbar::UpdateBarPos(float delta): unless delta == 0, pos (+0xa7) += delta, clamped below at 0 and above
// at (float)max (+0xab, int), then slot +0x358() redraws.
static void THISCALL updateBarPos4fa990(u8 *self, float d) {
  if (d == 0.0f)
    return;
  float p = *(float *)(self + 0xa7) + d;
  *(float *)(self + 0xa7) = p;
  if (0.0f > p)
    *(u32 *)(self + 0xa7) = 0;
  float mx = (float)*(s32 *)(self + 0xab);
  if (*(float *)(self + 0xa7) > mx)
    *(float *)(self + 0xa7) = mx;
  vcall<u32>(self, 0x358);
}
PCREG(4fa990, updateBarPos4fa990);

// 0x5f0750 ZCredits::Parse(const char*): appends the 12-byte record {1, text, <uninitialised word>} to the vector at
// this+0x7c (end +0x80, capacity end +0x84); a full vector goes through 0x5f0af0(end, &record) (the grow-and-insert
// helper). The third word is a stack word the original never writes, so the port is naked to keep the same frame.
extern "C" __attribute__((naked)) void creditsParse5f0750() {
  asm volatile(
      "push %ebp\n mov %esp, %ebp\n sub $0xc, %esp\n"
      "mov 0x80(%ecx), %edx\n add $0x7c, %ecx\n mov 8(%ebp), %eax\n"
      "movl $1, -0xc(%ebp)\n mov %eax, -8(%ebp)\n"
      "cmp 8(%ecx), %edx\n je 2f\n"
      "test %edx, %edx\n je 1f\n"
      "movq -0xc(%ebp), %xmm0\n mov -4(%ebp), %eax\n movq %xmm0, (%edx)\n mov %eax, 8(%edx)\n"
      "1: addl $0xc, 4(%ecx)\n mov %ebp, %esp\n pop %ebp\n ret $4\n"
      "2: lea -0xc(%ebp), %eax\n push %eax\n push %edx\n call ext_5f0af0\n mov %ebp, %esp\n pop %ebp\n ret $4\n");
}
PCREG(5f0750, creditsParse5f0750);
