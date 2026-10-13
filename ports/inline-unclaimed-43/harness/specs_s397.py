"""specs_s397.py - core batch 397: 0x5095f0 ZActorIf::opaqueCall (stdcall, one argument obj). The table count is at 0x701048
(0..3), the table at 0x701050 holds four logging stubs, and the tail target 0x5060b0 is hooked by address and logged (GUESS:
body not ported). obj has the word index at +0x10 (0..5)."""
from pilot import S
import engine_stubs as E


def _setup(c):
    c.emu.hook(0x5060b0, lambda em, r: (em.calllog.append(('tail5060b0', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=4)))


def _gen(c):
    r = c.rng
    c.emu.w32(0x701048, r.randint(0, 3))
    for k in range(4):
        def h(e, rr, k=k):
            e.calllog.append(('TBL5095', k, 0, (e.arg32(0),)))
            e.ret(eax=0, argbytes=4)
        c.emu.w32(0x701050 + 4 * k, c.emu._new_stub('t5095_%d' % k, h))
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.w16(o + 0x10, r.randint(0, 5))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5095f0, 'ZActorIf::opaqueCall (core) stdcall', 'stdcall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 397; tail target 0x5060b0 hooked (GUESS); table entries are logging stubs')
