"""specs_s972.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x482870 (src/batch972.cpp). Callees claimed elsewhere, hooked by address:
0x482800 (stdcall, one argument, callee-cleaned) and 0x4e1b30 (thiscall, no arguments). Recording stubs log the argument and ecx; both return 0."""
import serial_stubs as ss  # noqa: F401
from pilot import S


def _gen(c):
    def h482(em, r):
        c.emu.calllog.append(('482800', None, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h4e1(em, r):
        c.emu.calllog.append(('4e1b30', None, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x482800, h482)
    c.emu.hook(0x4e1b30, h4e1)
    return [c.rng.getrandbits(32)]


S(0x482870, 'wrapper over 0x482800 and 0x4e1b30 (unknown) stdcall', 'stdcall', None, ret=None, gen=_gen,
  note='unclaimed-80 gap band; callees 0x482800 (stdcall) and 0x4e1b30 hooked by address (claimed elsewhere)')
