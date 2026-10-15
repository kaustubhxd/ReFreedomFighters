"""specs_s957.py - residue-03, batch 957: CAction::AddAction (0x49f9b0), fastcall (this in ECX, arg1 in EDX, six stack
args). The action lookup (vslot 0x100 / 0x10c), the action's vslots 0x5c and 0xb0, the global manager's vslots 0x20, 0xac
and 0xcc and its callback (+8) are stubs. The entry object sits at e+4 so that [esi-4] is readable. The manager's range
(+0xc, +0x10) is set around the entry's address to take both sides of the test."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _stub, obj, r32


def mkvt(c, slots):
    tmp = obj(c, 0x40, slots)
    return c.emu.r32(tmp)


def g(c):
    o = c.emu.alloc(0x40, 16)
    esi = o + 4
    c.emu.w32(o, c.rng.choice([0, r32(c)]))
    c.emu.w32(esi, mkvt(c, {0x5c: _stub(c, 3), 0xb0: _stub(c, 8)}))
    cb = _stub(c, 0, ret=r32(c))
    gobj = obj(c, 0x40, {0x20: _stub(c, 1, ret=c.rng.randint(0, 1)), 0xac: _stub(c, 1), 0xcc: _stub(c, 1)})
    c.emu.w32(gobj + 8, cb if c.rng.random() < 0.7 else 0)
    c.emu.w32(gobj + 0xc, c.rng.choice([0, esi, esi + 1, esi - 1]))
    c.emu.w32(gobj + 0x10, c.rng.choice([esi + 1, esi, esi - 1, 0]))
    c.emu.w32(0x70038c, gobj)
    t = obj(c, 0x80, {0x100: _stub(c, 1, ret=(esi if c.rng.random() < 0.7 else 0)), 0x10c: _stub(c, 2, ret=esi)})
    return [t] + [r32(c) for _ in range(7)]


S(0x49f9b0, 'CAction::AddAction', 'fastcall', gen=g)
