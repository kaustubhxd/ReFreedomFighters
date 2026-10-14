"""specs_s936.py - unclaimed-09 batch 28 (docs/20-unclaimed-09.md, claim 30): ZOnScreenDisplay::DrawBufferViewUpdate.

GUESS recording stubs (unverified callees), both hooked with emu.hook:
- 0x4de7a0 (thiscall, the constructor on the local struct): writes a random 0x30-byte pattern into the struct at ecx and logs
  the pattern (the struct is compared by its bytes, not its stack address).
- 0x5a76c0 (thiscall, four arguments, the draw helper): logs ecx (the view object, a heap value), its two arguments, the 34
  bytes of the struct it is given and the dword behind its second pointer; then writes a random dword there and returns with
  ret 16 (the four arguments are popped by the callee).
The view object is 0x100 random bytes (heap, stable across exe and port)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    pattern = bytes(rng.getrandbits(8) for _ in range(0x30))
    qval = rng.getrandbits(32)

    def hctor(e2, r):
        this = e2.reg('ecx')
        e2.wbytes(this, pattern)
        e2.calllog.append(('Ctor4de7a0', pattern))
        e2.ret(argbytes=0)

    def hdraw(e2, r):
        this = e2.reg('ecx')
        a0, a1, p, q = e2.arg32(0), e2.arg32(1), e2.arg32(2), e2.arg32(3)
        e2.calllog.append(('Draw5a76c0', this, a0, a1, bytes(e2.rbytes(p, 0x30)), int.from_bytes(e2.rbytes(q, 4), 'little')))
        e2.w32(q, qval)
        e2.ret(eax=0, argbytes=16)

    e.hook(0x4de7a0, hctor)
    e.hook(0x5a76c0, hdraw)
    return [_rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5a7640, 'ZOnScreenDisplay::DrawBufferViewUpdate (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b28; GUESS recording stubs for 0x4de7a0 (ctor) and 0x5a76c0 (draw helper)')
