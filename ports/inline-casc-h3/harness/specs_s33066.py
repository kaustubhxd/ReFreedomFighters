"""specs_s33066.py - h3 (Sonnet) batch 33066."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _logsetup(c, slot):
    r = c.rng
    e = c.emu
    slog = pystub(c, 3, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {slot: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _assert(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g461a00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('i', k)), ret=lambda em, k: r.choice([0, 0, 0, 1, 0x100, 0x101, _w(c)]))
    me = obj(c, 0x40, {0x324: s})
    e.w32(me + 0x20, r.choice([0, 1, 2, 3, 5]))
    return [me]


def _g4901a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logsetup(c, 0x30)
    n = r.choice([0, 1, 2, 3, 4])
    nodes = [rnd(c, 0x40) for _ in range(n)]
    a = _w(c)
    tgt = r.randrange(0, n) if n else -1
    for i, nd in enumerate(nodes):
        e.w32(nd + 4, r.choice([0, 0, 1]))
        e.w32(nd + 0x23, a if (i == tgt and r.random() < 0.8) else _w(c))
        e.w32(nd + 0x14, nodes[i + 1] if i + 1 < n else 0)
    e.w32(0x7003bc, nodes[0] if n else 0)
    return [a]


def _g4c54d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4c5770, 1, this=True, side=lambda em, k: em.calllog.append(('f', em.rbytes(me + 0x52, 1)[0])))
    me = rnd(c, 0x80)
    ids = [r.getrandbits(16) for _ in range(3)]
    for off, v in zip((0x4c, 0x4e, 0x50), ids):
        e.wbytes(me + off, v.to_bytes(2, 'little'))
    e.wbytes(me + 0x52, bytes([r.choice([0, 1, 5])]))
    a = r.choice(ids + [r.getrandbits(32)]) | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    return [me, a, _w(c)]


def _g55ca30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (lambda p: (e.w32(p, r.choice([0, 1, _w(c)])), p)[1])(rnd(c, 0x10)))
    hook_rec(c, 0x5a2e20, 4, this=True, ret=lambda em, k: _w(c))
    me = rnd(c, 0x40)
    a = rnd(c, 0x20)
    return [me, a]


def _g56fe40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    s0 = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    e.w32(tab + 0xae4, obj(c, 0x40, {0: s0}))
    hook_rec(c, 0x563620, 2, this=True, ret=lambda em, k: _w(c))
    me = _zeroed(c, 0x4c0, 0x100)
    e.w32(me + 0x199, _w(c))
    e.w32(me + 0x19d, _w(c))
    e.w32(me + 0x4b6, r.choice([0, 1, 2, 3, 4, 5, _w(c)]))
    return [me]


def _g5e02e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x591f00, 0, this=True, ret=lambda em, k: p)
    s2e8 = pystub(c, 0, this=True)
    p = obj(c, 0x300, {0x2e8: s2e8})
    hook_rec(c, 0x4614d0, 3, this=True, ret=lambda em, k: _w(c))
    s230 = pystub(c, 2, this=True, ret=lambda em, k: rnd(c, 0x20))
    s0c = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    o = obj(c, 0x300, {0x230: s230})
    me = obj(c, 0x40, {0xc: s0c})
    e.w32(me + 8, o)
    e.w32(me + 0x10, r.choice([0, _w(c), _w(c)]))
    return [me]


def _g5f4e00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logsetup(c, 0x2c)
    _assert(c)
    me = rnd(c, 0x20)
    e.wbytes(me + 4, bytes([r.choice([1, 1, 1, 0, 2, 0xff])]))
    a = rnd(c, 8)
    return [me, a]


def _g64fd10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logsetup(c, 0x2c)
    s20 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    y = obj(c, 0x80, {0x20: s20})
    me = rnd(c, 0x80)
    e.w32(me + 0x2c, r.choice([0, _w(c)]))
    e.w32(me + 0x68, r.choice([0, y, y]))
    return [me, _w(c)]


S(0x461a00, 'GUESS scan indices with vcall 324', 'thiscall', None, ret='al', gen=_g461a00, note='batch33066')
S(0x4901a0, 'GUESS find node by key or log', 'stdcall', None, ret='eax', gen=_g4901a0, note='batch33066')
S(0x4c54d0, 'GUESS id match toggles flag', 'thiscall', None, ret='eax', gen=_g4c54d0, note='batch33066')
S(0x55ca30, 'GUESS two lookups then 5a2e20', 'thiscall', None, ret='eax', gen=_g55ca30, note='batch33066')
S(0x56fe40, 'GUESS select string and lookup', 'thiscall', None, ret='eax', gen=_g56fe40, note='batch33066')
S(0x5e02e0, 'GUESS vcall chain then 4614d0 or tail', 'thiscall', None, ret='eax', gen=_g5e02e0, note='batch33066')
S(0x5f4e00, 'GUESS multiply field or log assert', 'thiscall', None, ret='eax', gen=_g5f4e00, note='batch33066')
S(0x64fd10, 'GUESS add base or tail or log', 'thiscall', None, ret='eax', gen=_g64fd10, note='batch33066')
