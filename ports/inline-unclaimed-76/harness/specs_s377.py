"""specs_s377.py - area 76, residue 17, batch 377 (GUESS).
0x54c3d0: this+0x63ec -> object whose vtable slot 0x48 (thiscall, one word, logged) returns 0; 0x54ab70 runs as exe code: it calls 0x54dfa0
(hooked: logs ECX, returns 0) and then tail-jumps through the object at this+0x40b1 (vtable slot 0x10, thiscall, no arguments, returns a
per-run value, logged).
0x561f50: the engine 0x70039c -> E, whose vtable slot 0xbc (thiscall, no arguments) returns X; X's vtable slot 0xa4 (thiscall, no arguments)
returns a per-run value (logged)."""
from pilot import S


def _gen_54c(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def h48(em, r):
        em.calllog.append(('o48', 0x48, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h10(em, r):
        em.calllog.append(('o10', 0x10, em.reg('ecx'), ()))
        em.ret(eax=rv, argbytes=0)

    def h54d(em, r):
        em.calllog.append(('h54dfa0', 0x54dfa0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x54dfa0, h54d)
    vt48 = e.fake_vtable('o54c48', 0x60 // 4 * 4, {0x48: h48})
    obj = e.alloc(0x40, 4)
    e.w32(obj, vt48)
    vt10 = e.fake_vtable('o54c10', 0x40 // 4 * 4, {0x10: h10})
    this = e.alloc(0x4200, 4)
    e.wbytes(this, rng.randbytes(0x4200))
    e.w32(this + 0x63ec, obj if rng.random() < 0.7 else 0)
    e.w32(this + 0x40b1, vt10)     # 54ab70 jumps through [[this+0x40b1]+0x10]: the field is the vtable itself
    return [this]


def _gen_561(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def ha4(em, r):
        em.calllog.append(('x_a4', 0xa4, em.reg('ecx'), ()))
        em.ret(eax=rv, argbytes=0)

    vtX = e.fake_vtable('x561', 0xa8 // 4 * 4, {0xa4: ha4})
    X = e.alloc(0x40, 4)
    e.w32(X, vtX)

    def hbc(em, r):
        em.calllog.append(('e_bc', 0xbc, em.reg('ecx'), ()))
        em.ret(eax=X, argbytes=0)

    vtE = e.fake_vtable('e561', 0xc0 // 4 * 4, {0xbc: hbc})
    E = e.alloc(0x200, 4)
    e.wbytes(E, rng.randbytes(0x200))
    e.w32(E, vtE)
    e.w32(0x70039c, E)
    return []


S(0x54c3d0, 'chain54c3d0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_54c,
  note='area 76 batch 377; residue 17; 0x54ab70 runs as exe code; 0x54dfa0 hooked')
S(0x561f50, 'chain561f50 (GUESS)', 'cdecl', None, ret='eax', gen=_gen_561,
  note='area 76 batch 377; residue 17; vtable slots stubbed')
