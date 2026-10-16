"""specs_s1700.py - residue 13 batch 1700: 0x477840 (factory, tag 0x77f; ZActor ctor 0x476f50 hooked; allocators hooked) and
0x47f760 (destructor shape: manager 0x58 / slot 0x210, the 0x43de70 chain hooked, flag exits 0x45c510 / 0x4690b0 hooked)."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED, sysobj


def _alloc(c, addr, nargs, ret):
    rec = c.emu.alloc(4 * (nargs + 1), 4)

    def h(e, r):
        sp = e.reg('esp')
        for i in range(nargs):
            e.w32(rec + 4 * i, e.r32(sp + 4 + 4 * i))
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _cdecl_rec(c, addr, nargs):
    rec = c.emu.alloc(4 * (nargs + 1), 4)

    def h(e, r):
        sp = e.reg('esp')
        for i in range(nargs):
            e.w32(rec + 4 * i, e.r32(sp + 4 + 4 * i))
        e.ret(eax=0, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _fac(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _alloc(c, 0x45c4f0, 2, rnd(c, 0x200) if r.random() < 0.8 else 0)
    _alloc(c, 0x45c4b0, 1, rnd(c, 0x200) if r.random() < 0.8 else 0)
    hook(c, seq, 0x476f50, 3, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x80)
    b = r.choice([0, 0, 1, r.getrandbits(32)])
    return [me, r.getrandbits(32), b]


def _dtor(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x43de70, 0, ret=0, this=True, pop=True)
    _cdecl_rec(c, 0x45c510, 1)
    _cdecl_rec(c, 0x4690b0, 2)
    tgt = obj(c, 0x40, {0x210: stub(c, seq, 1)})
    mgr = obj(c, 0x100, {0x58: stub(c, seq, 1, ret=tgt if r.random() < 0.8 else 0)})
    sysobj(c, db=mgr)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x18, r.choice([0, r.getrandbits(32), 1]))
    return [me, r.choice([0, 1, 2, 4, 5, r.getrandbits(32)])]


S(0x477840, 'GUESS FUN_477840', 'thiscall', None, ret='eax', gen=_fac, note='batch1700; tag 0x77f; ZActor ctor hooked')
S(0x47f760, 'GUESS FUN_47f760', 'thiscall', None, ret='eax', gen=_dtor, note='batch1700; dtor shape; chain and exits hooked')
