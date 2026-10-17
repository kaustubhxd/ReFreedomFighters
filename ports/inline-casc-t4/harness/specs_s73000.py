from pilot import S
from recruits_util import rnd, clear_hooks


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    me = rnd(c, 0x100)
    # Exercise the append-in-capacity path, including the original null-end case.
    buf = rnd(c, 0x100)
    n = r.randrange(0, 7)
    start = buf
    end = 0 if r.random() < 0.08 else buf + 12 * n
    full = r.random() < 0.2
    cap = buf + 12 * n if full else buf + 12 * (n + r.randrange(1, 7))
    e.w32(me + 0x7c, start)
    e.w32(me + 0x80, end)
    e.w32(me + 0x84, cap)
    return [me, r.getrandbits(32)]


S(0x5f0700, 'GUESS append event record', 'thiscall', None, ret=None, gen=gen)
