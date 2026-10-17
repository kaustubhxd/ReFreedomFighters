"""specs_s356.py - area 76, batch 356: 0x61b1e0 (thiscall, four stack arguments, ret 0x10, bool in AL; GUESS; parked row).

Fixture as in specs_s355, with a second table U (P +0x13fe) whose cache holds the element pointer base (stride 4 by this+0xc).
The helper 0x65bc00 (six arguments, ret 0x18) and the lock 0x441730 are exe code hooked by address (logged, no writes). 0x616e00
runs as exe code. Counts 0..4 give path 1 (count 1) and path 2."""
import struct
from pilot import S


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _gen(c):
    e = c.emu
    rng = c.rng

    def hlock(em, r):
        em.calllog.append(('lock', 0x441730, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x441730, hlock)

    def hhelp(em, r):
        args = tuple(em.arg32(k) for k in range(6))
        em.calllog.append(('h65bc00', 0x65bc00, em.reg('ecx'), args))
        em.ret(eax=0, argbytes=24)

    e.hook(0x65bc00, hhelp)

    Y = e.alloc(0x8000, 4)
    e.wbytes(Y, b''.join(struct.pack('<f', rng.uniform(-10.0, 10.0)) for _ in range(0x8000 // 4)))
    CT = e.alloc(0x8000, 4)
    e.wbytes(CT, bytes(rng.getrandbits(8) for _ in range(0x100)))
    CU = e.alloc(0x8000, 4)
    e.wbytes(CU, bytes(rng.getrandbits(8) for _ in range(0x100)))

    r1c8 = rng.getrandbits(32)
    eng_vt = e.logging_vtable('cmd_eng', 0x180, impl={0x1c8: lambda em, a: (r1c8, None)},
                              argwords={0x1c8: 2, 0x17c: 3})
    E = e.alloc(0x1b00, 4)
    e.w32(E, eng_vt)
    Q = e.alloc(0x40, 4)
    e.w32(Q + 0x20, Y)
    e.w32(E + 0x1aa3, Q)
    for off in (0x9c3, 0x9c7):
        v = 0.0 if rng.random() < 0.1 else rng.choice([1.0, 2.0, -1.5])
        e.w32(E + off, struct.unpack('<I', struct.pack('<f', v))[0])
    e.w32(0x70039c, E)

    def table(cache):
        vt = e.logging_vtable('cmd_tab', 0x10, impl={4: lambda em, a: (cache, None)}, argwords={4: 2})
        t = e.alloc(0x40, 4)
        e.w32(t, vt)
        e.w32(t + 0x30, 0 if rng.random() < 0.7 else cache)
        return t

    T = table(CT)
    U = table(CU)
    P = e.alloc(0xba00, 4)
    e.wbytes(P + 0x1295, bytes([rng.choice([0, 1])]))
    e.wbytes(P + 0x1296, bytes([rng.choice([0, 1])]))
    e.w32(P + 0x13fa, T)
    e.w32(P + 0x13fe, U)
    B = e.alloc(0x40, 4)
    e.w32(B + 0xb9a4, P)

    word = rng.choice([0, 1, 5, 16, 31, 32, 33, 40])
    count = rng.choice([0, 1, 1, 2, 3, 4])
    V1 = rng.randint(0, 10)
    V2 = rng.randint(1, 8)
    u = rng.uniform(0.0, max(count - 1, 1))
    X = e.alloc(0x80, 4)
    e.wbytes(X, bytes(rng.getrandbits(8) for _ in range(0x80)))
    e.wbytes(X + 0xe, word.to_bytes(2, 'little'))
    e.w32(X + 0x14, 0)
    e.w32(X + 0x20, rng.getrandbits(32))
    e.w32(X + 0x48, V1)
    e.w32(X + 0x4c, V2)
    e.w32(X + 0x50, count)
    rec = e.alloc(0x80, 4)
    e.wbytes(rec, bytes(rng.getrandbits(8) for _ in range(0x80)))
    e.wbytes(rec + 0x48, struct.pack('<f', _f32(V1 + V2 * u)))
    W = e.alloc(0x40, 4)
    e.w32(W + 8, X)
    A = e.alloc(0x80, 4)
    e.w32(A + 0xc, rec)
    e.w32(A + 0x10, W)

    this_vt = e.logging_vtable('cmd_this', 0x10)
    this = e.alloc(0x40, 4)
    e.w32(this, this_vt)
    S4 = e.alloc(0x40, 4)
    e.w32(S4 + 0x14, rng.choice([1, 1, 7, 0]))
    e.w32(this + 4, S4)
    e.w32(this + 0xc, rng.choice([0, 1, 2, 3, 3, 2]) if rng.random() < 0.9 else 0)

    return [this, A, B, rng.getrandbits(32), rng.getrandbits(32)]


S(0x61b1e0, 'pe_61b1e0 (GUESS)', 'thiscall', None, ret='al', gen=_gen,
  note='area 76 batch 356; parked row; helpers 0x441730/0x65bc00 hooked; 0x616e00 is exe code')
