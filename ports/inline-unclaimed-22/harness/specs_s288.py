"""specs_s288.py - area 22, batch288 (src/batch288.cpp): eleven small residue-1 functions. Exe callees are hooked by
address and log ecx and their stack words (operator new 0x41e290 and sized delete 0x634273 are verified elsewhere; the
others are GUESS hooks); vtable slots are Python handlers that log ecx and their arguments. sprintf 0x42ac56 is hooked
(logs the destination, the format address and the argument)."""
from pilot import S
from helpers22 import _rnd, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _vt(c, slots):
    """slots = {off: (nargs, eax)}; eax may be a callable. Each call logs (slot, ecx, args)."""
    hs = {}
    for off, (n, eax) in slots.items():
        def h(em, r, off=off, n=n, eax=eax):
            em.calllog.append(('vt%x' % off, 0, em.reg('ecx'), tuple(em.arg32(k) for k in range(n))))
            em.ret(eax=eax(em) if callable(eax) else eax, argbytes=4 * n)
        hs[off] = h
    return _pyvt(c, hs)


def _obj(c, slots, n=8):
    o = _rnd(c, n)
    c.emu.w32(o, _vt(c, slots))
    return o


def _g_658110(c):
    _hk(c, 0x64f760, '64f760', 0)
    _hk(c, 0x41e290, 'new', 1, eax=_r(c), pop=0)
    return [_rnd(c, 0x1190)]


S(0x658110, 'ZRenderGC::AllocateDrawBuffers', 'thiscall', 0, ret=None, gen=_g_658110, note='batch288; void')


def _g_5ffb50(c):
    nxt = 0
    for _ in range(c.rng.choice([1, 1, 2, 3, 4])):
        o = _rnd(c, 0xa0)
        c.emu.w32(o + 0x9c, nxt)
        nxt = o
    return [nxt]


S(0x5ffb50, 'VMImageInfo_t::getDataSegSize', 'thiscall', 0, ret='u32', gen=_g_5ffb50, note='batch288; recursive chain')


def _g_57ad10(c):
    _hk(c, 0x610100, '610100', 1)
    _hk(c, 0x4e5e60, '4e5e60', 0, eax=_r(c))
    return [_rnd(c, 0x190), _rnd(c, 8)]


S(0x57ad10, 'ZFFSetStartZone::CopyEventDataBlock', 'thiscall', 1, ret=None, gen=_g_57ad10, note='batch288; void')


def _g_4cd390(c):
    _hk(c, 0x4cd050, '4cd050', 0, eax=_r(c))
    _hk(c, 0x634273, 'delete', 2, eax=_r(c), pop=0)
    return [_rnd(c, 0x20), _r(c)]


S(0x4cd390, 'STATICREFTAB scalar deleting dtor', 'thiscall', 1, ret='u32', gen=_g_4cd390, note='batch288')


def _g_54c2d0(c):
    s = _rnd(c, 0x54)
    c.emu.w32(s + 0x50, 0 if c.rng.random() < 0.3 else _obj(c, {0x1c: (1, _r(c))}))
    return [s, _r(c)]


S(0x54c2d0, 'forward vt 0x1c(float)', 'thiscall', 1, ret='al', gen=_g_54c2d0, note='batch288')


def _g_650cd0(c):
    s = _rnd(c, 0xc4)
    c.emu.w32(s + 0xbd, _obj(c, {0x64: (0, _r(c))}))
    return [s, _obj(c, {0x78: (1, _r(c))})]


S(0x650cd0, 'ZRenderGC::Save', 'thiscall', 1, ret='al', gen=_g_650cd0, note='batch288')


def _g_4d42d0(c):
    _hk(c, 0x42ac56, 'sprintf', 3, eax=_r(c), pop=0)
    s = _rnd(c, 0x1010)
    c.emu.w32(s, _vt(c, {0x1c: (0, _r(c))}))
    return [s, _r(c)]


S(0x4d42d0, 'format name, vt 0x1c', 'thiscall', 1, ret=None, gen=_g_4d42d0, note='batch288; void; sprintf hooked')


def _g_656e50(c):
    objs = {}

    def get(em):
        k = em.arg32(0)
        if k not in objs:
            objs[k] = _rnd(c, 0x24)
        return objs[k]
    s = _rnd(c, 8)
    c.emu.w32(s, _vt(c, {0xc: (1, get)}))
    a = _r(c)
    return [s, a, a if c.rng.random() < 0.15 else _r(c)]


S(0x656e50, 'ZPrimControlGC::CopyPrimDrawMode', 'thiscall', 2, ret=None, gen=_g_656e50, note='batch288; void')


def _g_64ff10(c):
    _hk(c, 0x644820, '644820', 0, eax=_r(c))
    rm = _rnd(c, 0x1914)
    c.emu.w32(rm + 0x190f, _obj(c, {0x1b0: (1, _r(c))}))
    c.emu.w32(0x70039c, rm)
    s = _rnd(c, 0x3c)
    return [s, _obj(c, {0xc: (1, _r(c))})]


S(0x64ff10, 'ZRenderBaseDll::Load2', 'thiscall', 1, ret='u32', gen=_g_64ff10, note='batch288; 0x70039c set per case')


def _g_65c990(c):
    s = _rnd(c, 0x418)
    c.emu.w32(s + 0x414, c.rng.choice([0, 1, 0x7e, 0x7f, c.rng.randrange(0x80)]))
    return [s, _r(c)]


S(0x65c990, 'ring push +0x200', 'thiscall', 1, ret=None, gen=_g_65c990, note='batch288; void')


def _g_495e90(c):
    rm = _rnd(c, 0xa0)
    c.emu.w32(rm + 0x9b, _obj(c, {0x154: (2, _r(c))}))
    c.emu.w32(0x70039c, rm)
    s = _rnd(c, 8)
    c.emu.w32(s, _vt(c, {4: (4, _r(c))}))
    return [s, _r(c), _r(c), _r(c), _r(c)]


S(0x495e90, 'ZGeomBuffer::AllocGeom', 'thiscall', 4, ret='u32', gen=_g_495e90, note='batch288')
