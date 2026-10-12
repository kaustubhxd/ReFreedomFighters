"""specs_s604.py - area 49 batch 604: CCivilianPathList::SetCivilianOnPath (0x5bf340).
Callees hooked by address (e.hook, same for the port and the original): 0x41e290 (__builtin_new, cdecl, fixed buffer),
0x5bdd30 (record constructor, thiscall one arg, returns a fixed value), 0x47bf10 (thiscall, two args). The render
manager's slot 0x58 is a counting handler: first call pops 12 (three args), second pops 4 (one arg)."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, sysobj, fedge  # noqa: F401


def _setup(c):
    r = c.rng
    buf = c.emu.alloc(0x40, 16)
    nullnew = r.random() < 0.3   # sometimes the allocation fails (returns 0): covers the p == 0 branch
    c.emu.hook(0x41e290, lambda e, rr: e.ret(eax=0 if nullnew else buf, argbytes=0))
    c.emu.hook(0x5bdd30, lambda e, rr: e.ret(eax=0x1234, argbytes=4))
    clog = c.emu.alloc(12, 4)   # records the 0x47bf10 call (this, arg0, arg1) so a wrong argument shows as a heap difference
    def f47(e, rr):
        e.w32(clog, e.reg('ecx'))
        e.w32(clog + 4, e.arg32(0))
        e.w32(clog + 8, e.arg32(1))
        e.ret(argbytes=8)
    c.emu.hook(0x47bf10, f47)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    x1 = c.emu.alloc(0x40, 16)
    x2 = c.emu.alloc(0x40, 16)

    def rm58(e, rr):
        n = e.r32(cnt)
        e.w32(cnt, n + 1)
        if n == 0:
            e.ret(eax=x1, argbytes=12)
        else:
            e.ret(eax=x2, argbytes=4)

    rm = c.emu.fake_object('rm', 0x100, nslots=0x60, slots={0x58: rm58})
    sysv = obj(c, 0xa0, {0x1c0: stub(c, 2, fldv=r.choice((0.0, 0.5, 0.999, r.random())))})
    c.emu.w32(sysv + 0x9b, rm)
    c.emu.w32(sysv + 0x40, r.randint(0, 1 << 20))
    c.emu.w32(0x70039c, sysv)
    o = obj(c, 0x40, {0x130: stub(c, 1)})
    self_ = rnd(c, 0x1000)
    c.emu.w32(self_ + 0x44, o)
    c.emu.w16(self_ + 0x916, r.getrandbits(16)) if hasattr(c.emu, 'w16') else c.emu.w32(self_ + 0x916, r.getrandbits(16))
    idx = r.randint(0, 3)
    blk = self_ + idx * 0x3a
    pv = obj(c, 0x40, {0x30: stub(c, 1, ret=r.getrandbits(32))})
    path = rnd(c, 0x40)
    c.emu.w32(path + 0x18, pv)
    c.emu.w32(blk + 0x4c, path)
    src = rnd(c, 0x20)
    c.emu.w32(blk + 0x59, src)
    c.emu.wf32(blk + 0x55, r.uniform(0.0, 2.0) if r.random() < 0.8 else fedge(c))
    c.emu.w8(blk + 0x54, r.randint(0, 200))
    info = rnd(c, 0x10)
    c.emu.w32(info, r.getrandbits(32))
    return self_, info, idx


def _scop(c):
    self_, info, idx = _setup(c)
    return [self_, info, idx]


S(0x5bf340, 'CCivilianPathList::SetCivilianOnPath', 'thiscall', None, ret=None, gen=_scop)
