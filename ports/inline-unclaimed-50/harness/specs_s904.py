"""specs_s904.py - gap-band slice, batch 904: 0x41ee20 (thiscall, one stack arg (n), ret 4, returns eax). Stand-ins (hooked, logged):
0x4d1060 (thiscall, ECX = the last table entry, one argument, returns a drawn dword), 0x4d0700 (as in batch901), the malloc import (as in
batch901). The flag words this+0x49, this+0x45 (count), this+0x30 are drawn to hit the table-first branch, the malloc branch and the
0x4d0700 branch."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    rv = r.choice([0, r.getrandbits(32)])
    blk_m = rnd(c, 0x200)
    blk_7 = rnd(c, 0x200)

    def h_1060(e, rr):
        e.calllog.append(('h.4d1060', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=rv, argbytes=4)

    def h_7(e, rr):
        e.calllog.append(('h.4d0700', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=blk_7, argbytes=4)

    def malloc(e, rr):
        e.calllog.append(('malloc', e.arg32(0)))
        e.ret(eax=blk_m, argbytes=0)

    only_hooks(c, {0x4d1060: h_1060, 0x4d0700: h_7})
    e.stub_import('malloc', malloc)
    self = rnd(c, 0x100)
    e.w32(self + 0x49, 0 if r.random() < 0.7 else 1)   # a dword compare in the exe
    cnt = r.randint(0, 3)
    e.w32(self + 0x45, cnt)
    for i in range(1, 4):
        e.w32(self + 0x31 + 4 * i, rnd(c, 0x20))
    e.w8(self + 0x30, r.choice([0, 0, 1]))
    e.w32(self + 0x31, rnd(c, 0x20))
    n = r.choice([0, 1, 0x40, r.getrandbits(20)])
    return [self, n]


S(0x41ee20, 'Alloc41ee20 (GUESS name)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch904 (band slice)')
