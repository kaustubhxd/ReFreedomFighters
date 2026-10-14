"""specs_s36021.py - cascade s4 batch 36021: 0x487490 (register two ids), 0x497210 (match a slot entry), 0x4e1070 (read a string from a packed buffer), 0x50e7f0 and 0x50f120 (bind records to engine objects)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _assert(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g487490(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0x130: pystub(c, 2, this=True)})
    s = obj(c, 0x20, {8: pystub(c, 0, this=True, ret=o)})
    e.wbytes(s + 0xa, bytes([r.choice([0, 1, 0xff]), r.choice([0, 1, 0xff])]))
    rets = [r.getrandbits(32) for _ in range(2)]
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, ret=lambda em, k: rets[min(k, 1)]),
                           0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    E = rnd(c, 0x20)
    return [E, s]


def _g497210(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 4)
    key = r.getrandbits(32)
    e.w32(0x6ffa9c, key)
    ents = e.alloc(0x60, 4)
    for i in range(8):
        e.w32(ents + 4 * i, r.getrandbits(32))
    tbl = e.alloc(0x100, 4)
    for i in range(0x20):
        e.w32(tbl + 4 * i, r.getrandbits(32))
    k = r.choice([0, 1, 2, 3])
    for j in range(3):
        _w32(c, ents + 12 * j + 4, r.randint(0, 6))
        _w32(c, ents + 12 * j + 8, r.choice([0, 1, 2, 3, 4]))
    if k:
        first = e.r32(ents + 12 * (k - 1) + 4)
        cnt = e.r32(ents + 12 * (k - 1) + 8)
        if cnt and r.random() < 0.6:
            e.w32(tbl + 8 * (first + r.randrange(cnt)), key)
    p = rnd(c, 0x80)
    e.wbytes(p + 0x59, bytes([k]))
    E = obj(c, 0x80, {0x18: pystub(c, 1, this=True)})
    e.w32(E + 0x40, ents)
    e.w32(E + 0x44, tbl)
    return [E, p]


def _g4e1070(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    hook_rec(c, 0x4e1590, 0, this=True, ret=r.randint(0, 9))

    def l24(em, rr):
        em.calllog.append(('log24', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    e.w32(0x700390, obj(c, 0x40, {0x24: e.stub_fn('log24', l24)}))
    p = e.alloc(0x60, 4)
    t = r.choice([0xff, 4, 5, 0x44, 0x45, 0x85, 0xc4, 0x3f, 0, 6, 0x25, 0x24, 0x65, 0x64, 0x1f])
    s = bytes(r.randint(1, 255) for _ in range(r.choice([0, 1, 5, 20]))) + b'\0'
    e.wbytes(p, bytes([t]) + s + bytes(r.getrandbits(8) for _ in range(4)))
    E = rnd(c, 0x20)
    e.w32(E + 8, p)
    buf = rnd(c, 0x60)
    return [E, buf]


def _bind(c, with_name, assert_path):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    logger(c, 3)
    rec1 = rnd(c, 0x10)
    rec2 = rnd(c, 0x10)
    e.wbytes(rec2 + 4, bytes([r.choice([0, 1, 2, 4, 5, 0xff])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (rec1, rec2)[min(k, 1)])
    hook_rec(c, 0x5002f0, 1, this=True)
    return rec1, rec2


def _g50f120(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    logger(c, 3)
    rec1 = rnd(c, 0x10)
    rec2 = rnd(c, 0x10)
    e.wbytes(rec2 + 4, bytes([r.choice([0, 1, 2, 4, 5, 0xff])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (rec1, rec2)[min(k, 1)])
    hook_rec(c, 0x5002f0, 1, this=True)
    x = r.getrandbits(32)
    o = 0 if r.random() < 0.25 else obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=x)})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=o), 0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    return [rnd(c, 0x20)]


def _g50e7f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec1 = rnd(c, 0x10)
    rec2 = e.alloc(0x10, 4)
    k = r.choice([0, 4, 4, 1, 7])
    e.wbytes(rec2, bytes(r.getrandbits(8) for _ in range(8)))
    old = obj(c, 0x20, {0x28: pystub(c, 0, this=True)})
    e.w32(rec2, old)
    e.wbytes(rec2 + 4, bytes([k]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k2: (rec1, rec2)[min(k2, 1)])
    sret = r.getrandbits(32) | 1
    s = obj(c, 0x20, {0x30: pystub(c, 1, this=True), 0x24: pystub(c, 0, this=True, ret=sret), 0x28: pystub(c, 0, this=True)})
    cc = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=s)})
    nm = 0 if r.random() < 0.4 else rnd(c, 0x10)
    q = obj(c, 0x20, {})
    e.w32(q + 4, nm)
    qq = 0 if r.random() < 0.3 else q
    ob = 0 if r.random() < 0.2 else obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=qq)})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=ob)})
    a = rnd(c, 0x20)
    e.w32(a + 0xc, cc)
    return [a]


S(0x487490, 'GUESS register two ids with the engine', 'thiscall', None, ret=None, gen=_g487490, note='batch36021')
S(0x497210, 'GUESS match slot entry and release', 'thiscall', None, ret=None, gen=_g497210, note='batch36021')
S(0x4e1070, 'GUESS read string from packed buffer', 'thiscall', None, ret=None, gen=_g4e1070, note='batch36021')
S(0x50e7f0, 'GUESS bind record to name and object', 'stdcall', None, ret=None, gen=_g50e7f0, note='batch36021')
S(0x50f120, 'GUESS bind record to engine id', 'stdcall', None, ret=None, gen=_g50f120, note='batch36021')
