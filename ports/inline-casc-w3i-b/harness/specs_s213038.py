"""specs_s213038.py - batch 213038: state refresh with engine lookup and logging paths, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g55b120(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec = rnd(c, 0x10)
    e.wbytes(rec + 4, bytes([r.choice([0, 1, 0, 1, 2, 5, 0xff, r.getrandbits(8)])]))
    e.w32(rec, r.choice([0, 1, r.getrandbits(32)]))
    rets = [rec, r.getrandbits(32), r.getrandbits(32)]
    hook_rec(c, 0x5003d0, 1, ret=lambda emu, k: rets[min(k, 2)], this=True)
    hook_rec(c, 0x5002f0, 1, ret=r.getrandbits(32), this=True)
    blk = rnd(c, 0x7a0)
    e.wbytes(blk + 0x78a, struct.pack('<I', r.choice([0, 0, r.getrandbits(32)])))
    e.wbytes(blk + 0x78e, struct.pack('<I', r.choice([0, 0, r.getrandbits(32)])))
    this = rnd(c, 0x40)
    e.w32(this + 0x1c, blk)
    k = r.randint(0, 14) if r.random() < 0.9 else r.getrandbits(32)
    node = obj(c, 0x20, {0x330: pystub(c, 0, ret=k, this=True)}, nslots=0xcd)
    nodep = node if r.random() < 0.9 else 0
    A = obj(c, 0x20, {0x2e8: pystub(c, 0, ret=nodep, this=True)}, nslots=0xbb)
    tab = obj(c, 0x40, {0x58: pystub(c, 1, ret=A, this=True)}, nslots=0x18)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, tab)
    M = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    L = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, L)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    a = rnd(c, 0x20)
    return [this, a]


S(0x55b120, 'refresh_state', 'thiscall', None, ret='eax', gen=g55b120)
