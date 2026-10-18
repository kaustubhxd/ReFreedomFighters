"""specs_s213079.py - batch 213079: pointer ray update with picker call and fallbacks, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g595250(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    rb = lambda emu, k: r.choice([0, 0, 0, 1, 0x100, 0xff, r.getrandbits(32)])
    rb2 = lambda emu, k: r.choice([0, 1, 0x100, 0x200, r.getrandbits(32)])

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))

    def pos_side(emu, k):
        if r.random() < 0.5:
            emu.wbytes(emu.arg32(0), struct.pack('<fff', r.uniform(-9, 9), r.uniform(-9, 9), r.uniform(-9, 9)))

    def hit_side(emu, k):
        emu.wbytes(emu.arg32(0) + 8, struct.pack('<f', r.choice([0.0, 1.0, r.uniform(-9, 9), float('nan')])))
    E1 = rnd(c, 0x20)
    E2 = rnd(c, 0x20)
    E3 = rnd(c, 0x20)
    Es = [E1, E2, E3]
    C = obj(c, 0x30, {0x94: pystub(c, 0, ret=lambda emu, k: Es[k % 3], this=True)}, nslots=0x60)
    D = obj(c, 0x20, {0x30: sl(8, rb, deref={0: 1, 2: 3, 3: 3}, side=hit_side)}, nslots=0x40)
    e.w32(C + 0x1c, D)
    eng = rnd(c, 0x1b00)
    e.w32(eng + 0x1aa3, C)
    e.w32(0x70039c, eng)
    X = rnd(c, 0x80)
    e.w32(X + 0x60, r.choice([0, 10, 100, r.getrandbits(32)]))
    e.w32(X + 0x64, r.choice([0, 20, 1000, r.getrandbits(32)]))
    e.w32(X + 0x6c, r.choice([1, 2, 3, 7, 0xffffffff, r.getrandbits(32) | 1]))
    if struct.unpack('<i', struct.pack('<I', (struct.unpack('<I', bytes(e.rbytes(X + 0x64, 4)))[0] - struct.unpack('<I', bytes(e.rbytes(X + 0x60, 4)))[0]) & 0xffffffff))[0] == -2**31:
        e.w32(X + 0x6c, 3)
    B = obj(c, 0x20, {0x34: sl(0, rb2), 0x38: sl(0, rb2), 0x30: sl(4, rb)}, nslots=0x40)
    this = obj(c, 0xa40, {0x254: sl(0, rb2), 0x84: sl(1, nullflag=(0,), side=pos_side), 0x21c: sl(1, lambda emu, k: 0 if r.random() < 0.3 else X),
                          0x230: sl(2), 0x220: sl(1)}, nslots=0x90)
    e.w32(this + 0x6c, B)
    e.wbytes(this + 0x9e7, bytes([r.choice([0, 1, 1, 0xff])]))
    hook_rec(c, 0x466c10, 3, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x595250, 'pointer_ray_update', 'thiscall', None, ret=None, gen=g595250)
