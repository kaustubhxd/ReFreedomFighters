"""specs_s213127.py - batch 213127: object command/state handler (flag lookups, string compare, global float markers, state dispatch), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g56a900(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    # stubs
    O = obj(c, 0x40, {0x2ec: pystub(c, 1, this=True), 0x34c: pystub(c, 5, this=True)}, nslots=0x100)
    this = obj(c, 0x200, {0x84: pystub(c, 0, this=True, ret=O)}, nslots=0x40)
    Rs = [rnd(c, 0x80) for _ in range(3)]
    for R in Rs:
        w32u(R + 0x70, r.choice([0x20, 0x20, 0x21, 0]))
    Y = obj(c, 0x40, {0x90: pystub(c, 2, this=True, stackmark=(1,),
                                     side=lambda emu, k: emu.wbytes(emu.arg32(1), bytes([r.choice([0, 0, 1, 0x7f])])))}, nslots=0x40)
    Q = obj(c, 0x40, {0x100: pystub(c, 1, this=True)}, nslots=0x50)
    K = obj(c, 0x40, {0x25c: pystub(c, 2, this=True, ret=Q)}, nslots=0x100)
    T = obj(c, 0xb00, {0x58: pystub(c, 1, this=True, ret=lambda emu, k: r.choice(Rs)),
                       0x134: pystub(c, 0, this=True, ret=Y)}, nslots=0x50)
    w32u(T + 0xadc, K)
    Z = obj(c, 0x40, {0x64: pystub(c, 2, this=True)}, nslots=0x20)
    G1 = obj(c, 0x40, {0xc: pystub(c, 3, this=True), 0x60: pystub(c, 1, this=True, ret=lambda emu, k: rb())}, nslots=0x20)
    H = obj(c, 0x40, {0xd4: pystub(c, 2, this=True)}, nslots=0x40)
    E = obj(c, 0x2000, {0xbc: pystub(c, 0, this=True, ret=Z)}, nslots=0x50)
    w32u(E + 0x9b, T)
    w32u(E + 0x1907, G1)   # always set: the original reads [G1] again unguarded in state 1
    w32u(E + 0x1a9f, H if r.random() < 0.7 else 0)
    e.w32(0x70039c, E)
    # this fields
    idx = r.choice([0xffffffff, 0xffffffff, 0, 1, 2, 3])
    w32u(this + 0x1b4, idx)
    for i in range(4):
        w32u(this + 0x19c + 4 * i, rb())
    w32u(this + 0x1c5, r.choice([1, 2, 3, 4, 5, 6, 4, 6, 1, 0, 7, 0x100]))
    # name at [[this+0x44]+4]
    tgt = bytes(e.rbytes(0x6a77bc, 40)).split(b'\0')[0] + b'\0'
    nm = e.alloc(48, 4)
    ch = r.random()
    if ch < 0.5:
        e.wbytes(nm, tgt)
    elif ch < 0.65:
        e.wbytes(nm, tgt[:-2] + b'x\0')
    elif ch < 0.75:
        e.wbytes(nm, b'\0')
    else:
        e.wbytes(nm, r.randbytes(6) + b'\0')
    ob = rnd(c, 0x10)
    w32u(ob + 4, 0 if r.random() < 0.15 else nm)
    w32u(this + 0x44, ob)
    w32u(this + 0x90, rb())
    # float markers vs [0x678858]
    cst = bytes(e.rbytes(0x678858, 4))
    other = struct.pack('<f', r.choice([0.0, 2.0, -1.0, float('nan')]))
    e.wbytes(0x6ffa60, cst if r.random() < 0.5 else other)
    e.wbytes(0x700324, cst if r.random() < 0.5 else other)
    hook_rec(c, 0x563110, 2, pop=8, this=True)
    hook_rec(c, 0x56ad00, 1, pop=4, this=True)
    hook_rec(c, 0x595440, 2, pop=8, this=True)
    hook_rec(c, 0x4947c0, 1, pop=4, this=True)
    hook_rec(c, 0x56ac30, 0, pop=0, this=True)
    a2 = r.choice([0, 1, 1, 1, 0x100, 0x101, rb()])
    return [this, rb(), a2]


S(0x56a900, 'obj_state_handler', 'thiscall', None, ret=None, gen=g56a900)
