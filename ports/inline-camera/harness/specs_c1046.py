"""specs_c1046.py - camera batch 1046: ZCAMERA::CopyData.

The fields are copied here; the original then tail-jumps through the destination's vtable slot 0x48 (the base
copy), which the spec stubs and logs by tag only (the source pointer differs between builds)."""
from pilot import S
from camgen import rnd, Log


def _copy(c):
    log = Log(c)

    def base_copy(e, res):
        log.put(0x48)
        e.ret(argbytes=4)

    dst = rnd(c, 0x200)
    src = rnd(c, 0x200)
    c.emu.w32(dst, c.emu.fake_vtable('dst', 0x4c // 4, {0x48: base_copy}))
    return [dst, src]


S(0x445750, 'ZCAMERA::CopyData', 'thiscall', gen=_copy)
