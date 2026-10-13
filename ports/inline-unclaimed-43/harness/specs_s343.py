"""specs_s343.py - gap band batch 343: 0x41f680 forwards to 0x4d0690 with ecx = dword [this+0x31]; the target returns the address
(ecx + 0x217). The result is an address inside the target block, which is the same in both runs."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x40)
    tgt = E.zero_obj(c, 0x240)
    c.emu.w32(o + 0x31, tgt)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x41f680, 'forward to address getter 0x4d0690 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='gap band batch 343; target 0x4d0690 is original exe code')
