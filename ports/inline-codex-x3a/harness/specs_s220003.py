"""Strict state-and-block spec for the MD5 compression transform at 0x606230."""
from pilot import S
from recruits_util import clear_hooks, rnd


def g606230(c):
    clear_hooks(c)
    state = rnd(c, 0x10)
    block = rnd(c, 0x40)
    return [state, block]


S(0x606230, 'MD5 compression block 0x606230', 'thiscall', None,
  ret=None, gen=g606230, note='batch220003')
