"""specs_s31095.py - Sonnet h1 batch 31095: assert-hook pointer at 0x7003b0 is always set (recorder returning a random EAX), log object at 0x700390."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, pop=None):
    return pystub(c, n, ret=r32(c) if ret is None else ret, pop=pop, this=True)


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _log(c, n_msg):
    o2 = obj(c, 0x40, {0x2c: st(c, n_msg, pop=0)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: st(c, 2, ret=o2)}))


def g52aa90(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    _log(c, 2)
    hook_rec(c, 0x52e240, 1, ret=r32(c), pop=4, this=True)
    me = rnd(c, 0x80)
    c.emu.wbytes(me + 0x31, bytes([r.choice([0, 1, 1])]))
    c.emu.w32(me + 0x65, r32(c))
    return [me, r32(c)]


def g4454a0(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x2c, r.choice([0, 1, 2, 3, 5]))
    return [me, r32(c)]


def g604090(c):
    clear_hooks(c)
    _assert_hook(c)
    _log(c, 3)
    return [r32(c), r32(c)]


S(0x52aa90, 'GUESS flag gate: tail 52e240 or log + assert hook, false', 'thiscall', None, ret='eax', gen=g52aa90, note='batch31095')
S(0x4454a0, 'GUESS bounded array append, assert hook when full', 'thiscall', None, ret='eax', gen=g4454a0, note='batch31095')
S(0x604090, 'GUESS log via global log object then assert hook', 'stdcall', None, ret='eax', gen=g604090, note='batch31095')
