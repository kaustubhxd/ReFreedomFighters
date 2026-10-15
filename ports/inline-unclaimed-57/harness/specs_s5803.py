"""specs_s5803.py - unclaimed-57, batch 103: 0x5d98b0 (GUESS name unnamed_5d98b0). Thiscall, no stack args, plain ret. The engine (global 0x70039c)
float at +0x48 is random in -40..40 (its scaled truncation is the step size). Both pairs (this+0x88, this+0x8c) and (this+0x90, this+0x94) are
small random integers, so the equal, the moving-up and the moving-down cases all occur. The callee 0x5d9f00 (another area's function) is a
logging stub with three arguments (twelve bytes popped); it writes nothing, so the fields it would move are checked by the heap comparison
of this, which holds the stored results."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d98b0(c):
    e = c.emu

    def h9f00(em, r):
        em.calllog.append(('9f00', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)
    e.hook(0x5d9f00, h9f00)

    eng = _rnd(c, 0x100)
    fv = c.rng.uniform(-40.0, 40.0)
    # the scale constant at 0x680a90 is 500.0, so a float of (k + 0.25) / 500 truncates to k: the step equals the distance exactly
    # in about three cases in ten (the strict > tests are checked at their edge)
    k = c.rng.randrange(0, 61)
    boundary = c.rng.random() < 0.3
    if boundary:
        fv = (k + 0.25) / 500.0
    e.wbytes(eng + 0x48, struct.pack('<f', fv))
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x200)
    for off in (0x88, 0x8c, 0x90, 0x94):
        e.w32(self_obj + off, c.rng.randrange(-60, 61) & 0xffffffff)
    if boundary:
        sign = 1 if c.rng.random() < 0.5 else -1
        for a_off, c_off in ((0x88, 0x8c), (0x90, 0x94)):
            cv = c.rng.randrange(-60, 61)
            e.w32(self_obj + c_off, cv & 0xffffffff)
            e.w32(self_obj + a_off, (cv + sign * k) & 0xffffffff)
    for off in (0x5c, 0x60, 0x68, 0x74, 0x78, 0x7c):
        e.w32(self_obj + off, c.rng.getrandbits(32))
    return [self_obj]


S(0x5d98b0, 'unnamed_5d98b0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d98b0,
  note='unclaimed-57 batch 103; callee 0x5d9f00 hooked (logs three args, pops twelve bytes); engine float at +0x48 random')
