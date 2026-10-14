"""specs_s36038.py - cascade s4 batch 36038: 0x615220 / 0x64d7d0 (pool slot release, record 0x8c / 0x78), 0x5d4660 (create and configure a sub-object), 0x5f5090 (find or create a named child), 0x4055a0 (free a record's buffers)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _pool(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blocks = [rnd(c, 0x20) for _ in range(3)]
    p = rnd(c, 0x20)
    rnd(c, r.randint(0, 0x300))
    b = rnd(c, 0x20)
    if r.random() < 0.5:
        p, b = b, p
    e.wbytes(b, bytes([r.choice([1, 1, 2, 3, 0])]))
    other = blocks[0]
    a = b if r.random() < 0.2 else blocks[1]
    d = b if r.random() < 0.2 else blocks[2]
    e.w32(b + 8, a)
    e.w32(b + 0xc, d)
    head = b if r.random() < 0.3 else other
    e.w32(other + 0xc, blocks[1] if r.random() < 0.5 else blocks[2])
    E = obj(c, 0x20, {0x2c: pystub(c, 1, this=True, ret=b), 0x34: pystub(c, 1, this=True)})
    e.w32(E + 8, head)
    e.w32(E + 0xc, r.getrandbits(32))
    return [E, p]


def _g5d4660(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pat = bytes(r.getrandbits(8) for _ in range(0x24))
    hook_rec(c, 0x4de7a0, 0, this='mark', side=lambda em, k: em.wbytes(em.reg('ecx'), pat))
    sub = rnd(c, 0x20)
    hook_rec(c, 0x4dc630, 2, this=True)
    hook_rec(c, 0x4dbe30, 1, this=True)
    hook_rec(c, 0x4dc440, 1, this=True)
    o = obj(c, 0x20, {0x2c: pystub(c, 0, this=True), 0xbc: pystub(c, 1, this=True), 0x234: pystub(c, 1, this=True),
                      0x23c: pystub(c, 1, this=True), 0x240: pystub(c, 1, this=True)})
    e.w32(o + 8, sub)
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    lst_obj = rnd(c, 0x20)
    e.w32(tab + 0xadc, lst_obj)
    lst = obj(c, 0x20, {0x1bc: pystub(c, 7, this=True, deref={1: 9, 2: 3}, ret=o)})
    s = rnd(c, 0x80)
    e.w32(s + 0x6b, lst if r.random() < 0.8 else 0)
    return [s]


def _g5f5090(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    child = rnd(c, 0x20) if r.random() < 0.5 else 0
    made = obj(c, 0x20, {0x48: pystub(c, 2, this=True)}) if r.random() < 0.7 else 0
    x = rnd(c, 0x20) if r.random() < 0.7 else 0
    calls = []
    t = obj(c, 0x20, {0x38: pystub(c, 3, this=True, ret=lambda em, k: child if k == 0 else made)})
    e.w32(0x724270, t)
    e._image_dirty = True
    hook_rec(c, 0x6000b0, 1, this=True, ret=x)
    owner = rnd(c, 0x20)
    e.w32(owner + 0x96, rnd(c, 0x10))
    s = rnd(c, 0x20)
    e.w32(s + 4, owner)
    return [s, r.getrandbits(32), r.getrandbits(32)]


def _g4055a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634d52, 1, pop=0)
    p = rnd(c, 0x40)
    e.w32(p + 0x30, 0 if r.random() < 0.15 else r.getrandbits(32) | 1)
    e.w32(p + 0x20, 0 if r.random() < 0.3 else rnd(c, 0x10))
    e.w32(p + 8, 0 if r.random() < 0.3 else rnd(c, 0x10))
    if r.random() < 0.7:
        q = rnd(c, 0x20)
        e.w32(p + 0x24, q)
    else:
        e.w32(p + 0x24, 0)
    if r.random() < 0.7:
        q2 = rnd(c, 0x20)
        e.w32(p + 0x28, q2)
    else:
        e.w32(p + 0x28, 0)
    return [p]


S(0x615220, 'GUESS release a pool slot (record 0x8c)', 'thiscall', None, ret=None, gen=_pool, note='batch36038')
S(0x64d7d0, 'GUESS release a pool slot (record 0x78, bit in p[9])', 'thiscall', None, ret=None, gen=_pool, note='batch36038')
S(0x5d4660, 'GUESS create and configure a sub-object', 'thiscall', None, ret=None, gen=_g5d4660, note='batch36038')
S(0x5f5090, 'GUESS find or create a named child', 'thiscall', None, ret='eax', gen=_g5f5090, note='batch36038')
S(0x4055a0, 'GUESS free a record\'s buffers', 'cdecl', None, ret=None, gen=_g4055a0, note='batch36038')
