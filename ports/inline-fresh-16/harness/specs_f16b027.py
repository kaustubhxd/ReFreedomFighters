"""specs_f16b027.py - fresh slice 16 batch 27 (see src/f16b027.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, fval, expstub
import struct


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _4e7(c):
    r = c.rng
    clear_hooks(c)
    expstub(c)
    me = rnd(c, 0x30)
    for o in range(0, 0x2c, 4):
        c.emu.w32(me + o, fval(c) if r.random() < 0.05 else _f(r.uniform(-100, 100)))
    k = r.random()
    c.emu.w32(me + 0xc, _f(r.choice([0.0, 0.001, 0.0009, r.uniform(0, 3), r.uniform(-1, 0)])) if k < 0.9 else fval(c))
    t = _f(r.uniform(-50, 150)) if r.random() < 0.9 else fval(c)
    return [me, rnd(c, 12), rnd(c, 12), t]


def _443(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    child = r.getrandbits(32)
    frees = [0, r.choice([0, 0, 1])]
    ca = codeaddr(c)
    phook(c, seq, ca, 0, this=True, ret=lambda e: frees.__setitem__(0, frees[0] - 1) or frees[0] + frees[1])
    alloc = obj(c, 0x40, {0x20: stub(c, seq, 1), 0x14: ca, 0: stub(c, seq, 1)})
    c.emu.w32(0x6ff968, alloc)
    tgs = []
    for _ in range(r.randrange(1, 4)):
        n = r.randrange(1, 5)
        arr = rnd(c, 0x404 + 4 * n + 8)   # a slot past the entries: a missing child writes arr[count]
        cap = r.choice([0, 0, 4, r.getrandbits(16)])
        c.emu.w32(arr, cap | (n << 16))
        if r.random() < 0.8:
            c.emu.w32(arr + 0x404 + 4 * r.randrange(0, n), child)
        if n == 1 and cap == 0:
            frees[0] += 1
        g = obj(c, 0x400, {})
        c.emu.w32(g + 0x7b, arr)
        tgs.append(g)
    links = {}
    for k, g in enumerate(tgs):
        nxt = tgs[k + 1] if k + 1 < len(tgs) else 0
        par = rnd(c, 0x10) if (nxt or r.random() < 0.5) else 0
        vt = c.emu.r32(obj(c, 0x400, {0x310: stub(c, seq, 0, ret=r.choice([0, 0, 0, 1, 0x100])),
                                     0x30c: stub(c, seq, 0, ret=r.choice([0, 0, 0, 1])),
                                     0x20: stub(c, seq, 0, ret=par)}))
        c.emu.w32(g, vt)
        if par:
            c.emu.w32(par + 8, (nxt ^ 0x5a000000) if nxt else r.getrandbits(32))
            links[c.emu.r32(par + 8)] = nxt
    phook(c, seq, 0x4db7e0, 0, this=True, ret=lambda e: links.get(e.reg('ecx'), 0))
    return [tgs[0], child]


def _630(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x630dd0, 3)
    phook(c, seq, 0x6302f0, 2)
    s = rnd(c, 0x16b0)
    for k in range(19):
        c.emu.w16(s + 0xa76 + 4 * k, 0 if r.random() < 0.85 else r.getrandbits(16))
    return [s]


S(0x4e7240, 'ZParamParticle::GetPosVel', 'thiscall', None, ret=None, gen=_4e7, note='f16b027; exp stubbed, vector helpers run as exe code')
S(0x443b40, 'ZTreeGroup::RemoveDynamicChildTreeGroup', 'thiscall', None, ret=None, gen=_443, note='f16b027')
S(0x630200, 'build_bl_tree (zlib)', 'cdecl', None, ret='eax', gen=_630, note='f16b027')
