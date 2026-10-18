"""specs_s213002.py - batch 213002: two selector jump tables, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _sel(c, lo, hi):
    r = c.rng
    return r.randint(lo, hi) if r.random() < 0.9 else r.getrandbits(32)


def g5af040(c):
    clear_hooks(c)
    return [_sel(c, 0, 13)]


def g486bb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [rnd(c, 0x40), _sel(c, -1, 9)]


S(0x5af040, 'sel_code_map', 'stdcall', None, ret='eax', gen=g5af040)
S(0x486bb0, 'field_by_sel_assert', 'thiscall', None, ret='eax', gen=g486bb0)
