"""specs_s213125.py - batch 213125: per-tick controller state machine (jump table over a power-of-two state), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g564700(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', v))
    flag = lambda p: (lambda emu, k: (rb() & ~0xff) | (1 if r.random() < p else 0))
    # owner object O with a sub-object at O+0xcb whose slot 0x14 returns the list length
    n = r.choice([0, 1, 2, 3])
    subvt = c.emu.alloc(0x40, 4)
    e.w32(subvt + 0x14, pystub(c, 0, this=True, ret=n))
    O = obj(c, 0x100, {0x300: pystub(c, 0, this=True)}, nslots=0xd0)
    w32u(O + 0xcb, subvt)
    state = r.choice([2, 4, 8, 16, 32, 2, 4, 8, 16, 32, 3, 0, 1, 64, 33])
    sl = {0x84: pystub(c, 0, this=True, ret=O), 0x100: pystub(c, 1, this=True)}
    self_ = obj(c, 0xe00, sl, nslots=0x70)
    child = obj(c, 0x40, {0x10: pystub(c, 0, this=True, ret=lambda emu, k: r.choice([0, 1, 1, 2, rb()])),
                          0x8: pystub(c, 2, this=True, ret=flag(0.5)),
                          0xc: pystub(c, 2, this=True, ret=flag(0.5))}, nslots=0x10)
    T = obj(c, 0x40, {0x28: pystub(c, 1, this=True)}, nslots=0x20)
    eng = rnd(c, 0x100)
    t = r.choice([0, 5, 50, 1000, -3 & 0xffffffff])
    w32u(eng + 0x30, t)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    ts = t - (1 << 32) if t >= 1 << 31 else t
    d = r.choice([-1, 0, 1, 0, 2, -2])
    fv = r.choice([(ts + d) / 1024.0, (ts + d) / 1024.0, (ts + d + 0.5) / 1024.0, float('nan'), 1e30, -1e30, r.uniform(-3, 3)])
    wf(self_ + 0xca6, fv)
    w32u(self_ + 0x184, state)
    self_b = self_
    e.wbytes(self_ + 0x18b, bytes([1 if r.random() < 0.12 else 0]))
    e.wbytes(self_ + 0x189, bytes([r.choice([0, 1])]))
    e.wbytes(self_ + 0x188, bytes([r.choice([0, 1, 0x80])]))
    e.wbytes(self_ + 0x85, bytes([1 if r.random() < 0.25 else 0]))
    w32u(self_ + 0xdc, 2 if r.random() < 0.85 else r.choice([0, 1, 3]))
    w32u(self_ + 0xc9a, 0xa if r.random() < 0.15 else r.randrange(0, 10))
    w32u(self_ + 0xc96, r.choice([0, 1, 2, 2, 2, 3]))
    w32u(self_ + 0xc8a, r.choice([0, 1, 5, 0x19]))
    w32u(self_ + 0xc8e, r.choice([0, 1, 1, 2]))
    w32u(self_ + 0xc9e, r.choice([0xa, 3, 5]))
    w32u(self_ + 0xc5e, child)
    # callee recorders
    hook_rec(c, 0x562260, 0, pop=0, this=True)

    def s960(emu, k):
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(0x2c)))
    hook_rec(c, 0x57f960, 0, pop=0, this='mark', side=s960)

    def s9b0(emu, k):
        p = emu.arg32(0)
        emu.w32(p, r.choice([0x20, 0x20, 1, 2, rb()]))
        lg(emu, 'v9b0', p, 4)
        emu.wbytes(emu.arg32(1), bytes(r.getrandbits(8) for _ in range(0x2c)))
    hook_rec(c, 0x57f9b0, 2, pop=8, this=True, stackmark=(1,), side=s9b0)

    def s360(emu, k):
        lg(emu, 'm360', emu.arg32(0), 0x2c)
    hook_rec(c, 0x565360, 1, pop=4, this=True, stackmark=(0,), side=s360)
    hook_rec(c, 0x565100, 1, pop=4, this=True)
    hook_rec(c, 0x564600, 1, pop=4, this=True)
    return [self_]


S(0x564700, 'controller_tick', 'thiscall', None, ret=None, gen=g564700)
