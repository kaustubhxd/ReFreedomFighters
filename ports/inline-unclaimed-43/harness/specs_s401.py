"""specs_s401.py - gap band parked row 0x41f1d0 (thiscall, no arguments). It picks the object at this + 0x31 + 4 * dword[this+0x45]
and tail-jumps to 0x4d1100 (exe thiscall, no arguments; hooked by address and logged: GUESS, body not ported). The hook returns
a random al drawn in gen. The index is 0..3 and the four object pointers are logging blocks."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'al': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup(c):
    def h(em, r):
        em.calllog.append(('checkallfreed', 0, em.reg('ecx') & 0xffffffff, ()))
        em.ret(eax=SHARED['al'], argbytes=0)
    c.emu.hook(0x4d1100, h)


def _gen(c):
    r = c.rng
    SHARED['al'] = r.choice([0, 1])
    o = E.zero_obj(c, 0x80)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x80)))
    idx = r.randint(0, 3)
    c.emu.w32(o + 0x45, idx)
    for k in range(4):
        blk = E.zero_obj(c, 0x20)
        c.emu.w32(o + 0x31 + 4 * k, blk)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x41f1d0, 'forward to CheckAllFreed (gap band parked) thiscall', 'thiscall', None, ret='al', gen=_gen, setup=_setup,
  note='gap band parked row, ported with 0x4d1100 hooked (GUESS)')
