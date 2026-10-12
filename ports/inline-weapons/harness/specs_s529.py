"""specs_s529.py - weapons batch 529: VerifyMat (0x4e2d60). Logger stubs record the message and length."""
from pilot import S
from wkit import rnd, stub, obj, sysobj


def _vm(c):
    r = c.rng
    lg = obj(c, 0x40, {0x2c: stub(c, 4, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=lg)})
    c.emu.w32(0x700390, l)
    o = rnd(c, 0x40)
    x = r.random()
    if x < 0.5:   # near-orthonormal frame (no warnings) with small noise
        import math
        ang = r.uniform(0, 6.28)
        cols = [(math.cos(ang), math.sin(ang), 0.0), (-math.sin(ang), math.cos(ang), 0.0), (0.0, 0.0, 1.0)]
        for ci, base in enumerate((0x0, 0xc, 0x18)):
            for j in range(3):
                pass
        # column C = (M0,M4,M8), column B = (M0c,M10,M14), column A = (M18,M1c,M20)
        mats = {0x0: cols[0], 0xc: cols[1], 0x18: cols[2]}
        for base, v in mats.items():
            for j in range(3):
                c.emu.wf32(o + base + 4 * j, v[j] + r.uniform(-1e-5, 1e-5) if r.random() < 0.9 else v[j] + r.uniform(-0.01, 0.01))
    else:
        for j in range(0x40 // 4):
            c.emu.wf32(o + 4 * j, r.uniform(-1.5, 1.5))
    return [o]


S(0x4e2d60, 'VerifyMat', 'thiscall', None, ret='al', gen=_vm)
