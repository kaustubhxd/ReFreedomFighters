"""specs_s2715.py - unclaimed-27 batch 15: FUN_4e5140 (GUESS, thiscall, returns eax) and FUN_508640 (GUESS, thiscall, ret 4).
FUN_508640's lookup 0x5003d0 is HOOKED (stub, not verified): it records its this and its argument in a heap record and returns
a fresh object P whose first dword is random (so the flag varies)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _p4e(c):
    o = _rnd(c, 0x800)
    c.emu.w32(o + 4, c.rng.choice([c.rng.getrandbits(32), 0x40000000, 0x80000000, 0x7fffffff, 0x80000001, 0xc0000000]))
    c.emu.w32(o + 0x10, c.rng.randint(0, 0x100) if c.rng.random() < 0.7 else c.rng.getrandbits(32))
    return [o]


def _p508(c):
    rec = c.emu.alloc(0x10, 4)
    pobj = _rnd(c, 0x100)
    c.emu.w32(pobj, c.rng.choice([0, 1, c.rng.getrandbits(32)]))

    def h(e, r, rec=rec, pobj=pobj):
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.arg32(0))
        e.ret(eax=pobj, argbytes=4)

    c.emu.hook(0x5003d0, h)
    o = _rnd(c, 0x800)
    c.emu.w32(o + 0x18, _rnd(c, 0x800))
    arg = _rnd(c, 0x100)
    c.emu.w32(arg + 4, c.rng.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o, arg]


S(0x4e5140, 'FUN_4e5140 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_p4e, note='residue of area 27 batch 15')
S(0x508640, 'FUN_508640 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_p508,
  note='batch 15; lookup 0x5003d0 is a hook (stub)')
