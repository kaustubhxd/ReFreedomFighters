"""specs_s8806.py - hitreact batch 8806: ZFFActorActionCloseCombat::Execute (0x5eb020). Exe code in both builds: PSVECSubtract
0x43e920, createmat 0x4de040, vaddscalar4 0x443ef0. ZBoneAnim::AddCallBackAlways 0x461570 is patched to a recording stub. The
attacker's GetRootTM (slot 0x80) and the target's root point (slot 0x84) fill per-case values; placement (slot 0x238) records
the matrix and point it gets."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge
from dkit import patch_jmp
from hkit import rec_stub, fvec


def _handle_stub(c):
    cnt = c.emu.alloc(4, 4)
    code = b'\xff\x05' + struct.pack('<I', cnt) + b'\x8b\x44\x24\x04\x35' + struct.pack('<I', 0x55aa0000) + b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _hdr(c):
    r = c.rng
    h = rnd(c, 0x80)
    c.emu.w32(h + 0x60, r.randrange(-5, 30) & 0xffffffff)
    c.emu.w32(h + 0x64, r.randrange(0, 60) & 0xffffffff)
    c.emu.w32(h + 0x6c, r.choice((25, 30, 15, 24, 0, r.randrange(-10, 100))) & 0xffffffff)
    return h


def _gen(c):
    r = c.rng
    emu = c.emu
    fv = lambda: r.choice((r.uniform(-500, 500), 0.0, fedge(c)))
    A = [fv() for _ in range(3)]
    B = [fv() for _ in range(3)]
    if r.random() < 0.15:
        B[0] = A[0]; B[2] = A[2]                 # x and z equal: no normalisation
    mat = fvec(c, [r.uniform(-1, 1) for _ in range(9)])
    pa = fvec(c, A)
    pb = fvec(c, B)
    patch_jmp(c, 0x461570, rec_stub(c, 3))
    bone = rnd(c, 0x40)
    at = obj(c, 0x800, {
        0x80: rec_stub(c, 2, skip=(0, 1), fills={0: (mat, 9, 0), 1: (pa, 3, 0)}),
        0x228: rec_stub(c, 5, ret=bone if r.random() < 0.85 else 0),
        0x238: rec_stub(c, 3, ptrs={0: [(4 * i, 'd') for i in range(9)], 1: [(0, 'd'), (4, 'd'), (8, 'd')]}),
        0x6b0: rec_stub(c, 0, ret=r.getrandbits(32)),
        0x704: rec_stub(c, 1),
    })
    tg = obj(c, 0x200, {0x84: rec_stub(c, 1, skip=(0,), fills={0: (pb, 3, 0)}), 0x128: rec_stub(c, 3)})
    rm = obj(c, 0x80, {0x4c: _handle_stub(c)})
    eng = rnd(c, 0x100)
    emu.w32(eng + 0x40, r.randrange(0, 1 << 24))
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    emu.w16(0x7143a4, r.getrandbits(16))
    self = rnd(c, 0x60)
    emu.w32(self + 8, at)
    emu.w32(self + 0xc, tg)
    emu.w32(self + 0x10, _hdr(c))
    emu.w32(self + 0x14, _hdr(c))
    emu.w32(self + 0x18, r.choice((0, 0, 1, 1, 2, r.getrandbits(32))))
    emu.mu.ctl_flush_tb()
    return [self]


S(0x5eb020, 'ZFFActorActionCloseCombat::Execute', 'thiscall', ret='al', gen=_gen)
