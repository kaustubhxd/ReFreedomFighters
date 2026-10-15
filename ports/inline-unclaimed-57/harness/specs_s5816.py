"""specs_s5816.py - unclaimed-57, batch 116: 0x5de260 (GUESS name unnamed_5de260). Thiscall, no stack args, plain ret. The sub-object (engine +0x9b) has fake
slots +0x138 (returns object x, the same each time), +0x58 (one arg, logged; the first call returns object A, the second returns object B). x has fake
slots +0x88 and +0x84 (two args: the key, logged; they write the per-key dword through the pointer) and +0x9c (two args: logged; returns a pointer to an
array of three random small ints). A has a dword at +0x676 (the key for the second +0x58 call, logged). B has slot +0x100 (one arg, logged; returns a
per-case dword). The float constant at 0x697890 and the key values are the exe's own data."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5260(c):
    e = c.emu
    keys = [0x681320, 0x6954e8, 0x6954f8, 0x69c218]
    vmap88 = {0x681320: c.rng.getrandbits(32)}
    vmap84 = {0x6954e8: struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100, 100)))[0],
              0x6954f8: struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100, 100)))[0]}
    ints = [c.rng.randrange(-500, 501) for _ in range(3)]
    ecount = [0]
    rb = c.rng.getrandbits(32)
    kA = c.rng.getrandbits(32)
    cnt58 = [0]
    rv100 = c.rng.getrandbits(32)

    arr = _rnd(c, 0x20)
    for i, v in enumerate(ints):
        e.w32(arr + 4 * i, v & 0xffffffff)

    def h138(em, r):
        em.calllog.append(('138', 0, None, ()))
        em.ret(eax=x_obj, argbytes=0)

    def h58(em, r):
        i = cnt58[0]
        cnt58[0] += 1
        em.calllog.append(('58', i, None, (em.arg32(0),)))
        em.ret(eax=A_obj if i == 0 else B_obj, argbytes=4)

    def h88(em, r):
        k = em.arg32(0)
        em.calllog.append(('88', 0, None, (k,)))
        em.w32(em.arg32(1), vmap88.get(k, 0))
        em.ret(eax=0, argbytes=8)

    def h84(em, r):
        k = em.arg32(0)
        em.calllog.append(('84', 0, None, (k,)))
        em.w32(em.arg32(1), vmap84.get(k, 0))
        em.ret(eax=0, argbytes=8)

    def h9c(em, r):
        em.calllog.append(('9c', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=arr, argbytes=8)

    def h100(em, r):
        em.calllog.append(('100', 0, None, (em.arg32(0),)))
        em.ret(eax=rv100, argbytes=4)

    vt_sub = e.fake_vtable('d5260_sub', 200, {0x138: h138, 0x58: h58})
    vt_x = e.fake_vtable('d5260_x', 200, {0x88: h88, 0x84: h84, 0x9c: h9c})
    vt_B = e.fake_vtable('d5260_B', 200, {0x100: h100})
    x_obj = _rnd(c, 0x40)
    e.w32(x_obj, vt_x)
    A_obj = _rnd(c, 0x800)
    e.w32(A_obj + 0x676, kA)
    B_obj = _rnd(c, 0x40)
    e.w32(B_obj, vt_B)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x200)
    return [self_obj]


S(0x5de260, 'unnamed_5de260 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5260,
  note='unclaimed-57 batch 116; sub slots +0x138 and +0x58 fake (A then B); x slots +0x88, +0x84, +0x9c fake; B slot +0x100 fake')
