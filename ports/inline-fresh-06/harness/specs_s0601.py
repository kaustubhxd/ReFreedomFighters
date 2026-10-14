"""specs_s0601.py - fresh-06 batch 1 (docs/20-fresh-06.md). Exe callees are replaced by logging stubs (helpers06.hk)
that pop what the real callee pops. Objects are random bytes, so stores past a field show as heap differences."""
from pilot import S
from helpers06 import rnd, hk, vt, obj


def _iter(c):
    return [rnd(c, 0x40)]


def _deldtor(c):
    hk(c, 0x602240, 0, ecx=True)
    hk(c, 0x634273, 2, pop=0)
    return [rnd(c, 0x40), c.rng.getrandbits(32)]


def _ingame(c):
    flag = c.rng.choice([0, 1, 0x100, 0xff, 0x12345601])
    o = obj(c, 0x40, vt(c, 'opt', {0x2c: (2, flag)}))
    eng = rnd(c, 0x2000)
    c.emu.w32(eng + 0x1907, o)
    c.emu.w32(0x70039c, eng)
    hk(c, 0x5f0380, 0, ecx=True)
    return [rnd(c, 0x40)]


def _copydata(c):
    hk(c, 0x4f9c60, 1, ecx=True)
    return [rnd(c, 0x400), rnd(c, 0x400)]


def _exists(c):
    hk(c, 0x4d6520, 3, ret=c.rng.getrandbits(32), ecx=True)
    return [rnd(c, 0x40), rnd(c, 0x20)]


def _geteid(c):
    node = c.rng.choice([0, rnd(c, 0x20)])

    def f(e, a, node=node):
        e.w32(a[0], node)
        e.w32(a[0] + 4, 0x5a5a5a5a)
    hk(c, 0x607200, 2, ecx=True, fn=f)
    return [rnd(c, 0x40), rnd(c, 0x20)]


def _token(c):
    hk(c, 0x5f2c60, 2, ecx=True)
    this = rnd(c, 0x2000)
    lst = rnd(c, 0x20)
    c.emu.w32(this + 0x1b6d, lst)
    tok = rnd(c, 0x20)
    if c.rng.random() < 0.4:
        c.emu.w32(lst + 4, tok)
    pp = rnd(c, 8)
    c.emu.w32(pp, tok)
    return [this, rnd(c, 0x20), pp]


def _free24(c):
    al = obj(c, 0x20, vt(c, 'alloc', {0x18: (2, 0)}))
    o = obj(c, 0x20, vt(c, 'mm', {0x20: (0, al)}))
    eng = rnd(c, 0x2000)
    c.emu.w32(eng + 0x190f, o)
    c.emu.w32(0x70039c, eng)
    n = c.rng.choice([0, 1, 2, 0x0aaaaaab, c.rng.getrandbits(32)])
    return [rnd(c, 0x40), n]


S(0x65c9e0, 'iterator post-increment by 8 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_iter)
S(0x5f1460, 'SaveSerialInfo_t::scalar deleting dtor thiscall', 'thiscall', None, ret='eax', gen=_deldtor)
S(0x5f0420, 'CModeControl_IngameOptions::Update thiscall', 'thiscall', None, ret=None, gen=_ingame)
S(0x4f8c20, 'ZEditControl::CopyData(const ZGEOM*) thiscall', 'thiscall', None, ret=None, gen=_copydata)
S(0x4d5c20, 'FsZip_t::Exists(const char*) thiscall', 'thiscall', None, ret='eax', gen=_exists)
S(0x606d60, 'SDLEventIds::GetEventId(const char*) thiscall', 'thiscall', None, ret='eax', gen=_geteid, stack_arg_bytes=8)
S(0x42d3e0, 'ZSysInterface::HandleNormalToken thiscall', 'thiscall', None, ret=None, gen=_token)
S(0x656360, 'free array of 24-byte elements (GUESS) stdcall', 'stdcall', None, ret=None, gen=_free24)
