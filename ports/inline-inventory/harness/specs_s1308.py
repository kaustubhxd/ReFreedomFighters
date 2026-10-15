"""specs_s1308.py - inventory thread batch 1308 (src/batch1308.cpp): CInventory Init / Save / Load."""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c


def _o(c, n=0x200):
    return rnd(c, n)


def _sys(c, r):
    sysobj = _o(c, 0x2000)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x9b, r.obj(0x200, {0x114: r.stub(1, 4, rand=True)}))


def init(c):
    r = Rec(c)
    _sys(c, r)
    return [_o(c)]


def stream(c, r, slots):
    return r.obj(0x40, {s: r.stub(sid, 1, rand=True) for s, sid in slots})


def save(c):
    r = Rec(c)
    o = _o(c)
    c.emu.w32(o + 4, c.rng.getrandbits(32))
    g = stream(c, r, [(0x40, 1), (0x3c, 2), (0x6c, 3)])
    return [o, g]


def load(c):
    r = Rec(c)
    o = _o(c)
    c.emu.w32(o + 4, c.rng.getrandbits(32))
    # the action REFTAB is embedded at +0x1c6: its vtable pointer sits there
    c.emu.w32(o + 0x1c6, r.vtable({0xc: r.stub(4, 0, rand=True)}))
    g = stream(c, r, [(0x40, 1), (0x44, 2), (0x70, 3)])
    return [o, g]


S(0x4ab9e0, 'CInventory::Init', 'thiscall', None, ret=None, gen=init, note='batch1308')
S(0x4acb30, 'CInventory::Save', 'thiscall', None, ret='al', gen=save, note='batch1308')
S(0x4acc20, 'CInventory::Load', 'thiscall', None, ret='al', gen=load, note='batch1308')
