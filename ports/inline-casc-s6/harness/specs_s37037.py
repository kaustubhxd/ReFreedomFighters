"""specs_s37037.py - cascade s6 batch 37037: 0x4a88c0 (message handler by 16-bit id). Packed fields on this; table slot 0x58 (id -> object with slot 0xbc); object at +0x4e has
slots 0xbc / 0x2c / 0x28; 0x4a93b0 hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4a88c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x4a93b0, 0, this=True)
    ids = r.sample(range(1, 0x1000), 5)
    # sometimes make two ids equal
    if r.random() < 0.15:
        ids[1] = ids[0]
    if r.random() < 0.1:
        ids[2] = ids[1]
    oid = r.randint(1, 0xffff)
    O = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)})
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: O if (em.arg32(0) == oid and r.random() < 0.85) else 0)}, table_size=0x20)
    Q = obj(c, 0x40, {0xbc: pystub(c, 1, this=True), 0x2c: pystub(c, 0, this=True), 0x28: pystub(c, 0, this=True)}) if r.random() < 0.85 else 0
    which = r.choice(range(5))
    if which == 3 and not Q:
        Q = obj(c, 0x40, {0xbc: pystub(c, 1, this=True), 0x2c: pystub(c, 0, this=True), 0x28: pystub(c, 0, this=True)})
    me = rnd(c, 0x100)
    for off, v in zip((0xcf, 0xcd, 0x48, 0x67, 0x89), ids):
        _w(c, me + off, v, 2)
    _w(c, me + 0xc3, oid)
    _w(c, me + 0x4e, Q)
    _w(c, me + 0x4a, r.choice([0, 1, 5]))
    _w(c, me + 0xd2, r.choice([0, 1, 2, 0xffffffff, 3]))
    pbuf = rnd(c, 0x20)
    _w(c, pbuf, r.choice([2, 4, 5, 4, 5, 1, 7]))
    idv = ids[which] | (r.choice([0, 0x10000, 0xabcd0000]) if r.random() < 0.3 else 0)
    if r.random() < 0.08:
        idv = 0x5555
    p = 0 if (which in (1, 2) and r.random() < 0.4) else pbuf
    return [me, idv, p]


S(0x4a88c0, 'GUESS message handler by id', 'thiscall', None, ret='eax', gen=_g4a88c0, note='batch37037')
