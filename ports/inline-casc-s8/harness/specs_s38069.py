"""specs_s38069.py - cascade s8 batch 38069: 0x5709d0. thiscall(this) void. Engine table object (slots 0x58 lookup, 0x134 -> X (slot 0x5c), 0x138 -> Z (slot 0x88 writes a random out value); +0xae4 -> object with slot 0),
this[0] vtable slot 0x84 -> Y (slot 0x114), this[0x94] block with the flag byte at +0x103e, this[0x54] object (slot 0x25c) -> object (slot 0x25c) -> object with a child list at +0x50 (next at +0x60, child at +0x54);
children have slot 0x1e0 (random al for the two flag masks) and slot 0x258 (logs the two dwords of the vector); this[0x1a3] sometimes set; this[0x1c0/0x1c4] preset to valid objects. 0x563750 / 0x563610 / 0x570310 hooked;
every slot is a logging stub (all calls are logged)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g5709d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lslot(name, nargs, retf=lambda: 0, mem=0):
        def h(em, res_):
            row = (name, em.reg('ecx') != 0) + tuple(em.arg32(i) for i in range(1 if mem else 0, nargs))   # mem: arg0 is a stack address, log the contents instead
            if mem:
                row = row + struct.unpack('<2I', em.rbytes(em.arg32(0), 8))
            em.calllog.append(row)
            em.ret(eax=retf(), argbytes=4 * nargs)
        return e.stub_fn(name, h)

    def named(em, res_):
        out = em.arg32(1)
        v = r.getrandbits(32)
        em.calllog.append(('named', em.arg32(0)))
        em.w32(out, v)
        em.calllog.append(('named-out', v))
        em.ret(eax=0, argbytes=8)
    Z = obj(c, 0x20, {0x88: e.stub_fn('named', named)})
    X = obj(c, 0x20, {0x5c: lslot('s5c', 3)})
    tb = obj(c, 0x20, {0x00: lslot('t0', 2, lambda: r.getrandbits(32))})
    sysobj(c, table_size=0xb00, table_slots={0x58: lslot('s58', 1, lambda: r.getrandbits(32)),
                                              0x134: e.stub_fn('s134', lambda em, res_: (em.calllog.append(('s134',)), em.ret(eax=X))),
                                              0x138: e.stub_fn('s138', lambda em, res_: (em.calllog.append(('s138',)), em.ret(eax=Z)))})
    e.w32(e.r32(e.r32(0x70039c) + 0x9b) + 0xae4, tb)
    Y = obj(c, 0x20, {0x114: lslot('s114', 1)})
    this = obj(c, 0x240, {0x84: e.stub_fn('s84', lambda em, res_: (em.calllog.append(('s84',)), em.ret(eax=Y)))})
    blk = rnd(c, 0x1100)
    if r.random() < 0.5:
        e.wbytes(blk + 0x103e, b'\0')
    e.w32(this + 0x94, blk)

    def child():
        return obj(c, 0x20, {0x1e0: e.stub_fn('s1e0', lambda em, res_: (em.calllog.append(('s1e0', em.arg32(0))), em.ret(eax=(r.getrandbits(32) & 0xffffff00) | r.choice([0, 1, 1, 0x80]), argbytes=4))),
                             0x258: lslot('s258', 2, mem=1)})
    nn = r.choice([0, 1, 2, 3, 5, 8, 30])
    prev = 0
    for i in range(nn):
        nd = rnd(c, 0x70)
        e.w32(nd + 0x54, child())
        e.w32(nd + 0x60, prev)
        prev = nd
    head = prev
    o2 = rnd(c, 0x70)
    e.w32(o2 + 0x50, head)
    o1 = obj(c, 0x20, {0x25c: e.stub_fn('s25c-b', lambda em, res_: (em.calllog.append(('s25c-b', em.arg32(0), em.arg32(1))), em.ret(eax=o2, argbytes=8)))})
    c54 = obj(c, 0x20, {0x25c: e.stub_fn('s25c-a', lambda em, res_: (em.calllog.append(('s25c-a', em.arg32(0), em.arg32(1))), em.ret(eax=(o1 if em.arg32(0) == 0x6a69fc else tobj), argbytes=8)))})
    tobj = obj(c, 0x20, {0x284: lslot('s284', 1)})
    e.w32(this + 0x54, c54)
    e.wbytes(this + 0x1a3, b'\1' if r.random() < 0.15 else b'\0')
    e.w32(this + 0x1c0, child())
    e.w32(this + 0x1c4, child())
    hook_rec(c, 0x563750, 2, this=True, pop=8)
    hook_rec(c, 0x563610, 1, this=True, pop=4)
    hook_rec(c, 0x570310, 0, this=True, pop=0)
    return [this]


S(0x5709d0, 'GUESS resolve handles and collect child objects', 'thiscall', None, ret=None, gen=_g5709d0, note='batch38069')
