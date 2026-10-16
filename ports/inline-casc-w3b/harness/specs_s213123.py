"""specs_s213123.py - batch 213123: menu command dispatch (jump table, codes 1/2/3/10/101/102), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g56c1a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    flag = lambda p: (lambda emu, k: (rb() & ~0xff) | (1 if r.random() < p else 0))
    # sub objects
    Y = obj(c, 0x40, {0x5c: pystub(c, 3, this=True)}, nslots=0x40)
    T = obj(c, 0x40, {0x134: pystub(c, 0, this=True, ret=Y),
                      0x138: pystub(c, 0, this=True, ret=lambda emu, k: rb()),
                      0x114: pystub(c, 5, this=True, ret=lambda emu, k: rb())}, nslots=0x60)
    tab = T
    eng = rnd(c, 0x100)
    e.w32(eng + 0x9b, tab)
    e.w32(0x70039c, eng)
    O44 = obj(c, 0x40, {0x12c: pystub(c, 2, this=True)}, nslots=0x60)
    OC7 = obj(c, 0x40, {0xbc: pystub(c, 1, this=True)}, nslots=0x60)
    self_ = obj(c, 0xd10, {0xd8: pystub(c, 0, this=True, ret=flag(0.15)),
                           0xd0: pystub(c, 1, this=True)}, nslots=0x60)
    B = rnd(c, 0x600)
    e.w32(self_ + 0x94, B)
    e.w32(self_ + 0x44, O44)
    w32u(self_ + 0xc7e, OC7)
    w32u(self_ + 0xcea, rnd(c, 0x20))
    lim = r.choice([1, 2, 3, 6])
    w32u(self_ + 0xce6, lim)
    w32u(self_ + 0xce2, r.choice([0, 0, lim - 1, lim, lim - 2, 1, 2, 0xffffffff]))
    w32u(B + 0x57 + 0x3ba, r.choice([2, 3, 2, 3, 0, 1, 4, rb()]))
    # string at B+0x3f9, up to 7 characters
    n = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 4, 4])
    s = [r.choice([0x41, 0x5a, 0x30, 0x7a]) for _ in range(n)]
    if n > 2:
        s[2] = r.choice([0x31, 0x38, 0x36, 0x39, 0x35, 0x38, 0x31, 0x36])
    if n > 3:
        s[3] = r.choice([0x52, 0x52, 0x51, 0x41, 0x30])
    e.wbytes(B + 0x3f9, bytes(s) + b'\0')
    code = r.choice([1, 1, 1, 1, 2, 3, 10, 101, 102, 10, 101, 0, 4, 9, 11, 100, 103, 0x66, 0x67, 0xffffffff, r.getrandbits(32)])
    # callee recorders
    hook_rec(c, 0x564fd0, 1, pop=4, this=True)
    hook_rec(c, 0x56b930, 2, pop=8, this=True)
    hook_rec(c, 0x5b1000, 1, pop=4, this=True, ret=flag(0.5))

    def s48(emu, k):
        lg(emu, 'p48', emu.reg('ecx'), 8)
    hook_rec(c, 0x48aad0, 0, pop=0, this='mark', ret=lambda emu, k: rb(), side=s48)
    hook_rec(c, 0x5ae710, 1, pop=4, this=True)

    def s59(emu, k):
        lg(emu, 'b59', emu.arg32(0), 8)
    hook_rec(c, 0x59cb60, 1, pop=4, this=True, stackmark=(0,), side=s59)
    hook_rec(c, 0x561be0, 0, pop=0, this=True, ret=flag(0.5))
    hook_rec(c, 0x563500, 0, pop=0, this=True)
    hook_rec(c, 0x562bc0, 0, pop=0, this=True)
    hook_rec(c, 0x565100, 1, pop=4, this=True)
    hook_rec(c, 0x56b460, 1, pop=4, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [self_, code]


S(0x56c1a0, 'menu_command', 'thiscall', None, ret=None, gen=g56c1a0)
