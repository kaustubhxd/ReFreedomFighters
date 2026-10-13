"""specs_s317.py - unclaimed-43 batch 317: 0x5edbe0, thiscall, three stack arguments (the third unused), ret 0xc.
Half the cases pass the stored pair (no change); the rest pass a new pair. The object is a zeroed block with random bytes
around the fields, so the heap compare sees each store and the flag byte at +0xa6."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x100)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x100)))
    a = r.getrandbits(32)
    b = r.getrandbits(32)
    if r.random() < 0.5:
        c.emu.w32(o + 0xe7, a)
        c.emu.w32(o + 0xef, b)
    else:
        c.emu.w32(o + 0xe7, r.getrandbits(32))
        c.emu.w32(o + 0xef, b if r.random() < 0.5 else r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o, a, b, r.getrandbits(32)]


S(0x5edbe0, 'set pair if changed (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 317 (leaf)')
