"""specs_s951.py - area 50 batch 951 (residue-9 free list): 0x615ed0 and 0x64c750 (no args; return constants 0x55 and 0x7f), 0x650c10 (thiscall; tail-calls
slot +0xc of the object at this+0x8c; stand-in logs), 0x65f5d0 (thiscall; difference of two dwords in the object at this+0xc), 0x4d1dd0 (thiscall;
calls slot +0x10 of this with one arg 0 (stand-in logs), then returns the dword at [[this+0xc]+4] & 0x3fffffff)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen_none(c):
    return []


def _gen_650(c):
    e, r = c.emu, c.rng

    def h(e, rr):
        e.calllog.append(('obj.c', e.reg('ecx')))
        e.ret(eax=rv, argbytes=0)

    rv = r.getrandbits(32)
    obj = vt_object(c, 0x40, {0xc: h}, nslots=0x100, name='obj')
    self = rnd(c, 0x100)
    e.w32(self + 0x8c, obj)
    return [self]


def _gen_65f(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x100)
    cobj = rnd(c, 0x10100)
    e.w32(self + 0xc, cobj)
    e.w32(cobj + 0x10069, r.getrandbits(32))
    e.w32(cobj + 0x10061, r.getrandbits(32))
    return [self]


def _gen_4d1(c):
    e, r = c.emu, c.rng

    def h10(e, rr):
        e.calllog.append(('self.10', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    only_hooks(c, {})
    cobj = rnd(c, 0x20)
    e.w32(cobj + 4, r.getrandbits(32))
    self = vt_object(c, 0x100, {0x10: h10}, nslots=0x100, name='self')
    e.w32(self + 0xc, cobj)
    return [self]


S(0x615ed0, 'constant 0x55 (no name in map)', 'cdecl', None, ret='eax', gen=_gen_none, note='area50 batch951 (residue-9 free)')
S(0x64c750, 'constant 0x7f (no name in map)', 'cdecl', None, ret='eax', gen=_gen_none, note='area50 batch951 (residue-9 free)')
S(0x650c10, 'tail call slot +0xc of +0x8c (no name in map)', 'thiscall', None, ret='eax', gen=_gen_650, note='area50 batch951 (residue-9 free)')
S(0x65f5d0, 'difference of two dwords (no name in map)', 'thiscall', None, ret='eax', gen=_gen_65f, note='area50 batch951 (residue-9 free)')
S(0x4d1dd0, 'call slot 0x10 then flag bits (no name in map)', 'thiscall', None, ret='eax', gen=_gen_4d1, note='area50 batch951 (residue-9 free)')
