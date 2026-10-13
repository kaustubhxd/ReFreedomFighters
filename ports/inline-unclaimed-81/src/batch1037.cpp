// batch1037.cpp - area 81, batch 1037: 26 list-append functions with one template (17 instructions each, plain ret, no arguments):
// the global head A is taken (ecx), the global tail B (eax) is read; when A is set, A->+0x14 = B and the pair is reloaded; otherwise
// [0x7003bc] = B. When B is set, B->+0x10 = A, otherwise [0x7003c0] = A. Then A and B are cleared. Ports share listAppendPair; each
// address has its own PCREG wrapper with its globals. No stand-ins.
#include "ff.h"

#define G32(a) (*(volatile u32 *)(a))
#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

static void listAppendPair(u32 A, u32 B) {
  u32 ecx = G32(A);
  u32 eax = G32(B);
  if (ecx) {
    D(ecx, 0x14) = eax;
    eax = G32(B);
    ecx = G32(A);
  } else {
    G32(0x7003bc) = eax;
  }
  if (eax) {
    D(eax, 0x10) = ecx;
  } else {
    G32(0x7003c0) = ecx;
  }
  G32(A) = 0;
  G32(B) = 0;
}

static void listAppend_66f080(void) { listAppendPair(0x6e5184u, 0x6e5188u); }
PCREG(66f080, listAppend_66f080);
static void listAppend_66f1c0(void) { listAppendPair(0x6e51ecu, 0x6e51f0u); }
PCREG(66f1c0, listAppend_66f1c0);
static void listAppend_66f300(void) { listAppendPair(0x6e50e8u, 0x6e50ecu); }
PCREG(66f300, listAppend_66f300);
static void listAppend_66f440(void) { listAppendPair(0x6e52f0u, 0x6e52f4u); }
PCREG(66f440, listAppend_66f440);
static void listAppend_66f580(void) { listAppendPair(0x6e539cu, 0x6e53a0u); }
PCREG(66f580, listAppend_66f580);
static void listAppend_66f6c0(void) { listAppendPair(0x6e54a4u, 0x6e54a8u); }
PCREG(66f6c0, listAppend_66f6c0);
static void listAppend_66f800(void) { listAppendPair(0x6e557cu, 0x6e5580u); }
PCREG(66f800, listAppend_66f800);
static void listAppend_66f940(void) { listAppendPair(0x6e5618u, 0x6e561cu); }
PCREG(66f940, listAppend_66f940);
static void listAppend_66fa80(void) { listAppendPair(0x6e5728u, 0x6e572cu); }
PCREG(66fa80, listAppend_66fa80);
static void listAppend_66fbc0(void) { listAppendPair(0x6e5804u, 0x6e5808u); }
PCREG(66fbc0, listAppend_66fbc0);
static void listAppend_66fd00(void) { listAppendPair(0x6e5878u, 0x6e587cu); }
PCREG(66fd00, listAppend_66fd00);
static void listAppend_66fe40(void) { listAppendPair(0x6e59b4u, 0x6e59b8u); }
PCREG(66fe40, listAppend_66fe40);
static void listAppend_66ff80(void) { listAppendPair(0x6e5c6cu, 0x6e5c70u); }
PCREG(66ff80, listAppend_66ff80);
static void listAppend_674080(void) { listAppendPair(0x6eeb88u, 0x6eeb8cu); }
PCREG(674080, listAppend_674080);
static void listAppend_6741c0(void) { listAppendPair(0x6eec68u, 0x6eec6cu); }
PCREG(6741c0, listAppend_6741c0);
static void listAppend_674300(void) { listAppendPair(0x6eed48u, 0x6eed4cu); }
PCREG(674300, listAppend_674300);
static void listAppend_674440(void) { listAppendPair(0x6eee28u, 0x6eee2cu); }
PCREG(674440, listAppend_674440);
static void listAppend_674580(void) { listAppendPair(0x6eef08u, 0x6eef0cu); }
PCREG(674580, listAppend_674580);
static void listAppend_6746c0(void) { listAppendPair(0x6ef010u, 0x6ef014u); }
PCREG(6746c0, listAppend_6746c0);
static void listAppend_674800(void) { listAppendPair(0x6ef0f0u, 0x6ef0f4u); }
PCREG(674800, listAppend_674800);
static void listAppend_674940(void) { listAppendPair(0x6ef208u, 0x6ef20cu); }
PCREG(674940, listAppend_674940);
static void listAppend_674a80(void) { listAppendPair(0x6ef2b0u, 0x6ef2b4u); }
PCREG(674a80, listAppend_674a80);
static void listAppend_674bc0(void) { listAppendPair(0x6ef39cu, 0x6ef3a0u); }
PCREG(674bc0, listAppend_674bc0);
static void listAppend_674d00(void) { listAppendPair(0x6ef47cu, 0x6ef480u); }
PCREG(674d00, listAppend_674d00);
static void listAppend_674e40(void) { listAppendPair(0x6ef55cu, 0x6ef560u); }
PCREG(674e40, listAppend_674e40);
static void listAppend_674f80(void) { listAppendPair(0x6ef638u, 0x6ef63cu); }
PCREG(674f80, listAppend_674f80);
