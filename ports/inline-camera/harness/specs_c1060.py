"""specs_c1060.py - camera batch 1060: CCameraBox::Load2 (0x4cb110): virtual slot 0x64 with 0x10."""
from pilot import S
from camgen import rnd, Log


def _load2(c):
    log = Log(c, 32)
    self_ = rnd(c, 0x80)
    c.emu.w32(self_, c.emu.fake_vtable('cambox', 0x68 // 4 + 1, {
        0x64: lambda e, res: (log.put(0x64, e.arg32(0)), e.ret(argbytes=4)),
    }))
    return [self_]


S(0x4cb110, 'CCameraBox::Load2', 'thiscall', gen=_load2)
