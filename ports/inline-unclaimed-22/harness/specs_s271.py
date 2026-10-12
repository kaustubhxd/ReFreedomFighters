"""specs_s271.py - area 22, batch271 (src/batch271.cpp): ZMoveOnSpline::ZMoveOnSpline. The base geom constructor 0x43e990
and the REFTAB32 constructor 0x4ccba0 are not verified anywhere and are hooked as GUESS stubs (logged, return ecx). The
allocator 0x41e290 (unclaimed-64) runs as exe code over a Python allocator at [0x70038c] (slot 8) that hands out per-case
blocks or 0; the helper constructors 0x522e80 and 0x4ccbe0 (inline-batch45) run as exe code. Engine db vt[0x114] returns a
per-call random word. The global mover list [0x7003b8] gets a random count."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _hk


def _g_511cd0(c):
    e = c.emu
    db = _rnd(c, 0x100)
    e.w32(db, _multi_vt(c, {0x114: (lambda em, a: (c.rng.getrandbits(32), None), 4)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    blocks = [c.rng.choice([_rnd(c, sz), _rnd(c, sz), _rnd(c, sz), 0]) for sz in (0x67, 0xac, 0x1c, 0x1c)]
    seq = list(blocks)

    def alloc(em, a):
        return (seq.pop(0) if seq else 0, None)
    al = _rnd(c, 0x10)
    e.w32(al, _multi_vt(c, {8: (alloc, 1)}))
    e.w32(0x70038c, al)
    lst = _rnd(c, 0x420 + 4 * 40)
    e.w32(lst + 0x41c, c.rng.randrange(0, 39))
    e.w32(0x7003b8, lst)
    _hk(c, 0x43e990, 'base.43e990', 3, eax=lambda em: em.reg('ecx'))
    _hk(c, 0x4ccba0, 'reftab.4ccba0', 0, eax=lambda em: em.reg('ecx'))
    e.mu.ctl_flush_tb()
    return [_rnd(c, 0x220), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x511cd0, 'ZMoveOnSpline::ZMoveOnSpline', 'thiscall', None, ret='eax', gen=_g_511cd0,
  note='batch271; base ctor 0x43e990 and REFTAB32 ctor 0x4ccba0 hooked (GUESS); allocator and helper ctors as exe code; SEH frame and cookie not reproduced')
