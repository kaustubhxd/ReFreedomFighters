"""specs_s394.py - core batch 394: 0x55ec30 (stdcall, one argument obj). The table count is at 0x713f10 (0..3), the table at
0x713f18 holds four logging stubs (in-emulator functions that log their argument and return), and the tail target 0x5095f0
is hooked by address and logged (GUESS: body not ported). obj is a block with the word index at +0x10 (0..5)."""
from pilot import S
import engine_stubs as E


def _setup(c):
    c.emu.hook(0x5095f0, lambda em, r: (em.calllog.append(('tail5095f0', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=4)))


def _gen(c):
    r = c.rng
    count = r.randint(0, 3)
    c.emu.w32(0x713f10, count)
    for k in range(4):
        def h(e, rr, k=k):
            e.calllog.append(('TBL', k, 0, (e.arg32(0),)))
            e.ret(eax=0, argbytes=4)
        c.emu.w32(0x713f18 + 4 * k, c.emu._new_stub('tbl%d' % k, h))
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.w16(o + 0x10, r.randint(0, 5))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x55ec30, 'ZFFActorIf::opaqueCall (core) stdcall', 'stdcall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 394; tail target 0x5095f0 hooked (GUESS); table entries are logging stubs')
