"""specs_s6505.py - unclaimed-65 batch 5 (docs/20-unclaimed-65.md, claim 5): ZShotActivate::RegisterMessages. The render object at
(global 0x70039c)+0x9b has slot +0x114 (four stack arguments, callee pops 16) that logs them and returns a per-case word. The
function takes no arguments. Translation cache flushed after the patch-free setup (no exe patch here)."""
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


def _setup(c):
    # slot +0x114 returns a per-call word (the four calls in order)
    vals = [c.rng.getrandbits(16) for _ in range(4)]
    state = {'i': 0}

    def reg(e, r):
        args = tuple(e.arg32(k) for k in range(4))
        e.calllog.append(('zmsg-114', e.reg('ecx'), args))
        v = vals[state['i'] % 4]
        state['i'] += 1
        e.ret(eax=v, argbytes=16)
    vt = c.emu.fake_vtable('render-zmsg', 0x140, {0x114: reg})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    rr = _rnd(c, 0x200)
    c.emu.w32(rr + 0x9b, obj)
    c.emu.w32(0x70039c, rr)


def _gen(c):
    return [_rnd(c, 0x40)]   # this (ecx) is ignored by the function


S(0x4c8fe0, 'ZShotActivate::RegisterMessages (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 5 (residue 18); four slot +0x114 calls (name, 0, file, line) storing words to 0x70036c..0x700378')
