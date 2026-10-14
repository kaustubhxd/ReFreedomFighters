"""specs_s46000.py - cascade t7 batch 46000: 0x56a220 UI widget command dispatcher. All callees hooked; self vtable slot 0xd0, widget slots
(+0x44 slot 0x12c, +0x90 slot 0x658), engine object table (+0x9b) slots 0x114/0x138/0xa8/0x134 are recorders; the assert hook is always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, HEAP_LO, HEAP_HI

STR = b'C08R'


def _o(c):
    r = c.rng
    o = rnd(c, 0x1100)
    e = c.emu
    e.wbytes(o + 0x103e, bytes([r.choice([0, 1, 2])]))
    e.wbytes(o + 0x1040, bytes([r.choice([0, 1, 5])]))
    e.wbytes(o + 0x1042, bytes([r.choice([0, 1, 7])]))
    e.w32(o + 0x1044, r.choice([3, 3, 3, 0, 4, r.getrandbits(32)]))
    e.w32(o + 0x1048, r.choice([0xfffffffd, 0xfffffffd, 0, r.getrandbits(32)]))
    if r.random() < 0.5:
        s = STR
    else:
        s = bytes([ord('C'), r.choice(b'0123456789'), r.choice([0x38, 0x38, r.choice(b'0123456789')]),
                   r.choice([0x41, 0x41, 0x52, r.choice(b'ABCRXYZ')])])
    e.wbytes(o + 0x48, s + b'\0')
    return o


def _id(r):
    k = r.random()
    if k < 0.1:
        return r.randrange(0, 6)
    if k < 0.7:
        return r.choice([0x64, 0xc8, 0x2b67, 0x309, 0x378, 0x384, 0x3e8, 0x3f2, 0xbb8, 0xfa0, 0x1b58])
    if k < 0.78:
        return 0xff0000 | r.randrange(0, 0x70)
    if k < 0.92:
        return r.choice([0x12c, 0x18f, 0x12c + r.randrange(0, 0x64)])
    return r.choice([6, 0x63, 0x65, 0xc7, 0x190, 0x12b, 0x1b57, 0x1b59, 0xfa1, 0x1000000, r.getrandbits(32)])


def g56a220(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562b50, 1, this=True, deref={0: -5})
    hook_rec(c, 0x562bc0, 0, this=True)
    hook_rec(c, 0x562c20, 1, this=True)
    hook_rec(c, 0x563500, 0, this=True)
    hook_rec(c, 0x561f10, 1, this=True)
    hook_rec(c, 0x59c420, 0, this=True)
    hook_rec(c, 0x5ae270, 1, this=True)
    hook_rec(c, 0x5ae710, 1, this=True)
    hook_rec(c, 0x610100, 1, this=True)

    def pair_side(em, k):
        p = em.reg('ecx')
        em.calllog.append(('pair', em.r32(p), em.r32(p + 4)))
    hook_rec(c, 0x48aad0, 0, this='mark', ret=lambda em, k: r.getrandbits(32), side=pair_side)
    newids = [r.randrange(0, 8) for _ in range(8)]
    flips = [r.random() < 0.5 for _ in range(8)]

    def s114(em, k):
        v = em.arg32(4)
        if 0x0fe00000 <= v < 0x0ff00000:
            em.calllog.append(('idloc', em.r32(v)))
            if flips[min(k, 7)]:
                em.w32(v, newids[min(k, 7)])
    rets = [r.getrandbits(32) for _ in range(8)]
    p = obj(c, 0x40, {0x68: pystub(c, 3, this=True), 0x5c: pystub(c, 3, this=True)})
    t_slots = {0x114: pystub(c, 5, this=True, ret=lambda em, k: rets[min(k, 7)], stackmark=(4,), side=s114),
               0x138: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32)),
               0xa8: pystub(c, 0, this=True),
               0x134: pystub(c, 0, this=True, ret=p)}
    sysobj(c, table_slots=t_slots)
    w = obj(c, 0x40, {0x12c: pystub(c, 2, this=True)})
    w90 = obj(c, 0x40, {0x658: pystub(c, 0, this=True)}) if r.random() < 0.7 else 0
    me = obj(c, 0x400, {0xd0: pystub(c, 1, this=True)})
    e.w32(me + 0x44, w)
    e.w32(me + 0x90, w90)
    e.w32(me + 0x94, _o(c))
    e.w32(me + 0xdc, r.choice([2] * 12 + [3, 0, 4]))
    e.w32(me + 0x198, r.choice([0, r.getrandbits(32)]))
    e.wbytes(me + 0x1c5, (r.choice([4, 4, r.getrandbits(32)])).to_bytes(4, 'little'))
    e.wbytes(me + 0x87, bytes([r.choice([0, 1])]))
    for i in range(0x70):
        e.w32(me + 0x180 + 4 * i, r.choice([0, r.getrandbits(32)]))
    return [me, _id(r)]


S(0x56a220, 'GUESS UI widget command dispatcher', 'thiscall', None, ret='al', gen=g56a220, note='batch46000')
