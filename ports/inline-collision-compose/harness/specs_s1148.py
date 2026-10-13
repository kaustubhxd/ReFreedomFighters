"""specs_s1148.py - collision thread batch 1148 (name GUESS): 0x55bd60. The helpers 0x5003d0, 0x43e920, 0x43e960, 0x4e0d00 and
0x451890 run as exe code. Virtual: O = this+0x1c: slot 0x84 (one pointer argument; writes three floats through it; not logged),
slot 0x5d0 (no arguments; returns R or zero); R's slot 0x218 (four words: the pointer is not logged, the three floats are);
the sys object's slot 0x1c0 (two constant arguments, returns a float in ST0). The logger 0x700390 (slot 0x20 opens a stream; its
slot 0x2c is cdecl) and the hook 0x7003b0 (cdecl) are recording fakes. The list entries are 8 bytes; byte +4 picks the branch
(0 and 2 write, others log)."""
import struct
from pilot import S, F


def _f2w(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _lst(c, count, types):
    e, r = c.emu, c.rng
    data = e.alloc(0x100, 16)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x100)))
    for k in range(count + 2):
        ent = data + 8 * k
        v = r.uniform(-4, 4) if r.random() < 0.8 else 0.0
        e.wf32(ent, v)
        e.wbytes(ent + 4, bytes([r.choice(types)]))
    base = e.alloc(0x20, 4)
    e.w32(base, data)
    e.w32(base + 8, 16)
    L = e.alloc(0x20, 4)
    e.w32(L, base)
    e.w32(L + 4, 0)
    e.w32(L + 8, count)
    return L


def _run(c):
    e, r = c.emu, c.rng
    # the three-floats writer (slot 0x84): values fixed per case; the pointer is not logged
    v84 = [r.uniform(-3, 3) for _ in range(3)]
    if r.random() < 0.3:
        v84[0] = 0.0
        v84[2] = 0.0
    if r.random() < 0.2:
        v84 = [0.0, 0.0, 0.0]

    def slot84(em, rr):
        p = em.arg32(0)
        for i in range(3):
            em.wf32(p + 4 * i, v84[i])
        em.ret(argbytes=4)

    # the R object's slot 0x218 (four words)
    def slot218(em, rr):
        em.calllog.append(('218', em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(argbytes=16)

    rvt = e.fake_vtable('R_55bd60', 0x100, {0x218: slot218})
    R = e.alloc(0x40, 4)
    e.w32(R, rvt)
    rv = R if r.random() < 0.85 else 0

    def slot5d0(em, rr):
        em.ret(eax=rv, argbytes=0)

    ovt = e.fake_vtable('O_55bd60', 0x180, {0x84: slot84, 0x5d0: slot5d0})
    O = e.alloc(0x40, 4)
    e.w32(O, ovt)
    self_ = e.alloc(0x40, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(self_ + 0x1c, O)

    # the sys object: slot 0x1c0 returns a float in ST0
    sv = r.uniform(-2, 2)

    def slot1c0(em, rr):
        em.calllog.append(('1c0', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8, st0=sv)

    svt = e.fake_vtable('sys_55bd60', 0x180, {0x1c0: slot1c0})
    sysobj = e.alloc(0x100, 16)
    e.wbytes(sysobj, bytes(r.getrandbits(8) for _ in range(0x100)))
    e.w32(sysobj, svt)
    e.w32(0x70039c, sysobj)

    # logger and hook
    def rec2c(em, rr):
        em.calllog.append(('2c', em.arg32(1), em.arg32(2)))
        em.ret(argbytes=0)
    svt2 = e.fake_vtable('stream_55bd60', 0x30, {0x2c: rec2c})
    stream = e.alloc(0x40, 4)
    e.w32(stream, svt2)

    def slot20(em, rr):
        em.calllog.append(('20', em.arg32(0), em.arg32(1)))
        em.ret(eax=stream, argbytes=8)
    lvt = e.fake_vtable('logger_55bd60', 0x30, {0x20: slot20})
    logger = e.alloc(0x40, 4)
    e.w32(logger, lvt)
    e.w32(0x700390, logger)

    def hook(em, rr):
        em.calllog.append(('hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('hook_7003b0_55bd60', hook))

    # the argument X: +4 is the list L (four or more entries), +8 is L2 (three or more)
    types_a = [0, 0, 2, 1, 3, 4]
    L = _lst(c, r.randrange(4, 7), types_a)
    L2 = _lst(c, r.randrange(3, 6), types_a)
    X = e.alloc(0x20, 16)
    e.w32(X + 4, L)
    e.w32(X + 8, L2)
    return [self_, X]


S(0x55bd60, 'vector pass: list reads, slot 0x84, PSVECSubtract, normalise, scale, vaddscalar, transform, slot 0x218, writes (name GUESS; void)',
  'thiscall', None, ret=None, gen=_run, note='batch1148')
