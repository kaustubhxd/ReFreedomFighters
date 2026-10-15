"""specs_s66069.py - cascade s4 batch 66069: 0x4b8080 / 0x4b81d0 (/GS-protected twins: bind two registry objects and notify the first)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _gen(c, A, B, W, BUF, F, size):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    ids = {0x68c070: 0x501, 0x69268c: 0x502}

    def s88(em, rr):                      # o->slot 0x88 (name, &id) ret 8
        em.calllog.append(('s88', em.arg32(0)))
        em.w32(em.arg32(1), ids.get(em.arg32(0), 0))
        em.ret(eax=0, argbytes=8)
    o = obj(c, 0x30, {0x88: e.stub_fn('s88', s88)})
    objA = obj(c, 0x40, {0x130: pystub(c, 3, this=True)})
    objB = rnd(c, 8)
    objs = {0x501: objA if r.random() < 0.85 else 0, 0x502: objB if r.random() < 0.85 else 0}

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0), 4)
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x58: e.stub_fn('find', find),
                           0x114: pystub(c, 5, this=True, ret=lambda em, k: r.choice([0x12345678, 0xffff, 0x10000]))})
    so = int.from_bytes(bytes(e.rbytes(0x70039c, 4)), 'little')
    tab = int.from_bytes(bytes(e.rbytes(so + 0x9b, 4)), 'little')
    e.w32(tab + 0xae4, r.choice([0, rnd(c, 8)]))
    rv = r.choice([0, rnd(c, 8)])

    def h60(em, rr):                      # 0x49df60 (ecx = registry, a, &local) ret 8
        em.calllog.append(('h49df60', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=rv, argbytes=8)
    e.hook(0x49df60, h60)
    hook_rec(c, 0x49e0d0, 0, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x49df30, 0, this=True)
    t = e.alloc(size, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.wbytes(t + F, bytes([r.choice([0, 5])]))
    return [t]


def _g4b8080(c):
    return _gen(c, 0x78, 0x7c, 0x74, 0x80, 0x183, 0x200)


def _g4b81d0(c):
    return _gen(c, 0x11b, 0x11f, 0x117, 0x123, 0x223, 0x300)


S(0x4b8080, 'GUESS /GS bind two registry objects and notify the first', 'thiscall', None, ret=None, gen=_g4b8080, note='batch66069')
S(0x4b81d0, 'GUESS /GS bind two registry objects and notify the first (twin)', 'thiscall', None, ret=None, gen=_g4b81d0, note='batch66069')
