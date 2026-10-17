"""specs_s1223.py - pathfinding batch 1223: ZPFOctree_packed::SerializeData(blob, mode, bool) (0x531270).

Real exe code: memcpy (0x634d22) and the allocator through new (0x41e290). The debug logs run when 0x701b5d is set.
"""
import struct
from pilot import S
from pfspec import rnd, reporter, allocator
import pilot


def u16(v):
    return struct.pack('<H', v & 0xffff)


def _oct(c, blob_len=0x4000):
    """Random but well-formed blob: returns (blob bytes, counts dict) for the layout in batch1223.cpp."""
    r = c.rng
    A = r.randint(1, 4)
    B = r.randint(0, 3)
    C = r.randint(0, 3)
    D = r.randint(0, 3)
    E = r.randint(0, 3)
    F = r.randint(0, 3)
    G = r.randint(0, 3)
    H = r.randint(0, 3)
    I = r.randint(0, 3)
    J = r.randint(0, 3)
    flag4 = r.random() < 0.6
    flag5 = r.random() < 0.5
    rb = lambda n: bytes(r.getrandbits(8) for _ in range(n))
    b = bytearray()
    b += struct.pack('<I', r.choice([0x1923482, 0x1923483, 0x1923484]))
    b += u16(A) + u16(B) + rb(B * 0x16)
    b += u16(C) + rb(C * 12)
    b += u16(D) + rb(D * A * 4)
    b += u16(E) + rb(E * 4)
    b += u16(F) + rb(F * 10)
    b += u16(G) + rb(G * 12)
    if flag4:
        b += rb(G * 4)
        if flag5:
            b += rb(G * 24)
    b += u16(H) + rb(H * 4)
    b += u16(I) + rb(I * 10) + rb(I)
    b += u16(J) + rb(J)
    b += rb(0x44)
    return bytes(b), flag4, flag5


def _memcpy_stub(e):
    """VCRUNTIME140 memcpy (cdecl: dst, src, n) as a Python stub; the same in both builds."""
    def h(em, rr):
        dst, src, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n:
            em.wbytes(dst, em.rbytes(src, n))
        em.ret(eax=dst, argbytes=0)
    e.stub_import('memcpy', h)


def _sd(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    allocator(c)
    _memcpy_stub(e)
    e.w8(0x701b5d, r.choice([0, 0, 1]))
    blob, flag4, flag5 = _oct(c)
    buf = e.alloc(len(blob) + 32, 16)
    e.wbytes(buf, blob)
    oct_ = e.alloc(0xd20, 4)
    e.wbytes(oct_, bytes(0xd20))
    e.w8(oct_ + 4, 1 if flag4 else 0)
    e.w8(oct_ + 5, 1 if flag5 else 0)
    # arrays already there (mode 2 copies into them): big enough for every count
    for off in (0x54, 0x5a, 0x72, 0x60, 0x66, 0x88, 0x8c, 0x90, 0x6c, 0x78, 0x7c, 0x82):
        e.w32(oct_ + off, e.alloc(0x400, 16))
    mode = r.choice([1, 1, 2])
    return [oct_, buf, mode, r.choice([0, 1])]   # the bool argument (ret 0xc)


S(0x531270, 'ZPFOctree_packed::SerializeData', 'thiscall', None, ret='eax', gen=_sd, n=200)
