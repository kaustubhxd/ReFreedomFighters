"""specs_s37040.py - cascade s6 batch 37040: 0x5355a0. Command buffer cursor at this+0x51a9 (spec buffer), list objects with scripted slots 0x4c / 0x5c, optional object at
this+0x52fe whose sub-object lives at +0x19 (its vtable pointer is stored unaligned there) with slots 0x14, 0x4c, 0x5c; this slots 0x17c / 0x180 / 0x188."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g5355a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def mkslots(items):
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
        return {0x4c: pystub(c, 1, this=True, nullflag=(0,), side=begin),
                0x5c: pystub(c, 1, this=True, nullflag=(0,), side=side, ret=nxt)}

    def mklist():
        items = [r.getrandbits(32) for _ in range(r.choice([0, 1, 2, 3]))]
        return obj(c, 0x20, mkslots(items))
    l1 = mklist() if r.random() < 0.8 else 0
    l2 = mklist() if r.random() < 0.8 else 0
    buf = e.alloc(0x400, 4)
    for i in range(0x100):
        e.w32(buf + 4 * i, r.getrandbits(32))
    me = e.alloc(0x5400, 4)
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0x17c, pystub(c, 0, this=True))
    e.w32(vt + 0x180, pystub(c, 1, this=True))
    e.w32(vt + 0x188, pystub(c, 0, this=True))
    e.w32(me, vt)
    e.wbytes(me + 0x51a9, buf.to_bytes(4, 'little'))
    if r.random() < 0.7:
        O = e.alloc(0x60, 4)
        items = [r.getrandbits(32) for _ in range(r.choice([0, 1, 2, 3]))]
        sl = mkslots(items)
        cnt = r.choice([0, 1, 2, 3, len(items)])
        sl[0x14] = pystub(c, 0, this=True, ret=cnt)
        svt = e.alloc(0x100, 4)
        for off, code in sl.items():
            e.w32(svt + off, code)
        e.wbytes(O + 0x19, svt.to_bytes(4, 'little'))
        e.wbytes(me + 0x52fe, O.to_bytes(4, 'little'))
    return [me, r.getrandbits(32), l2, l1]


S(0x5355a0, 'GUESS emit command records', 'thiscall', None, ret=None, gen=_g5355a0, note='batch37040')
