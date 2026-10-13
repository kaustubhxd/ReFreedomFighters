"""specs_s319.py - unclaimed-43 batch 319: 0x469580, thiscall, no arguments, returns the dword at (this+0x40)+0x1f, or 0 when
this+0x40 is NULL (25% of cases). The dword is read unaligned (offset 0x1f)."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x40)
    # the low page is mapped and not compared: put nonzero bytes at 0x1f so a read through NULL would show
    c.emu.wbytes(0x1f, bytes(r.randrange(1, 256) for _ in range(4)))
    if r.random() >= 0.25:
        p = E.zero_obj(c, 0x40)
        c.emu.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x40)))
        c.emu.w32(o + 0x40, p)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x469580, 'dword at this+0x40 +0x1f (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-43 batch 319 (leaf)')
