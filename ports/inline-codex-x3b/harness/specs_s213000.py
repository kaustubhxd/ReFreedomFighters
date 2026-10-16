"""specs_s213000.py - batch 213000: jump-table (byte map + table) functions, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _ch(c, lo, hi, p=0.8):
    r = c.rng
    if r.random() < p:
        return r.randint(lo, hi)
    return r.getrandbits(32)


def g628ee0(c):
    clear_hooks(c)
    return [_ch(c, 0, 0x30)]


def g62c640(c):
    clear_hooks(c)
    r = c.rng
    a = r.choice([r.randint(0xd0, 0xff), r.randint(0, 255), r.getrandbits(32)])
    if r.random() < 0.5:
        a = (r.getrandbits(24) << 8) | (a & 0xff)
    b = r.choice([r.randint(0xf0, 0xff), r.randint(0, 255), r.getrandbits(32)])
    if r.random() < 0.5:
        b = (r.getrandbits(24) << 8) | (b & 0xff)
    if r.random() < 0.3:
        a = (a & ~0xff) | 0xff
        b = (b & ~0xff) | r.choice([0xfc, 0xfd, 0xfe, 0xff])
    return [a, b]


def g5af1d0(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x10, 0)
    return [o, _ch(c, 0xa, 0x12)]


def _gstep(base, span):
    def g(c):
        clear_hooks(c)
        o = rnd(c, 0x20)
        if c.rng.random() < 0.5:
            c.emu.w32(o + 0xc, 0)
        b = _ch(c, base - 2, base + span + 2)
        if c.rng.random() < 0.2:
            b = 0x1c
        return [o, b]
    return g


S(0x628ee0, 'is_space', 'cdecl', None, ret='eax', gen=g628ee0)
S(0x62c640, 'classify_hi_byte', 'cdecl', None, ret='eax', gen=g62c640)
S(0x5af1d0, 'select_field', 'thiscall', None, ret='eax', gen=g5af1d0)
S(0x62cb80, 'parser_step_a', 'cdecl', None, ret='eax', gen=_gstep(0xf, 0x1a))
S(0x62e120, 'parser_step_b', 'cdecl', None, ret='eax', gen=_gstep(0xb, 0x12))
