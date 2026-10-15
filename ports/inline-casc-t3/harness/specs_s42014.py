"""specs_s42014.py - Sonnet t3 batch 42014. 0x4af0d0 returns a float on st0 (ret='st0'). Iterator object [this+0x18] (null in a tenth of the cases): slot 0x4c (init, cursor pointer flagged),
slot 0x64 (next: returns the nodes of a spec list in order, then 0). Nodes have +0x48 (-1 in a third), +0x74 -> block with a vec3 at +0x70 (often zero)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fv(r):
    return r.choice([0.0, 0.0, r.uniform(-10, 10), r.uniform(-1e3, 1e3), 1e-30, float('nan')])


def g4af0d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3, 5])):
        n = rnd(c, 0x90)
        b = rnd(c, 0xa0)
        e.wbytes(n + 0x48, struct.pack('<i', -1 if r.random() < 0.33 else r.getrandbits(31)))
        e.w32(n + 0x74, b)
        e.wbytes(b + 0x70, struct.pack('<fff', _fv(r), _fv(r), _fv(r)))
        nodes.append(n)
    ret = lambda em, k: nodes[k] if k < len(nodes) else 0
    it = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,)), 0x64: pystub(c, 1, this=True, nullflag=(0,), ret=ret)})
    me = rnd(c, 0x40)
    e.w32(me + 0x18, it if r.random() < 0.9 else 0)
    return [me]


S(0x4af0d0, 'GUESS length of the first live node vector', 'thiscall', None, ret='st0', gen=g4af0d0, note='batch42014')
