"""specs_s31100.py - batch 31100."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def g5d4610(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x589c20, 1, ret=r32(c), pop=4, this=True)
    c.emu.w32(0x7003b8, rnd(c, 0x40))

    def side(em, k):
        em.w32(em.arg32(1), r32(c))
    o = obj(c, 0x40, {0x88: pystub(c, 2, ret=r32(c), this=True, side=side, deref={1: 1})})
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=o, this=True)})
    return [rnd(c, 0x80)]


def g5f3010(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    hook_rec(c, 0x634d22, 3, ret=r32(c), pop=0)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, r.choice([0, 5, 0x100, r32(c) >> 4]))
    n = r.choice([0, 1, 4, 0x10, r32(c) >> 8])
    cap = (c.emu.r32(me + 8) + n) & 0xffffffff
    c.emu.w32(me + 0xc, r.choice([cap, cap, cap + 1, cap - 1 & 0xffffffff, r32(c)]))
    return [me, r32(c), n]


def g438d50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x439670, 0, ret=lambda e, k: r.choice([0, 1, r32(c)]), pop=0, this=True)
    rec = rnd(c, 0x20)
    c.emu.w32(rec + 4, r.choice([3, 3, 0, r32(c)]))
    c.emu.w8(rec + 0x10, r.choice([0, 1, 1, 0xff, r.getrandbits(8)])) if hasattr(c.emu, 'w8') else c.emu.w32(rec + 0x10, r.choice([0, 1, 0x100, r32(c)]))
    ret = r.choice([0, rec, rec])
    me = obj(c, 0x40, {0x60: pystub(c, 1, ret=ret, this=True)})
    return [me, r32(c)]


S(0x5d4610, 'GUESS fetch value via slot 0x88 and 589c20', 'thiscall', None, ret='eax', gen=g5d4610, note='batch31100')
S(0x5f3010, 'GUESS bounds-asserted append copy', 'thiscall', None, ret=None, gen=g5f3010, note='batch31100')
S(0x438d50, 'GUESS lookup via slot 0x60 then flag and 439670', 'thiscall', None, ret='al', gen=g438d50, note='batch31100')
