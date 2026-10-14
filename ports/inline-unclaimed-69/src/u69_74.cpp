// u69_74.cpp - area 69, group 74 (slice 8). A family of 51 list-flush functions (size 72, same code, each with its own head/tail globals G1, G2).
// Each: ecx = [G1], eax = [G2]; if ecx != 0 { [ecx+0x14] = eax; eax = [G2]; ecx = [G1] } else { [0x7003bc] = eax };
// then if eax != 0 { [eax+0x10] = ecx } else { [0x7003c0] = ecx }; [G1] = 0; [G2] = 0. thiscall, no args, void.
#include "ff.h"

static void THISCALL flushList672030(void) {
  u32 ecx = *(u32 *)0x6e763c;
  u32 eax = *(u32 *)0x6e7640;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7640;
    ecx = *(u32 *)0x6e763c;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e763c = 0;
  *(u32 *)0x6e7640 = 0;
}
PCREG(672030, flushList672030);

static void THISCALL flushList672080(void) {
  u32 ecx = *(u32 *)0x6e775c;
  u32 eax = *(u32 *)0x6e7760;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7760;
    ecx = *(u32 *)0x6e775c;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e775c = 0;
  *(u32 *)0x6e7760 = 0;
}
PCREG(672080, flushList672080);

static void THISCALL flushList6720d0(void) {
  u32 ecx = *(u32 *)0x6e7954;
  u32 eax = *(u32 *)0x6e7958;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7958;
    ecx = *(u32 *)0x6e7954;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7954 = 0;
  *(u32 *)0x6e7958 = 0;
}
PCREG(6720d0, flushList6720d0);

static void THISCALL flushList672120(void) {
  u32 ecx = *(u32 *)0x6e7874;
  u32 eax = *(u32 *)0x6e7878;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7878;
    ecx = *(u32 *)0x6e7874;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7874 = 0;
  *(u32 *)0x6e7878 = 0;
}
PCREG(672120, flushList672120);

static void THISCALL flushList672170(void) {
  u32 ecx = *(u32 *)0x6e783c;
  u32 eax = *(u32 *)0x6e7840;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7840;
    ecx = *(u32 *)0x6e783c;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e783c = 0;
  *(u32 *)0x6e7840 = 0;
}
PCREG(672170, flushList672170);

static void THISCALL flushList6721c0(void) {
  u32 ecx = *(u32 *)0x6e7804;
  u32 eax = *(u32 *)0x6e7808;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7808;
    ecx = *(u32 *)0x6e7804;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7804 = 0;
  *(u32 *)0x6e7808 = 0;
}
PCREG(6721c0, flushList6721c0);

static void THISCALL flushList672210(void) {
  u32 ecx = *(u32 *)0x6e78e4;
  u32 eax = *(u32 *)0x6e78e8;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e78e8;
    ecx = *(u32 *)0x6e78e4;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e78e4 = 0;
  *(u32 *)0x6e78e8 = 0;
}
PCREG(672210, flushList672210);

static void THISCALL flushList672260(void) {
  u32 ecx = *(u32 *)0x6e77cc;
  u32 eax = *(u32 *)0x6e77d0;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e77d0;
    ecx = *(u32 *)0x6e77cc;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e77cc = 0;
  *(u32 *)0x6e77d0 = 0;
}
PCREG(672260, flushList672260);

static void THISCALL flushList6722b0(void) {
  u32 ecx = *(u32 *)0x6e78ac;
  u32 eax = *(u32 *)0x6e78b0;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e78b0;
    ecx = *(u32 *)0x6e78ac;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e78ac = 0;
  *(u32 *)0x6e78b0 = 0;
}
PCREG(6722b0, flushList6722b0);

static void THISCALL flushList672300(void) {
  u32 ecx = *(u32 *)0x6e791c;
  u32 eax = *(u32 *)0x6e7920;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7920;
    ecx = *(u32 *)0x6e791c;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e791c = 0;
  *(u32 *)0x6e7920 = 0;
}
PCREG(672300, flushList672300);

static void THISCALL flushList672350(void) {
  u32 ecx = *(u32 *)0x6e7794;
  u32 eax = *(u32 *)0x6e7798;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7798;
    ecx = *(u32 *)0x6e7794;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7794 = 0;
  *(u32 *)0x6e7798 = 0;
}
PCREG(672350, flushList672350);

static void THISCALL flushList6723a0(void) {
  u32 ecx = *(u32 *)0x6e7994;
  u32 eax = *(u32 *)0x6e7998;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7998;
    ecx = *(u32 *)0x6e7994;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7994 = 0;
  *(u32 *)0x6e7998 = 0;
}
PCREG(6723a0, flushList6723a0);

static void THISCALL flushList6723f0(void) {
  u32 ecx = *(u32 *)0x6e79cc;
  u32 eax = *(u32 *)0x6e79d0;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e79d0;
    ecx = *(u32 *)0x6e79cc;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e79cc = 0;
  *(u32 *)0x6e79d0 = 0;
}
PCREG(6723f0, flushList6723f0);

static void THISCALL flushList672440(void) {
  u32 ecx = *(u32 *)0x6e7a04;
  u32 eax = *(u32 *)0x6e7a08;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7a08;
    ecx = *(u32 *)0x6e7a04;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7a04 = 0;
  *(u32 *)0x6e7a08 = 0;
}
PCREG(672440, flushList672440);

static void THISCALL flushList672490(void) {
  u32 ecx = *(u32 *)0x6e7bb0;
  u32 eax = *(u32 *)0x6e7bb4;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7bb4;
    ecx = *(u32 *)0x6e7bb0;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7bb0 = 0;
  *(u32 *)0x6e7bb4 = 0;
}
PCREG(672490, flushList672490);

static void THISCALL flushList6724e0(void) {
  u32 ecx = *(u32 *)0x6e7c4c;
  u32 eax = *(u32 *)0x6e7c50;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7c50;
    ecx = *(u32 *)0x6e7c4c;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7c4c = 0;
  *(u32 *)0x6e7c50 = 0;
}
PCREG(6724e0, flushList6724e0);

static void THISCALL flushList672530(void) {
  u32 ecx = *(u32 *)0x6e7c18;
  u32 eax = *(u32 *)0x6e7c1c;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7c1c;
    ecx = *(u32 *)0x6e7c18;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7c18 = 0;
  *(u32 *)0x6e7c1c = 0;
}
PCREG(672530, flushList672530);

static void THISCALL flushList672580(void) {
  u32 ecx = *(u32 *)0x6e7c80;
  u32 eax = *(u32 *)0x6e7c84;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7c84;
    ecx = *(u32 *)0x6e7c80;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7c80 = 0;
  *(u32 *)0x6e7c84 = 0;
}
PCREG(672580, flushList672580);

static void THISCALL flushList6725d0(void) {
  u32 ecx = *(u32 *)0x6e7be4;
  u32 eax = *(u32 *)0x6e7be8;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e7be8;
    ecx = *(u32 *)0x6e7be4;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e7be4 = 0;
  *(u32 *)0x6e7be8 = 0;
}
PCREG(6725d0, flushList6725d0);

static void THISCALL flushList672620(void) {
  u32 ecx = *(u32 *)0x6e8994;
  u32 eax = *(u32 *)0x6e8998;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8998;
    ecx = *(u32 *)0x6e8994;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8994 = 0;
  *(u32 *)0x6e8998 = 0;
}
PCREG(672620, flushList672620);

static void THISCALL flushList672670(void) {
  u32 ecx = *(u32 *)0x6e89c8;
  u32 eax = *(u32 *)0x6e89cc;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e89cc;
    ecx = *(u32 *)0x6e89c8;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e89c8 = 0;
  *(u32 *)0x6e89cc = 0;
}
PCREG(672670, flushList672670);

static void THISCALL flushList6726c0(void) {
  u32 ecx = *(u32 *)0x6e8a00;
  u32 eax = *(u32 *)0x6e8a04;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8a04;
    ecx = *(u32 *)0x6e8a00;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8a00 = 0;
  *(u32 *)0x6e8a04 = 0;
}
PCREG(6726c0, flushList6726c0);

static void THISCALL flushList672710(void) {
  u32 ecx = *(u32 *)0x6e8a34;
  u32 eax = *(u32 *)0x6e8a38;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8a38;
    ecx = *(u32 *)0x6e8a34;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8a34 = 0;
  *(u32 *)0x6e8a38 = 0;
}
PCREG(672710, flushList672710);

static void THISCALL flushList672760(void) {
  u32 ecx = *(u32 *)0x6e8a68;
  u32 eax = *(u32 *)0x6e8a6c;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8a6c;
    ecx = *(u32 *)0x6e8a68;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8a68 = 0;
  *(u32 *)0x6e8a6c = 0;
}
PCREG(672760, flushList672760);

static void THISCALL flushList6727b0(void) {
  u32 ecx = *(u32 *)0x6e8a9c;
  u32 eax = *(u32 *)0x6e8aa0;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8aa0;
    ecx = *(u32 *)0x6e8a9c;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8a9c = 0;
  *(u32 *)0x6e8aa0 = 0;
}
PCREG(6727b0, flushList6727b0);

static void THISCALL flushList672800(void) {
  u32 ecx = *(u32 *)0x6e8ad0;
  u32 eax = *(u32 *)0x6e8ad4;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8ad4;
    ecx = *(u32 *)0x6e8ad0;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8ad0 = 0;
  *(u32 *)0x6e8ad4 = 0;
}
PCREG(672800, flushList672800);

static void THISCALL flushList672850(void) {
  u32 ecx = *(u32 *)0x6e8b04;
  u32 eax = *(u32 *)0x6e8b08;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8b08;
    ecx = *(u32 *)0x6e8b04;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8b04 = 0;
  *(u32 *)0x6e8b08 = 0;
}
PCREG(672850, flushList672850);

static void THISCALL flushList6728a0(void) {
  u32 ecx = *(u32 *)0x6e8b3c;
  u32 eax = *(u32 *)0x6e8b40;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8b40;
    ecx = *(u32 *)0x6e8b3c;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8b3c = 0;
  *(u32 *)0x6e8b40 = 0;
}
PCREG(6728a0, flushList6728a0);

static void THISCALL flushList6728f0(void) {
  u32 ecx = *(u32 *)0x6e8b70;
  u32 eax = *(u32 *)0x6e8b74;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8b74;
    ecx = *(u32 *)0x6e8b70;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8b70 = 0;
  *(u32 *)0x6e8b74 = 0;
}
PCREG(6728f0, flushList6728f0);

static void THISCALL flushList672940(void) {
  u32 ecx = *(u32 *)0x6e8bd8;
  u32 eax = *(u32 *)0x6e8bdc;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8bdc;
    ecx = *(u32 *)0x6e8bd8;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8bd8 = 0;
  *(u32 *)0x6e8bdc = 0;
}
PCREG(672940, flushList672940);

static void THISCALL flushList672990(void) {
  u32 ecx = *(u32 *)0x6e8ba4;
  u32 eax = *(u32 *)0x6e8ba8;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8ba8;
    ecx = *(u32 *)0x6e8ba4;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8ba4 = 0;
  *(u32 *)0x6e8ba8 = 0;
}
PCREG(672990, flushList672990);

static void THISCALL flushList6729e0(void) {
  u32 ecx = *(u32 *)0x6e8c10;
  u32 eax = *(u32 *)0x6e8c14;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8c14;
    ecx = *(u32 *)0x6e8c10;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8c10 = 0;
  *(u32 *)0x6e8c14 = 0;
}
PCREG(6729e0, flushList6729e0);

static void THISCALL flushList672a30(void) {
  u32 ecx = *(u32 *)0x6e8c48;
  u32 eax = *(u32 *)0x6e8c4c;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8c4c;
    ecx = *(u32 *)0x6e8c48;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8c48 = 0;
  *(u32 *)0x6e8c4c = 0;
}
PCREG(672a30, flushList672a30);

static void THISCALL flushList672a80(void) {
  u32 ecx = *(u32 *)0x6e8c7c;
  u32 eax = *(u32 *)0x6e8c80;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8c80;
    ecx = *(u32 *)0x6e8c7c;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8c7c = 0;
  *(u32 *)0x6e8c80 = 0;
}
PCREG(672a80, flushList672a80);

static void THISCALL flushList672ad0(void) {
  u32 ecx = *(u32 *)0x6e8cb0;
  u32 eax = *(u32 *)0x6e8cb4;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8cb4;
    ecx = *(u32 *)0x6e8cb0;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8cb0 = 0;
  *(u32 *)0x6e8cb4 = 0;
}
PCREG(672ad0, flushList672ad0);

static void THISCALL flushList672b20(void) {
  u32 ecx = *(u32 *)0x6e8ce4;
  u32 eax = *(u32 *)0x6e8ce8;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8ce8;
    ecx = *(u32 *)0x6e8ce4;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8ce4 = 0;
  *(u32 *)0x6e8ce8 = 0;
}
PCREG(672b20, flushList672b20);

static void THISCALL flushList672b70(void) {
  u32 ecx = *(u32 *)0x6e8d18;
  u32 eax = *(u32 *)0x6e8d1c;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8d1c;
    ecx = *(u32 *)0x6e8d18;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8d18 = 0;
  *(u32 *)0x6e8d1c = 0;
}
PCREG(672b70, flushList672b70);

static void THISCALL flushList672bc0(void) {
  u32 ecx = *(u32 *)0x6e8e20;
  u32 eax = *(u32 *)0x6e8e24;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8e24;
    ecx = *(u32 *)0x6e8e20;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8e20 = 0;
  *(u32 *)0x6e8e24 = 0;
}
PCREG(672bc0, flushList672bc0);

static void THISCALL flushList672c10(void) {
  u32 ecx = *(u32 *)0x6e8db0;
  u32 eax = *(u32 *)0x6e8db4;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8db4;
    ecx = *(u32 *)0x6e8db0;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8db0 = 0;
  *(u32 *)0x6e8db4 = 0;
}
PCREG(672c10, flushList672c10);

static void THISCALL flushList672c60(void) {
  u32 ecx = *(u32 *)0x6e8de8;
  u32 eax = *(u32 *)0x6e8dec;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8dec;
    ecx = *(u32 *)0x6e8de8;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8de8 = 0;
  *(u32 *)0x6e8dec = 0;
}
PCREG(672c60, flushList672c60);

static void THISCALL flushList672cb0(void) {
  u32 ecx = *(u32 *)0x6e8e58;
  u32 eax = *(u32 *)0x6e8e5c;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8e5c;
    ecx = *(u32 *)0x6e8e58;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8e58 = 0;
  *(u32 *)0x6e8e5c = 0;
}
PCREG(672cb0, flushList672cb0);

static void THISCALL flushList672d00(void) {
  u32 ecx = *(u32 *)0x6e8e94;
  u32 eax = *(u32 *)0x6e8e98;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8e98;
    ecx = *(u32 *)0x6e8e94;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8e94 = 0;
  *(u32 *)0x6e8e98 = 0;
}
PCREG(672d00, flushList672d00);

static void THISCALL flushList672d50(void) {
  u32 ecx = *(u32 *)0x6e8ec8;
  u32 eax = *(u32 *)0x6e8ecc;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8ecc;
    ecx = *(u32 *)0x6e8ec8;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8ec8 = 0;
  *(u32 *)0x6e8ecc = 0;
}
PCREG(672d50, flushList672d50);

static void THISCALL flushList672da0(void) {
  u32 ecx = *(u32 *)0x6e8efc;
  u32 eax = *(u32 *)0x6e8f00;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8f00;
    ecx = *(u32 *)0x6e8efc;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8efc = 0;
  *(u32 *)0x6e8f00 = 0;
}
PCREG(672da0, flushList672da0);

static void THISCALL flushList672df0(void) {
  u32 ecx = *(u32 *)0x6e8f30;
  u32 eax = *(u32 *)0x6e8f34;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8f34;
    ecx = *(u32 *)0x6e8f30;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8f30 = 0;
  *(u32 *)0x6e8f34 = 0;
}
PCREG(672df0, flushList672df0);

static void THISCALL flushList672e40(void) {
  u32 ecx = *(u32 *)0x6e8f64;
  u32 eax = *(u32 *)0x6e8f68;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8f68;
    ecx = *(u32 *)0x6e8f64;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8f64 = 0;
  *(u32 *)0x6e8f68 = 0;
}
PCREG(672e40, flushList672e40);

static void THISCALL flushList672e90(void) {
  u32 ecx = *(u32 *)0x6e8f98;
  u32 eax = *(u32 *)0x6e8f9c;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8f9c;
    ecx = *(u32 *)0x6e8f98;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8f98 = 0;
  *(u32 *)0x6e8f9c = 0;
}
PCREG(672e90, flushList672e90);

static void THISCALL flushList672ee0(void) {
  u32 ecx = *(u32 *)0x6e8fd8;
  u32 eax = *(u32 *)0x6e8fdc;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6e8fdc;
    ecx = *(u32 *)0x6e8fd8;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6e8fd8 = 0;
  *(u32 *)0x6e8fdc = 0;
}
PCREG(672ee0, flushList672ee0);

static void THISCALL flushList672f30(void) {
  u32 ecx = *(u32 *)0x6ec3a4;
  u32 eax = *(u32 *)0x6ec3a8;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6ec3a8;
    ecx = *(u32 *)0x6ec3a4;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6ec3a4 = 0;
  *(u32 *)0x6ec3a8 = 0;
}
PCREG(672f30, flushList672f30);

static void THISCALL flushList672f80(void) {
  u32 ecx = *(u32 *)0x6ec4a0;
  u32 eax = *(u32 *)0x6ec4a4;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6ec4a4;
    ecx = *(u32 *)0x6ec4a0;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6ec4a0 = 0;
  *(u32 *)0x6ec4a4 = 0;
}
PCREG(672f80, flushList672f80);

static void THISCALL flushList672fe0(void) {
  u32 ecx = *(u32 *)0x6ec540;
  u32 eax = *(u32 *)0x6ec544;
  if (ecx != 0) {
    *(u32 *)(ecx + 0x14) = eax;
    eax = *(u32 *)0x6ec544;
    ecx = *(u32 *)0x6ec540;
  } else {
    *(u32 *)0x7003bc = eax;
  }
  if (eax != 0)
    *(u32 *)(eax + 0x10) = ecx;
  else
    *(u32 *)0x7003c0 = ecx;
  *(u32 *)0x6ec540 = 0;
  *(u32 *)0x6ec544 = 0;
}
PCREG(672fe0, flushList672fe0);
