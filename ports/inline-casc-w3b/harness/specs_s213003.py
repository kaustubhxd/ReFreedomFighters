"""specs_s213003.py - batch 213003: parser step functions with jump tables, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _step(base, span, extra=None):
    def g(c):
        clear_hooks(c)
        r = c.rng
        o = rnd(c, 0x20)
        if r.random() < 0.5:
            c.emu.w32(o + 0xc, 0)
        if r.random() < 0.4:
            c.emu.w32(o + 8, r.choice([0, 0, 1, 2, 5]))
        b = r.randint(base - 2, base + span + 2) if r.random() < 0.9 else r.getrandbits(32)
        if r.random() < 0.15:
            b = 0x1c
        if base == -4 and r.random() < 0.3:
            b = r.choice([-4, 0x22, 0x1a])
            c.emu.w32(o + 8, r.choice([0, 1, 2]))
        if extra:
            extra(c)
        return [o, b]
    return g


def _hook62dc60(c):
    hook_rec(c, 0x62dc60, 2, ret=c.rng.getrandbits(32), pop=0, deref={0: 4})


S(0x62ca20, 'parser_step_c', 'cdecl', None, ret='eax', gen=_step(0xf, 0x1a))
S(0x62d470, 'parser_step_d', 'cdecl', None, ret='eax', gen=_step(0xf, 0x15))
S(0x62dbb0, 'parser_step_e', 'cdecl', None, ret='eax', gen=_step(-4, 0x26, _hook62dc60))
