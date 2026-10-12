"""specs_s298.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4a50b0 and 0x5816f0 (scalar-deleting dtors with an
SEH frame, not reproduced). Stubs: the engine-object slot 0x34 (logged), the exe helper 0x4690b0 (logged, cdecl), and the
global callback at 0x7003b0 (always set to a logged stub: with it null the exe asserts, int3, which is not ported)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dtor(c):
    e = c.emu

    def h4690(em, r):
        em.calllog.append(('h4690b0', 0x4690b0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    e.hook(0x4690b0, h4690)
    def cbh(em, r):                         # the exe asserts (int3) when the callback is null, so it is always set here
        em.calllog.append(('cb7003', 0x7003b0, None, ()))
        em.ret(eax=0, argbytes=0)
    cb = e._new_stub('cb7003', cbh)            # a code stub: heap memory is not executable
    e.w32(0x7003b0, cb)

    o_vt = e.logging_vtable('eng9b5b', 0x0e, impl={}, argwords={0x34: 1})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    self_ = _rnd(c, 0x80)
    flags = c.rng.choice([0, 1, 2, 4, 5, 3, 7, c.rng.getrandbits(32)])
    return [self_, flags]


S(0x4a50b0, 'dtorA (GUESS)', 'thiscall', None, ret='eax', gen=_dtor, note='batch298; ret 4; SEH frame not reproduced')
S(0x5816f0, 'dtorB (GUESS)', 'thiscall', None, ret='eax', gen=_dtor, note='batch298; ret 4; SEH frame not reproduced')
