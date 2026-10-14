"""specs_s37043.py - cascade s6 batch 37043: 0x4b3270. Lists embedded in this (+0x10e: slots 0x4c, 0x64, 0xc; +0xf2: slots 0x4c, 0x5c, 0xc) are scripted objects; 0x4b3a70,
0x4b6b90, 0x4b6e00 hooked; table slots 0x4c / 0x54 / 0x58; owner at this+0x44 with slots 0x12c (3 args) and 0x130 (3 args)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4b3270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x4b3a70, 0, this=True)
    hook_rec(c, 0x4b6b90, 1, this=True)
    hook_rec(c, 0x4b6e00, 2, this=True)
    me = e.alloc(0x180, 4)
    for i in range(0x60):
        e.w32(me + 4 * i, r.getrandbits(32))

    def script(off, slots, items, nextslot):
        st = [0]

        def begin(em, k):
            st[0] = 0
            em.w32(em.arg32(0), 1)

        def side(em, k):
            em.w32(em.arg32(0), 1 if st[0] < len(items) else 0)

        def nxt(em, k):
            i = st[0]
            st[0] += 1
            return items[i] if i < len(items) else 0
        vt = e.alloc(0x100, 4)
        e.w32(vt + 0x4c, pystub(c, 1, this=True, nullflag=(0,), side=begin))
        e.w32(vt + nextslot, pystub(c, 1, this=True, nullflag=(0,), side=side, ret=nxt))
        e.w32(vt + 0xc, pystub(c, 0, this=True))
        e.w32(me + off, vt)
    script(0x10e, None, [r.randint(1, 0xffff) for _ in range(r.choice([0, 1, 2, 3]))], 0x64)
    ids2 = [r.randint(1, 0xffff) for _ in range(r.choice([0, 1, 2, 3]))]
    script(0xf2, None, ids2, 0x5c)
    objs = {i: (rnd(c, 0x20) if r.random() < 0.7 else 0) for i in ids2}
    oid = r.randint(1, 0xffff)
    O = obj(c, 0x80, {0x210: pystub(c, 1, this=True)})
    e.w32(O + 0x4c, r.choice([0, 0, 5]))
    so = sysobj(c, table_slots={0x54: pystub(c, 1, this=True, ret=lambda em, k: objs.get(em.arg32(0), 0)),
                                0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32)),
                                0x58: pystub(c, 1, this=True, ret=O)}, table_size=0x20)
    n = r.choice([0, 1, 3, -1])
    _w(c, me + 0xee, n)
    b90 = e.alloc(0x10, 1)
    b94 = e.alloc(0x10, 1)
    e.wbytes(b90, bytes(r.getrandbits(8) for _ in range(0x10)))
    e.wbytes(b94, bytes(r.getrandbits(8) for _ in range(0x10)))
    _w(c, me + 0x90, b90)
    _w(c, me + 0x94, b94)
    _w(c, me + 0x88, r.choice([0, 0x1234]))
    _w(c, me + 0x9a, r.choice([0, 1]), 1)
    _w(c, me + 0xa0, r.choice([0, 1]), 1)
    owner = obj(c, 0x40, {0x12c: pystub(c, 3, this=True), 0x130: pystub(c, 3, this=True)})
    _w(c, me + 0x44, owner)
    return [me]


S(0x4b3270, 'GUESS release per-frame state', 'thiscall', None, ret=None, gen=_g4b3270, note='batch37043')
