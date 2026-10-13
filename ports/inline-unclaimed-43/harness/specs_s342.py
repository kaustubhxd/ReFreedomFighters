"""specs_s342.py - gap band batch 342: 0x41edd0 forwards to 0x4d0580 with ecx = dword [this+0x31]; the target returns the dword at
+0x213 of that object. Both objects are blocks with random bytes."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x40)
    tgt = E.zero_obj(c, 0x240)
    c.emu.wbytes(tgt, bytes(c.rng.getrandbits(8) for _ in range(0x240)))
    c.emu.w32(o + 0x31, tgt)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x41edd0, 'forward to getter 0x4d0580 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='gap band batch 342; target 0x4d0580 is original exe code')
