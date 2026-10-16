"""Controlled strict spec for 0x662f40's vector easing step."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, rnd


def g662f40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self = rnd(c, 0x60)
    output_vec = rnd(c, 0x20)
    child_vec = rnd(c, 0x20)

    # SetDstDir's input vector, the easing object's output angle, and vangpul's
    # output are all recorded or written by controlled hooks.  This keeps the
    # outer function's ordering and all register/stack arguments observable.
    hook_rec(c, 0x662fd0, 1, ret=r.getrandbits(32), this=True,
             deref={0: 3})

    eased_bits = r.getrandbits(32)
    done = r.choice([0, 1, 0xff, r.getrandbits(32)])

    def write_eased(emu, call_no):
        emu.w32(emu.arg32(0), eased_bits)

    hook_rec(c, 0x6627c0, 1, ret=done, this=True, deref={0: 1},
             side=write_eased)

    edx_log = e.alloc(4 * 8, 4)
    out_words = [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]

    def rotate_result(emu, call_no):
        edx_log_write = edx_log + 4 * min(call_no, 7)
        emu.w32(edx_log_write, emu.reg('edx'))
        p = emu.reg('ecx')
        for i, word in enumerate(out_words):
            emu.w32(p + 4 * i, word)

    hook_rec(c, 0x4e0130, 2, ret=r.getrandbits(32), this=True,
             side=rotate_result)
    return [self, output_vec]


S(0x662f40, 'matrix_ease_frame_update', 'thiscall', None, ret='al',
  gen=g662f40, reg_values=True)
