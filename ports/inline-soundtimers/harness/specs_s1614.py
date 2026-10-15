"""specs_s1614.py - soundtimers batch 1614: small ZDllSound helpers (records in a fake sound-data block)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _block(c):
    """Sound data: a wave at 0x40, a sound (type 2 -> wave) at 0x80, a set (type 3) at 0xc0, junk at 0x100."""
    r = c.rng
    b = rnd(c, 0x400, 16)
    c.emu.w32(b + 0x40, 1)
    c.emu.w32(b + 0x44, r.choice([0x200, 0]))
    c.emu.w32(b + 0x48, r.getrandbits(32))
    c.emu.w32(b + 0x80, 2)
    c.emu.w32(b + 0x84, r.choice([0x210, 0]))
    c.emu.w32(b + 0x88, r.choice([0x40, 0]))
    c.emu.w32(b + 0xc0, 3)
    n = r.randint(1, 8)
    c.emu.w16(b + 0xc8, n)
    c.emu.w32(b + 0xd0, 0x300)
    return b


def _dll(c, seq, slots=None):
    r = c.rng
    clear_hooks(c)
    d = obj(c, 0x5400, slots or {})
    b = _block(c)
    c.emu.w32(d + 0x5302, b if r.random() < 0.9 else 0)
    return d, b


def _id(c):
    return c.rng.choice([0, 0x40, 0x80, 0xc0, 0x100, 0x40, 0x80])


def _simple(c):
    seq = Seq(c)
    d, b = _dll(c, seq)
    return [d, _id(c)]


def _rec(c):
    seq = Seq(c)
    d, b = _dll(c, seq)
    k = c.rng.choice([0, 0x40, 0x80, 0xc0, 0x100])
    return [d, (b + k) if (k and b) else (rnd(c, 0x10) if k else 0)]


S(0x537770, 'ZDllSound::GetSoundObject', 'thiscall', None, ret='eax', gen=_simple, note='batch1614')
S(0x537e40, 'ZDllSound::IsWave', 'thiscall', None, ret='al', gen=_simple, note='batch1614')
S(0x537310, 'ZDllSound::GetName', 'thiscall', None, ret='eax', gen=_rec, note='batch1614')
S(0x537790, 'ZDllSound::GetWave', 'thiscall', None, ret='eax', gen=_rec, note='batch1614')


def _mono(c):
    seq = Seq(c)
    r = c.rng
    w = rnd(c, 0x10)
    s = rnd(c, 0x10)
    d, b = _dll(c, seq, {0x40: stub(c, seq, 1, ret=s if r.random() < 0.85 else 0),
                         0x1dc: stub(c, seq, 1, ret=w if r.random() < 0.85 else 0)})
    return [d, r.getrandbits(32)]


S(0x537e00, 'ZDllSound::IsPlayingMono', 'thiscall', None, ret='al', gen=_mono, note='batch1614')


def _random(c):
    seq = Seq(c)
    r = c.rng
    d, b = _dll(c, seq)
    f = c.emu.alloc(4, 4)
    c.emu.wf32(f, r.choice([0.0, 0.999999, 0.5, 0.01, r.random()]))
    s = obj(c, 0x100, {0x1c0: stub(c, seq, 2, fld=f)})
    c.emu.w32(0x70039c, s)
    return [d, (b + 0xc0) if b else rnd(c, 0x20)]


S(0x537370, 'ZDllSound::GetRandomFromSoundSet', 'thiscall', None, ret='eax', gen=_random, note='batch1614')


def _reg(c):
    seq = Seq(c)
    r = c.rng
    d, b = _dll(c, seq)
    hook(c, seq, 0x53a910, 1)
    c.emu.w32(d + 0x52fa, rnd(c, 0x20) if r.random() < 0.8 else 0)
    return [d, r.getrandbits(32)]


S(0x534d60, 'ZDllSound::ActorRegister', 'thiscall', None, ret=None, gen=_reg, note='batch1614')


def _getsound(c):
    seq = Seq(c)
    r = c.rng
    d, b = _dll(c, seq)
    if b:
        c.emu.w32(b, 0x20)
        c.emu.w32(b + 0x20, r.choice([0, 1]) if r.random() < 0.2 else 1)
        c.emu.w32(b + 0x24, 0 if r.random() < 0.3 else 5)
        n = c.emu.r32(b + 0xc8) & 0xffff
        for i in range(n):
            c.emu.w32(b + 0x300 + 4 * i, r.choice([0x40, 0x80]))   # waves and sounds only (no sets: a set member would loop or read garbage)
        c.emu.w32(b + 0x100, 5)
        c.emu.w32(b + 0x108, r.choice([0x40, 0x80, 0xc0, 0x140]))
        c.emu.w32(b + 0x140, 3)
        c.emu.w16(b + 0x148, 2)          # the set at 0x140 has two members (no empty set: an empty set reads garbage)
        c.emu.w32(b + 0x150, 0x300)      # its member table
        c.emu.w32(b + 0x300, 0x40)
        c.emu.w32(b + 0x304, 0x80)
        c.emu.w32(b + 0x180, r.choice([4, 6, 16, 0, 17]))
    f = c.emu.alloc(4, 4)
    c.emu.wf32(f, r.random() * 0.999)
    s = obj(c, 0x100, {0x1c0: stub(c, seq, 2, fld=f)})
    c.emu.w32(0x70039c, s)
    return [d, r.choice([0, 0x40, 0x80, 0xc0, 0x100, 0x140, 0x180])]


S(0x537400, 'ZDllSound::GetSound', 'thiscall', None, ret='eax', gen=_getsound, note='batch1614')
