"""specs_s1012.py - unclaimed-04 batch 12 (docs/20-unclaimed-04.md): ZFenceGate::Command (0x5c2630, high name).
thiscall, two stack arguments (ret 8): msg (dword, compared as a word) and data (not read).
Three message words sit in the image (0x71432c, 0x714330, 0x714334; zero in the file, set at run time). The spec
writes them in setup, from the case rng, so both runs see the same words. msg is chosen to match one of them in most
cases. The first word sets this+0x25b, asks the manager (global 0x70039c, its +0x9b) for a target through slot 0x58 with
this+0x50, and, when the target is non-null, calls the manager's slot 0x114 with FOUR stack arguments (0x68fee8, 0,
0x6b3cdc, 0x4f; the exe also leaves 0x3e8 and 0 on the stack), then the target's slot 0x12c with (the low word of the
result, 0x3e8, 0). The second and third words set
and clear this+0x25a. Slot 0x114 is RegisterZMsg (four arguments, ret 0x10; docs/20-climb.md).
All virtual slots are logging stubs."""
from pilot import S


def _setup(c):
    e = c.emu
    words = [c.rng.getrandbits(16) for _ in range(3)]
    for addr, w in zip((0x71432c, 0x714330, 0x714334), words):
        e.wbytes(addr, w.to_bytes(2, 'little'))
    e.fg_words = words
    P = e.alloc(0x100, 4)
    M_vt = e.logging_vtable('manager', 0x11c // 4 + 1,
                            impl={0x58: lambda em, a: (getattr(em, 'fg_target', 0), None),
                                  0x114: lambda em, a: (getattr(em, 'fg_ret', 0), None)},
                            argwords={0x58: 1, 0x114: 4})
    M = e.alloc(0x100, 4)
    e.w32(M, M_vt)
    e.w32(P + 0x9b, M)
    e.w32(0x70039c, P)


def _args(c):
    e = c.emu
    T_vt = e.logging_vtable('target', 0x130 // 4 + 1, argwords={0x12c: 3})
    T = e.alloc(0x100, 4)
    e.w32(T, T_vt)
    e.fg_target = T if c.rng.random() < 0.8 else 0
    e.fg_ret = c.rng.getrandbits(32)
    o = e.alloc(0x400, 4)  # the flag bytes are at +0x25a and +0x25b
    e.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x400)))
    e.w32(o + 0x50, c.rng.getrandbits(32))
    words = e.fg_words
    msg = c.rng.choice(words + [c.rng.getrandbits(32), c.rng.getrandbits(16)])
    data = c.rng.getrandbits(32)
    return [o, msg, data]


S(0x5c2630, 'ZFenceGate::Command (high) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 12; slot 0x114 takes four args (ret 0x10); slot 0x12c gets (id, 0x3e8, 0) (docs/20-climb.md)')
