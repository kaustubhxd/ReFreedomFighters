"""specs_f16b001.py - fresh slice 16 batch 1 (see src/f16b001.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj, HOOKED


def _cdecl_rec(c, addr, nargs):
    rec = c.emu.alloc(4 * (nargs + 1), 4)

    def h(e, r):
        sp = e.reg('esp')
        for i in range(nargs):
            e.w32(rec + 4 * i, e.r32(sp + 4 + 4 * i))
        e.w32(rec + 4 * nargs, e.r32(rec + 4 * nargs) + 1)
        e.ret(eax=0, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _noargs(c):
    clear_hooks(c)
    return []


def _get(c):
    clear_hooks(c)
    return [rnd(c, 0x40)]


def _dtor(c):
    clear_hooks(c)
    _cdecl_rec(c, 0x634273, 2)
    return [rnd(c, 0x10), c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _48c(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    o = obj(c, 0x20, {0x2b8: stub(c, seq, 0, ret=r.getrandbits(32))})
    db = rnd(c, 0xb00)
    c.emu.w32(db + 0xadc, o if r.random() < 0.8 else 0)
    sysobj(c, db=db)
    me = rnd(c, 0xc00)
    c.emu.w32(me + 0xbc9, r.choice([0, 0, 0, 1, r.getrandbits(32)]))
    return [me]


def _571(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    inner = obj(c, 0x20, {0x74: stub(c, seq, 0)})
    s = obj(c, 0x100, {0xbc: stub(c, seq, 0, ret=inner)})
    c.emu.w8(s + 0x6c, r.choice([0, 0, 1, 0x80]))
    c.emu.w32(0x70039c, s)
    me = obj(c, 0x40, {0xd0: stub(c, seq, 1)})
    return [me]


def _4c1(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    db = obj(c, 0x40, {0x2c: stub(c, seq, 0, ret=r.choice([0, 1, 0x100, 0xffffff00, r.getrandbits(32)]))})
    sysobj(c, db=db)
    me = obj(c, 0x40, {0x68: stub(c, seq, 2), 0x84: stub(c, seq, 0, ret=r.getrandbits(32))})
    return [me]


S(0x63480d, 'FUN_63480d (returns 1)', 'cdecl', None, ret='eax', gen=_noargs, note='f16b001')
S(0x6387c0, 'FUN_6387c0 (get +0x24)', 'thiscall', None, ret='eax', gen=_get, note='f16b001')
S(0x638cc0, 'FUN_638cc0 (get +0x2d)', 'thiscall', None, ret='eax', gen=_get, note='f16b001')
S(0x633688, 'FUN_633688 (deleting dtor 0x6c1600)', 'thiscall', None, ret='eax', gen=_dtor, note='f16b001; delete hooked')
S(0x48c480, 'FUN_48c480 (+0xadc slot 0x2b8)', 'thiscall', None, ret=None, gen=_48c, note='f16b001')
S(0x571bc0, 'CSoundMenu::ApplyChanges', 'thiscall', None, ret=None, gen=_571, note='f16b001')
S(0x4c1f40, 'ZSoundExtend::Init', 'thiscall', None, ret='eax', gen=_4c1, note='f16b001')
