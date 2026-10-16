"""Strict failure-recovery fixture for the parser helper at 0x621230."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, rnd


def g621230(c):
    # Drive the real, useful lookup/allocation-failure path. It performs the
    # name-table lookup, asks the pool helper to allocate an entry, commits
    # that helper's null result through the caller's out pointer, and returns
    # the documented failure result. The large normal parsing body is then
    # intentionally not entered, so neither side reads synthetic parser state.
    clear_hooks(c)
    e, r = c.emu, c.rng
    parser = rnd(c, 0x200)
    callback = rnd(c, 0x40)
    out = rnd(c, 4)
    e.w32(out, r.getrandbits(31) | 1)
    a2 = r.getrandbits(32)
    a4 = rnd(c, 0x20)

    # 0x61fd60 and 0x6204f0 are caller-cleaned cdecl helpers here. A lookup
    # miss followed by an allocation failure is a valid, observable result:
    # [out] becomes zero and the helper returns one.
    hook_rec(c, 0x61fd60, 3, ret=0, pop=0, this=False)
    hook_rec(c, 0x6204f0, 2, ret=0, pop=0, this=False)
    return [parser, callback, a2, out, a4]


S(0x621230, 'parse_helper_lookup_alloc_failure', 'cdecl', None, ret='eax',
  gen=g621230,
  note='batch220009: lookup miss + pool allocation failure; writes out=0 and returns 1')
