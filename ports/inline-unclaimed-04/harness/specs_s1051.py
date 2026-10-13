"""specs_s1051.py - unclaimed-04 batch 51 (docs/20-unclaimed-04.md): 0x4c9530 (thiscall, one word argument, ret 8, returns 0).
Global 0x70039c is a pointer P; the dword at P+0x40 is copied to this+0x5b when the copy is needed. The object's vtable slot 0x64
is a logging thiscall stub (one argument, ret 4; GUESS). Some cases alias this+0x5b with P+0x40 (the copy is skipped)."""
from pilot import S


def _rnd(c, e, n):
    a = e.alloc(n, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    e = c.emu
    # P first, then a 0x200-byte pad: an alias this = P - 0x1b writes up to P + 0xe5 and must not reach the vtable
    e.alloc(0x40, 4)  # room below P for the alias case
    P = _rnd(c, e, 0x100)
    e.alloc(0x200, 4)
    vt = e.logging_vtable('this4c', 0x64 // 4 + 1, argwords={0x64: 1})
    e.this_vt = vt
    e.w32(0x70039c, P)
    e.P = P


def _args(c):
    e = c.emu
    P = e.P
    if c.rng.random() < 0.2:
        # alias: this+0x5b == P+0x40, so the copy is skipped
        this = P + 0x40 - 0x5b
        e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
        e.w32(this, e.this_vt)
    else:
        this = _rnd(c, e, 0x100)
        e.w32(this, e.this_vt)
    w48 = c.rng.getrandbits(16)
    w4a = c.rng.choice([w48, c.rng.getrandbits(16), (w48 ^ 1) & 0xffff])
    e.wbytes(this + 0x48, w48.to_bytes(2, 'little'))
    e.wbytes(this + 0x4a, w4a.to_bytes(2, 'little'))
    if c.rng.random() < 0.3:
        e.wbytes(this + 0x59, bytes([0, 0]))
    if c.rng.random() < 0.3:
        e.wbytes(this + 0x5a, bytes([0]))
    m = c.rng.choice([w48, w4a, c.rng.getrandbits(16), 0x10000 | w48])
    return [this, m, c.rng.getrandbits(32)]


S(0x4c9530, 'unknown::thiscall_word_copy_slot64 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args,
  setup=_setup, note='unclaimed-04 batch 51; object vtable slot 0x64 is a logging stub (GUESS)')
