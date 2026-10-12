"""specs_s971.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42cfd0 (see src/batch971.cpp). The callee 0x4d2ed0 (claimed in
docs/20-unclaimed-22.md) is hooked by address with a recording thiscall stub: it logs ecx and its argument, and returns a per-case value
(zero 30%). The out-pointer is null 30% of the time, else a heap dword."""
from pilot import S


def _gen(c):
    r = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32) | 1

    def h(em, rr):
        c.emu.calllog.append(('4d2ed0', None, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=r, argbytes=4)

    c.emu.hook(0x4d2ed0, h)
    out = 0
    if c.rng.random() >= 0.3:
        out = c.emu.alloc(4, 4)
        c.emu.w32(out, c.rng.getrandbits(32))
    return [c.rng.getrandbits(32), out]


S(0x42cfd0, 'wrapper around 0x4d2ed0 (unknown) stdcall', 'stdcall', None, ret='al', gen=_gen,
  note='unclaimed-80 gap band; callee 0x4d2ed0 hooked by address (claimed elsewhere); result to out-pointer; returns r != 0')
