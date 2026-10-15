"""specs_s34162.py - tier H. 0x484ff0: hooked 0x443ef0 (writes a random vector through its stack pointer ecx; args logged), this slot 0x20 returns an object with slot 0x7c (2 args, the vector logged through deref), /GS check keeping eax, float at the unaligned +0x451. 0x48f7e0: float +0x10 equal to 2.0 in half, hooked 0x494b40 / 0x494ac0, p with slots 0x5c (3 args) and 0x14."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g484ff0(c):
    clear_hooks(c)
    r = c.rng

    def fill(em, k):
        ptr = em.reg('ecx')
        em.wbytes(ptr, b''.join(r.getrandbits(32).to_bytes(4, 'little') for _ in range(4)))
    hook_rec(c, 0x443ef0, 2, this='mark', pop=8, side=fill)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    o = obj(c, 0x20, {0x7c: pystub(c, 2, this=True, deref={1: 4}, ret=r.getrandbits(32))}, nslots=0x80 // 4)
    me = obj(c, 0x470, {0x20: pystub(c, 0, this=True, ret=o)}, nslots=0x24 // 4)
    c.emu.wbytes(me + 0x451, _fbits(r).to_bytes(4, 'little'))
    return [me, rnd(c, 0x40), r.getrandbits(32)]


def _g48f7e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x494b40, 1, this=True)
    hook_rec(c, 0x494ac0, 1, this=True)
    p = obj(c, 0x20, {0x5c: pystub(c, 3, this=True), 0x14: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))}, nslots=0x60 // 4)
    me = rnd(c, 0x40)
    two = struct.unpack('<I', struct.pack('<f', 2.0))[0]
    c.emu.w32(me + 0x10, two if r.random() < 0.5 else (0xffffffff if r.random() < 0.1 else _fbits(r)))
    return [me, p]


S(0x484ff0, 'GUESS build vector and hand to slot', 'thiscall', None, ret=None, gen=_g484ff0, note='batch34162')
S(0x48f7e0, 'GUESS react when value is 2.0', 'thiscall', None, ret=None, gen=_g48f7e0, note='batch34162')
