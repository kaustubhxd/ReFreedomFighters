"""Controlled strict spec for 0x6630f0's timer/easing update."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, rnd


def g6630f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self = rnd(c, 0x80)

    # The scale is 1/1024 and the compare threshold is much smaller than one
    # tick.  Include equal and adjacent ticks (skip) as well as separated and
    # signed extreme values (update), so all conditional effects are observed.
    old_ticks, milliseconds = r.choice([
        (0, 0), (1, 1), (-1, -1), (0, 1), (1, 0),
        (0, 2), (2, 0), (-2, 0), (0, -2),
        (1024, 0), (0, 1024), (-1024, 1024),
        (0x7fffffff, 0x7fffffff), (0x80000000, 0x80000000),
        (0x7fffffff, 0x80000000), (r.getrandbits(32), r.getrandbits(32)),
    ])
    e.w32(self + 0x45, old_ticks)

    # The fastcall's ECX is recorder-visible through hook_rec; retain EDX in
    # heap state too, so its second vector address is part of the comparison.
    edx_log = e.alloc(4 * 8, 4)

    def save_edx(emu, call_no):
        emu.w32(edx_log + 4 * min(call_no, 7), emu.reg('edx'))

    blend = r.choice([0.0, -0.0, 1.0, -1.0, 0.125, -3.5,
                      r.uniform(-100.0, 100.0)])
    hook_rec(c, 0x4e0030, 0, ret=r.getrandbits(32), this=True,
             st0=blend, side=save_edx)
    hook_rec(c, 0x662ab0, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x662b00, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x662b70, 1, ret=r.getrandbits(32), this=True)
    return [self, milliseconds]


S(0x6630f0, 'matrix_ease_set_time', 'thiscall', None, ret=None,
  gen=g6630f0, reg_values=True)
