"""specs_s903.py - gap-band slice, batch 903: 0x41e8a0 (ZSysMem::Delete, thiscall, one stack arg (pointer), ret 4, returns al).
Stand-ins (hooked, logged): slot +0x20 of this (returns an index: 0, 1 or 2), slot +0x88 (bool), slot +0xd4 (bool), slot +0x7c (two
args), slot +0x84, the object at this+0x2c's slot +4 (one arg), 0x4d1140, 0x41e680 (returns a drawn dword), 0x4cfdb0, 0x634d10 (cdecl),
and the free import (stub_import 'free'). Real exe code runs for 0x41e650 and 0x41f190. The block header words are drawn with both
signs and small counts so both paths run."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    answers = {'idx': r.choice([0, 0, 1, 2])}
    b88 = r.random() < 0.5
    d4 = r.random() < 0.5
    x680 = r.getrandbits(32)

    def h_free(e, rr):
        e.calllog.append(('free', e.arg32(0) != 0))
        e.ret(eax=0, argbytes=0)

    def h20(e, rr):
        e.calllog.append(('self.20', e.arg32(0) != 0))
        e.ret(eax=answers['idx'], argbytes=4)

    def h88(e, rr):
        e.calllog.append(('self.88', e.arg32(0) != 0))
        e.ret(eax=1 if b88 else 0, argbytes=4)

    def hd4(e, rr):
        e.calllog.append(('self.d4', e.arg32(0)))
        e.ret(eax=1 if d4 else 0, argbytes=4)

    def h7c(e, rr):
        e.calllog.append(('self.7c', e.arg32(0), e.arg32(1) != 0))
        e.ret(eax=0, argbytes=8)

    def h84(e, rr):
        e.calllog.append(('self.84',))
        e.ret(eax=0, argbytes=0)

    def hx4(e, rr):
        e.calllog.append(('X.4', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h_1140(e, rr):
        e.calllog.append(('h.4d1140', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=0, argbytes=4)

    def h_680(e, rr):
        e.calllog.append(('h.41e680', e.arg32(0) != 0))
        e.ret(eax=x680, argbytes=0)

    def h_dfb0(e, rr):
        e.calllog.append(('h.4cfdb0', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=0, argbytes=4)

    def h_d10(e, rr):
        e.calllog.append(('h.634d10', e.arg32(0) != 0, e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x4d1140: h_1140, 0x41e680: h_680, 0x4cfdb0: h_dfb0, 0x634d10: h_d10})
    e.stub_import('free', h_free)
    X = vt_object(c, 0x40, {4: hx4}, nslots=0x20, name='X')
    self = vt_object(c, 0x100, {0x20: h20, 0x88: h88, 0xd4: hd4, 0x7c: h7c, 0x84: h84}, nslots=0x60, name='self')
    if r.random() < 0.8:
        e.w32(self + 0x2c, X)
    else:
        e.w32(self + 0x2c, 0)
    for off in (0x18, 0x1c):
        e.w32(self + off, rnd(c, 0x40) if r.random() < 0.5 else 0)
    for i in range(1, 3):
        e.w32(self + 0x31 + 4 * i, rnd(c, 0x20))
    # manager global and its object (real code 0x41e650 reads +0x1c5d of it)
    m2 = rnd(c, 0x2000)
    e.w32(m2 + 0x1c5d, 0)
    mgr = rnd(c, 0x1b00)
    e.w32(mgr + 0x9b, m2 if r.random() < 0.6 else 0)
    e.w32(0x70039c, mgr)
    # the block p with header words at p-0x10 and p-0x20
    blk = rnd(c, 0x140)
    p = blk + 0x80
    hdr8 = r.choice([0x40000000, 0x80000010, 0x10, 0xc0000010, 0x20000010 | 0x40000000])
    e.w32(p - 0x10 + 8, hdr8)
    e.w32(p - 0x10 + 4, r.choice([-2, 0, 1, 2, 3]) & 0xffffffff)
    e.w32(p - 0x10 + 0xc, r.choice([0, 7]))
    e.w32(p - 0x20 + 0x0, rnd(c, 0x40) if r.random() < 0.5 else 0)
    e.w32(p - 0x20 + 0x4, rnd(c, 0x40) if r.random() < 0.5 else 0)
    e.w32(p - 0x20 + 0x18, r.choice([0x10, 0x40000010, 0x80000010]))
    e.w32(p - 0x20 + 0x1c, r.choice([0, 5]))
    if r.random() < 0.1:
        p = 0
    return [self, p]


S(0x41e8a0, 'ZSysMem::Delete(void*) (named)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch903 (band slice)')
