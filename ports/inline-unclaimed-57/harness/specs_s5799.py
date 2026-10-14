"""specs_s5799.py - unclaimed-57, batch 99: 0x5da470 (GUESS name unnamed_5da470). Thiscall, no stack args, returns eax (an object or 0).
The engine (global 0x70039c) sub-object at +0x9b has a fake slot +0x58 (one argument, logged): its first call returns r1 (null in about one case in
ten); its later calls return u objects from a per-case list. Each of these objects has a string pointer at +4 (from a small pool that includes
a null, so the default string at 0x67c8e8 is used). The engine's pointer at +0x190f is an object p whose slot +0x98 returns the list q; q has
slot +0x14 (a per-case count 0 to 3) and slot +0x30 (one argument, logged; returns an element). The name comparison is the CRT import _stricmp
at 0x676414 (stub_import: case-insensitive compare, returns 0 on a match). The gate at this+0x5e is zero in about one case in four."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 1)
    c.emu.wbytes(a, text + b'\x00')
    return a


def _d5a470(c):
    e = c.emu
    strs = [_cstr(c, b'Alpha'), _cstr(c, b'alpha'), _cstr(c, b'Beta'), 0]
    cnt_v = c.rng.randrange(0, 4)
    null_r1 = c.rng.random() < 0.1
    gate0 = c.rng.random() < 0.25
    elems = [_rnd(c, 0x40) for _ in range(4)]
    tvals = [c.rng.getrandbits(32) | 1 for _ in range(4)]
    uobjs = [_rnd(c, 0x40) for _ in range(4)]
    for k, u in enumerate(uobjs):
        e.w32(u + 4, strs[c.rng.randrange(0, 4)])
    r1 = _rnd(c, 0x40)
    e.w32(r1 + 4, strs[c.rng.randrange(0, 4)])
    calls = [0]

    def h58(em, r):
        k = calls[0]
        calls[0] += 1
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        if k == 0:
            em.ret(eax=0 if null_r1 else r1, argbytes=4)
        else:
            em.ret(eax=uobjs[(k - 1) % 4], argbytes=4)

    def h98(em, r):
        em.calllog.append(('98', 0, None, ()))
        em.ret(eax=q_obj, argbytes=0)

    def h14(em, r):
        em.calllog.append(('14', 0, None, ()))
        em.ret(eax=cnt_v, argbytes=0)

    def h30(em, r):
        i = em.arg32(0)
        em.calllog.append(('30', 0, None, (i,)))
        em.ret(eax=tvals[i % 4], argbytes=4)

    def stricmp(em, rr):
        def cs(addr):
            out = b''
            while True:
                b = em.mu.mem_read(addr + len(out), 1)[0]
                if b == 0:
                    return out.lower()
                out += bytes([b])
        a, b = cs(em.arg32(0)), cs(em.arg32(1))
        em.ret(eax=0 if a == b else ((a > b) - (a < b)) & 0xffffffff, argbytes=0)
    e.stub_import('_stricmp', stricmp)

    vt_sub = e.fake_vtable('d5a470_sub', 160, {0x58: h58})
    vt_p = e.fake_vtable('d5a470_p', 160, {0x98: h98})
    vt_q = e.fake_vtable('d5a470_q', 160, {0x14: h14, 0x30: h30})
    q_obj = _rnd(c, 0x40)
    e.w32(q_obj, vt_q)
    p = _rnd(c, 0x40)
    e.w32(p, vt_p)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(eng + 0x190f, p)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x56, c.rng.getrandbits(32))
    e.w32(self_obj + 0x5e, 0 if gate0 else c.rng.getrandbits(32) | 1)
    return [self_obj]


S(0x5da470, 'unnamed_5da470 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_d5a470,
  note='unclaimed-57 batch 99; engine sub slot +0x58 fake (r1, then u objects); p slot +0x98; q slots +0x14 and +0x30; _stricmp import stubbed')
