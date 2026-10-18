"""specs_s213128.py - batch 213128: per-frame update of a pending prompt object (many object-table notifications, string compares, image strings), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g59b820(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    flag = lambda p: (lambda emu, k: (rb() & ~0xff) | (1 if r.random() < p else 0))
    G = rnd(c, 0x3000)
    e.w32(0x7003b8, G)
    Rs = [obj(c, 0x40, {0x28: pystub(c, 0, this=True), 0x2c: pystub(c, 0, this=True)}, nslots=0x20) for _ in range(3)]
    Xo = obj(c, 0x40, {0x88: pystub(c, 2, this=True, stackmark=(1,),
                                      side=lambda emu, k: emu.w32(emu.arg32(1), r.choice([0, 1, 2, rb()])))}, nslots=0x40)
    Yo = obj(c, 0x40, {0x90: pystub(c, 2, this=True, stackmark=(1,),
                                      side=lambda emu, k: emu.wbytes(emu.arg32(1), bytes([r.choice([0, 0, 1, 0x7f])])))}, nslots=0x40)
    T = obj(c, 0x40, {0x138: pystub(c, 0, this=True, ret=Xo),
                      0x134: pystub(c, 0, this=True, ret=Yo),
                      0x58: pystub(c, 1, this=True, ret=lambda emu, k: r.choice(Rs + [0, 0])),
                      0x114: pystub(c, 5, this=True, ret=lambda emu, k: rb())}, nslots=0x50)
    E = obj(c, 0x100, {0x5c: pystub(c, 2, this=True, ret=flag(0.4))}, nslots=0x40)
    w32u(E + 0x9b, T)
    e.w32(0x70039c, E)
    o44 = obj(c, 0x40, {0x130: pystub(c, 2, this=True)}, nslots=0x50)
    this = rnd(c, 0x1100)
    e.w32(this + 0x44, o44)
    w32u(this + 0x1044, r.choice([3, 3, 2, 1, 0, 5]))
    e.wbytes(this + 0x103c, bytes([1 if r.random() < 0.35 else 0]))
    e.wbytes(this + 0x103f, bytes([1 if r.random() < 0.2 else 0]))
    e.wbytes(this + 0x103e, bytes([1 if r.random() < 0.5 else 0]))
    e.wbytes(this + 0x41a, bytes([r.choice([0, 1, 1, 7])]))
    e.wbytes(this + 0x4a, bytes([r.choice([0x38, 0x38, 0x38, 0x34, 0x35, 0x36, 0x37, 0x41])]))
    e.wbytes(this + 0x4b, bytes([r.choice([0x45, 0x45, 0x45, 0x46])]))
    tgt = bytes(e.rbytes(0x6a9280, 24)).split(b'\0')[0] + b'\0'
    nm = e.alloc(32, 4)
    ch = r.random()
    if ch < 0.35:
        e.wbytes(nm, tgt)
    elif ch < 0.5:
        e.wbytes(nm, tgt[:-2] + b'z\0' if len(tgt) > 2 else b'zz\0')
    else:
        e.wbytes(nm, bytes([r.choice([0x41, 0x58, 0x30]), r.choice([0x41, 0x42, 0x43, 0x44, 0x45, 0x40, 0x61, 0xc1])]) + b'\0')
    w32u(this + 0x4d, nm)
    # hooks
    hook_rec(c, 0x59b0a0, 0, pop=0, this=True)
    hook_rec(c, 0x5adeb0, 1, pop=4, this=True, ret=flag(0.85))

    def s930(emu, k):
        lg(emu, 'b930', emu.arg32(0), 20)
    hook_rec(c, 0x5ae930, 2, pop=8, this=True, stackmark=(0,), side=s930)
    hook_rec(c, 0x5b1250, 1, pop=4, this=True)
    hook_rec(c, 0x5acfb0, 0, pop=0, this=True, ret=lambda emu, k: r.choice([0xfffffffe, 0, 1, 3, 5]))
    hook_rec(c, 0x5ad000, 1, pop=4, this=True)
    hook_rec(c, 0x59b3c0, 0, pop=0, this=True)
    hook_rec(c, 0x59c4a0, 0, pop=0, this=True)
    Bo = rnd(c, 0x20)
    hook_rec(c, 0x589c20, 1, pop=4, this=True, ret=Bo)
    hook_rec(c, 0x596d00, 1, pop=4, this=True)
    hook_rec(c, 0x596d30, 1, pop=4, this=True)
    hook_rec(c, 0x596940, 4, pop=16, this=True, stackmark=(1,))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x59b820, 'prompt_update', 'thiscall', None, ret=None, gen=g59b820)
