"""specs_s373.py - area 76, residue 18, batch 373.
0x671fe0 (cdecl, no arguments): the globals 0x6e7590 and 0x6e7594 hold two objects or zero (random); the objects' +0x10/+0x14 are written.
0x4d93e0 (thiscall, no arguments): this is a random block; the engine 0x70039c -> +0x9b -> dat; dat+8 -> obj whose vtable slot 0x34 is a
thiscall stub with one word (logged); 0x4de7a0 is hooked (logs ECX, writes nothing). The memset import (0x676260) is a fixture stub."""
from pilot import S


def _gen_671(c):
    e = c.emu
    rng = c.rng
    objs = [e.alloc(0x40, 4) for _ in range(2)]
    for o in objs:
        e.wbytes(o, rng.randbytes(0x40))
    a = objs[0] if rng.random() < 0.6 else 0
    b = objs[1] if rng.random() < 0.6 else 0
    e.w32(0x6e7590, a)
    e.w32(0x6e7594, b)
    e.w32(0x7003bc, rng.getrandbits(32))
    e.w32(0x7003c0, rng.getrandbits(32))
    return []


def _gen_4d9(c):
    e = c.emu
    rng = c.rng

    def h34(em, r):
        em.calllog.append(('o34', 0x34, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    vt = e.fake_vtable('o4d93e0', 0x40 // 4 * 4, {0x34: h34})
    obj = e.alloc(0x40, 4)
    e.w32(obj, vt)
    dat = e.alloc(0x40, 4)
    e.w32(dat + 8, obj)
    eng = e.alloc(0x200, 4)
    e.w32(eng + 0x9b, dat)
    e.w32(0x70039c, eng)

    def h4de(em, r):
        em.calllog.append(('h4de7a0', 0x4de7a0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x4de7a0, h4de)

    def _memset(em, r):
        dst, val, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n:
            em.mu.mem_write(dst, bytes([val & 0xff]) * n)
        em.ret(eax=dst, argbytes=0)

    e.stub_import('memset', _memset)
    this = e.alloc(0x80, 4)
    e.wbytes(this, rng.randbytes(0x80))
    return [this]


S(0x671fe0, 'list671fe0 (GUESS)', 'cdecl', None, ret=None, gen=_gen_671,
  note='area 76 batch 373; residue 18; plain cdecl, no arguments')
S(0x4d93e0, 'init4d93e0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_4d9,
  note='area 76 batch 373; residue 18; 0x4de7a0 hooked; memset import stubbed')
