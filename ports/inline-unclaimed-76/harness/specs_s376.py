"""specs_s376.py - area 76, residue 17, batch 376 (thiscall functions; GUESS).
0x635490: this+0x14 -> an object whose slot 0 (thiscall, one word, returns 0) is logged; null sometimes.
0x425150: this+0x28 -> an object with slot 0 as above (null sometimes); this+0xc -> another such object (null sometimes); 0x42ad20 runs as
exe code. 0x659b10: this is an object whose slot 0xe4 (thiscall, one word, returns a per-run value) is logged; the argument is a block whose
+0x14 receives the value."""
from pilot import S


def _slot0_obj(c, name):
    e = c.emu
    def h0(em, r):
        em.calllog.append((name, 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    vt = e.fake_vtable(name, 0x40 // 4 * 4, {0: h0})
    o = e.alloc(0x40, 4)
    e.w32(o, vt)
    return o


def _gen_635(c):
    e = c.emu
    rng = c.rng
    this = e.alloc(0x40, 4)
    e.wbytes(this, rng.randbytes(0x40))
    e.w32(this + 0x14, _slot0_obj(c, 'o635') if rng.random() < 0.7 else 0)
    return [this]


def _gen_425(c):
    e = c.emu
    rng = c.rng
    this = e.alloc(0x40, 4)
    e.wbytes(this, rng.randbytes(0x40))
    e.w32(this + 0x28, _slot0_obj(c, 'o425a') if rng.random() < 0.7 else 0)
    e.w32(this + 0xc, _slot0_obj(c, 'o425b') if rng.random() < 0.6 else 0)
    return [this]


def _gen_659(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def he4(em, r):
        em.calllog.append(('oe4', 0xe4, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=rv, argbytes=4)

    vt = e.fake_vtable('o659', 0x100 // 4 * 4, {0xe4: he4})
    this = e.alloc(0x40, 4)
    e.w32(this, vt)
    arg = e.alloc(0x40, 4)
    e.wbytes(arg, rng.randbytes(0x40))
    return [this, arg]


S(0x635490, 'dtor635490 (GUESS)', 'thiscall', None, ret=None, gen=_gen_635, note='area 76 batch 376; residue 17')
S(0x425150, 'reset425150 (GUESS)', 'thiscall', None, ret=None, gen=_gen_425,
  note='area 76 batch 376; residue 17; 0x42ad20 runs as exe code')
S(0x659b10, 'store659b10 (GUESS)', 'thiscall', None, ret='al', gen=_gen_659, note='area 76 batch 376; residue 17')
