"""specs_c1075.py - camera batch 1075: ZCameraOverlay::CopyData (0x458300). The source's slot 0x1e0 gives the answer (a fixed
function of the argument, chosen in the generator)."""
from pilot import S
from camgen import rnd


def _copy(c):
    r = c.rng
    yes = r.random() < 0.7
    src = rnd(c, 0x100)
    c.emu.w32(src, c.emu.fake_vtable('zgeom', 0x1e4 // 4, {
        0x1e0: lambda e, res: (e.ret(eax=1 if yes else 0, argbytes=4)),
    }))
    dst = rnd(c, 0x100)
    return [dst, src]


S(0x458300, 'ZCameraOverlay::CopyData', 'thiscall', gen=_copy)
