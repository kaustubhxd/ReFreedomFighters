"""specs_s1632.py - soundtimers batch 1632: ZDllSound find wrappers, GetName(int), AllocateObject, AddToRefChain.
The DLL's FindObject / FindObjectIdx / GetSoundObject / GetName virtuals are stubs that record their arguments; the
data header is a fake block with the offsets the wrappers read. ZRefAlloc::AddToChain (0x533da0) is hooked."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook


def _data(c, seq):
    r = c.rng
    b = rnd(c, 0x200, 16)
    c.emu.w32(b, 0x40)
    h = b + 0x40
    for off in (0x28, 0x10, 0x2c, 0x14, 0x1c, 4, 0x20, 8):
        c.emu.w32(h + off, r.randint(0, 0x100))
    return b


def _dll(c, seq):
    r = c.rng
    clear_hooks(c)
    b = _data(c, seq)
    d = rnd(c, 0x5400)
    slots = {0x1ac: stub(c, seq, 3, ret=r.getrandbits(32)), 0x1b0: stub(c, seq, 3, ret=r.getrandbits(32)),
             0x54: stub(c, seq, 1, ret=rnd(c, 8)), 0x1e8: stub(c, seq, 1, ret=rnd(c, 8))}
    vt = obj(c, 0x200, slots)
    c.emu.w32(d, c.emu.r32(vt))
    c.emu.w32(d + 0x5302, b if r.random() < 0.9 else 0)
    name = c.emu.alloc(16, 4)
    c.emu.wbytes(name, b'Wood\0')
    return d, name


def _find(c):
    seq = Seq(c)
    d, name = _dll(c, seq)
    return [d, name]


for addr, nm in ((0x5366f0, 'FindMapping'), (0x536840, 'FindRoom'), (0x536870, 'FindSound'), (0x536920, 'FindSoundSet')):
    S(addr, 'ZDllSound::' + nm, 'thiscall', None, ret='eax', gen=_find, note='batch1632')


def _getname(c):
    seq = Seq(c)
    d, name = _dll(c, seq)
    return [d, c.rng.choice([0, 1, 5, c.rng.getrandbits(32)])]


S(0x5372f0, 'ZDllSound::GetName(int)', 'thiscall', None, ret='eax', gen=_getname, note='batch1632')


def _alloc(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = r.getrandbits(32) | 1
    mg = obj(c, 0x200, {})
    from specs_s1617 import _mgr
    m = _mgr(c, seq, newh=h)
    if not c.emu.r32(m):   # the manager needs its generator (the spec's 5% empty case faults in both builds)
        g0 = obj(c, 0x20, {4: stub(c, seq, 0, ret=h), 0x14: stub(c, seq, 1, ret=1)})
        c.emu.w32(g0 + 0x10, 0x3ff)
        c.emu.w32(m, g0)
    c.emu.w32(m + 0x100c, r.choice([0, 5, 0x3fe]))   # below the pool size: exhaustion faults in the generator, not the code
    d = rnd(c, 0x1100)
    c.emu.wbytes(d + 0x8b, c.emu.rbytes(m, 0x1014))
    db = obj(c, 0x80, {0x60: stub(c, seq, 1, ret=0)})
    sysobj(c, db=db)
    return [d]


S(0x535570, 'ZDllSound::AllocateObject', 'thiscall', None, ret=None, gen=_alloc, note='batch1632')


def _chain(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x533da0, 2, ret=r.getrandbits(32))
    d = rnd(c, 0x1200)
    return [d, r.getrandbits(32), r.getrandbits(32)]


S(0x535490, 'ZDllSound::AddToRefChain', 'thiscall', None, ret='eax', gen=_chain, note='batch1632')
