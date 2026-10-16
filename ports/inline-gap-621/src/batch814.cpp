// batch814.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// One list-unlink template: a head at H (first at H[0], last at H[1]); the first's +0x14 gets the last, the last's +0x10
// gets the first; with no neighbour the globals 0x7003bc (no first) or 0x7003c0 (no last) take the other end.
static void unlinkHead(u32 H) {
  u32 ecx = *(u32 *)(H + 0);
  u32 eax = *(u32 *)(H + 4);
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)(H + 4);
    ecx = *(u32 *)(H + 0);
  } else {
    *(u32 *)0x7003bcu = eax;
  }
  if (eax != 0) {
    *(u32 *)(eax + 0x10) = ecx;
  } else {
    *(u32 *)0x7003c0u = ecx;
  }
  *(u32 *)(H + 0) = 0;
  *(u32 *)(H + 4) = 0;
}

// 0x66ef30 (head 0x6e4f8c)
static void __attribute__((cdecl)) unlink_66ef30(void) { unlinkHead(0x6e4f8cu); }
PCREG(66ef30, unlink_66ef30);

// 0x673030 (head 0x6ec578)
static void __attribute__((cdecl)) unlink_673030(void) { unlinkHead(0x6ec578u); }
PCREG(673030, unlink_673030);

// 0x673170 (head 0x6ec658)
static void __attribute__((cdecl)) unlink_673170(void) { unlinkHead(0x6ec658u); }
PCREG(673170, unlink_673170);

// batch815: the same template with the next four heads
static void __attribute__((cdecl)) unlink_673530(void) { unlinkHead(0x6eca8cu); }
PCREG(673530, unlink_673530);
static void __attribute__((cdecl)) unlink_673670(void) { unlinkHead(0x6ecb6cu); }
PCREG(673670, unlink_673670);
static void __attribute__((cdecl)) unlink_6737b0(void) { unlinkHead(0x6ecc4cu); }
PCREG(6737b0, unlink_6737b0);
static void __attribute__((cdecl)) unlink_6738f0(void) { unlinkHead(0x6ecd60u); }
PCREG(6738f0, unlink_6738f0);

// batch816: the same template with five more heads
static void __attribute__((cdecl)) unlink_673a30(void) { unlinkHead(0x6eced8u); }
PCREG(673a30, unlink_673a30);
static void __attribute__((cdecl)) unlink_673b70(void) { unlinkHead(0x6ecf8cu); }
PCREG(673b70, unlink_673b70);
static void __attribute__((cdecl)) unlink_673cb0(void) { unlinkHead(0x6ed0acu); }
PCREG(673cb0, unlink_673cb0);
static void __attribute__((cdecl)) unlink_673df0(void) { unlinkHead(0x6ed2b8u); }
PCREG(673df0, unlink_673df0);
static void __attribute__((cdecl)) unlink_673f30(void) { unlinkHead(0x6eeaa8u); }
PCREG(673f30, unlink_673f30);

// batch817: the template with the last two heads of the family
static void __attribute__((cdecl)) unlink_6732b0(void) { unlinkHead(0x6ec8ccu); }
PCREG(6732b0, unlink_6732b0);
static void __attribute__((cdecl)) unlink_6733f0(void) { unlinkHead(0x6ec9b0u); }
PCREG(6733f0, unlink_6733f0);
