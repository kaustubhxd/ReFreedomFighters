"""specs_c1073.py - camera batch 1073: two ICF-shared bodies (0x549de0 returns true; 0x6368b0 calls the callback at 0x7003b0
when set; an unset one traps). The callback is a logging stub and is always set in the cases compared."""
from pilot import S
from camgen import rnd, Log


def _true(c):
    return [rnd(c, 0x40)]


def _cb(c):
    log = Log(c, 16)
    c.emu.hook(0x445330, lambda e, res: (log.put(0x445330), e.ret(argbytes=0)))
    c.emu.w32(0x7003b0, 0x445330)   # always set: an unset callback is an int3 trap in both builds (not compared)
    return [rnd(c, 0x40), rnd(c, 0x20)]


S(0x549de0, 'ZCAMERA::DisableParentBoundAdjust (ICF body, returns true)', 'thiscall', gen=_true)
S(0x6368b0, 'ZBaseCamera::GetCameraPosition (ICF body, callback)', 'thiscall', gen=_cb)
