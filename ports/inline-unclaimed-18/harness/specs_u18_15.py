"""specs_u18_15.py - core-todo residue 17 (unclaimed-18 thread): ZRelayMessageList::CopyData (0x4b8950)."""
from pilot import S
from ckit import obj, rnd, rvt


def _rmlcd(c):
    r = c.rng
    e = c.emu
    this = rnd(c, 0x100)
    ev = rnd(c, 0x100)
    k = [r.choice([0, 1, 2, 3])]          # how many more values the event's object yields
    def f4c(e, t, a):
        e.wbytes(a[0], (1 if k[0] > 0 else 0).to_bytes(4, 'little'))
        return (0, None, ('f4c',))
    def f5c(e, t, a):
        if k[0] > 0:
            k[0] -= 1
            e.wbytes(a[0], (1).to_bytes(4, 'little'))
        else:
            e.wbytes(a[0], (0).to_bytes(4, 'little'))
        return (r.getrandbits(32), None, ('f5c',))
    evobj = obj(e, 'evobj', 0x40, {0x4c: (1, f4c), 0x5c: (1, f5c)}, nslots=0x60 // 4)
    if r.random() < 0.8:
        e.w32(ev + 0x4c, evobj)
    else:
        e.w32(ev + 0x4c, 0)
    thisobj = obj(e, 'thisobj', 0x40, {0x4: (1, lambda e, t, a: (0, None, (a[0],)))}, nslots=0x10)
    e.w32(this + 0x4c, thisobj)
    return [this, ev]


S(0x4b8950, 'ZRelayMessageList::CopyData', 'thiscall', None, ret=None, gen=_rmlcd, note='u18 core residue 17')
