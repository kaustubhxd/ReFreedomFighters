"""specs_s602.py - area 49 batch 602: CCivilianPathList cleanup (0x5bdfa0) and destructor (0x5be080)."""
from pilot import S
from wkit import rnd, stub, obj, sysobj, patch_jmp


def _free_hook(emu, r):
    # cdecl free/delete: the caller pops its arguments, so return with no argbytes
    emu.ret()


def _setup(c):
    r = c.rng
    # hook by address (e.hook): the same stub for the port (which calls these addresses) and the original
    c.emu.hook(0x41e2c0, _free_hook)
    c.emu.hook(0x634273, _free_hook)
    c.emu.hook(0x4690b0, _free_hook)
    rm = obj(c, 0x100, {0x34: stub(c, 1)})
    sysobj(c, {})
    so = c.emu.r32(0x70039c)
    c.emu.w32(so + 0x9b, rm)
    c.emu.w32(0x7003b0, stub(c, 0))
    self_ = rnd(c, 0x1000)
    cnt = r.randint(0, 4)
    c.emu.w32(self_ + 0x90c, cnt)
    for i in range(cnt):
        e = obj(c, 0x40, {}) if r.random() < 0.8 else 0
        if e:
            for off in (0xc, 0x10, 0x14):
                c.emu.w32(e + off, c.emu.alloc(8, 4) if r.random() < 0.6 else 0)
        c.emu.w32(self_ + 0x59 + i * 0x3a, e)
    return self_


def _cleanup(c):
    return [_setup(c)]


def _dtor(c):
    r = c.rng
    self_ = _setup(c)
    flags = r.choice((0, 2, 4, 6, 1 | 4, 1 | 4 | 2))
    if flags & 1 and not flags & 4:
        flags |= 4
    return [self_, flags]


S(0x5bdfa0, 'CCivilianPathList cleanup (0x5bdfa0)', 'thiscall', None, ret=None, gen=_cleanup)
S(0x5be080, 'CCivilianPathList::~CCivilianPathList', 'thiscall', None, ret='eax', gen=_dtor)
