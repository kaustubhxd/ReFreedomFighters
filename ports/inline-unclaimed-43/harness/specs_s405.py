"""specs_s405.py - gap band parked row 0x41eab0 (thiscall, one stack argument, ret 4; the forwarder returns the target's eax).
The object at this+0x31 is a logging block. The target 0x4d0100 (exe thiscall, one argument, ret 4) is hooked by address and
logged (GUESS: body not ported); it returns a dword drawn in gen."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'ret': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup(c):
    def h(em, r):
        em.calllog.append(('target4d0100', 0, em.reg('ecx') & 0xffffffff, (_nostack(em.arg32(0)),)))
        em.ret(eax=SHARED['ret'], argbytes=4)
    c.emu.hook(0x4d0100, h)


def _gen(c):
    r = c.rng
    SHARED['ret'] = r.getrandbits(32)
    o = E.zero_obj(c, 0x80)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x80)))
    blk = E.zero_obj(c, 0x40)
    c.emu.w32(o + 0x31, blk)
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


S(0x41eab0, 'forward to 0x4d0100 (gap band parked) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band parked row; target 0x4d0100 hooked (GUESS)')
