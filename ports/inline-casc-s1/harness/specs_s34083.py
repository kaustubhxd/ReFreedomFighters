"""specs_s34083.py - six queue items. 0x65a5d0 uses the register ABI (ecx, edx, stack dword) with n in 1..12 (n + 3 >> 2 is never zero); 0x530890 uses bit offsets up to 0x100 and counts 0..6; 0x62c5b0 compares strings that are equal up to case in half the cases."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _filt(ids):
    def g(c):
        clear_hooks(c)
        r = c.rng
        a = rnd(c, 0x20)
        c.emu.w32(a + 0xc, r.choice([0, 0, 1, r.getrandbits(32)]))
        return [a, r.choice(ids + [0xf, 0x1c, 0x1c, 0, 0x1d, r.getrandbits(32), 0xffffffff])]
    return g


def _g530890(c):
    clear_hooks(c)
    r = c.rng
    bm = rnd(c, 0x400)
    if r.random() < 0.3:
        c.emu.wbytes(bm, bytes(r.choice([0, 0xff, 0x55]) for _ in range(0x400)))
    return [bm, r.choice([0, 1, 5, 31, 32, 63, 64, 0x7f, 0x100, r.randrange(0, 0x200)]), r.choice([0, 1, 2, 3, 4, 6, 0xffffffff, 0xfffffff0])]


def _g62c5b0(c):
    clear_hooks(c)
    r = c.rng
    alpha = bytes(range(0x40, 0x5b)) + bytes(range(0x60, 0x7b)) + b'0-_[]@`{'
    n = r.choice([0, 1, 3, 6])
    base = bytes(r.choice(alpha) for _ in range(n))
    s1 = rnd(c, 0x20)
    s2 = rnd(c, 0x20)
    other = bytes(b ^ 0x20 if r.random() < 0.5 and (0x41 <= b <= 0x5a or 0x61 <= b <= 0x7a) else b for b in base)
    if r.random() < 0.4 and other:
        k = r.randrange(len(other))
        other = other[:k] + bytes([r.choice(alpha)]) + other[k + 1:]
    if r.random() < 0.15:
        other = other + b'x'
    c.emu.wbytes(s1, base + b'\0')
    c.emu.wbytes(s2, other + b'\0')
    return [s1, s2]


def _g65a5d0(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x140), rnd(c, 0x10), r.choice([1, 2, 3, 4, 5, 8, 9, 12])]


S(0x62cc00, 'GUESS event filter G', 'cdecl', None, ret='eax', gen=_filt([0x15, 0x18]), note='batch34083')
S(0x62d790, 'GUESS event filter H', 'cdecl', None, ret='eax', gen=_filt([0x12, 0x16]), note='batch34083')
S(0x62d1b0, 'GUESS event filter I', 'cdecl', None, ret='eax', gen=_filt([0x11, 0x19]), note='batch34083')
S(0x530890, 'GUESS gather strided bits', 'stdcall', None, ret='eax', gen=_g530890, note='batch34083')
S(0x62c5b0, 'GUESS case-insensitive equal', 'cdecl', None, ret='eax', gen=_g62c5b0, note='batch34083')
S(0x65a5d0, 'GUESS paddw broadcast add', ('regs', ['ecx', 'edx', 's']), None, ret=None, gen=_g65a5d0, note='batch34083')
