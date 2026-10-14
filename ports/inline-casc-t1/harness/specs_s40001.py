"""specs_s40001.py - tier H. 0x5ab970: unaligned pointer/limit at +0x6e/+0x72 (difference around 16), chain [[a+8]+8] to a random object read by the real 0x4db7c0, ret eax. 0x5a0da0: slot 0x114 of the engine table, vtable slot 0x130, hooked 0x5a01e0. 0x52a700: ring buffer with cap/tail/head (never cap 0 or -1), ret al. 0x452e60: engine sys object +0x1aa3 (unaligned) -> object -> [+0x18] with slots 0x8c/0xac (buffer filled by the first slot and compared), self slots 0x238/0x220, float arg F(). 0x4f1b20: engine table slot 0x4c, this+0x1a7 object slots 0x2c/0x98 (float arg compared). 0x4804e0: hooked allocator, float at +0x1c."""
import struct
from pilot import S, EDGE_F, F
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, hook_rec


def _fb(v):
    try:
        return struct.unpack('<I', struct.pack('<f', v))[0]
    except OverflowError:
        return 0x7f800000 if v > 0 else 0xff800000


def _rf(r):
    k = r.random()
    if k < 0.15:
        return _fb(r.choice(EDGE_F))
    if k < 0.2:
        return r.getrandbits(32)
    return _fb(r.uniform(-1000, 1000))


def _g5ab970(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    y = rnd(c, 0x80)
    for off in (0x40, 0x44, 0x48):
        e.w32(y + off, _rf(r))
    if r.random() < 0.3:
        e.w32(y + 0x44, _fb(r.choice([0.0, 1e-3, 1e5, 1e9, 3e9, -3e9, 1e12, 0.5, -0.5])))
    x = rnd(c, 0x20)
    e.w32(x + 8, y)
    a = rnd(c, 0x20)
    e.w32(a + 8, x)
    me = rnd(c, 0x100)
    delta = r.choice([0, 1, 5, 15, 16, 17, 31, 100, -3, -16, r.getrandbits(32)])
    e.wbytes(me + 0x6e, a.to_bytes(4, 'little') + ((a + delta) & 0xffffffff).to_bytes(4, 'little'))
    return [me]


def _g5a0da0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5a01e0, 0, this=True)
    t = obj(c, 0x40, {0x114: pystub(c, 5, ret=r.getrandbits(32), this=True)}, nslots=0x118 // 4)
    sysobj(c, table_slots=None)
    e.w32(e.r32(0x70039c) + 0x9b, t)
    vt = e.alloc(0x140, 4)
    e.w32(vt + 0x130, pystub(c, 2, this=True))
    me = rnd(c, 0xb00)
    e.w32(me, vt)
    n = r.choice([0, 0, 1, 2, 3, 7, 0x10, 0x20, r.randrange(0, 0x20)])
    e.wbytes(me + 0x7ce, n.to_bytes(4, 'little'))
    return [me]


def _g52a700(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cap = r.choice([1, 2, 3, 5, 8])
    buf = rnd(c, 8 * 0x32 + 16)
    head = r.randrange(0, cap)
    tail = (head + 1) % cap if r.random() < 0.4 else r.randrange(0, cap)
    me = rnd(c, 0x20)
    e.w32(me, buf)
    e.w32(me + 4, cap)
    e.w32(me + 8, tail)
    e.w32(me + 0xc, head)
    return [me, rnd(c, 0x40)]


def _g452e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(em, k):
        buf = em.arg32(1)
        em.wbytes(buf, bytes((k * 37 + i * 11 + 5) & 0xff for i in range(0x1c)))
    s8c = pystub(c, 2, this=True, deref={1: 7}, side=fill)
    sacc = pystub(c, 2, this=True, deref={1: 7})
    q = obj(c, 0x20, {0x8c: s8c, 0xac: sacc}, nslots=0xb0 // 4)
    mid = rnd(c, 0x40)
    e.w32(mid + 0x18, q)
    so = sysobj(c)
    e.wbytes(so + 0x1aa3, mid.to_bytes(4, 'little'))
    sub = rnd(c, 0x80)
    me = obj(c, 0x20, {0x238: pystub(c, 0, this=True), 0x220: pystub(c, 1, this=True)}, nslots=0x240 // 4)
    e.w32(me + 8, sub)
    return [me, F(struct.unpack('<f', struct.pack('<I', _rf(r)))[0])]


def _g4f1b20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = obj(c, 0x40, {0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x50 // 4)
    so = sysobj(c)
    e.w32(so + 0x9b, t)
    vt = e.alloc(0xa0, 4)
    e.w32(vt + 0x2c, pystub(c, 1, ret=r.choice([0, 0, 1, r.getrandbits(32)]), this=True))
    e.w32(vt + 0x98, pystub(c, 3, this=True))
    me = rnd(c, 0x200)
    e.wbytes(me + 0x1a7, vt.to_bytes(4, 'little'))
    p = rnd(c, 0x60)
    e.w32(p + 0x4c, r.choice([0, 1, -1 & 0xffffffff, 100, 0x80000000, 0x7fffffff, r.getrandbits(32)]))
    return [me, p]


def _g4804e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a, b = rnd(c, 0x10), rnd(c, 0x50)
    seq = [a, b]
    hook_rec(c, 0x41e290, 1, ret=lambda em, k: seq[min(k, 1)], pop=0)
    me = rnd(c, 0xa0)
    e.w32(me + 0x1c, _rf(r))
    return [me]


S(0x5ab970, 'GUESS scaled value of a range head', 'thiscall', None, ret='eax', gen=_g5ab970, note='batch40001')
S(0x5a0da0, 'GUESS apply selected entry', 'thiscall', None, ret=None, gen=_g5a0da0, note='batch40001')
S(0x52a700, 'GUESS ring buffer push', 'thiscall', None, ret='al', gen=_g52a700, note='batch40001')
S(0x452e60, 'GUESS update entry field', 'thiscall', None, ret=None, gen=_g452e60, note='batch40001')
S(0x4f1b20, 'GUESS conditional negated adjust', 'thiscall', None, ret=None, gen=_g4f1b20, note='batch40001')
S(0x4804e0, 'GUESS build default record', 'thiscall', None, ret=None, gen=_g4804e0, note='batch40001')
