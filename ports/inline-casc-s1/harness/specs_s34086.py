"""specs_s34086.py - five queue items.
0x53aa10: circular list of 1..4 nodes (+0xc next, last link null in a half, head = unaligned [this+0xe] = first node); each node reaches flags through +4, +8, +0x3c; start null in a quarter; want byte 0 / 1 / other.
0x65a540: register ABI (ecx = dst, edx = src) + (mul pointer, n); n in 1..12. 0x651db0: engine object with fields equal to the argument in a half of the cases. 0x54a170: random blocks. 0x5b1250: 0..4 names, key equal to one in a half."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g53aa10(c):
    clear_hooks(c)
    r = c.rng
    k = r.randrange(1, 5)
    nodes = [rnd(c, 0x20) for _ in range(k)]
    for i, n in enumerate(nodes):
        a = rnd(c, 0x20)
        b = rnd(c, 0x50)
        c.emu.w32(b + 0x3c, r.getrandbits(32) if r.random() < 0.7 else r.choice([0x1000, 0x800, 0x1800, 0]))
        c.emu.w32(a + 8, b)
        c.emu.w32(n + 4, a)
        nxt = nodes[(i + 1) % k] if (i < k - 1 or r.random() < 0.5) else 0
        c.emu.w32(n + 0xc, nxt)
    me = rnd(c, 0x20)
    c.emu.wbytes(me + 0xe, nodes[0].to_bytes(4, 'little'))
    start = 0 if r.random() < 0.25 else r.choice(nodes)
    if start == 0 and r.random() < 0.4:
        c.emu.wbytes(me + 0xe, bytes(4))
    return [me, start, r.choice([0, 1, 1, 0x100, 0x101, r.getrandbits(32)])]


def _g65a540(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x140), rnd(c, 0x140), rnd(c, 0x10), r.choice([1, 2, 3, 4, 5, 8, 9, 12])]


def _g651db0(c):
    clear_hooks(c)
    r = c.rng
    so = rnd(c, 0x1f00)
    c.emu.w32(0x70039c, so)
    a = rnd(c, 0x10)
    for off, aoff in ((0x6f, 0), (0x73, 4), (0x7f, 8)):
        if r.random() < 0.5:
            c.emu.wbytes(so + off, bytes(c.emu.rbytes(a + aoff, 4)))
    c.emu.wbytes(so + 0x63, bytes([r.choice([0, 1, 0, 1, 5])]))
    c.emu.w32(a + 0xc, r.choice([0, 1, r.getrandbits(32)]))
    return [a]


def _g54a170(c):
    clear_hooks(c)
    return [rnd(c, 0x70), rnd(c, 0x80)]


def _g5b1250(c):
    clear_hooks(c)
    r = c.rng
    alpha = b'abAB'
    mk = lambda n: bytes(r.choice(alpha) for _ in range(n))
    key = mk(r.choice([0, 1, 2, 3]))
    kp = rnd(c, 0x10)
    c.emu.wbytes(kp, key + b'\0')
    me = rnd(c, 0x5e0)
    n = r.choice([0, 1, 2, 4, 0xffffffff])
    c.emu.w32(me + 0x5b8, n)
    for i in range(4):
        nm = key if r.random() < 0.3 else mk(r.choice([0, 1, 2, 3]))
        sp = rnd(c, 0x10)
        c.emu.wbytes(sp, nm + b'\0')
        c.emu.w32(me + 8 + 4 * i, sp)
    return [me, kp]


S(0x53aa10, 'GUESS next matching node in circular list', 'thiscall', None, ret='eax', gen=_g53aa10, note='batch34086')
S(0x65a540, 'GUESS pmulhw scaled add', ('regs', ['ecx', 'edx', 's', 's']), None, ret=None, gen=_g65a540, note='batch34086')
S(0x651db0, 'GUESS sync engine state', 'stdcall', None, ret=None, gen=_g651db0, note='batch34086')
S(0x54a170, 'GUESS copy selected fields', 'stdcall', None, ret='eax', gen=_g54a170, note='batch34086')
S(0x5b1250, 'GUESS mark named entry', 'thiscall', None, ret=None, gen=_g5b1250, note='batch34086')
