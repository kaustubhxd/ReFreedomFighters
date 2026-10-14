// batch34112.cpp - escalation batch 34112: 0x63ade0 / 0x6483e0 (asm list walkers), 0x528090, 0x62f340, 0x4cd690.
#include "ff.h"

extern "C" void thunk63ade0(void);
extern "C" void thunk6483e0(void);
// 0x63ade0 / 0x6483e0, thiscall plain: skips list nodes ([this+8] head, link +8) whose word +2 is 0xffff, stopping at the original head or the end; a live node: [this+0xc]++ and tail jump (0x63b050 / 0x648690) with ecx = node.
// None left: calls 0x63b440 / 0x63b3c0 on this; zero (al) returns 0, else [this+0xc]++ and the tail jump with ecx = [this+8].
asm(
    ".text\n"
    ".globl thunk63ade0\n"
    "thunk63ade0:\n"
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  mov 8(%esi), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je .L1_63ade0\n"
    "  mov $0xffff, %edx\n"
    ".L0_63ade0:\n"
    "  mov 8(%esi), %eax\n"
    "  cmpw %dx, 2(%eax)\n"
    "  jne .L2_63ade0\n"
    "  mov 8(%eax), %eax\n"
    "  mov %eax, 8(%esi)\n"
    "  cmp %eax, %ecx\n"
    "  je .L1_63ade0\n"
    "  test %eax, %eax\n"
    "  jne .L0_63ade0\n"
    ".L1_63ade0:\n"
    "  mov %esi, %ecx\n"
    "  call ext_63b440\n"
    "  test %al, %al\n"
    "  jne .L3_63ade0\n"
    "  xor %eax, %eax\n"
    "  pop %esi\n"
    "  ret\n"
    ".L2_63ade0:\n"
    "  incl 0xc(%esi)\n"
    "  mov %eax, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_63b050\n"
    ".L3_63ade0:\n"
    "  incl 0xc(%esi)\n"
    "  mov 8(%esi), %ecx\n"
    "  pop %esi\n"
    "  jmp ext_63b050\n"
    ".globl thunk6483e0\n"
    "thunk6483e0:\n"
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  mov 8(%esi), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je .L1_6483e0\n"
    "  mov $0xffff, %edx\n"
    ".L0_6483e0:\n"
    "  mov 8(%esi), %eax\n"
    "  cmpw %dx, 2(%eax)\n"
    "  jne .L2_6483e0\n"
    "  mov 8(%eax), %eax\n"
    "  mov %eax, 8(%esi)\n"
    "  cmp %eax, %ecx\n"
    "  je .L1_6483e0\n"
    "  test %eax, %eax\n"
    "  jne .L0_6483e0\n"
    ".L1_6483e0:\n"
    "  mov %esi, %ecx\n"
    "  call ext_63b3c0\n"
    "  test %al, %al\n"
    "  jne .L3_6483e0\n"
    "  xor %eax, %eax\n"
    "  pop %esi\n"
    "  ret\n"
    ".L2_6483e0:\n"
    "  incl 0xc(%esi)\n"
    "  mov %eax, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_648690\n"
    ".L3_6483e0:\n"
    "  incl 0xc(%esi)\n"
    "  mov 8(%esi), %ecx\n"
    "  pop %esi\n"
    "  jmp ext_648690\n"
);
PCREG(63ade0, thunk63ade0);
PCREG(6483e0, thunk6483e0);

extern "C" u32 THISCALL ext_529cd0(void *self, u32 f);          // thiscall ret 4 (float argument passed as raw bits)
extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);             // cdecl memcpy
extern "C" u8 *ext_41e290(u32 n);                                // cdecl alloc
extern "C" u32 THISCALL ext_4cd540(void *self, u8 *p);           // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x528090, thiscall plain: for i < unaligned [this+0x8d] (signed): ext_529cd0(this+0xe75+0x133*i, 3.0f); then for i < unaligned [this+0x91]: ext_529cd0(this+0x180d+0x133*i, 3.0f).
static void THISCALL fn528090(u8 *self) {
  s32 i = 0;
  if ((s32)rd32(self + 0x8d) > 0) {
    u8 *p = self + 0xe75;
    do {
      ext_529cd0(p, 0x40400000);
      i++;
      p += 0x133;
    } while (i < (s32)rd32(self + 0x8d));
  }
  i = 0;
  if ((s32)rd32(self + 0x91) > 0) {
    u8 *p = self + 0x180d;
    do {
      ext_529cd0(p, 0x40400000);
      i++;
      p += 0x133;
    } while (i < (s32)rd32(self + 0x91));
  }
}
PCREG(528090, fn528090);

// 0x62f340, cdecl(a), returns [a+0x1c]: p = [a+0x1c]; n = min([p+0x14], [a+0x10]) (unsigned); nothing when n is 0. Else ext_634d22([a+0xc], [p+0x10], n); [a+0xc] += n; [p+0x10] += n; [a+0x14] += n; [a+0x10] -= n;
// [p+0x14] -= n; when [p+0x14] is then 0: [p+0x10] = [p+8].
static u32 fn62f340(u8 *a) {
  u8 *p = *(u8 **)(a + 0x1c);
  u32 n = *(u32 *)(p + 0x14);
  if (n > *(u32 *)(a + 0x10)) n = *(u32 *)(a + 0x10);
  if (n == 0) return 0;
  ext_634d22(*(u32 *)(a + 0xc), *(u32 *)(p + 0x10), n);
  u8 *q = *(u8 **)(a + 0x1c);
  *(u32 *)(a + 0xc) += n;
  *(u32 *)(q + 0x10) += n;
  q = *(u8 **)(a + 0x1c);
  *(u32 *)(a + 0x14) += n;
  *(u32 *)(a + 0x10) -= n;
  *(u32 *)(q + 0x14) -= n;
  u8 *r = *(u8 **)(a + 0x1c);
  if (*(u32 *)(r + 0x14) == 0) *(u32 *)(r + 0x10) = *(u32 *)(r + 8);
  return (u32)r;
}
PCREG(62f340, fn62f340);

// 0x4cd690, thiscall(s) ret 4: duplicates the zero-terminated string s into a block from ext_41e290(strlen + 1) and passes it to ext_4cd540(this, copy); returns its eax.
static u32 THISCALL fn4cd690(u8 *self, const u8 *s) {
  u32 len = 0;
  while (s[len]) len++;
  u8 *p = ext_41e290(len + 1);
  const u8 *q = s;
  u8 *d = p;
  u8 c;
  do {
    c = *q++;
    *d++ = c;
  } while (c);
  return ext_4cd540(self, p);
}
PCREG(4cd690, fn4cd690);
