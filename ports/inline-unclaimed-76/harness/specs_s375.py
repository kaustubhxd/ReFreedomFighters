"""specs_s375.py - area 76, residue 18, batch 375: 0x660f60 (thiscall, no arguments, plain ret; GUESS).
The engine 0x70039c has 0x9c7 and 0x9c3 nonzero (mostly). this+0x20 is a random byte (zero about half the time), this+0x18 -> an object
whose vtable slots 0x4c (thiscall, one word, logged) and 0x64 (thiscall, one word, logged) are stubs: 0x64 returns the next element of
a per-run list of 0..3 random 0x200-byte objects, then 0. The element objects are random."""
import struct
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    eng = e.alloc(0x1000, 4)
    e.wbytes(eng, rng.randbytes(0x1000))
    for off in (0x9c3, 0x9c7):
        v = 0.0 if rng.random() < 0.1 else rng.choice([1.0, -2.0, 0.5])
        e.w32(eng + off, struct.unpack('<I', struct.pack('<f', v))[0])
    e.w32(0x70039c, eng)

    elems = [e.alloc(0x200, 4) for _ in range(rng.randint(0, 3))]
    for el in elems:
        e.wbytes(el, rng.randbytes(0x200))
    seq = list(elems) + [0]
    state = {'k': 0}

    def h4c(em, r):
        em.calllog.append(('o4c', 0x4c, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h64(em, r):
        em.calllog.append(('o64', 0x64, em.reg('ecx'), (em.arg32(0),)))
        v = seq[min(state['k'], len(seq) - 1)]
        state['k'] += 1
        em.ret(eax=v, argbytes=4)

    vt = e.fake_vtable('o660f60', 0x80 // 4 * 4, {0x4c: h4c, 0x64: h64})
    obj = e.alloc(0x40, 4)
    e.w32(obj, vt)
    this = e.alloc(0x40, 4)
    e.wbytes(this, rng.randbytes(0x40))
    e.w32(this + 0x18, obj)
    e.wbytes(this + 0x20, bytes([0 if rng.random() < 0.5 else 1]))
    return [this]


S(0x660f60, 'loop660f60 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='area 76 batch 375; residue 18; object vtable slots 0x4c and 0x64 stubbed')
