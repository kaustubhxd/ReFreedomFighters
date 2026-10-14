"""specs_s309.py - mounted gun batch 309: ZFFHeroMovementMachinegun ctor, dtor, GetAnims, movement base dtor body.
The base constructor (0x5e0e10), base GetAnims (0x5e3e90) and operator delete (0x634273) are Python hooks that log
their calls; ZMovementBaseMove's destructor (0x480fd0) runs as exe code on sub-objects whose +0x14 is null or an
object with a logging slot 0."""
from pilot import S
from mg_helpers import _rnd, _obj, flush, new_log, log_stub


def _hooks(c):
    def h_ctor(e, r):
        e.calllog.append(('base_ctor', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(argbytes=8)

    def h_anims(e, r):
        e.calllog.append(('base_getanims', e.reg('ecx')))
        e.ret()

    def h_delete(e, r):
        e.calllog.append(('delete', e.arg32(0), e.arg32(1)))
        e.ret()   # cdecl
    c.emu.hook(0x5e0e10, h_ctor)
    c.emu.hook(0x5e3e90, h_anims)
    c.emu.hook(0x634273, h_delete)


def _mode(c, offs):
    r = c.rng
    log = new_log(c)
    s = _rnd(c, 0x5a0)
    for i, o in enumerate(offs):
        if r.random() < 0.5:
            c.emu.w32(s + o + 0x14, 0)
        else:
            c.emu.w32(s + o + 0x14, _obj(c, 0x10, {0: log_stub(c, log, 0x100 + i, 1)}))
    return s


def _ctor(c):
    _hooks(c)
    return [_rnd(c, 0x5a0), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _base(c):
    s = _mode(c, [0x55, 0x3d, 0x25])
    flush(c)
    return [s]


def _dtor(c):
    _hooks(c)
    s = _mode(c, [0x523, 0x4ab, 0x3eb, 0x3d3, 0x55, 0x3d, 0x25])
    flush(c)
    return [s, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _anims(c):
    _hooks(c)
    return [_rnd(c, 0x5a0)]


S(0x5e1110, 'ZFFHeroMovementMachinegun ctor', 'thiscall', None, ret='eax', gen=_ctor, note='batch309')
S(0x4878d0, 'ZMovementBase dtor body', 'thiscall', None, gen=_base, note='batch309')
S(0x5e1510, 'ZFFHeroMovementMachinegun deleting dtor', 'thiscall', None, ret='eax', gen=_dtor, note='batch309')
S(0x5e4680, 'ZFFHeroMovementMachinegun::GetAnims', 'thiscall', None, gen=_anims, note='batch309')
