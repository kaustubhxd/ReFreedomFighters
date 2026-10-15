"""specs_s919.py - vehicles batch 919: damper physics and CUnderCarriageTank::DynamicsFrameUpdate."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def blk(c, n, offs, lo=-10, hi=10):
    o = _rnd(c, n)
    for off in offs:
        c.emu.w32(o + off, rf(c, lo, hi))
    return o


PULL = (0, 4, 8, 0xc, 0x10)
S(0x524370, 'pull near ground (inferred)', 'thiscall', ret='al', gen=lambda c: [blk(c, 0x20, PULL)])
S(0x524540, 'pull Verlet step (inferred)', 'thiscall', gen=lambda c: [blk(c, 0x20, PULL), rf(c, 0, 0.01)])
S(0x5245c0, 'pull Verlet step with ground (inferred)', 'thiscall', gen=lambda c: [blk(c, 0x20, PULL), rf(c, 0, 0.01)])


def g_spring(c):
    s = blk(c, 0x40, (0, 4, 8, 0xc, 0x10, 0x14))
    a, b = blk(c, 0x20, PULL), blk(c, 0x20, PULL)
    if c.rng.random() < 0.1:
        c.emu.w32(b, c.emu.r32(a))
    c.emu.w32(s + 0x18, a)
    c.emu.w32(s + 0x1c, b)
    return [s, rf(c, 0.001, 0.01)]


S(0x5246a0, 'damper spring step (inferred)', 'thiscall', ret='st0', gen=g_spring)

DF = (0xc, 0x11, 0x15, 0x19, 0x1d, 0x21, 0x25, 0x29, 0x2d, 0x31, 0x35, 0x41, 0x45, 0x49, 0x4d, 0x51, 0x55, 0x59,
      0x5d, 0x61, 0x65)


def damper(c, d):
    for off in DF:
        c.emu.w32(d + off, rf(c, -10, 10))
    c.emu.w32(d + 0x15, rf(c, -5, 0))
    c.emu.w32(d + 0x19, rf(c, 0, 5))
    c.emu.w32(d + 0x21 + 0x18, d + 0x41)
    c.emu.w32(d + 0x21 + 0x1c, d + 0x55)


def g_ds(c):
    d = _rnd(c, 0xe0)
    damper(c, d)
    return [d, rf(c, 0.001, 0.01)]


S(0x516070, 'CDamper physics step (inferred)', 'thiscall', gen=g_ds)


def uc(c):
    o = _rnd(c, 0x2400)
    a, b = c.rng.randint(0, 4), c.rng.randint(0, 4)
    c.emu.w32(o + 0x8d, a)
    c.emu.w32(o + 0x91, b)
    for base, n in ((0x95, a), (0x785, b)):
        for i in range(n):
            damper(c, o + base + i * 0xde)
    c.emu.w32(o + 0x21b5, rf(c, 0.001, 0.01))
    for k in range(0x60 // 4):
        c.emu.w32(o + 4 * k, rf(c, -1, 1))
    for off in (0x21b9, 0x21bd):
        c.emu.w32(o + off, rf(c, 50, 400))
    return o


S(0x527b30, 'CUnderCarriageTank physics step (inferred)', 'thiscall', gen=lambda c: [uc(c)])


def g_dyn(c):
    s = _rnd(c, 0x200)
    c.emu.w32(s + 0x40, c.rng.randint(0, 1 << 20))
    c.emu.w32(s + 0x48, rf(c, 0, 0.1))
    c.emu.w32(0x70039c, s)
    o = uc(c)
    c.emu.wf32(o + 0x48, (c.emu.r32(s + 0x40) - c.rng.randint(-20, 200)) / 1024.0)
    return [o]


S(0x527bd0, 'CUnderCarriageTank::DynamicsFrameUpdate', 'thiscall', gen=g_dyn)
