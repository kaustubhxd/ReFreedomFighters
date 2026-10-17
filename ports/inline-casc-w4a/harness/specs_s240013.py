"""specs_s240013.py - Sonnet-w4a: thunk, fatal assert, SEH wrapper."""
import pe_emu
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_chain, STACK_LO, STACK_HI


def _w(c):
    return c.rng.getrandbits(32)


def _g660ce0(c):
    clear_hooks(c)
    r = c.rng
    st = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    child = obj(c, 0x20, {0x14: st})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, r.choice([0, child, child]))
    return [me]


def _g5f17d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sink = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0, ret=lambda em, k: _w(c))})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=sink)})
    e.w32(0x700390, logger)
    e.w32(0x7003b0, pystub(c, 0, pop=0, ret=lambda em, k: _w(c)))
    return [_w(c)]


def _g41c9c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x6f5630, _w(c))
    seh_chain(c, r.choice([0, 1, 2]))

    def side(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
            return
        nxt = em.r32(a)
        em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8), em.r32(a + 0xc)))
    hook_rec(c, 0x41ca80, 4, pop=16, side=side, ret=lambda em, k: _w(c))
    cell = e.r32(0x67606c)
    dbg = r.choice([0, 0, 1])

    def h(em, res):
        em.ret(eax=dbg, argbytes=0)
    e.stubs[cell] = (e.stubs[cell][0], h)
    return [_w(c), _w(c), _w(c), _w(c)]


S(0x660ce0, 'GUESS child vtable tail thunk', 'thiscall', None, ret='eax', gen=_g660ce0, note='batch240013')
S(0x5f17d0, 'GUESS assert failure logger', 'stdcall', None, ret='eax', gen=_g5f17d0, note='batch240013')
S(0x41c9c0, 'GUESS SEH wrapper around 41ca80', 'stdcall', None, ret='eax', gen=_g41c9c0, note='batch240013')
