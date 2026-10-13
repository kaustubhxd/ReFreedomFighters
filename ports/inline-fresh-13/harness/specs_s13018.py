"""specs_s13018.py - fresh-13 batch 18: 0x45a810 ZPICOBJ::GetSysMemPixInterpolated(const float*, int, int*). Thiscall,
ret 0xc. Mip object (this+0x33) slot 0x30 (1 arg, logged) returns the image for level + 1 and the palette for 0.
Image: width / height s16 in {1, 2, 3, 5, 8, 0, -3} with random u32 pixels, 64 bytes of padding before it (clamping
can index -1). uv floats in [-0.2, 1.2] (and exact edges). Bit depth +0x2f in {0x100, 0xff, 0x20, 0x1000, -1}.
Blend slot 0x220 (3 args, float bits logged) returns a mix of its arguments; slot 0x228 (8 args: pixels, x, y, width
logged, four byte pointers written with per-call random indices, never logged). The assert hook 0x7003b0 is a logged
stub. out is 0 or a heap buffer."""
import struct
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=16, width=6)
    w = r.choice([1, 2, 3, 5, 8, 8, 0, -3])
    h = r.choice([1, 2, 3, 5, 8, 8, 0, -3])
    n = max(w, 1) * max(h, 1) + 8
    buf = rnd(c, 64 + 4 + 4 * n + 64)
    img = buf + 64
    c.emu.w16(img, w)
    c.emu.w16(img + 2, h)
    pal = rnd(c, 0x400)

    def _mip(e):
        return img if e.r32(e.reg('esp') + 4) else pal
    mip = vobj(c, 0x40, {0x30: logstub(c, log, 1, 1, ret=_mip)})
    idx = [r.getrandbits(8) for _ in range(4)]

    def _idx(e, rr):
        sp = e.reg('esp')
        log.put(e, [2, e.r32(sp + 4), e.r32(sp + 8), e.r32(sp + 12), e.r32(sp + 16)])
        for k in range(4):
            e.wbytes(e.r32(sp + 20 + 4 * k), bytes([idx[k]]))
        e.ret(eax=0, argbytes=32)
    a228 = c.emu.alloc(16, 16)
    c.emu.wbytes(a228, b'\xc3' * 16)
    HOOKED.add(a228)
    c.emu.hook(a228, _idx)

    def _bl(e):
        sp = e.reg('esp')
        a, b, t = e.r32(sp + 4), e.r32(sp + 8), e.r32(sp + 12)
        return (a * 3 + b * 5 + t) & 0xffffffff
    me = vobj(c, 0x40, {0x220: logstub(c, log, 3, 3, ret=_bl), 0x228: a228})
    c.emu.w32(me + 0x33, mip)
    c.emu.w32(me + 0x2f, r.choice([0x100, 0xff, 0x20, 0x1000, 0xffffffff]))
    c.emu.w32(0x7003b0, logstub(c, log, 0, 4, this=False))
    uv = c.emu.alloc(8, 4)
    for k in range(2):
        c.emu.wf32(uv + 4 * k, r.choice([r.uniform(-0.2, 1.2), r.uniform(0, 1), 0.0, 1.0, 0.5, 0.999]))
    out = r.choice([0, rnd(c, 8)])
    flush(c)
    return [me, uv, r.getrandbits(32), out]


S(0x45a810, 'ZPICOBJ::GetSysMemPixInterpolated', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13018; mip / blend / index slots logged; assert hook logged')
