"""specs_s36050.py - cascade s4 batch 36050: 0x5524a0 (place a model with a matrix), 0x5eedb0 (lay out a three-part frame and forward)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g5524a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    rec = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=rec)
    patA = bytes(r.getrandbits(8) for _ in range(0x24))
    patB = bytes(r.getrandbits(8) for _ in range(12))

    def s80(em, rr):
        em.calllog.append(('s80', em.reg('ecx')))
        em.wbytes(em.arg32(0), patA)
        em.wbytes(em.arg32(1), patB)
        em.ret(0, 8)
    ob = obj(c, 0x20, {0x80: e.stub_fn('s80', s80)})
    mg = obj(c, 0x20, {0x238: pystub(c, 5, this=True, deref={0: 9, 1: 3, 2: 3}, ret=lambda em, k: 0x6000 + k),
                       0x23c: pystub(c, 6, this=True, deref={1: 9, 2: 3, 3: 3})})
    so = sysobj(c, table_size=0xb00, table_slots={0x58: pystub(c, 1, this=True, ret=ob), 0xb4: pystub(c, 1, this=True)})
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, mg)
    e.w32(0x713f08, r.choice([0, 0, 0x7777, 0xabcdef]))
    e._image_dirty = True
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [p]


def _g5eedb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for addr in (0x5edbe0, 0x5ed340, 0x5edc20, 0x5ed3d0):
        hook_rec(c, addr, 3, this=True)
    hook_rec(c, 0x5ed9c0, 0, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x5ed9b0, 0, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x5ac620, 2, this=True)
    hook_rec(c, 0x5ac640, 2, this=True)
    parts = [obj(c, 0x20, {4: pystub(c, 2, this=True)}) for _ in range(3)]
    s = rnd(c, 0x40)
    e.w32(s + 4, parts[0])
    e.w32(s + 8, parts[1])
    e.w32(s + 0xc, parts[2])
    e.wbytes(s + 0x10, bytes([r.choice([0, 1, 1, 0x80])]))
    e.w32(s + 0x11, r.choice([2, 2, 0, 1, 3]))
    e.w32(s + 0x15, r.choice([1, 1, 0, 2]))
    e.w32(s + 0x19, r.getrandbits(32))
    e.w32(s + 0x1d, r.getrandbits(32))
    return [s, r.getrandbits(32), r.getrandbits(32)]


S(0x5524a0, 'GUESS place a model with a matrix', 'stdcall', None, ret=None, gen=_g5524a0, note='batch36050')
S(0x5eedb0, 'GUESS lay out a three-part frame and forward', 'thiscall', None, ret=None, gen=_g5eedb0, note='batch36050')
