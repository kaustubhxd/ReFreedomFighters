"""specs_s4029.py - area 70 batch 4029: 0x562390 (GUESS name). Render-manager fake: slot 0x138 returns an object X (per case);
X's slot 0x88 writes the out value through its second argument (value logged, pointer not) and pops 8; the render manager's
slot 0x58 records its argument and returns a per-case value. The table index edi is drawn in 1..4 (the body indexes arr[edi-1])."""
import struct
from pilot import S, F


def _cache(c):
    e, r = c.emu, c.rng
    outv = r.getrandbits(32)
    ret58 = r.getrandbits(32)
    xvt = e.fake_vtable('x_562390', 0x23, {0x88: lambda em, rr: _x88(em, rr, outv)})
    x = e.alloc(0x40, 4)
    e.w32(x, xvt)
    rvt = e.fake_vtable('rm_562390', 0x4f, {
        0x138: lambda em, rr: em.ret(eax=x, argbytes=0),
        0x58: lambda em, rr: _s58(em, rr, ret58),
    })
    rm = e.alloc(0x40, 4)
    e.w32(rm, rvt)
    sys_ = e.alloc(0xc0, 16)
    e.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0xc0)))
    e.w32(sys_ + 0x9b, rm)
    e.w32(0x70039c, sys_)
    self_ = e.alloc(0x100, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    e.w32(self_ + 0xf8, 0 if r.random() < 0.8 else r.getrandbits(32))
    if r.random() < 0.5:
        m = e.alloc(0x700, 16)
        e.w32(m + 0x684, r.randrange(1, 5))
        e.w32(self_ + 0x90, m)
    else:
        e.w32(self_ + 0x90, 0)
    return [self_]


def _x88(em, rr, outv):
    out_ptr = em.arg32(1)
    em.calllog.append(('88', em.arg32(0)))
    em.wbytes(out_ptr, struct.pack('<I', outv))
    em.ret(argbytes=8)


def _s58(em, rr, ret58):
    em.calllog.append(('58', em.arg32(0)))
    em.ret(eax=ret58, argbytes=4)


S(0x562390, 'cache a render-manager value in [this+0xf8] (name GUESS)', 'thiscall', None, ret=None, gen=_cache,
  note='batch4029')
