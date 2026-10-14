"""specs_s37001.py - cascade s6 batch 37001: 0x4dc2b0 (serialise an entry into a stream). Stream slot 0x10 recorded (ptr, size, first dword); owner slot 0x10 returns a random EAX
(only AL counts); manager at [[0x70039c]+0x9b]+8 has slots 0x5c (lookup by id) and 0x4c (base pointer)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4dc2b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    so = sysobj(c, table_size=0x40)
    tab = e.r32(so + 0x9b)
    ent = rnd(c, 0x30)
    e.wbytes(ent + 0x1c, bytes([r.choice([0, 1, 7])]))
    e.w32(ent, 0 if r.random() < 0.2 else rnd(c, 0x20))
    q = e.r32(ent)
    base = r.getrandbits(32)
    if q:
        e.w32(q + 8, (base + 0x70 * r.choice([0, 1, 5, 0x7fff, 0x12345, -3 & 0xffffffff]) + r.choice([0, 1, 0x6f])) & 0xffffffff)
    rv = (ent if r.random() < 0.85 else 0)
    mgr = obj(c, 0x20, {0x5c: pystub(c, 1, this=True, ret=rv), 0x4c: pystub(c, 0, this=True, ret=base)})
    e.w32(tab + 8, mgr)
    me = rnd(c, 0x80)
    if r.random() < 0.8:
        e.w32(me + 0x3c, e.r32(me + 0x3c) | r.choice([0x100000, 0x40000, 0x140000, 0x20000000, 0xffffffff]))
    else:
        e.w32(me + 0x3c, e.r32(me + 0x3c) & 0xfffbffff)
    if r.random() < 0.25:
        e.wbytes(me + 0x5c, bytes(2))
    if r.random() < 0.15:
        e.w32(me + 0x54, 0)
    else:
        nodes = [rnd(c, 0x30) for _ in range(r.choice([1, 2, 3]))]
        for k, n in enumerate(nodes):
            e.w32(n + 0x23, r.choice([0x100bbd, 0x100bbd, r.getrandbits(32), 0x100000, 0x200002]))
            e.w32(n + 0xc, nodes[k + 1] if k + 1 < len(nodes) else 0)
        e.w32(nodes[0] + 0x23, r.choice([0x100000, 0x300000, 0x200002, r.getrandbits(32), 0x100bbd]))
        own = obj(c, 0x20, {0x10: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)]))})
        e.w32(own + 0xc, nodes[0])
        e.w32(me + 0x54, own)
    strm = obj(c, 0x20, {0x10: pystub(c, 2, this=True, deref={0: 1})})
    return [me, strm]


S(0x4dc2b0, 'GUESS serialise entry to stream', 'thiscall', None, ret='al', gen=_g4dc2b0, note='batch37001')
