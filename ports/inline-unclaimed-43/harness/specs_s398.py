"""specs_s398.py - core batch 398: 0x4a6060 ZRequireMatPosSpeed::Init (thiscall, two stack arguments, ret 8). The first
argument is unused; the second is the object passed as ECX to the reader. The reader 0x4e6180 is hooked by address and logged
(GUESS: a float reader; the hook writes a deterministic float to its destination so the result depends on it). 0x4e0d00 is
exe code, run as is (it scales the three floats at its ECX object). The record holds finite random floats in [-8, 8]."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _setup(c):
    def h(em, r):
        dst = em.arg32(0)
        val = float((dst >> 4) & 0xff) / 16.0
        em.calllog.append(('read4e6180', 0, em.reg('ecx') & 0xffffffff, (dst & 0xffff,)))
        em.mu.mem_write(dst, struct.pack('<f', val))
        em.ret(eax=1, argbytes=4)
    c.emu.hook(0x4e6180, h)


def _gen(c):
    r = c.rng
    self_ = E.zero_obj(c, 0x100)
    c.emu.wbytes(self_, struct.pack('<24f', *[r.uniform(-8.0, 8.0) for _ in range(24)]))
    obj = E.zero_obj(c, 0x40)
    c.emu.mu.ctl_flush_tb()
    return [self_, r.getrandbits(32), obj]


S(0x4a6060, 'ZRequireMatPosSpeed::Init (core) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 398; reader 0x4e6180 hooked (GUESS); 0x4e0d00 is exe code')
