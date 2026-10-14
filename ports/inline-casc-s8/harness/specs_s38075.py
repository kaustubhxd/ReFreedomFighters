"""specs_s38075.py - cascade s8 batch 38075. thiscall(this) void; this = 0x80-byte random block: unaligned handle +0x11, file object +0x15 (slots 0xc tell (stateful counter), 0x10 seek, 0x14 read (fills the buffer with bytes from the
position), 0x18 write (logs the written bytes; returns the count, sometimes off by one)), two tables (+0x5a base / +0x56 count 0..3 and +0x4e / +0x4a count 0..3) of 0x2a-byte entries with a name length word at +0x18 (0..40) and a
dword at +0x26. No stack address is logged: the written buffers are logged by content."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g4d7740(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pos = [r.getrandbits(16)]

    def tell(em, res_):
        pos[0] += r.randrange(0, 0x100)
        em.calllog.append(('tell', em.arg32(0)))
        em.ret(eax=pos[0], argbytes=4)

    def seek(em, res_):
        em.calllog.append(('seek', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)

    def read(em, res_):
        buf, n, h = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('read', n, h))
        em.wbytes(buf, bytes(r.getrandbits(8) for _ in range(n)))
        em.ret(eax=n, argbytes=12)

    def write(em, res_):
        buf, n, h = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('write', n, h, bytes(em.rbytes(buf, n))))
        em.ret(eax=(n if r.random() < 0.9 else n + r.choice([-1, 1])), argbytes=12)
    F = obj(c, 0x40, {0xc: e.stub_fn('tell', tell), 0x10: e.stub_fn('seek', seek), 0x14: e.stub_fn('read', read), 0x18: e.stub_fn('write', write)})
    this = rnd(c, 0x80)

    def table():
        n = r.choice([0, 1, 2, 3])
        arr = rnd(c, 0x2a * 3 + 8)
        for i in range(n):
            e.wbytes(arr + 0x2a * i + 0x18, struct.pack('<H', r.randrange(0, 41)))
            e.wbytes(arr + 0x2a * i + 0x26, struct.pack('<I', r.randrange(0, 0x1000)))
        return arr, n
    a1, n1 = table()
    a2, n2 = table()
    for off, v in ((0x11, r.getrandbits(32)), (0x15, F), (0x5a, a1), (0x56, n1), (0x4e, a2), (0x4a, n2)):
        e.wbytes(this + off, struct.pack('<I', v))
    return [this]


S(0x4d7740, 'GUESS zip central directory writer', 'thiscall', None, ret=None, gen=_g4d7740, note='batch38075')
