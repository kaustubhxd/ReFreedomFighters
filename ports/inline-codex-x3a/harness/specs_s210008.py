"""specs_s210008.py - Sonnet-w3a: table dispatchers with index rebasing, assert-fail tail, ctors; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _disp(T, N, TAB):
    def g(c):
        clear_hooks(c)
        n = c.rng.choice([0, 1, 2, 3, 5])
        c.emu.w32(N, n)
        for i in range(n):
            c.emu.w32(TAB + 4 * i, pystub(c, 1, ret=_r(c), this=True))
        hook_rec(c, T, 1, ret=_r(c), this=True)
        a = rnd(c, 0x40)
        c.emu.wbytes(a + 0x10, (c.rng.randrange(0, n + 4)).to_bytes(2, 'little'))
        return [rnd(c, 0x40), a]
    return g


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g602d30(c):
    clear_hooks(c)
    c.emu.w32(0x724694, 0 if c.rng.random() < 0.6 else _r(c))
    o = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    _assert_hook(c)
    return []


def g52cec0(c):
    clear_hooks(c)
    eng = obj(c, 0x100, {0x1c8: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x80)
    c.emu.w32(0x70039c, eng)
    return [rnd(c, 0x40), _r(c), _r(c)]


def g565b20(c):
    clear_hooks(c)
    o = obj(c, 0x40, {0xd8: pystub(c, 0, ret=c.rng.choice([0, 0x100, 1, _r(c)]), this=True)}, nslots=0x60)
    hook_rec(c, 0x564fd0, 1, ret=_r(c), this=True)
    hook_rec(c, 0x564600, 1, ret=_r(c), this=True)
    return [o, c.rng.choice([0, 1, 1, 2, _r(c)])]


def g573650(c):
    clear_hooks(c)
    hook_rec(c, 0x43de40, 3, ret=_r(c), this=True)
    return [rnd(c, 0x40), _r(c), _r(c), _r(c)]


S(0x5060b0, 'table_dispatch_5060b0', 'thiscall', None, ret='eax', gen=_disp(0x504560, 0x700f7c, 0x700f80), note='batch210008')
S(0x51ff40, 'table_dispatch_51ff40', 'thiscall', None, ret='eax', gen=_disp(0x51b600, 0x7019a8, 0x7019b0), note='batch210008')
S(0x603d90, 'table_dispatch_603d90', 'thiscall', None, ret='eax', gen=_disp(0x5fa270, 0x724698, 0x7246a0), note='batch210008')
S(0x6053c0, 'table_dispatch_6053c0', 'thiscall', None, ret='eax', gen=_disp(0x5fa270, 0x724768, 0x724770), note='batch210008')
S(0x602d30, 'assert_fail_if_zero', 'cdecl', None, ret='eax', gen=g602d30, note='batch210008')
S(0x52cec0, 'init_engine_slot_1c8', 'thiscall', None, ret='eax', gen=g52cec0, note='batch210008')
S(0x565b20, 'call_564fd0_slot_d8', 'thiscall', None, ret='al', gen=g565b20, note='batch210008')
S(0x573650, 'ctor_vt_6a8d30', 'thiscall', None, ret='eax', gen=g573650, note='batch210008')
