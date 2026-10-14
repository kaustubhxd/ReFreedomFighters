"""specs_s2905.py - unclaimed-29 batch 5 (docs/20-unclaimed-29.md, claim 5, slice 8): CCheckInsideBox::Load. The load object's
slot +0x40 writes a per-call value through its pointer argument (the argument slot is written and read back); the render object
at the global 0x70039c+0x9b returns a per-case value from slot +0x58."""
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


def _gen(c):
    vals = [c.rng.getrandbits(32) for _ in range(4)]
    state = {'i': 0}

    def write_through(e, r):
        ptr = e.arg32(0)
        e.calllog.append(('load-slot40', e.reg('ecx'), ()))
        e.w32(ptr, vals[state['i'] % 4])
        state['i'] += 1
        e.ret(eax=0, argbytes=4)
    load_vt = c.emu.fake_vtable('zloadgame-box', 0x44, {0x40: write_through})
    load = _rnd(c, 0x40)
    c.emu.w32(load, load_vt)

    rv = c.rng.getrandbits(32)
    rm_obj_vt = c.emu.logging_vtable('render-obj', 0x60, impl={0x58: lambda e, a: (rv, None)}, argwords={0x58: 1})
    rm_obj = _rnd(c, 0x40)
    c.emu.w32(rm_obj, rm_obj_vt)
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, rm_obj)
    c.emu.w32(0x70039c, rm)
    self_ = _rnd(c, 0x100)
    return [self_, load]


S(0x5b8180, 'CCheckInsideBox::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-29 batch 5 (slice 8); load slot +0x40 writes through pointers; render object slot +0x58 twice')
