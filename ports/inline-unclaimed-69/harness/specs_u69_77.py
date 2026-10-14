"""specs_u69_77.py - area 69, group 77 (slice 8): 0x64c240. Callees 0x63ea00 and 0x64d5f0 are GUESS stubs (thiscall, one stack arg, ret 4): they log
ECX and the arg as booleans against the spec's objects. The ring is at [self+0x1005d]+0x268 (write pointer at +0x268 inside a 0x8300-byte object).
The record chain uses +0x1c links (acyclic); each record's +8 is a 0x80-byte object whose byte +0x3e is 0 or 1 (so the decrement can reach zero)."""
from pilot import S
from ckit import rnd


def _leave(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x1008 + 0x10)
    P0 = rnd(c, 0x8300)
    e.w32(self_ + 0x1005d, P0)
    ring0 = P0 + 0x268 + 8
    if r.random() < 0.2:
        w = ring0 + 4 * 0x1fff       # the slot before the end: the write wraps
    else:
        w = ring0 + 4 * r.randrange(0, 0x2000)
    e.w32(P0 + 0x268, w)
    g = rnd(c, 0x100)
    e.w32(0x70039c, g)
    e.w32(g + 0x3c, r.getrandbits(32))
    objs = {}
    e.hook(0x63ea00, lambda e, res: (e.calllog.append(('t63ea00', int(e.reg('ecx') == P0), int(e.arg32(0) == e.arg32(0)))), e.ret(argbytes=4)))
    e.hook(0x64d5f0, lambda e, res: (e.calllog.append(('t64d5f0', int(e.reg('ecx') == self_), int(e.arg32(0) != 0))), e.ret(argbytes=4)))
    k = r.randrange(1, 4)
    recs = [rnd(c, 0x40) for _ in range(k)]
    for i, rec in enumerate(recs):
        X = rnd(c, 0x80)
        e.w32(rec + 8, X)
        e.wbytes(X + 0x3e, bytes([r.choice([0, 1, 2])]))
        e.w32(rec + 0x1c, recs[i + 1] if i + 1 < k else 0)
    return [self_, recs[0]]


S(0x64c240, 'geomLeave64c240 (thiscall, one arg, ret 4)', 'thiscall', None, ret=None, gen=_leave,
  note='u69 group 77; GUESS stubs 0x63ea00 and 0x64d5f0 (thiscall, one arg, ret 4)')
