"""specs_s1204.py - pathfinding batch 1204: ZPathfinder3 wrappers."""
from pilot import S, F
from pfspec import rnd, hooks, reporter, RET


def _pf(c, packed_p=0.7):
    o = rnd(c, 0xa0)
    c.emu.w8(o + 0x31, 1 if c.rng.random() < packed_p else 0)
    return o


def _ret(c, addr):
    RET[addr] = c.rng.getrandbits(32) if c.rng.random() < 0.5 else c.rng.choice([0, 1, 0x100])


def _checkline(c):
    hooks(c.emu, {0x52e0a0: ('octCheckLine', 'this', 3)})
    _ret(c, 0x52e0a0)
    reporter(c)
    return [_pf(c), rnd(c, 12), rnd(c, 12), c.rng.getrandbits(32)]


S(0x52a800, 'ZPathfinder3::CheckLine', 'thiscall', None, ret='al', gen=_checkline)


def _checkpos(c):
    hooks(c.emu, {0x52e240: ('octCheckPosition', 'this', 1)})
    _ret(c, 0x52e240)
    reporter(c)
    return [_pf(c), rnd(c, 12)]


S(0x52aa90, 'ZPathfinder3::CheckPosition', 'thiscall', None, ret='al', gen=_checkpos)


def _vtobj(c, name, n=0x60, argwords=None):
    o = rnd(c, 0xa0)
    c.emu.w32(o, c.emu.logging_vtable(name, n, argwords=argwords or {}))
    return o


def _cmd(c):
    o = _vtobj(c, 'ZPathfinder3', argwords={0x16c: 2})
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x52aae0, 'ZPathfinder3::ClassCommand', 'thiscall', None, ret='eax', gen=_cmd)


def _msgs(c):
    e = c.emu
    mid = c.rng.getrandbits(32)
    m = e.alloc(16)
    e.w32(m, e.logging_vtable('msgtable', 0x50, impl={0x114: lambda em, a: (mid, None)}, argwords={0x114: 4}))
    sysi = rnd(c, 0xa0)
    e.w32(sysi + 0x9b, m)
    e.w32(0x70039c, sysi)


def _classinit(c):
    hooks(c.emu, {0x43e0f0: ('ZSTDOBJ::ClassInit', 'this', 0)})
    _msgs(c)
    return [_vtobj(c, 'ZPathfinder3', argwords={0x110: 2})]


S(0x52abc0, 'ZPathfinder3::ClassInit', 'thiscall', None, gen=_classinit)


def _links(c):
    log = {}
    hooks(c.emu, {0x530b60: ('GetLocalCoords', 'this', 2, {'fill': {0: 6}}),
                  0x530db0: ('GetLocalVector', 'this', 2, {'fill': {0: 6}}),
                  0x52e4f0: ('octEnableSpecialLinks', 'this', 3, {'peek': {0: 6, 1: 6}})})
    o = _pf(c)
    c.emu.w32(o + 0x65, c.rng.getrandbits(32))
    return [o, rnd(c, 12), rnd(c, 12), c.rng.getrandbits(32)]


S(0x52b020, 'ZPathfinder3::EnableSpecialLinks', 'thiscall', None, gen=_links)


def _nearest(c):
    hooks(c.emu, {0x52e670: ('octFindNearestPoint', 'this', 4)})
    _ret(c, 0x52e670)
    o = _pf(c)
    return [o, rnd(c, 12), F(c.fv()), F(c.fv()), F(c.fv())]


S(0x52b130, 'ZPathfinder3::FindNearestPoint', 'thiscall', None, ret='eax', gen=_nearest)


def _len(c):
    reporter(c)
    return [rnd(c, 0x10), rnd(c, 12), rnd(c, 12)]


S(0x52b330, 'ZPathfinder3::FindPathLength', 'thiscall', None, ret='st0', gen=_len)


def _load2(c):
    hooks(c.emu, {0x45f3a0: ('ZGEOM::Load2', 'this', 0), 0x52b9d0: ('ProcessAdditionalDoors', 'this', 0)})
    _msgs(c)
    return [rnd(c, 0xa0)]


S(0x52b3f0, 'ZPathfinder3::Load2', 'thiscall', None, gen=_load2)


def _load(c):
    hooks(c.emu, {0x45f3c0: ('ZGEOM::Load', 'this', 1), 0x52b430: ('CPathRequestQueue::Load', 'this', 1)})
    _ret(c, 0x45f3c0)
    return [rnd(c, 0xa0), _vtobj(c, 'ZLoadGame', argwords={0x48: 1})]


S(0x52b4a0, 'ZPathfinder3::Load', 'thiscall', None, ret='al', gen=_load)


def _save(c):
    hooks(c.emu, {0x45f960: ('ZGEOM::Save', 'this', 1)})
    _ret(c, 0x45f960)
    o = rnd(c, 0xa0)
    c.emu.w32(o + 0x79, rnd(c, 0x10))
    return [o, _vtobj(c, 'ZSaveGame', argwords={0x44: 1, 0x10: 2})]


S(0x52cb00, 'ZPathfinder3::Save', 'thiscall', None, ret='al', gen=_save)


def _req(c):
    hooks(c.emu, {0x52c270: ('RequestPathOld', 'this', 7)})
    _ret(c, 0x52c270)
    r = c.rng
    return [rnd(c, 0xa0), r.getrandbits(32), rnd(c, 12), rnd(c, 12), r.getrandbits(32), F(c.fv()),
            r.getrandbits(32), r.getrandbits(32)]


S(0x52c240, 'ZPathfinder3::RequestPath', 'thiscall', None, ret='eax', gen=_req)


def _dtor(c):
    hooks(c.emu, {0x52a600: ('~ZPathfinder3', 'this', 0), 0x45c510: ('ZGEOM::delete', 'cdecl', 1)})
    return [rnd(c, 0xa0), c.rng.choice([0, 1, 4, 5, c.rng.getrandbits(32)])]


S(0x52a6c0, 'ZPathfinder3::`scalar deleting destructor`', 'thiscall', None, ret='eax', gen=_dtor)


def _odtor(c):
    hooks(c.emu, {0x52d080: ('~ZPFOctree_packed', 'this', 0), 0x634273: ('delete', 'cdecl', 2)})
    return [rnd(c, 0xa0), c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


S(0x52d190, 'ZPFOctree_packed::`scalar deleting destructor`', 'thiscall', None, ret='eax', gen=_odtor)
