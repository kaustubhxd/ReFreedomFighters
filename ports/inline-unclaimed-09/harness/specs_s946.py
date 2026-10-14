"""specs_s946.py - area 56 residue 15, claim A5: ZRunParamAnim::CreateAnims(CHUNKFILE*) (0x4e6e70).

The chunk file is 0x200 random bytes. Its +4 dword takes each of the four top-two-bit patterns (so both offset choices run),
and its +8 dword is a small even offset in [0, 0x40] (the copies read f+off and f+off+4, which stay inside the buffer). The
helper 0x4e6dc0 is a GUESS recording stub: it logs its object (heap) and its two arguments (the chunk file pointer and the
constant), and returns with ret 8."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng

    def h6dc0(e2, r):
        e2.calllog.append(('E4e6dc0', e2.reg('ecx'), e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    e.hook(0x4e6dc0, h6dc0)
    f = _rnd(c, 0x200)
    top = rng.choice([0x00000000, 0x40000000, 0x80000000, 0xc0000000])
    e.w32(f + 4, top | (rng.getrandbits(32) & 0x3fffffff))
    e.w32(f + 8, rng.randrange(0, 0x41, 4))
    this = _rnd(c, 0x100)
    return [this, f]


S(0x4e6e70, 'ZRunParamAnim::CreateAnims (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A5; helper 0x4e6dc0 is a GUESS recording stub (unverified)')
