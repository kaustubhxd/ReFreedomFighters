"""specs_s2481.py - decomp area 24, batch 2481: two save functions. The base save (0x45f960, recorder, returns AL: a fixed value
per case) runs first; when AL is set, the save object gets its two slots and AL = 1, otherwise AL is the base result.
0x4545a0 ZGATE::Save: slot 0x60 with the byte at +0x5a, then slot 0x3c with the dword at +0x5c.
0x44c1e0 ZSNDOBJ::Save: slot 0x3c with the dword at +0x1c, then slot 0x60 with the byte at +0x20.
Thiscall, ret 4, AL."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    v = r.choice([0, 1, 0x101])
    hook_rec(c, 0x45f960, 1, this=True, ret=v)
    sg = obj(c, 0x40, {0x60: pystub(c, 1), 0x3c: pystub(c, 1)})
    return [rnd(c, 0x100), sg]


S(0x4545a0, 'ZGATE::Save', 'thiscall', None, ret='al', gen=_gen, note='batch2481')
S(0x44c1e0, 'ZSNDOBJ::Save', 'thiscall', None, ret='al', gen=_gen, note='batch2481')
