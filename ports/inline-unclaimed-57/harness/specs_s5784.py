"""specs_s5784.py - unclaimed-57, batch 84: 0x5d92e0 (GUESS name unnamed_5d92e0). Thiscall with one stack argument a (ret 4), no return value;
ECX is not used. a has fake slots +0x20 (no args: returns object e), +0x27c (one arg: the value from the engine sub-object, logged).
e has fake slot +0x25c (two args: logged; returns object r, or null in about three cases in ten). r has fake slot +0x258 (two args: the
pointer to the two-float array is NOT logged; its eight bytes are read and logged, then the second arg). The engine sub-object at +0x9b
has fake slot +0x4c (one arg: logged with a tag for e). Writes into e+0x30 and a+0x48 are checked by the heap comparison."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d92e0(c):
    e_ = c.emu
    e_obj = _rnd(c, 0x80)
    r_obj = _rnd(c, 0x40)
    null_r = c.rng.random() < 0.3
    s_val = c.rng.getrandbits(32)

    def h20(em, r):
        em.calllog.append(('20', 0, None, ()))
        em.ret(eax=e_obj, argbytes=0)

    def h27c(em, r):
        em.calllog.append(('27c', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h25c(em, r):
        em.calllog.append(('25c', 0, 'E' if em.reg('ecx') == e_obj else 'other', (em.arg32(0), em.arg32(1))))
        em.ret(eax=0 if null_r else r_obj, argbytes=8)

    def h258(em, r):
        p = em.arg32(0)
        bits = struct_bits(em.rbytes(p, 8))
        em.calllog.append(('258', 0, 'R' if em.reg('ecx') == r_obj else 'other', (bits, em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h4c(em, r):
        tag = 'E' if em.arg32(0) == e_obj else 'other'
        em.calllog.append(('4c', 0, None, (tag,)))
        em.ret(eax=s_val, argbytes=4)

    vt_a = e_.fake_vtable('d92e0_a', 160, {0x20: h20, 0x27c: h27c})
    vt_e = e_.fake_vtable('d92e0_e', 160, {0x25c: h25c})
    vt_r = e_.fake_vtable('d92e0_r', 160, {0x258: h258})
    vt_sub = e_.fake_vtable('d92e0_sub', 160, {0x4c: h4c})
    e_.w32(e_obj, vt_e)
    e_.w32(r_obj, vt_r)
    a_obj = _rnd(c, 0x80)
    e_.w32(a_obj, vt_a)
    sub = _rnd(c, 0x40)
    e_.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e_.w32(eng + 0x9b, sub)
    e_.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x40)
    return [self_obj, a_obj]


def struct_bits(b):
    import struct
    return struct.unpack('<II', b)


S(0x5d92e0, 'unnamed_5d92e0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d92e0,
  note='unclaimed-57 batch 84; a slots +0x20 and +0x27c, e slot +0x25c, r slot +0x258 (float bits logged), sub slot +0x4c fake')
