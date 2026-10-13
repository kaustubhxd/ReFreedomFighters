"""specs_s2717.py - unclaimed-27 batch 17: LINKREFTAB::RunInitNxtRef (0x4cf0c0, thiscall, ret 4) and FUN_55c740 (GUESS, thiscall,
ret 4). The lookup 0x5003d0 is HOOKED (stub, not verified): it records its this and argument in a heap record and returns a
fresh object whose first dword is random."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rri(c):
    o = _rnd(c, 0x800)
    run = _rnd(c, 8)
    return [o, run]


def _f55(c):
    rec = c.emu.alloc(0x10, 4)
    pobj = _rnd(c, 0x100)
    c.emu.w32(pobj, c.rng.choice([0, 1, c.rng.getrandbits(32)]))

    def h(e, r, rec=rec, pobj=pobj):
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.arg32(0))
        e.ret(eax=pobj, argbytes=4)

    c.emu.hook(0x5003d0, h)
    o = _rnd(c, 0x800)
    c.emu.w32(o + 0x1c, _rnd(c, 0x1000))   # the byte stored is at +0x917, so this object must be larger than 0x918
    arg = _rnd(c, 0x100)
    c.emu.w32(arg + 4, c.rng.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o, arg]


S(0x4cf0c0, 'LINKREFTAB::RunInitNxtRef (unknown) thiscall', 'thiscall', None, ret=None, gen=_rri,
  note='batch 17; sets arg[0]=0, arg[1]=1 and clears the top bit of +0xc')
S(0x55c740, 'FUN_55c740 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f55,
  note='batch 17; lookup 0x5003d0 is a hook (stub)')
