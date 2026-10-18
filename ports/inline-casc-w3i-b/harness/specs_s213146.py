"""specs_s213146.py - batch 213146: tagged stream cursor move (type-class size tables, attached records, backward walk), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g4e1620(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    cls = [0, 1, 1, 2, 2, 4, 3, 1, 3, 1, 1, 3]
    buf = bytearray()
    nrec = r.choice([0, 1, 2, 3, 5, 8, 12, 20, 30])
    starts = []
    for i in range(nrec):
        starts.append(len(buf))
        roll = r.random()
        if roll < 0.04:
            t = 0xff
        elif roll < 0.12:
            t = 6 | (0x40 if r.random() < 0.3 else 0) | (r.choice([0, 0x80]))
        elif roll < 0.18:
            t = r.choice([0, 13, 40, 63]) | (0x40 if r.random() < 0.3 else 0) | r.choice([0, 0x80])
        else:
            t = r.randrange(1, 13)
            if t == 6:
                t = 7
            t |= (0x40 if r.random() < 0.3 else 0) | r.choice([0, 0, 0x80])
        buf.append(t)
        if t == 0xff:
            continue
        ty = t & 0x3f
        if 1 <= ty <= 12:
            k = cls[ty - 1]
            if k == 0:
                buf += bytes(r.getrandbits(8) for _ in range(8))
            elif k == 1:
                buf += bytes(r.getrandbits(8) for _ in range(4))
            elif k == 2:
                buf += bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 3, 6]))) + b'\0'
            elif k == 3:
                pl = r.choice([4, 4, 5, 8, 12, 0, 1, 3])
                buf += struct.pack('<I', pl) + bytes(r.getrandbits(8) | 0x01 for _ in range(max(0, pl - 4)))
    buf += b'\xff' * 24
    base = e.alloc(len(buf) + 16, 4)
    e.wbytes(base, bytes(buf))
    start = base + (r.choice(starts) if starts and r.random() < 0.3 else 0)
    this = rnd(c, 0x40)
    e.w32(this + 8, start)
    n = r.choice([0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 7, -8, r.randint(-12, 12), r.randint(-30, 30)])
    return [this, n & 0xffffffff]


S(0x4e1620, 'stream_seek', 'thiscall', None, ret='al', gen=g4e1620, stack_arg_bytes=4)
