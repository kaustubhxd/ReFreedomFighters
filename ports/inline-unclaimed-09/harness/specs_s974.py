"""specs_s974.py - area 56 band, claim A40 (0x536c40).

a is 0 in about half the cases; otherwise a is a random heap pointer. The global 0x70039c (g_pSysInterface) points to a fake object
(0x1000 random bytes) whose +0x9b dword points to a second fake object (0x1000 random bytes) whose +0xadc dword is random. 0x445c50 is
hooked (recording, returns a random dword, plain ret). ret='eax'."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h(e2, r):
        e2.calllog.append(('H445c50', e2.reg('ecx')))
        e2.ret(eax=rv, argbytes=0)

    rv = rng.getrandbits(32)
    e.hook(0x445c50, h)
    x = e.alloc(0x1000, 4)
    e.wbytes(x, bytes(rng.getrandbits(8) for _ in range(0x1000)))
    e.w32(x + 0xadc, rng.getrandbits(32))
    g = e.alloc(0x1000, 4)
    e.wbytes(g, bytes(rng.getrandbits(8) for _ in range(0x1000)))
    e.w32(g + 0x9b, x)
    e.w32(0x70039c, g)
    a = 0 if rng.random() < 0.5 else e.alloc(0x40, 4)
    return [a]


S(0x536c40, 'unnamed 0x536c40 (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A40; 0x445c50 hooked (CurrentRoom per 20-camera, not used)')
