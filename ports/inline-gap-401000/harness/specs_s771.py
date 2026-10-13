"""specs_s771.py - gap band batch 771 (docs/20-gap-band-401000.md): 0x4106b0, cdecl (a, b). 0x410560 (cdecl, two args) is a logging stub whose
result per call is taken from the case seed and the arguments (so the loop may run more than once; the flag at +0x10 decides the exit)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    seed = c.rng.getrandbits(32)

    def stub(e, r):
        k = hash((seed, e.arg32(0), e.arg32(1))) % 5
        v = (1, 0, -1, -1, 2)[k]
        # a negative result is only allowed while the flag at +0x10 is clear: once it is set the loop must end (else it never returns)
        if v < 0 and e.r32((e.arg32(0) + 0x10) & 0xffffffff) != 0:
            v = 0
        e.calllog.append(('0x410560', (e.arg32(0), e.arg32(1), v)))
        e.ret(eax=v & 0xffffffff, argbytes=0)
    ss.patch(c, 0x410560, c.emu.stub_fn('410560 logger', stub))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    a = _rnd(c, 0x20)
    c.emu.w32(a + 0x10, c.rng.choice([0, 1]))
    return [a, c.rng.getrandbits(32)]


S(0x4106b0, 'CRT helper 0x4106b0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 771: retry loop over the 0x410560 stub, flag at +0x10')
