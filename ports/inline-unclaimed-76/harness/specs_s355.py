"""specs_s355.py - area 76, batch 355: 0x61b570 (thiscall, four stack arguments, ret 0x10, bool in AL; GUESS; parked row).

Fixture: THIS (+0xc = element index, nonzero except sometimes; +4 -> S with +0x14). The argument a: +0xc = rec (+0x48 float F1),
+0x10 = W with W+8 = X (word +0xe, count +0x50, V1 +0x48, V2 +0x4c, +0x14 = 0, +0x20 random). The argument b: +0xb9a4 = P
(flag bytes at +0x1295 and +0x1296; +0x13fa = T, whose vtable slot 4 returns the cache C). The engine (0x70039c) has +0x1aa3 = Q with
+0x20 = Y (the element array, finite floats). Helpers 0x441730 and 0x440530 (locks), and 0x65bc60/0x65bcc0/0x65bd20 (six arguments,
ret 0x18) are exe code hooked by address (logged, no writes). 0x616e00 and the CRT helper run as exe code. Counts are 0..4, so path 1
(count 1) and path 2 (count != 1) both run. V1, V2 and F1 are chosen so the fractional index stays in 0..count-1."""
import struct
from pilot import S


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _gen(c):
    e = c.emu
    rng = c.rng

    # ---- locks and helpers (hooked: logged, no writes)
    def hlock(name, addr):
        def h(em, r):
            em.calllog.append((name, addr, em.reg('ecx'), ()))
            em.ret(eax=0, argbytes=0)
        return h

    e.hook(0x441730, hlock('lock', 0x441730))
    e.hook(0x440530, hlock('unlock', 0x440530))

    def hhelp(name, addr):
        def h(em, r):
            args = tuple(em.arg32(k) for k in range(6))
            em.calllog.append((name, addr, em.reg('ecx'), args))
            em.ret(eax=0, argbytes=24)
        return h

    for name, addr in (('h65bc60', 0x65bc60), ('h65bcc0', 0x65bcc0), ('h65bd20', 0x65bd20)):
        e.hook(addr, hhelp(name, addr))

    # ---- the element array Y (engine Q +0x20) and the cache C (T +0x30)
    Y = e.alloc(0x8000, 4)
    Yf = b''.join(struct.pack('<f', rng.uniform(-10.0, 10.0)) for _ in range(0x8000 // 4))
    e.wbytes(Y, Yf)
    C = e.alloc(0x8000, 4)
    e.wbytes(C, bytes(rng.getrandbits(8) for _ in range(0x100)))

    # ---- the engine E (0x70039c)
    r1c8 = rng.getrandbits(32)
    eng_vt = e.logging_vtable('cmd_eng', 0x180, impl={0x1c8: lambda em, a: (r1c8, None)},
                              argwords={0x1c8: 2, 0x178: 3, 0x17c: 3})
    E = e.alloc(0x1b00, 4)
    e.w32(E, eng_vt)
    Q = e.alloc(0x40, 4)
    e.w32(Q + 0x20, Y)
    e.w32(E + 0x1aa3, Q)
    for off in (0x9c3, 0x9c7):
        v = 0.0 if rng.random() < 0.1 else rng.choice([1.0, 2.0, -1.5])
        e.w32(E + off, struct.unpack('<I', struct.pack('<f', v))[0])
    e.w32(0x70039c, E)

    # ---- the table T (P +0x13fa) and P (b +0xb9a4)
    t_vt = e.logging_vtable('cmd_T', 0x10, impl={4: lambda em, a: (C, None)}, argwords={4: 2})
    T = e.alloc(0x40, 4)
    e.w32(T, t_vt)
    e.w32(T + 0x30, 0 if rng.random() < 0.7 else C)
    P = e.alloc(0xba00, 4)
    e.wbytes(P + 0x1295, bytes([rng.choice([0, 1])]))
    e.wbytes(P + 0x1296, bytes([rng.choice([0, 1])]))
    e.w32(P + 0x13fa, T)
    B = e.alloc(0x40, 4)
    e.w32(B + 0xb9a4, P)

    # ---- X (a +0x10 +8) and rec (a +0xc)
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

    # ---- THIS
    this_vt = e.logging_vtable('cmd_this', 0x10)
    this = e.alloc(0x40, 4)
    e.w32(this, this_vt)
    S4 = e.alloc(0x40, 4)
    e.w32(S4 + 0x14, rng.choice([1, 1, 7, 0]))
    e.w32(this + 4, S4)
    e.w32(this + 0xc, rng.choice([0, 1, 2, 3, 3, 2]) if rng.random() < 0.9 else 0)

    c_val = rng.getrandbits(32)
    d_val = rng.getrandbits(32)
    return [this, A, B, c_val, d_val]


S(0x61b570, 'pe_61b570 (GUESS)', 'thiscall', None, ret='al', gen=_gen,
  note='area 76 batch 355; parked row; helpers 0x441730/0x440530/0x65bc60/0x65bcc0/0x65bd20 hooked; 0x616e00 is exe code')
