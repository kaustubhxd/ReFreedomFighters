"""specs_s4001.py - area 70 batch 4001: five plain leaves. Random object bytes so every read and store is checked.
0x5ab0d0 is given the sentinel 0x10000000 in +0x300 about a quarter of the time so both branches run."""
from pilot import S, F


def _obj(c, sentinel=False):
    e, r = c.emu, c.rng
    o = e.alloc(0x1000, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x1000)))
    if sentinel:
        e.w32(o + 0x300, 0x10000000 if r.random() < 0.5 else r.getrandbits(32))
    return o


def _getter(c):
    return [_obj(c)]


def _setdw(c):
    return [_obj(c), c.rng.getrandbits(32)]


def _setfields(c):
    return [_obj(c), c.rng.getrandbits(32), F(c.fv(-1000.0, 1000.0))]


def _setdw2(c):
    return [_obj(c), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _add(c):
    return [_obj(c, sentinel=True), c.rng.getrandbits(32)]


S(0x562010, 'getter at +0x85 (area 70 leaf)', 'thiscall', None, ret='al', gen=_getter, note='batch4001')
S(0x49e250, 'setter dword at +0 (area 70 leaf)', 'thiscall', None, gen=_setdw, note='batch4001')
S(0x514450, 'two-field setter +0x1e5/+0x1e9 (area 70 leaf)', 'thiscall', None, gen=_setfields, note='batch4001')
S(0x53c590, 'two-dword setter +4/+8 (area 70 leaf)', 'thiscall', None, gen=_setdw2, note='batch4001')
S(0x5ab0d0, 'conditional add +0x8c3 (area 70 leaf)', 'thiscall', None, gen=_add, note='batch4001')
