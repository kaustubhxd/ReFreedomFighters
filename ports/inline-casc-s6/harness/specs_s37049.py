"""specs_s37049.py - cascade s6 batch 37049: 0x4ac460. Embedded list at this+0x11a (scripted slots 0x4c / 0x5c); table slots 0x58, 0x4c and the format object at [table+0xae4]
(slot 0: 2 args); engine slot 0x190 -> object whose cdecl slot 0x198 (4 args) writes into the stack buffer; 0x4ace80 hooked (this = ecx, 6 stack args); allocator at 0x70038c
(slot 0xcc) returns records with +0x106; embedded object at this+0x1c6 (slot 4)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4ac460(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    items = [r.randint(1, 0xffff) for _ in range(r.choice([0, 1, 2, 3, 4]))]
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
    me = e.alloc(0x200, 4)
    lvt = e.alloc(0x100, 4)
    e.w32(lvt + 0x4c, pystub(c, 1, this=True, nullflag=(0,), side=begin))
    e.w32(lvt + 0x5c, pystub(c, 1, this=True, nullflag=(0,), side=side, ret=nxt))
    _w(c, me + 0x11a, lvt)
    svt = e.alloc(0x40, 4)
    e.w32(svt + 4, pystub(c, 1, this=True))
    _w(c, me + 0x1c6, svt)
    names = [rnd(c, 0x10) for _ in range(2)]

    def mkobj():
        sobj = obj(c, 0x20, {0x300: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 1]))})
        e.w32(sobj + 4, r.choice([0, names[0], names[1]]))
        return obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100])),
                             0x2e8: pystub(c, 0, this=True, ret=sobj)})
    objs = {i: (mkobj() if r.random() < 0.8 else 0) for i in items}
    fmt = obj(c, 0x20, {0x0: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32))})
    so = sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=0)}, table_slots={
        0x58: pystub(c, 1, this=True, ret=lambda em, k: objs.get(em.arg32(0), 0)),
        0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    _w(c, tab + 0xae4, fmt)
    # engine slot 0x190 object with cdecl slot 0x198
    cd = obj(c, 0x40, {0x198: pystub(c, 4, pop=0, stackmark=(1,))})
    eng_vt = e.r32(so)
    e.w32(eng_vt + 0x190, pystub(c, 0, this=True, ret=cd))
    recs = [rnd(c, 0x120) for _ in range(3)]
    g = obj(c, 0x100, {0xcc: pystub(c, 1, this=True, ret=lambda em, k: recs[k % 3] if r.random() < 0.8 else 0)})
    e.w32(0x70038c, g)
    hook_rec(c, 0x4ace80, 6, this=True, stackmark=(0,), pop=0x18, ret=lambda em, k: r.getrandbits(32))
    _w(c, me + 0x44, rnd(c, 0x20))
    return [me]


S(0x4ac460, 'GUESS register records for listed objects', 'thiscall', None, ret=None, gen=_g4ac460, note='batch37049')
