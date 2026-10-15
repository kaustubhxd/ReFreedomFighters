"""specs_f1105.py - fresh-11 batch 5: slice-11 functions of 119 to 131 bytes."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from h11 import L, obj, rbuf, fbuf, patch


def r32(c): return c.rng.getrandbits(32)


def set_eng9b(c, o9b):
    eng = rbuf(c, 0x200)
    c.emu.w32(eng + 0x9b, o9b)
    c.emu.w32(0x70039c, eng)


def g_factory(hooks):
    def g(c):
        p = rbuf(c, 0x200)
        pool = obj(c, 'pool', {0x44: L('alloc', 1, ret=c.rng.choice([0, p, p]))})
        e = rbuf(c, 0x20)
        c.emu.w32(e + 8, pool)
        set_eng9b(c, e)
        for h in hooks:
            patch(c, h, L('ctor_%x' % h, 0, ret=r32(c)))
        return [r32(c)]
    return g
for a, vt in ((0x5bca30, 0x6aaf64), (0x5c5b30, 0x6b431c), (0x5c7bb0, 0x6b47b0), (0x5d6a70, 0x6b5ae4)):
    S(a, 'GUESS factory (0x469870, vtable 0x%x)' % vt, 'thiscall', None, ret='eax', gen=g_factory([0x469870]))
S(0x4b2ef0, 'GUESS factory (0x469870, vtable 0x691590, +0x50)', 'thiscall', None, ret='eax', gen=g_factory([0x469870]))
S(0x5bd2f0, 'GUESS factory (0x469870, vtable 0x6aafec, REFTAB32 +0x4c)', 'thiscall', None, ret='eax',
  gen=g_factory([0x469870, 0x4ccba0]))
S(0x5659b0, 'GUESS factory (0x564460, vtable 0x6a6b00)', 'thiscall', None, ret='eax', gen=g_factory([0x564460]))


def g_60feb0(c):
    d = obj(c, 'dev', {0xfc: L('SetStageState', 4, ret=r32(c), ecx=False)})
    c.emu.w32(0x724a00, d)
    s = c.rng.randint(0, 7)
    vals = [r32(c) for _ in range(3)]
    for k, base in enumerate((0x7248c8, 0x7248e8, 0x724908)):
        c.emu.w32(base + 4 * s, vals[k] if c.rng.random() < 0.4 else r32(c))
    return [s, vals[0], vals[1], vals[2]]
S(0x60feb0, 'GUESS set stage states 4/5/6 (cached)', 'fastcall', None, ret=None, gen=g_60feb0)


def g_4c6770(c):
    patch(c, 0x4c65a0, L('body', 0, ret=r32(c)))
    patch(c, 0x4690b0, L('lort', 2, pop=0, ret=r32(c), ecx=False))
    c.emu.w32(0x7003b0, c.emu.stub_fn('cb', L('cb7003b0', 0, ret=r32(c), ecx=False)))
    return [rbuf(c, 0x80), c.rng.choice([0, 1, 4, 5, r32(c)])]
S(0x4c6770, 'ZPreviewCamera::~ZPreviewCamera (deleting)', 'thiscall', None, ret='eax', gen=g_4c6770)


def g_63d270(c):
    patch(c, 0x64c8d0, L('ViewBase::Init', 0, ret=r32(c)))
    c.emu.w32(0x7003b0, c.emu.stub_fn('cb', L('cb7003b0', 0, ret=r32(c), ecx=False)))
    v = fbuf(c, 0x10060)
    c.emu.w32(v + 0x10055, c.rng.randint(0, 0x1f))
    o = obj(c, 'draw', {0x60: L('vt60', 0, ret=r32(c)), 0x7c: L('CreateViewImpl', 3, ret=v)}, size=0x180)
    free = c.rng.choice([0, 3, 0x1f, 0x20])
    for i in range(0x20):
        c.emu.w32(o + 0x6c + 4 * i, 0 if i == free else (r32(c) | 1))
    c.emu.wbytes(o + 5, bytes([c.rng.choice([0, 1])]))
    c.emu.w32(o + 0xec, c.rng.choice([0, 5, 0x1f, 0x20]))
    return [o, r32(c), r32(c)]
S(0x63d270, 'ZDrawBase::CreateView', 'thiscall', None, ret='eax', gen=g_63d270)


def g_48b530(c):
    patch(c, 0x4920e0, L('LinkBefore', 2, ret=r32(c)))
    o = rbuf(c, 0xa10)
    n = c.rng.randint(0, 20)
    c.emu.w32(o + 0xa0c, n)
    c.emu.w32(o + 0xa08, c.rng.choice([n, n + 1, n + 5, 0]))
    prio = c.rng.randint(-50, 50) & 0xffffffff
    nodes = []
    for _ in range(c.rng.randint(0, 5)):
        nd = rbuf(c, 0x14)
        c.emu.w32(nd + 8, 0 if c.rng.random() < 0.8 else 1)
        c.emu.w32(nd + 4, c.rng.choice([c.rng.randint(-50, 50) & 0xffffffff, prio]))
        nodes.append(nd)
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 0x10, nodes[i + 1] if i + 1 < len(nodes) else 0)
    c.emu.w32(o + 0xa04, nodes[0] if nodes else 0)
    return [o, r32(c), prio]
S(0x48b530, 'ZTimeUpdateList::AddSort', 'thiscall', None, ret='eax', gen=g_48b530)
