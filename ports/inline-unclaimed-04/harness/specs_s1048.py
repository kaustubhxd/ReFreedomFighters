"""specs_s1048.py - unclaimed-04 batch 48 (docs/20-unclaimed-04.md): two thiscall functions, two stack arguments (ret 8).
0x56fa70 returns al = 0: calls 0x562e90(a, b); when the low byte of b is non-zero it calls 0x56f2d0 and clears this+0x1ed;
it always clears this+0x196.
0x574e30 has no return value: when this+0x88 is non-zero it calls 0x573930(a, b); then when b == 2 and this+0x21b is
non-zero it calls 0x574ff0.
All four helpers are hooked by address with logging stubs (GUESS: their bodies are not ported). Objects are random bytes: 0x200 for 0x56fa70, 0x240 for 0x574e30 (it reads this+0x21b)."""
from pilot import S


def _log(c, name, nargs, argbytes):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx'), tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=0, argbytes=argbytes)
    return h


def _setup56(c):
    c.emu.hook(0x562e90, _log(c, '562e90', 2, 8))
    c.emu.hook(0x56f2d0, _log(c, '56f2d0', 0, 0))


def _setup57(c):
    c.emu.hook(0x573930, _log(c, '573930', 2, 8))
    c.emu.hook(0x574ff0, _log(c, '574ff0', 0, 0))


def _obj(c, size=0x200):
    o = c.emu.alloc(size, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return o


def _args56(c):
    # the flag is the low byte of b, so 0x100 (low byte 0) must leave the second helper uncalled
    return [_obj(c), c.rng.getrandbits(32), c.rng.choice([0, 1, 0x100, 0xff00, c.rng.getrandbits(32)])]


def _args57(c):
    o = _obj(c, 0x240)  # this+0x21b is read: the object must extend past it
    if c.rng.random() < 0.5:
        c.emu.wbytes(o + 0x88, bytes([c.rng.choice([0, 1, 0x80])]))
    if c.rng.random() < 0.3:
        # a zero flag at +0x21b is what keeps the second helper uncalled when b == 2
        c.emu.wbytes(o + 0x21b, bytes([0]))
    return [o, c.rng.getrandbits(32), c.rng.choice([0, 1, 2, 3, 0x102, c.rng.getrandbits(32)])]


S(0x56fa70, 'unknown::thiscall_562e90_56f2d0 (unknown) thiscall', 'thiscall', None, ret='al', gen=_args56,
  setup=_setup56, note='unclaimed-04 batch 48; 0x562e90 and 0x56f2d0 hooked by address (GUESS)')

S(0x574e30, 'unknown::thiscall_573930_574ff0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_args57,
  setup=_setup57, note='unclaimed-04 batch 48; 0x573930 and 0x574ff0 hooked by address (GUESS)')
