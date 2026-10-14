"""specs_s36034.py - cascade s4 batch 36034: 0x575800, 0x576260 (twin of 0x575160), 0x5f07a0, 0x5fe240 / 0x5fe300 (tree node insert with 6/8-byte keys)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger
import specs_s36033 as _p


def _g575800(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    v = rnd(c, 0x10)
    e.w32(v + 4, 0 if r.random() < 0.3 else rnd(c, 0x10))
    w = obj(c, 0x20, {0x2f0: pystub(c, 0, this=True, ret=v), 0x2f8: pystub(c, 1, this=True)})
    ed = obj(c, 0x20, {0x12c: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, ret=lambda em, n: r.getrandbits(32) if False else (0x12345678 * (n + 3)) & 0xffffffff)})
    s = obj(c, 0x260, {0x84: pystub(c, 0, this=True, ret=w)})
    e.w32(s + 0x44, ed)
    if r.random() < 0.85:
        e.w32(s + 0x224 + 0x24 * r.randint(0, 4), v)
    return [s]


def _g576260(c):
    return _p._g575160(c)


def _g5f07a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vt = e.alloc(8, 4)
    e.w32(vt + 4, pystub(c, 2, this=True))
    s = rnd(c, 0x90)
    for i in range(0x1c):
        o = rnd(c, 0x20)
        e.w32(o, vt)
        e.w32(s + 4 + 4 * i, o)
    k0 = r.choice([0, 0, 1, 2, 3])
    m = r.choice([0, 1, 2, 3, 5, 12, 28, 40])
    A = e.alloc(12 * 0x30, 4)
    for i in range(0x30):
        e.w32(A + 12 * i, r.choice([0, 1, 2, 2, 1, 0, 3, 7]))
        e.w32(A + 12 * i + 4, r.getrandbits(32))
        e.w32(A + 12 * i + 8, r.getrandbits(32))
    e.w32(s + 0x7c, A)
    e.w32(s + 0x88, k0)
    e.w32(s + 0x80, A + 12 * (k0 + m) if r.random() < 0.9 else A + 12 * 0x2f)
    vals = [r.choice([0, 1, 2, 7, 100, 0xffffffff, r.getrandbits(32)]) for _ in range(8)]
    hook_rec(c, 0x5ac940, 1, this=True)
    hook_rec(c, 0x5ab9d0, 0, this=True, ret=lambda em, n, _v=vals: _v[n % 8])
    hook_rec(c, 0x5ac620, 2, this=True)
    return [s, r.getrandbits(32), r.getrandbits(32)]


def _tree(c, keylen):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    head = rnd(c, 0x20)
    other = rnd(c, 0x20)
    T = rnd(c, 0x10)
    e.w32(T, head)
    parent = head if r.random() < 0.3 else other
    key = rnd(c, 8)
    pk = rnd(c, 8)
    mode = r.choice(['lt', 'eq', 'gt', 'hi', 'lo'])
    if keylen == 2:
        kv = int.from_bytes(e.rbytes(key, 2), 'little')
        pv = {'lt': kv + 1, 'eq': kv, 'gt': kv - 1, 'hi': 0x8000, 'lo': 1}[mode] & 0xffff
        if mode == 'hi':
            e.wbytes(key, (0x7fff).to_bytes(2, 'little'))
        e.wbytes(parent + 0xd, pv.to_bytes(2, 'little'))
    else:
        kv = int.from_bytes(e.rbytes(key, 4), 'little')
        pv = {'lt': kv + 1, 'eq': kv, 'gt': kv - 1, 'hi': 0x80000000, 'lo': 1}[mode] & 0xffffffff
        if mode == 'hi':
            e.wbytes(key, (0x7fffffff).to_bytes(4, 'little'))
        e.wbytes(parent + 0xd, pv.to_bytes(4, 'little'))
    if r.random() < 0.4:
        e.w32(head + 9, parent)
    if r.random() < 0.4:
        e.w32(head + 5, parent)
    e.w32(T + 4, r.getrandbits(32))
    out = e.alloc(8, 4)
    e.hook(0x6014a0, lambda em, rr: (em.calllog.append(('alloc', 0, None, (em.arg32(0),))), em.ret(eax=rnd(c, max(em.arg32(0), 16)), argbytes=4)))

    def reb(em, rr):
        em.calllog.append(('rebalance', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=0, argbytes=0)
    e.hook(0x430480, reb)
    return [T, out, 0 if r.random() < 0.75 else r.getrandbits(32), parent, key]


def _g5fe240(c):
    return _tree(c, 2)


def _g5fe300(c):
    return _tree(c, 4)


S(0x575800, 'GUESS lookup an entry and send two lines', 'thiscall', None, ret='al', gen=_g575800, note='batch36034')
S(0x576260, 'GUESS name compare then log call (twin of 0x575160)', 'thiscall', None, ret=None, gen=_g576260, note='batch36034')
S(0x5f07a0, 'GUESS lay out widgets from entries', 'thiscall', None, ret=None, gen=_g5f07a0, note='batch36034')
S(0x5fe240, 'GUESS tree node insert with a 6-byte key', 'thiscall', None, ret=None, gen=_g5fe240, note='batch36034')
S(0x5fe300, 'GUESS tree node insert with an 8-byte key', 'thiscall', None, ret=None, gen=_g5fe300, note='batch36034')
