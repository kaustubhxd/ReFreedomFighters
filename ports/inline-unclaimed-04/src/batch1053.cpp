// batch1053.cpp - unclaimed-04 batch 53 (docs/20-unclaimed-04.md): 0x62a870 (residue 3).
// cdecl (enc, ptr, end, tokPtr), returns 0 or 1. GUESS: expat checkPiTarget for a one-byte encoding (enc unused):
// a PI target of exactly "xml" is the XML declaration (token 12); "XML" with any upper-case letter is rejected (returns 0).
#include "ff.h"

// 0x62a870
static int __attribute__((cdecl)) unk62a870CheckPiTarget(const void *enc, const char *ptr, const char *end, int *tokPtr) {
  (void)enc;
  int upper = 0;
  *tokPtr = 0xb;  // XML_TOK_PI
  if (end - ptr != 3) return 1;
  switch (ptr[0]) {
    case 'x': break;
    case 'X': upper = 1; break;
    default: return 1;
  }
  switch (ptr[1]) {
    case 'm': break;
    case 'M': upper = 1; break;
    default: return 1;
  }
  switch (ptr[2]) {
    case 'l': break;
    case 'L': upper = 1; break;
    default: return 1;
  }
  if (upper) return 0;
  *tokPtr = 0xc;  // XML_TOK_XML_DECL
  return 1;
}
PCREG(62a870, unk62a870CheckPiTarget);
