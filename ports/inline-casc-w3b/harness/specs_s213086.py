"""specs_s213086.py - batch 213086: object serializer into a stream object, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5f92c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    Sx = obj(c, 0x20, {0x38: sl(1), 0x2c: sl(1), 0x28: sl(1), 0x24: sl(1), 0x48: sl(2)}, nslots=0x60)
    this = obj(c, 0x100, {0x28: sl(0)}, nslots=0x40)
    e.w32(this + 0x96, rnd(c, 0x10)[0] if False else r.getrandbits(32))
    e.w32(this + 0x64, r.getrandbits(32))
    for off in (0xaa, 0xac, 0xb2, 0xb4, 8):
        e.wbytes(this + off, struct.pack('<H', r.getrandbits(16)))
    e.wbytes(this + 0xa, struct.pack('<I', r.getrandbits(32)))
    e.wbytes(this + 0xe, struct.pack('<I', r.getrandbits(32)))
    e.wbytes(this + 0x16, struct.pack('<I', r.choice([0, 0, 0x1234, r.getrandbits(32)])))
    e.w32(this + 0x24, r.getrandbits(32))
    e.w32(this + 0x20, r.choice([0, 0, 1, r.getrandbits(32)]))
    n = r.choice([0, 0, 1, 2, 3, 5])
    kids = [obj(c, 0x20, {0xc: sl(2)}, nslots=0x20) for _ in range(n)]
    arr = rnd(c, 4 * 8 + 4)
    for i, k in enumerate(kids):
        e.w32(arr + 4 * i, k)
    e.w32(this + 0x4c, arr)
    e.w32(this + 0x54, n)
    e.w32(this + 0x9e, r.getrandbits(32))
    e.w32(this + 0xa2, r.getrandbits(32))
    hook_rec(c, 0x600820, 1, this=True)
    hook_rec(c, 0x5f4940, 1, this=True)
    hook_rec(c, 0x5f9450, 3, this=True)
    hook_rec(c, 0x600810, 0, this=True)
    hook_rec(c, 0x600860, 3, this=True)
    return [this, Sx, r.getrandbits(32)]


S(0x5f92c0, 'serialize_object', 'thiscall', None, ret=None, gen=g5f92c0)
