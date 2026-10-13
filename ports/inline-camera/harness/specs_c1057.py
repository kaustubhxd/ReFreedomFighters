"""specs_c1057.py - camera batch 1057: CCameraBox::End (0x5c7d90) and CCameraBox::FrameUpdate (0x5c7da0).

The sized delete 0x634273 is hooked (logs its size only: the block address is a heap pointer). The object's
vtable slot 0x68 logs its two arguments."""
from pilot import S
from camgen import rnd, Log


def _end(c):
    log = Log(c, 64)
    c.emu.hook(0x634273, lambda e, res: (log.put(0x634273, e.arg32(1)), e.ret(argbytes=0)))
    self_ = rnd(c, 0x80)
    c.emu.w32(self_ + 0x4c, rnd(c, 0x20))
    return [self_]


def _frame(c):
    log = Log(c, 64)
    self_ = rnd(c, 0x80)
    c.emu.w32(self_, c.emu.fake_vtable('cambox', 0x6c // 4, {
        0x68: lambda e, res: (log.put(0x68, e.arg32(0), e.arg32(1)), e.ret(argbytes=8)),
    }))
    return [self_]


S(0x5c7d90, 'CCameraBox::End', 'thiscall', gen=_end)
S(0x5c7da0, 'CCameraBox::FrameUpdate', 'thiscall', gen=_frame)
