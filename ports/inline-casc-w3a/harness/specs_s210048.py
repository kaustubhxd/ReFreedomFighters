"""specs_s210048.py - Sonnet-w3a: /GS rows: message formatter into a 0x104 stack buffer, consistency check with the assert handler; stubs tag/log the stack buffers."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _log(tag): return lambda emu, k: emu.calllog.append((tag,))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g57c390(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    hook_rec(c, 0x561c40, 0, ret=c.rng.choice([0, 1, 0x100, 0x80, 0xff]))

    def sbuf(emu, k):
        emu.w32(emu.arg32(1), 0xFEED0000 | c.rng.getrandbits(16))

    def s5636(emu, k):
        emu.calllog.append(('buf', emu.r32(emu.arg32(1))))
    hook_rec(c, 0x5636c0, 2, ret=_r(c), this=True, stackmark=(1,), side=s5636)
    f = obj(c, 0x40, {0x198: pystub(c, 5, ret=_r(c), pop=0, stackmark=(1,), side=sbuf)}, nslots=0x70)
    st = obj(c, 0x40, {0: pystub(c, 2, ret=lambda e, k: c.rng.getrandbits(32), this=True)}, nslots=4)
    mg = rnd(c, 0xb00); c.emu.w32(mg + 0xae4, st)
    eng = obj(c, 0x200, {0x190: pystub(c, 0, ret=f, this=True)}, nslots=0x70)
    _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    t = rnd(c, 0x190); c.emu.w32(t + 0x180, _r(c))
    return [t]


def g5ff960(c):
    clear_hooks(c)
    _assert_hook(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    t = rnd(c, 0x40)
    ref = [c.emu.r32(t + 0x18 + 4 * i) for i in range(4)]
    eq = c.rng.random() < 0.5
    which = c.rng.randrange(0, 4)
    vals = list(ref) if eq else [ref[i] ^ (0x100 if i == which else 0) for i in range(4)]
    exp = [c.emu.r32(t + 8), c.emu.r32(t + 0xc)]
    pick = [c.rng.random() < 0.5, c.rng.random() < 0.5]

    def s70(emu, k):
        for i in range(4): emu.w32(emu.arg32(0) + 4 * i, vals[i])

    def s5c(emu, k):
        emu.w32(emu.arg32(0), exp[k] if pick[k] else exp[k] ^ 1)
    a = obj(c, 0x40, {0x70: pystub(c, 2, ret=_r(c), this=True, stackmark=(0,), side=s70),
                      0x5c: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=s5c)}, nslots=0x30)
    return [t, a]


S(0x57c390, 'gs_format_message', 'thiscall', None, ret=None, gen=g57c390, note='batch210048')
S(0x5ff960, 'gs_consistency_check', 'thiscall', None, ret=None, gen=g5ff960, note='batch210048')
