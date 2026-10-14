"""specs_u69_80.py - area 69, residue-8 forwarder 0x664202 (lea ecx,[ebp-0x90]; jmp 0x4cbec0).
The forwarder needs a valid EBP, so the spec passes EBP through the ('regs', ['ebp']) ABI with a buffer in emulator memory.
The target 0x4cbec0 is real: if the list head is not empty it calls 0x634273(first, 1), which is not exercised here (its body is unchecked).
Only the empty-list path (head next == head+4) is generated, so the non-empty branch is not covered by this spec."""
from pilot import S
from ckit import rnd


def _frame(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    head = ebp - 0x90          # the forwarder passes this as ECX
    e.w32(head, head + 4)      # empty list: first == &sentinel
    return [ebp]


S(0x664202, 'fwd664202 (naked forwarder to 0x4cbec0, EBP-relative object)', ('regs', ['ebp']), None, ret=None, gen=_frame,
  note='u69 group 80; empty-list path only; 0x634273 branch unexercised')
