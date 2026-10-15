"""specs_s43004.py - t4 (Sonnet) batch 43004. 0x484ff0: 0x443ef0 runs for real, slots 0x20 / 0x7c are stubs (out vector recorded);
0x48f7e0: 0x494b40 / 0x494ac0 hooked; 0x4ef130: 0x4cc7f0 (regs ecx, edx) and 0x43e0f0 hooked, slots 0x178 / 0x6c / 0x244 stubs."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r):
    k = r.random()
    if k < 0.06:
        return r.choice([0.0, -0.0, float('nan'), float('inf'), float('-inf')])
    if k < 0.2:
        return r.uniform(-1e5, 1e5)
    return r.uniform(-20, 20)


def _g484ff0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s7c = pystub(c, 2, this=True, deref={1: 3})
    eng = obj(c, 0x40, {0x7c: s7c})
    me = obj(c, 0x480, {0x20: pystub(c, 0, ret=eng, this=True)})
    e.w32(me + 0x451, _fb(_fl(r)))
    a = rnd(c, 0x40)
    b = rnd(c, 0x20)
    for i in range(3):
        e.w32(a + 0xc + 4 * i, _fb(_fl(r)))
        e.w32(b + 4 * i, _fb(_fl(r)))
    return [me, a, b]


def _g48f7e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = struct.unpack('<f', e.rbytes(0x680a60, 4))[0]
    me = rnd(c, 0x40)
    e.w32(me + 0x10, _fb(r.choice([k, k, _fl(r), float('nan')])))
    hook_rec(c, 0x494b40, 1, this=True)
    hook_rec(c, 0x494ac0, 1, this=True)
    a = obj(c, 0x40, {0x5c: pystub(c, 3, this=True), 0x14: pystub(c, 0, ret=_w(c), this=True)})
    return [me, a]


def _g4ef130(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sub = obj(c, 0x20, {0x178: pystub(c, 0, ret=_w(c) | 1, this=True)})
    so = sysobj(c)
    e.w32(so + 0x190f, sub)
    found = r.choice([0, 0, 1, _w(c)])

    def edx(em, k):
        em.calllog.append(('edx', em.reg('edx')))
    hook_rec(c, 0x4cc7f0, 0, this=True, ret=found, pop=0, side=edx)
    hook_rec(c, 0x43e0f0, 0, this=True)
    e.w8(0x700e20, r.getrandbits(8)) if hasattr(e, 'w8') else e.wbytes(0x700e20, bytes([r.getrandbits(8)]))
    me = obj(c, 0x40, {0x6c: pystub(c, 1, this=True, deref={0: 9}), 0x244: pystub(c, 0, this=True)})
    return [me]


S(0x484ff0, 'GUESS offset point by negated scale then slot 0x7c', 'thiscall', None, ret=None, gen=_g484ff0, note='batch43004')
S(0x48f7e0, 'GUESS timer restart if value set then slot 0x5c', 'thiscall', None, ret=None, gen=_g48f7e0, note='batch43004')
S(0x4ef130, 'GUESS set flag from string find then default block slot 0x6c', 'thiscall', None, ret=None, gen=_g4ef130, note='batch43004')
