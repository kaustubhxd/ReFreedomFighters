"""specs_s210073.py - Sonnet-w3a: 0x42ab62. cdecl(fmt, v1, v2): file handle from 0x634d64(1), then 0x42ab26(file, fmt, 0, &v1); the pointer is into the caller's stack so the hook records the two dwords it points at."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _r(c): return c.rng.getrandbits(32)


def g42ab62(c):
    clear_hooks(c)
    hook_rec(c, 0x634d64, 1, ret=_r(c), pop=0)
    hook_rec(c, 0x42ab26, 4, ret=_r(c), pop=0, deref={3: 2})
    return [_r(c), _r(c), _r(c)]


S(0x42ab62, 'printf_stream1', 'cdecl', None, ret='eax', gen=g42ab62, note='batch210073')
