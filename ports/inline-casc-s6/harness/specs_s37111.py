"""specs_s37111.py - cascade s6 batch 37111 (0x569df0, thiscall(reader) ret 4). The reader callees (0x4e5e60 dword, 0x4e5ea0 string) are hooks: the dword reader returns the
call number plus a random base (so every field receives a different value; a zero is injected for the flag read), the string reader returns null, an empty string or a short text;
0x41e290 hands out spec blocks and 0x610100 is a recording hook."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g569df0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = r.getrandbits(32)
    zero_at = r.choice([13, 99, 13])

    def dw(em, k):
        if k == zero_at:
            return 0
        return (base + 0x01010101 * k) & 0xffffffff
    hook_rec(c, 0x610100, 1, this=True)
    hook_rec(c, 0x4e5e60, 0, this=True, ret=dw)
    texts = [0, 0]
    for i in range(2):
        ch = r.choice(['null', 'empty', 'text', 'text'])
        if ch == 'null':
            texts[i] = 0
        elif ch == 'empty':
            a = e.alloc(8, 1)
            e.wbytes(a, b'\x00' + bytes(r.randrange(1, 255) for _ in range(7)))
            texts[i] = a
        else:
            n = r.randint(1, 9)
            a = e.alloc(0x20, 1)
            e.wbytes(a, bytes(r.randrange(1, 255) for _ in range(n)) + b'\x00' + bytes(r.randrange(1, 255) for _ in range(0x1e - n)))
            texts[i] = a
    hook_rec(c, 0x4e5ea0, 0, this=True, ret=lambda em, k: texts[k % 2])
    pool = [e.alloc(0x20, 4) for _ in range(2)]
    for p in pool:
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x20)))
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: pool[k % 2])
    t = rnd(c, 0x1d0)
    rd = rnd(c, 0x10)
    return [t, rd]


S(0x569df0, 'GUESS load_state', 'thiscall', None, ret=None, gen=_g569df0, note='batch37111')
