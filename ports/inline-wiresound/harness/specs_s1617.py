"""specs_s1617.py - soundtimers batch 1617: sound object handles (pool manager)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _mgr(c, seq, newh=0):
    r = c.rng
    clear_hooks(c)
    mask = r.choice([0xff, 0x3ff, 0xf])
    gen = obj(c, 0x20, {4: stub(c, seq, 0, ret=newh), 0x14: stub(c, seq, 1, ret=(r.getrandbits(24) << 8) | r.choice([0, 1, 1]))})
    c.emu.w32(gen + 0x10, mask)
    m = c.emu.alloc(0x1020, 4)
    c.emu.w32(m, gen if r.random() < 0.95 else 0)
    tbl = c.emu.alloc(4 * (mask + 1), 4)
    for i in range(mask + 1):
        c.emu.w32(tbl + 4 * i, r.choice([0xffffffff, r.randint(0, 15)]))
    c.emu.w32(m + 4, tbl)
    c.emu.w32(m + 8, rnd(c, 0xfd * 16 + 0x10))
    for i in range(16):
        c.emu.w32(m + 0xc + 4 * i, r.randint(0, 15))
    c.emu.w32(m + 0x1010, r.randint(0, 15))
    c.emu.w32(m + 0x100c, r.choice([0, 5, 0x3ff, 0x400]))
    ch = obj(c, 0x40, {0x2c: stub(c, seq, 3, pop=False)})
    lg = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, lg)
    return m


def _alloc(c):
    seq = Seq(c)
    m = _mgr(c, seq, newh=c.rng.getrandbits(32))
    if not c.emu.r32(m):
        c.emu.w32(m, obj(c, 0x20, {4: stub(c, seq, 0, ret=c.rng.getrandbits(32))}))
        c.emu.w32(c.emu.r32(m) + 0x10, 0xff)
        c.emu.w32(m + 4, c.emu.alloc(0x400, 4))
    return [m]


S(0x533e00, 'ZSoundObjectManager::AllocateObject', 'thiscall', None, ret='eax', gen=_alloc, note='batch1617')


def _conv(c):
    seq = Seq(c)
    m = _mgr(c, seq)
    return [m, c.rng.choice([0, c.rng.getrandbits(32), c.rng.randint(1, 0x3ff)])]


S(0x533fc0, 'ZSoundObjectManager::ConvRefToPtr', 'thiscall', None, ret='eax', gen=_conv, note='batch1617')


def _sref(c):
    seq = Seq(c)
    m = _mgr(c, seq)
    d = c.emu.alloc(0x8b + 0x1020, 4)
    c.emu.wbytes(d + 0x8b, c.emu.rbytes(m, 0x1014))
    return [d, c.rng.choice([0, c.rng.getrandbits(32), c.rng.randint(1, 0x3ff)])]


S(0x533be0, 'ZDllSound::SRefToPtr', 'thiscall', None, ret='eax', gen=_sref, note='batch1617')
