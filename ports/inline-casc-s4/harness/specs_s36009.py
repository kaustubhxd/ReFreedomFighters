"""specs_s36009.py - cascade s4 batch 36009: 0x49dfd0 (join two path strings, slot 4), 0x4a4e80 and 0x4c96f0 (read fields from a stream through typed slots)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _cstr(c, n, pool=b'abXY/._-'):
    r = c.rng
    a = c.emu.alloc(n + 8, 4)
    c.emu.wbytes(a, bytes(r.choice(pool) for _ in range(n)) + b'\0' + bytes(r.getrandbits(8) for _ in range(7)))
    return a


def _g49dfd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ret = r.choice([0, 0, 1, 0x1234567])

    def sh(em, res):
        p = em.arg32(0)
        s = b''
        while True:
            ch = em.rbytes(p, 1)
            if ch == b'\0':
                break
            s += ch
            p += 1
        em.calllog.append(('slot4', s))
        em.ret(eax=ret, argbytes=4)
    me = obj(c, 0x20, {4: e.stub_fn('slot4', sh)})
    la = r.choice([0, 0, 1, 5, r.randint(0, 0x60)])
    lb = r.choice([0, 0, 1, 5, r.randint(0, 0x60)])
    return [me, _cstr(c, la), _cstr(c, lb)]


def _mk(c, sizes):
    r = c.rng
    slots = {}
    for off, n in sizes.items():
        def side(em, k, n=n):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(n)))
        slots[off] = pystub(c, 1, this=True, side=side)
    return obj(c, 0x20, slots)


def _gstream(sizes):
    def g(c):
        clear_hooks(c)
        me = rnd(c, 0x90)
        return [me, _mk(c, sizes)]
    return g


S(0x49dfd0, 'GUESS join path strings, resolve via slot 4', 'thiscall', None, ret='eax', gen=_g49dfd0, note='batch36009')
S(0x4a4e80, 'GUESS read fields from stream (A)', 'thiscall', None, ret='al', gen=_gstream({0x44: 2, 0x68: 1, 0x58: 4, 0x50: 4}), note='batch36009')
S(0x4c96f0, 'GUESS read fields from stream (B)', 'thiscall', None, ret='al', gen=_gstream({0x44: 2, 0x68: 1, 0x58: 4, 0x6c: 12}), note='batch36009')


def _g4f2b30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    from recruits_util import sysobj
    q = 0 if r.random() < 0.3 else r.getrandbits(32) | 1
    p = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x80])), 0x318: pystub(c, 1, this=True, ret=q)})
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    me = obj(c, 0x80, {0x2dc: pystub(c, 4, this=True), 0x2ec: pystub(c, 1, this=True)})
    e.w32(me + 0x64, p)
    a = p if r.random() < 0.75 else rnd(c, 0x10)
    return [me, a, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x4f2b30, 'GUESS detach current child and notify', 'thiscall', None, ret=None, gen=_g4f2b30, note='batch36009')


def _g4f8ff0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4fa350, 1, this=True)
    y = obj(c, 0x20, {0x328: pystub(c, 0, this=True), 0x34c: pystub(c, 5, this=True)})
    me = obj(c, 0x200, {0x110: pystub(c, 2, this=True), 0x2c4: pystub(c, 0, this=True, ret=y), 0x364: pystub(c, 1, this=True)})
    o = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)})
    e.wbytes(me + 0x1bf, o.to_bytes(4, 'little'))
    p = rnd(c, 0xb0)
    sv = 0 if r.random() < 0.25 else _cstr(c, r.choice([0, 1, 7, r.randint(0, 40)]))
    e.wbytes(p + 0x97, sv.to_bytes(4, 'little'))
    e.wbytes(me + 0x1bb, (0 if r.random() < 0.2 else p).to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


S(0x4f8ff0, 'GUESS reset view and request resize', 'thiscall', None, ret='al', gen=_g4f8ff0, note='batch36009')
