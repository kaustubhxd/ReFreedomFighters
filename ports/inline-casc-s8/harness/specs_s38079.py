"""specs_s38079.py - cascade s8 batch 38079. thiscall(other) ret 4; this / other = 0x80-byte random objects (this[0] vtable is overwritten by the 0x24-byte copy). Owner link this[0x54] (nullable -> [0xc] -> flag dword at +0x23
with the 0x800000 / 0xa00000 bits random), this[0x50] node (flag dword at +0x3c, link +0x54 -> [8], word +0x5c), other[0x54] (nullable). Engine system object: +0x190f notice object (slot 0x190), table slots 0x178 (al random),
+8 -> object (slot 0x4c), +0x5d35 -> object (slot 0x24), +0x5d31 -> object (slot 0). All ten callees are hooks (0x4daff0 returns 0 or an object with slot 0x320); the tail slot 0x1d0 of this[0x54] logs its argument.
ret=None: the original's return value is only defined on the tail-call path."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4da440(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lslot(name, nargs, retf=lambda: 0):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx') != 0) + tuple(em.arg32(i) for i in range(nargs)))
            em.ret(eax=retf(), argbytes=4 * nargs)
        return e.stub_fn(name, h)
    NT = obj(c, 0x20, {0x190: lslot('notice', 2)})
    X = obj(c, 0x20, {0x4c: lslot('x4c', 0, lambda: 0x5000000 + 0x100 * r.randrange(8))})
    O24 = obj(c, 0x20, {0x24: lslot('o24', 1, lambda: r.getrandbits(32))})
    O0 = obj(c, 0x20, {0x0: lslot('o0', 1)})
    so = sysobj(c, table_size=0x5e00, table_slots={0x178: lslot('s178', 0, lambda: r.choice([0, 0, 1]))})
    tbl = e.r32(so + 0x9b)
    e.wbytes(so + 0x190f, struct.pack('<I', NT))
    e.w32(tbl + 8, X)
    e.wbytes(tbl + 0x5d35, struct.pack('<I', O24 if r.random() > 0.15 else 0))
    e.wbytes(tbl + 0x5d31, struct.pack('<I', O0))
    flagsets = [0, 0x800000, 0xa00000, 0x200000, 0x800000 | r.getrandbits(8), 0xa00000 | r.getrandbits(8)]

    def mkowner():
        if r.random() < 0.2:
            return 0
        q = rnd(c, 0x40)
        e.wbytes(q + 0x23, struct.pack('<I', r.choice(flagsets)))
        o = obj(c, 0x20, {0x1d0: lslot('tail', 1)})
        e.w32(o + 0xc, q)
        return o

    def mknode():
        n = rnd(c, 0x70)
        e.w32(n + 0x3c, r.choice([0, 0x40000, 0x40000000, 0x40040000, 0x40000000, r.getrandbits(32)]))
        blk = rnd(c, 0x10)
        e.w32(n + 0x54, blk)
        e.wbytes(n + 0x5c, struct.pack('<H', r.choice([0, 1, 3, 7])))
        return n, blk
    this = rnd(c, 0x80)
    other = rnd(c, 0x80)
    node, blk = mknode()
    R = obj(c, 0x20, {0x320: lslot('r320', 1)})
    for o in (this, other):
        e.w32(o + 0x3c, r.getrandbits(32))
        e.w32(o + 0x6c, r.choice([0, 0, r.getrandbits(32)]))
        e.w32(o + 0x68, r.choice([0, 0, r.getrandbits(32)]))
    e.wbytes(this + 0x5a, struct.pack('<H', r.choice([0, 1, 5])))
    e.w32(this + 0x64, r.choice([0, 1, 7]))
    e.w32(this + 0x50, node)
    ow = mkowner()
    e.w32(this + 0x54, ow)
    e.w32(other + 0x54, r.choice([0, rnd(c, 0x20), rnd(c, 0x20)]))
    if r.random() < 0.5:
        e.w32(other + 0x3c, e.r32(other + 0x3c) | 0x800 | 0x40000)
    if r.random() < 0.3:
        e.w32(this + 0x3c, e.r32(this + 0x3c) | 0x40000 | 0x1)
    hook_rec(c, 0x4dc630, 2, this=True, pop=8)
    hook_rec(c, 0x4da3c0, 1, this=True, pop=4)
    hook_rec(c, 0x4da770, 1, this=True, pop=4)
    hook_rec(c, 0x4dae60, 0, this=True, pop=0)
    hook_rec(c, 0x4daff0, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, R]))
    hook_rec(c, 0x4dbe30, 1, this=True, pop=4)
    hook_rec(c, 0x4dc030, 0, this=True, pop=0)
    hook_rec(c, 0x4dc440, 1, this=True, pop=4)
    hook_rec(c, 0x4dc970, 1, this=True, pop=4)
    return [this, other]


S(0x4da440, 'GUESS copy widget state and resync', 'thiscall', None, ret=None, gen=_g4da440, note='batch38079')
