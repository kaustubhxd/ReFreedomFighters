"""specs_s1615.py - soundtimers batch 1615: GetMapping, FindMaterial, AddEvent."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook


def _maps(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    d = obj(c, 0x5400, {0x1b0: stub(c, seq, 3, ret=r.getrandbits(32))})
    b = rnd(c, 0x800, 16)
    c.emu.w32(b, 0x20)
    n = r.choice([0, 1, 3, 6, -1])
    c.emu.w32(b + 0x20 + 0x10, n & 0xffffffff)
    c.emu.w32(b + 0x20 + 0x28, 0x100)
    mats = [r.randint(1, 4) for _ in range(6)]
    fws = [r.randint(1, 3) for _ in range(6)]
    for i in range(max(n, 0)):
        m = 0x200 + 0x20 * i
        c.emu.w32(b + 0x100 + 4 * i, m)
        c.emu.w32(b + m + 0xc, mats[i])
        c.emu.w32(b + m + 0x10, fws[i])
    c.emu.w32(d + 0x5302, b if r.random() < 0.9 else 0)
    return d


def _mapping(c):
    d = _maps(c)
    r = c.rng
    return [d, r.choice([0, 1, 2, 3, 4]), r.choice([0, 1, 2, 3])]


S(0x537270, 'ZDllSound::GetMapping', 'thiscall', None, ret='eax', gen=_mapping, note='batch1615')


def _material(c):
    return [_maps(c), rnd(c, 8)]


S(0x536720, 'ZDllSound::FindMaterial', 'thiscall', None, ret='eax', gen=_material, note='batch1615')


def _event(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    ev = rnd(c, 0x20)
    hook(c, seq, 0x53a9e0, 0, ret=ev)
    db = obj(c, 0x80, {0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    d = rnd(c, 0x5400)
    c.emu.w32(d + 0x52fa, rnd(c, 0x10) if r.random() < 0.85 else 0)
    return [d, rnd(c, 0x10), rnd(c, 0xc), r.choice([0, 4, 0xc, r.getrandbits(32)]), r.getrandbits(32),
            r.getrandbits(32), r.getrandbits(32)]


S(0x534da0, 'ZDllSound::AddEvent', 'thiscall', None, ret='al', gen=_event, note='batch1615')
