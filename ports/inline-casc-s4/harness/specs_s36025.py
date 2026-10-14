"""specs_s36025.py - cascade s4 batch 36025: 0x4c2360, 0x4c23f0 and 0x4ca620 (read fields from a stream), 0x46d810 (notify matching list entries), 0x4fa510 (message handler for one id)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _stream(c, sizes):
    r = c.rng
    slots = {}
    for off, n in sizes.items():
        def side(em, k, n=n):
            em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(n)))
        slots[off] = pystub(c, 1, this=True, side=side)
    return obj(c, 0x20, slots)


def _gstream(sizes, esize=0xc0):
    def g(c):
        clear_hooks(c)
        return [rnd(c, esize), _stream(c, sizes)]
    return g


def _g46d810(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    res = [r.choice([0, 0, 1, 5]) for _ in range(8)]
    st = {'i': 0}

    def m(em, rr):
        k = st['i']
        st['i'] += 1
        em.calllog.append(('4cc850', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=res[min(k, 7)], argbytes=0)
    e.hook(0x4cc850, m)
    key = r.randint(1, 3)
    n = r.choice([0, 1, 2, 3])
    elems = []
    for i in range(n):
        el = rnd(c, 0x10)
        e.w32(el, key if r.random() < 0.6 else r.randint(1, 3))
        e.w32(el + 4, r.getrandbits(32) | 1)
        elems.append(el)
    objs = []
    for i in range(n):
        if r.random() < 0.2:
            objs.append(0)
        else:
            o = rnd(c, 0x20)
            e.w32(o + 4, 0 if r.random() < 0.3 else rnd(c, 0x10))
            objs.append(o)
    seq = elems + [0]
    cobj = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)), 0x44: pystub(c, 1, this=True, stackmark=(0,)),
                         0x64: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[min(k, len(seq) - 1)])})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, len(objs) - 1)] if objs else 0)})
    sink = obj(c, 0x20, {4: pystub(c, 1, this=True)})
    E = rnd(c, 0x80)
    e.w32(E + 0x70, 0 if r.random() < 0.1 else cobj)
    return [E, sink, key, 0 if r.random() < 0.4 else rnd(c, 0x10)]


def _g4fa510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    x = obj(c, 0x20, {0x308: pystub(c, 1, this=True), 0x350: pystub(c, 3, this=True), 0x34c: pystub(c, 5, this=True)})
    E = obj(c, 0x100, {0x2c4: pystub(c, 0, this=True, ret=x)})
    tgt = r.getrandbits(32)
    e.w32(E + 0x9b, tgt)
    a = tgt if r.random() < 0.8 else r.getrandbits(32)
    return [E, a, r.choice([2, 2, 0, 1, 3, r.getrandbits(32)])]


S(0x4c2360, 'GUESS read fields from stream (G)', 'thiscall', None, ret='al', gen=_gstream({0x44: 2, 0x68: 1, 0x50: 4, 0x48: 4}), note='batch36025')
S(0x46d810, 'GUESS notify sink for matching entries', 'thiscall', None, ret=None, gen=_g46d810, note='batch36025')
S(0x4c23f0, 'GUESS read fields from stream (H)', 'thiscall', None, ret='al', gen=_gstream({0x44: 2, 0x68: 1, 0x50: 4}), note='batch36025')
S(0x4ca620, 'GUESS read fields from stream (I)', 'thiscall', None, ret='al', gen=_gstream({0x6c: 12, 0x68: 1, 0x40: 4}, 0x100), note='batch36025')
S(0x4fa510, 'GUESS message handler for matching id', 'thiscall', None, ret='al', gen=_g4fa510, note='batch36025')
