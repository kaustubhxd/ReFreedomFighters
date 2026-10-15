"""specs_s66050.py - cascade s4 batch 66050: 0x600540 / 0x600610 (map insert with a position hint, u16 and u32 keys)."""
from pilot import S
from recruits_util import clear_hooks


def _build(c, wide):
    r = c.rng
    e = c.emu
    keys = sorted(set(r.sample(range(1, 20), r.choice([0, 1, 2, 3, 5]))))
    head = e.alloc(0x30, 8)
    nodes = []
    for k in keys:
        n = e.alloc(0x30, 8)
        if wide:
            e.w32(n + 0xd, k)
        else:
            e.wbytes(n + 0xd, k.to_bytes(2, 'little'))
        e.w32(n + 9, r.choice([0, 0, n + 0x20]))
        nodes.append(n)
    first = nodes[0] if nodes else head
    last = nodes[-1] if nodes else head
    e.w32(head + 5, first)
    e.w32(head + 9, last)
    t = e.alloc(0x10, 8)
    e.w32(t, head)
    e.w32(t + 4, len(nodes) if r.random() < 0.9 else 0)
    pred = {}
    for i, n in enumerate(nodes):
        pred[n] = nodes[i - 1] if i > 0 else head
    pred[head] = last
    hint = r.choice(nodes + [head])
    ks = r.choice([0, 1, 5, 10, 25, 0x10003, 0xffff, 0x1ffff])
    if not wide:
        ks &= 0xffff
    if keys and r.random() < 0.5:
        ks = r.choice(keys) + r.choice([-1, 0, 1])
    key = e.alloc(8, 8)
    e.w32(key, ks & 0xffffffff)

    def dec(em, rr):                      # 0x42ffc0 (ecx = &iter) plain ret: iter = predecessor
        it = em.reg('ecx')
        cur = em.r32(it)
        em.calllog.append(('prev', cur))
        em.w32(it, pred.get(cur, head))
        em.ret(eax=0, argbytes=0)
    e.hook(0x42ffc0, dec)
    cell = e.alloc(8, 8)
    e.w32(cell, r.getrandbits(32))

    def ins(name, argb):
        def h(em, rr):
            em.calllog.append((name, em.reg('ecx'), em.r32(em.arg32(1))))
            em.ret(eax=cell, argbytes=8)
        return h

    def at(name):
        def h(em, rr):
            em.calllog.append((name, em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2), em.r32(em.arg32(3))))
            em.w32(em.arg32(0), 0x5a5a5a5a)
            em.ret(eax=em.arg32(0), argbytes=16)
        return h
    out = e.alloc(8, 8)
    e.w32(out, 0xdead)
    return t, out, hint, key, ins, at


def _g600540(c):
    clear_hooks(c)
    t, out, hint, key, ins, at = _build(c, False)
    c.emu.hook(0x6004a0, ins('ins16', 8))
    c.emu.hook(0x5fe240, at('at16'))
    return [t, out, hint, key]


def _g600610(c):
    clear_hooks(c)
    t, out, hint, key, ins, at = _build(c, True)
    c.emu.hook(0x6006e0, ins('ins32', 8))
    c.emu.hook(0x5fe300, at('at32'))
    return [t, out, hint, key]


S(0x600540, 'GUESS map insert with a position hint (u16 keys)', 'thiscall', None, ret='eax', gen=_g600540, note='batch66050')
S(0x600610, 'GUESS map insert with a position hint (u32 keys)', 'thiscall', None, ret='eax', gen=_g600610, note='batch66050')
