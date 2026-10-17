"""specs_s5823.py - unclaimed-57, batch 123: 0x5d4c00 (CBoxAutoFire::FireShot(), GUESS name), thiscall, no args, plain ret. The helpers 0x4de7a0 (mreset) and
0x5d4e80 (vector helper) run as original code. The engine (global 0x70039c) has slot +0x1c0 (the helper calls it three times with two args (0x6b53ac, 0x39/0x3a/0x3b):
returns a per-case st0 float for each), +0x40 (the loop limit) and +0x9b (the sub-object). The sub-object has
slot +0x58 (one arg, logged): it returns the objects A, B, C in turn (0 or an object, in about one case in eight each). A has slot +0x98 (two args, logged
with the bytes of both blocks), C has slots +0xbc, +0x33c, +0x35c (returns a per-case flag), +0x360, +0x354 (returns a per-case byte), +0x2d0, +0x7c, +0x32c.
A, B, C each have a +8 block of random bytes (read by the helper). The logger (global 0x700390) has slot +0x20 (two args: returns object O) and O has
slot +0x2c (cdecl, logged). this+0x48 is set so that each loop turn adds a bounded step to the cut value (a few turns per case)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _d4c00(c):
    e = c.emu
    rnd = c.rng
    K = struct.unpack('<f', e.mu.mem_read(0x678620, 4))[0]
    this48 = _f32(rnd.uniform(0.5, 2.0) / K)
    this4c = _f32(rnd.uniform(-1.0, 1.0) / K)
    cut0 = int(_f32(_f32(this48 + this4c) * K))
    if rnd.random() < 0.1:
        eng40 = cut0 - rnd.randrange(0, 3)  # the early return path
    else:
        eng40 = cut0 + rnd.randrange(1, 6)
    keys = [rnd.getrandbits(32) for _ in range(3)]
    f_z = _f32(rnd.uniform(-3.0, 3.0))
    f_a = _f32(rnd.uniform(-3.0, 3.0))
    f_b = _f32(rnd.uniform(-3.0, 3.0))
    r35c = rnd.choice([0, 1])
    r354 = rnd.choice([0, 1, 0x100, 0x200, 0x1ff, 0x101])  # the low byte is what the port tests; the high bits must matter too
    objs = [0 if rnd.random() < 0.12 else None for _ in range(3)]
    calls58 = [0]
    objA = _rnd(c, 0x40)
    objB = _rnd(c, 0x40)
    objC = _rnd(c, 0x40)
    O_obj = _rnd(c, 0x40)
    cand = [objA, objB, objC]
    cand = [0 if objs[i] == 0 else cand[i] for i in range(3)]

    def h1c0(em, r):
        # the helper pushes (0x6b53ac, k) before each call: all three calls take two arguments
        k = em.arg32(1)
        em.calllog.append(('1c0', k, None, (em.arg32(0), k)))
        em.ret(st0=f_z if k == 0x39 else (f_a if k == 0x3a else f_b), argbytes=8)

    def h58(em, r):
        k = calls58[0]
        calls58[0] += 1
        em.calllog.append(('58', k % 3, None, (em.arg32(0),)))
        em.ret(eax=cand[k % 3], argbytes=4)

    def hlg20(em, r):
        em.calllog.append(('lg20', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=O_obj, argbytes=8)

    def hO2c(em, r):
        em.calllog.append(('O2c', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    def role(em):
        c_ = em.reg('ecx')
        return 'A' if c_ == objA else ('B' if c_ == objB else ('C' if c_ == objC else 'other'))

    def hA98(em, r):
        em.calllog.append(('A98', role(em), None, (em.rbytes(em.arg32(0), 0x24), em.rbytes(em.arg32(1), 12))))
        em.ret(eax=0, argbytes=8)

    def h7c(em, r):
        em.calllog.append(('C7c', role(em), None, (em.rbytes(em.arg32(0), 0x24), em.rbytes(em.arg32(1), 12))))
        em.ret(eax=0, argbytes=8)

    def hbc(em, r):
        em.calllog.append(('Cbc', role(em), None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h33c(em, r):
        em.calllog.append(('C33c', role(em), None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h35c(em, r):
        em.calllog.append(('C35c', role(em), None, ()))
        em.ret(eax=r35c, argbytes=0)

    def h360(em, r):
        em.calllog.append(('C360', role(em), None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h354(em, r):
        em.calllog.append(('C354', role(em), None, ()))
        em.ret(eax=r354, argbytes=0)

    def h2d0(em, r):
        em.calllog.append(('C2d0', role(em), None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h32c(em, r):
        em.calllog.append(('C32c', role(em), None, (em.rbytes(em.arg32(0), 12),)))
        em.ret(eax=0, argbytes=4)

    vt_eng = e.fake_vtable('d4c00_eng', 200, {0x1c0: h1c0})
    vt_sub = e.fake_vtable('d4c00_sub', 100, {0x58: h58})
    vt_lg = e.fake_vtable('d4c00_lg', 100, {0x20: hlg20})
    vt_O = e.fake_vtable('d4c00_O', 60, {0x2c: hO2c})
    vt_obj = e.fake_vtable('d4c00_obj', 240, {0x98: hA98, 0x7c: h7c, 0xbc: hbc, 0x33c: h33c, 0x35c: h35c, 0x360: h360, 0x354: h354, 0x2d0: h2d0, 0x32c: h32c})
    vt_A = vt_B = vt_C = vt_obj
    e.w32(O_obj, vt_O)
    e.w32(objA, vt_A)
    e.w32(objB, vt_B)
    e.w32(objC, vt_C)
    for o in (objA, objB, objC):
        e.w32(o + 8, _rnd(c, 0x100))
    lg = _rnd(c, 0x40)
    e.w32(lg, vt_lg)
    e.w32(0x700390, lg)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng, vt_eng)
    e.w32(eng + 0x40, eng40 & 0xffffffff)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x48, struct.unpack('<I', struct.pack('<f', this48))[0])
    e.w32(self_obj + 0x4c, struct.unpack('<I', struct.pack('<f', this4c))[0])
    e.w32(self_obj + 0x50, keys[0])
    e.w32(self_obj + 0x54, keys[1])
    e.w32(self_obj + 0x5c, keys[2])
    return [self_obj]


S(0x5d4c00, 'CBoxAutoFire::FireShot (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d4c00,
  note='unclaimed-57 batch 123; helpers 0x4de7a0 and 0x5d4e80 run as original code; engine slot +0x1c0 (0 or 2 args, ret address picks), sub slot +0x58, objects A, B, C, logger and O fake')
