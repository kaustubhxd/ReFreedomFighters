"""specs_s34156.py - tier H batch. 0x528ae0: floats at +0x7c/+0x80/+0x22c4/+0x22c8, unaligned ids at +0x21a5/+0x21a9, 0x528f50 hooked (stdcall 2 args, ecx recorded). 0x656ac0: two float blocks A (dest) and B. 0x515950: kind 1 / 4 / 2 / other. 0x59d4e0: register args begin/edx=end and dest, 0..3 blocks (dest buffer well above). 0x4bdc70: constructor over a random block, 0x469870 hooked. 0x5510a0: chain of objects, hooked 0x5003d0 / 0x500360. 0x656200: slot 0x50 logs the 8-dword request."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r, center=None):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif center is not None and k < 0.5:
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 0.5])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g528ae0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x528f50, 2, this=True, pop=8, ret=r.getrandbits(32))
    me = rnd(c, 0x22e0)
    for off in (0x7c, 0x80, 0x22c4, 0x22c8):
        c.emu.wbytes(me + off, _fbits(r).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x21a5, r.getrandbits(32).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x21a9, r.getrandbits(32).to_bytes(4, 'little'))
    return [me]


def _g656ac0(c):
    clear_hooks(c)
    r = c.rng
    A, B = rnd(c, 0x40), rnd(c, 0x40)
    if r.random() < 0.1:
        A = B
    for off in (0x10, 0x14):
        c.emu.w32(B + off, r.getrandbits(32))
    lo = r.uniform(-50, 50)
    c.emu.w32(B + 0x1c, struct.unpack('<I', struct.pack('<f', lo + 1.0))[0] if r.random() < 0.6 else _fbits(r))
    c.emu.w32(B + 0x18, struct.unpack('<I', struct.pack('<f', lo + r.choice([-1, 0, 0.5, 2.0])))[0] if r.random() < 0.6 else _fbits(r))
    return [A, B]


def _g515950(c):
    clear_hooks(c)
    r = c.rng
    ch = obj(c, 0x20, {0x8: pystub(c, 2, this=True, ret=r.getrandbits(32))}, nslots=0xc // 4)
    cc = rnd(c, 0x70)
    c.emu.wbytes(cc, ch.to_bytes(4, 'little') + bytes(0x60 - 4) if False else b'')
    # object block whose first dword is the vtable pointer of ch
    blk = rnd(c, 0x70)
    c.emu.w32(blk, c.emu.r32(ch))
    c.emu.wbytes(blk + 0x35, r.choice([1, 1, 4, 4, 2, 0, 7]).to_bytes(4, 'little'))
    c.emu.wbytes(blk + 0x39, r.choice([0, 1, 2, 2, 3]).to_bytes(4, 'little'))
    for off in (0x5f, 0x5b, 0x57):
        c.emu.wbytes(blk + off, _fbits(r).to_bytes(4, 'little'))
    me = rnd(c, 0xd0)
    c.emu.w32(me + 0x5c, blk)
    c.emu.w32(me + 0xc0, _fbits(r))
    return [me]


def _g59d4e0(c):
    clear_hooks(c)
    r = c.rng
    nblk = r.choice([0, 1, 2, 3, -1])
    src = rnd(c, 0x200)
    begin = src
    end = src + (nblk * 0x40 if nblk >= 0 else -0x40) + r.choice([0, 0, 5, 0x3f])
    dest = rnd(c, 0x400) + 0x300
    if r.random() < 0.15:
        dest = src + max(nblk, 1) * 0x40 + 0x10 * r.randrange(4)   # overlapping move inside the block
    return [begin, end & 0xffffffff, dest]


def _g4bdc70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x469870, 0, this=True, pop=0)
    return [rnd(c, 0x100)]


def _g5510a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5003d0, 1, this=True, ret=rnd(c, 0x10))
    hook_rec(c, 0x500360, 1, this=True, ret=r.getrandbits(32))
    o = obj(c, 0x20, {}, nslots=1)
    s = obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=o)}, nslots=0x50 // 4)
    a = obj(c, 0x20, {0x18: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, s, s]))}, nslots=0x1c // 4)
    pf = rnd(c, 0x10)
    c.emu.w32(pf, _fbits(r))
    return [a, r.getrandbits(32), pf]


def _g656200(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x20, {0x50: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32), deref={0: 8})}, nslots=0x54 // 4)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x528ae0, 'GUESS accumulate and forward two floats', 'thiscall', None, ret=None, gen=_g528ae0, note='batch34156')
S(0x656ac0, 'GUESS clamp range copy', 'stdcall', None, ret=None, gen=_g656ac0, note='batch34156')
S(0x515950, 'GUESS forward by kind', 'thiscall', None, ret=None, gen=_g515950, note='batch34156')
S(0x59d4e0, 'GUESS copy blocks backward', ('regs', ['ecx', 'edx', 's']), None, ret='eax', gen=_g59d4e0, note='batch34156')
S(0x4bdc70, 'GUESS construct object', 'thiscall', None, ret='eax', gen=_g4bdc70, note='batch34156')
S(0x5510a0, 'GUESS look up and forward float', 'stdcall', None, ret='eax', gen=_g5510a0, note='batch34156')
S(0x656200, 'GUESS build request', 'thiscall', None, ret='eax', gen=_g656200, note='batch34156')
