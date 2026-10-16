"""specs_s521.py - weapons batch 521: ZItemWeapon members and ZLNKWHANDS::GetAimAnim."""
from pilot import S
from wkit import rnd, stub, obj, b, patch_jmp, vec, sysobj


def _geomref(c):
    g = rnd(c, 0x100)
    for o in range(0, 0x100, 4):
        c.emu.wf32(g + o, c.rng.uniform(-5, 5))
    h = rnd(c, 0x20)
    c.emu.w32(h + 8, g)
    return h


def _w(c, extra=None):
    t = rnd(c, 0x200)
    c.emu.w32(t + 0x11b, _geomref(c))
    sl = {0x350: stub(c, 0, ret=t), 0x348: stub(c, 0, ret=_geomref(c)),
          0x2c4: stub(c, 2, skip=(0, 1), fills=((0, vec(c, 9, -1, 1), 9), (1, vec(c, 3, -50, 50), 3)))}
    if extra:
        sl.update(extra)
    return obj(c, 0x200, sl), t


def _plain(c):
    return [_w(c)[0]]


def _firepos(c):
    return [_w(c)[0], rnd(c, 0x30), rnd(c, 0x10)]


def _rootmuzzle(c):
    return [_w(c)[0], rnd(c, 0x10)]


def _verify(c):
    r = c.rng
    if r.random() < 0.15:
        return [rnd(c, 0x10), 0]
    ci = rnd(c, 0x40)
    c.emu.w32(ci + 0x23, r.choice((0x1007d4, 0x1007d3, r.getrandbits(32))))
    t = rnd(c, 0x20)
    c.emu.w32(t + 0xc, ci)
    return [rnd(c, 0x10), t]


def _destroy(c):
    t = obj(c, 0x40, {0x31c: stub(c, 1)})
    return [obj(c, 0x100, {0x350: stub(c, 0, ret=t)})]


def _copy(c):
    patch_jmp(c, 0x43f8c0, stub(c, 1, rec_ecx=True))
    o = obj(c, 0x100, {0x1e0: stub(c, 1, ret=b(c, 0.4))})
    return [rnd(c, 0x100), o]


def _sounds(c):
    r = c.rng
    tab = obj(c, 0x80, {0x60: stub(c, 2, ret=r.getrandbits(32))})
    so = rnd(c, 0x1b00)
    c.emu.w32(so + 0x1a9f, 0 if r.random() < 0.2 else tab)
    c.emu.w32(0x70039c, so)
    t = obj(c, 0x40, {0x378: stub(c, 0, ret=0 if r.random() < 0.2 else r.getrandbits(32))})
    return [obj(c, 0x100, {0x350: stub(c, 0, ret=t)})]


def _aimanim(c):
    r = c.rng
    def wpn(ty):
        t = obj(c, 0x40, {0x330: stub(c, 0, ret=ty)})
        return obj(c, 0x40, {0x350: stub(c, 0, ret=t)})
    ty = r.choice(list(range(13)) + [99])
    w = 0 if r.random() < 0.1 else wpn(ty)
    l = 0 if r.random() < 0.3 else wpn(r.choice((ty, ty, 0, 1, 5)))
    return [obj(c, 0x400, {0x50c: stub(c, 0, ret=w), 0x508: stub(c, 0, ret=l)})]


S(0x46eab0, 'ZItemWeapon::GetMuzzleExitPos', 'thiscall', None, ret='eax', gen=_plain)
S(0x46e6d0, 'ZItemWeapon::GetFirePosition', 'thiscall', None, ret=None, gen=_firepos)
S(0x46ee50, 'ZItemWeapon::GetRootMuzzleExitPos', 'thiscall', None, ret=None, gen=_rootmuzzle)
S(0x471aa0, 'ZItemWeapon::VerifyItemTemplate', 'thiscall', None, ret='al', gen=_verify)
S(0x46d6e0, 'ZItemWeapon::DestroyItem', 'thiscall', None, ret=None, gen=_destroy)
S(0x46cd60, 'ZItemWeapon::CopyData', 'thiscall', None, ret=None, gen=_copy)
S(0x46f240, 'ZItemWeapon::InitSounds', 'thiscall', None, ret=None, gen=_sounds)
S(0x473e50, 'ZLNKWHANDS::GetAimAnim', 'thiscall', None, ret='eax', gen=_aimanim)
