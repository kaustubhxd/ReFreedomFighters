"""specs_s213107.py - batch 213107: timed ring of ids with expiry pass and fade-out pass, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def fx(x):
    p = 0xf000 * x
    v = (p >> 10) & 0xffffffff
    sv = v - (1 << 32) if v & 0x80000000 else v
    return sv >> 10


def trunc(f):
    return int(f)


def g45c180(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    cap = r.choice([4, 8, 16, 32])
    head = r.randrange(cap)
    tail = head if r.random() < 0.15 else r.randrange(cap)
    keep = r.choice([0, 1, 2, cap // 2, cap, cap + 1, r.randrange(0, cap + 2)])
    tick = r.choice([r.randrange(0, 2000000), r.randrange(0, 5000), 0, 1 << 20])
    f2c = f32(r.choice([0.0, 1.0, 2.5, 10.0, r.uniform(0, 30)]))
    f28 = f32(r.choice([0.0, 0.5, 1.0, 5.0, r.uniform(0, 20)]))
    tmpA = fx(tick - trunc(f32(f2c * 1024.0)))
    tmpB = fx(tick - trunc(f32(f28 * 1024.0)))
    now = fx(tick)
    this = obj(c, 0x270, {0x220: pystub(c, 1, this=True), 0x218: pystub(c, 2, this=True)}, nslots=0x100)
    e.w32(this + 0x38, tail)
    e.w32(this + 0x3c, head)
    e.w32(this + 0x1c, cap)
    e.w32(this + 0x18, keep)
    e.wbytes(this + 0x2c, struct.pack('<f', f2c))
    e.wbytes(this + 0x28, struct.pack('<f', f28))
    e.w32(this + 0x24, r.getrandbits(32))
    e.w32(this + 0x30, r.randrange(0, 4))
    nid = r.choice([2, 3, 6])
    ids = bytes(r.randrange(nid) for _ in range(cap + 4))
    idp = e.alloc(len(ids) + 4, 4)
    e.wbytes(idp, ids)
    e.w32(this + 0x248, idp)
    stamps = bytearray()
    for i in range(256):
        v = r.choice([0, 0, tmpA, tmpA - 1, tmpA + 1, tmpB, tmpB - 1, tmpB + 1, now, r.randrange(-1000, 100000), r.getrandbits(32)])
        stamps += struct.pack('<I', v & 0xffffffff)
    sp = e.alloc(len(stamps), 4)
    e.wbytes(sp, bytes(stamps))
    e.w32(this + 0x250, sp)
    lp = e.alloc(4 * 300, 4)
    e.wbytes(lp, bytes(r.getrandbits(8) for _ in range(4 * 300)))
    e.w32(this + 0x24c, lp)
    hp = e.alloc(4 * 256, 4)
    e.wbytes(hp, b''.join(struct.pack('<I', 0 if r.random() < 0.15 else r.getrandbits(32)) for _ in range(256)))
    e.w32(this + 0x40, hp)
    # engine
    N2 = obj(c, 0x20, {0x40: pystub(c, 1, this=True)}, nslots=0x40)
    Mo = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=N2)}, nslots=0x40)
    eng = obj(c, 0x1a00, {}, nslots=4)
    e.w32(eng + 0x40, tick)
    e.w32(eng + 0x190f, Mo)
    e.w32(0x70039c, eng)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [this]


S(0x45c180, 'timed_ring_expire', 'thiscall', None, ret=None, gen=g45c180)
