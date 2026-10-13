"""specs_s4111.py - unclaimed-41 batch 11 (slice 13): 0x5fa0d0 (thiscall, two stack arguments: s, flag; ret 8; returns eax).

Table t = this+4: t+0x14 = n (0..5 entries), t+0xc = arr. Entry e = arr[i]: e[0] = P (a random string over 'abc', length 0..8, NUL
not stored), e[4] = Q = P + length (so L = length). The query s is a copy of an entry's string half of the time and a random
string over 'abc' (length 0..8) otherwise, NUL terminated. The flag is random.
The error hook at 0x7003b0 is set in every case to a counter stub (inc dword [count]; ret), so its calls are visible in the heap:
the exe traps (int3) when the flag is set and the hook is zero, and that trap is not modelled. Faulting cases must be 0 (JSON)."""
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _word(c):
    n = c.rng.randint(0, 8)
    return bytes(c.rng.choice(b'abc') for _ in range(n))


def _lookup(c):
    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    # the hook: inc dword [hook_cnt]; ret (its call count lands in the heap, so a call or a missing call is visible)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + ss.P(hook_cnt) + b'\xc3'))
    self_ = _rnd(c, 0x100)
    t = _rnd(c, 0x40)
    n = c.rng.randint(0, 5)
    arr = c.emu.alloc(4 * max(n, 1), 4)
    words = []
    for i in range(n):
        w = _word(c)
        words.append(w)
        buf = c.emu.alloc(len(w) + 1, 1)
        c.emu.wbytes(buf, w)
        e = c.emu.alloc(8, 4)
        c.emu.w32(e, buf)
        c.emu.w32(e + 4, buf + len(w))
        c.emu.w32(arr + 4 * i, e)
    c.emu.w32(t + 0xc, arr)
    c.emu.w32(t + 0x14, n)
    c.emu.w32(self_ + 4, t)
    if n > 0 and c.rng.random() < 0.5:
        q = words[c.rng.randrange(n)]
    else:
        q = _word(c)
    sbuf = c.emu.alloc(len(q) + 1, 1)
    c.emu.wbytes(sbuf, q + b'\x00')
    return [self_, sbuf, c.rng.getrandbits(32) & 0xff | (c.rng.getrandbits(1) << 8)]


S(0x5fa0d0, 'findName5fa0d0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_lookup,
  note='unclaimed-41 batch 11; linear name lookup; error hook set to ret')
