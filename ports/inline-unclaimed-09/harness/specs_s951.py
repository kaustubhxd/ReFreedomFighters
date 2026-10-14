"""specs_s951.py - area 56, claim A10: ZFFSearchLightGroup::Alarm(float*, S*) (0x5c61b0).

this (0x100 random): +0x6d a float in [0, 20] (its product with the constant is truncated to an int), +0x44 an object o with
vt+0x12c (logs its id, the word, and the 16 bytes of the local it is given). S (0x40 random): +0xc the list (or null in one
case in five), +0x28 written by the call. A is three random floats. The global at 0x70039c (0x2000 random bytes) has +0x40 a
random int; the word at 0x71433c is random. The list: vt+0x4c logs (its one argument is a stack pointer, so it is not logged); vt+0x5c hands out ids from a short sequence with repeats and writes the flag. 0x5c78e0 is a GUESS recording stub
(logs its argument). All unverified callees."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _gen(c):
    e = c.emu
    rng = c.rng
    ids = [rng.randrange(0, 12) for _ in range(rng.randint(0, 4))]
    if ids and rng.random() < 0.5:
        ids = ids + ids[:1]
    seq = {'i': 0}

    def h4c(e2, r):
        e2.calllog.append(('L4c',))
        e2.ret(argbytes=4)

    def h5c(e2, r):
        flagp = e2.arg32(0)
        i = seq['i']
        seq['i'] = i + 1
        if i < len(ids):
            e2.w32(flagp, 1)
            e2.calllog.append(('L5c', ids[i]))
            e2.ret(eax=ids[i], argbytes=4)
        else:
            e2.w32(flagp, 0)
            e2.calllog.append(('L5c', 'end'))
            e2.ret(eax=0, argbytes=4)

    def h12c(e2, r):
        l = bytes(e2.rbytes(e2.arg32(2), 16))
        e2.calllog.append(('O12c', e2.arg32(0), e2.arg32(1), l))
        e2.ret(argbytes=12)

    def h5c78(e2, r):
        e2.calllog.append(('E5c78e0', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    e.hook(0x5c78e0, h5c78)
    lst = e.fake_object('alarm_list', 0x40, slots={0x4c: h4c, 0x5c: h5c})
    o = e.fake_object('alarm_o', 0x40, slots={0x12c: h12c})
    g = _rnd(c, 0x2000)
    e.w32(g + 0x40, rng.getrandbits(32))
    e.w32(0x70039c, g)
    e.w16(0x71433c, rng.getrandbits(16))
    this = _rnd(c, 0x100)
    e.w32(this + 0x6d, _f(rng.uniform(0.0, 20.0)))
    e.w32(this + 0x44, o)
    a = _rnd(c, 0x20)
    for i in range(3):
        e.w32(a + 4 * i, _f(rng.uniform(-50.0, 50.0)))
    s = _rnd(c, 0x40)
    e.w32(s + 0xc, lst if rng.random() < 0.8 else 0)
    return [this, a, s]


S(0x5c61b0, 'ZFFSearchLightGroup::Alarm (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A10; 0x5c78e0, list and this+0x44 object are GUESS recording stubs (unverified)')
