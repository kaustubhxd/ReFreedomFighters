"""specs_s1505.py - recruits thread batch 1505: ZGameOSD::CommandAllRecruits / CommandOneRecruit.
CommandRecruit, IsRecruited, RemoveRecruit and FindCurrentRecruit are recorders; round(float) runs as exe code; the
engine random (system slot 0x1c0) returns a fixed float per case on the x87 stack."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks, sysobj


def _osd(c):
    r = c.rng
    hook_rec(c, 0x597050, 3, this=True)
    hook_rec(c, 0x597a70, 1, ret=lambda e, k: r.choice([0, 1, 0x100]), this=True)
    hook_rec(c, 0x597e00, 1, this=True)
    so = sysobj(c, rand=r.choice([0.0, 0.999, r.random(), 0.5, r.random()]))
    c.emu.w32(so + 0x1b5d, r.choice([0, 1, 2]))
    s = rnd(c, 0x2400)
    n = r.choice([0, r.randint(1, 10)])
    c.emu.w32(s + 0x1fae, n)
    pool = [r.getrandbits(32) for _ in range(6)]
    for i in range(n):
        c.emu.w32(s + 0x1dae + 4 * i, r.choice(pool))
    c.emu.w32(s + 0x1fb2, r.randint(0, max(n - 1, 0)))
    m = r.choice([0, 0, r.randint(1, 5), -1])
    c.emu.w32(s + 0x2e6, m & 0xffffffff)
    for i in range(max(m, 0)):
        c.emu.w32(s + 0xe6 + 4 * i, r.choice(pool))
    n_ = n
    hook_rec(c, 0x597680, 2, ret=r.choice([-1] + list(range(max(n_, 1)))) & 0xffffffff, this=True)
    cmd = r.choice([0, 3, 4, 5, 5, r.getrandbits(32)])
    dis = r.getrandbits(32)
    if r.random() < 0.5:
        dis &= 0xffffff00
    return [s, cmd, dis]


def _gen(c):
    clear_hooks(c)
    return _osd(c)


S(0x596d70, 'ZGameOSD::CommandAllRecruits', 'thiscall', gen=_gen, note='batch1505')
S(0x596ef0, 'ZGameOSD::CommandOneRecruit', 'thiscall', gen=_gen, note='batch1505')
