"""specs_s8805.py - hitreact batch 8805: ZFFActorActionCloseCombat::Update (0x5eb7e0). vdist 0x4e0870 runs as exe code. The
attacker's / target's slot 0x84 fill a per-case root point; the target's slot 0x128 records the message id, the arguments
and the 11 dwords of the SDamageInfo at action +0x21 (a heap pointer, so also recorded as is)."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge
from hkit import rec_stub, fvec


def _gen(c):
    r = c.rng
    emu = c.emu
    fv = lambda: r.choice((r.uniform(-300, 300), 0.0, fedge(c)))
    A = [r.uniform(-300, 300) for _ in range(3)]
    if r.random() < 0.4:   # on the 170 boundary (horizontal), any height
        B = [A[0] + r.choice((170.0, 169.99, 170.01, 169.5, 170.5)), r.uniform(-300, 300), A[2]]
    else:
        B = [fv() for _ in range(3)]
    pa = fvec(c, A)
    pb = fvec(c, B)
    at = obj(c, 0x100, {0x84: rec_stub(c, 1, skip=(0,), fills={0: (pa, 3, 0)})})
    tg = obj(c, 0x200, {0x84: rec_stub(c, 1, skip=(0,), fills={0: (pb, 3, 0)}),
                        0x128: rec_stub(c, 3, ptrs={1: [(4 * i, 'd') for i in range(11)]})})
    eng = rnd(c, 0x80)
    now = r.randrange(0, 1 << 20)
    emu.w32(eng + 0x40, now)
    emu.w32(0x70039c, eng)
    emu.w16(0x7143a8, r.getrandbits(16))
    self = rnd(c, 0x60)
    emu.w8(self + 0x20, r.choice((0, 1, 1, 0x80)))
    emu.w32(self + 8, at)
    emu.w32(self + 0xc, tg)
    t = r.choice((now / 1024.0, (now + 1) / 1024.0, (now - 1) / 1024.0, r.uniform(0, 2048), fedge(c)))
    emu.wf32(self + 0x1c, t)
    emu.mu.ctl_flush_tb()
    return [self]


S(0x5eb7e0, 'ZFFActorActionCloseCombat::Update', 'thiscall', ret='al', gen=_gen)
