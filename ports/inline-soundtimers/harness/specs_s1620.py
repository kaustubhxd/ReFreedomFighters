"""specs_s1620.py - soundtimers batch 1620: FreeObject, DeleteSnd, DeleteSoundPtr, sound object delete, ActorRemove."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook
from specs_s1617 import _mgr


def _free(c):
    seq = Seq(c)
    m = _mgr(c, seq)
    if not c.emu.r32(m):
        g0 = obj(c, 0x20, {})
        c.emu.w32(g0 + 0x10, 0xf)
        c.emu.w32(m, g0)
    g = c.emu.r32(m)
    vt = c.emu.r32(g)
    nvt = c.emu.alloc(0x20, 4)
    for off in (4, 0x14):
        c.emu.w32(nvt + off, c.emu.r32(vt + off) if vt else 0)
    c.emu.w32(nvt + 0x10, stub(c, seq, 1, ret=(c.rng.getrandbits(24) << 8) | c.rng.choice([0, 1, 1])))
    c.emu.w32(g, nvt)
    mask = c.emu.r32(g + 0x10)
    h = c.rng.getrandbits(32)
    tbl = c.emu.r32(m + 4)
    c.emu.w32(tbl + 4 * (h & mask), c.rng.randint(0, 15))
    return [m, h]


S(0x534090, 'ZSoundObjectManager::FreeObject', 'thiscall', None, ret=None, gen=_free, note='batch1620')


def _delsnd(c):
    m, h = _free(c)
    d = c.emu.alloc(0x8b + 0x1020, 4)
    c.emu.wbytes(d + 0x8b, c.emu.rbytes(m, 0x1014))
    return [d, h]


S(0x5331c0, 'ZDllSound::DeleteSnd', 'thiscall', None, ret=None, gen=_delsnd, note='batch1620')


def _delptr(c):
    seq = Seq(c)
    clear_hooks(c)
    d = obj(c, 0x40, {0x114: stub(c, seq, 1)})
    return [d, rnd(c, 0x20) if c.rng.random() < 0.85 else 0]


S(0x5331d0, 'ZDllSound::DeleteSoundPtr', 'thiscall', None, ret=None, gen=_delptr, note='batch1620')


def _del(c):
    seq = Seq(c)
    clear_hooks(c)
    d = obj(c, 0x200, {0x118: stub(c, seq, 1)})
    sysobj(c, extra={0x1a9f: d if c.rng.random() < 0.85 else 0})
    return [rnd(c, 0x20)]


S(0x44b740, 'ZSoundObject delete (cdecl)', 'cdecl', None, ret=None, gen=_del, note='batch1620')


def _rm(c):
    seq = Seq(c)
    clear_hooks(c)
    hook(c, seq, 0x53b1b0, 1)
    d = rnd(c, 0x5400)
    c.emu.w32(d + 0x52fa, rnd(c, 0x20) if c.rng.random() < 0.8 else 0)
    return [d, c.rng.getrandbits(32)]


S(0x534d80, 'ZDllSound::ActorRemove', 'thiscall', None, ret=None, gen=_rm, note='batch1620')
